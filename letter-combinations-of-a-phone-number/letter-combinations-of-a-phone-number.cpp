class Solution {
    string keypad[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void recur(string &A,int idx,vector<string> &res,string &str)
    {
        if(idx == A.size())
        {
            if(str.size() > 0) res.push_back(str);
            return;
        }

        int i = A[idx] - '0';
        for(auto ch : keypad[i])
        {
            str.push_back(ch);
            recur(A,idx+1,res,str);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string str;
        recur(digits,0,res,str);
        return res;
    }
};