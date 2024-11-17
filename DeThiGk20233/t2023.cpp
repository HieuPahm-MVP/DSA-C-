#include <bits/stdc++.h>
using namespace std;
#define MS 100
class Map{
    private: 
        pair<int,int> arr[MS];
        int st;
        int size;
    public:
        Map() : size(0), st(MS / 2){} //khoi tao so luong phan tu la khong va don 2 phan tu vao giua
        //bo sung them phan tu
        void add(int k, int v){
            for(int i = st; i < st + size; i++){
                if(arr[i].first == k){
                    arr[i].second = v; //neu da ton tai thi cap nhat lai gia tri cua v
                    return;
                }
            }
            if(size < MS){
                arr[st + size] = make_pair(k,v);
                ++size;
            }
            else cout<<"Map is full";
        }
        //xoa di phan tu k cho truoc
        bool remove(int k){
            for(int i = st; i < st + size; i++){
                if(arr[i].first == k){
                    arr[i] = arr[st + size - 1];
                    //viec thay bang phan tu cuoi cung se lam cho toc do chay cua chuong trinh nhanh hon
                    --size;
                    return true;//xoa thanh cong
                }
            }
            return false;
        }
        //xay dung giai thuat de quy va cai dat thu tuc de quy
        int find(int k, int idx = 0){
            int realTime = st + idx;
            if(idx > size) return -1;
            if(arr[realTime].first == k) return arr[realTime].second;
            return find(k, idx + 1);
        }
        void display(){
            if (size == 0) {  
                std::cout << "Map is empty." << std::endl;  
                return;  
            }  
            for(int i = 0; i < size; i++){
                cout<<arr[st + i].first<<" "<<arr[st + i].second<<endl;
            }
        }
};
int main(){
    Map myMap;
    myMap.add(1, 100);  
    myMap.add(2, 200);  
    myMap.add(3, 200);  
    myMap.add(5, 200);  
    myMap.add(88, 200);  
    myMap.add(1, 150); // Cập nhật phần tử có key = 1  
    myMap.display(); // Hiển thị map sau khi xóa  

    std::cout << "Value for key 1: " << myMap.find(1) << std::endl;  
    std::cout << "Removing key 2: " << (myMap.remove(2) ? "Success" : "Not found") << std::endl;  
    // myMap.display(); // Hiển thị map sau khi xóa  
    

}