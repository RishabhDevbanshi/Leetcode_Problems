class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        if(size(s) < 10)
            return {};
        
        vector<string> res;
        
        auto kardo = [](deque<char> q){
          string str = "";
            while(!q.empty())
                str += q.front() , q.pop_front();
            
            return str;
        };
        
        deque<char> q;
        map<deque<char>,int> mp;
        
        for(int i=0;i<10;i++)
            q.push_back(s[i]);
        
        mp[q]++;
        
        for(int i=10;i<size(s);i++)
        {
            q.pop_front();
            q.push_back(s[i]);
            mp[q]++;
            if(mp[q] == 2)
            {
                string str = kardo(q);
                res.push_back(str);
            }
        }
        
        return res;
    }
};