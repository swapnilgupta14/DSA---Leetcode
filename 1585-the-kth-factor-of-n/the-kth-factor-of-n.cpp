class Solution {
public:
    int kthFactor(int n, int k) {
        if(n == 0) return 0;
        vector<int> factorList = factor(n);
        if(k > factorList.size()) return -1;
        return factorList[k-1];
        
    }

    vector<int> factor(int n){
        vector<int> res;
        for(int i = 1; i<n/2+1 ; i++)
            if(n%i == 0)
                res.push_back(i);
        res.push_back(n);
        return res;
    }
};