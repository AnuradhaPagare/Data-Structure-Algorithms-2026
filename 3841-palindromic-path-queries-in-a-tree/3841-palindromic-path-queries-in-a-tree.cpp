class Solution {
private:
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    int cur_pos;
    vector<int> bit;
    int N;

    void update_bit(int idx, int val) {
        for (; idx <= N; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    int query_bit(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum ^= bit[idx];
        }
        return sum;
    }

    int query_range(int l, int r) {
        return query_bit(r) ^ query_bit(l - 1);
    }

    int dfs(int v, int p, int d) {
        parent[v] = p;
        depth[v] = d;
        int size = 1;
        int max_c_size = 0;
        for (int c : adj[v]) {
            if (c != p) {
                int c_size = dfs(c, v, d + 1);
                size += c_size;
                if (c_size > max_c_size) {
                    max_c_size = c_size;
                    heavy[v] = c;
                }
            }
        }
        return size;
    }

    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = ++cur_pos;
        if (heavy[v] != -1) {
            decompose(heavy[v], h);
        }
        for (int c : adj[v]) {
            if (c != parent[v] && c != heavy[v]) {
                decompose(c, c);
            }
        }
    }

    int query_path(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            res ^= query_range(pos[head[v]], pos[v]);
            v = parent[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        res ^= query_range(pos[u], pos[v]);
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent.assign(n, 0);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        cur_pos = 0;

        dfs(0, -1, 0);
        decompose(0, 0);

        N = n;
        bit.assign(n + 1, 0);
        
        vector<int> current_mask(n, 0);
        for (int i = 0; i < n; ++i) {
            current_mask[i] = 1 << (s[i] - 'a');
            update_bit(pos[i], current_mask[i]);
        }

        vector<bool> ans;

        for (const string& q : queries) {
            if (q[0] == 'u') {
                int u;
                char c;
                sscanf(q.c_str(), "update %d %c", &u, &c);
                int new_mask = 1 << (c - 'a');
                update_bit(pos[u], current_mask[u] ^ new_mask);
                current_mask[u] = new_mask;
            } else {
                int u, v;
                sscanf(q.c_str(), "query %d %d", &u, &v);
                int path_mask = query_path(u, v);
                bool is_palindrome = (path_mask & (path_mask - 1)) == 0;
                ans.push_back(is_palindrome);
            }
        }

        return ans;
    }
};
