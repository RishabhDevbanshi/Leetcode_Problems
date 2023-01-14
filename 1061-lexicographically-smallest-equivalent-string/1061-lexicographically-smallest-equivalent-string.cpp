class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        map<char,char> mp;
        for(int i=0;i<26;i++)
            mp['a'+i] = 'a'+i;
        
        function<char(char)> findPar = [&](char node){
            if(node == mp[node])
                return node;
            return mp[node] = findPar(mp[node]);
        };
        
        function<void(char,char)> unon = [&](char u,char v){
            // cout << u << " " << v << " -> ";
            u = findPar(u) , v = findPar(v);
            // cout << u << " " << v << "\n";
            if(u == v)
            {
                // cout << "map -> ";
                // for(auto &it : mp)
                // cout << "{ " <<  it.first << " " << it.second <<  "} , "; cout << "\n";
                return;
            }
            else if(u<v)
                mp[v] = u;
            else
                mp[u] = v;
            // cout << "map -> ";
                // for(auto &it : mp)
                // cout << "{ " <<  it.first << " " << it.second <<  "} , "; cout << "\n";
        };
        
        
        for(int i=0;i<size(s1);i++)
            unon(s1[i],s2[i]);
        
        string res = "";
        for(auto &ch : baseStr)
            res += findPar(ch);
        
        return res;
    }
};