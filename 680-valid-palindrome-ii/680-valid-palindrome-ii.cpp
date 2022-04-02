class Solution {
public:
    bool validPalindrome(string s) {
        
        if(size(s) < 3)
            return true;
        
        int start = 0 , end = size(s) - 1;
        while(start <= end)
        {
            if(s[start] == s[end])
                start++ , end--;
            else
                break;
        }
        
        if(start > end)
            return true;
        
        function<bool(int,int)> check = [&](int i,int j){
            bool ok = true;
            while(i<=j)
            {
                if(s[i] != s[j])
                {
                    ok = false;
                    break;
                }
                i++ , j--;
            }
            
            return ok;
        };
        
        return check(start+1,end) || check(start,end-1);
        
    }
};