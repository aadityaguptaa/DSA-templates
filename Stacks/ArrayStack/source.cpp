#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

class ArrayStack{
  int top;
public:
  int array[MAX];

  ArrayStack(){
     top = -1;
  }

  bool push(int x){
    if(top > MAX -1){
      printf("Stack Overflow\n");
      return false;
    }else{
      array[++top] = x;
      return true;
    }
  }

  int pop(){
    if(top < 0){
      printf("Stack is Empty\n");
      return 0;
    }else{
      int x = array[top--];
      return x;
    }
  }

  int peek(){
    if(top < 0){
      printf("Stack in Empty\n");
      return 0;
    }else{
      return array[top];
    }
  }

  bool isEmpty(){
    return top < 0;
  }
};


int main(void){

  class ArrayStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";

    return 0;

}
