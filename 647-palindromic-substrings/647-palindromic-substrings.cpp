class Solution {
public:
    int countSubstrings(string s) {
        
        int cnt = 0;
        
        for(int i=0;i<size(s);i++)
        {
            string temp = "";
            for(int j=i;j<size(s);j++)
            {
                temp += s[j];
                int start = 0 , end = size(temp)-1;
                bool ok = true;
                while(start < end)
                {
                    if(temp[start++] != temp[end--])
                    {
                        ok = false;
                        break;
                    }
                }
                
                cnt += ok;
            }
        }
        
        return cnt;
    }
};