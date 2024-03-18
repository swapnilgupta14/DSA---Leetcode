#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool compareIntervals(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(), compareIntervals);

        int count = 1; 
        int end = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > end) { 
                count++;
                end = points[i][1];
            } else { 
                end = min(end, points[i][1]);
            }
        }

        return count;
    }
};
