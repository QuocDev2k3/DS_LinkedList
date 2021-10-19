//Xây dựng danh sách liên kết đơn. Nhập x, n tạo thành danh sách liên kết( Mỗi nút có 2 giá trị x và i, i chạy từ 1 -> n)
//s(x,n) = x^1 + x^2 + x^3 + ... + x^n
//Viết hàm xuất ra tổng các phần tử trong danh sách liên kết.


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *createNode(int x) {
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

Node *addNode(Node *head, int x) {
    Node *temp = createNode(x);
    head->next = temp;
    return temp;
}

int getLT(int x, int i) {               // Hàm tính lũy thưà
    int m = x;
    for (int j=1; j<i; j++) {
        m*=x;
    }
    return m;
}

void printSum(Node*head) {              // Hàm in tổng
    int Sum = 0;
    Node *p = head;
    while (p!=NULL) {
        Sum += p->data;
        p = p->next;
    }
    cout << "Sum of linked list = "<< Sum << endl; 
}

int main() {
    int x,n;
    cin >> n;
    cin >> x;
    Node *head = createNode(x);
    Node *p = head;
    for (int i=1; i<n; i++) {
        int k = getLT(x,i+1);
        p = addNode(p,k);
    }
    printSum(head);
    return 0;
}