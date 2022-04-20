// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
	    typedef long double ld;
	    
	    priority_queue<pair<ld,ld>> pq;
	    
	    for(int i=0;i<w.size();i++)
	    {
	        ld a = w[i] , b = p[i];
	        pq.push({b/a,a});
	    }
	    
	    auto isSq = [&](ld num){
	      return floor(sqrt(num)) == ceil(sqrt(num));  
	    };
	    
	    ld profit = 0;
	    
	    while(!pq.empty() and C>0)
	    {
	        auto p = pq.top();
	        pq.pop();
	        
	        ld x = p.first , y = p.second;
	        
	        if(isSq(y))
	            continue;
	            
	           //cout << x << " " << y <<" \n";
	       
	       ld req = min<ld>(C,y);
	       //cout << C << " " << req << " " << x << "\n";
	       C -= req;
	       
	       
	       profit += req * x;
	    }
	    
	    
	    return profit;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends