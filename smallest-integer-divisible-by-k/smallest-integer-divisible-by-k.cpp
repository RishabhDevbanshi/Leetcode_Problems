class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0 || k%5 == 0)
            return -1;
        
        // if(k%3 == 0)
        //     return k;
        // cout<<"here";
        unordered_map<int,int> mp;
        
        string str = "";
        int num = -1;
        
        while(num)
        {
            str += '1';
            if(num == -1) num = 1;
            else num += 1;
            int rem = num%k;
            if(mp.count(rem))
                return -1;
            mp[rem]++;
            num = rem*10;
            // cout<<num<<" "<<rem<<" ";
        }
        
        
        return size(str);
    }
};