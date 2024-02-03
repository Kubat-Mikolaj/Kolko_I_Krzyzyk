/*  Gra Kółko i Krzyżyk 
    Wersja I
    Mikołaj Kubat
    03.02.2024*/

#include <stdio.h>
#include <stdlib.h>

#include "kolko.h"

int main()
{
    /* Zdefiniowanie planszy do gry 3x3 */
    char board[3][3];
    int player;
    int row;
    int column;

    player = 1;
    row = 0;
    column = 0;

    inicjalizujPlansze(board);

    while (1)
    {
        plansza(board);

        printf("Gracz %d, podaj wiersz (0-2): ", player);
        scanf("%d", &row);

        printf("Gracz %d, podaj kolumnę (0-2): ", player);
        scanf("%d", &column);

        if (wykonajRuch(board, player, row, column))
        {
            
            zmienGracza(&player);
        }
        else
        {
            continue;
        }

        int zwyciestwo = sprawdzWygrana(board);
        if (zwyciestwo != 0)
        {
            printf("Gracz %d zwycięża!\n", zwyciestwo);
            return 0;
        }

        if (sprawdzRemis(board))
        {
            printf("Remis!\n");
            return 0;
        }
    }

    return 0;
}
