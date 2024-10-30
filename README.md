# Crossword Standalone

This application puts together crosswords from a list of word and hint pairs.  
Here is an example of such a list, in a format that the program can use:

> example;Thing characteristic of a general rule.  
> placeholder;Occupies a position in an absence.  

Here is a small example of an output:

```
2024-10-29 00:00:00
LOCK  
I O   
FIRE  
T E   
Across  
1: securement mechanism. aquatic elevation. (4)  
3: Promethean gift. (4)  
Down  
1: To pick up or raise. Aerodynamic force perpendicular to flow direction. (4)  
2: Genre postfix, in the centre. (4)  
┌────┬────┬────┬────┐  
│1   │    │2   │    │  
│    │    │    │    │  
├────┼────┼────┼────┤  
│    │▒▒▒▒│    │▒▒▒▒│  
│    │▒▒▒▒│    │▒▒▒▒│  
├────┼────┼────┼────┤  
│3   │    │    │    │  
│    │    │    │    │  
├────┼────┼────┼────┤  
│    │▒▒▒▒│    │▒▒▒▒│  
│    │▒▒▒▒│    │▒▒▒▒│  
└────┴────┴────┴────┘
```

As of writing this releases have executables compiled for Windows, MacOS, and Ubuntu using GitHub Actions.
Compiling requires at least C17 and C++14, this should already be set up for CMake. Only standard libraries 

Arguments can be given:
"-w" or "--width" followed by how many letters wide the crossword will be, must be an integer.

"-h" or "--height" followed by how many letters tall the crossword will be, must be an integer.

"-c" or "--count" followed by the upper bound on words placed, must be an integer.

"-f" or "--first" is the central character the crossword will start with and build off of, must be a character.

"-i" or "--iterations" followed by the number of crosswords you want created, must be an integer.

"-l" or "--list" followed by the relative filename of list of words you want to use, by default this is "wordQuestions.txt".

"-o" or "--output" followed by the filename you want the append the output to, by default the output is written to stdout, the terminal.  

"-r" or "--random", by default the longest words in a list are attempted first to optimize for table coverage. Give this arg to enable randomization.

"-d" or "--deterministic", by default randomization uses external data but this makes replication less feasible. Give this arg to have consistent starting conditions.

"-s" or "--seed" followed by a string. Controllable randomization variance.

## Changelog
v1.0.2:
- Added arg to write output to a file.  
- Added iterations arg for batches of outputs.  
- Fixed list filename arg interfering with other args.  

v1.0.1:  
- Added randomization, with controllable seeds.  
- Added word list file selection.  

v1.0.0:  
Initial release. A simple command line crossword generator that can prompt for inputs or use args.  
