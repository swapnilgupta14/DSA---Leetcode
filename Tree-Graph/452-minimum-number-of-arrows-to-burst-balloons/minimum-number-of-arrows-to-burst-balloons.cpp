class Solution {
public:
    static bool custom_comp(const vector<int> &a, const vector<int> &b){
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        // [[10,16],[2,8],[1,6],[7,12]]
        int count = 1;
        sort(points.begin(), points.end(), custom_comp);
        int end = points[0][1];
        //[[1,6] [2,8] [7,12] [10,16]]
        for(int i=1; i<n; i++){
            if(points[i][0] > end){
                count+=1;
                end = points[i][1];
            }else{
                end = min(end, points[i][1]);
            }
        }
        return count;
    }
};