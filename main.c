#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

typedef struct{
    int x;
    int y;
}Length, Coord;

typedef enum{S_COVERED, S_QUESTION, S_FLAG, S_REVEALED}State;

typedef struct{
    State state;
    char num; // -1 means bomb
}Square;

bool validArgs(const int argc, char **argv)
{
    if(argc != 3){
        printf("Expected 3 args, got %i!\n", argc);
        printf("Falling back to default args (\"9\" \"9\" \"10\")\n");
        return false;
    }

    for(int arg = 0; arg < 3; arg++){
        for(size_t i = 0; i < strlen(argv[arg]); i++){
            if(!isdigit(argv[arg][i])){
                printf("Argument %i (\"%s\") is invalid!\n", arg, argv[arg]);
                printf("Falling back to default args (\"9\" \"9\" \"10\")\n");
                return false;
            }
        }
    }
    printf("Using args (\"%i\" \"%i\" \"%i\")\n", atoi(argv[0]), atoi(argv[1]), atoi(argv[2]));
    return true;
}
char randomNumber(int upper,int lower){
	return (rand() % (upper - lower + 1)) + lower;
}
Square **newGrid(const Length len, const int numBombs)
{
    Square **grid = calloc(len.x, sizeof(Square *));
    for(int i = 0; i < len.y; i++) grid[i] = calloc(len.y, sizeof(Square));
				srand(time(NULL));
	for(int currentBombs = 0; currentBombs < numBombs; currentBombs++){
		int x = randomNumber(len.x-1,0);
		int y = randomNumber(len.y-1,0);
		if(grid[x][y].num != -1)
			grid[x][y].num = -1;
			
	}

    return grid;
}

// ./main.out xlen ylen numMines
// default: ./main.out  9 9 10
int main(int argc, char **argv)
{
    srand(time(0));
    Length len = {.x = 9, .y = 9};
    int numBombs = 10;
    if(validArgs(argc-1, argv+1)){
        len.x = atoi(argv[1]);
        len.y = atoi(argv[2]);
        numBombs = atoi(argv[3]);
    }
	Square **grid = newGrid(len,numBombs);

    return 0;
}
