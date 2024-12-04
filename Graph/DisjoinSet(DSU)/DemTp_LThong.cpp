#include <bits/stdc++.h>
using namespace std;
int n,m;
int parent[10005];
//Tìm đỉnh đại diện cho tập hợp chứa u
int Find(int u){
    if(u == parent[u]) return u;
    int tmp = Find(parent[u]);
    parent[u] = tmp;
    return tmp;
}
bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    else{
        if(u < v) parent[v] = u;
        else parent[u] = v;
        return true;
    }
}
int main(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    for(int i = 0; i < m; i++){
        int x,y; cin>>x>>y;
        Union(x,y);
    }
    int dem = 0;
    for(int i = 1; i <= n; i++){
        if(i == parent[i]) ++dem;
    }
    cout<<dem<<endl;
}