//Nhập vào một số nguyên n, tiếp theo là n số nguyên của một dãy số.
//Hãy cài đặt nó vào một danh sách liên kết đơn và in ra màn hình danh sách đó, sau mỗt phần tử có đúng một khoảng trắng.


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *createNode(int x) {            //Hàm tạo Node, trả về 1 node temp với data x và con trỏ next=NULL
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

Node *addNode(Node *p,int x) {       //Hàm chèn thêm phần tử cuối, tương tự createNode nhưng nó trả lại node temp mới lúc này đã nằm cuối danh sách thay cho p ban đầu
    Node *temp = createNode(x);
    p->next = temp;
    return temp;
}

void printing(Node*head) {           // Gán cho node tạm thời (p) Node đầu 1 linkedlist (head), sau đó từ từ dịch node đến cuối danh sách 
    Node *p = head;
    while (p!=NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

int main() {
    int n,x;
    cin >> n;
    cin >> x;                          //Nhập giá trị cho node Head
    Node *head = createNode(x);       //Khởi tạo node Head với giá trị x
    Node *p = head;                   //Tạo 1 node mới, tạm thời đặt nó là node Head
    for (int i=1; i<n; i++) {
        cin >> x;
        p= addNode(p,x);             //Liên tục chèn node vào sau nó
    }
    printing(head);
    return 0;
}


