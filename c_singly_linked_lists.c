/*
 * Singly linked linear lists
 */

#include "stdio.h"
#include "stdlib.h"

typedef int ele_type;

struct node {
    ele_type data;
    struct node *next;
};

typedef struct node *list;

void init_list(list *link_list){
    *link_list = (list) malloc(sizeof(struct node));    //给头指针赋值，即赋值为头结点的地址
    (*link_list)->next = NULL;                          //给头结点的指针域赋值为null，即首元结点为空
}

int list_length(list link_list){    //头指针
    int i = 0;
    list p = link_list->next;
    while (p && ++i){
        p = p->next;
    }
    return i;
}

int main(){
    list link_list;         //实际上link_list此时为头指针，还未指向头结点，即未赋值
    init_list(&link_list);  //头指针自己的地址
    printf("%d", list_length(link_list));
}
