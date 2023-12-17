class Solution {
public:
    bool isPalindrome(int n){
        string s = to_string(n);
        int low = 0, high = s.size() - 1;
        while(low <= high){
            if(s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
    long long inc(int N){
        while(!isPalindrome(N))
            N++;
        return N;
    }
    long long dec(int N){
        while(!isPalindrome(N))
            N--;
        return N;
    }
    long long func(int N, vector<int>& nums){
        long long ans = 0;
        for(auto v : nums){
            ans += abs(N - v);
        }

        return ans;
    }
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long a = inc(nums[nums.size()/2]);
        long long b = dec(nums[nums.size()/2]);

        return min(func(a, nums), func(b, nums));
    }
};