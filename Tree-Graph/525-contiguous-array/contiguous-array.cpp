class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        unordered_map<int, int> sumMap;
        int maxLength = 0;
        int sum = 0;
        sumMap[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 1) ? 1 : -1;
            if (sumMap.find(sum) != sumMap.end()) {
                maxLength = max(maxLength, i - sumMap[sum]);
            } else {
                sumMap[sum] = i;
            }
        }
        return maxLength;
    }
private:
    int findMaxLength1(vector<int>& nums) {
        // Brute Force - Time Limit Exceeded
        int max_length = 0;
        if(nums.size() == 2){
            if((nums[0] + nums[1]) == 2) return 0;
            if((nums[0] + nums[1]) == 1) return 2;
            else return 0; 
        }
        for(int i=0; i<nums.size()-1; i++){
            int zeroes = 0;
            int ones = 0;
            nums[i] == 0 ? zeroes++ : ones++ ;
            for(int j=i+1; j<nums.size(); j++){
                nums[j] == 0 ? zeroes++ : ones++;
                if(zeroes == ones){
                    if(j-i+1  > max_length) max_length = j-i+1;
                }
            }
        }
        return max_length;
    }
};