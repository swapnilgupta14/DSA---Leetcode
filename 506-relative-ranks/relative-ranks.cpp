class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        priority_queue<pair<int, int>> pq;
        unordered_map<int, string> ranks = {
            {1, "Gold Medal"},
            {2, "Silver Medal"},
            {3, "Bronze Medal"}
        };

        for (int i = 0; i < n; ++i) {
            pq.push({score[i], i});
        }

        int rank = 1;
        while (!pq.empty()) {
            auto [sc, idx] = pq.top();
            pq.pop();
            if (rank <= 3) {
                ans[idx] = ranks[rank];
            } else {
                ans[idx] = to_string(rank);
            }
            ++rank;
        }

        return ans;
    }
};
