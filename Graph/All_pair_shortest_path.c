#include <stdio.h>
#define INF 99999

int min(int a, int b) {
    if(a>b)
    {
        return b;
    }else{
        return a;}
}

int cost[9][9] = {
    {0, 4, 0, 0, 0, 0, 0, 8, 0},
    {4, 0, 8, 0, 0, 0, 0,11, 0},
    {0, 8, 0, 7, 0, 4, 0, 0, 2},
    {0, 0, 7, 0, 9,14, 0, 0, 0},
    {0, 0, 0, 9, 0,10, 0, 0, 0},
    {0, 0, 4,14,10, 0, 2, 0, 0},
    {0, 0, 0, 0, 0, 2, 0, 1, 6},
    {8,11, 0, 0, 0, 0, 1, 0, 7},
    {0, 0, 2, 0, 0, 0, 6, 7, 0}
};


void Shortest() {
    int A[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (i == j){
            A[i][j] = 0;}
            else if (cost[i][j] == 0){
                    A[i][j] = INF;}
            else{
                 A[i][j] = cost[i][j];
            }
        }
    }


    for (int k = 0; k < 9; k++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
            }
        }
    }

    
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (A[i][j] == INF)
                printf("%s    ", "INF");
            else
                printf("%d    ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("All pais short path algo\n");
    Shortest();
    return 0;
}
