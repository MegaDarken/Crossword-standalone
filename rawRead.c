//Source: https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html
#include "rawRead.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

struct termios orig_termios;

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void disableRawMode()
{
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void enableRawMode()
{
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);
  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
long rawReadBuffer(char array[], long count)
{
    enableRawMode();

    ssize_t result = read(STDIN_FILENO, array, count);
    if ( result != 1 )
    {
        printf("Issue with rawRead: ");

        if (iscntrl(array))
        {
            printf("%s\n", array);
        }
        else
        {
            printf("%d ('%s')\n", array[0], array);
        }
    }

    disableRawMode();

    return result;
} 

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
char rawRead()
{
  char c;
  rawReadBuffer(&c, 1);

  return c;
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void rawReadLoop(char escape)
{
    enableRawMode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != escape)
    {
        if (iscntrl(c))
        {
            printf("%s\n", &c);
        }
        else
        {
            printf("%d ('%s')\n", c, &c);
        }
    }

    disableRawMode();
}

// int main(int argc, char** argv)
// {
//     //rawRead(27);//27 is Esc
// }
