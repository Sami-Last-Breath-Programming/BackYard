#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Colors
typedef enum colors
{
    RED = 1,
    GREEN = 2,
    BLUE = 3,
    BLACK = 4,

} colors;

// Vector
typedef struct vector2
{
    int x;
    int y;

} vector2;

// Color Obj
typedef struct ColorObj
{
    colors color;
    vector2 pos;

} ColorObj;


// Entry Point
int main(void)
{
    #define MATRIX_SIZE 6

    ColorObj *matrix = malloc(MATRIX_SIZE * sizeof(ColorObj));
    
    // Handle Memory Error
    if (matrix == NULL)
    {
        printf("Can't Allocate Memory !\n");
        exit(EXIT_FAILURE);
    }
    
    // Data in Matrix
    matrix[0] = (ColorObj){RED, {2,4}};
    matrix[1] = (ColorObj){GREEN, {-2, 74}};
    matrix[2] = (ColorObj){BLUE, {12, -4}};
    matrix[3] = (ColorObj){BLACK, {1, 0}};
    matrix[4] = (ColorObj){RED, {45, 89}};
    matrix[5] = (ColorObj){BLUE, {0, -15}};


    // Print Matrix Data
    for (uint8_t objCount = 0; objCount < MATRIX_SIZE; objCount++)
    {
        printf("Object: %i, Color: %i, Position: (%i, %i)\n",
            objCount+1, matrix[objCount].color, matrix[objCount].pos.x, 
            matrix[objCount].pos.y);
    }

    // Free Memory
    free(matrix);

    return EXIT_SUCCESS;
}