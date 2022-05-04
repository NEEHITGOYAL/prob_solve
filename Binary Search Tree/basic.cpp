#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node() {
        data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    Node(int data,Node* left,Node* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
    
};

Node* insertInBST(Node* root,int data){
    if(root == NULL)
        return new Node(data);
    if(data <= root->data)
        root->left = insertInBST(root->left,data);
    else
        root->right = insertInBST(root->right,data);
    return root;
}

Node* buildtree(){
    //reads a list of numbers till -1 and also these numbers will be inserted into BST
    int data;
    cin>>data;
    Node* root = NULL;
    while(data != -1){
        root = insertInBST(root,data);
        cin>>data;
    }
    return root;
}
//preorder traversal
void printpre(Node* root){
    if(root == NULL)
        return;
    cout<<root -> data<<" ";
    printpre(root->left);
    printpre(root->right);
}

//inorder traversal
void printin(Node* root){
    if(root == NULL)
        return;
    printin(root->left);
    cout<<root -> data<<" ";
    printin(root->right);
}

//postorder traversal
void printpost(Node* root){
    if(root == NULL)
        return;
    printpost(root->left);
    printpost(root->right);
    cout<<root -> data<<" ";
}

//height of tree
int height(Node* root){
    if(root == NULL)
        return 0;
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs)+1;
}

//printkthlevel
void printkthlevel(Node* root,int k){
    if(root == NULL)
        return;
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printkthlevel(root->left,k-1);
    printkthlevel(root->right,k-1);
    return;
}

//print all levels
void printalllevel(Node * root){
    int h = height(root);
    for(int i=1;i<=h;i++){
        printkthlevel(root,i);
        cout<<endl;
    }
} 

//breadth first search/travel
void bfs(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* x = q.front();
        if(x == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<x->data<<" ";
            q.pop();
            if(x->left != NULL)
                q.push(x->left);
            if(x->right != NULL)
                q.push(x->right);
        }
    }
    return;
}

//search operation
bool search(Node* root,int val){
    if(root == NULL)
        return false;
    if(root->data == val)
        return true;
    if(root->data > val)
        return search(root->left,val);
    else
        return search(root->right,val);
}

//deletion of node in BST
Node* deleteinBST(Node* root, int val){
    if(root  == NULL )
        return NULL;
    else if(val<root->data){
        root->left = deleteinBST(root->left,val);
        return root; 
    }
    else if(val > root->data){
        root->right = deleteinBST(root->right,val);
        return root;
    }
    //Found the node and now delete it
    else{
        //case 1
        //no child
        if(root->left == NULL and root->right == NULL){
            delete root;
            return NULL;
        }
        //case 2 
        //only 1 child
        else if(root->left == NULL and root->right != NULL){
            Node* tmp = root->right;
            delete root;
            return tmp;
        }
        else if(root->left != NULL and root->right == NULL){
            Node* tmp = root->left;
            delete root;
            return tmp;
        }
        //case 3 
        //2 child nodes
        else{
            Node* replace = root->right;
            while(replace->left != NULL)
                replace = replace->left;
            root->data = replace->data;
            root->right = deleteinBST(root->right,replace->data);
            return root; 
        }
    }
}

//check if it is a BST
bool isBST(Node* root,int minv = INT_MIN,int maxv = INT_MAX){
    if(root == NULL)
        return true;
    if(root->data >= minv and root->data <=maxv and isBST(root->left,minv,root->data) and isBST(root->right,root->data,maxv))
        return true;
    return false;
}

int main(){
    // 5 3 7 1 6 8 -1 1 -1

    //insertion
    Node* root = buildtree();
    bfs(root);
    cout<<endl;
    printin(root);
    cout<<endl;

    //searching
    int s = 1;
    if(search(root,s))
        cout<<"present"<<endl;
    else
        cout<<"Not present"<<endl;

    //deleting
    root = deleteinBST(root,s);
    bfs(root);
    root = insertInBST(root,1);
    bfs(root);
    cout<<endl;

    //check if is BST
    if(isBST(root))
        cout<<"it is a BST"<<endl;
    else
        cout<<"NOT a BST"<<endl;

}