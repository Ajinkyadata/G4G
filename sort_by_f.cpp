/* Given an array A[] of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
For each testcase, in a new line, print each sorted array in a seperate line. For each array its numbers should be seperated by space.

Constraints:
1 ≤ T ≤ 70
30 ≤ N ≤ 130
1 ≤ Ai ≤ 60 

Example:
Input:
2
5
5 5 4 6 4
5
9 9 9 2 5

Output:
4 4 5 5 6
9 9 9 2 5 */

#include <iostream>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;

int compare(pair<int,int> &a, pair<int, int > &b)
{
    if(a.second==b.second)
    return (a.first<b.first);
    return (a.second> b.second);
}



int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;

        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];

	    map <int,int> mp;

        for(int i=0;i<n;i++)
        mp[a[i]]++;

        int psize=mp.size();
        pair <int ,int > p[psize];

        int j=0;
        for(auto it=mp.begin();it!=mp.end();it++)
         p[j++]=make_pair(it->first,it->second);

        sort(p,p+psize,compare);

        for(auto i=0;i<psize;i++)
        {
            int freq=p[i].second;
            while(freq--)
            cout<<p[i].first<<" ";
        }   	    
	    
        cout<<endl;
    }
}