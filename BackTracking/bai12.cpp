#include <bits/stdc++.h>
using namespace std;
// Cho mảng A[] gồm n phần tử, hãy xác định xem có thể chia mảng A[] thành 2 tập
// sao cho tổng của 2 tập bằng nhau hay không?
int n,s = 0, a[100],x[100], ok = 0;
void ql(int i, int bd, int sum){
    if(ok) return;
    for(int j = bd; j <= n; j++){
        if(sum + a[j] <= s){
            x[i] = a[j];
            if(sum + a[j] == s) ok = 1;
            else ql(i + 1, j + 1, sum + a[j]);
        }
    }   
}
int main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        s += a[i];
    }
    if(s % 2 == 1) return 0;
    s /= 2;
    sort(a+1, a+n+1);
    ql(1,1,0);
}