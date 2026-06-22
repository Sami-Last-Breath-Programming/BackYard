/*  Most inefficent program just for learning !! */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

FILE *readFile(FILE *, const char *);
void display(FILE *, char *, int);

int main(int argc, char **argv)
{
    FILE *fd = NULL;
    char lineBuff[256];
   
     // Handel Args
    if (argc < 2 || argc > 2)
    {
        printf("Error: Invalid Path of Text File !\n");
        exit(EXIT_FAILURE);
    }

    // Update Every Loop
    while (true)
    {
        // Read Text File context
        fd = readFile(fd, argv[1]);

        // Display The Content
        display(fd, lineBuff, 256);
        
        // Sleep for 1 second
        sleep(2);
    }

    return EXIT_SUCCESS;
}

FILE *readFile(FILE *fd, const char *filePath)
{
    // Opening A file 
    fd = fopen(filePath, "r");

    // Handle Erros
    if (fd == NULL) 
    {
        printf("Error: Invalid Text File !\n");
        exit(EXIT_FAILURE);
    }
    return fd;
}

void display(FILE *fd, char *lineBuff, int size)
{
    // Read Each Line from the file pointer
    while (fgets(lineBuff, size, fd))
        printf("%s", lineBuff);
    
    // End Header
    printf("\n");
    
    // close the file
    fclose(fd);
}
