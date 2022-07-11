// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    vector<int> res;
    sort(a,a+n);
    int left = 0 , right = n-1;
    while(left <= right)
    {
        res.push_back(a[right--]);
        if(left <= right) res.push_back(a[left++]);
    }
    
    int fl = 0;
    for(int i=0;i<n;i++)
    {
        if(i%2 == 0) fl += res[i];
        else fl -= res[i];
        
        if(fl == 0)
            return {-1};
    }
    
    return res;
}
