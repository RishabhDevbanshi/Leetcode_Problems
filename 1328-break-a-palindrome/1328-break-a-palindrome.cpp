class Solution {
public:
    string breakPalindrome(string pallindrome) {
        
        if(size(pallindrome) == 1)
            return "";
        
        for(int i=0;i<size(pallindrome)>>1;++i)
        {
            // cout << pallindrome[i] << " ";
            if(pallindrome[i] != 'a')
            {
                pallindrome[i] = 'a'; 
                return pallindrome;
            }
        }
        // cout << "\n";
        
        if(size(pallindrome)&1)
            pallindrome.back() = 'b';
        else
            pallindrome[size(pallindrome)>>1] = 'b';
        
        return pallindrome;
    }
};