/*Given a Binary Tree and a node x in it, find the distance of the closest leaf to x 
in Binary Tree.
 If given node itself is a leaf, then the distance is 0.
 TC- O(n) as it does at most 2 traversals of the tree.
 */

#include<iostream>
using namespace std;

struct Tree{

    int data;
    Tree* left,*right;

};

Tree* newnode(int data){

        Tree *temp = new Tree;
        temp->data=data;
        temp->left = temp->right = NULL;
        return temp;

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

void leafX(Tree *X,int lvl,int *ans){

    if(!X) return ;

    if(!X->left && !X->right){
        *ans = min(*ans,lvl);
        return;
    }

    leafX(X->left,lvl+1,ans);
    leafX(X->right,lvl+1,ans);


}


bool parentX(Tree *root,Tree* X,int *ans){

    if(!root) return false;

    if(root==X) return true;

    // Search x in left subtree of root 
    bool l = parentX(root->left,X,ans);

    if(l){//if X is present in left subtree of root then check for 
          //leaf in right subtree of root

        leafX(root->right,2,ans);

    }

    // Search x in right subtree of root 
    bool r = parentX(root->right,X,ans);

    if(r){//if X is present in right subtree of root then check for 
          //leaf in left subtree of root

        leafX(root->left,2,ans);

    }

    return false;

}

void printIn(Tree* root){

    if(!root) return;

    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);

}

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        int a[n];

        for(int i=0;i<n;i++)cin>>a[i];

        Tree* root = insert(a,root,0,n);
        
        Tree* X = root->left;
        int ans = 1000000;

        printIn(root);
        leafX(X,0,&ans);//find leaf in X's subtree

        parentX(root,X,&ans);//check if a closest leaf can be reached through X's parent

        cout<<"\n"<<ans;
    }


return 0;

}


