
#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    //constructor
    
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

    //insert node at head
    void insertAtHead(Node* &head, int d){
        //new node creats

        Node* temp = new Node(d);
        temp -> next = head;
        head  = temp;

    }

    //insert node at tail
    void insertAtTail(Node* &tail, int d){
        //new node create
        Node* temp = new Node(d);
        tail -> next = temp;
        tail = temp;

    }
    //insert at specific position
    void insertAtPosition(Node* &head,Node* &tail, int position, int d){
         //difficult to add value at specific first position


         if(position ==1){
            insertAtHead(head, d);
            return;
         }
         //----------
        Node* temp = head;
        int cnt = 1;

        while(cnt < position-1){
            temp = temp -> next;
            cnt++;
        }

        // inserting at last position
        if(temp -> next == NULL){
            insertAtTail(tail, d);
            return;
        }
        //creating a new  node for d
        Node* nodeToInsert = new Node(d);

        nodeToInsert -> next = temp ->next;
        temp -> next = nodeToInsert;
    }

    //traversing like output 
    void show(Node* &head){
        Node* temp = head;

        while(temp != NULL){
            cout<< temp -> data << " "; 
            temp = temp -> next;
              }
              cout<< endl;
    
    }
        
int main(){
    Node* node1 = new Node(10);
      Node* node2 = new Node(20);
      Node* node3 = new Node(30);

      //link them manually
      node1-> next = node2;
      node2-> next = node3;

    // cout<< node1 -> data<<endl;
    // cout<< node2 -> data<<endl;
    // cout<< node3 -> data<<endl;
    // cout<<node1 -> next<<endl;

    //head pointed to node1
    Node* head = node1;
    Node* tail = node3;
    cout<<"linked list itms"<<endl;
    show(head);

    cout<<"Insert 5 in start of list"<<endl;
    insertAtHead(head, 5);
    show(head);
//add another valu as a example
cout<<"insert 100 end of the list"<<endl;
    insertAtTail(tail, 100);
    show(tail);
//add at specific position
cout<<"Insert 77 at at 3 position and update list"<<endl;
    insertAtPosition(head,tail,3, 77);
    show(head);
    //difficult to add value at specific first position
    cout<<"Insert 22 at at 1 position and update list"<<endl;
    insertAtPosition(head,tail,1, 22);
    show(head); 

    cout<<"Insert 99 at at 4 position and update list"<<endl;
    insertAtPosition(head,tail,4, 99);
    show(head);

cout<<"Insert 2000 at at 8 position and update list"<<endl;
    insertAtPosition(head,tail,9, 2000);
    show(head);

    //verifay latest head and tail value
    cout<<"latest head and tail vale"<<endl;
    cout<<"head value: "<<head -> data<<endl;
    cout<<"Tail value: "<< tail -> data<<endl;
    return 0;
}