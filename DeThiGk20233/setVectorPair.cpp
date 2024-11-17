#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int val): data(val), next(NULL){}
};
class Set{
    private:
        Node* head;
    public:
        Set(): head(NULL){}
        bool contains(int value){
            Node* cur = head;
            while(cur != NULL){
                if(cur->data == value) return true;
                cur = cur->next;
            }
            return false;
        }
        void insert(int val){
            if(contains(val)){
                return;
            }
            Node* newNode = new Node(val);
            //chen vao dau danhs sach
            if(head == NULL || head->data > val){
                newNode->next = head;
                head = newNode;
                return;
            }
            //Tim vi tri chen nut moi
            Node* cur = head;
            while(cur->next != NULL && cur->next->data < val){
                cur = cur->next;
            }
             newNode->next = cur->next;  
        cur->next = newNode;  
        }
          // Hàm in ra các phần tử trong set  
    void print() {  
        Node* current = head;  
        while (current != nullptr) {  
            std::cout << current->data << " ";  
            current = current->next;  
        }  
        std::cout << std::endl;  
    }  
};
int main(){
    Set mySet;  
    mySet.insert(30);  
    mySet.insert(10);  
    mySet.insert(20);  
    mySet.insert(20); // Phần tử trùng sẽ không được chèn vào  
    mySet.insert(40);  
    mySet.insert(50);  

    std::cout << "Các phần tử trong set (được sắp xếp): ";  
    mySet.print();  
}