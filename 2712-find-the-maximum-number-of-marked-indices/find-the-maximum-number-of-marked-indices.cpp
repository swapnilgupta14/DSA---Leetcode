class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int temp=0;
        int n=nums.size();
        int i=(n-1)/2;

        multiset<int> st (nums.begin(),nums.end());

        while(i>=0 && st.size()>1){
            int val=nums[i];
            if( st.lower_bound(val*2) !=st.end()){
                temp+=2;
                st.erase(st.lower_bound(val*2));
                auto x = st.find(val);
                st.erase(x);
            }
            i--;
        }
        return temp;

        
    }
};