class Solution {
    
    vector<int> arr;
    unordered_map<string,int> dp;
    
    string makeKey(vector<int> &arr,int pos)
    {
        string str = to_string(pos) + '$';
        vector<int> copy = arr;
        sort(copy.begin(),copy.end());
        for(auto val : copy) str += to_string(val) + '$';
        
        return str;
    }
    
    int recur(vector<int> &tasks,int sessionTime,int pos)
    {
        if(pos >= tasks.size()) return 0;
        
        string key = makeKey(arr,pos);
        
        if(dp.find(key) != dp.end()) return dp[key];
        
        arr.push_back(tasks[pos]);
        int ans = 1 + recur(tasks,sessionTime,pos+1);
        arr.pop_back();
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] + tasks[pos] <= sessionTime)
            {
                arr[i] += tasks[pos];
                ans = min(ans,recur(tasks,sessionTime,pos+1));
                arr[i] -= tasks[pos];
            }
        }
        
        return dp[key] = ans;
    }
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        return recur(tasks,sessionTime,0);
    }
};