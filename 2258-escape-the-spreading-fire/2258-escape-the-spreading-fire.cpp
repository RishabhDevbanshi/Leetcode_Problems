class Solution {
public:
    int maximumMinutes(vector<vector<int>>& a) {
    	typedef long long ll;
        ll n = size(a), m = a[0].size();
        const ll inf = 2e9 + 7;
        const ll hor[] = {-1, 0, 1, 0};
        const ll col[] = {0, -1, 0, 1};
        bool xx = true;
        vector<vector<ll>> aag;
        vector<vector<ll>> dis;
        ll mid = inf;
        auto e = [&] (ll r, ll c) {
            return 0 <= r && r < n && 0 <= c && c < m && a[r][c] == 0 && (xx || aag[r][c] > mid + dis[r][c] - (r == n - 1 && c == m - 1 ? 1 : 0));
        };
        auto recur = [&] (const vector<pair<ll, ll>> &source, vector<vector<ll>> &d) {
            d.assign(n, vector<ll>(m, inf));
            queue<pair<ll, ll>> q;
            for (auto &[r, c] : source) {
                q.emplace(r, c);
                d[r][c] = 0;    
            }
            while(!q.empty()) {
                auto [r, c] = q.front();
                q.pop();   
                for(ll dir = 0; dir < 4; dir++) {
                    ll nr = r + hor[dir], nc = c  + col[dir];
                    if(e(nr, nc) && d[r][c] + 1 < d[nr][nc]) {
                        q.emplace(nr, nc);
                        d[nr][nc] = d[r][c] + 1;
                    }
                }    
            }
        };
        vector<pair<ll, ll>> src;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    src.emplace_back(i, j);
                }
            }
        }
        recur(src, aag);
        src = {{0, 0}};
        recur(src, dis);

        ll lo = 0, hi = 1e9;
        ll ans = -1;
        while (lo <= hi) {
            xx = false;
            mid = (lo + hi) / 2;
            vector<vector<ll>> can;
            recur(src, can);
            if (can[n - 1][m - 1] < inf) {
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};