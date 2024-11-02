//Ensure loaded only once
#ifndef __RAW_READ__
#define __RAW_READ__

void disableRawMode();
void enableRawMode();

long rawReadBuffer(char* array, long count);
char rawRead();
void rawReadLoop(char escape);

#endif //__RAW_READ__
