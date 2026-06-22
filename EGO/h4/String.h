#ifndef STRING_H
#define STRING_H

typedef struct String;

unsigned int strLen(String *str);

List *convertStrList(String);

#endif