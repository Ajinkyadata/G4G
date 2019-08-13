/* Given a binary tree of size N, your task is to complete the function zigZagTraversal(), that prints the nodes of binary tree in ZigZag manner.

For Example:
For the below binary tree the zigzag order 
traversal will be 1 3 2 7 6 5 4.

Binary Tree Example
Input:
The function takes a single argument as input, the reference pointer to the root of the binary tree.
There will be T testcases and for each test case the function will be called separately.
Output:
For each test case print on a new line space separated all the nodes of the tree in ZigZag manner.
Constraints:
1<=T<=500
1<=N<=1000
Example:
Input:
1
10
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 4 8 L 5 9 R 6 10 L 7 11 R
Output:
1 3 2 4 5 6 7 11 10 9 8 */

//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *left, *right;
};
Node* newNode(int data)
{
	Node* node = new struct Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}
void zigZagTraversal(Node* root);
int main()
{
  int t;
  cin>>t;
  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin>>n;
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
     zigZagTraversal(root);
  }
  return 0;
}
// Contributed by: Hashit Sidhwa

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function 
// Function takes a single argument as input
// the root of the binary tree
// print a new line after each test case
void zigZagTraversal(Node* root)
{
	// Code here
	if(root==NULL)
	return ;
	stack <Node*> current;
	stack<Node*> next;
	bool flag=1;
	
	current.push(root);
	
	while(!current.empty())
	{
	    Node* temp=current.top();
	    current.pop();
	    
	    if(temp)
	    {
	        cout<<temp->data<<" ";
	        
	        if(flag)
	        {
	            if(temp->left)
	            next.push(temp->left);
	            if(temp->right)
	            next.push(temp->right);
	        }
	        else
	        {
	            if(temp->right)
	            next.push(temp->right);
	            if(temp->left)
	            next.push(temp->left);
	        }
	    }
	    
	    if(current.empty()==true)
	    {
	        flag=!flag;
	        swap(current,next);
	    }
	}
	cout<<endl;
}