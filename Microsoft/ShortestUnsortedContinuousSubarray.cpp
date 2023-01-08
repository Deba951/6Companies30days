// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int sol=0, cnt=-1, n=nums.size();
        
        for (int i=1; i<n; ++i){
            
            if (nums[i]<nums[i-1]){
                int j = i;
                
                while (j>0 && nums[j]<nums[j-1]){
                    swap(nums[j], nums[j-1]);
                    --j;
                }

                if (cnt==-1 || cnt>j) 
                    cnt = j;

                sol = i-cnt+1;
            }
        }
        return sol;
    }
};
