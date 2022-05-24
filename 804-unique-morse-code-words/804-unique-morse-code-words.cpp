class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> arr = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        
        unordered_set<string> st;
        
        for(auto &word : words)
        {
            string str = "";
            for(auto &ch : word)
                str += arr[ch - 'a'];
            st.insert(str);
        }
        
        return size(st);
    }
};