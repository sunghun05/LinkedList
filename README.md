#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
    int data;//노드의 정수형 데이터 저장
    struct Node *next;//다음 노드의 주소 저장
};

void create(Node *head, Node *p, int a) {//node 생성
    Node *newNode = (Node *)malloc(sizeof(Node));//새로운 노드 생성

    newNode->data = a;  //새로운 노드의 데이터에 정수형 자료 입력
    newNode->next = NULL;   //노드의 다음 노드의 주솟값을 저장하는 포인터 초기화

    if (head->next == NULL) {       //노드가 아예 없을때
        head->next = (struct Node *) newNode;   //헤드의 다음 노드를 가리키는 포인터는 새로운 노드
    }
    else {                        //노드가 하나라도 있을때
        p = head;       //순회하는 포인터가 첫번째 노드를 가리킴
        while (p->next != NULL) {
            p = p->next;                //마지막 노드까지 이동
        }
        p->next = newNode;              //마지막 노드가 가리키는 노드를 새로운 노드로 지정
    }

}
void search(Node *head, Node *p) {//검색 함수
    p = head;       //순회하는 포인터가 헤드를 가리킴
    while(p->next != NULL){  //마지막 노드까지 반복
        p = p->next;
        printf("\n%d\n", p->data);  //노드를 순회하며 값 출력
    }
}
void insert(Node* head, Node* p, int index, int data) {  //삽입 함수
    p = head;                                            //순회하는 포인터를 헤드로 위치
    for (int i = 0; i != index; i++) {                  //삽입 인덱스 전 까지 이동
        p = p->next;

    }
    printf("\ninsert\n");                                
    Node* newNode = (Node*)malloc(sizeof(Node));          //새로운 노드 생성
    Node* tmp = (Node*)malloc(sizeof(Node));              //임시 노드 생성
    newNode->data = data;                                  //새 노드에 데이터 삽입
    tmp = p->next;                                        //임시 노드를 원하는 인덱스 다음 인덱스 노드로 지정
    p->next = newNode;                                    //p가 가리키는 노드를 새로운 노드로 지정
    newNode->next = tmp;                                  //새 노드의 다음 노드를 임시 노드를 가리키도록 지정
}
void append(Node* head, Node* p, int data) {               //append 함수
    p = head;                                             //순회하는 포인터가 첫번째 노드를 가리킴
    while (p->next != NULL) {
        p = p->next;                                      //마지막 노드까지 이동
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    p->next = newNode;                                    //마지막 노드가 가리키는 노드를 새로운 노드로 지정
    newNode->data = data;
    newNode->next = NULL;                                  //마지막 노드가 가리키는 노드는 항상 NULL이다.
}
int pop(Node* head) {                                      //pop함수, 마지막 노드를 없애고 마지막 노드의 데이터를 리턴
    int data ;
    Node* p = (Node*)malloc(sizeof(Node));
    Node* tmp = (Node*)malloc(sizeof(Node));
    p = head;
    tmp = head;
    while(p->next != NULL){
        p = p->next;                                       //마지막 노드까지 이동 P
    }
    while(tmp->next != p){
        tmp = tmp->next;                                  //p노드 전까지 이동
    }
    data = p->data;                                       
    tmp->next = NULL;                                     //임시 노드가 가리키는 노드를 NULL
    
    free(p->next);                                        //마지막 노드 삭제
    free(p);
    
    return data;                                          //데이터 리턴
}
int max(Node*head){
    Node* p = (Node*)malloc(sizeof(Node));
    int num=0;
    p = head;
    
    while(p->next != NULL){
        p = p->next;
        if(p->data > num){
            num = p->data;
        }
    }
    return num;
}
void print(Node*head){
    Node *p = (Node*)malloc(sizeof(Node));
    p = head;
    int j = 0;
    while(p->next != NULL){
        p = p->next;
        j++;
    }
    for (int i = 0;i<j;i++){
        printf("_____     ");
    }
    printf("\n");
    p = head;
    while(p->next != NULL){
        p = p->next;
        printf("| %d | --->", p->data);
    }
    printf("\n");
    for (int i = 0;i<j;i++){
        printf("-----     ");
    }
    printf("\n");
}
int main() {
    int menu = 0;

    while(1){

        int cnt = 0;
        int data;
        int index;
        int n = 0;

        printf("<---------enter the menu number (1 : create list, 2 : search lists, 3 : insert, 4 : append, 5 : pop, 6 : max, 7 : print  -1 : exit) : ");
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
            case 5 :
                n = pop(head);
                printf("\npop : %d\n", n);
                break;
            case 6 :
                n = max(head);
                printf("\nmax value is : %d\n", n);
                break;
            case 7:
                print(head);
                break;
            case -1 :
                return 0;
        }
    }
}
