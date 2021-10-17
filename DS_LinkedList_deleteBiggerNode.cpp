//Nhập vào một số nguyên dương n, tiếp theo là n số nguyên của một dãy số, hãy cài đặt nó vào một danh sách liên kết đơn. Tiếp theo nhập một số nguyên k (0 ≤ k <n).
//Hãy xóa những phần tử có giá trị lớn hơn giá trị của phần tử ở chỉ số k. In ra màn hình danh sách đó, sau một phần tử có đúng một khoảng trắng.


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *createNode (int x) {
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

Node *addNode(Node *head, int x) {
    Node *temp =createNode(x);
    head->next = temp;
    return temp;
}

int getlim(Node *head,int k) {                          //This function return the "k" Node's value
    Node *p = head;
    for (int i=0; i<k;i++) {
        p = p->next;
    }
    return p->data;
}

void printList(Node *head) {
    Node *p = head;
    while (p!=NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

int main() {
    int n,x,k;
    cin >> n;
    cin >> x;
    Node *head = createNode(x);
    Node *p = head;
    for (int i=1; i<n; i++) {
        cin >> x;
        p = addNode(p,x);
    }
    cin >> k;                                // Finished input 1st List and index "k"
    int lim = getlim(head,k);                // Finished finding the Limit value of index "k"
    p = head;                                // Re-establishing p to be head again
    Node *headscd;                           // Announcing new "head" for second linked list
    while (p!=NULL) {
        if(p->data <= lim) {
            headscd = createNode(p->data);
            break;                           // I break the loop because I'm only looking for the value for head of the new linked list
        }
        p = p->next;
    }
    Node *q = headscd;                       // Now the head of the second linked list has been established                           
    p = p->next;
    while(p!=NULL) {
        if (p->data <= lim) {
            q = addNode(q,p->data);          // Adding Node to the second linked list
        }
        p = p->next;
    }
    printList(headscd);
    return 0;
}