#include <bits/stdc++.h>
using namespace std;
//thuật toán được sử dụng để tìm đường đi ngắn nhất từ 1 đỉnh đến các đỉnh còn lại
//dùng cho vô hướng và có hướng O(E+V(logV))
struct edge{
    int x,y,w;
};
int n,m;
bool taken[10000];
vector<pair<int,int>> adj[100005];

void nhap(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int x,y,w; cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
}
void dijkstra(int s){
    vector<int> d(n+1, 1e9);
    d[s] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    Q.push({0,s});
    while(!Q.empty()){
        pair<int,int> top = Q.top(); Q.pop();
        int u = top.second, kc = top.first;
        if(kc > d[u]) continue;
        for(auto it : adj[u]){
            int v = it.first, w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v],v});
            }
        }
    }
    for(int i = 1; i <= n; i++) cout<<d[i]<<" ";
}