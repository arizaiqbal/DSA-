#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
Node(int val){
    data=val;
    next=NULL;
}
};
class LinkedList{    public:
    Node* head;
    LinkedList(){head=NULL;}
    LinkedList(Node* ptr){head=ptr;}
    
    void Insertion(int val){
        Node* n=new Node(val);
        if(head==NULL){
            head=n;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
    
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};


Node* mergeList(Node* head1, Node*head2){
      Node*ptr1=head1;
       Node*ptr2=head2;
     Node* dummyhead=new Node(-11);
     Node* ptr3=dummyhead;
while(ptr1!=NULL&&ptr2!=NULL)
     {
        if(ptr1->data>ptr2->data){
            ptr3->next=ptr2;
           ptr2=ptr2->next;}
           else{
            ptr3->next=ptr1;
            ptr1=ptr1->next;
           }
           ptr3=ptr3->next;
     }
     if(ptr1){
        ptr3->next=ptr1;
     }
     if(ptr2){
        ptr3->next=ptr2;
     }
     return dummyhead->next;

}
int main(){
    LinkedList list1,list2;
    list1.Insertion(1);
    list1.Insertion(3);
    list1.Insertion(5);
    cout << "List 1: ";
    list1.display();
    cout << endl;
    list2.Insertion(2);
    list2.Insertion(4);
    list2.Insertion(6);
    cout << "List 2: ";
    list2.display();
    cout << endl;
    Node* head = mergeList (list1.head , list2.head);
    LinkedList mergedList(head);
    cout<<"Merge List :";
    mergedList.display();
    return 0;
}