#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1 if yes, 0 if no (ASCII)
int isLetter(char c)
{
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return 1;
    return 0;
}

//Read from start index until non-character, return traversed characters
char *getWord(char *str, int start)
{
    //mark the returned string
    if(!isLetter(str[start]))
    {
        return "!";
    }

    //find length of word
    int wordLength = 0;
    int index = start;

    while(isLetter(str[index++]))
        wordLength++;
    wordLength += 1;

    char *word = (char *) malloc(wordLength);

    //loop through first word
    for(int i = 0; i < wordLength; i++)
    {
        //if current index not a letter
        if(!isLetter(str[start + i]))
        {
            word[i] = '\0';
            break;
        }

        word[i] = str[start + i];
    }

    return word;
}

//Split string into separate words
char **split(char *input)
{
    //append input str with nul character
    input = strcat(input, "\0");

    int length = strlen(input);

    char **args = (char **) malloc(length) + 1;
    
    //loop through input string
    int index = 0;
    int word = 0;
    //iterate word by word, adding each to args list
    while(1)
    {
        if(input[index] == '\0')
            break;

        //read a word into args list
        args[word] = getWord(input, index);

        //if the word is marked, try the next index
        if(args[word][0] == '!')
        {
            index++;
            continue;
        }

        //move index forward 1 word
        index += strlen(args[word]);

        //next word
        word++;
    }

    return args;
}