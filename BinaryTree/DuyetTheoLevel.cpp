#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *left;
    node *right;
    node(int x){
        val = x;
        left = right = NULL;
    }
};
void makeRoot(node *root, int u, int v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}
void insertNode(node *root, int u, int v, char c){
    if(root == NULL) return;
    if(root->val == u) makeRoot(root,u,v,c);
    else{
        insertNode(root->left,u,v,c);
        insertNode(root->right,u,v,c);
    }
}
void levelOrder(node *root, int u, int v, char c){
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *tmp = q.front();
        q.pop();
        cout<<tmp->val<<' ';
        if(tmp->left != NULL){
            q.push(tmp->left);
        }
        if(tmp->right != NULL){
            q.push(tmp->right);
        }
    }
}   

int main(){
    node *root = NULL;
    int n; cin>>n;
    for(int i = 0; i < n; i++){
        int u,v; char c;
        if(root == NULL){
            root = new node(u);
            makeRoot(root,u,v,c);
        }
        else{
            insertNode(root,u,v,c);
        }
    }
}