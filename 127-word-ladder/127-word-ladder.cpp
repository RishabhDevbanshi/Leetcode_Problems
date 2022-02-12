class Solution {
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        unordered_map<string,bool> mp;
        
        typedef long long ll;
        int ans = 0;
        
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty())
        {
            int sz = size(q);
            ans++;
            for(int i=0;i<sz;i++)
            {
                string word = q.front();
                q.pop();
                
                if(word == endWord)
                    return ans;
                
                for(int i=0;i<size(word);i++)
                {
                    string temp = word;
                    for(int j=0;j<26;j++)
                    {
                        temp[i] = 'a' + j;
                        if(st.count(temp) and mp.count(temp)==0)
                            q.push(temp) , mp[temp] = true;
                    }
                }
            }
        }
        
        
        return 0;
    }
};