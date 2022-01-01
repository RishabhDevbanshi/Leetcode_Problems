class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1) return "";
        int n = __gcd(size(str1),size(str2));
        return str2.substr(0,n);
    }
};