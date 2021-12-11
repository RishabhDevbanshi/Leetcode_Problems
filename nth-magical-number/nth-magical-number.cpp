class Solution {
    typedef long long ll;
    const ll mod = 1e9 + 7;
public:
    int nthMagicalNumber(int n, int a, int b) {
        ll lcm = (a*b)/__gcd(a,b);
        vector<ll> numbers;
        ll temp = a;
        while(temp != lcm)
        {
            numbers.push_back(temp);
            temp += a;
        }
        
        temp = b;
        
        while(temp != lcm)
        {
            numbers.push_back(temp);
            temp += b;
        }
        
        numbers.push_back(lcm);
        sort(numbers.begin(),numbers.end());
        n--;
        ll times = n/(size(numbers));
        // cout<<times<<"\n";
        for(auto &val : numbers) val += times * lcm;
        
        // for(auto &val : numbers) cout<<val<<" ";
        
        ll idx = n;
        idx %= size(numbers);
        
        return numbers[idx]%mod;
    }
};