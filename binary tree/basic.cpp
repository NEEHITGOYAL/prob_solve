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
Node* buildtree(){
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    Node* root = new Node(d);
    root->left = buildtree();
    root->right = buildtree();
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
//count no. of nodes
int countnode(Node* root){
    if(root == NULL)
        return 0;
    return 1 + countnode(root->left) + countnode(root->right);
}

//sum of all nodes
int sumnode(Node* root){
    if(root == NULL)
        return 0;
    return root->data + sumnode(root->left) + sumnode(root->right);
}
//diameter of tree (longest chain)
int diameter(Node* root){
    if(root==NULL)
        return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1 + h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1,max(op2,op3));
}
//fast diameter in time complexity o(N)
class Pair{
    public:
        int height;
        int diameter;
};

Pair fastdiameter(Node* root){
    Pair p;
    if(root == NULL){
        p.height = p.diameter = 0;
        return p;
    }
    Pair left = fastdiameter(root->left);
    Pair right = fastdiameter(root->right);

    p.height = max(left.height,right.height) +1;
    p.diameter = max(left.height + right.height,max(left.diameter,right.diameter));
    return p;
}

//sum replace
int replaceSum(Node* root){
    if(root == NULL)
        return 0;
    if(root->left==NULL and root->right == NULL){
        return root->data;
    }
    //Recursive Part
    int left_sum = replaceSum(root->left);
    int right_sum = replaceSum(root->right);
    int temp = root->data;
    root->data = left_sum+right_sum;
    return root->data + temp;
}

//height Balance tree
class HBpair{
    public:
        int height;
        bool balance;
};

HBpair balanced(Node* root){
    HBpair p;
    if(root == NULL){
        p.balance = true;
        p.height = 0;
        return p;
    }

    HBpair left =  balanced(root->left);
    HBpair right = balanced(root->right);

    p.height = max(left.height,right.height) + 1;
    if(abs(left.height - right.height)<=1 && left.balance && right.balance)
        p.balance = true;
    else
        p.balance = false;
    return p;
}

//BUILDING HEIGHT BALANCE TREE FROM ARRAY
Node* buildtreefromarray(int *a,int s,int e){
    //Base Case
    if(s>e){
        return NULL;
    }
    //Recursive Case
    int mid  = (s+e)/2;
    Node* root = new Node(a[mid]);
    root->left = buildtreefromarray(a,s,mid-1);
    root->right = buildtreefromarray(a,mid+1,e);
    return root;
}

//CREATE TREE FROM TRAVERSAL
Node* createtreefromtrav(int *ino,int *pre,int s,int e){
    static int i=0;
    if(s>e)
        return NULL;
    Node* root = new Node(pre[i]);
    int index = -1;
    for(int j=s;j<=e;j++){
        if(ino[j] == pre[i]){
            index = j;
            break;
        }
    }
    i++;
    root->left = createtreefromtrav(ino,pre,s,index-1);
    root->right = createtreefromtrav(ino,pre,index+1,e);
    return root;
}

//printrightview
void rightview(Node* root,int level,int &maxlevel){
    if(root == NULL)
        return;
    if(maxlevel < level){
        //have discovered new level
        cout << root->data <<" ";
        maxlevel = level;
    }
    rightview(root->right,level+1,maxlevel);
    rightview(root->left, level+1, maxlevel);
}

//PRINT LEFT VIEW 
void leftview(Node* root,int level,int &maxlevel){
    if(root == NULL)
        return;
    if(maxlevel < level){
        cout<<root->data<<" ";
        maxlevel = level;
    }
    leftview(root->left,level+1,maxlevel);
    leftview(root->right,level+1,maxlevel);

    
}

//LOWEST COMMON ANCESTOR
Node* lca(Node* root, int a ,int b ){
    if( root == NULL)
        return NULL;
    if(root->data ==a or root->data == b){
        return root;
    }
    //search in left and right subtree
    Node* leftans = lca(root->left,a,b);
    Node* righttans = lca(root->right,a,b);

    if(leftans != NULL and righttans != NULL)
        return root;
    if(leftans != NULL)
        return leftans;
    return righttans;    
}

//Maximum Sum Path from any node to any node in given binary tree
class Sumpair{
    public:
        int maxsum;
        int branchsum;
    Sumpair(){
        maxsum =0;
        branchsum = 0;
    }    
};

