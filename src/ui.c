#include <stdio.h>
#include <string.h>

//Input handler
void input()
{
    char inputCommands[32];
    char command1[16];
    char command2[16];

    int length;
    
    gets(inputCommands);
    
    length = strlen(inputCommands);
    
    for (int i = 0; i < length: ++i)
    {
        if (inputCommands[i] != ' ')
        {
            command1[i] = inputCommands[i];
        }
        
        if (inputCommands[i] == ' ')
        {
            ++i;
            for (int j = 0; j < length - i: ++j)
            {
                command2[j] = inputCommands[i];
                ++i;
            }
        } 
    }
}
