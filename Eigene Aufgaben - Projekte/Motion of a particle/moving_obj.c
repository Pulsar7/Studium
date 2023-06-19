#include <stdio.h>
#include <math.h>
#define GA 9.81 // m/s²


typedef struct Object {
    float x; // m
    float y; // m
    float vx; // m/s
    float vy; // m/s
    float m; // kg
    float r; // m -> Radius
} Object;


int simulate_obj(Object *object, Object *object2, float time) {
    object->x = object->vx*time+object->x;
    object->y = object->vy*time+object->y;
    object->vy -= GA*time;

    object2->x = object2->vx*time+object2->x;
    object2->y = object2->vy*time+object2->y;
    object2->vy -= GA*time;

    // collisions
    float distance = sqrt(pow(object2->x - object->x, 2) + pow(object2->y - object->y, 2));
    printf("d=%f | R_r=%f\n",distance,(object->r+object2->r));
    if (distance <= (object->r+object2->r)) {
        printf("Collission detected!\n");

        float total_v1 = sqrt(object->vx*object->vx + object->vy*object->vy);
        float total_v2 = sqrt(object2->vx*object2->vx + object2->vy*object2->vy);
        float v_ges_before = ((object->m*total_v1)+(object2->m*total_v2));
        
    } else {
        
    }
}


int main(int argc, const char **argv) {
    // define first object 'ball'
    Object ball;
    ball.x = 0;
    ball.y = 1;
    ball.m = 1;
    ball.vx = 10;
    ball.vy = 5;
    ball.r = 1.0;

    // define second object 'bullet'
    Object bullet;
    bullet.x = 1;
    bullet.y = 1;
    bullet.m = 0.1;
    bullet.vx = -10;
    bullet.vy = 5;
    bullet.r = 0.1;

    // Data-File
    FILE* dataFile = fopen("obj_data.txt", "w");
    if (dataFile == NULL) {
        printf("Error while trying to open file!\n");
        return 1;
    }

    // simulating objects
    float time = 0.0;
    while (1) {
        simulate_obj(&ball,&bullet,time);
        printf("(BALL) X=%f | Y=%f | VX=%f | VY=%f\n",ball.x,ball.y,ball.vx,ball.vy);
        printf("(BULLET) X=%f | Y=%f | VX=%f | VY=%f\n",bullet.x,bullet.y,bullet.vx,bullet.vy);
        fprintf(dataFile, "%.2f;%.2f;%.2f;%.2f\n",ball.x,ball.y,
            bullet.x,bullet.y
        );
        if (ball.y < 0 || bullet.y < 0) {
            printf("Object is on the ground.\n");
            break;
        }
        time += 0.01;
    }
    fclose(dataFile);
}