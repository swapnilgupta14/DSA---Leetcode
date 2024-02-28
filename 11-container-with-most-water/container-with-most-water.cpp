class Solution {
public:
    int maxArea(vector<int>& height) {
        //  height = [1,8,6,2,5,4,8,3,7]
        long int x = 0;
        long int y = height.size()-1;
        
        long int mArea = 0;
        while(x<y){
            long int dis = abs(y-x);
            long int newArea = dis * min(height[x], height[y]);
            if(newArea > mArea) mArea = newArea;
            if(height[x] <= height[y]){
                x++;
            }else{
                y--;
            }

        }
        return mArea;
    }
};