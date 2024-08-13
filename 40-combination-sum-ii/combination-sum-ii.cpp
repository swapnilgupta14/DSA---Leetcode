class Solution {
public:

    vector<vector<int>> res;
    int n;
    void compute(int idx,vector<int>& candidates, int target,vector<int> temp){
        if(target==0){
            res.push_back(temp);
            return;
        }

        if(target<0 || idx==n){
            return;
        }

        temp.push_back(candidates[idx]);
        compute(idx+1,candidates,target-candidates[idx],temp);
        temp.pop_back();
        while((idx+1)<n && candidates[idx]==candidates[idx+1]) idx++;
        compute(idx+1,candidates,target,temp);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        n = candidates.size();
        vector <int> temp;
        compute(0,candidates,target,temp);
        return res;
    }
};