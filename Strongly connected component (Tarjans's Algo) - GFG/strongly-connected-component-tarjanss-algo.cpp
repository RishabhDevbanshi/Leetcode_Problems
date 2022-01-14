// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    vector<vector<int>> res;
    vector<int> arr;
    int t = 0;
    
    void dfs(vector<int> adj[],int node,stack<int> &st,bool inS[],int disc[],int low[])
    {
        disc[node] = low[node] = t++;
        
        st.push(node); inS[node] = true;
        
        for(auto &child : adj[node])
        {
            if(disc[child] == -1)
            {
                dfs(adj,child,st,inS,disc,low);
                low[node] = min(low[node],low[child]);
            }
            else if(inS[child]) low[node] = min(low[node],disc[child]);
        }
        
        if(disc[node] == low[node])
        {
            while(st.top() != node)
            {
                arr.push_back(st.top());
                inS[st.top()] = false;
                st.pop();
            }
            arr.push_back(node);
            st.pop();
            inS[node] = false;
            sort(arr.begin(),arr.end());
            res.push_back(arr);
            arr.clear();
        }
        
    }
    
    
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        bool inS[V];
        memset(inS,false,sizeof inS);
        int disc[V] , low[V];
        memset(disc,-1,sizeof disc);
        memset(low,-1,sizeof low);
        
        stack<int> st;
        
        for(int i=0;i<V;i++)
        {
            if(disc[i] == -1)
                dfs(adj,i,st,inS,disc,low);
        }
        
        sort(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends