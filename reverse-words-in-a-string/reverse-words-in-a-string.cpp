class Solution {
public:
    string reverseWords(string A) {
        vector<string> words;
        string str = "";
        int n = A.size();
        for(int i=0;i<n;i++)
        {
            if(A[i] == ' ')
            {
                string c = "";
                for(auto ch : str)
                {
                    int nu = ch;
                    if(nu != 32) c += ch;
                }
                if(c.size()>0) words.push_back(c);
                str = "";
            }
            else str += A[i];
        }

        if(str.size() > 0) words.push_back(str);

        n = words.size();
        A="";
        for(int i=n-1;i>0;i--) A += words[i] + " ";
        A += words[0];

        return A;
    }
};