#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%i",&num);
    
    if ((num % 2) == 0){
        printf("Yes %i is Divisible by 2 \n", num);
    }
    else{
        printf("%i is Not Divisible by two \n", num);
    }

    return EXIT_SUCCESS;
}