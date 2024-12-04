#include <bits/stdc++.h>
using namespace std;
//xác định có phải là cây nhị phân đầy đủ hay không?????
struct node{
    int data;
    node *left;
    node *right;
    node(int x){
        data = x;
        left = right = NULL;
    }
};

bool check(node *root){
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) return true;
    if(root->left != NULL && root->right != NULL){
        return check(root->left) && check(root->right);
    }
    else return false;
}