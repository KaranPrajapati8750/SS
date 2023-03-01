#include<iostream>

using namespace std;



//Tree
struct TreeNode{
    int data;
    TreeNode *left,*right;

};

TreeNode* newNode(int data){
    TreeNode* temp= new TreeNode;
    temp->data= data;
    temp->left = temp->right = NULL;
    return temp;
}

//Linked List
struct Node{
    TreeNode* data;
    Node* next;
};

Node* newNodeLL(TreeNode* tNode){

    Node* node = new Node;
    node->data = tNode;
    node->next = NULL;

    return node;

}


//Queue using linked list
class queue 
{

    public:
        int num;
        Node* front;
        Node* rear;

        queue(){

            front=NULL;
            rear=NULL;
            num=0;

        }        

        int size(){
            return num;
        }

        bool isEmpty(){
            return num==0;
        }

        void enQ(TreeNode* tNode){

            if(front==NULL){
                front = rear = newNodeLL(tNode);
            }

            else{
            rear->next = newNodeLL(tNode);
            rear = rear->next;
            }
            num++;
        }

        TreeNode* deQ(){
            
            if(num>0){

                if(front==rear){ 

                    TreeNode* temp = front->data;
                    num--;
                    front=rear=NULL;
                    return temp;
                }

                Node* temp = front;
                TreeNode* tnode = front->data;
                front=front->next;
                
                num--;
                temp->next = NULL;
                delete(temp);
                return tnode;
            }
        }

};



int NearestLeaf(TreeNode* root){
    
    if(!root) return -1;

    int h=0;
    queue q;

    q.enQ(root);

    while(!q.isEmpty()){
        
        int size = q.size();
        TreeNode* t ;

        while(size--){

            t = q.deQ();

            if(!t->left && !t->right) return h;

            if(t->left){
                q.enQ(t->left);
            }

            if(t->right){
                q.enQ(t->right);
            }

        }
            h++;


    }

}

void printIn(TreeNode* root){

    if(!root) return ;

    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);



}

//Tree Creation from array

TreeNode* createTree(int a[],TreeNode* root,int i,int n){

    if(i<n){

        TreeNode* temp = newNode(a[i]);

        root=temp;

        root->left = createTree(a,root->left,2*i+1,n);
        root->right = createTree(a,root->right,2*i+2,n);

    }

    return root;

}


int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];

        TreeNode* root=createTree(a,root,0,n);

        //printIn(root);
        int res = NearestLeaf(root);
        cout<<res<<endl;


    }

return 0;

}

