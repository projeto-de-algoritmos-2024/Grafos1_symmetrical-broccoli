typedef vector<int> vi;

class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        std::vector<int> status(n, 0);
        std::vector<int> dist(n, 0);
        std::vector<int> ans(n, 0);
        for(int i = 0; i < n ; i++) {
            if(!status[i]) {
                dfs(edges, status, dist, ans, i);
            }
        }
        return ans;
    }

private:
    void dfs(vector<int> &edges, vector<int> &status, vector<int> & dist, vector<int> & ans, int u) {
        status[u] = 1;
        int next = edges[u];
        if(status[next] == 0) {
            dist[next] = dist[u] + 1;
            dfs(edges, status, dist, ans, next);
            if(dist[next] < dist[u] + 1) {
                ans[u] = ans[next];
                dist[u] = dist[next];
            } else {
                ans[u] = ans[next] + 1;
            }
        } else if(status[next] == 1) {
            ans[u] = dist[u] - dist[next] + 1;
            dist[u] = dist[next];
        } else {
            ans[u] = ans[next] + 1;
        }
        status[u] = 2;
    }
};