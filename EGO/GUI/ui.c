#include <stdlib.h>
#include "iup.h"

int main(int argc, char **argv)
{
    IupOpen(&argc, &argv);

    IupMessage("Hello World", "Hello Every one.");

    IupClose();

    return EXIT_SUCCESS;
}