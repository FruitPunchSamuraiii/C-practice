#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Map and player and monster max hp
#define EMPTY 0
#define MONSTER 1
#define EXIT 2
#define MAX_HP 100

//Colours
#define RESET "\033[0m"
#define GRAY "\033[90m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"

typedef struct 
{
    int hp;
    int x;
    int y;
    int gold;
} Player;


int random_range(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int handle_movement(int *px, int *py)
{
    char move;
    int next_x = *px;
    int next_y = *py;

    printf("Where do you want to move?\n");
    scanf(" %c", &move);
    while (getchar() != '\n');

    if (move == 'D' || move == 'd')
    {
        next_x++;
    }
    else if (move == 'A' || move == 'a')
    {
        next_x--;
    }
    else if (move == 'S' || move == 's')
    {
        next_y++;
    }
    else if (move == 'W' || move == 'w')
    {
        next_y--;
    }
    else if (move == 'Q' || move == 'q')
    {
        printf("Quitting\n");
        return -1;
    }
    else
    {
        printf("Invalid input!\n");
        return 0;
    }

    if (next_x < 0 || next_x >= 5 || next_y < 0 || next_y >= 5)
    {
        printf("You hit a wall!\n");
        return 0;
    }

    // Write the updated coordinates back into main()'s player struct
    *px = next_x;
    *py = next_y;
    return 1;
}

int monster_encounter(int player_hp)
{
    //Sets the basic variables
    int monster_hp = 100;
    char choice; 

    printf("\nA monster has appeared!\n");

    //Combat loop goes on for as long as one of the people is alive
    while (player_hp > 0 && monster_hp > 0)
    {
        printf("Your hp is: %d\n", player_hp);
        printf("The monsters hp is %d\n", monster_hp);

        printf("You can either:\n 1:Attack\n 2:Heal\n");
        scanf(" %c", &choice);
        while (getchar() != '\n'); //Loops the get choice. if the second choice doesn not equal '\n' it gets discarded. Is '\n' not equal to itself? They are equal so condition is false and loops 

        //Reaction to player input
        switch (choice)
        {
            case '1':
            {
                int dmg = random_range(10, 25); //10-25 dmg inclusive
                monster_hp -= dmg;
                if (monster_hp < 0) //If hp is negative, it only prints 0
                {
                    monster_hp = 0;
                }
                printf("You dealt %d dmg!\n", dmg);
                break;
            }
            case '2':
            {
                int healing = random_range(20, 30); //Heals 20-30hp
                player_hp += healing; 
                //Incase the player heals above the max, 100 in this case
                if (player_hp > MAX_HP)
                {
                    player_hp = MAX_HP;
                }

                printf("You healed!\n");
                break;
            }
            default:
                printf("Invalid input!\n");
                continue;
        }

        //Monsters turn, happens only if it survives players turn
        if (monster_hp > 0)
        {
            int monster_dmg = random_range(10, 25); //Deals 10-25 dmg inclusive. (rand() % (max - min + 1)) + min
            player_hp -= monster_dmg;
            if (player_hp < 0)
            {
                player_hp = 0; //Prevents negative hp
            }
            printf("The monster deals %d dmg!\n", monster_dmg);
        }
        
    }

    //Prints what happened in the fight and returns player hp to main
    if (player_hp <= 0)
    {
        player_hp = 0;
        printf("You died!\n");
    }
    else
    {
        printf("You defeated the monster!\n");
    }

    return player_hp;
    
}

int main()
{
    srand((unsigned int)time(NULL)); //Makes a seed to keep it random once main starts

    printf("Welcome to the game!\n");
    printf("Try to collect as much gold as you can before escaping.\n");
    printf("Just basic wasd controls. You can type Q to quit the game any time out of combat.\n");

    //2D array for map
    int map[5][5];
    //For each y, checks each x
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            //30% chance to generate monster on square being checked
            map[y][x] = (rand() % 10 < 3) ? MONSTER : EMPTY; //Generates random number 0-9, taking the remainder after dividing by 10. <3 checks if result is 0, 1 or 2. If true, 1, if false, 0
        }
    }
    
    //This make sure the exit is atleast 2 tiles away from the spawn and doesnt overwrite the spawn for instant exit
    int exit_x, exit_y;
    do {
        exit_x = rand() % 5;
        exit_y = rand() % 5;
    } while (exit_x + exit_y < 2);

    map[exit_y][exit_x] = EXIT;
    //Player spawn
    map[0][0] = EMPTY;

    //Setting up the main things so they dont get changed back to base in loop but they have a base value
    Player player = 
    {
        .hp = MAX_HP,
        .x = 0,
        .y = 0,
        .gold = 0
    };

    char player_movement;
    int game_running = 1;


    //Create fog of war map here
    char fog_of_war[5][5];
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            fog_of_war[y][x] = '.';
        }
    }
    //Reveals player immidiatley on spawn
    fog_of_war[0][0] = '0';

    while (game_running)
    {
        //Main loop for the columns
        for (int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 5; x++)
            {
                if (x == player.x && y == player.y) //When the loops x and y match the players, it doesnt print the array number
                {
                    printf("P ");
                }
                else if (fog_of_war[y][x] == '1')
                {
                    printf(GREEN "1 " RESET); //Defeated monster green 
                }
                else if (fog_of_war[y][x] == '0')
                {
                    printf(YELLOW "0 " RESET); //Stepped over tile yellow 
                }
                else
                {
                    printf(GRAY ". " RESET); // Fog of war gray 
                }
            }
            printf("\n");
        }

        //Player movement input
        int status = handle_movement(&player.x, &player.y);
        if (status == -1)
        {
            break;
        }
        if (status == 0)
        {
            continue;
        }
    
        //Check what spot player landed on
        if (map[player.y][player.x] == MONSTER)
        {
            player.hp = monster_encounter(player.hp);
            if (player.hp <= 0)
            {
                //If player hp is 0, they're dead so game ends
                game_running = 0;
            }
            else
            {
                int gold_dropped = random_range(5, 30); //5-30 gold dropped inclusive
                player.gold += gold_dropped;
                fog_of_war[player.y][player.x] = '1';
                map[player.y][player.x] = EMPTY; //Makes sure the player cant farm this tile
                printf("The monster dropped %d gold! Your gold is now: %d\n", gold_dropped, player.gold);
            }
        }
        else if (map[player.y][player.x] == EXIT)
        {
            printf("You have escaped!\n");
            printf("Your gold count is: %d", player.gold);
            game_running = 0;
        }
        else
        {
            //First time you beat monster, fog of war becomes 1 and mapp 0. later when you walk over, map 0 so goes into this block and sees fog of war already 1
            if (fog_of_war[player.y][player.x] != '1')
            {
                fog_of_war[player.y][player.x] = '0';
            }
            continue;
        }
        

    }
    return 0;
}