class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> arr = {
                1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 23,
                34, 45, 56, 67, 78, 89, 123, 234, 345,
                456, 567, 678, 789, 1234, 2345, 3456, 4567,
                5678, 6789, 12345, 23456, 34567, 45678, 56789,
                123456, 234567, 345678, 456789, 1234567, 2345678,
                3456789, 12345678, 23456789, 123456789,
          };
        
        // sort(arr.begin(),arr.end());
        // for(auto &val : arr) cout<<val<<",";
        
        int lidx = lower_bound(arr.begin(),arr.end(),low) - arr.begin();
        int uidx = lower_bound(arr.begin(),arr.end(),high) - arr.begin();
        
        uidx = uidx >= size(arr) ? size(arr)-1 : uidx;
        
        if(arr[uidx] > high) uidx--;
        
        vector<int> res;
        
        for(int i=lidx;i<=uidx;i++)
        {
            res.push_back(arr[i]);
        }
        
        
        return res;
    }
};