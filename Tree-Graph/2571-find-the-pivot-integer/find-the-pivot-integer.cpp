class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) return 1;
        int pivot = n-1;
        int l = ((n-2)*(n-2+1))/2;
        int r = n;
        while(pivot >= 2){
            if(l == r) return pivot;
            l -= pivot-1;
            r = r+pivot;
            pivot--;
        }
        return -1;
    }
};