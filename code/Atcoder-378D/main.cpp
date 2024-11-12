#include <bits/stdc++.h>

#define int long long

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tuple<int,int,int> tp;
typedef vector<tp> vtp;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int MAX = 1e8 + 5;
const int NONE = 0;


void solve(){
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> grid(h);
    for (int i = 0; i < h; ++i) cin >> grid[i];
    int ans = 0;

    function<bool(int, int)> is_valid = [&](int r, int c) {
        return 0 <= r && r < h && 0 <= c && c < w && grid[r][c] == '.';
    };

    function<void(int, int, int, set<pii>)> dfs = 
        [&](int r, int c, int steps, set<pii> visited) {
        if (steps == k) {
            ans++;
            return;
        }

        visited.insert({r, c});

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (is_valid(nr, nc) && visited.find({nr, nc}) == visited.end()) {
                dfs(nr, nc, steps + 1, set<pii>(visited)); 
            }
        }
    };

    for (int r = 0; r < h; ++r) {
        for (int c = 0; c < w; ++c) {
            if (grid[r][c] == '.') {
                dfs(r, c, 0, set<pii>());
            }
        }
    }

    cout << ans << endl;
}

signed main(){
    fastInp;
 
    int t = 1;
    //cin >> t;

    while(t--){
	    solve();
    }
}