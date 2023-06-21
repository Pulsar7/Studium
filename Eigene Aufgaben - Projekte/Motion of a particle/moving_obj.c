#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define GA 9.81 // m/s²


// Solution?
int coordinate_system[100][100][2] = {
    {0,0}, {0,1}, {0,2}
};


typedef enum {True=0,False=1} Bool;
typedef struct Object {
    float x;  // m
    float y;  // m
    float vx; // m/s
    float vy; // m/s
    float m;  // kg
    float r;  // m -> Radius
    char obj_ch;
    Object *next;
    Object *previous;
} Object;

Object *head_pointer = NULL;

Object* create_obj_head(char obj_ch, float x, float y, float vx, float vy, float m, float r) {
    head_pointer = (Object*)malloc(sizeof(Object));
    if (head_pointer != NULL) {
        head_pointer->obj_ch = obj_ch;
        head_pointer->x = x;
        head_pointer->y = y;
        head_pointer->vx = vx;
        head_pointer->vy = vy;
        head_pointer->m = m;
        head_pointer->r = r;
        head_pointer->next = NULL;
        head_pointer->previous = NULL;
    } else {
        printf("Couldn't assign new space!\n");
    }
    return head_pointer;
}

Object* create_obj(char obj_ch, float x, float y, float vx, float vy, float m, float r) {
    Object *current = head_pointer;
    if (head_pointer == NULL) {
        current = create_obj_head(obj_ch,x,y,vx,vy,m,r);
        if (current == NULL) {
            return NULL;
        }
    }
    Object* current = head_pointer;
    while (current != NULL) {
        // iterates to the end of list
        current = current->next;
    }
    current->next = (Object*)malloc(sizeof(Object));
    current->next->next = NULL;
    current->next->previous = current;
    current->next->obj_ch = obj_ch;
    current->next->x = x;
    current->next->y = y;
    current->next->vx = vx;
    current->next->vy = vy;
    current->next->m = m;
    current->next->r = r;
    return current->next;
}

Bool delete_obj(char obj_char) {
    if (head_pointer == NULL) {
        printf("Couldn't delete %c - list is empty.\n",obj_char);
        return NULL;
    }
    Object *current = head_pointer;
    while (current != NULL) {
        if (current->obj_ch == obj_char) {
            break;
        }
        current = current->next;
    }
    if (current != NULL) {
        Object *new_current = current->previous;
        if (current->next == NULL && current->previous == NULL) {
            // Head-Pointer and length of list is 0
        }
        if (current->next == NULL && current->previous != NULL) {
            // Last element
            current->previous->next = NULL;
        }
        if (current->next != NULL && current->previous == NULL) {
            // Head-Pointer and length of list is not 0
            current->next->previous = NULL;
        }
        if (current->next != NULL && current->previous != NULL) {
            // Middle element
            current->next->previous == current->previous;
            current->previous->next = current->next;
        }
        free(current);
        return True;
    } else {
        printf("There is no element with the character '%c'\n",obj_char);
        return False;
    }
}

Bool delete_all_obj(void) {
    Bool status = True;
    if (head_pointer != NULL) {
        Object *current = head_pointer;
        while (current->next != NULL && status == True) {
            status = delete_obj(current->obj_ch);
        }
        return status;
    } else {
        printf("There is nothing to delete!\n");
        return False;
    }
}


Bool simulate_obj(Object *obj1, Object *obj2, float time) {
    obj1->x = obj1->vx * time + obj1->x;
    obj1->y = obj1->vy * time + obj1->y;
    obj1->vy -= GA * time;

    obj2->x = obj2->vx * time + obj2->x;
    obj2->y = obj2->vy * time + obj2->y;
    obj2->vy -= GA * time;

    if (obj1->y <= obj1->r) { 
        // obj1 collides with floor
    }

    if (obj2->y <= obj2->r) { 
        // obj2 collides with floor
    }

    // collisions with other object
    float distance = sqrt(pow(obj2->x - obj1->x, 2) + pow(obj2->y - obj1->y, 2));
    printf("d=%f | R_r=%f\n", distance, (obj1->r + obj2->r));
    if (distance <= (obj1->r + obj2->r)) {
        printf("Collission detected!\n");

        // Also wrong -> LeifiPhysik
        float v1 = sqrt(pow(obj1->vx, 2) + pow(obj1->vy, 2));
        float v2 = sqrt(pow(obj2->vx, 2) + pow(obj2->vy, 2));
        float result_v1 = (obj1->m * v1 + obj2->m * (2 * v2 - v1)) / (obj1->m + obj2->m);
        float result_v2 = (obj2->m * v2 + obj1->m * (2 * v1 - v2)) / (obj1->m + obj2->m);

        float obj2vx = obj2->vx;
        float obj2vy = obj2->vy;
        float obj1vx = obj1->vx;
        float obj1vy = obj1->vy;
        printf("Beforev1=%f - Resultv1=%f | Beforev2=%f - Resultv2=%f\n",v1,result_v1,v2,result_v2);
        /*
        obj1->vx = result_v1 * cos(atan2(obj1vy, obj1vx));
        obj1->vy = result_v1 * sin(atan2(obj1vy, obj1vx));
        obj2->vx = result_v2 * cos(atan2(obj2vy, obj2vx));
        obj2->vy = result_v2 * sin(atan2(obj2vy, obj2vx));
        */

        // OLD - probably non realistic calculations -> source?
        float total_v1 = sqrt(obj1->vx*obj1->vx + obj1->vy*obj1->vy);
        float total_v2 = sqrt(obj2->vx*obj2->vx + obj2->vy*obj2->vy);
        float v_ges_before = ((obj1->m*total_v1)+(obj2->m*total_v2));
        float final_v1 = ((obj1->m - obj2->m) * total_v1 + 2 * obj2->m * total_v2) / (obj1->m + obj2->m);
        float final_v2 = ((obj2->m - obj1->m) * total_v2 + 2 * obj1->m * total_v1) / (obj1->m + obj2->m);
        obj1->vx = final_v1 * cos(atan2(obj1->y,obj1->x));
        obj1->vy = final_v1 * sin(atan2(obj1->y,obj1->x));
        obj2->vx = final_v2 * cos(atan2(obj2->y,obj2->x));
        obj2->vy = final_v2 * sin(atan2(obj2->y,obj2->x));
    }
    return True;
}

int main(int argc, const char **argv) {
    // define first object 'ball'
    Object *ball = create_obj('B',-40,45,15,10,0,1.30);
    // define second object 'bullet'
    Object *bullet = create_obj('U',20,45,0.9,-10,0,0.09);
    // Data-File
    FILE *dataFile = fopen("obj_data.txt", "w");
    if (dataFile == NULL) {
        printf("Error while trying to open file!\n");
        return 1;
    }

    // simulating objects
    float time = 0.0;
    int floor_counter = 0;
    while (1) {
        simulate_obj(ball, bullet, time);
        printf("(BALL) X=%f | Y=%f | VX=%f | VY=%f\n", ball->x, ball->y, ball->vx, ball->vy);
        printf("(BULLET) X=%f | Y=%f | VX=%f | VY=%f\n", bullet->x, bullet->y, bullet->vx, bullet->vy);
        fprintf(dataFile, "%.2f;%.2f;%.2f;%.2f\n", ball->x, ball->y,
                bullet->x, bullet->y);
        if (ball->y < 0 || bullet->y < 0) {
            floor_counter++;
            if (floor_counter == 3) {
                printf("Object is on the ground.\n");
                break;
            }
        }
        time += 0.001;
    }
    fclose(dataFile);
    Bool status = delete_all_obj();
    return status;
}