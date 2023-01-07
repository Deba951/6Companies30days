// https://leetcode.com/problems/combination-sum-iii/description/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n){
        vector<vector<int>> v;
        
        for (int i = 0; i < (1 << 9); ++i){
            vector<int> cv;
            int sum = 0;
            
            for (int j = 1; j <= 9; ++j){
                if (i & (1 << (j-1))){
                    sum += j;
                    cv.push_back(j);
                }
            }
            
            if (sum == n && cv.size() == k) 
                v.push_back(cv);
        }
        return v; 
    }       
};
