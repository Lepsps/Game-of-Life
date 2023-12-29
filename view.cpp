#include "view.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>

void printq(int** dopm, int N) {
    for (int x = 1; x < N - 1; x++) {
        for (int y = 1; y < N - 1; y++) {
            if (dopm[x][y])
                fputs("#",stdout);
            else
                fputs("_", stdout);
        }
        fputs("\n",stdout);
    }
}



void input(int **dopm,int N) {
    char w;
    int x, y;
    x = y = 0;
    offset(0, 0);
    while (1) {

        w = _getch();
        switch (w) {
        case ' ':
            offset(x,y);
            if (dopm[y+1][x+1]) {
                dopm[y+1][x+1] = 0;
            }
            else {
                dopm[y+1][x+1] = 1;
            }
            offset(x, y);
            break;
        case 'w':
            offset(x, y);
            y -= 1;
            
            break;
        case 's':
            offset(x, y);
            y += 1;
            
            break;
        case 'a':
            offset(x, y);
            x -= 1;
  
            break;
        case 'd':
            offset(x, y);
            x += 1;
  
            break;
        }
        system("cls");
        printq(dopm, N);
        offset(x, y);
        if (w == 'e') {
            break;
        }
    }

}

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
void offset(short x, short y)
{
    COORD pole = { x, y };
    SetConsoleCursorPosition(handle, pole);

}



void files(int** dopm,int n,int q) {   
    if (q == 1) {
        const char* name = "./config/data1.txt";
        cikl(dopm, n, name);
    }
    else if (q == 2) {
        const char* name = "./config/data2.txt";
        cikl(dopm, n, name);
    }
    else if (q == 3) {
        const char* name = "./config/data3.txt";
        cikl(dopm, n, name);
    }
    else if (q == 4) {
        const char* name = "./config/data4.txt";
        cikl(dopm, n, name);
    }
    else if (q == 5) {
        const char* name = "./config/data5.txt";
        cikl(dopm, n, name);

    }
    

}

void cikl(int** dopm, int n, const char* name) {
    FILE* fp;
    fopen_s(&fp, name, "r");
    char* file = (char*)malloc(n * sizeof(char));


    for (int i = 1; i < n - 1; i++) {
        fgets(file, n*n, fp);
        for (int j = 1; j < n - 1; j++) {
            if (file[j] == '#') {
                dopm[i][j] = 1;
            }
            else {
                dopm[i][j] = 0;
            }

        }

    }

    fclose(fp);
}

