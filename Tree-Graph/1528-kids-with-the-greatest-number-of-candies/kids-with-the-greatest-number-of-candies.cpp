class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size(), false);
        int m = *max_element(candies.begin(), candies.end());
        for(int i=0 ;i <candies.size(); i++){
            if (candies[i] + extraCandies >= m) result[i] = true;
        }
        return result;
    }
};