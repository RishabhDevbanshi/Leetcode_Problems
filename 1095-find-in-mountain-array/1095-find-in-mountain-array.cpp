/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int start = 0 , end = n-1;
        int peak , peakVal;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            int val = mountainArr.get(mid);
            int prev= mid-1>=0 ? mountainArr.get(mid-1) : INT_MAX;
            int next = mid+1<n ? mountainArr.get(mid+1) : INT_MAX;
            
            if(val > prev and val > next)
            {
                peak = mid;
                peakVal = val;
                break;
            }
            else if(mid == 0)
                start += 1;
            else if(mid == n-1)
                end -= 1;
            else if(val < prev)
                end = mid-1;
            else start = mid+1;
        }
        
        // cout<<peak<<" "<<peakVal<<"\n";
        
        int startVal = mountainArr.get(0) , endVal = mountainArr.get(n-1);
        
        if(target > peakVal)
            return -1;
        
        if(target == peakVal)
            return peak;
        
        // cout<<peak<<" "<<peakVal<<"\n";
        
        if(target >= startVal and target <= peakVal)
        {
            int start = 0 , end = peak-1;
            while(start <= end)
            {
                int mid = start + (end-start)/2;
                int val = mountainArr.get(mid);
                // cout<<start<<" "<<end<<" "<<val<<"\n";
                
                if(val == target) return mid;
                else if(val < target) start = mid+1;
                else end = mid-1;
            }
        }
        
        // cout<<endVal<<"\n";
        
        if(target >= endVal and target <= peakVal)
        {
            // cout<<"here\n";
            int start = peak+1 , end = n-1;
            while(start <= end)
            {
                int mid = start + (end-start)/2;
                int val = mountainArr.get(mid);
                if(val == target) return mid;
                else if(val < target) end = mid-1;
                else start = mid+1;
            }
        }
        
        return -1;
    }
};