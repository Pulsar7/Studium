#include <stdio.h>
#include <math.h>
#define GA 9.81 // m/s²


typedef struct Object {
    float x;  // m
    float y;  // m
    float vx; // m/s
    float vy; // m/s
    float m;  // kg
    float r;  // m -> Radius
} Object;


int simulate_obj(Object *obj1, Object *obj2, float time) {
    obj1->x = obj1->vx*time+obj1->x;
    obj1->y = obj1->vy*time+obj1->y;
    obj1->vy -= GA*time;

    obj2->x = obj2->vx*time+obj2->x;
    obj2->y = obj2->vy*time+obj2->y;
    obj2->vy -= GA*time;


    // collisions with floor
    float obj1_floor_d = sqrt(pow(obj1->x - 0, 2) + pow(obj1->y - 0, 2));
    float obj2_floor_d = sqrt(pow(obj2->x - 0, 2) + pow(obj2->y - 0, 2));

    // collisions with other object
    float distance = sqrt(pow(obj2->x - obj1->x, 2) + pow(obj2->y - obj1->y, 2));
    printf("d=%f | R_r=%f\n",distance,(obj1->r+obj2->r));
    if (distance <= (obj1->r+obj2->r)) {
        printf("Collission detected!\n");
        obj1->vx = (obj1->vx * (obj1->m - obj2->m) + (2 * obj2->m * obj2->vx)) / (obj1->m + obj2->m);
        obj1->vy = (obj1->vy * (obj1->m - obj2->m) + (2 * obj2->m * obj2->vy)) / (obj1->m + obj2->m);
        
        obj2->vx = (obj2->vx * (obj2->m - obj1->m) + (2 * obj1->m * obj1->vx)) / (obj1->m + obj2->m);
        obj2->vy = (obj2->vy * (obj2->m - obj1->m) + (2 * obj1->m * obj1->vy)) / (obj1->m + obj2->m);
        
        /* OLD - probably non realistic calculations -> source?
        float total_v1 = sqrt(obj1->vx*obj1->vx + obj1->vy*obj1->vy);
        float total_v2 = sqrt(obj2->vx*obj2->vx + obj2->vy*obj2->vy);
        float v_ges_before = ((object->m*total_v1)+(object2->m*total_v2));
        float final_v1 = ((object->m - object2->m) * total_v1 + 2 * object2->m * total_v2) / (object->m + object2->m);
        float final_v2 = ((object2->m - object->m) * total_v2 + 2 * object->m * total_v1) / (object->m + object2->m);
        object->vx = final_v1 * cos(atan2(object->y,object->x));
        object->vy = final_v1 * sin(atan2(object->y,object->x));
        object2->vx = final_v2 * cos(atan2(object2->y,object2->x));
        object2->vy = final_v2 * sin(atan2(object2->y,object2->x));
        */
    } else {
        
    }
}


int main(int argc, const char **argv) {
    // define first object 'ball'
    Object ball;
    ball.x = -3;
    ball.y = 1;
    ball.m = 5.0;
    ball.vx = 10;
    ball.vy = 1;
    ball.r = 0.30;

    // define second object 'bullet'
    Object bullet;
    bullet.x = 3;
    bullet.y = 1;
    bullet.m = 0.1;
    bullet.vx = -10;
    bullet.vy = 1;
    bullet.r = 0.09;

    // Data-File
    FILE* dataFile = fopen("obj_data.txt", "w");
    if (dataFile == NULL) {
        printf("Error while trying to open file!\n");
        return 1;
    }

    // simulating objects
    float time = 0.0;
    int floor_counter = 0;
    while (1) {
        simulate_obj(&ball,&bullet,time);
        printf("(BALL) X=%f | Y=%f | VX=%f | VY=%f\n",ball.x,ball.y,ball.vx,ball.vy);
        printf("(BULLET) X=%f | Y=%f | VX=%f | VY=%f\n",bullet.x,bullet.y,bullet.vx,bullet.vy);
        fprintf(dataFile, "%.2f;%.2f;%.2f;%.2f\n",ball.x,ball.y,
            bullet.x,bullet.y
        );
        if (ball.y < 0 || bullet.y < 0) {
            floor_counter++;
            if (floor_counter == 3) {
                printf("Object is on the ground.\n");
                break;
            }
        }
        time += 0.001;
    }
    fclose(dataFile);
}