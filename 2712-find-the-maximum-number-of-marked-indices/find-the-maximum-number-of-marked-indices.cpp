class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int i=0, j=n/2;
        while(i<n/2 && j<n){
            if(2*nums[i]<=nums[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i * 2;
    }
private:
    int maxNumOfMarkedIndicesf(vector<int>& nums) {
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