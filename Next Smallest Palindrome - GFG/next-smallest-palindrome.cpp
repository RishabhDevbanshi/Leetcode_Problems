// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	vector<int> generateNextPalindrome(int number[], int n) {
	    
	    vector<int> v;
	    for(int i=0;i<n;i++) v.push_back(number[i]);
	    
	    if(v.size() == 1)
	    {
	        if(v[0] == 9)
	        {
	            return {1,1};
	        }
	        else return {++v[0]};
	    }
	    
	    auto add=[&](int i){
		int carry = 1;
		while(i >= 0 && carry){
			v[i] += carry;
			carry = v[i]/10;
			v[i] %= 10;
			i--;
		}
		if(carry){
			v.insert(v.begin(),1);
		}
	};

	auto copy=[&](){
		int l=0, r= v.size()-1;
		while(l <= r){
			v[r] = v[l];
			r--;
			l++;
		}
	};

	auto compare=[&](int i,int j){
		bool ok = true;
		bool allequal = true;
		while( i >=0 &&  j<n){
			if(v[i] > v[j]) return false;
			if(v[j] > v[i]) return true;
			allequal &= v[j] == v[i];
			i--;j++;
		}
		return allequal;
	};

	auto odd=[&](){
		int p = n/2;
		int i=p-1, j = p+1;
		if(compare(i,j)){
			add(p);
		}
		copy();
	};

	auto even=[&](){
		int p = n/2;
		int i = p-1, j = p;
		if(compare(i,j)){
			add(i);
		}
		copy();
	};

	if(n&1){
		odd();
	}
	else{
		even();
	}

	if(v.size() == 1){
		if(v[0] == 9){
			v = {1,1};
		}
		else
			v[0]++;
	}
	return v;
	}

};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends