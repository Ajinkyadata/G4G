/* Given a Binary Tree of size N, your task is to complete the function deletionBT(), that should delete a given node from the tree by making sure that tree shrinks from the bottom (the deleted not is replaced by bottommost and rightmost node).
Example:

Eample Deletion in Bt
Input:
The function takes two arguments as input, the reference pointer to the root of the binary tree and an integer Key that needed to be deleted from the tree.
There are T test cases and for each test case the function will be called separately.

Output:
For each test output will be the inorder traversal of the new tree.

Constraints:
1<=T<=100
1<=N<=103

Example:
Input:
2
7
10 20 L 20 30 L 30 40 L 30 50 R 40 60 L 60 70 R 70 80 L
40
6
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R
6
Output:
60 70 80 30 50 20 10 
4 2 5 1 7 3  */

#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int key;
	Node* left, *right;
};
struct Node* newNode(int key)
{
	struct Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
};
/* Inorder traversal of a binary tree*/
void inorder(struct Node* temp)
{
	if (!temp)
		return;
	inorder(temp->left);
	cout << temp->key << " ";
	inorder(temp->right);
}
void deletionBT(struct Node* root, int key);
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     int key;
     cin>>key;
     deletionBT(root, key);
     inorder(root);
     cout<<endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*
Structre of the node of the tree is as
struct Node
{
	int key;
	Node* left, *right;
};
*/
// you are required to complete this function
void deletionBT(struct Node* root, int key)
{
    // code here
    
    if (root==NULL)
    return ;
    queue <struct Node*> q;
    struct Node* temp,*deep,*k,*father;
    
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        if(temp->key==key)
        k=temp;
        q.pop();
        if(temp->left)
        {q.push(temp->left); father=temp; }
        if(temp->right)
        {q.push(temp->right); father=temp;}
    }
    if(father->right==temp)
    father->right=NULL;
    else
    father->left=NULL;
    
    int t=temp->key;
    temp->key=key;
    k->key=t;
    
    delete temp;  
    
}
