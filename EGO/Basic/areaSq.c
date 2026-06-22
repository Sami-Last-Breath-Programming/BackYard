#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{   
    int side;
    
    printf("Enter a Side of Square: ");
    scanf("%i", &side);
    printf("The Area of Square is: %i \n",
        side*side
    );

    return EXIT_SUCCESS;
}