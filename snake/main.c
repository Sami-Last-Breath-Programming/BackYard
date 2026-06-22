#include <stdio.h>
#include "snake.h"

#pragma clang diagnostic ignored push
#pragma clang diagnostic ignored "-Wkeyword-macro"
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
int main(void)
START   
    int a = 5;
    int b = 4 + 1;

    if (a == b)
    START 
        printf("YES\n");
    END
    
    else
    START
        printf("NO\n");
    END

    return 0;
END
#pragma clang diagnostic pop
