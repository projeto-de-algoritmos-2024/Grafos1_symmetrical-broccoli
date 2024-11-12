class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        std::vector<int> painted(graph.size(), -1);
        std::queue<int> q;
        for (int i = 0; i < (int)graph.size(); i++) {
            if (painted[i] != -1)
                continue;

            painted[i] = 1;
            q.push(i);
            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (auto& v : graph[curr]) {
                    if(painted[v] == painted[curr])
                        return false;
                    
                    if(painted[v] != -1)
                        continue;

                    painted[v] = 1 - painted[curr];
                    q.push(v);
                }
            }
        }
        return true;
    }
};