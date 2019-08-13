#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,flag=0;
	    cin>>n;
	    long int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	    sort(arr,arr+n);
	    
	    //for(int i=0;i<n;i++)
	    //cout<<arr[i];
	    
	    int l=0,r=n-2,k;
	    
	    for(k=n-2;k>=2;k--)
	    {
	        cout<<arr[l]<<" "<<arr[r]<<" "<<arr[k]<<endl;
	        
	        while(l<r)
	        {
	        if(arr[l]*arr[l]+arr[r]*arr[r]==arr[k]*arr[k])
	        {
	            cout<<"Yes"<<endl;
	            flag=1;
	            break;
	        }
	        else if(arr[l]*arr[l]+arr[r]*arr[r]<arr[k]*arr[k])
	            l++;
	        else
	            r--;
	        }
	    }
	    if(flag==0)
	    cout<<"No"<<endl;
	}
	
	return 0;
}