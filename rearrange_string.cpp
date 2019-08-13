#include<iostream>
#include<queue>
using namespace std;

class minheap
{
    public:
    pair<char, int> arr;
    int cap;
    int hsize;
    minheap(int x)
    {
        hsize=0;
        cap=x;
        pair<char, int> arr[cap];
    }

    string extractmin(){}
    void deletemin(){}
    void heapy(){}
    void decreasekey(){}
    void insert(){}
};

struct compare
{
    
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        priority_queue<minheap,vector<minheap>,compare>

    }

}
