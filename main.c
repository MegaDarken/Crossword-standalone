
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "charArray.h"
#include "charGrid.h"
#include "rawRead.h"
#include "arrayUtility.h"
#include "charArraySplit.h"
#include "crossword.h"
#include "valRead.h"

int main(int argc, char** argv)
{

    int width, height, wordCount;

    printf("\nEnter width:");
    valRead_intDest(&width, "\007\nInput must be integer:");

    printf("\nEnter height:");
    valRead_intDest(&height, "\007\nInput must be integer:");

    printf("\nEnter wordCount:");
    valRead_intDest(&wordCount, "\007\nInput must be integer:");

    crossword(width, height, wordCount);

}
