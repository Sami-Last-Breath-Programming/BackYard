#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myLib.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

String *newString(char *buff)
{
    size_t sizeOfBuff = 0;
    String *newString;
    
    // Check the Lenght of the buff
    for (size_t index = 0; buff[index] != '\0'; index++)
    {
        sizeOfBuff++;
    }

    // Allocate memory for the string struct
    newString = malloc(sizeof(String) + sizeOfBuff + 1);

    // Check for allocation erros 
    if (newString != NULL)
    {
        newString->len = sizeOfBuff;
        strcpy(newString->str, buff);
        return newString;
    }
    else
    {
        printf("Error: Can't Allocate Memory For String !\n");
        exit(EXIT_FAILURE);
    }

}

List *newList(String **arrayBuff, size_t size)
{
    // Allocate memory for the List struct
    List *newList = malloc(sizeof(List));

    // Check for allocation erros 
    if (newList != NULL)
    {
        newList->len = size;
        newList->cap = size;
        newList->elements = malloc(sizeof(String *) * newList->len);

        if (newList->elements != NULL)
        {
            for (size_t index = 0; index < newList->len; index++)
            {
                newList->elements[index] = arrayBuff[index];
            }
        }
    }
    else
    {
        printf("Error: Can't Allocate Memory For List !\n");
        exit(EXIT_FAILURE);
    }

    return newList;
}

void freeList(List *ptr)
{
    // Free the Strings 
    for (size_t index = 0; index < ptr->len; index++)
    {
        free(ptr->elements[index]);
    }

    // Free list pointer
    free(ptr->elements);
    free(ptr);
}

Dictionary *newDictionary(void)
{
    // Allocate Memory For The Dictionary
    Dictionary *newDic = malloc(sizeof(Dictionary));

    // Check for Allocation 
    if (newDic != NULL)
    {
        newDic->size = 0;
        newDic->pairs = NULL;
    }
    else
    {
        printf("Error: Can't allocate memory for Dictionary");
        exit(EXIT_FAILURE);
    }

    return newDic;
}

void addEntry(Dictionary *dic, String *key, List *values)
{
    Pair **temp;

    // Pair on Heap 
    Pair *newPair = malloc(sizeof(Pair));
    
    // Check for allocation 
    if (newPair != NULL)
    {
        newPair->key = key;
        newPair->values = values;
    }
    else
    {
        printf("Error! Can't Allocate memory for Pair!\n");
        exit(EXIT_FAILURE);
    }

    temp = realloc(dic->pairs, sizeof(Pair *) * (dic->size + 1));
    
    if (temp != NULL)
    {
        dic->pairs = temp;
        dic->pairs[dic->size] = newPair;
        dic->size += 1;
    }
    else
    {
        printf("Error! Can't Rellocate memory for Pair ** !\n");
        exit(EXIT_FAILURE);
    }

}

void printDictionary(Dictionary *dic)
{
    size_t len;

    for (size_t index = 0; index < dic->size; index++)
    {   
        // Header
        printf("---------------------------------\n");

        // print the key
        printf("Key: %s\n", dic->pairs[index]->key->str);
        printf("Values: ");

        len = dic->pairs[index]->values->len;

        for (size_t index2 = 0; index2 < len; index2++)
        {
            // print Values of the key
            if (index2 == len - 1)
                printf("%s", dic->pairs[index]->values->elements[index2]->str);
            else
                printf("%s, ", dic->pairs[index]->values->elements[index2]->str);
        }

        printf("\n");
    }
   printf("---------------------------------\n");
}

void freeDictionary(Dictionary *dic)
{
    for (size_t index = 0; index < dic->size; index++)
    {   
        // free the key
        free(dic->pairs[index]->key);
        
        // free the list 
        freeList(dic->pairs[index]->values);
            
        // free each pair
        free(dic->pairs[index]);

    }

    // free the pairs ptr
    free(dic->pairs);

    // free dic
    free(dic);
}

#pragma clang diagnostic pop
