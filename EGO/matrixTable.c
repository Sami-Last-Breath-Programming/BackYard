#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define true 1
#define false 0

typedef _Bool bool;

const char *subjects[] = {
    "English", "Maths", "Chemistry",
    "Physics", "Biology", "Computer"
}

int *tables;
int tableSize = NULL;

void createTable()
{
    char name[20] = NULL;
    int buff = NULL;

    int *newTable = (int *)malloc((6*1) * sizeof(int));
    char *tableName = (char *)malloc(sizeof(char));
    int tableNameCapacity = 2;

    printf("Enter Student Name: ");
    scanf("%s", &name);

    if (name != NULL)
    {
        for (int index = 0; index < 20; index++)
        {
            while (name[index] != '\0')
            {
                if (index > tableNameCapacity)
                {
                    char tmp = realloc(tableName, 
                        tableNameCapacity * tableNameCapacity, sizeof(char)
                    );
                    if (tmp != NULL)
                    {
                        tableName = temp;
                        tableName[index] = name[index];  
                    }
                    else printf("Error: Table Name Memory Resize Failed\n")
                }
                else tableName[index] = name[index];
            }
        }
        name = NULL;
    }
    else printf("Error: Invaid Name \n");
    
    for (int row = 0; row < 6; row++)
    {
            printf("%s: ", subjects[row])
            
            while (getchar(stdin) != "\n");
            scanf("%i", &buff);

            if (buff != NULL)
            {
                newTable[row][1] = buff;
                buff = NULL;
            }
            else
            {
                printf("Error: Invaid Marks \n");
                newTable[row][1] = 0;
            }
    }

    if (tableSize != NULL)
    {
        tables[tableSize + 1] = {tableName, tableSize};
    }
    else
    {
        tableSize = 0
        tables[tableSize] = {tableName, tableSize};
    }
}

void removeTable()
{
    printf("Choose Table To Remove\n")
}

void checkOption(int selection)
{   
    switch (selection)
    {
        case 1:
            createTable();
            printf("Created Table")
            break;
        case 2:
            removeTable();
            break;
        case 3: 
            viewTable();
            break;
    }
}

void uiLoop()
{
    int selection = NULL;
    bool isExit = false; 
    
    printf("\n-------------------\n");
    printf("Welcome to Database\n");
    printf("-------------------\n");

    while (!isExit)
    {
        printf("1: Create Student Marks Record");
        printf("2: Remove Student Marks Record");
    
        while (getchar(stdin) != "\n");
        scanf("%i", &selection);
    
        if (selection != NULL)
        {
            checkOption(selection);
            selection = NULL;
        }
        else printf("Error: Invaid Option \n");
    }
        
}

int main(void)
{
    uiLoop();

    return EXIT_SUCCESS; 
}