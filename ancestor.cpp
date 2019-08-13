/* Given a Binary Tree and a target key, your task is to complete the function printAncestors() that prints all the ancestors of the key in the given binary tree.

              1
            /   \
          2      3
        /  \
      4     5
     /
    7
Key: 7
Ancestor: 4 2 1
Input:
The function takes 2 arguments as input, first the reference pointer to the root node of the binary tree and a integer value target. There will be multiple test cases and for each test the function will be called seperately.
Output:
For each test print all the ancestors of the target vlue in the order of their hierarchy.
Constraints:
1<=T<=100
1<=N<=100
Example:
Input:
2
2
1 2 L 1 3 R
2
5
1 2 R 1 3 L 2 4 L 2 5 R 4 7 L
7
Ouput:
1
4 2 1 */


#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Node
{
int data;
struct Node* left;
struct Node* right;
};
bool printAncestors(struct Node *root, int target);
struct Node* newNode(int data)
{
struct Node* node = (struct Node*)malloc(sizeof(struct Node));
node->data = data;
node->left = NULL;
node->right = NULL;
return(node);
}
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
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
     int a;
     cin>>a;
    printAncestors(root, a);
  }
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
// Function should print all the ancestor of the target node
bool print(struct Node *root, int target)
{
    if(root==NULL)
     return 0;
     
     if(root->data==target)
     return 1;
     
     bool h1=print(root->left,target);
     bool h2=print(root->right,target);
     
     if(h1||h2)
     {cout<<root->data<<" ";
     return 1;}
     else 
     return 0;
}


bool printAncestors(struct Node *root, int target)
{
     // Code here
    bool f=print(root,target);
    cout<<endl;
    return true;
    
    
     
}