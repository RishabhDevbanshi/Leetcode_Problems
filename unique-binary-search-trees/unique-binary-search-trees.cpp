class Solution {
    void recur(int n,unordered_map<int,int> &mp)
    {
        if(n==0 || n==1) return;
        recur(n-1,mp);
        int val = 0;
        for(int i=1;i<=n;i++)
        {
            int left = i-1;
            int right = n-i;
            val += mp[left]*mp[right];
        }
        mp[n] = val;
    }
public:
    int numTrees(int n) {
        unordered_map<int,int> mp;
        mp[0] = mp[1] = 1;
        recur(n,mp);
        return mp[n];
    }
};