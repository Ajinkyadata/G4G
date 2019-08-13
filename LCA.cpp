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
Node * lca(Node* ,int ,int );
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
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
     int a,b;
     cin>>a>>b;
     Node * k = lca(root,a,b);
     cout<<k->data<<endl;
  }
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
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
/* If n1 and n2 are present, return pointer
   to LCA. If both are not present, return 
   NULL. Else if left subtree contains any 
   of them return pointer to left.*/
bool common(Node* root,int n,vector<Node* >& v)
{
    int h1,h2;
    
    if(root==NULL)
    return 0;
    
    v.push_back(root);
    if(root->data==n)
    return 1;
   // h1=common(root->left,n,v);
    //h2=common(root->right,n,v);
    
    if(root->left && common(root->left,n,v) || common(root->right,n,v) && root->right)
    return 1;
    
    v.pop_back();
    return 0;
}
   

Node * lca(Node* root ,int n1 ,int n2 )
{
   //Your code here 
   int a,b;
   if(root==NULL)
   return NULL;
   vector<Node* >v1,v2;
   
   a=common(root,n1,v1);
   b=common(root,n2,v2);
   
   cout<<a<<b<<"--";
   
   if(a==0 || b==0)
   return NULL;
   else
   {
        auto i=v1.begin();auto j=v2.begin();
        while((*i)->data==(*j)->data)
        {
            i++;j++;
        }
        return *(i-1);
   }
 
}