class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // brute 38/total - TLE
        
        // vector<int> ans;
        // int n = nums.size();
        // int i = 0;
        // vector<int> vec;
        // while(i < n-k+1){
        //     int m = INT_MIN;
        //     for(int j=i ; j<i+k ; j++){
        //         if(nums[j] > m) m = nums[j];
        //     }
        //     vec.push_back(m);
        //     i++;
        // }
        // return vec;

        // optimized approach
        vector<int> ans;
        int i=0;
        int j=0;
        priority_queue<pair<int,int>> pq;
            while(j<nums.size()){
                pq.push({nums[j],j});
                if(j-i+1 ==k){
                while(pq.top().second <i){
                    pq.pop();
                }
                if(pq.top().second >=i){
                    ans.push_back(pq.top().first);
                }
                    i++;
                }
                j++;
            }
            return ans;
    }
};