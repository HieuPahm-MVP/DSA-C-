#include <bits/stdc++.h>
using namespace std;
// cạnh cầu
int n,m;
vector<int> ke[1001];
vector<pair<int,int>> dscanh;
bool visited[1001];
void nhap(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int x,y; cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
    }
}
void DFS(int u, int s, int t){
    visited[u] = true;
    for(int v : ke[u]){
        if((v == t && u == s) || (u == t && v == s)) continue;
        if(!visited[v]) DFS(v,s,t);
    }
}
int tplt(int s, int t){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++ans;
            DFS(i,s,t);
        }
    }
    return ans;
}
int main(){
    nhap();
    int cc = tplt(0,0);
    int dem = 0;
    for(auto it : dscanh){
        int x = it.first, y = it.second;
        memset(visited, false, sizeof(visited));
        if(cc < tplt(x,y)) ++dem;
    }
    cout<<dem;
}