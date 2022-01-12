// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.


string f(int i)
{
    string bin = "";
    while(i)
    {
        bin += '0' + (i%2);
        i /= 2;
    }
    
    reverse(bin.begin(),bin.end());
    return bin;
}

vector<string> generate(int N)
{
	vector<string> res;
	for(int i=1;i<=N;i++)
	{
	    res.push_back(f(i));
	}
	
	return res;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends