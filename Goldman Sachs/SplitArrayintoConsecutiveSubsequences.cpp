// https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> u, m;
        
        for (int i : nums) 
            ++u[i];
        
        for (int i : nums) {
            
            if (u[i] == 0) 
                continue;
            
            if (m[i] > 0){
                --m[i];
                ++m[i + 1];
            } 
            
            else if (u[i+1]>0 && u[i+2]>0){
                --u[i + 1];
                --u[i + 2];
                ++m[i + 3];
            } 
            
            else 
                return false;
            
            --u[i];
        }
        return true;
    }
};
