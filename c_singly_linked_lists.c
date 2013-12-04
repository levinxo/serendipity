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
    (*link_list)->next = NULL;                          //给头结点的指针域赋值为null，即首元结点指针为空
}

void list_print(list link_list){
    list p = link_list->next;
    printf("list ele: ");
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int list_insert(list *link_list, int i, ele_type data){
    int j = 0;
    list new_node = (list) malloc(sizeof(struct node));
    list p = *(link_list);
    while (p && j < i){
        p = p->next;
        j++;
    }
    if (!p || j > i){
        return 0;
    }
    new_node->data = data;
    new_node->next = p->next;
    p->next = new_node;
    return 1;
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
    int i;
    list link_list;         //实际上link_list此时为头指针，还未指向头结点，即未赋值
    init_list(&link_list);  //头指针自己的地址
    for (i=0; i<10; i++){
        list_insert(&link_list, 0, 9-i);
    }
    printf("list length: %d\n", list_length(link_list));
    list_print(link_list);
}
