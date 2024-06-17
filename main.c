#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    int data;
    struct Node *next;
};

Node create(Node *head, Node *p, int a) {
    printf("\n=========================new node create====================\n");
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("\n\nnew node is %d\n", newNode);

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
        printf("\n%d\n", p->data);
        p = p->next;
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

//    printf("%x\n", &head->data);
//    printf("%x", &head->next);
//    printf("\n%x", head);

    create(head, p, 0);
    create(head, p, 1);
    create(head, p, 2);
    create(head, p, 3);
    search(head, p);
}
