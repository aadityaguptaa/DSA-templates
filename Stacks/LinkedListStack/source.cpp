#include <iostream>

using namespace std;

class stackNode{
public:
  int data;
  stackNode *next;
  
};

stackNode *head = NULL;
int size = 0;

void push(int x){
  stackNode *node= new stackNode();
  node->data = x;
  node->next = head;
  head = node;
  size++;
}

bool isEmpty(){
  return head == NULL && size == 0;
}

int pop(){
  if(head == NULL){
    cout << "Empty Stack"<<endl;
    return 0;
  }
  else{
    int x = head->data;
    head = head->next;
    size--;
    return x;
  }
}

int main(void){

}
