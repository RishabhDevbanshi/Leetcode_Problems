class Solution {
public:
    string subStrHash(string s, long long power, long long modulo, int k, int hashValue) {
        typedef long long ll;
        ll hash = 0;
        ll pr = 1;
        int idx = size(s);
        
        int n = size(s);
        
        for(int i=n-1;i>=0;i--)
        {
            hash = ((hash * power)%modulo + ((s[i] - 'a' + 1))%modulo)%modulo;
            
            // cout<<hash<<" ";
            
            if(i + k >= n)
            {
                pr = (pr * power)%modulo;
            }
            else
            {
                hash = (hash - ((s[i+k] - 'a' + 1) * pr)%modulo  
                        + modulo)%modulo;
            }
            
            if(hash == hashValue)
            {
                // cout<<idx<<" ";
                idx = i;
            }
        }
        // cout<<idx<<"\n";
        return s.substr(idx,k);
    }
};