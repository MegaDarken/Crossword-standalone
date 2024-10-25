Crossword Standalone

Arguments can be given:
"-w" or "--width" followed by how many letters wide the crossword will be, must be an integer.

"-h" or "--height" followed by how many letters tall the crossword will be, must be an integer.

"-c" or "--count" followed by the upper bound on words placed, must be an integer.

"-f" or "--first" is the central character the crossword will start with and build off of, must be a character.

"-r" or "--random", by default the longest words in a list are attempted first to optimise for table coverage. Give this arg to enable randomization.

"-d" or "--deterministic", by default randomization uses external data but this makes replication less feasable. Give this arg to have consistant starting conditions.

"-s" or "--seed" followed by a string. Controlable randomisation varience.