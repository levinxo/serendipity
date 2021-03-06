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

int list_delete(list *link_list, int i, ele_type *data){
    int j = 0;
    list del_node;
    list p = *link_list;
    while (p && j < i){
        p = p->next;
        j++;
    }
    if (!p || j > i){
        return 0;
    }
    del_node = p->next;
    p->next = del_node->next;
    *data = del_node->data;
    free(del_node);
    return 1;
}

int get_ele(list link_list, int i, ele_type *e){
    int j = 0;
    list p = link_list->next;
    while (p && j < i){
        p = p->next;
        j++;
    }
    if (!p || j > i){
        return 0;
    }
    *e = p->data;
    return 1;
}

int locate_ele(list link_list, ele_type data){
    int i = 0;
    list p = link_list->next;
    while (p){
        if (p->data == data){
            return i;
        }
        i++;
        p = p->next;
    }
    return -1;
}

//反转单链表
void list_reverse(list* link_list){
    list pfirst = NULL;
    list p = NULL;
    if (!(*link_list)->next->next){
        return;
    }
    
    pfirst = (*link_list)->next;
    p = pfirst->next;
    while (p){
        pfirst->next = p->next;
        p->next = (*link_list)->next;
        (*link_list)->next = p;
        p = pfirst->next;
    }
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
    ele_type del_data;
    ele_type ele;
    list link_list;         //实际上link_list此时为头指针，还未指向头结点，即未赋值
    init_list(&link_list);  //头指针自己的地址
    for (i=0; i<10; i++){
        list_insert(&link_list, 0, 9-i);
    }
    printf("list length: %d\n", list_length(link_list));
    list_print(link_list);
    list_delete(&link_list, 5, &del_data);
    printf("删除第6个元素: %d\n", del_data);
    list_print(link_list);
    get_ele(link_list, 6, &ele);
    printf("获取第7个元素: %d\n", ele);
    printf("元素3的位置: %d\n", locate_ele(link_list, 3));
    printf("反转单链表: \n");
    list_reverse(&link_list);
    list_print(link_list);
}
