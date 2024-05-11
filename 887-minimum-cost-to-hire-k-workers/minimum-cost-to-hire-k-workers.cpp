class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double,int>> wageToQuality;
        for(int i=0;i<n;++i) {
            wageToQuality.push_back({wage[i]/(1.0*quality[i]),quality[i]});
        }
        sort(wageToQuality.begin(),wageToQuality.end());

        double ans = DBL_MAX;
        priority_queue<int> pq;
        int currSum = 0;
        for(int i=0;i<k;++i) {
            pq.push(wageToQuality[i].second);
            currSum += wageToQuality[i].second;
        }
        ans = currSum*wageToQuality[k-1].first;
        for(int i=k;i<n;++i) {
            currSum -= pq.top();
            pq.pop();
            pq.push(wageToQuality[i].second);
            currSum += wageToQuality[i].second;
            ans = min(ans,wageToQuality[i].first * currSum);
        }
        return ans;
    }
};