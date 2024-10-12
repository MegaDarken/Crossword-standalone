#ifndef BOX_DRAWING_
#define BOX_DRAWING_

#include <stddef.h>

enum boxDrawingLineType {noLine, standardLine, boldLine, parallelLines};

const char *boxDrawing_indexValue(int index);
const char *boxDrawing_value(enum boxDrawingLineType left, enum boxDrawingLineType right, enum boxDrawingLineType up, enum boxDrawingLineType down);

void boxDrawing_print_horizontalLine(enum boxDrawingLineType across, enum boxDrawingLineType *up, enum boxDrawingLineType *down, const size_t count);
void boxDrawing_print_intervalHorizontalLine(enum boxDrawingLineType across, enum boxDrawingLineType up, enum boxDrawingLineType down, const size_t verticalCount, const size_t interval);

#endif //BOX_DRAWING_