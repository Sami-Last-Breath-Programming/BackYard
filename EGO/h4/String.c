#include <stdlib.h>
#include "String.h"


typedef struct 
{
    unsigned int len;
    char *value

}String;


String *makeString(const char *buff)
{
    String *str = malloc
}

unsigned int strLen(String *str)
{
    unsigned int count;
    char word;

    for (count= 0; word !='\0'; count++)
    {
        word = str->value[count];
        str->len += 1;
    }
}