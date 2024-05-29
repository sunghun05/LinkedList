#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;     //102
    struct Node *next;
}Node;
Node *head = NULL;              //head는 첫번째 노드의 주소
Node *tail = NULL;              //tail은 마지막 노드의 주소
Node create() {
    int input = 0;
    if (head == NULL){          //head가 비어있을 때
        Node *firstNode = (Node*)malloc(sizeof(Node));
        head->next = &firstNode;//처음 노드의 주소를 참조
        tail->next = &firstNode;//처음 노드의 주소를 참조
        firstNode->data = input;//처음 노드의 데이터 삽입
    }else {                     //첫번쨰 노드가 이미 존재할 때
        Node *newNode = (Node*)malloc(sizeof(Node));
        tail->next = &newNode;  //새로운 노드의 주소를 tail이 참조
    }
}

void main(void) {
    create();
}
