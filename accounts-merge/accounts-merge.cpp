class Solution {
    bool haveCommon(vector<string> &a,vector<string> &b)
    {
        if(a[0] != b[0]) return false;
        for(auto &ele : b)
        {
            if(ele == b[0]) continue;
            for(auto &cand : a) 
            {
                if(cand == ele) return true;
            }
        }
        
        return false;
    }
    
    void dfs(vector<int> adj[],int node,vector<int> &con,bool *vis)
    {
        vis[node] = 1;
        con.push_back(node);
        for(auto &child : adj[node])
        {
            if(!vis[child]) dfs(adj,child,con,vis);
        }
    }
    
    void merge(vector<int> &con,vector<vector<string>> &res,vector<vector<string>> &acc)
    {
        vector<string> arr(1);
        arr[0] = acc[con[0]][0];
        set<string> st;
        for(auto &idx : con)
        {
            for(int i=1;i<acc[idx].size();i++)
                st.insert(acc[idx][i]);
        }
        
        for(auto &ele : st) arr.push_back(ele);
        res.push_back(arr);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> adj[accounts.size()];
        
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=i+1;j<accounts.size();j++)
            {
                bool check = haveCommon(accounts[i],accounts[j]);
                if(check) 
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<vector<string>> res;
        bool vis[accounts.size()];
        memset(vis,false,sizeof(vis));
        // int cnt = 0;
        for(int i=0;i<accounts.size();i++)
        {
            vector<int> con;
            if(!vis[i])
            {
                dfs(adj,i,con,vis);
                merge(con,res,accounts);
            }
        }
        
        
        // cout<<cnt<<" ";
        return res;
    }
};