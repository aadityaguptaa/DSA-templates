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
  if(position == 1){
    newNode->prev=NULL;
    newNode->next=*head;
    if(*head){
     (*head)->prev=newNode;
    }
    *head = newNode;
    return;
  }

}

int main(void){

}
