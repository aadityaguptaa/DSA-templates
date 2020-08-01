#include <bits/stdc++.h>

using namespace std;

class TreeNode(){
  int data;
  TreeNode *left;
  TreeNode *right;
}

void preOrderTraversalRecursive(TreeNode *root){
  if(root){
    cout << root->data;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }
}

void preOrderTraversalNonRecursive(TreeNode *root){
  stack<int> st;
  while(1){
    while(root){
      cout << root->data;
      st.push(root);
      root = root -> left;
    }
  }
  if(st.empty()){
    root = st.pop();
    root = root->right;
  }
}

void inOrderTraversalRecursive(TreeNode *root){
  if(root){
    inOrderTraversal(root->left);
    cout << root->data;
    inOrderTraversal(root->right);
  }
}

void postOrderTraversalRecursive(TreeNode *root){
  if(root){
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data;
  }
}

void levelOrderTraversal(TreeNode *root){
  queue<int> qu;
  if(!root){
    return;
  }
  qu.push(root);
  while(!qu.empty()){
    TreeNode *temp = qu.pop();
    cout << temp->data;
    if(temp->left){
      qu.push(temp->left);
    }
    if(temp->right){
      qu.push(temp->right);
    }
  }
}

int main (void){

}
