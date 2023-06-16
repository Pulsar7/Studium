#include <stdio.h>
#include <math.h>

#define WIDTH 80    // Breite der Konsole
#define HEIGHT 24   // Höhe der Konsole

void plotPoint(char canvas[HEIGHT][WIDTH], int x, int y, char marker) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas[y][x] = marker;
    }
}

void printCanvas(char canvas[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char canvas[HEIGHT][WIDTH];
    
    // Initialisiere das Leinwand-Array mit Leerzeichen
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }
    
    double amplitude = HEIGHT / 2.0;
    double frequency = 0.1;
    
    // Berechne und zeichne die Kurve
    for (int x = 0; x < WIDTH; x++) {
        double y = amplitude * sin(frequency * x);
        int plotY = (int)(amplitude + y);
        
        plotPoint(canvas, x, plotY, '*');
    }
    
    // Gib die Leinwand aus
    printCanvas(canvas);
    
    return 0;
}