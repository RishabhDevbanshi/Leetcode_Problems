
    // unordered_map<vector<int>,int> mp;
class DetectSquares {
    
    int mp[1001][1001] = {};
    vector<vector<int>> arr;
public:
    DetectSquares() {
        // mp.clear();
        // memset(mp,0,sizeof(mp));
        // arr.clear();
    }
    
    void add(vector<int> point) {
        mp[point[0]][point[1]]++;
        arr.emplace_back(point);
    }
    
    int count(vector<int> point) {
        int cnt = 0;
        for(auto p : arr)
        {
            // vector<int> p = it.first;
            if(p[0] == point[0] || p[1] == point[1]) continue;
            else if(abs(p[0] - point[0]) == abs(p[1] - point[1]))
            {
                cnt += mp[p[0]][point[1]] * mp[point[0]][p[1]];
            }
        }
        return cnt;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */