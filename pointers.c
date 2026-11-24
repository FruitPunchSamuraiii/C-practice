#include <stdio.h>

int main()
{
    //Pointers
        //regular variable
        int var = 10;
        //pointer variable ptr to store whrere the var is, like a middleman
        int *ptr = &var;
        //Directly accessing ptr will give address
        printf("%p\n", ptr);
        //You have to dereference the pointer to access the value, which can be done using *, when this is done, you are accessing data directly
        printf("%d", *ptr);

}