class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if (n == 0) return 0;
        vector<int>v(n);
        vector<int>u(n);
        v[0] = height[0];
        for(int i=1;i<n;i++){
            v[i] = max(v[i - 1], height[i]);
        }
        u[n - 1] = height[n - 1];
        for(int i=n-2;i>=0;i--){
            u[i] = max(u[i + 1], height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(v[i],u[i])-height[i]);
        }
        return ans;
    }
};