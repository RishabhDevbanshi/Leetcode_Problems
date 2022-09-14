class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char,queue<int>> mp;
        
        int tot = 0,i=0;
        
        for(auto &ch : croakOfFrogs)
        {
            if(ch == 'c')
            {
                
            }
            else if(ch == 'r')
            {
                if(mp['c'].empty())
                    return -1;
                mp['c'].pop();
            }
            else if(ch == 'o')
            {
                if(mp['r'].empty())
                    return -1;
                mp['r'].pop();
            }
            else if(ch == 'a')
            {
                if(mp['o'].empty())
                    return -1;
                mp['o'].pop();
            }
            else
            {
                if(mp['a'].empty())
                    return -1;
                mp['a'].pop();
            }
            if(ch != 'k') mp[ch].push(i);
            i++;
            int x = size(mp['c']) + size(mp['r']) + size(mp['o']) + size(mp['a']) + size(mp['k']);
            tot = max<int>(tot,x);
        }
        
        int x = size(mp['c']) + size(mp['r']) + size(mp['o']) + size(mp['a']) + size(mp['k']);
        
        if(x)
            return -1;
        
        return tot;
    }
};