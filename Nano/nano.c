// Just a try just for learning 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TREE "tree.nan"
#define ERROR "Error: Invalid Command in Script !\n"

void makeTree();
void praseTree();
void run(int, char *);

int main(int argc, char **argv)
{
    // Args Check
    if (argc < 2 || argc > 3)
    {
        printf("Error: Invalid Source Code Path !\n");
        exit(EXIT_FAILURE);
    }
    
    // Calling makeTree func
    makeTree(argv);

    // Prasing The Tree
    praseTree();
    
}

void makeTree(char **argv)
{
    int index, times = 0;
    char token;
    
    //Max Char Buffer for a line
    char lineBuff[256];
    
    // Opening the source code 
    FILE *fd = fopen(argv[1], "r");

    // Clear and Open Tree file
    system("cat /dev/null > tree.nan");
    FILE *fd2 = fopen(TREE, "a");
   
    // Handling the Null file pointer
    if (fd == NULL || fd2 == NULL) exit(EXIT_FAILURE);
    
    // Looping on each Line
    while (fgets(lineBuff, sizeof(lineBuff), fd))
    {
        index = 0,
        token = lineBuff[index];

        // Looping to each char
        while (token != '\0')
        {
            if (token != ' ')
            {
                if (token != '"')
                    fprintf(fd2, "%c", token);
                else times += 1;
            }
            else
            {
                switch (times)
                {
                    case 0:
                        fprintf(fd2, "\n");
                        break;
                    case 1:
                        fprintf(fd2, " ");
                        break;
                    case 2:
                        fprintf(fd2, "\n");
                        times = 0;
                        break;
                    default:
                        printf(ERROR);
                        exit(EXIT_FAILURE);
                }
            }
            index++;
            token = lineBuff[index];
        }
    }
    fprintf(fd2, "\n");
    
    // Closing all open files
    fclose(fd);
    fclose(fd2);
}

void praseTree()
{
    int command = 0;
    char lineBuff[100];
    
    // Language KeyWords
    char *keyWords[] = {
        "display\n",
    };
    size_t size = sizeof(keyWords) / sizeof(keyWords[0]);

    // Open the tree;
    FILE *fd = fopen(TREE, "r");

    // Handling the Null file pointer
    if (fd == NULL) exit(EXIT_FAILURE);

    // Looping on each Keyword 
    while (fgets(lineBuff, sizeof(lineBuff), fd))
    {
        for (int index = 0; index < size; index++)
        {
            if (!strcmp(lineBuff, keyWords[index])) command = index + 1;
            else 
            {
                run(command, lineBuff);
                command = 0;
            }
        }
    }
    fclose(fd);
}

void run(int command, char *lineBuff)
{
    switch (command)
    {
        case 0:
            printf(ERROR);
            exit(EXIT_FAILURE);
            break;
        case 1:
            printf("%s", lineBuff);
            break;
    }
} 