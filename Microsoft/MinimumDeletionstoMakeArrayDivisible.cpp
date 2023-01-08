// https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd = sol(numsDivide);

    sort(nums.begin(), nums.end());

    for (int i=0; i<nums.size(); ++i){
      if (gcd % nums[i] == 0)
        return i;
    }

    return -1;
  }

 private:
  int sol(vector<int>& nums) {
    int hcf = nums[0];
    for (int i: nums)
      hcf = gcd(hcf, i);
    return hcf;
  }
};
