#include <iostream>
#include <string>
#include<stack>
using namespace std;

bool check(string s)
{
    stack<char> st;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')
	        {
	            st.push(s[i]);
	            continue;
	        }
	        
	        if(st.empty())
	        return false;
	        
	        char x=st.top();st.pop();
	        
	   if(x=='(' && (s[i]=='}' || s[i]==']'))
	        return false;

	   //x=st.top();st.pop();
	   if(x=='[' && (s[i]=='}' || s[i]==')'))
	        return false;

	   //x=st.top();st.pop();
	   if(x=='{' && (s[i]==']' || s[i]==')'))
	        return false;

	  }
	  return (st.empty());
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    if(check(s))
	    cout<<"balanced"<<endl;
	   else
	    cout<<"not balanced"<<endl;
	   
	}
	return 0;
}
