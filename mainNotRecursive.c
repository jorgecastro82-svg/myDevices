#include <stdio.h>
#include "stack.h"
#include <stdbool.h>

#define DIM 27

typedef struct{
    int x;
    int y;
}Coord;

bool solveMaze(Stack *stack,char (*maze)[DIM]);
void printMaze(char (*maze)[DIM]);
Coord *newCoord(int x,int y);

int main(){

    
    char maze[DIM][DIM] = {
{'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
{'x','A','x',' ',' ',' ',' ',' ','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
{'x',' ','x','x','x',' ','x',' ','x',' ','x','x','x','x','x','x','x','x','x',' ','x','x','x','x',' ',' ','x'},
{'x',' ',' ',' ',' ',' ','x',' ','x',' ',' ',' ',' ',' ',' ','x',' ',' ','x',' ',' ',' ',' ','x',' ',' ','x'},
{'x','x','x','x','x','x','x',' ','x','x','x','x','x','x',' ','x','x',' ','x','x','x','x',' ','x','x','x','x'},
{'x',' ',' ',' ',' ',' ','x',' ','x',' ',' ',' ',' ','x',' ','x',' ',' ',' ',' ','x','x',' ',' ',' ',' ','x'},
{'x',' ','x','x','x',' ','x',' ','x','x','x','x',' ','x',' ','x',' ','x','x','x','x','x',' ','x',' ',' ','x'},
{'x',' ',' ',' ','x',' ','x',' ',' ',' ',' ','x',' ',' ',' ',' ',' ','x','x','x','x','x','x','x',' ',' ','x'},
{'x','x','x',' ','x',' ','x','x','x','x',' ','x','x','x','x','x','x','x',' ',' ',' ',' ','x',' ',' ',' ','x'},
{'x',' ','x',' ','x',' ',' ',' ','x','x',' ',' ',' ',' ','x','x',' ',' ',' ','x','x',' ','x',' ','x','x','x'},
{'x',' ','x',' ','x',' ','x',' ','x','x','x','x','x',' ',' ','x',' ','x','x','x','x',' ','x',' ',' ',' ','x'},
{'x',' ','x',' ','x',' ','x',' ',' ',' ','x',' ','x','x',' ','x',' ',' ',' ',' ','x',' ','x','x',' ',' ','x'},
{'x',' ','x',' ','x',' ','x','x','x',' ',' ',' ',' ','x',' ','x',' ','x','x',' ','x',' ',' ',' ',' ',' ','x'},
{'x',' ','x',' ','x',' ','x','x','x','x','x','x','x','x',' ','x',' ',' ','x',' ','x','x','x','x',' ',' ','x'},
{'x',' ',' ',' ','x',' ',' ',' ',' ',' ',' ',' ',' ','x',' ','x','x',' ','x',' ','x',' ',' ',' ',' ',' ','x'},
{'x',' ','x','x','x','x','x','x','x','x','x','x',' ','x',' ',' ','x','x','x',' ','x',' ','x','x','x','x','x'},
{'x',' ',' ',' ','x',' ',' ',' ',' ',' ',' ','x',' ',' ','x',' ',' ',' ',' ',' ','x',' ',' ','x',' ',' ','x'},
{'x','x','x',' ','x',' ','x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x',' ','x',' ',' ','x'},
{'x',' ','x',' ','x',' ',' ',' ',' ',' ',' ',' ','x',' ',' ',' ',' ','x','x',' ',' ',' ',' ','x',' ',' ','x'},
{'x',' ','x',' ','x',' ','x','x','x','x','x',' ','x','x','x','x',' ','x','x',' ','x','x','x','x',' ',' ','x'},
{'x',' ','x',' ','x',' ',' ',' ',' ','x','x',' ',' ',' ','x',' ',' ','x','x',' ','x',' ',' ',' ',' ',' ','x'},
{'x',' ','x',' ','x','x','x','x','x','x','x',' ','x',' ',' ','x',' ','x','x',' ','x',' ','x',' ','x','x','x'},
{'x',' ','x',' ',' ',' ',' ',' ',' ',' ',' ',' ','x','x',' ','x',' ','x','x',' ','x','x','x',' ','x','x','x'},
{'x',' ','x','x','x','x','x','x','x','x','x','x','x',' ',' ','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x'},
{'x',' ',' ',' ','x',' ',' ',' ','x',' ',' ',' ','x',' ','x','x','x','x','x','x','x','x','x','x',' ',' ','x'},
{'x',' ','x',' ',' ',' ','x',' ',' ',' ','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','B','x'},
{'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'}
};
    
    Coord *initial = newCoord(1,1);
    Stack stackOfValidCoords = {NULL,0};

    printMaze(maze);
    push(&stackOfValidCoords,initial);
    if(solveMaze(&stackOfValidCoords,maze)){
        printf("\nTLETS GOOOOOOOOOOOOOOOOOOOOOo\n");
        printMaze(maze);
    }
    else{
        printf("\nTHERES NO SOLUTION\n");
        printMaze(maze);
    }

    return 0;
}

void printMaze(char (*maze)[DIM]){
    for(int i = 0;i < DIM;i++){
        printf("\n");void fillCorrectCoords(Stack *stack,char (*maze)[DIM]);
        for(int j = 0;j < DIM;j++){
            if(maze[i][j] == '*'){
                printf("\033[32m[%c]\033[0m", maze[i][j]);
            }
            else{
                printf("[%c]",maze[i][j]);
            }
        }
    }
    printf("\n");
}

Coord *newCoord(int x,int y){
    Coord *c = malloc(sizeof(Coord));
    c->x = x;
    c->y = y;
    return c;
}

//this fills up the stack with the solutions
bool solveMaze(Stack *stack,char (*maze)[DIM]){
    Coord *aux = peek(stack);
    
    //case empty
    if(!aux){
        return false;
    }
    while(true){
        aux = peek(stack);

        if((!(aux->x + 1 > DIM - 1)) && maze[aux->x+1][aux->y] != '*' && maze[aux->x+1][aux->y] != 'x'){
            if(maze[aux->x+1][aux->y] == 'B')
                return true;
            maze[aux->x+1][aux->y] = '*';
            push(stack,newCoord(aux->x+1,aux->y));
            continue;
        }
        else if((!(aux->x - 1 < 0)) && maze[aux->x-1][aux->y] != '*' && maze[aux->x-1][aux->y] != 'x'){
            if(maze[aux->x-1][aux->y] == 'B')
                return true;
            maze[aux->x-1][aux->y] = '*';
            push(stack,newCoord(aux->x-1,aux->y));
            continue;
        }
        else if((!(aux->y + 1 > DIM - 1)) && maze[aux->x][aux->y+1] != '*' && maze[aux->x][aux->y+1] != 'x'){
            if(maze[aux->x][aux->y+1] == 'B')
                return true;
            maze[aux->x][aux->y+1] = '*';
            push(stack,newCoord(aux->x,aux->y+1));
            continue;
        }
        else if((!(aux->y - 1 < 0)) && maze[aux->x][aux->y-1] != '*' && maze[aux->x][aux->y-1] != 'x'){
            if(maze[aux->x][aux->y-1] == 'B')
                return true;
            maze[aux->x][aux->y-1] = '*';
            push(stack,newCoord(aux->x,aux->y-1));
            continue;
        }
        else{
            free(pop(stack));
            if(!stack->top)
                return false;
        }
    }
    return false;
}

