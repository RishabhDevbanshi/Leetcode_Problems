class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = size(s) - 1;
        
        while (l < r) {
            char t = s[l];
            s[l] = s[r];
            s[r] = t;
            ++l;
            --r;
        }
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);