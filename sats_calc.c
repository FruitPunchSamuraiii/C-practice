#include <stdio.h>
#include <time.h>

//Mode function
int calculateMode(int arr[], int n)
{
    int mode = arr[0];
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            mode = arr[i];
        }
    }
    if (maxCount == 1)
    {
        return -1; //No mode
    }
    else
    {
        return mode;
    }
}

//Mean function
float calculateMean(int arr[], int n) 
{
    float sum = 0;
    //Loops from 0 to n-1 to add the values of the array
    for (int i = 0; i < n; i++)
    {
        sum += arr[i]; //Adds each number to running total
    }
    return sum / n;
}


int main()
{
    int numbers[10];
    int n;

    //Asks for how many numbers are being used for calculation
    printf("Input how many numbers you wanna peform calculations with, no more than 10\n");
    scanf("%d", &n);

    //Checks for valid input
    if (n < 1 || n > 10)
    {
        printf("Invalid input!");
        return 1;
    }

    //Loop to store numbers
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    //Mode
    int mode = calculateMode(numbers, n);
    if (mode == -1)
    {
        printf("There is no mode!\n");
    }
    else
    {
        printf("The mode is %d", mode);
    }

    //Loop through array and prints it
    printf("\nYou entered: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
   
    //Prints the mean
    printf("Mean = %.2f\n", calculateMean(numbers, n));

    return 0;
}