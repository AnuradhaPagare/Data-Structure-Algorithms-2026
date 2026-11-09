class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> requestCount(k, 0);
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        
        int n = arrival.size();
        for (int i = 0; i < n; ++i) {
            int currTime = arrival[i];
            
            while (!busy.empty() && busy.top().first <= currTime) {
                available.insert(busy.top().second);
                busy.pop();
            }
            
            if (available.empty()) {
                continue;
            }
            
            int targetServer = i % k;
            auto it = available.lower_bound(targetServer);
            
            if (it == available.end()) {
                it = available.begin();
            }
            
            int assignedServer = *it;
            requestCount[assignedServer]++;
            busy.push({currTime + load[i], assignedServer});
            available.erase(it);
        }
        
        int maxRequests = *max_element(requestCount.begin(), requestCount.end());
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (requestCount[i] == maxRequests) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
