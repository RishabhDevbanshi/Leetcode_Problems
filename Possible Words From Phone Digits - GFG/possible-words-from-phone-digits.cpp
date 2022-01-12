// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    map<int,string> mp = {
        {2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},
        {7,"pqrs"},{8,"tuv"},{9,"wxyz"}
    };
    
    
    void recur(int *a,int n,int idx,string &str,vector<string> &arr)
    {
        if(idx >= n) 
        {
            arr.push_back(str);
            return;
        }
        
        for(auto &ch : mp[a[idx]])
        {
            str += ch;
            recur(a,n,idx+1,str,arr);
            str.pop_back();
        }
    }
    
    
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        string str; vector<string> arr;
        
        recur(a,N,0,str,arr);
        
        return arr;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends