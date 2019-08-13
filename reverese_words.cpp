/*Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr*/

#include <iostream>
#include <stack>
#include<vector>
using namespace std;

void reverse(char *s, char *e)
{
    char temp;
    while(s<e)
    {temp=*s;
    *s++=*e;
    *e--=temp;}
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    char s[100000];
	    cin>>s;
	    char *temp=s;
	    char *begin=s;
	    char *t=s;
	    
	    while(*temp)
	    {
	        temp++;
	        
	        if(*temp=='\0')
	        {
	            reverse(begin,temp-1);
	            break;
	        }
	        else if (*temp=='.')
	        {
	            reverse(begin,temp-1);
	            begin=temp+1;
	        }

	        
	    }
	    reverse(t,temp-1);
	    
	    cout<<s;
	    cout<<endl;
	}

	return 0;
}
