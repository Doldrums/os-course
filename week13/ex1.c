//
// Created by Orina on 16.11.2021.
//
#define column 3
#define row 5

#include <stdio.h>
int E[column], A[column], C[row][column], R[row][column];
int temp = 0;


int ratio(int some_value){
    if (C[some_value][0] == -1) return 0;
    for(int i = 0; i < column; ++i) if (R[some_value][i] > A[i]) return 0;
    return 1;
}


void terminate(int some_value){
    for (int i = 0; i < column; ++i){
        A[i] += C[some_value][i];
        C[some_value][i] = -1;
        R[some_value][i] = -1;
    }
    temp++;
}


int main(){
    FILE *input = fopen("input1.txt", "r");
    for (int i = 0; i < column; ++i)
        fscanf(input, "%d", &E[i]);
    for (int i = 0; i < column; ++i)
        fscanf(input, "%d", &A[i]);
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            fscanf(input, "%d", &C[i][j]);
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            fscanf(input, "%d", &R[i][j]);
    for (int k = 0; k <= row; ++k)
        for(int i = 0; i < row; ++i)
            if (ratio(i)) terminate(i);
    if (temp >= row) printf("Ok\n");
    else printf("DeadLock\n");
    return 0;
}
