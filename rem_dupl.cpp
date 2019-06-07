/* Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).

Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list and next line contains the linked list data.

Output:
For each testcase, there will be a single line of output which contains linked list with no duplicates.

User Task:
The task is to complete the function removeDuplicates() which should remove the duplicates from linked list. The printing is done automatically by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
4
2 2 4 5
5
2 2 2 2 2 */

#include <bits/stdc++.h>
#include<iostream>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
                Node *temp = head;
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
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
};*/
// root: head node
void del(Node *prev, Node *curr)
{
    prev->next=curr->next;
    delete curr;
}

Node *removeDuplicates(Node *root)
{
 // your code goes here
    Node *temp;
    temp=root;
    while(temp->next!=NULL)
    {
        Node *temp1;
        temp1=temp->next;
        if(temp->data==temp1->data)
        del(temp,temp->next);
        else
        temp=temp->next;
    }
    return root;
}