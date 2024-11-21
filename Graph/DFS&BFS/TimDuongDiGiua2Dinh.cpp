#include <bits/stdc++.h>
//Dung DFS or BFS deu ok
using namespace std;
int n, m, dem = 0;
vector<int> ke[1001];
bool visited[1001];
int id[1001];
void nhap(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int x,y; cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}
//thuat toan chinh
void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        id[x] = dem;
        for(int y : ke[x]){
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
}
int main(){
    nhap();
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dem++;
            BFS(i);
        }
    }
    int q; cin>>q;// số lần truy vấn
    while(q--){
        int x,y; cin>>x>>y; //2 đỉnh cần được xét
        if(id[x] == id[y]) cout<<"1";
        else cout<<"-1"<<endl;
    }
    //để không bị quá thời gian ta sẽ phân chia thành 2 thành phần liên thông để việc truy cập thông qua 
    //bien dem
    //chỉ mất O(1)
}
