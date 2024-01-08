#include <stdio.h>
#include <string.h>

struct Car {
    int id;
    char name[20];
    char color[10];
};

int main() {

    struct Car Ferrari;
    Ferrari.id = 1;
    strcpy(Ferrari.name,"Ferrari");
    strcpy(Ferrari.color,"Red");


    printf("ID: %d\nName: %s\nColor: %s\n",Ferrari.id,Ferrari.name,Ferrari.color);
    
    return 0;
}