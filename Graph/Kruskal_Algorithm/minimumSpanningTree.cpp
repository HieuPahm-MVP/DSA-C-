//cây khung cực tiểu --> không được tạo thành 1 chu trình
//sử dụng DSU để thực hiện KrusKal
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct edge{
    int x,y,w;
};
int n,m;
int sz[100005], parent[1000001];
vector<edge> dscanh;
//DSU
void ktao(){
    for(int i = 1; i <= n; i++){
        sz[i] = 1;
        parent[i] = i;
    }
}
int Find(int u){
    if(u == parent[u]) return u;
    else return parent[u] = Find(parent[u]);
}
bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] > sz[v]){
        parent[v] = u;
        sz[u] += sz[v];
    }
    else{
        parent[u] = v;
        sz[v] += sz[u];
    }
    return true;
}
void nhap(){
    for(int i =0; i<m; i++){
        int x,y,w; cin>>x>>y>>w;
        dscanh.push_back({x,y,w});
    }
}
void Kruskal(){
    //Buoc 1: sap xep danh sach canh theo trong so tang dan
    sort(dscanh.begin(),dscanh.end(), [](edge a, edge b)-> bool{
        return a.w < b.w;
    });
    //b2 : lap
    int d = 0;
    vector<edge> mst;
    for(int i = 0; i < m; i++){
        if(mst.size() == n - 1) break;
        edge e = dscanh[i];
        if(Union(e.x, e.y)){
            mst.push_back(e);
            d += e.w;
        }
    }
    cout<<d<<endl; // trong so tren cay
}
int main(){
    nhap();
    ktao();
    Kruskal();
}