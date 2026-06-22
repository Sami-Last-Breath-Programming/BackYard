#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage" 

int main(void)
{   
    // Create a dictionary 
    Dictionary *data = newDictionary();

    // Add  data to dictionay 
    addEntry(data, newString("Fruits"), newList((String *[]){
        newString("Apple"),
        newString("Mango"),
        newString("Orange"),
    }, 3));

    addEntry(data, newString("Names"), newList((String *[]){
        newString("Sami"),
        newString("Rahul"),
        newString("Noob"),
    }, 3));

    addEntry(data , newString("Citys"), newList((String *[]){
        newString("Dehi"),
        newString("New Yock"),
        newString("London"),
    }, 3));

    // Print dictionay 
    printDictionary(data);

    // Free dictionary
    freeDictionary(data);

    return EXIT_SUCCESS;
}   
#pragma clang diagnostic pop
