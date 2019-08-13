/* You are given a binary tree for which you have to print its vertical order traversal. your task is to complete the function verticalOrder which takes one argument the root of the binary tree and prints the node of the binary tree in vertical order as shown below.
If there are multiple nodes passing through a vertical line, then they should printed as they appear in level order traversal.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains 2 lines of input. The first line contains number of operations to insert the nodes. The second line contains the nodes and their position during the insertion.

Output Format:
For each testcase, the vertical order traversal of the tree is to be printed. The nodes' data are to be separated by spaces.

Your Task:
This is a function problem. Your task is to just complete the verticalOrder() function and you don't have to take any input or output. The newline is automatically appended by the driver code.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 5000

Example:
Input:
4
3
1 2 L 1 3 R 3 5 L
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R
4
1 2 L 1 3 R 2 4 R 4 5 R

Output:
2 1 5 3
3 1 2
40 20 10 60 30
2 1 4 3 5

Explanation:
Testcase1:
         1
       /     \
    2         3
              /
         5
As it is evident from the above diagram that during vertical traversal 2 will come first, then 1 and  5, and then 3. So output is 2 1 5 3 */

#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void verticalOrder(Node *root);
/* Driver program to test size function*/
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
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     verticalOrder(root);
     cout << endl;
  }
  return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
void verticalOrder(Node *root)
{
    if(root==NULL)
    return ;
    
    int hd=0;
    map<int ,vector<int>> mp;
    
    queue <pair<int ,struct Node*>> q;
    
    q.push(make_pair(hd,root));
    
    while(!q.empty())
    {
        pair <int ,struct Node*> temp=q.front();
        q.pop();
        hd=temp.first;
        struct Node* node=temp.second;
        
        mp[hd].push_back(node->data);
        
        if(node->left)
        q.push(make_pair(hd-1,node->left));
        
        if(node->right)
        q.push(make_pair(hd+1,node->right));
        
    }
    
    for(auto itr=mp.begin();itr!=mp.end();itr++)
    {
        for(int i=0;i<itr->second.size();++i)
        {
            cout<<itr->second[i]<<" ";
        }
        //cout<<endl;
    }
    
}