// Bài 16. Điện thoại cục gạch
// Cho xâu kí tự S chỉ bao gồm các số từ 2 tới 9, mỗi chữ số này trên bàn phím của
// điện thoại cục gạch tương ứng với 3 chữ cái như trong hình bên dưới. Bạn hãy in
// ra các xâu kí tự có thể tạo thành bằng cách ấn mỗi chữ số trong xâu S đúng 1
// lần. Bạn hãy in ra các xâu kết quả theo thứ tự từ điển tăng dần.
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<char> v[10];
char x[10];
void xuly(){
    int idx = 2, cnt = 0;
    for(char c = 'a'; c <= 'z'; c++){
        v[idx].push_back(c);
        if(idx == 7 || idx == 9){
            if(v[idx].size() == 4) ++idx;
        }
        else{
            if(v[idx].size() == 3) ++idx;
        }
    }
}
void ql(int i,string res){
    int num = s[i] - '0';
    for(char c : v[num]){
        x[i] = c;
        if(i == num){
            cout<<res + c<<" ";
        }
        else ql(i+1,res+c);
    }
}
int main(){
    xuly();
    cin>>s;
    sort(s.begin(),s.end());
    n = s.length();
    s = '0' + s;
    string tmp = "";
    ql(1,tmp);
}