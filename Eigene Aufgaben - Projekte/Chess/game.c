#include "game.h"
#include <string.h>


void draw_chessboard(Piece *chessboard) {
    int pawn_counter = 0, rook_counter = 0, bishop_counter = 0, knight_counter = 0;
    int piece_counter = 0;
    char name[] = "00";
    for (int i = 0; i < 8; i++) {
        if (i == 2) {
            pawn_counter = 0;
            rook_counter = 0;
            bishop_counter = 0;
            knight_counter = 0;
        }
        for (int j = 0; j < 8; j++) {
            piece_counter++;
            if (i > 1 && i < 6) {
                Piece empty;
                strcat(empty.name,"  ");
                chessboard[piece_counter] = empty;
            }
            if (i == 0) { // first row
                if (j == 0 || j == 7) { // white rook
                    rook_counter++;
                    Piece rook;
                    rook.color = White;
                    name[0] = 'r';
                    name[1] = rook_counter+'0';
                    printf("OLD='%s'\n",rook.name);
                    strcat(rook.name,name);
                    chessboard[piece_counter] = rook;
                    printf("NEW='%s'\n",rook.name);
                } else if (j == 1 || j == 6) { // white knight
                    knight_counter++;
                    Piece knight;
                    knight.color = White;
                    name[0] = 'k';
                    name[1] = knight_counter+'0';
                    strcat(knight.name,name);
                    chessboard[piece_counter] = knight;
                } else if (j == 2 || j == 5) { // white bishop
                    bishop_counter++;
                    Piece bishop;
                    bishop.color = White;
                    name[0] = 'b';
                    name[1] = bishop_counter+'0';
                    strcat(bishop.name,name);
                    chessboard[piece_counter] = bishop;
                } else if (j == 3) { // white Queen
                    Piece queen;
                    queen.color = White;
                    strcat(queen.name,"Q ");
                    chessboard[piece_counter] = queen;
                } else if (j == 4) { // white King
                    Piece king;
                    king.color = White;
                    strcat(king.name,"K ");
                    chessboard[piece_counter] = king;
                } 
            } else if (i == 1) { // second row -> white pawns
                pawn_counter++;
                Piece pawn;
                pawn.color = White;
                name[0] = 'p';
                name[1] = pawn_counter+'0';
                printf("[WHITE PAWNN] My name before before: '%s' | My name before: %s\n",pawn.name,name);
                strcat(pawn.name,name);
                chessboard[piece_counter] = pawn;
                printf("Second row\n");
            } else if (i == 6) { // seventh row -> black pawns
                pawn_counter++;
                Piece pawn;
                pawn.color = Black;
                name[0] = 'p';
                name[1] = pawn_counter+'0';
                strcat(pawn.name,name);
                chessboard[piece_counter] = pawn;
            } else if (i == 7) { // eighth row
                if (j == 0 || j == 7) { // black rook
                    rook_counter++;
                    Piece rook;
                    rook.color = Black;
                    name[0] = 'r';
                    name[1] = rook_counter+'0';
                    strcat(rook.name,name);
                    chessboard[piece_counter] = rook;
                } else if (j == 1 || j == 6) { // black knight
                    knight_counter++;
                    Piece knight;
                    knight.color = Black;
                    name[0] = 'k';
                    name[1] = knight_counter+'0';
                    strcat(knight.name,name);
                    chessboard[piece_counter] = knight;
                } else if (j == 2 || j == 5) { // black bishop
                    bishop_counter++;
                    Piece bishop;
                    bishop.color = Black;
                    name[0] = 'b';
                    name[1] = bishop_counter+'0';
                    strcat(bishop.name,name);
                    chessboard[piece_counter] = bishop;
                } else if (j == 3) { // black Queen
                    Piece queen;
                    queen.color = Black;
                    strcat(queen.name,"Q ");
                    chessboard[piece_counter] = queen;
                } else if (j == 4) { // black King
                    Piece king;
                    king.color = Black;
                    strcat(king.name,"K ");
                    chessboard[piece_counter] = king;
                } 
            }
        }
    }
}

void show_chessboard(Piece *chessboard) {
    for (int i = 0; i < 64; i++) {
        printf("  '%s'  ",chessboard[i].name);
        if (i%8 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

Bool check_if_move_is_legal(Piece piece, int *new_position) {
    return False;
}

Bool move_piece(Piece piece, int *new_position) {
    
    return False;
}