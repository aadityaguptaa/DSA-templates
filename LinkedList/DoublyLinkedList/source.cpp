#include <bits/stdc++.h>

using namespace std;

class DLLNode{
public:
  int data;
  DLLNode *prev;
  DLLNode *next;
};

void insertion(DLLNode **head, int data, int position){
  DLLNode *newNode = new DLLNode();
  newNode->data = data;
  int k = 1;
  if(!newNode){
    cout <<"Memory Error"<<endl;
    return;
  }
  if(position == 1){
    newNode->prev=NULL;
    newNode->next=*head;
    if(*head){
     (*head)->prev=newNode;
    }
    *head = newNode;
    return;
  }
  DLLNode *temp = *head;
  while(k != position && temp->next != NULL){
    temp = temp->next;
    k++;
  }
  if(k != position){
    cout << "Desired position does not exist"<<endl;
    return;
  }
  newNode->next = temp->next;
  newNode->prev = temp;
  if(temp->next){
    temp->next->prev = newNode;
  }
  temp->next = newNode;
}

void deletion(DLLNode **head, int position){
  DLLNode *temp, *temp2 = *head;
  int k = 1;
  if(*head == NULL){
    cout<<"Empty List"<<endl;
    return;
  }
  if(position == 1){
    *head = (*head)->next;
    if((*head) != NULL){
      (*head)->prev = NULL;
      return;
    }
  }
  while(k <position && temp->next != NULL){
    temp = temp->next;
    k++;
  }
  if(k != position-1){
    cout<<"Desired position does not exist"<<endl;
    return;
  }
  temp2 = temp->prev;
  temp2->next=temp->next;
  if(temp->next){
    temp->next->prev=temp2;
  }
  return;
}

int main(void){

}
