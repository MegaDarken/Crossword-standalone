cmake_minimum_required(VERSION 3.22)
project(Crossword-standalone)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 14)

add_executable(Crossword-standalone
abs.h
arrayList.c
arrayList.h
arrayUtility.h
boxDrawing.c
boxDrawing.h
charArray.c
charArray.h
charArrayPair.c
charArrayPair.h
charArrayPairArray.c
charArrayPairArray.h
charArraySplit.c
charArraySplit.h
charGrid.c
charGrid.h
clearInput.c
clearInput.h
consoleCodePage.c
consoleCodePage.h
consoleProcessing.c
consoleProcessing.h
crossword.c
crossword.h
fileUtility.c
fileUtility.h
insertionSort.c
insertionSort.h
printTime.c
printTime.h
randomTable.c
randomTable.h
rawRead.c
rawRead.h
seedyShuffle.h
shuffle.h
stringConstexpr.h
stringHash.h
swapping.h
valRead.c
valRead.h
wprintTime.c
wprintTime.h
wrawRead.c
wrawRead.h
wvalRead.c
wvalRead.h
main.cpp
)
