class Solution {
public:
    string reverseVowels(string s) {
        auto isVowel = [&](char ch){
            return ch=='a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U';
        };
        
        int start = 0, end = size(s)-1;
        while(start < end)
        {
            while(start < end and !isVowel(s[start])) ++start;
            while(start < end and !isVowel(s[end])) --end;
            // cout << start << " " << end << "\n";
            swap(s[start],s[end]);
            ++start , --end;
        }
        
        
        return s;
    }
};