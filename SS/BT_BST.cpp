/*Given a Binary Tree, write a function that returns the size
 of the largest subtree which is also a Binary Search Tree (BST). 
 If the complete Binary Tree is BST, then return the size of the whole tree.*/

#include<iostream>
using namespace std;

#define INT_MAX 100000
#define INT_MIN -100000

struct Tree{
    int data;
    Tree* left,*right;
};

Tree *newNode(int data){

    Tree* temp = new Tree;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;

}

Tree* insert(int a[],Tree* root,int i,int n){

    if(i<n){

        Tree* temp = newNode(a[i]);
        root=temp;

        root->left = insert(a,root->left,2*i+1,n);
        root->right = insert(a,root->right,2*i+2,n);

    }
    return root;


}


void printIN(Tree* root){

    if(!root) return ;

    printIN(root->left);
    cout<<root->data<<" ";
    printIN(root->right);

}


//INFO of BST
struct INFO{

    int size;//size of binary Tree
    int max;//max in subtree
    int min;//min in subtree
    bool isBST;
    int ans;//Nodes in Largest BSt

};

//Returns INFO of biggest BST
INFO BT_BST(Tree* root){

    if(!root) return {0,INT_MIN,INT_MAX,true,0};

    if(!root->left && !root->right) return {1,root->data,root->data,true,1};

    INFO left = BT_BST(root->left);
    INFO right = BT_BST(root->right);

    INFO cur_info;
    cur_info.size = (1 + left.size + right.size);

    if(left.isBST && right.isBST && left.max<root->data && right.min>root->data ){

        cur_info.min = min(left.min,min(root->data,right.min));
        cur_info.max = max(right.max,max(root->data,right.max));

        cur_info.isBST = true;
        cur_info.ans = cur_info.size;

        return cur_info;
    }

    //If whole tree is not BST then store Largest BST among left and right subtree.
    cur_info.ans = max(left.ans,right.ans);
    cur_info.isBST = false;

    return cur_info;

}

 int main(){

     int t;
     cin>>t;

    while(t--){

        int n;
        cin>>n;
        
        Tree* root;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        root = insert(a,root,0,n);

        INFO res=BT_BST(root);
        cout<<res.ans<<endl;

    }

return 0;

}