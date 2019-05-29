/* Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Expected Time Complexity: O(n)

Input:
The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each test case consists of three lines. First line of each testcase contains an integer N denoting size of the array. Second line contains N space separated integer denoting elements of the array. Third line of the test case contains an integer K.

Output:
Corresponding to each test case, print the kth smallest element in a new line.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105
1 <= K <= N

Example:
Input:
2
6
7 10 4 3 20 15
3
5
7 10 4 20 15
4

Output:
7
15 */

/* #include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
//int arr[30];

int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int N;
        vector<int> v;
        cin>>N;

        for (int i=0; i<N; i++)
        {
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        int k;
        cin>>k;

        sort(v.begin(),v.end());
          
        cout<<v.at(k-1)<<endl;        
    }

} */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int h[1000]={0};
        for(int i=0;i<n;i++){
        cin>>a[i];
            h[a[i]]++;
        }
 
        int k;
        cin>>k;
        for(int i=1;i<=1000;i++){
            if(h[i]>=1)
            k--;
            if(k==0){
            cout<<i<<endl;
            break;}
        }
        
    }
	//code
	return 0;
}