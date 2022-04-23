class Solution { 
    string link = "tiny/url/";
    int num = 0;
    unordered_map<string,string> mp;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string sh = link + to_string(num);
        num++;
        mp[sh] = longUrl;
        return sh;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));