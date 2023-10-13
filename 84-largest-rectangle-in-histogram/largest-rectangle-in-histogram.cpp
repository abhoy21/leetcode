class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        vector<int> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int temp = height[i] * (right[i] - left[i] + 1);
            ans = max(ans, temp);
        }

        return ans;
    }
};