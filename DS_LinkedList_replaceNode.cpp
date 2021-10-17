//Nhập vào một số nguyên dương n, tiếp theo là n số nguyên của một dãy số, hãy cài đặt nó vào một danh sách liên kết đơn. Tiếp theo nhập hai số nguyên a và b.
//Hãy thay đổi giá trị của những phần tử có giá trị a thành giá trị b. In ra màn hình danh sách đó, sau một phần tử có đúng một khoảng trắng.


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

void convert(Node *head, int a, int b) {
    Node *p = head;
    while (p!=NULL) {
        if (p->data == a) {
            p->data = b;
        }
        p = p->next;
    }
}

void printList(Node*head) {
    Node *p = head;
    while (p!=NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

int main() {
    int n,x,a,b;
    cin >> n;
    cin >> x;
    Node *head = createNode(x);
    Node *p = head;
    for (int i=1; i<n;i++) {
        cin >> x;
        p = addNode(p,x);
    }
    cin >> a >> b;
    convert(head,a,b);
    printList(head);
    return 0;
}