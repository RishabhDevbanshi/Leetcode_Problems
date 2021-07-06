class Solution {
    bool canPlace(vector<int> &arr,int n,int m,int dist)
    {
        int cnt=1 , prev=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i] - prev >= dist)
            {
                cnt++;
                prev = arr[i];
            }
            
            if(cnt == m) return true;
        }
        
        return false;
    }
public:
    int maxDistance(vector<int>& arr, int m) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int start = 1, end = arr[n-1] - arr[0],res;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(canPlace(arr,n,m,mid))
            {
                res = mid;
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        
        return res;
    }
};