/* Plik nagłókowy do programu kółko i krzyżyk 
   Mikołaj Kubat
   03.02.2024**/

#ifndef KOLKO_I_KRZYZYK_H
#define KOLKO_I_KRZYZYK_H

/* Deklarownanie funkcji */

// Deklaracje funkcji
void plansza(char board[3][3]);
void inicjalizujPlansze(char board[3][3]);
int wykonajRuch(char board[3][3], int player, int row, int column);
int sprawdzWygrana(char board[3][3]);
int sprawdzRemis(char board[3][3]);
void zmienGracza(int *player);


#endif
