#include <bits/stdc++.h>
using namespace std;
// Tổ hợp có tổng bằng X
// Cho mảng A[] gồm N số nguyên dương phân biệt và số X. Nhiệm vụ của bạn là
// tìm phép tổ hợp các số trong mảng A[] có tổng bằng X. Các số trong mảng A[] có
// thể được sử dụng nhiều lần. Mỗi tổ hợp các số của mảng A[] được in ra theo thứ
// tự không giảm các số. Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số
// như sau: {2, 2, 2, 2}, {2, 2, 4}, {2, 6}, {4, 4}, {8}.
int n,a[100],x[100],s;
vector<vector<int>> v;
void ql(int i, int bd, int sum){
    for(int j = bd; j <= n; j++){
        if(sum + a[j] <= s){
            x[i] = a[j];
            if(sum + a[j] == s){
                vector<int> tmp(x+1, x + i + 1);
                v.push_back(tmp);
            }
            else ql(i + 1, j, sum + a[j]);
        }
    }
}
int main(){
    cin>>n>>s;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ql(1,1,0);
    if(v.size() == 0) cout<<"-1";
    else{
        cout<<v.size()<<endl;
        for(auto it : v){
            cout<<"{";
            for(int i = 0; i < it.size(); i++){
                cout<<it[i];
                if(i < it.size() - 1) cout<<" ";
            }
            cout<<"}\n";
        }
    }
}