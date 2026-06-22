#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    
    printf("Enter a number to check: ");
    scanf("%i", &num);

    printf("The number is %s \n",
        ((num % 2) != 0) ? "Odd": "Even"
    );
   
    return EXIT_SUCCESS;
}