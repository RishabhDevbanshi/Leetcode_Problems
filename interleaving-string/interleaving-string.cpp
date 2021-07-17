class Solution {
    bool recur(string &s1,string &s2,string &s3,
               int n1,int n2,int n3,int p1,int p2,int p3,map<string,bool> &mp)
    {
        if(p3 == n3)
        {
            if(p1 == n1 and p2 == n2) return true;
            return false;
        }
        
        string key = to_string(p1) + "," + to_string(p2) + "," + to_string(p3) + ".";
        
        if(mp.find(key) != mp.end())
            return mp[key];
        
        bool one = false, two = false;
        
        if(s1[p1] == s3[p3])
            one = recur(s1,s2,s3,n1,n2,n3,p1+1,p2,p3+1,mp);
        if(s2[p2] == s3[p3])
            two = recur(s1,s2,s3,n1,n2,n3,p1,p2+1,p3+1,mp);
        
        return mp[key] = one || two;
        
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if(n1 + n2 != n3) 
            return false;
        map<string,bool> mp;
        return recur(s1,s2,s3,n1,n2,n3,0,0,0,mp);
        
    }
};