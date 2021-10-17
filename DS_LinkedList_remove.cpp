//Nhập vào một số nguyên dương n, tiếp theo là n số nguyên của một dãy số, hãy cài đặt nó vào một danh sách liên kết đơn. 
//Tiếp theo cho một số nguyên k, (0 ≤ k < n), hãy xóa phần tử ở chỉ số k và in ra màn hình danh sách đó, sau một phần tử có một khoảng trắng.


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *createNode(int x) {
    Node *temp = new Node;
    temp-> data = x;
    temp-> next = NULL;
    return temp;
}

Node *addNode(Node*head, int x) {
    Node *temp = createNode(x);
    head->next = temp;
    return temp;
}

Node* removeNode(Node* head, int k) {
    Node*p = head;
    for (int i=1; i<k; i++) {
        p= p->next;
    }
    Node *q = p->next;
    p->next = q->next;
    delete(q);
    return head;
}

Node* removeHead(Node*head) {
    Node *temp = head;
    temp = temp->next;
    delete(head);
    return temp;
}

void printList(Node *head) {
    Node *p = head;
    while (p!= NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

int main() {
    int n,x,k;
    cin >> n;
    cin >> x;
    Node *head = createNode(x);
    Node* p = head;
    for (int i=1; i<n; i++) {
        cin >> x; 
        p = addNode(p,x);
    }
    cin >> k;
    if (k==0) {
        head = removeHead(head);
    }
    else   {
        head = removeNode(head,k);
    }
    printList(head);
    return 0;
}