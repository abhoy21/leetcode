class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int prev = points[0][1];
        int cnt = 1;
        
        for(auto p: points){
            if(prev < p[0]){
                cnt++;
                prev = p[1];
            }
            prev = min(prev, p[1]);
        }

        return cnt;
    }
};