class Solution {
public:
    int n;
    vector<int> t; // Use a vector for memoization

    int getNextIndex(vector<vector<int>>& array, int currentJobEnd) {
        int l = 0, r = n - 1;
        int result = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (array[mid][0] >= currentJobEnd) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    int solve(int curr, vector<vector<int>>& array) {
        if (curr >= n)
            return 0;
        if (t[curr] != -1)
            return t[curr];

        int take = 0;
        int skip;
        int next = getNextIndex(array, array[curr][1]);

        take = array[curr][2] + solve(next, array);
        skip = solve(curr + 1, array);

        return t[curr] = max(take, skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        t.resize(n, -1); // Initialize memoization array with -1

        vector<vector<int>> array(n, vector<int>(3, 0));

        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }

        // Sort the jobs based on their end times
        sort(array.begin(), array.end());
        return solve(0, array);
    }
};