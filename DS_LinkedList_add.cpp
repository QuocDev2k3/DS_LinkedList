//Nhập vào một số nguyên dương n, tiếp theo là n số nguyên của một dãy số, hãy cài đặt nó vào một danh sách liên kết đơn. 
//Tiếp theo nhập hai số nguyên k và x, (0 ≤ k ≤ n), hãy chèn giá trị x vào danh sách liên kết tại chỉ số k và in ra màn hình danh sách đó


#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *createNode(int x) {
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

Node *addNode(Node*p, int x) {
    Node *temp = createNode(x);
    p->next = temp;
    return temp;
}

Node *addHead(Node*head, int x) {
    Node *temp = createNode(x);
    temp->next = head;
    head = temp;
    return head;
}

void addMid(Node *head,int k, int x) {
    Node *p = head;
    for (int i=0; i<k-1; i++) {
        p = p->next;
    }
    Node *temp = createNode(x);
    temp->next = p->next;
    p->next = temp;
}

void printList(Node *head) {
    Node *p = head;
    while (p!= NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

int main() {
    int n,x,k,a;
    cin >> n;
    cin >> x;
    Node *head = createNode(x);
    Node *p = head;
    for (int i=1; i<n; i++) {
        cin >> x;
        p = addNode(p,x);
    }
    cin >> k >> a;
    if (k==0) {
        head = addHead(head,a);
    }
    else {
        addMid(head,k,a);
    }
    printList(head);
    return 0;
}
