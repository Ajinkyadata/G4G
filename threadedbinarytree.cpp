#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* left; bool lt; node* right; bool rt;
};

node* newnode(int x)
{
    node* temp=new node();
    temp->data=x;
    temp->right=NULL; temp->rt=0; temp->left=NULL; temp->lt=0;
}

void filltbt(node* root)
{
   if(root==NULL)
   return ;
   filltbt(root->left);
   root->right==
   filltbt(root->right);
}

int main()
{
    node* dummy=newnode(0);
    node* root=newnode(1); root->rt=1; root->lt=1;
    dummy->left=root; dummy->lt=1; dummy->rt=1; dummy->right=dummy->right;
    root->left=newnode(5); root->left->lt=1;  
    root->left->left=newnode(2);    //root->left->left->left=root;
    root->right=newnode(11); root->right->rt=1; root->right->lt=1;
    root->right->left=newnode(16);
    root->right->right=newnode(31);

    return 0;
}