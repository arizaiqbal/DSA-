#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
    data = d;
next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
    head = NULL;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
     
    
    while (temp->next) temp = temp->next;
      temp->next = newNode;
    }

    Node* reverseList(Node* node) {
Node* prev = NULL;
   Node* curr = node;

    while (curr) {
    Node* nextNode = curr->next;
       curr->next = prev;
        prev = curr;
        curr = nextNode;
}
return prev;
    }

    bool isPalindrome() {
      if (!head || !head->next) return true;
       Node* slow = head;
       Node* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondHalf = reverseList(slow->next);
     Node* firstHalf = head;
    Node* tempSecond = secondHalf;

 bool palindrome = true;
  while (tempSecond) {
   if (firstHalf->data != tempSecond->data) {
    palindrome = false;
  break;
}

    firstHalf = firstHalf->next;
    tempSecond = tempSecond->next;
   }

   slow->next = reverseList(secondHalf);
   return palindrome;
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

int main() {
  LinkedList list;
  list.insertEnd(1);
  list.insertEnd(2);
  list.insertEnd(3);
  list.insertEnd(2);
  list.insertEnd(1);

    cout << "Linked List: ";
    list.display();

    if (list.isPalindrome())
cout << "Linked list is a palindrome" << endl;
   else
 cout << "Linked list is not a palindrome" << endl;

    return 0;
}

