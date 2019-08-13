/* Suppose there is a circle. There are N petrol pumps on that circle.
 You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.

Your task is to complete the function tour() which returns an integer denoting 
the first point from where a truck will be able to complete the circle 
(The truck will stop at each petrol pump and it has infinite capacity).

Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Input:
The first line of input will be the number of test cases. Then T test 
cases follow. Each Test case contains 2 lines. The first 
line will contain an integer N denoting the number of petrol pumps and in the next 
line are N space separated values petrol and distance denoting the amount of petrol every petrol 
pump has and the distance to next petrol pump respectively .

Output:
The output of each test case will be the index of the the first point 
from where a truck will be able to complete the circle otherwise -1 .

Constraints:
1 <= T <= 100
1 <= N <= 50
1 <= petrol, distance <= 100

Example (To be used only for expected output)
Input:
1
4
4 6 6 5 7 3 4 5
Output:
1

Explanation:
Testcase 1: there are 4 petrol pumps with amount of petrol and 
distance to next petrol pump value pairs as {4, 6}, {6, 5}, {7, 3} and {4, 5}. 
The first point from where truck can make a circular tour is 2nd petrol pump. Output in this case is 1 
(index of 2nd petrol pump). */


#include<bits/stdc++.h>
using namespace std;
struct petrolPump
{
    int petrol;
    int distance;
};
int tour(petrolPump [],int );
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/
/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
    int start=0,en=1,index=start,sum=0;
    
    sum+=p[start].petrol-p[start].distance;
    
    while(start!=en)
    {
        while(sum<0 && start!=en)
        {
            sum-=p[start].petrol-p[start].distance;
            start=(start+1)%n;
            index=start;
            if(en<start)
            en=start;
            
            if(start==0)
            return -1; // fir se kon jayega
        }
        
        
        sum+=p[en].petrol-p[en].distance;
        en=(en+1)%n;// yaaad rahe
        
    }
    
    if (sum<0)
    return -1;
    else 
    return index;
}