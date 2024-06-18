#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    int data;
    struct Node *next;
};

Node create(Node *head, Node *p, int a) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = a;
    newNode->next = NULL;

    if (head->next == NULL) {       //노드가 아예 없을때
        head->next = (struct Node *) newNode;
    }
    else {                        //노드가 하나라도 있을때
        p = head;       //순회하는 포인터가 첫번째 노드를 가리킴
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
    }

}
void search(Node *head, Node *p) {
    p = head;       //순회하는 포인터가 첫번째 노드를 가리킴
    while(p->next != NULL){
        p = p->next;
        printf("\n%d\n", p->data);
    }
}
void insert(Node* head, Node* p, int index, int data) {
    p = head;
    for (int i = 0; i != index; i++) {
        p = p->next;

    }
    printf("\ninsert\n");
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* tmp = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    tmp = p->next;
    p->next = newNode;
    newNode->next = tmp;
}
void append(Node* head, Node* p, int data) {
    p = head;       //순회하는 포인터가 첫번째 노드를 가리킴
    while (p->next != NULL) {
        p = p->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    p->next = newNode;
    newNode->data = data;
    newNode->next = NULL;
}
void main(void) {
    int menu = 0;

    while(1){

        int cnt = 0;
        int data;
        int index;

        printf("<---------enter the menu number (1 : create list, 2 : search lists, 3 : insert, 4 : append,  -1 : exit) : ");
        while(!scanf("%d", &menu)){
            printf("enter the correct menu number: ");
            while(getchar() != '\n');
        }
        switch (menu) {
            case 1 :
                printf("===================create list======================\n"
                       "enter a length of list : ");
                Node* head = (Node*)malloc(sizeof(Node));
                Node* p = (Node*)malloc(sizeof(Node));
                head->data = 0;
                head->next = NULL;
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
            case 3:
                printf("\nenter a index : ");
                scanf("%d", &index);
                printf("\nenter a data : ");
                scanf("%d", &data);
                insert(head, p, index, data);
                break;
            case 4 :
                printf("\nenter a data : ");
                scanf("%d", &data);
                append(head, p, data);
                break;
            case -1 :
                return ;
        }
    }
}
