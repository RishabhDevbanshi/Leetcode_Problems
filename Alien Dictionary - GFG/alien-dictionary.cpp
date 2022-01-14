// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    void dfs(vector<int> g[],int node,stack<int> &st,bool vis[])
    {
        vis[node] = true;
        for(auto &child : g[node])
        {
            if(!vis[child])
            {
                dfs(g,child,st,vis);
            }
        }
        
        st.push(node);
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> g[K];
        
        for(int i=0;i<N-1;i++)
        {
            int mn = min(dict[i].size(),dict[i+1].size());
            for(int j=0;j<mn;j++)
            {
                if(dict[i][j] != dict[i+1][j])
                {
                    int u = dict[i][j]-'a' , v = dict[i+1][j]-'a';
                    g[u].push_back(v);
                    break;
                }
            }
        }
        
        stack<int> st;
        bool vis[K];
        string res;
        memset(vis,false,sizeof vis);
        for(int i=0;i<K;i++)
        {
            if(vis[i]) continue;
            dfs(g,i,st,vis);
            
            // string res;
        }
        while(!st.empty())
        {
            res += 'a' + st.top();
            st.pop();
        }
        // reverse(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends