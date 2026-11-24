#include <stdio.h>
#include <time.h>

int main()
{
    //Creates a seed for random
    srand(time(NULL));

    //Sets up the board as a 5x5 and filled with 0's
    int board[5][5] = {0};
    int battleship_status = 1;

    //Generates random column and row 0-4
    int row = rand() % 5;
    int column = rand() % 5;

    //Places the battleship
    board[row][column] = 1;

    //Game loop - Active as long as the battleship is alive
    while (battleship_status == 1)
    {
        //Makes the guesses 0 to prevent errors from loops
        int column_guess = 0;
        int row_guess = 0;

        //Takes user guesses
        printf("What row do you think the battleship is on? 0-4\n");
        scanf("%d", &row_guess);
        printf("What column do you think the battleship is on? 0-4\n");
        scanf("%d", &column_guess);

        //Checks if the co'ordinates are valid
        if (row_guess < 0 || row_guess > 4 || column_guess < 0 || column_guess > 4)
        {
            printf("Invalid coordinates! Please pick numbers between 0 and 4.\n");
            continue; //Skips the rest of this loop
        }

        //Tells the user if it's a hit or miss
        if (board[row_guess][column_guess] == 1)
        {
            printf("HIT! You win!");
            battleship_status = 0;
            break; //If not included, it spams the terminal with asking the user a guess
        }
        else
        {
            printf("Miss!\n");
        }
    }


    return 0;
}