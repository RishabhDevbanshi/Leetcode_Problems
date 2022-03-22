class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        
        while(k)
        {
            int x = (n-1)*26;
            
            int diff = k - x;
            
            // cout << k << " ";
            
            if(diff < 2)
                ans += 'a' , k--;
            else 
                ans += ('a' + diff - 1) , k -= diff;
            
            // cout << k << " " << diff << "\n";
             --n;
        }
        
        
        return ans;
    }
};