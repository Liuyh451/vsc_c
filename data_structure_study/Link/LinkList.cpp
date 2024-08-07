#include <iostream>
using namespace std;
typedef struct Node
{
    /* data */
    int data;
    struct Node* next;
} List;
void selectSort(List*&L){
    List*p=L,*q,*r;
    while (p)
    {
        /* code */
        q=p;r=p->next;
        while (r)
        {
            if(r->data>q->data){
                q=r;
            }
            r=r->next;
        }
        int temp=q->data;q->data=p->data;p->data=temp;
        p=p->next;

    }
    
}
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
// 插入节点到链表头部
void insertAtHead(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}
// 打印链表元素
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main(){
    struct Node* list = NULL;
    // 插入元素
    insertAtHead(&list, 4);
    insertAtHead(&list, 2);
    insertAtHead(&list, 6);
    insertAtHead(&list, 1);
    insertAtHead(&list, 5);
    insertAtHead(&list, 3);
    printList(list);
    selectSort(list);
    printList(list);
}
