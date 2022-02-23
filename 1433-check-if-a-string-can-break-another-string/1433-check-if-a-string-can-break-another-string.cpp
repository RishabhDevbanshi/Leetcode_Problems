class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        
        bool cana = true , canb = true;
        
        for(int i=0;i<size(s1);i++)
        {
            cana = cana and s1[i] >= s2[i];
            canb = canb and s2[i] >= s1[i];
        }
        
        return cana || canb;
    }
};