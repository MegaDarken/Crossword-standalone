#include "clearInput.h"

#include <stdio.h>

void clearInput_until(const int val)
{
    for (int ch = getchar(); ch != EOF && ch != '\n';ch = getchar());
}

void clearInput_untilNewLine()
{
    clearInput_until('\n');
}
