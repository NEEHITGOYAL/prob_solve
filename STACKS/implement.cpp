#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

//stack implementation using array
class stack{
    int top;
    public:
        int arr[MAX];
        stack(){top = -1;}
        
        bool isempty(){
            if(top == -1)
                return true;
            else    
                return false;
        }

        void push(int x){
            if(top >= (MAX-1)){
                cout<<"Stack overflow";
                return;
            }
            else{
                arr[++top] = x;
                return;
            }
        }

        void pop(){
            if(top<0)
            {
                cout<<"stack is empty";
                return ;
            }
            else
            {
                top--;
            }
        }

        int Top(){
            if(top<0){
                cout<<"stack is empty";
                return 0;
            }
            else{
                return arr[top];
            }
        }

};

//implementation using linked list
class StackNode {
    public:
    int data;
    StackNode *next;
     
    StackNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
 
class Stack {
     
    StackNode *top;
     
    public:
     
    
    // Push and pop operations
    void push(int data)
    {
        if (top == NULL) {
            top = new StackNode(data);
            return;
        }
        StackNode *s = new StackNode(data);
        s->next = top;
        top = s;
    }
     
    StackNode* pop()
    {
        StackNode *s = top;
        top = top->next;
        free(s);
        return s;
    }
 
    // prints contents of stack
    void display()
    {
        StackNode *s = top;
        while (s != NULL) {
            cout << s->data << " ";
            s = s->next;
        }
        cout << endl;
    }

    int Top(){
        return top->data;
    }
 
    // Reverses the stack using simple
    // linked list reversal logic.
    void reverse()
    {
        StackNode *prev, *cur, *succ;
        cur = prev = top;
        cur = cur->next;
        prev->next = NULL;
        while (cur != NULL) {
 
            succ = cur->next;
            cur->next = prev;
            prev = cur;
            cur = succ;
        }
        top = prev;
    }
};