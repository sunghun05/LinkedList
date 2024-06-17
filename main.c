#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    int data;
    struct Node *next;
};

Node create(Node *head, Node *p, int a) {
//    printf("\n=========================new node create====================\n");
    Node *newNode = (Node *)malloc(sizeof(Node));
//    printf("\n\nnew node is %d\n", newNode);

    newNode->data = a;
    newNode->next = NULL;

    if (head->next == NULL) {       //노드가 아예 없을때

        //printf("\nhead is NULL");

        head->next = (struct Node *) newNode;

    } else {                        //노드가 하나라도 있을때
        //printf("\nhead is NOT NULL");

        p = head;       //순회하는 포인터가 첫번째 노드를 가리킴

        while(p->next != NULL){
            p = p->next;
        }
        p->next = newNode;
    }

//    printf("\n%s", "newNode의 data : "); printf("%x", &newNode->data);
//    printf("\n%s", "head의 next : "); printf("%x", head->next);
//
//    printf("\n\n%d", head->next->data);

}
void search(Node *head, Node *p) {

    p = head;       //순회하는 포인터가 첫번째 노드를 가리킴

    while(p != NULL){
        p = p->next;
        printf("\n%d\n", p->data);
    }

}
void main(void) {
    Node *head = (Node *)malloc(sizeof(Node));
    Node *tail = (Node *)malloc(sizeof(Node));
    Node *p = (Node *)malloc(sizeof(Node));
    head->data = 0;
    tail->data = 0;
    tail->next = NULL;
    head->next = NULL;
    int menu = 0;

    while(1){
        int cnt = 0;

        printf("<---------enter the menu number : ");
        while(!scanf("%d", &menu)){
            printf("enter the correct menu number: ");
            while(getchar() != '\n');
        }
        switch (menu) {
            case 1 :
                printf("===================create list======================\n"
                       "enter a length of list : ");
                while(!scanf("%d", &cnt)){
                    printf("enter the correct number: ");
                    while(getchar() != '\n');
                }
                for(int i=0; i<cnt; i++) {
                    int data = 0;
                    printf("enter a data number : ");
                    while(!scanf("%d", &data)){
                        printf("enter the correct data number: ");
                        while(getchar() != '\n');
                    }
                    create(head, p, data);
                    while(getchar() != '\n');
                }


                break;
            case 2:
                search(head, p); while(getchar() != '\n');
                break;
            case -1 :
                return ;
        }
    }

}
