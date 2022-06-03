#include <stdio.h>

void foo();

int main(){
    printf("Primer paso!\n");
    foo();
    printf("Llegué hasta aquí!\n");
    return 0;
}

void foo(){
    exit(1);
}