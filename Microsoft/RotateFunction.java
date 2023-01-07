// https://leetcode.com/problems/rotate-function/description/

class Solution {
    public int maxRotateFunction(int[] nums) {
        int sum=0, cnt=0, n=nums.length;
        
        for (int i=0; i<n; i++) {
            sum += nums[i];
            cnt += i * nums[i];
        }

        int max = cnt;
        
        for (int i=n-1; i>0; i--) {
            cnt = cnt + sum - n * nums[i];
            max = Math.max(max, cnt);
        }       
        return max;
    }
}
