class Solution {
public:
    int deleteAndEarn(vector<int>& arr) {
        int mx = 0;
        int n = size(arr);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            // cin >> arr[i];
            mx = max(mx, arr[i]);
            mp[arr[i]]++;
        }

        vector<int> dp(mx + 1, 0);

        dp[1] = mp.find(1) == mp.end() ? 0 : mp[1];

        for (int i = 2; i < size(dp); i++)
        {
            int val = mp.find(i) == mp.end() ? 0 : mp[i];
            dp[i] = max(dp[i - 1], dp[i - 2] + (val * i));
        }

        // cout << dp.back() << "\n";
        return dp.back();
    }
};