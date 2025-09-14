
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* child;

Node(int val){
    data = val;
    next = NULL;
    child = NULL;
}
};
 
class LinkedList{
        Node* head;
public:
    LinkedList(){
        head = NULL;
    }
        Node* getHead() { 
            return head; 
        }
        void setHead(Node* h) {
             head = h; 
        }

        void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void flatten() {
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* tempNext = curr->next;
                curr->next = curr->child;
                Node* tail = curr->child;
                while (tail->next) tail = tail->next;
                tail->next = tempNext;
                curr->child = NULL;
            }
            curr = curr->next;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList list;
    Node* n1 =new Node(1);
    Node* n2 = new Node(2);
    Node* n3 =new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2;
n2->next = n3;
    n2->child = n4;
      n4->next = n5;

    list.setHead(n1);

    cout <<"Before Flatten: ";
    list.display();
    list.flatten();
    cout <<"After Flatten: ";
    list.display();
    return 0;
}