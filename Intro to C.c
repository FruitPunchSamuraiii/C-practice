#include <stdio.h>

int main()
{

    //Basic addition with inputs from user
    int num1;
    int num2;
    printf("Please enter a number: ");
    scanf("%d", &num1); //Assign %d which means int, then the location, which is &num1
    printf("Please enter another number: ");
    scanf("%d", &num2);
    int num3 = num1 + num2;
    printf("Those sum up to %d \n", num3);

    //Input and displaying a char
    char c;
    printf("What is your fave char?");
    scanf(" %c", &c); //Put a space here cause the \n is still buffered
    printf("your fave character is %c \n", c);

    //Input and display string, you do it as an array of char's
    char name[20]; //You put a cap on how many char's can be stored
    printf("What do you want your username to be?");
    scanf("%s", name);
    printf("Your username is %s\n", name);

    //Basic if statement
    int choice;
    printf("Type 1 or 0\n");
    scanf("%d", &choice);
    if (choice == 0)
    {
        printf("You typed 0!\n");
    }
    else if (choice == 1)
    {
        printf("You typed 1!\n");
    }
    else
    {
        printf("Invalid input!");
    }

    //For loop
    for (int i = 0; i <= 10; i++) //The arguments are (variable based on; conditions for loop to stop; what happens to variable each loop) i++ means add 1 to i every loop
    {
        printf("i = %d\n", i);
    }

    //While loop
    int N = 1;
    while (N <= 20)
    {
        printf("N is equal to %d\n", N);
        N = N + 1;
    }

    //If to check user input
    int num;
    printf("Type a number: \n");
    scanf("%d", &num);
    if (num < 0)
    {
        printf("Your number is negative!\n");
    }
    else if (num > 0)
    {
        printf("Your number is above 0!\n");
    }
    else if (num == 0)
    {
        printf("Your number is 0!\n");
    }
    else
    {
        printf("Invalid input\n");
    }

    //For loop countdown
    int count = 10;
    while (count >= 0)
    {
        printf("Count is: %d\n", count);
        count = count - 1;
    }

    //Pointers
    //regular variable
    int var = 10;
    //pointer variable ptr to store whrere the var is, like a middleman
    int *ptr = &var;
    //Directly accessing ptr will give address
    printf("%p", ptr);
    //You have to dereference the pointer to access the value, which can be done using *, when this is done, you are accessing data directly
    printf("%d", *ptr);

    return 0;
}



