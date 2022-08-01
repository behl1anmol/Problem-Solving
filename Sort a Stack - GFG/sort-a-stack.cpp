//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

void Insert_sorted(stack<int> &s, int num){
        
        if(s.empty()) s.push(num);
        else if(s.top() > num){
            
            int x = s.top();
            s.pop();
            Insert_sorted(s, num);
            s.push(x);
        }
        else s.push(num);
    }


void SortedStack_utils(stack<int> &s){
        
    if(s.empty()) return;
        
    int num = s.top();
    s.pop();
    SortedStack_utils(s);
        
    Insert_sorted(s,num);
}



/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
    SortedStack_utils(s);
    
}