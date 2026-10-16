class Solution {
    long long MOD = 1e9 + 7;
    vector<long long> tree1, tree2, lazy;

    void pushDown(int node, int start, int end) {
        if (lazy[node] == 0) return;
        
        long long val = lazy[node];
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node;
        int rightChild = 2 * node + 1;
        long long lenLeft = mid - start + 1;
        long long lenRight = end - mid;

        tree2[leftChild] = (tree2[leftChild] + 2 * val * tree1[leftChild] % MOD + lenLeft * val % MOD * val % MOD) % MOD;
        tree1[leftChild] = (tree1[leftChild] + lenLeft * val) % MOD;
        lazy[leftChild] = (lazy[leftChild] + val) % MOD;

        tree2[rightChild] = (tree2[rightChild] + 2 * val * tree1[rightChild] % MOD + lenRight * val % MOD * val % MOD) % MOD;
        tree1[rightChild] = (tree1[rightChild] + lenRight * val) % MOD;
        lazy[rightChild] = (lazy[rightChild] + val) % MOD;

        lazy[node] = 0;
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return;
        
        if (l <= start && end <= r) {
            long long len = end - start + 1;
            tree2[node] = (tree2[node] + 2 * val * tree1[node] % MOD + len * val % MOD * val % MOD) % MOD;
            tree1[node] = (tree1[node] + len * val) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
            return;
        }

        pushDown(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);

        tree1[node] = (tree1[2 * node] + tree1[2 * node + 1]) % MOD;
        tree2[node] = (tree2[2 * node] + tree2[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree1.assign(4 * n, 0);
        tree2.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> lastPos;
        long long totalSumSquares = 0;

        for (int j = 0; j < n; ++j) {
            int k = lastPos.count(nums[j]) ? lastPos[nums[j]] : -1;
            
            update(1, 0, n - 1, k + 1, j, 1);
            totalSumSquares = (totalSumSquares + tree2[1]) % MOD;
            lastPos[nums[j]] = j;
        }

        return totalSumSquares;
    }
};
