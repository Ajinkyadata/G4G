#include <iostream>
using namespace std;

class node{public: int data; node *next; };

node * new_node(int y)
{
    node* temp=new node();
    temp->data=y;
    temp->next=NULL;
    return temp;
}

void push(node* root,int data)
{
    while(root->next!=NULL)
    {
        root=root->next;
    }
    root->next=new_node(data);
}


void print(node *root)
{
    while(root!=NULL)
    {
        cout<<root->data<<" ";
        root=root->next;
    }
    cout<<endl;
}


int root_nth(node* root)
{
    int i=1,j=1;
    node* sqrt=NULL;

    while(root!=NULL)
    {
        if(i==j*j)
            {
            if(sqrt==NULL)  
            sqrt=root;
            else
            sqrt=sqrt->next;
            j++;}
        
        root=root->next;
        i++;
    }
    return sqrt->data;
}

int main()
{
    node* root=NULL;
    root=new_node(1);
    push(root,5);
    push(root,6);
    push(root,3);
    push(root,2);
    push(root,66);
    push(root,32);
    push(root,22);
    push(root,11);
    print(root);
    cout<<root_nth(root)<<endl;
    return 0;
}

