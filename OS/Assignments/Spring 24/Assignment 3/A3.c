#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

int board[3][3] = {0}; //tic-tac-toe board->0 for empty, 1 for O, 2 for X
int turn=0;
int flag[2] = {0}; //flags
int gameEnd=0;

int checkIfEnds(int player){
    int checkNum;
    if (player==0){
        checkNum=2; //player
    }
    else{
        checkNum=1; //computer
    }
    //checking row-wise
    for (int r=0;r<3;r++){
        int count=0;
        for (int c=0;c<3;c++){
            if (board[r][c]==checkNum){
                count++;
            }
        }
        if (count==3){
            gameEnd=1;
            return 1;
        }
    }
    //checking column-wise
    for (int c=0;c<3;c++){
        int count=0;
        for (int r=0;r<3;r++){
            if (board[r][c]==checkNum){
                count++;
            }
        }
        if (count==3){
            gameEnd=1;
            return 1;
        }
    }
    //checking diagonally
    int count=0;
    for (int i=0;i<3;i++){
        if (board[i][i]==checkNum){
            count++;
        }
    }
    if (count==3){
        gameEnd=1;
        return 1;
    }
    count=0;
    for (int i=0;i<3;i++){
        if (board[i][2-i]==checkNum){
            count++;
        }
    }
    if (count==3){
        gameEnd=1;
        return 1;
    }
    //if space filled then return 2
    count=0;
    for (int r=0;r<3;r++){
        for (int c=0;c<3;c++){
            if (board[r][c]!=0){
                count++;
            }
        }
    }
    if (count==9){
        gameEnd=1;
        return 2;
    }
    //if not over then return 0
    return 0;
}


void printBoard(){
    for (int r=0;r<3;r++){
        for (int c=0;c<3;c++){
            if (board[r][c]==0){
                printf("_   ");
            }
            else if (board[r][c]==1){
                printf("O   ");
            }
            else if (board[r][c]==2){
                printf("X   ");
            }
        }
        printf("\n");
    }
}


void* PlayerTakeMove(void* arg){
    //takes X by default, player num 0, move represented by 2
    do{
       flag[0]=1;
       turn=2;
       while (flag[1]==1 && turn==2 && gameEnd==0){}
        if (gameEnd==0){
            //critical sec start
            int row, col;
            printf("Players Turn:");
            scanf("%d %d", &row, &col);
            while (row>3 || row<1 || col>3 || col<1){
                printf("Enter values between 1 and 3:");
                scanf("%d %d", &row, &col);
            }
            while (board[row-1][col-1]!=0){
                printf("Place already taken. Re-enter: ");
                scanf("%d %d", &row, &col);
                while (row>3 && row<1 || col>3 && col<1){
                    printf("Enter values between 1 and 3:");
                    scanf("%d %d", &row, &col);
                }
            }
            board[row-1][col-1]=2;
            printBoard();
            int n=checkIfEnds(0);
            if (n==1){
                printf("Player won!\n");
                // pthread_exit(0);
                // printf("Game end=%d\n", gameEnd);
            }
            else if (n==2){
                printf("Draw!\n");
                // pthread_exit(0);
            }
            //sec ends
            flag[0]=0;
        }
    }while(gameEnd==0);
    pthread_exit(0);
}


void* ComputerTakeMove(void* arg){
    //takes O by default, player num 1, move represented by 1
    do{
        flag[1]=1;
        turn=1;
        while (flag[0]==1 && turn==1 && gameEnd==0){}
        if (gameEnd==0){
            //critical sec start
            int row, col;
            printf("Computers Turn:");
            row=rand()%3;
            col=rand()%3;
            while (board[row][col]!=0){
                row=rand()%3;
                col=rand()%3;
            }
            printf("%d %d\n", row+1, col+1);
            board[row][col]=1;
            printBoard();
            int n=checkIfEnds(1);
            if (n==1){
                printf("Computer won!\n");
                // printf("Game end=%d\n", gameEnd);
                // pthread_exit(0);
            }
            else if (n==2){
                printf("Draw!\n");
                // pthread_exit(0);
            }
            //sec ends
            flag[1]=0;
        }
    }while (gameEnd==0);
    pthread_exit(0);
}


int main(){
    pthread_t playerThread, computerThread;
    printf("X - Player\nO - Computer\n_ - Empty\n");
    printf("Enter the rows and columns in the following format: [r c]\n\n");
    printBoard();
    if (pthread_create(&playerThread, NULL, PlayerTakeMove, NULL)==-1){
        printf("Player Thread not created.\n");
        return -1;
    }
    if (pthread_create(&computerThread, NULL, ComputerTakeMove, NULL)==-1){
        printf("Computer Thread not created.\n");
        return -1;
    }
    pthread_join(playerThread, NULL);
    pthread_join(computerThread, NULL);

    printf("Game Ended!");
    return 0;
}
