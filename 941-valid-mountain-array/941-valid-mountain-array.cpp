class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(size(arr) < 3 || arr[1] < arr[0])
            return false;
        
        int peak = -1;
        
        for(int i=1;i<size(arr);i++)
        {
            if(arr[i] == arr[i-1])
                return false;
            if(arr[i] < arr[i-1])
            {
                peak = i-1;
                break;
            }
        }
        
        // cout<<peak<<"\n";
        
        if(peak == -1 || peak == size(arr)-1)
            return false;
        
        for(int i=peak+1;i<size(arr)-1;i++)
        {
            if(arr[i] < arr[i+1] || arr[i] == arr[i+1])
                return false;
        }
        
        return true;
    }
};