class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        sort(properties.begin(),properties.end(),[&](auto &a,auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            else return a[0] < b[0];
        });
        
        int cnt = 0;
        int mx = properties.back()[1] , ma = properties.back()[0];
        
        // for(auto &v : properties)
            // cout<<v[0]<<" "<<v[1]<<"\n";
        // cout<<"\n";
        for(int i=size(properties)-2;i>=0;i--)
        {
            // cout<<mx<<" "<<cnt<<"\n";
            if(properties[i][0] == ma)
                mx = max(mx,properties[i][1]);
            else 
            {
                if(properties[i][1] < mx) cnt++;
                else mx = properties[i][1] , ma = properties[i][0];
            }
        }
        
        return cnt;
        
    }
};