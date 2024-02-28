class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0) return 0;
        int len = log2(right);
        int diff = -1;
        for(int i=len; i>=0; i--){
            if((left & 1<<i) != (right & 1<<i)){
                diff = i;
                break;
            }
        }
        int ans = right;
        for(int i=0; i<=diff; i++){
            if(ans & 1<<i) ans -= 1<<i;
        }
        return ans;
    }
};