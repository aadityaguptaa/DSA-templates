#include <bits/stdc++.h>

using namespace std;

class Node{
public:
  int data;
  Node *next;
};

void push(Node **headRef, int data){
  Node* newNode = new Node();
  newNode -> data = data;
  newNode->next = *headRef;
  *headRef = newNode;
}

void insertAfter(Node *prevNode, int data ){
  if(prevNode == NULL){
    cout << "The given previous Node cannot be NULL"<<endl;
  }
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next=prevNode->next;
  prevNode->next = newNode->next;

}

void append(Node **headRef , int data){
  Node *newNode = new Node();
  newNode->data = data;
  Node *current = *headRef;
  if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }
  while(current->next != NULL){
    current = current->next;
  }
  current->next = newNode;
  newNode->next = NULL;
}

void printList(Node *head){
  Node * current = head;
  while (current != NULL) {
    std::cout << current->data <<" ";
    current = current->next;
  }
}

void deleteNodeFromLinkedList(Node **head, int position){
  if(*head == NULL){
    cout << "List Empty";
    return;
  }
  Node* prevNode;
  Node* currentNode;
  currentNode = *head;
  if(position == 1){
    *head = (*head)->next;
    return;
  }
  int k = 1;
  while((currentNode != NULL) && k < position){
    prevNode = currentNode;
    currentNode = currentNode->next;
  }
  prevNode->next = NULL;
  return;
}

int main(void){

  /* Start with the empty list */
    Node* head = NULL;

    // Insert 6. So linked list becomes 6->NULL
    append(&head, 6);

    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    push(&head, 7);

    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    push(&head, 1);

    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    append(&head, 4);

    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);

    cout<<"Created Linked list is: ";
    printList(head);

    return 0;

}