Sumpair maximumsum(Node* root){
    Sumpair p;
    if(root == NULL)
        return p;
    Sumpair left = maximumsum(root->left);
    Sumpair right = maximumsum(root->right);

    int op1 = root->data;
    int op2 = root->data + left.branchsum;
    int op3 = root->data + right.branchsum;
    int op4 = root->data + left.branchsum + right.branchsum;

    int curr_ans_through_root = max(op1,max(op2,max(op3,op4)));

    p.branchsum = max(left.branchsum,max(right.branchsum,0)) + root->data;
    p.maxsum = max(left.maxsum,max(right.maxsum,curr_ans_through_root));
    return p;
}

// Finding distance between any two nodes

int search(Node* root,int key,int level){
    if(root == NULL)
        return -1;
    if(root->data == key)
        return level;
    
    int left = search(root->left,key,level +1);
    if(left != -1)
        return left;
    return search(root->right,key,level+1);
}

int finddistance(Node* root,int a,int b){
    Node* lca_node = lca(root,a,b);
    int l1 = search(lca_node,a,0);
    int l2 = search(lca_node,b,0);
    return l1+l2;
}

int main(){
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

//                8
//      10               3
//  1       6                14
//      9       7        13

    Node tree;
    cout<<tree.data<<" ";
    cout<<tree.left<<" ";
    cout<<tree.right<<" ";
    cout<<endl;
    Node* root = buildtree();
    cout<<"Preorder : ";
    
    //pre order traversal
    printpre(root);  //root->left->right
    cout<<endl;
    
    //Inorder traversal
    cout<<"Inorder : ";
    printin(root);//left->root->right
    cout<<endl;
    
    //post order traversal
    cout<<"Postorder : ";
    printpost(root);//left->right->root
    cout<<endl;
    
    //height of tree
    cout<<"Height of tree :"<<height(root)<<endl;
    
    //level order traversal hight time complexity
    printalllevel(root);
    cout<<endl;
    
    //bfs
    cout<<"BFS:"<<endl;
    bfs(root);

    //count no, of nodes
    cout<<"number of nodes in given tree is:"<<countnode(root)<<endl;
    
    //count sum of all nodes
    cout<<"sum of nodes in given tree is:"<<sumnode(root)<<endl;
    
    //diameter of tree (its not the node we count the distance that is no. of connection linked in straight path)
    cout<<"Diameter of tree time complexity of nsquare is "<<diameter(root)<<endl;
    
    //diameter of tree in fast way in o(n) time complexity
    cout<<"fast diameter:";
    Pair p = fastdiameter(root);
    cout<<p.diameter<<endl;

    //replaceSumproblem
    cout<<"replaceSumprob"<<endl;
    Node* root2 = root;
    replaceSum(root2);
    bfs(root2);
    cout<<endl;

    //heightbalancedtree
    cout<<"height balanced tree problem"<<endl;
    if(balanced(root).balance)
        cout<<"tree is height balanced"<<endl;
    else
        cout<<"tree is not balanced"<<endl;

    //BUILDING HEIGHT BALANCE TREE FROM ARRAY  
    int a[] = {1,2,3,4,5,6,7};
    int n=7;
    Node* root3 = buildtreefromarray(a,0,n-1);
    bfs(root3); 
    cout<<endl;

    // Create tree fron inorder and pre order array
    int ino[] = {3,2,8,4,1,6,7,5};
    int pre[] = {1,2,3,4,8,5,6,7};
    int k = sizeof(ino)/sizeof(int);
    Node* root4 = createtreefromtrav(ino,pre,0,k-1);
    bfs(root4);
    cout<<endl;

    //right view of tree
    int maxlevel = -1;
    rightview(root4,0,maxlevel);
    cout<<endl;

    //left view of tree
    maxlevel = -1;
    leftview(root4,0,maxlevel);
    cout<<endl; 

    //lca
    int d = 1;
    int b =4;
    cout<<"LCA of 1 and 4 is "<<lca(root4,d,b)->data<<endl;

    //Maximum Sum Path from any node to any node 
    cout<<"Max sum path : " <<maximumsum(root4).maxsum << endl;

    //finding distance between any two nodes
    cout << "Distance between any two given node is "<<finddistance(root4,d,b)<<endl;
}