#include <stdio.h>
#include <stdlib.h>

const float pi = 3.14F;

int main(void)
{   
    
    // area = pie(r^2)
    int radius;

    printf("Enter the Radius of Circle: ");
    scanf("%i",&radius);
    printf("The Area of Circle is: %.4f \n", 
        pi*(radius*radius)
    );
    
    return EXIT_SUCCESS;
}