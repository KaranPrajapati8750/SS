#include<iostream>
 
using namespace std;

#define MAX 200

class Stack {
    int top;
 
    public:
        int a[MAX]; // Maximum size of Stack

        Stack() { top = -1; }

    bool push(int x)
    {
        if (top >= (MAX - 1)) {
        //    cout << "Stack Overflow";
            return false;
        }
        else {
            a[++top] = x;
          //  cout << x << " pushed into stack\n";
            return true;
        }
    }

    int pop()
    {
        if (top < 0) {
           // cout << "Stack Underflow";
            return 0;
        }
        else {
            int x = a[top--];
            return x;
        }
    }
    
    int peek()
    {
        if (top < 0) {
        //        cout << "Stack is Empty";
            return 0;
        }
        else {
            int x = a[top];
            return x;
        }
    }

    bool isEmpty()
    {
        return (top < 0);
    }

};


bool topo(bool mat[][MAX], int node, Stack &s, bool vis[],int V){
	
    vis[node] = 1;

    for(int i=0;i<V;i++){

        if(mat[node][i]){

            if(!vis[i])
                topo(mat,i,s,vis,V);

        }

	}
    
	s.push(node);

}
int main()
{
    int V,E;
    cin >> V >> E;

    bool mat[MAX][MAX];

    for(int i=0;i<E;i++){
        int u,v;
        cin>>u >> v ;
        mat[u][v] =1;
    }

    bool vis[V];
    Stack s;

    for(int i=0;i<V;i++){
        vis[i] =0;
    }  

    for(int i=0;i<V;i++){
        
        if(!vis[i]){topo(mat,i,s,vis,V);}
    
    }

    while(!(s.isEmpty())){
        cout<<s.peek()<<" ";
        s.pop();       
    }


   return 0;

}