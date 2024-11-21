#include <bits/stdc++.h>
using namespace std;

int n,m,s,t;
vector<int> ke[1001];
bool visited[1001];
int parent[1001]; // lưu giá trị cha của đỉnh đang xét
void nhap(){
    cin>>n>>m>>s>>t;
    for(int i = 0; i < m; i++){
        int x,y; cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
    }
}
//thuat toan dfs, tìm kiếm theo chiều sâu
void DFS(int u){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            DFS(v);
            parent[v] = u;
        }
    }
}
int main(){
    nhap();
    DFS(s);
    if(!visited[t]) cout<<"-1";
    else{
        vector<int> res;
        while(t != s){
            res.push_back(t);//đẩy cái đỉnh cuối cùng vào vector
            t = parent[t];// gán giá trị t mới bằng cha để nó lùi về được đỉnh đầu tiên
        }
        res.push_back(s);
        reverse(res.begin(), res.end());
        for(int x : res) cout<<x<<' ';
    }
}
