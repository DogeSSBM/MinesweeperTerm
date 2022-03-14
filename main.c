#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct{
    int x;
    int y;
}Length, Coord;

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

// ./main.out xlen ylen numMines
// default: ./main.out  9 9 10
int main(int argc, char **argv)
{
    Length len = {.x = 9, .y = 9};
    if(validArgs(argc-1, argv+1)){
        len.x = atoi(argv[1]);
        len.y = atoi(argv[2]);
    }
    (void)len;
    printf("Hello, world\n");
    return 0;
}
