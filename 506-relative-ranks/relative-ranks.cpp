class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; ++i) {
            pq.push({score[i], i});
        }

        int rank = 1;
        while (!pq.empty()) {
            auto [sc, idx] = pq.top();
            pq.pop();
            switch(rank){
                case 1:
                    ans[idx] = "Gold Medal";
                    break;
                case 2:
                    ans[idx] = "Silver Medal";
                    break;
                case 3:
                    ans[idx] = "Bronze Medal";
                    break;
                default:
                    ans[idx] = to_string(rank);
            }
            rank++;
        }

        return ans;
    }
};
