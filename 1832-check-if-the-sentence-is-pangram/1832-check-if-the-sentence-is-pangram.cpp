class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> freq(26);
        for(auto &ch : sentence)
            freq[ch - 'a']++;
        for(auto &ele : freq)
            if(ele == 0)
                return false;
        return true;
    }
};