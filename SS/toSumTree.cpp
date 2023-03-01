#include<iostream>
using namespace std;


struct Tree{

    int data;
    Tree *left,*right;

};

Tree* newnode(int data){
    Tree *node = new Tree;
    node->data = data;
    node->left = node->right = NULL;

    return node;
}
    

Tree* insert(int a[],Tree* root,int i,int n){

    if(i<n){
        Tree* temp = newnode(a[i]);

        root=temp;
        root->left = insert(a,root->left,2*i+1,n);

        root->right = insert(a,root->right,2*i+2,n);

    }

    return root;

}

int toSumTree(Tree* root){

    if(!root) return 0;

    int oldVal = root->data;

    root->data = toSumTree(root->left) + toSumTree(root->right);

    return oldVal+root->data;



}

void printInorder(Tree* root){

    if(!root) return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);

}

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];

        Tree* root=insert(a,root,0,n);

        toSumTree(root);

        printInorder(root);

        cout<<endl;
    }

return 0;
}
