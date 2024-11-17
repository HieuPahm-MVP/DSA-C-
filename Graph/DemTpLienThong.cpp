#include <bits/stdc++.h>
using namespace std;
bool visited[1005];
vector<int> ke[1005];
int n,m;

void DFS(int u){
    visited[u] = true;
    for(int x : ke[u]){
        if(!visited[x]){
            DFS(x);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        int x,y; cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            DFS(i);
            cnt++;
        }
    }
    cout<<cnt;
}