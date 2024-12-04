#include <bits/stdc++.h>
using namespace std;
//tìm độ cao lớn nhất của một node lá trên cây.
struct node{
    int data;
    node *left;
    node *right;
    node(int x){
        data = x;
        left = right = NULL;
    }
};
int count(node *root){
    if(root == NULL) return -1;
    return max(count(root->left) + 1, count(root->right) + 1);
}