//Problem-1  Discuss how stacks can be used for checking balancing of symbols.

/*
Solution:

Stacks can be used to check whether the given expression has balanced symbols. This
algorithm is very useful in compilers. Each time the parser reads one character at a time. If the
character is an opening delimiter such as (, {, or [- then it is written to the stack. When a closing
delimiter is encountered like ), }, or ]-the stack is popped.

The opening and closing delimiters are then compared. If they match, the parsing of the string
continues. If they do not match, the parser indicates that there is an error on the line. A linear-time
O(n) algorithm based on stack can be given as:

Algorithm:

a) Create a stack.
b) while (end of input is not reached) {
      1) If the character read is not a symbol to be balanced, ignore it.
      2) If the character is an opening symbol like (, [, {, push it onto the stack
      3) If it is a closing symbol like ),],}, then if the stack is empty report an
      error. Otherwise pop the stack.
      4) If the symbol popped is not the corresponding opening symbol, report an
      error.
}
c) At end of input, if the stack is not empty report an error
*/

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------


#include <bits/stdc++.h>

using namespace std;

int main (void){

int noOfTestCases;
cin >> noOfTestCases;

  for(int i = 0; i < noOfTestCases; i++){
    int flag = 0;
    string inputString;
    cin >> inputString;
    int length = inputString.size();
    stack<char> s;
    for(int j = 0; j < length; j++){
      if(inputString[j] == '(' || inputString[j] == '[' || inputString[j] == '{'){
        s.push(inputString[j]);
      }else{
        if(s.top() == '('){
          if(inputString[j] != ')'){
            cout << "Unbalanced" << endl;
            s.pop();
            flag = 1;
            break;}
            s.pop();
          }else if(s.top() == '{'){
            if(inputString[j] != '}'){
              cout << "Unbalanced" << endl;
              s.pop();
              flag = 1;
              break;}
              s.pop();
          }else if(s.top() == '['){
            if(inputString[j] != ']'){
              cout << "Unbalanced" << endl;
              s.pop();
              flag = 1;
              break;
            }
            s.pop();
          }
        }
    }
    if(flag != 1){
      cout <<"Balanced" << endl;
    }
  }
}
