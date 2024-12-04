#include <bits/stdc++.h>
using namespace std;
//cho cây nhị phân nhiệm vụ của bạn là đếm số lượng node trên cây node lá.
struct node{
    int data;
    node *left;
    node *right;
    node(int x){
        data = x;
        left = right = NULL;
    }
};
void makeNode(node *root, int u, int v, char c){
      if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}
void insertNode(node *root, int u, int v, char c){
    if(root == NULL) return;
    if(root->data = u){
        makeNode(root, u, v, c);
    }else{
        insertNode(root->left, u,v,c);
        insertNode(root->right, u, v, v);
    }
}
int demLa(node *root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int dem = 0;
    dem += demLa(root->left);
    dem += demLa(root->right);
    return dem;
}