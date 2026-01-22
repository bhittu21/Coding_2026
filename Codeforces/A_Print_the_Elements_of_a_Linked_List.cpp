// Coded by Bhittu21
// ID: 0182510012101146 - 65D

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d){
            this->data = d;
            this->next = nullptr;
        }
};

void insertAtTail(Node* &head, Node* &tail, int d){
    Node* tmp = new Node(d);
    if(head == nullptr){
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
        tail = tmp;
    }
}

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    
    if(head==nullptr || head->next == nullptr){
        return head;
    }

    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* cur = head;
    SinglyLinkedListNode* next = nullptr;

    while(cur!=nullptr){
        next= cur->next;
        cur->next= prev;
        prev= cur;
        cur = next;

    }

    return prev;


}


int main(){
    
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    cin >> n;

    while(n--){
        int x;
        cin >> x;
        insertAtTail(head, tail, x);
    }

    printList(head);


    return 0;
}