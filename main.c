#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//5:40 in video

char board[3][3];
const char PLAYER = 'x';
const char COMPUTER = 'o';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main(){
    char winner = ' ';
    resetBoard();

    while (winner == ' ' && checkFreeSpaces() != 0)
    {
        printBoard();

        playerMove();

        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0){
            break;
        };

        computerMove();

        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0){
            break;
        };
    }

    printBoard();
    printWinner(winner);
    
    

    return 0;
}

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[j][i]);
            if (j < 2) printf("|"); 
        }
        
        printf("\n");
        if (i < 2) printf("---|---|---\n");  
    }
}
int checkFreeSpaces()
{
    int empty = 9;
    
    for(int i = 0; i <3; i++){
        for(int j = 0; j <3; j++){
            if (board[i][j] != ' '){
                empty--;
            }
        }
    }
    return empty;
}
void playerMove(){
    int x;
    int y;

    do 
    {
        printf("move x (0-2) :");
        scanf("%d", &x);
        printf("move y (0-2) :");
        scanf("%d", &y);
        printf("\n");

        if(board[x][y] != ' ')
        {
            printf("\nno\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        };
    } while (board[x][y] != ' ');
    

}
void computerMove(){
    
    srand(time(0));
    
    int x;
    int y;

    do
    {
        x = rand() % 3;
        y = rand() % 3;
    } while (board[x][y] != ' ');
    
    board[x][y] = COMPUTER;
}
char checkWinner()
{      

    for(int i = 0; i < 3; i++)
    {
        
        printf("\n%d\n", i);
        
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0]; 
        }

        else if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        };
        
        if (board[0][0] == board[1][1] && board[0][0] ==board[2][2]){
            return board[1][1];
        }
        else if (board[0][2] == board[1][1] && board[0][2] ==board[2][0]){
            return board[1][1];
        };
    
    };

    return ' ';
    
}
void printWinner(char winner)
{
    if(winner == PLAYER){
        printf("player win\n");
    }
    else if (winner == COMPUTER){
        printf("computer win\n");
    }
    else
    {
        printf("draw\n");
    };
}