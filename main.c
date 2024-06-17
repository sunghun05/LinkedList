#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;     //102
    struct Node *next;

}Node;
Node *head = NULL;              //head는 첫번째 노드의 주소
Node *tail = NULL;              //tail은 마지막 노드의 주소

Node create() {
    Node a;
    Node b;
    Node c;
    a.data = 1;
    b.data = 2;
    c.data = 3;
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    head->next = &a;
    tail->next = &c;
}
void search() {
    while(head->next) {
        int **h = head->next;
        printf("%d", h);
        head->next = head->next;
    }
//    printf("%d", head->data);

}
void main(void) {
    int menu = 0;
    do {
        if(!scanf("%d", &menu)){
            printf("incorrect number");
            while(getchar() != '\n');
            continue;
        }
        if(menu == 1){
            create();
            while(getchar() != '\n');
            continue;
        }
        if(menu == 2){
            search();
            while(getchar() != '\n');
            continue;
        }
        else{ break;}
    }while(1);
}
