//đồ thị có hướng liên thông mạnh nếu giữa 2 đỉnh bất kì đều có đường đi
//Nếu đồ thị không liên thông mạnh thì nó sẽ chia thành các thành phần liên thông mạnh
//thuật toán Kosaruju --> tìm thành phần liên thông mạnh O(V+E)
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ke[1001], re_ke[1001];
bool visited[1001];
stack<int> st;

void nhap(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int x,y; cin>>x>>y;
        ke[x].push_back(y);
        re_ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void DFS1(int u){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]) DFS1(v);   
    }
    st.push(u);
}
void DFS2(int u){
    visited[u] = true;
    cout<<u<<' ';
    for(int v : re_ke[u]){
        if(!visited[v]) DFS2(v);
    }
}
void koSaRaJu(){
    for(int i = 1; i <= n; i++){
        if(!visited[i]) DFS1(i);
    }
    memset(visited, false, sizeof(visited));
    int scc = 0;
    while(!st.empty()){
        int u = st.top(); st.pop();
        if(!visited[u]){
            ++scc;
            cout<<"SCC"<<scc<<": ";
            DFS2(u);cout<<endl;
        }
    }
}
int main(){
    nhap();
    koSaRaJu();
}
