/*********************************************************
 * Name: Matthew Egan
 * CS 362 Fall 2019
 * Random testing quiz
**********************************************************/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//formula for calculating a random number, rand() % (max_number + 1 - minimum_number) + minimum_number, 
//adapted from https://stackoverflow.com/questions/1202687/how-do-i-get-a-specific-range-of-numbers-from-rand
char inputChar()
{
    //produce a random number in range of 32-126, which is from space through ~ in ASCII characters
    char randomChar = (rand() % (126 + 1 - 32)) + 32;

    return randomChar;
}

char *inputString()
{
    static char str[6];

    int i = 0;

    //rand() % 16 + 101 will give range from 97-116, which in ascii is a-t(lowercase)
    while (i < 5)
    {
      str[i] = (rand() % (116 + 1 - 97)) + 97;
      i++;
    }
    
    return str;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
