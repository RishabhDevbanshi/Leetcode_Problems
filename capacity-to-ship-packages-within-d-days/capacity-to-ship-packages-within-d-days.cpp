class Solution {
    bool canPlace(vector<int> &arr,int n,int m,int dist)
    {
        int cnt=1, sum=0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] > dist) return false;
            
            if(sum + arr[i] > dist)
            {
                sum = arr[i];
                cnt++;
                if(cnt > m) return false;
            }
            else sum += arr[i];
        }
        
        return true;
    }
public:
    int shipWithinDays(vector<int>& arr, int days) {
        int n = arr.size();
        int mn = INT_MAX, sum=0;
        for(int i=0;i<n;i++)
        {
            mn = min(mn,arr[i]);
            sum += arr[i];
        }
        
        int start = mn, end = sum,res;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(canPlace(arr,n,days,mid))
            {
                res = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        
        return res;
    }
};