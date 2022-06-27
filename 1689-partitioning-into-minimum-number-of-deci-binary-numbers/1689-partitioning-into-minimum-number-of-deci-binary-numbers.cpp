class Solution {
public:
    int minPartitions(string n) {
        
        int tot = 0;
        
        for(int i=0;i<size(n);i++)
        {
            tot += max(0,(n[i]-'0') - tot);
        }
        
        return tot;
    }
};