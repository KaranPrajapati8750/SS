/*
Given an integer ‘K’ and a binary tree in string format. 
Every node of a tree has value in range from 0 to 9. 
We need to find sum of elements at K-th level from root. 
The root is at level 0.
Tree is given in the form: (node value(left subtree)(right subtree))

Examples:

Input : tree = "(0(5(6()())(4()(9()())))(7(1()())(3()())))" 
        k = 2
Output : 14

TC-
4
(0(5(6()())(4()(9()())))(7(1()())(3()())))
1
(0(5(6()())(4()(9()())))(7(1()())(3()())))
2
(0(5(6()())(4()(9()())))(7(1()())(3()())))
3
(8(3(2()())(6(5()())()))(5(10()())(7(13()())())))
3

Answers 
12 14 9 9


*/

#include<iostream>
using namespace std;

int SumAtlvlK(string S,int K){

    int lvl = -1;
    int sum = 0;
    int i=0;
    int n = S.length();

    while(i<n){

        if(S[i]=='(') lvl++;

        else if(S[i]==')') lvl--;

        else if(lvl==K)
            sum += S[i]-'0';

        i++;
    }
    return sum;
}



int main(){

    int t;
    cin>>t;

    while(t--){

        string S;
        cin>>S;

        int K;
        cin>>K;

        int sum = SumAtlvlK(S,K);

        cout<<sum<<endl;


    }


return 0;


}




















