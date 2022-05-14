class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int start = 0 , end = n-1;
        while(start <= end)
        {
            // cout<<start<<" "<<end<<"\n";
            int mid = start + (end - start)/2;
            // cout<<INT_MIN<<"\n";
            long long prev = (mid-1 == -1) ? -2147483649 : arr[mid-1];
            long long next = (mid+1 == n) ? -2147483649 : arr[mid+1];
            if(arr[mid] > prev and arr[mid] > next) return mid;
            else if(prev > arr[mid]) end = mid-1;
            else start = mid+1;
        }

        return -1;
    }
};