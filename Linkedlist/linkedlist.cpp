#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* push(Node* headref,int data){
    Node* newnode = new Node(data);
    newnode->next = (headref);
    headref = newnode;
    return headref;
}

void insertafter(Node* prev_node,int newdata ){
    Node* newnode = new Node(newdata);
    newnode -> next = prev_node->next;
    prev_node->next = newnode;
}

void append(Node* headref,int data){
    Node* newnode = new Node(data);
    while(headref->next != NULL){
        headref = headref->next;
    }
    headref->next = newnode;
    newnode->next = NULL;
}

void deletenode(Node** headref,int data){
    Node* temp = *headref;
    Node* prev = NULL;
    if(temp != NULL && temp->data == data){
        *headref = temp->next;
        delete temp;
        return;
    }
    else{
        while(temp != NULL && temp->data != data){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            return;
        }
        prev->next = temp->next;
        delete temp;
    }
}

void deletepos(Node** head_ref,int pos){
    if(*head_ref == NULL)
        return;
    Node* temp = *head_ref;
    if(pos == 0){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for(int i=0;temp != NULL && i<pos -1;i++)
        temp = temp->next;
    if(temp == NULL || temp->next == NULL)
        return;
    Node* del = temp->next;
    temp->next = temp->next->next;
    free(del);

}

void print(Node* headref){
    while(headref != NULL){
        cout<<headref->data<<"->";
        headref = headref->next;
    }
    return;
}
Node* reverse(Node *head){
    //base case
    if(head->next == NULL){
        return head;
    }
    //rec case
    Node *rev = reverse(head->next);
    //statements
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return rev;
}

int main(){
    Node*  a = new Node(3);
    a = push(a,1);
    insertafter(a,2);
    append(a,4);
    print(a);
    cout<<endl;
    Node* rev  = reverse(a);
    print(rev);
}