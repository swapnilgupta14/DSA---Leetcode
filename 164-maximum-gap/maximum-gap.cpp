#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumGap(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        
        int bucket_size = max(1, ((max_val - min_val) / static_cast<int>(nums.size() - 1)));
        int num_buckets = (max_val - min_val) / bucket_size + 1;
        
        
        vector<pair<int, int>> buckets(num_buckets, {-1, -1});
        
        for (int num : nums) {
            int bucket_index = (num - min_val) / bucket_size;
            if (buckets[bucket_index].first == -1) {
                buckets[bucket_index] = {num, num};
            } else {
                buckets[bucket_index].first = min(buckets[bucket_index].first, num);
                buckets[bucket_index].second = max(buckets[bucket_index].second, num);
            }
        }
        
        int max_gap = 0;
        int prev_max = min_val;
        for (auto& bucket : buckets) {
            if (bucket.first != -1) {
                max_gap = max(max_gap, bucket.first - prev_max);
                prev_max = bucket.second;
            }
        }
        
        return max_gap;
    }
};
