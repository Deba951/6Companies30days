// https://leetcode.com/problems/number-of-boomerangs/description/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        
        for (int i=0; i<points.size(); ++i){
            map<int, int> m;
            for (int j=0; j<points.size(); ++j){
                if (i==j) 
                    continue;
                ++m[solve(points[i], points[j])];
            }
            
            for (auto it=m.begin(); it!=m.end(); ++it)
                ans += (it -> second) * (it ->second - 1);
        }
        return ans;
    }

private:
    int solve(vector<int>& p1, vector<int>& p2){
        return (p1[0]-p2[0]) * (p1[0]-p2[0]) + (p1[1]-p2[1]) * (p1[1]-p2[1]);
    }
};
