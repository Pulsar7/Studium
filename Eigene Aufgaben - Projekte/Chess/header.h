#ifndef HEADER_H
#define HEADER_H
#define WIDTH 8
#define HEIGHT 8
#define USER_INPUT_LEN 10
#define MAX_PLAYER_NAME_LEN 50


typedef enum {True=0,False} Bool;
typedef enum {black,white} Color;

typedef struct Piece {
    int value;
    char letter;
    Color color;
} Piece;

typedef struct Player {
    Color color;
    char name[MAX_PLAYER_NAME_LEN];
} Player;

extern Piece wPawn;
extern Piece bPawn;
extern Piece wRook;
extern Piece bRook;
extern Piece wBishop;
extern Piece bBishop;
extern Piece wKing;
extern Piece bKing;
extern Piece wQueen;
extern Piece bQueen;

// functions
void show_chessboard(Piece (*chessboard)[WIDTH][HEIGHT]);
void draw_chessboard(Piece (*chessboard)[WIDTH][HEIGHT]);
void move_piece(Piece (*chessboard)[WIDTH][HEIGHT], char letter);

#endif