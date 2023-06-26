#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"


Piece chessboard[WIDTH][HEIGHT];


Bool main(int argc, const char **argv) {
    srand(time(NULL));
    Player wplayer;
    Player bplayer;
    Player this_player;
    wplayer.color = white;
    bplayer.color = black;
    strcat(wplayer.name,"White");
    strcat(bplayer.name,"Black");
    if ((rand()%2)+0 == 1) {
        this_player.color = wplayer.color;
        strcat(this_player.name,wplayer.name);
    } else {
        this_player.color = bplayer.color;
        strcat(this_player.name,bplayer.name);
    }
    draw_chessboard(&chessboard);
    Bool status = True;
    char user_input[USER_INPUT_LEN];
    Bool rochade_status = True; // !
    printf("You are playing as '%s'\n",this_player.name);
    while (status == True) {
        show_chessboard(&chessboard);
        printf("> ");
        fgets(user_input,USER_INPUT_LEN,stdin);
        switch(user_input[0]) {
            case 'r': case 'R':
                // wants to move a rook
                move_piece(&chessboard)
                break;
            case 'p': case 'P':
                // wants to move a pawn
                break;
            case 'q': case 'Q':
                // wants to move a queen
                break;
            case 'n': case 'N':
                // wants to move a knight
                break;
            case 'k': case 'K':
                // wants to move the king
                break;
            default:
                printf("That's not a valid option!\n");
                break;
        }
    }
    return True;
}