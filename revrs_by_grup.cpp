/* Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Input:
First line of input contains number of testcases T. For each testcase, first line contains length of linked list and next line contains the linked list elements.

Output:
For each testcase, there will be a single line of output which contains the linked list with every k group elements reversed.

Example:
Input:
1
8
1 2 2 4 5 6 7 8
4

Output:
4 2 2 1 8 7 6 5

Explanation:
Testcase 2: Since, k = 4. So, we have to reverse everty group of two elements. Modified linked list is as 4, 2, 2, 1, 8, 7, 6, 5. */


#include<bits/stdc++.h>
using namespace std;
/* Link list node */
struct node *reverse (struct node *head, int k);
struct node
{
    int data;
    struct node* next;
}*head;
/* UTILITY FUNCTIONS */
/* Function to push a node */
  void insert()
{
    int n,value;
    cin>>n;
    struct node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            head=(struct node *) malloc( sizeof(struct node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
printf(" ");
}
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t,k,value,n;
     cin>>t;
     while(t--)
     {
     insert();
     cin>>k;
     head = reverse(head, k);
     printList(head);
     }
     return(0);
}
/*This is a function problem.You only need to complete the function given below*/
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
  struct node
  {
     int data;
     struct Node *next;
  }
*/
struct node *reverse (struct node *head, int k)
{ 
    stack<int> st;
    vector<int >v;
    struct node *temp=head;
    int c=0;
    while(temp!=NULL)
    {
        v.push_back(temp->data);
        temp=temp->next;
        c++;
    }

    /*  for(int i=0;i<c;i++)
        cout<<"|"<<v[i]<<"|";
     */
    int l=0,i,z;

    /* cout<<c/k<<";;;"; */
    int r=c%k;
    for(z=0;z<c/k;z++)
    {
        /* cout<<z<<"'''";*/
        for(i=l;i<l+k;i++)
    {
        st.push(v[i]);
    }
    
        for(i=l;i<l+k;i++)
    {
        //cout<<st.top()<<"//";
        v[i]=st.top();
        st.pop();
    }
        l+=k;
    }
    
  
       for(i=l;i<l+r;i++)
    {
        st.push(v[i]);
    }
    
        for(i=l;i<l+r;i++)
    {
        //cout<<st.top()<<"//";
        v[i]=st.top();
        st.pop();
    } 

    /* for(int i=0;i<c;i++)
    cout<<v[i]<<"||";
 */

    
    temp=head;
    int j=0;
    while(temp!=NULL)
    {
        temp->data=v[j];
        temp=temp->next;
        j++;
    }
    
    return head;
    
}