#include <stdio.h>
#include <stdlib.h>
#define FG_A 9.81 // m/s


/* 2-D Simulation of an object
    -> without air-resistance
*/

typedef enum {true,false} BOOLEAN;
typedef struct Object {
    float x; // X-Coordinate in m
    float y; // Y-Coordinate in m
    float vx; // velocity in x-direction in m/s
    float vy; // velocity in y-direction in m/s
} Object;


BOOLEAN update_obj_position(Object *object, float time) {
    object->x = object->vx*time;
    object->y = object->vy*time;
    object->vy -= FG_A*time;
    if (object->vx == 0 && object->vy == 0) {
        printf("Object isn'nt moving anymore!\n");
        return false;
    }
    return true;
}


int main(int argc, const char **argv) {
    BOOLEAN status;
    Object bullet;
    bullet.x = 0;
    bullet.y = 0;
    bullet.vx = 20;
    bullet.vy = 10;
    FILE* dataFile = fopen("projectile_data.txt", "w");
    if (dataFile == NULL) {
        printf("Error while trying to open file!\n");
        return 1;
    }
    float time = 0.0;
    for (int steps = 0; steps < 10; steps++) {
        time = steps*0.01;
        fprintf(dataFile, "%.2f %.2f\n", bullet.x, bullet.y);
        status = update_obj_position(&bullet,time);
        if (status == true) {
            printf("(%f s) x = %f | y = %f | vx = %f | vy = %f\n",time,bullet.x,bullet.y,bullet.vx,bullet.vy);
        } else {
            break;
        }
    }
    fprintf(dataFile, "%.2f %.2f\n", bullet.x, bullet.y);
    fclose(dataFile);
    FILE* gnuplotPipe = popen("gnuplot -persist", "w");
    if (gnuplotPipe == NULL) {
        printf("Couldn't open GNUplot!\n");
        return 1;
    }
    
    fprintf(gnuplotPipe, "plot 'projectile_data.txt' with lines\n");
    
    // Schließe die GNUplot-Pipe
    fclose(gnuplotPipe);
    printf("Simulation finished.\n");
    return 0;
}