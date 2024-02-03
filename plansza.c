// plansza.c
#include <stdio.h>
#include <stdlib.h>
#include "kolko.h"

#define tablicaX 3
#define tablicaY 3
// ANSI Escape Codes dla kolorów
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void plansza(char board[3][3])
{
    printf("Aktualny stan planszy: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'X')
                printf(ANSI_COLOR_RED " %c " ANSI_COLOR_RESET, board[i][j]);
            else if (board[i][j] == 'O')
                printf(ANSI_COLOR_GREEN " %c " ANSI_COLOR_RESET, board[i][j]);
            else
                printf(" %c ", board[i][j]);

            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("-----------\n");
    }
}

void inicjalizujPlansze(char board[3][3])
{
    int i;
    int j;

    for(i = 0; i < tablicaX; i++)
    {
        for(j = 0; j < tablicaY; j++)
        {
            board[i][j] = ' ';  // Ustawia każde pole planszy na puste (' ')
        }
    }
}

int  wykonajRuch(char board[3][3], int player, int row, int column)
{
    /* Sprawdź poprawność ruchu */
    if (row < 0 || row >= tablicaX || column < 0 || column >= tablicaY || board[row][column] != ' ')
    {
        printf("Ruch jest nieprawidłowy. Podaj nowy ruch. \n");
        return 0; 
    }

    /* Wykonanie ruchu */
    if(player == 1)
    {
        board[row][column] = 'X'; 
    }
    else if (player == 2)
    {
        board[row][column] = 'O';
    }
    return 1;
}

int sprawdzWygrana(char board[3][3])
{
    // Sprawdzanie warunku zwycięstwa poziomo
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return (board[i][0] == 'X') ? 1 : 2;
        }
    }

    // Sprawdzanie warunku zwycięstwa pionowo
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
        {
            return (board[0][j] == 'X') ? 1 : 2;
        }
    }

    // Sprawdzanie warunku zwycięstwa na skos
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return (board[0][0] == 'X') ? 1 : 2;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        return (board[0][2] == 'X') ? 1 : 2;
    }

    return 0; // Brak zwycięzcy
}

int sprawdzRemis(char board[3][3])
{
    // Sprawdzanie remisu
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0; // Gra nie jest zakończona
            }
        }
    }

    return 1; // Remis
}

void zmienGracza(int *player)
{
    // Zmiana gracza
    if (*player == 1) 
    {
        *player = 2;
    } 
    else 
    {
        *player = 1;
    }
}
