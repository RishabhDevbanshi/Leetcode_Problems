class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> arr(size(mat));
        for(int i=0;i<size(mat);i++)
        {
            int cnt = 0;
            for(int j=0;j<size(mat[0]);j++)
            {
                if(mat[i][j])
                    cnt++;
                else
                    break;
            }
            
            arr[i] = {cnt,i};
        }
        
        sort(arr.begin(),arr.end());
        
//         for(auto &val : arr)
//         {
//             cout << val.first << " " << val.second << "\n";
//         }
        
        vector<int> res(k);
        
        for(int i=0;i<k;i++)
            res[i] = arr[i].second;
        
        return res;
    }
};