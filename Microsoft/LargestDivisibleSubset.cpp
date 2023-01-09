// https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        
        if(nums.size()==0)
            return ans;
        
        sort(nums.begin(),nums.end());
        int max = 1;
        
        vector<int> dp(nums.size()+1,1);
        
        for(int i=1;i<nums.size();++i){
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                    if(max<dp[i])
                        max = dp[i];
                }
            }
        }
        
        int prev = -1;
        for(int i=nums.size()-1;i>=0;i--){
            if(dp[i]==max &&  (prev%nums[i]==0 || prev==-1)){
                ans.push_back(nums[i]);
                max -=1;
                prev = nums[i];
            }
        }
        return ans;
    }
};
