class Solution {
public:
    string convert(string A, int B) {
        if(B == 1) return A;
        vector<vector<char>> arr(B,vector<char>(A.size(),'#'));
        int i=0, j=0, k=0;
        while(i<B and j<A.size()) arr[i++][0] = A[j++];

        i = B-2 , k = 1;
        bool fromDown = true;

        while(j < A.size())
        {
            if(fromDown)
            {
                while(i>=0 and j < A.size()) arr[i--][k] = A[j++];
                i+=2 , k++;
                fromDown = false;
            }
            else
            {
                while(i < B and j<A.size()) arr[i++][k] = A[j++];
                i-=2 , k++;
                fromDown = true;
            }
        }

        string res = "";

        for(auto v : arr)
        {
            for(auto ch : v) {if(ch!='#') res += ch;}
        }

        return res;
    }
};