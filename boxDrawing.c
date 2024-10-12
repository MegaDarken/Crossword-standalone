#include "boxDrawing.h"

#include <stdio.h>
#include <string.h>

const char *boxDrawing_indexValue(const int index)
{
    const char *array[] = {
        " ","╴","╸","?", "╶","─","╾","?", "╺","╼","━","?", "?","?","?","═",
        "╵","┘","┙","╛", "└","┴","┵","?", "┕","┶","┷","?", "?","?","?","╧",
        "╹","┚","┛","?", "┖","┸","┹","?", "┗","┺","┻","?", "?","?","?","?",
        "?","╜","?","╝", "╙","╨","?","?", "?","?","?","?", "╚","?","?","╩",
        
        "╷","┐","┑","╕", "┌","┬","┭","?", "┍","┮","┯","?", "?","?","?","╤",
        "│","┤","┥","╡", "├","┼","┽","?", "┝","┾","┿","?", "?","?","?","╪",
        "╿","┦","┩","?", "┞","╀","╃","?", "┡","╄","╇","?", "?","?","?","?",
        "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",

        "╻","┒","┓","?", "┎","┰","┱","?", "┏","┲","┳","?", "?","?","?","?",
        "╽","┧","┪","?", "┟","╁","╅","?", "┢","╆","╈","?", "?","?","?","?",
        "┃","┨","┫","?", "┠","╂","╉","?", "┣","╊","╋","?", "?","?","?","?",
        "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",

        "?","╖","?","?", "╓","╥","?","?", "?","?","?","?", "?","?","?","╦",
        "?","?","?","╛", "?","?","?","?", "?","?","?","?", "?","?","?","╧",
        "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
        "?","╢","?","╣", "╟","╫","?","?", "?","?","?","?", "╠","?","?","╬",
    };

    return array[index];
}

const char *boxDrawing_value(const enum boxDrawingLineType left, const enum boxDrawingLineType right, const enum boxDrawingLineType up, const enum boxDrawingLineType down)
{
    return boxDrawing_indexValue(left | (right << 2) | (up << 4) | (down << 6));
}

void boxDrawing_print_horizontalLine(const enum boxDrawingLineType across, const enum boxDrawingLineType *up, const enum boxDrawingLineType *down, const size_t count)
{
    if (count < 1)
    {
        return;
    }

    if (count == 1)
    {
        printf("%s", boxDrawing_value(noLine, noLine, up[0], down[0]));
        return;
    }
    
    printf("%s", boxDrawing_value(noLine, across, up[0], down[0]));

    for (size_t i = 1; i < count - 1; i++)
    {
        printf("%s", boxDrawing_value(across, across, up[i], down[i]));
    }

    printf("%s", boxDrawing_value(across, noLine, up[count - 1], down[count - 1]));
    
}

void boxDrawing_print_intervalHorizontalLine(const enum boxDrawingLineType across, const enum boxDrawingLineType up, const enum boxDrawingLineType down, const size_t verticalCount, const size_t interval)
{
    if (verticalCount < 1)
    {
        return;
    }

    if (verticalCount == 1)
    {
        printf("%s", boxDrawing_value(noLine, noLine, up, down));
        return;
    }

    printf("%s", boxDrawing_value(noLine, across, up, down));

    const char *intervalCharPtr = boxDrawing_value(across, across, noLine, noLine);

    for (size_t i = 0; i < interval; i++)
    {
        printf("%s", intervalCharPtr);
    }

    for (size_t j = 1; j < verticalCount - 1; j++)
    {
        printf("%s", boxDrawing_value(across, across, up, down));

        for (size_t i = 0; i < interval; i++)
        {
            printf("%s", intervalCharPtr);
        }
    }

    printf("%s", boxDrawing_value(across, noLine, up, down));
}