class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xdif = abs(sx - fx);
        int ydif = abs(sy - fy);

        if(xdif == 0 && ydif == 0)
            return t != 1;
        
        return xdif <= t && ydif <= t;
    }
};