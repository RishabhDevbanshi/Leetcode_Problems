class Solution {
    string arr[14] = {"1","22","122","333","1333","22333","122333","4444","14444","224444","1224444","55555","155555","666666"};
    vector<string> perm;
    void permute(string a, int l, int r)
    {
        // Base case
        if (l == r)
            perm.push_back(a);
        else
        {
            // Permutations made
            for (int i = l; i <= r; i++)
            {

                // Swapping done
                swap(a[l], a[i]);

                // Recursion called
                permute(a, l+1, r);

                //backtrack
                swap(a[l], a[i]);
            }
        }
    }
public:
    int nextBeautifulNumber(int n) {
        sort(arr,arr+14,[](string &a,string &b){
            if(a.size() != b.size()) return a.size() < b.size();
            return a < b;
            });
        // for(int i=0;i<14;i++) cout<<arr[i]<<" ";
        cout<<endl;
        string str = to_string(n);
        perm.clear();
        vector<string> brr;
        string res = "-1";
        string emer = "-1";
        for(auto &ch : arr)
        {
            if(ch.size() == str.size()) brr.push_back(ch);
            else if(ch.size() == str.size()+1)
            {
                emer = ch;
                break;
            }
        }
        
        
        for(auto &ele : brr)
        {
            // cout<<ele<<" ";
            perm.clear();
            permute(ele,0,ele.size()-1);
            string sr = str;
            sort(perm.begin(),perm.end(),[](string &a,string &b){
                return a<b;
            });
            for(auto &p : perm)
            {
                if(p>str)
                {
                    if(res == "-1") res = p;
                    else if(p < res) res = p;
                }
            }
        }
        if(res != "-1") return stoi(res);
        return stoi(emer);
        
    }
};