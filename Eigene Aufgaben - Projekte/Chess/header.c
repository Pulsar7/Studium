#include "header.h"
#include <stdio.h>

// Create Pieces
Piece wPawn = {1, 'p', white};
Piece bPawn = {1, 'p', black};
Piece wRook = {1, 'r', white};
Piece bRook = {1, 'r', black};
Piece wBishop = {1, 'b', white};
Piece bBishop = {1, 'b', black};
Piece wQueen = {1, 'q', white};
Piece bQueen = {1, 'q', black};
Piece wKing = {1, 'k', white};
Piece bKing = {1, 'k', black};
Piece empty = {-2, 'e', black};
Piece bKnight = {1, 'n', black};
Piece wKnight = {1, 'n', white};

// Functions

void draw_chessboard(Piece (*chessboard)[WIDTH][HEIGHT]) {
    (*chessboard)[0][0] = wRook;
    (*chessboard)[0][1] = wKnight;
    (*chessboard)[0][WIDTH-2] = wKnight;
    (*chessboard)[0][2] = wBishop;
    (*chessboard)[0][WIDTH-3] = wBishop;
    (*chessboard)[0][3] = wQueen;
    (*chessboard)[0][4] = wKing;
    (*chessboard)[0][WIDTH-1] = wRook;
    for (int r = 0; r < WIDTH; r++) {
        (*chessboard)[1][r] = wPawn;
    }
    for (int r = 0; r < WIDTH; r++) {
        (*chessboard)[HEIGHT-2][r] = bPawn;
    }
    (*chessboard)[HEIGHT-1][0] = bRook;
    (*chessboard)[HEIGHT-1][1] = bKnight;
    (*chessboard)[HEIGHT-1][WIDTH-2] = bKnight;
    (*chessboard)[HEIGHT-1][2] = bBishop;
    (*chessboard)[HEIGHT-1][WIDTH-3] = bBishop;
    (*chessboard)[HEIGHT-1][3] = bQueen;
    (*chessboard)[HEIGHT-1][4] = bKing;
    (*chessboard)[HEIGHT-1][WIDTH-1] = bRook;
}

void show_chessboard(Piece (*chessboard)[WIDTH][HEIGHT]) {
    printf("\e[1;1H\e[2J");
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if ((*chessboard)[WIDTH-1-i][HEIGHT-1-j].color == white) {
                printf("   %s%c   ","\x1b[37m",(*chessboard)[WIDTH-1-i][HEIGHT-1-j].letter);
            } else {
                printf("   %s%c   ","\x1b[90m",(*chessboard)[WIDTH-1-i][HEIGHT-1-j].letter);
            }
        }
        printf("\n\n");
    }
}

void move_piece(Piece (*chessboard)[WIDTH][HEIGHT], char letter) {
    
}