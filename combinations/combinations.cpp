class Solution {
    void recur(int A,int B,vector<int> &arr,vector<vector<int>> &res,int num)
    {
        if(num > A)
        {
            if(arr.size() == B) res.push_back(arr);
            return;
        }

        recur(A,B,arr,res,num+1);

        arr.push_back(num);
        recur(A,B,arr,res,num+1);
        arr.pop_back();
    }
public:
    vector<vector<int>> combine(int A, int B) {
        vector<int> arr;
        vector<vector<int>> res;

        recur(A,B,arr,res,1);
        
        return res;
    }
};