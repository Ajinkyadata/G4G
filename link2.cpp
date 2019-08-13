#include<iostream>
//#include<cstdlib>

using namespace std;

typedef struct Node_
{
    int data;
    struct Node_ *next;
} Node;

Node* create_node(int x)
{
    Node *temp=new Node;
    temp->data=x;
    temp->next=NULL;
    return temp;
}

Node* insert(Node *head, int x)
{
    Node * temp=head;
    if(head==NULL)
        {
            head=create_node(x);
            return head;
        }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=create_node(x);
        return head;
    }
    
}






int main()
{
    Node *head=NULL;
    int n=5;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        head=insert(head,temp);
    }
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    return 0;
}