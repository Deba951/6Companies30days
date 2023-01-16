// https://leetcode.com/problems/count-nice-pairs-in-an-array/

class Solution {
public:
    int countNicePairs(vector<int>& nums){
        constexpr int mod = 1'000'000'007;
        long ans = 0;
        unordered_map<int, long> count;

        for (const int i : nums)
        ++count[i - rev(i)];

        for (const auto& [_, freq] : count){
        ans += freq * (freq - 1) / 2;
        ans %= mod;
        }
        return ans;
    }

private:
    int rev(int n){
        int ans = 0;

        while (n){
            ans = ans * 10 + (n % 10);
            n /= 10;
        }
        return ans;
    }
};
