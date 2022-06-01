// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

struct Node
{
    bool isEnd;
    Node *arr[26];

    Node()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            arr[i] = nullptr;
    }
};

#define size(x) x.size()


class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    int wordBreak(string s, vector<string> &wordDict)
        {

            Node *root = new Node();

            auto add =[& ](string & word)
            {
                auto tmp = root;
                for (auto &ch: word)
                {
                    if (!tmp->arr[ch - 'a'])
                        tmp->arr[ch - 'a'] = new Node();
                    tmp = tmp->arr[ch - 'a'];
                }

                tmp->isEnd = true;
            };

            for (auto &word: wordDict)
                add(word);

            vector<bool> dp(size(s) + 1, false);
            dp[0] = true;
            
            for(int i=0;i<=size(s);i++)
            {
                if(dp[i])
                {
                    auto tmp = root;
                    for(int j=i;j<size(s);j++)
                    {
                        if(!tmp->arr[s[j] - 'a'])
                            break;
                        tmp = tmp->arr[s[j] - 'a'];
                        if(tmp->isEnd)
                            dp[j+1] = true;
                    }
                }
            }

            return dp.back();
        }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends