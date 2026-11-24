#include <stdio.h>
#include <time.h>

//Define rock, paper, scissors, which replaces it later with the second argument, makes code easier to read
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int main()
{
    //Creates a seed to make random more random, has to be outside of loop as its based on time
    srand(time(NULL));

    int player_score = 0;
    int computer_score = 0;
    //Game loop using for statement
    for (int run = 0; run < 5; run++)
    {
        //Creates the variables
        int player = 0;
        int computer = rand() % 3 + 1;
        int result = 0;

        //Game system
        printf("Pick one of the following: \n 1 = Rock\n 2 = Paper\n 3 = Scissors\n");
        scanf("%d", &player);

        //Array of pointers, indicated by *, for a clean text output of what the computer chose
        char *ChoiceNames[] = {" ", "Rock", "Paper", "Scissors" }; //Empty at start cause it starts at index 0

        //Failsafe if incorrect input
        if (player < 1 || player > 3)
        {
            printf("Invalid input! Please try again!");
            return 1; //Return 1 means to exit earlt due to an emergency
        }

        printf("\nYou chose: %s\n", ChoiceNames[player]);
        printf("Computer chose: %s\n\n", ChoiceNames[computer]);

        //Who wins
        if (player == computer)
        {
            result = 0; //Tie
        }
        else if ((player == ROCK && computer == SCISSORS) || 
                (player == PAPER && computer == ROCK) || 
                (player == SCISSORS && computer == PAPER))
        {
            result = 1; //User wins
        }
        else
        {
            result = -1; //Computer wins
        }

        //Show who the winner is
        if (result == 1)
        {
            printf("      You win!\n   ---------------\n");
            player_score++; //Point added to player
        }
        else if (result == -1)
        {
            printf("      You lose!\n   ---------------\n");
            computer_score++; //Point added to computer
        }
        else
        {
            printf("     It's a tie!\n   ---------------\n");
        }
    }

    //Shows the overall points of both computer and player
    printf("---------Game over---------\n");
    printf("The final scores were: \n Your score: %d\n Computer score:%d\n", player_score, computer_score);
    printf("---------------------------\n");
    
    //Checks winner and outputs the winner
    if (player_score > computer_score)
    {
        printf("You are the winner!");
    }
    else if (computer_score > player_score)
    {
        printf("You lost!");
    }
    else
    {
        printf("It was a tie!");
    }

    return 0;
}