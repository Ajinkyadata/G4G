#include<iostream>
#include<cstdlib>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node* create_node(int x)
    {
        Node *temp=new Node;
        temp->data=x;
        temp->next=NULL;
        return temp;
    }

    Node* insert_at_end( Node *tip,int y)
    {
        Node* temp=tip;
        if(tip==NULL)
        {
            tip=create_node(y);
            return tip;
        }
        else
            {
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=create_node(y);
                return tip;
            }
    }

    void insert_q_after_p(Node *q,Node *p)
    {
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=p->next;
        p->next=q;
    }
    void reorder(Node *head)
    {
        Node *q=head;
        while(head->next!=NULL)
        {
            insert_q_after_p(q,head);
            head=head->next->next;
            q=head;
        }
    }
};

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        Node *head;
        head=NULL;
        cin>>n;               
        for(int j=0;j<n;j++)
        {
            int temp;
            cin>>temp;
            head=head->insert_at_end(head,temp);
        }
        head->reorder(head);
        Node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    return 0;
}