/* Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Input Format:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list and next line contains linked list elements and last line contains k, by which linked list is to be rotated.

Output Format:
For each testcase, print the rotated linked list.

User Task:
The task is to complete the function rotate() which takes head reference as the first argument and k as the second argument. The printing is done automatically by the driver code.

Constratints:
1 <= T <= 100
1 <= N <= 103
1 <= k <= 103

Example:
Input:
2
8
1 2 3 4 5 6 7 8
4
5
2 4 7 8 9
3

Output:
5 6 7 8 1 2 3 4
8 9 2 4 7 */
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
Node *rotate(struct Node *head, int k);
Node *insert() {
    int n, i, value;
    struct Node *temp, *head = NULL;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> value;
        if (i == 0) {
            head = new Node(value);
            temp = head;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
    return head;
}
void printList(Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf(" ");
}
/* Drier program to test above function*/
int main(void) {
    int t, k;
    scanf("%d", &t);
    while (t--) {
        Node *head = insert(); // insert function to build linked list
        scanf("%d", &k);
        head = rotate(head, k); // rotate linked list anti-clockwise  by k nodes
        printList(head);        // print linked list after rotation
    }
    return (0);
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
}; */
/*  This function should rotate list counter-clockwise
    by k and return new head (if changed) */
Node* rotate(Node* head, int k) {
    
    /* Node *temp=head;
    Node *first=head;
    
    while(temp!=NULL && k!=1)
    {
        temp=temp->next; k--;
    }
    head=temp->next;
    temp->next=NULL;
    Node *temp2=head;
    while(temp2->next!=NULL)
    temp2=temp2->next;
    temp2->next=first;
    return head; */


    Node *temp=head;
    while(temp!=NULL && k!=1)
        {temp=temp->next;k--;}

    if(temp==NULL)
    return head;
    else
    {
        Node *kthnode=temp;
        while(temp->next!=NULL)
        temp=temp->next;

        temp->next=head;
        head=kthnode->next;
        kthnode->next=NULL;
        return head;
    }
    
}