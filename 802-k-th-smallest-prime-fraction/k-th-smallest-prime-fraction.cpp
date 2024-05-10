class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<float, pair<int, int>>> pq;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i != j) {
                    float x = float(arr[i]) / float(arr[j]);
                    pq.push({x * -1, {i, j}});
                }
            }
        }

        while (k > 1 && !pq.empty()) {
            pq.pop();
            k--;
        }

        auto t = pq.top();
        vector<int> ans = {arr[t.second.first], arr[t.second.second]};
        return ans;
    }
};