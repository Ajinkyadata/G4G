/* You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present.

Input:
First line of input contains number of testcases T. T testcases follow. For each testcase, first line of input contains length N of the linked list and next line contains N data of the linked list. The third line contains the position of the node(from head) to which the last node will get connected. If it is 0 then there is no loop.

Output:
For each testcase, in a new line, 1 will be printed if loop is removed(correct answer) else 0 will be printed(for wrong answer).

User Task:
You don't have to read the input, or print the output. Just complete the function removeTheLoop() which has only argument as head reference of the linked list. If you complete this function in correct way and loop gets removed, the answer will be 1.

Constraints:
1 <= T <= 50
1 <= N <= 300

Example:
Input:
2
3
1 3 4
2
4
1 8 3 4
0

Output:
1
1 */

#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
 Node* insert(Node* head, int data)
{
    if (head == NULL)
        head = new Node(data);
    else
        head->next = insert(head->next, data);
    return head;
}
 void makeLoop(Node* head, int x)
{
    if (x == 0)
        return;
    Node* curr = head;
    Node* last = head;
    int counter = 0;
    while (counter < x)
    {
        curr = curr->next;
        counter++;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = curr;
}
 int detectloop(Node* head)
{
    Node* hare = head->next;
    Node* tortoise = head;
    while (hare != tortoise && hare != NULL && tortoise != NULL)
    {
        hare = hare->next;
        tortoise = tortoise->next;
        if (hare != NULL && hare->next != NULL)
            hare = hare->next;
        if (hare == tortoise)
            return 1;
    }
    if (hare == tortoise)
        return 1;
    return 0;
}
 int length(Node* head, bool hasloop)
{
    int len = 0;
    if (hasloop == false)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    else
    {
        Node* hare = head->next;
        Node* tortoise = head;
        while (hare != tortoise)
        {
            hare = hare->next;
            tortoise = tortoise->next;
            hare = hare->next;
            if (hare == tortoise)
                break;
        }
       
        int looplen = 0;
        while (hare->next!=tortoise)
        {
            hare = hare->next;
            looplen++;
        }
        
        looplen++;
        Node* begin = head;
        int startlen = 0;
        tortoise = tortoise->next;
        while (begin != tortoise)
        {
            
            begin = begin->next;
            tortoise = tortoise->next;
            startlen++;
        }
        
        return looplen + startlen;
        
    }
}
//Position this line where user code will be pasted.
int main() {
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *head=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
            head=insert(head,arr[i]);
            
        }
        int x;
        cin>>x;
        makeLoop(head,x);
        int lengthll=0;
        if(detectloop(head)==1)
        lengthll=length(head,true);
        else
        lengthll=length(head,false);
        
        removeTheLoop(head);
        
        if (detectloop(head) == 0 && lengthll == length(head, false))
        {
            cout<<1<<endl;
        }
        else
        cout<<0<<endl;
    }
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*The function removes the loop from the linked list if present
You are required to complete this method*/


/* 1. using tortoise and hare find the meeting point 
2. then move p1 to start and p2 at the meeting point 
3. keep p2 to make cycles and with each cycle of p2 move p1 one step forward
 and also see when next of p2 becomes equal to p1 that will be the start of loop and then simply make next of p2 as null */

// not that optimized
/* void remove_loop(Node *root,Node *meet)
{
    Node *ptr1=root;
    Node *ptr2=meet;
    
    
    while(1)
    {
        ptr2=meet;
        while(ptr1!=ptr2->next && ptr2->next!=meet)
        {
            ptr2=ptr2->next;
        }
        if(ptr2->next==ptr1)
        break;
        
        
    ptr1=ptr1->next;
    }
    
    ptr2->next=NULL;
    
} */

/* 1.count length 
2.move p1p2 in start 
3.move p2 till length of the loop 
4. move both one step each till their next guy is same...
that will b the start of loop,just make next of p2 as null to remove the loop */

void remove_loop(Node *head,Node *meet)
{
    int len=1;
    Node *ptr1,*ptr2;
    
    ptr1=ptr2=meet;
    
    while(ptr2->next!=ptr1)
    {
        ptr2=ptr2->next;
        len++;
    }
    ptr1=head;
    ptr2=head;
    
    for(int i=0;i<len;i++)
        ptr2=ptr2->next;
        
    while(ptr1->next!=ptr2->next)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    
    ptr2->next=NULL;
}

Node* isloop(Node *root)
{
    Node *slow=root;
    Node *fast=root;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast)
         return slow;
    }
    return NULL;
}
void removeTheLoop(Node *head)
{
     //Your code here
     Node *meet;
     meet=isloop(head);
     if (meet!=NULL)
         remove_loop(head,meet);
     else 
         return ;
     
}