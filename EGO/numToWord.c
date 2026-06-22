#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define makeItem(_key, str, _len) {.key = _key, .value = {.len = _len, .value = str}}

typedef struct 
{
    unsigned int len;
    char *value;
}String;

typedef struct List
{
    int size; 
    int *elements;
}List;

typedef struct
{
    int key;
    String value;
} Item;

enum PlaceValues
{
    Ten_Crores = 8,
    Crores = 7,
    Ten_Lakhs = 6,
    Lakhs = 5,
    Ten_Thousands = 4,
    Thousands = 3,
    Hundreds = 2,
    Tens = 1,
    Ones = 0, 

};
 
Item wordNum[] = {

    makeItem(1, "One", 3),
    makeItem(2, "Two", 3),
    makeItem(3, "Three", 5),
    makeItem(4, "Four", 4),
    makeItem(5, "Five", 4),
    makeItem(6, "Six", 3),
    makeItem(7, "Seven", 5),
    makeItem(8, "Eight", 5),
    makeItem(9, "Nine", 4),
    makeItem(10, "Ten", 3),
    makeItem(11, "Eleven", 6),
    makeItem(12, "Twelve", 6),
    makeItem(13, "Thirteen", 8),
    makeItem(14, "Forteen", 7),
    makeItem(15, "Fifteen", 7),
    makeItem(16, "Sixteen", 7),
    makeItem(17, "Seventeen", 9),
    makeItem(18, "Eighteen", 8),
    makeItem(19, "Nineteen", 8),
    makeItem(20, "Twenty", 6),
    makeItem(30, "Thirty", 6),
    makeItem(40, "Fourty", 6),
    makeItem(50, "Fifty", 5),
    makeItem(60, "Sixty", 5),
    makeItem(70, "Seventy", 7),
    makeItem(80, "Eighty", 6),
    makeItem(90, "Ninety", 6),
};

void debug(int value)
{
    printf("\n--------------\n");
    printf("Debug: %i\n", value);
    printf("--------------\n");
}

void stringLen(String *str)
{
    int count = 0;
    char word;
    
    while (true)
    {   
        word = str->value[count];
        if (word != '\0') count++;
        else break;

    }
}

char *getWord(int num)
{
    
    size_t size =  sizeof(wordNum) / sizeof(wordNum[0]);

    unsigned count;
    char *word;
    unsigned int len;
    
    for (count = 0; count < size; count++)
    {
        if (num == wordNum[count].key)
        {
            len = (wordNum[count].value.len) + 1;
            // debug(len);
            
            word = malloc(len * sizeof(char));
            
            for (int chunk = 0; chunk <=len; chunk++)
            {
                word[chunk] = wordNum[count].value.value[chunk];
            }
            break;
        }
    }
    return word;
}

void getOnes(List *list)
{
    char *word;

    word = getWord(list->elements[Ones]);
    printf("%s", word);
    free(word);
}

void getTens(int placeNum, List *list,  enum PlaceValues flag)
{   
    char *word;
    char *onesWord;
    char onesNum;
    
    if (flag == Hundreds) onesNum = list->elements[2];
    else  onesNum = list->elements[Tens];

    if (placeNum >= 2)
    {
        word = getWord(placeNum * 10);
        
        if (onesNum == 0)
            printf("%s", word);
        else
        {
            onesWord = getWord(onesNum);
            printf("%s %s", word, onesWord);
            free(word);
            free(onesWord);
        }
    }
    else if (placeNum < 2 && placeNum != 0)
    {
        word = getWord(
                (placeNum * 10) + onesNum
            );
        printf("%s", word);
        free(word);
    }
}

void convertToWords(List *list, bool *exitFlag)
{   
    int placeNum = (list->elements == NULL)? 0: list->elements[0];
    int size = (list->size == 0)?  0 :  list->size - 1;
    
    debug(size);
    debug(placeNum);
    switch (size)
    {
        case Ones:
            if (placeNum != 0)
            {
                getOnes(list);
            }
            else printf("Zero");
            break;
        
        case Tens:
            getTens(placeNum, list, Tens);
            break;
        
        case Hundreds:
            getOnes(list);
            printf(" Hundred ");
            getTens(list->elements[Tens], list, Hundreds);
            break;

    }
    
    printf("\n");
    printf("------------------------------------\n");
    // *exitFlag = true;
}

void readString(String *str)
{
    str->value = malloc(4 * sizeof(char));
    str->len = 4;
    int word;

    for (int count = 0; count < str->len; count++)
    {
        word = fgetc(stdin);
        if (count == str->len - 1)
        {
            str->value = realloc(str->value, ( str->len + str->len) * sizeof(char));
            str->len +=str->len;
        };
        
        if (word !='\n'&& word != EOF)
        {
            str->value[count] = word;
            str->value[count + 1] = '\0';
        }
        else break;
        
    };

    
}

void runApp()
{
    int num;
    String numString;
    bool exitFlag = false;
    
    printf("\n------------------------------------\n");
    printf("Welcome To Number to Words Converter\n");
    printf("------------------------------------\n");

    while (!exitFlag)
    {
        printf("Enter Number To Be Converted: ");
        readString(&numString);
        
        printf("\n");

        
        // convertToWords(extratedDigits, &exitFlag);
        // free(extratedDigits);
    }

    printf("\n------------------------------------\n");
    printf("Program Closed !\n");
    printf("------------------------------------\n");
    
}

int main(void)
{
    runApp();
    return EXIT_SUCCESS;
}