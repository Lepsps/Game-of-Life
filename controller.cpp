#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "game.h"
#include "view.h"




void controller() {
    while (1) {
        int play;
        int w;
        printf_s("Game Of Life\n");
        printf_s("Press 1 to play\n");
        printf_s("Press 2 to see config\n");
        scanf_s("%d", &play);
        system("cls");

        printf_s("Enter field size\n");
        int size = 0;
        int i = 0;

        while (size < 1) {
            scanf_s(" %d", &size);
            if (size == 0)
                printf_s("Error. Try again\n");
        }
        size += 2;
        system("cls");

        int** dopm1 = (int**)malloc(size * sizeof(int*));
        int** dopm2 = (int**)malloc(size * sizeof(int*));
        zapoln(dopm1, size);
        system("cls");

        if (play == 1) {
            input(dopm1, size);
            for (int j = 0; j < size; j++) {
                dopm2[j] = (int*)malloc(size * sizeof(int));
                for (int u = 0; u < size; u++)
                    dopm2[j][u] = dopm1[j][u];
            }
            while (1) {
                i += 1;
                system("cls");
                printq(dopm1, size);
                Sleep(500);
                game(dopm1, size);
                w = _kbhit();
                if (w) {
                    system("cls");
                    i = 0;
                    break;
                }
                if (i % 2 == 0) {
                    game(dopm2, size);
                    if (check_cikle(dopm1, dopm2, size)) {
                        printf("Game over\n");
                        Sleep(6000);
                        system("cls");
                        break;
                    }
                }
                
            }
        }
        else if (play == 2) {
            int q;
            printf_s("Choose number of config (1-5):");
            scanf_s("%d", &q);
            files(dopm1, size, q);
            for (int j = 0; j < size; j++) {
                dopm2[j] = (int*)malloc(size * sizeof(int));
                for (int u = 0; u < size; u++)
                    dopm2[j][u] = dopm1[j][u];
            }

            while (1) {
                i += 1;
                system("cls");
                printq(dopm1, size);
                Sleep(500);
                game(dopm1, size);
                w = _kbhit();
                if (w) {
                    system("cls");
                    i = 0;
                    break;
                }
                if (i % 2 == 0) {
                    game(dopm2, size);
                    if (check_cikle(dopm1, dopm2, size)) {
                        printf("Game over\n");
                        Sleep(6000);
                        system("cls");
                        break;
                    }
                }

            }

        }
    }
}



