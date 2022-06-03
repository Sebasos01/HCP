#include "chartree.c"

int main(){
    Tree root = create_node('f', 777);
    Tree son = create_node('s', 666);
    add_son(root, son, 1);
    print_node(root);
    print_node(son);
    return 0;
}