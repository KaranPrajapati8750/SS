#include<iostream>
using namespace std;

struct Tree{

    int data;
    Tree* left,*right;

};

Tree* newNode(int data){

    Tree* temp = new Tree;
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;

}

Tree* insertBST(Tree* root,int data){

    if(!root) return newNode(data);

    if(root->data< data){
        root->right = insertBST(root->right,data);
    }

    else if(root->data> data){
        root->left = insertBST(root->left,data);
    }
    return root;
}

void KthLargest(Tree* root,int k ,int &c){

    if(!root || c>=k)return ;

    KthLargest(root->right,k,c);
    c++;

    if(k==c){
        cout<<root->data<<endl;
        return;
    }

    KthLargest(root->left,k,c);


}


int main(){

    int t;
    cin>>t;

    while(t--){
        
        Tree* root = NULL;
        int n;
        cin>>n;

        int node;

        for(int i=0;i<n;i++){
            cin>>node;
            root=insertBST(root,node);
        }

        int k;
        cin>>k;
        
        int c=0;

        KthLargest(root,k,c);
        
    }

 return 0;

}
