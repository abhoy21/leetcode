class Solution {
public:
    std::vector<int> v;
    Solution(std::vector<int>& w) {
        v.push_back(w[0]);
        for(int i = 1; i < w.size(); i++) { // Changed the loop starting index to 1
            v.push_back(v.back() + w[i]);
        }
    }
    
    int pickIndex() {
        int totalSum = v.back();
        int key = rand() % totalSum;
        int low = 0, high = v.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (key < v[mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */