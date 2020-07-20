#include <iostream>

using namespace std;

class CLLNode{
public:
  int data;
  CLLNode *next;
};

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

int main(void){

}
