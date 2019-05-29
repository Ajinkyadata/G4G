/* Given an unsorted array of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Note: If you find multiple answers then print the Smallest number found. Also, expected solution is O(n) time and constant extra space.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print B, the repeating number followed by A which is missing in a single line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ A[i] ≤ N

Example:
Input:
2
2
2 2
3 
1 3 3

Output:
2 1
3 2 */

#include<iostream>
#include<vector>

using namespace std;


int getmax(vector<int> &v)
{
    int max=0,index;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>max)
        {
            max=v[i];
            index=i;
        }        
    }
    return index;
}

int getmin(vector<int> &v)
{
    int min=99999,index;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>min)
        {
            min=v[i];
            index=i;
        }        
    }
    return index;
}

int main()
{
    int T;
    cin>>T;
    for(int i=0; i<T; i++)
    {
        int N;
        vector<int> v,y,z;
        cin>>N;
        for(int j=0; j<N; j++)
        {
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        int max,t;
        max=getmax(v);
        t=v[max];
        vector <int > w;
        w.resize(100000);
        w.assign(100000,0);

        //cout<<w[200]<<endl;

        for(int j=0;j<N;j++)
        {
            w[v[i]]=w[v[i]]+1;
            //cout<<w[v[i]]<<" ";
        }

        for(int j=0;j<N;j++)
        {
            if(w[i]==2)
            y.push_back(w[i]);
            else if(w[i]==0)
            z.push_back(w[i]);
        }

        int miss,rep;
        miss=getmin(y);
        rep=getmin(z);

        cout<<miss<<" "<<rep<<endl;        
    }


    return 0;
}