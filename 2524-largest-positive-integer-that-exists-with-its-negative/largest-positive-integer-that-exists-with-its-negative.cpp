class Solution {
public:
    int findMaxK(vector<int>& nums) {
        priority_queue<int> pq1;
        priority_queue<int> pq2;
        for(auto it: nums){
            if(it < 0) pq2.push(-1 * it);
            else pq1.push(it);
        }
        while(!pq1.empty() && !pq2.empty()){
            // if(pq1.top() != (pq2.top())) pq1.pop();
            if(pq1.top() > (pq2.top())) pq1.pop();
            if(pq1.top() < (pq2.top())) pq2.pop();
            else if(pq1.top() == (pq2.top())) return pq1.top();

        }
        return -1;
    }
};