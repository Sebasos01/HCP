//#include "quicksort.c"
#include "chartree.c"
#include <stdio.h>
#include <stdlib.h>

#define D_SIZE 19 //Default size of the register in the heap
#define D_AUGMENTOR 10 //Default size of the augmentor

typedef struct table_row Row;
struct table_row{
    char chr;
    char* code;
    unsigned int frecuency;
    unsigned long int total_bits;
};

void set_table(Row* table[]);
void set_register(Row** pregister, FILE* f_pointer, Row* table[]);
void print_register(Row registerr[]);
Row* read_file(char source[], Row* table[]);
void sort_register(Row registerr[]);

int main(){
    Row* table[256];
    set_table(table);
    Row* registerr = read_file("oh_boy.txt", table);
    if (registerr == NULL){
        printf("Empty register\n");
        exit(1);
    }
    unsigned int sum = 0;
    unsigned int sum_c = 0;
    for (int i = 0; i < 256; i++){
        if (table[i] != NULL){
            sum++;
            sum_c += table[i]->frecuency;
            printf("%c %c %u %u %u\n", i, table[i]->chr, i, table[i]->chr, table[i]->frecuency);
        }
    }
    printf("The number of unique chars is: %u\n", sum);
    printf("The number of chars: %u\n", sum_c);     
    free(registerr);
    registerr = NULL;
    return 0;
}

void set_table(Row* table[]){
    for (int i = 0; i < 256; i++) {
        table[i] = NULL;
    }
}

void print_table(Row registerr[]){
    //To implement
}

void set_register(Row** pregister, FILE* f_pointer, Row* table[]){
    char ch;
    *(pregister) = (Row*) calloc(D_SIZE, sizeof(Row));
    if (*(pregister) == NULL){
        printf("Error allocating memory for the character register for the first time");
        exit(1);
    }
    Row* current_row = *(pregister);
    int current_size = D_SIZE;
    while ((ch = fgetc(f_pointer)) != EOF) {
        if (*(pregister) == NULL){
            printf("Error when trying to reallocate the character register\n");
            exit(1);
        }
        if (table[ch] == NULL){
            // Source of bugs
            // if ((current_row - *(pregister)) == current_size){
            //     *(pregister) = (Row*) realloc(*(pregister), (current_size = current_size + D_AUGMENTOR)*sizeof(Row));
            // }

            current_row->chr = ch;
            table[ch] = current_row;
            current_row++;
        }
        (table[ch]->frecuency)++;
    }
    printf("The final register size is: %u\n", current_size);
}

Row* read_file(char source[], Row* table[]){
    Row* registerr = NULL;
    FILE* f_pointer = NULL;
    f_pointer = fopen(source, "r");
    if (f_pointer == NULL){
        printf("The file is not available\n");
        exit(1);
    }
    else {
        set_register(&registerr, f_pointer, table);
    }
    fclose(f_pointer);
    return registerr;
}
