#define ll long long
class Solution {
    vector<ll> sieve(int n) 
    {
        int*arr = new int[n + 1](); 
        vector<ll> vect; 
        for (int i = 2; i < n; i++)
        {
            if (arr[i] == 0)
            {
                vect.push_back(i); 
                for (int j = 2 * i; j < n; j += i)
                arr[j] = 1;
            } 
        }
        return vect;
    }

public:
    int countPrimes(int n) {
        vector<bool> v (n+1, true);
        v[0] = v[1] =  false;
        int cnt = 0;
        for (long long int i = 2; i < n; i++){
            if (v[i]){
                cnt++;
                for (long long int j = i*i; j < n; j+=i )
                    v[j] = false;
            }
        }
        return cnt;  
    }
};