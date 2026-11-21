class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> lastSeen(26, -1);

        auto dfsFindParent = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            if (lastSeen[c] != -1) {
                newParent[u] = lastSeen[c];
            }

            int prev = lastSeen[c];
            lastSeen[c] = u;

            for (int v : adj[u]) {
                self(self, v);
            }

            lastSeen[c] = prev;
        };

        dfsFindParent(dfsFindParent, 0);

        vector<vector<int>> newAdj(n);
        for (int i = 1; i < n; ++i) {
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        auto dfsSubtreeSize = [&](auto& self, int u) -> int {
            for (int v : newAdj[u]) {
                ans[u] += self(self, v);
            }
            return ans[u];
        };

        dfsSubtreeSize(dfsSubtreeSize, 0);
        return ans;
    }
};
