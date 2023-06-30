#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <stdlib.h>

typedef enum {True,False} Bool;
typedef enum {Black,White} Color;

typedef struct {
    char name[2];
    Color color;
} Piece;

// Functions
void draw_chessboard(Piece *chessboard);
Bool move_piece(Piece piece, int *new_position);
void show_chessboard(Piece *chessboard);

#endif