#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float num = 1.99999f;

    printf("I chop off the .99999: %i \n",
        (int)num
    );
    
    return EXIT_SUCCESS; 
}