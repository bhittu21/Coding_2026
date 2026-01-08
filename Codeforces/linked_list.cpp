#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){

        this->data = val;
        this->next = NULL;

    }

};


void insert_at_head(Node* &head, int val){

    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;

}

void insert_at_tail(Node* &head, int val){

    Node* newnode = new Node(val);
    // cornar case
    if(head==NULL){
        head = newnode;
        return;
    }

    Node* tmp = head;
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }

    tmp->next = newnode;

}

void insert_at_pos(Node* &head, int pos, int val){

    Node* newnode = new Node(val);

    Node* tmp = head;

    for(int i=1;i<pos;i++){
        tmp = tmp->next;
    }

    Node* tmpNextNext = tmp->next;
    tmp->next = newnode;
    newnode->next = tmpNextNext;

}

void delete_at_pos(Node* &head, int pos){

    Node* tmp = head;

    for(int i=1;i<pos-1;i++){
        tmp = tmp->next;
    }

    tmp->next = tmp->next->next;

}

void print_linked_list(Node* head){

    Node* tmp = head;
    while(tmp!=NULL){

        cout << tmp->data << " ";
        tmp = tmp->next;

    }

}

int main(){

    Node* head = NULL;

    int n;
    cin >> n;

    while(n--){

        int x;
        cin >> x;

        insert_at_tail(head, x);

    }

    print_linked_list(head);

}