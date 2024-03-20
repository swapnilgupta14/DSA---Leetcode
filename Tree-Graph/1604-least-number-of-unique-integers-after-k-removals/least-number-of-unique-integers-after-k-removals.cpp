class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // optimized using heap
        map<int, int> mp;
        for (auto& it : arr) {
            mp[it]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto& it : mp) {
            pq.push({-it.second, it.first});
        }
        while (k > 0 && !pq.empty()) {
            auto x = pq.top();
            if(abs(x.first) > 1){
                pq.pop();
                pq.push({(abs(x.first) -1) * (-1), x.second});
                k--;
            }else if(abs(x.first) == 1){
                pq.pop();
                k--;
            }
            
        }
        // while(!pq.empty()){
        //     auto x = pq.top();
        //     cout << x.first << " and" << x.second << endl;
        //     pq.pop();
        // }
        return pq.size();
    }

private:
    int findLeastNumOfUniqueInts1(vector<int>& arr, int k) {
        // O(3n) - TLE (40/43 case passed)
        map<int, int> mp;
        for (auto& i : arr) {
            mp[i]++;
        }
        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(),
             [](const auto& a, const auto& b) { return a.second < b.second; });

        int index = 0;
        while (k > 0 && index < vec.size()) {
            if (k >= vec[index].second) {
                k -= vec[index].second;
                vec.erase(vec.begin() + index);
            } else {
                vec[index].second -= k;
                k = 0;
            }
        }
        return vec.size();
    }
};