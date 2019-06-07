/* Given a singly linked list of 0s and 1s find its decimal equivalent

   Input  : 0->0->0->1->1->0->0->1->0
   Output : 50
   
Decimal Value of an empty linked list is considered as 0.

Since the answer can be very large, answer modulo 1000000007 should be printed.

Input:
The task is to complete the method which takes one argument: the head of the linked list. The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return should decimal equivalent modulo 1000000007

Constraints:
1 <=T<= 200
0 <=N<= 100
Data of Node is either 0 or 1

Example:
Input:
2
3
0 1 1    
4
1 1 1 0

Output:
3
14 */




// Program to check if linked list is empty or not
#include<iostream>
using namespace std;
const long long unsigned int MOD = 1000000007;
/* Link list Node */
struct Node
{
    bool data;
    struct Node* next;
};
long long unsigned int decimalValue(struct Node *head);
void append(struct Node** head_ref, struct Node **tail_ref, bool new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
bool isEmpty(struct Node *head);
/* Driver program to test above function*/
int main()
{
    bool l;
    int i, n, T;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
        cout << decimalValue(head) << endl;
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */
/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;
}; */
// Should return decimal equivalent modulo 1000000007 of binary linked list 

int powo(int x,int y)
{
    int mul=1;
    for(int i=0;i<y;i++)
    mul*=x;
    
    return mul;
    
}


long long unsigned int decimalValue(Node *head)
{
   Node *temp;
   temp=head;
   int c=0;
   while(temp->next!=NULL)
   {
       temp=temp->next;
       c++;
   }
   //cout<<c<<" ";

   temp=head;
   int i=c;
   long long unsigned int sum=0;
   while(temp!=NULL)
   {
       sum+=(temp->data)*powo(2,i);
       temp=temp->next;
       i--;
   }
  // sum=sum%1000000007;
   return sum%100000000;
}