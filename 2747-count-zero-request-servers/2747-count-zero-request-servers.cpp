class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int qSize = queries.size();
        vector<pair<int, int>> sortedQueries(qSize);
        for (int i = 0; i < qSize; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(qSize);
        vector<int> serverCounts(n + 1, 0);
        int activeServers = 0;

        int left = 0;
        int right = 0;
        int numLogs = logs.size();

        for (const auto& [q, idx] : sortedQueries) {
            int start = q - x;
            int end = q;

            while (right < numLogs && logs[right][1] <= end) {
                int serverId = logs[right][0];
                if (serverCounts[serverId] == 0) {
                    activeServers++;
                }
                serverCounts[serverId]++;
                right++;
            }

            while (left < numLogs && logs[left][1] < start) {
                int serverId = logs[left][0];
                serverCounts[serverId]--;
                if (serverCounts[serverId] == 0) {
                    activeServers--;
                }
                left++;
            }

            ans[idx] = n - activeServers;
        }

        return ans;
    }
};
