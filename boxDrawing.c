#include "boxDrawing.h"

#include <stdio.h>
#include <wchar.h>
#include <string.h>

const __WCHAR_TYPE__ *boxDrawing_indexValue(const int index)
{
    const __WCHAR_TYPE__ *array[] = {
        L" ",L"╴",L"╸",L"?", L"╶",L"─",L"╾",L"?", L"╺",L"╼",L"━",L"?", L"?",L"?",L"?",L"═",
        L"╵",L"┘",L"┙",L"╛", L"└",L"┴",L"┵",L"?", L"┕",L"┶",L"┷",L"?", L"?",L"?",L"?",L"╧",
        L"╹",L"┚",L"┛",L"?", L"┖",L"┸",L"┹",L"?", L"┗",L"┺",L"┻",L"?", L"?",L"?",L"?",L"?",
        L"?",L"╜",L"?",L"╝", L"╙",L"╨",L"?",L"?", L"?",L"?",L"?",L"?", L"╚",L"?",L"?",L"╩",
        
        L"╷",L"┐",L"┑",L"╕", L"┌",L"┬",L"┭",L"?", L"┍",L"┮",L"┯",L"?", L"?",L"?",L"?",L"╤",
        L"│",L"┤",L"┥",L"╡", L"├",L"┼",L"┽",L"?", L"┝",L"┾",L"┿",L"?", L"?",L"?",L"?",L"╪",
        L"╿",L"┦",L"┩",L"?", L"┞",L"╀",L"╃",L"?", L"┡",L"╄",L"╇",L"?", L"?",L"?",L"?",L"?",
        L"?",L"?",L"?",L"?", L"?",L"?",L"?",L"?", L"?",L"?",L"?",L"?", L"?",L"?",L"?",L"?",

        L"╻",L"┒",L"┓",L"?", L"┎",L"┰",L"┱",L"?", L"┏",L"┲",L"┳",L"?", L"?",L"?",L"?",L"?",
        L"╽",L"┧",L"┪",L"?", L"┟",L"╁",L"╅",L"?", L"┢",L"╆",L"╈",L"?", L"?",L"?",L"?",L"?",
        L"┃",L"┨",L"┫",L"?", L"┠",L"╂",L"╉",L"?", L"┣",L"╊",L"╋",L"?", L"?",L"?",L"?",L"?",
        L"?",L"?",L"?",L"?", L"?",L"?",L"?",L"?", L"?",L"?",L"?",L"?", L"?",L"?",L"?",L"?",

        L"?",L"╖",L"?",L"?", L"╓",L"╥",L"?",L"?", L"?",L"?",L"?",L"?", L"?",L"?",L"?",L"╦",
        L"?",L"?",L"?",L"╛", L"?",L"?",L"?",L"?", L"?",L"?",L"?",L"?", L"?",L"?",L"?",L"╧",
        L"?",L"?",L"?",L"?", L"?",L"?",L"?",L"?", L"?",L"?",L"?",L"?", L"?",L"?",L"?",L"?",
        L"?",L"╢",L"?",L"╣", L"╟",L"╫",L"?",L"?", L"?",L"?",L"?",L"?", L"╠",L"?",L"?",L"╬",
    };

    return array[index];
}

const __WCHAR_TYPE__ *boxDrawing_value(const enum boxDrawingLineType left, const enum boxDrawingLineType right, const enum boxDrawingLineType up, const enum boxDrawingLineType down)
{
    return boxDrawing_indexValue(left | (right << 2) | (up << 4) | (down << 6));
}

void boxDrawing_fprint_horizontalLine(FILE *stream, const enum boxDrawingLineType across, const enum boxDrawingLineType *up, const enum boxDrawingLineType *down, const size_t count)
{
    if (count < 1)
    {
        return;
    }

    if (count == 1)
    {
        fwprintf(stream, L"%ls", boxDrawing_value(noLine, noLine, up[0], down[0]));
        return;
    }
    
    fwprintf(stream, L"%ls", boxDrawing_value(noLine, across, up[0], down[0]));

    for (size_t i = 1; i < count - 1; i++)
    {
        fwprintf(stream, L"%ls", boxDrawing_value(across, across, up[i], down[i]));
    }

    fwprintf(stream, L"%ls", boxDrawing_value(across, noLine, up[count - 1], down[count - 1]));
    
}

void boxDrawing_print_horizontalLine(const enum boxDrawingLineType across, const enum boxDrawingLineType *up, const enum boxDrawingLineType *down, const size_t count)
{
    boxDrawing_fprint_horizontalLine(stdout, across, up, down, count);
}

void boxDrawing_fprint_intervalHorizontalLine(FILE *stream, const enum boxDrawingLineType across, const enum boxDrawingLineType up, const enum boxDrawingLineType down, const size_t verticalCount, const size_t interval)
{
    if (verticalCount < 1)
    {
        return;
    }

    if (verticalCount == 1)
    {
        fwprintf(stream, L"%ls", boxDrawing_value(noLine, noLine, up, down));
        return;
    }

    fwprintf(stream, L"%ls", boxDrawing_value(noLine, across, up, down));

    const __WCHAR_TYPE__ *intervalCharPtr = boxDrawing_value(across, across, noLine, noLine);

    for (size_t i = 0; i < interval; i++)
    {
        fwprintf(stream, L"%ls", intervalCharPtr);
    }

    for (size_t j = 1; j < verticalCount - 1; j++)
    {
        fwprintf(stream, L"%ls", boxDrawing_value(across, across, up, down));

        for (size_t i = 0; i < interval; i++)
        {
            fwprintf(stream, L"%ls", intervalCharPtr);
        }
    }

    fwprintf(stream, L"%ls", boxDrawing_value(across, noLine, up, down));
}

void boxDrawing_print_intervalHorizontalLine(const enum boxDrawingLineType across, const enum boxDrawingLineType up, const enum boxDrawingLineType down, const size_t verticalCount, const size_t interval)
{
    boxDrawing_fprint_intervalHorizontalLine(stdout, across, up, down, verticalCount, interval);
}