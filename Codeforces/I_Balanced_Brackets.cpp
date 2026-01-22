#include <bits/stdc++.h>
using namespace std;

string isBalanced(string s){
    int size = s.length();

    int flag=1;

    for(int i=0;i<size/2;i++){
        if(s[i]=='(' && s[size-i-1]!=')'){
            flag=0;
            break;
        }

        else if(s[i]=='{' && s[size-i-1]!='}'){
            flag=0;
            break;
        }

        else if(s[i]=='[' && s[size-i-1]!=']'){
            flag=0;
            break;
        }
    }

    if(flag){
        return "YES";
    } else {
        return "NO";
    }


}


int compare_lists(SinglyLinkedListNode* llist1, SinglyLinkedListNode* llist2) {

    while (llist1 != nullptr && llist2 != nullptr) {

        if (llist1->data != llist2->data) {
            return 0;
        }

        llist1 = llist1->next;
        llist2 = llist2->next;
    }

    return (llist1 == nullptr && llist2 == nullptr) ? 1 : 0;
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* headA, SinglyLinkedListNode* headB) {

    if (headA == nullptr) return headB;
    if (headB == nullptr) return headA;

    SinglyLinkedListNode* head = nullptr;
    SinglyLinkedListNode* tail = nullptr;

    if (headA->data <= headB->data) {
        head = tail = headA;
        headA = headA->next;
    } else {
        head = tail = headB;
        headB = headB->next;
    }

    while (headA != nullptr && headB != nullptr) {
        if (headA->data <= headB->data) {
            tail->next = headA;
            tail = headA;
            headA = headA->next;
        } else {
            tail->next = headB;
            tail = headB;
            headB = headB->next;
        }
    }

    if (headA != nullptr) tail->next = headA;
    else tail->next = headB;

    return head;
}

vector<int> getMax(vector<string> operations) {
    vector<int> res;
    vector<int> st, mx;

    for (string &op : operations) {
        if (op[0] == '1') {

            int x = stoi(op.substr(2));
            st.push_back(x);

            if (mx.empty() || x > mx.back()) mx.push_back(x);
            else mx.push_back(mx.back());

        } else if (op[0] == '2') {

            st.pop_back();
            mx.pop_back();

        } else {
            res.push_back(mx.back());
        }
    }

    return res;
}

string isBalanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return "NO";
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return "NO";
            }
        }
    }
    return st.empty() ? "YES" : "NO";
}



int main() {
    int t;
    cin >> t;
    while(t--){
        
        string s;
        cin >> s;

        isBalanced(s);
    }

}