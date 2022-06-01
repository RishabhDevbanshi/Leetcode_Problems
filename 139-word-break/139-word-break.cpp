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

class Solution
{
    public:
        bool wordBreak(string s, vector<string> &wordDict)
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