class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n) , suffix(n);

        int pro = 1;
        for (int i = 0; i < n; i++)
        {
            pro *= nums[i];
            prefix[i] = pro;
        }

        pro = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            pro *= nums[i];
            suffix[i] = pro;
        }

        vector<int> res(n, 1);
        // for (auto &val : prefix) cout << val << " ";
        // cout << endl;
        // for (auto &val : suffix) cout << val << " ";
        // cout << endl;

        for (int i = 0; i < n ; i++)
        {
            if (i - 1 >= 0) res[i] *= prefix[i - 1];
            if (i + 1 < n) res[i] *= suffix[i + 1];
        }

        return res;
    }
};