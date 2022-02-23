class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string ans = votes[0];
        vector<vector<int>> rank(30,vector<int>(30));
        // memset(rank,0,sizeof rank);
        
        for(auto &vote : votes)
        {
            for(int i=0;i<size(vote);i++)
                rank[vote[i] - 'A'][i]++;
        }
        
        sort(ans.begin(),ans.end(),[&](auto &a,auto &b){
            if(rank[a - 'A'] == rank[b - 'A'])
                return a < b;
            return rank[a - 'A'] > rank[b - 'A']; 
        });
        
        
        return ans;
    }
};