class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int sum) {
        
            typedef long long ll;
        vector<vector<int>> res;
          int n = arr.size();
          // debug(n);
    
          sort(arr.begin(), arr.end());
          unordered_map<ll, int> mp;
    
          for (auto &ele : arr) mp[ele]++;
    
          int i = 0 ;
          // cout << "here\n";
          while (i < n)
          {
                // cout << "here\n";
                int j = i + 1;
                while (j < n)
                {
                      int k = j + 1;
                      // cout << "here";
                      while (k < n)
                      {
                            mp[arr[i]]-- , mp[arr[j]]-- , mp[arr[k]]--;
                            ll val = sum - ((ll)arr[i] + (ll)arr[j] + (ll)arr[k]);
    
                            // debug(arr[i], arr[j], arr[k], val);
    
                            if (mp.count(val) and mp[val] > 0 and val >= arr[k] and val <= 1e9 and val>=-1e9)
                                  res.push_back({arr[i], arr[j], arr[k],(int) val});
    
                            mp[arr[i]]++, mp[arr[j]]++ , mp[arr[k]]++;
    
                            k++;
                            while (k < n and arr[k] == arr[k - 1]) k++;
                      }
    
    
                      j++;
                      while (j < n and arr[j] == arr[j - 1]) j++;
                }
    
                i++;
                while (i < n and arr[i] == arr[i - 1]) i++;
          }
    
          return res;
    }
};