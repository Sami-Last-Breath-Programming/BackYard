#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    int numbers[4] = {
        [0] = (5*2)-(2*3),
        [1] = (5*2)/(2*3),
        [2] = (5*3),
        [3] = (5+2)/(2*3),
    };

    int numbersLen = sizeof(numbers) / numbers[0];

    for (unsigned int i = 0; i < numbersLen; i++)
    {
        printf("The Answer for %c: %i \n",
            65+i,
            numbers[i]
        );
    };
    
    return EXIT_SUCCESS;
}