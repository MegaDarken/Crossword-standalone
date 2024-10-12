#ifndef FILE_UTILITY_
#define FILE_UTILITY_

#include <stdio.h>

FILE* fileUtility_open(const char* filename, const char* modes);

size_t fileUtility_charBufferGet(char buffer[], size_t bufferSize, FILE* filePointer);
size_t fileUtility_charBufferGetUntil(char buffer[], size_t bufferSize, char reference, FILE* filePointer);
size_t fileUtility_charBufferGetUntilWhitespace(char buffer[], size_t bufferSize, FILE* filePointer);

size_t fileUtility_intBufferGet(int buffer[], size_t bufferSize, FILE* filePointer);
size_t fileUtility_intBufferGetUntil(int buffer[], size_t bufferSize, int reference, FILE* filePointer);
size_t fileUtility_intBufferGetUntilWhitespace(int buffer[], size_t bufferSize, FILE* filePointer);

int fileUtility_nextNonWhitespace(FILE* filePointer);
int fileUtility_nextWhitespace(FILE* filePointer);

int fileUtility_upcoming(FILE* filePointer);

int fileUtility_nextAfterComment(int reference, FILE* filePointer);
void fileUtility_afterComment(int reference, FILE* filePointer);

#endif //FILE_UTILITY_