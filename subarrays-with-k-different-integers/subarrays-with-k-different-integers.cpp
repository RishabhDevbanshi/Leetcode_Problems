class Solution {
    int countAtMostB(vector<int> &arr,int b)
    {
        if(b == 0) return 0;
        // if(b == 1) return arr.size();
        int start = 0 , end = 0, cnt = 0;
        map<int,int> mp;
        bool flag = true;
        while(start < arr.size() and end < arr.size())
        {
            if(flag) mp[arr[end]]++;
            if(mp.size() > b)
            {
                mp[arr[start]]--;
                if(mp[arr[start]] == 0) mp.erase(arr[start]);
                start++;
                flag = false;
            }
            else
            {
                flag = true;
                cnt += max(0,end - start + 1);
                end++;
            }
            // cout<<mp.size()<<" ";
        }
        // cout<<"\n";
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& A, int B) {
        int a = countAtMostB(A,B) , b = countAtMostB(A,B-1);
        // cout<<countAtMostB(A,B)<<" "<< countAtMostB(A,B-1)<<"\n";
        return a-b;
    }
};