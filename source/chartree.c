#include <stdlib.h>
#include <stdio.h>

typedef struct treecharnode* Tree;
struct treecharnode{
    char value;
    unsigned int weight;
    Tree leftson, rightson, father;
};

Tree create_node(char value, int weight){
    Tree node = (Tree) calloc(1, sizeof(struct treecharnode));
    node->value = value;
    node->weight = weight;
    return node;
}

void add_son(Tree father, Tree son, char is_left){
    if (is_left){
        father->leftson = son;
    }
    else {
        father->rightson = son;
    }
    son->father = father;
}

void print_node(Tree node){
    printf("%p: {v:'%c', w: %u, f:%p, ls:%p, rs:%p}\n", node, node->value, node->weight,node->father, node->leftson, node->rightson);
}

