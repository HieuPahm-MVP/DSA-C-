#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *left;
    node *right;
    node (int x){
        val = x;
        left = right = NULL;
    }
};
void spiral(node * root){
    stack<node *> s1, s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            node *tmp = s1.top();
            s1.pop();
            cout<<tmp->val<<' ';
            if(tmp->right != NULL) s2.push(tmp->right);
            if(tmp->left != NULL) s2.push(tmp->left);
        }
        while(!s2.empty()){
            node *tmp = s2.top();
            s2.pop();
            cout<<tmp->val<<' ';
            if(tmp->left != NULL) s1.push(tmp->left);
            if(tmp->right != NULL) s1.push(tmp->right);
        }
    }
}