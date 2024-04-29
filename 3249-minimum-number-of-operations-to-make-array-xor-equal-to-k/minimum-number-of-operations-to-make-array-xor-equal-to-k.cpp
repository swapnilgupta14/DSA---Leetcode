class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int op=0, xp=0; 
        for(int x:nums) {
            xp^=x;
        }
        for(int i=0; i<=31; i++)
        {
            int b1 = (k>>i) & 1;
            int b2 = (xp>>i) & 1;
            if(b1!=b2) op++;
        }
        return op;
    }
};