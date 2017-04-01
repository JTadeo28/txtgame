#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1 if yes, 0 if no
int isLetter(char c)
{
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return 1;
    return 0;
}

//Read from start index until non-character, return traversed characters
char *getWord(char *str, int start)
{
    //find length of word
    int wordLength = 0;
    int index = start;
    while(isLetter(str[index++]))
        wordLength++;

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
    //Total length of input string
    int length = strlen(input);

    char **args = (char **) malloc(length);
    
    //loop through input string
    int index = 0;
    int word = 0;
    //iterate word by word, adding each to args list
    while(input[index])
    {
        //read a word into args list
        args[word] = getWord(input, index);

        //move index forward 1 word (and 1 space)
        index += strlen(args[word]) + 1;

        //next word
        word++;
    }

    return args;
}