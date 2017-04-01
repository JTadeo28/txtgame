#include <stdio.h>

#include "../h/room.h"
#include "../h/ui.h"

int main()
{
    FILE *svg;
    
    svg = fopen("data.svg", "r");
    
    if (svg == NULL)
        printf("No save found.\n");

    //--------------------------------

        Room *cellar;

        ROOMsetID(cellar, 69);
        printf("cellar id is %d\n", ROOMgetID(cellar));

        ROOMsetDesc(cellar, "Sunlight illuminates the damp room.");
        printf("%s\n", ROOMgetDesc(cellar));

    //--------------------------------

        char *str = "two words pal";

        char **args = split(str);

        //printf("%s\n", args[0]);
        

    //--------------------------------
    
    while(1)
    {
        //Print description
        //Gather input
        //Update character
        break;
    }
    
    return 0;
}