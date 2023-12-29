#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


int count_buf = 0;
int count_buf_old = 0;

int sosedi(int x, int y, int** dopm) {
    int dx, dy;
    int count = 0;
    for (dx = -1; dx < 2; dx++) {
        for (dy = -1; dy < 2; dy++) {
            if (dopm[x + dx][y + dy]) {
                count++;
            }
        }
    }
    return count;
}

int check_cikle(int** dopm, int** dopm2, int n){
    int  c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dopm2[i][j] == dopm[i][j])
                c += 1;
        }
    }
    if (c == (n * n)) {
        return 1;
    }
    else { return 0; }
}



void game(int** dopm,int N) {
    int** buffer = (int**)malloc(N * sizeof(int*));
    zapoln(buffer, N);
    
    for (int x = 1; x < N - 1; x++)
        for (int y = 1; y < N - 1; y++)
            buffer[x][y] = dopm[x][y];

    for (int x = 1; x < N - 1; x++)
        for (int y = 1; y < N - 1; y++) {
            if (buffer[x][y] == 0) {
                if (sosedi(x, y, dopm) == 3)
                    buffer[x][y] = 1;
            }
            else {
                if (sosedi(x, y, dopm) == 3 || sosedi(x, y, dopm) == 4) {
                    buffer[x][y] = 1;
                }
                else { buffer[x][y] = 0; }
            }
        }

    for (int x = 1; x < N - 1; x++) {
        for (int y = 1; y < N - 1; y++) { 
            dopm[x][y] = buffer[x][y];
            

        }
    }
    for (int i = 0; i < N; i++) {
        free(buffer[i]);
    }
    
}

void zapoln(int** dopm, int size) {
    for (int i = 0; i < size; i++) {
        dopm[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            dopm[i][j] = 0;
        }
    }
}

