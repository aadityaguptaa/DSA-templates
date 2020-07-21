#include <iostream>

using namespace std;

//blueprint of list node
class CLLNode{
public:
  int data;
  CLLNode *next;
};

//returns the length of Circular Linked List
int CircularListLength(CLLNode **head){
  int k = 0;
  CLLNode *current = *head;
  if(*head == NULL){
    return 0;
  }
  do{
    current = current->next;
    k++;
  }while(current != *head);
  return k;
}

//Prints Circular Linked List Data
void printCircularListData(CLLNode **head){
  CLLNode *current = *head;
  if(*head == NULL){
    return;
  }
  do{
    printf("%d ", current->data);
    current = current->next;
  }while(current != *head);
}

//insert element to the list
void insertNode(CLLNode **head, int data, int position){
  CLLNode *newNode = new CLLNode();
  newNode->data = data;

  //insert at the end
  if(CircularListLength(head) == position){
    CLLNode *temp = *head;
    while(temp->next != *head){
      temp = temp->next;
    }

    newNode->next = newNode;

    if(*head == NULL){
      *head = newNode;
    }else{
      newNode->next = *head;
      temp->next = newNode;
    }
    return;
  }
  //inserts at the beginning
  else if(position == 1){
    newNode->next = newNode;
    if(*head == NULL){
      *head = newNode;
      return;
    }
    CLLNode *temp = *head;
    while(temp->next != *head){
      temp = temp->next;
    }

    if(*head == NULL){
      *head = newNode;
    }else{
      newNode->next = *head;
      temp->next = newNode;
      *head = newNode;
    }
    return;
  }
  //inserts in the middle
  int k = 1;
  CLLNode *current = *head;
  while(k < position-1){
    current = current->next;
    k++;
  }
  newNode->next = current->next;
  current->next = newNode;
}

void DeletingFrontNodeFromCLL(CLLNode **head){
  if(*head == NULL){
    printf("List is empty\n");
    return;
  }
  CLLNode *current = *head;
  while ((current->next) != *head) {
    current = current->next;
  }
  current->next = (*head)->next;
  *head = (*head)->next;
}

//driver function
int main(void){

  CLLNode *head = NULL;

  insertNode(&head, 5, 1);
  insertNode(&head, 99, 1);
  insertNode(&head, 2, 2);
  insertNode(&head, 3, 2);
  insertNode(&head, 100, 3);
  DeletingFrontNodeFromCLL(&head);
  printCircularListData(&head);

}
