// https://leetcode.com/problems/max-points-on-a-line/description/

class Solution {
private:
    int getGCD(int a, int b) {
        if (b == 0)
            return a;
        return getGCD(b, a % b);
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        if (n == 0)
            return 0;
        int res = 0;
        
        for (int i=0; i<n; ++i){
            int x1 = points[i][0], y1 = points[i][1], dup = 1, subRes = 0;
            unordered_map<double,unordered_map<double,int>> umap;
            
            for (int j = i + 1; j < n; ++j){
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                if (x1 == x2 && y1 == y2)
                    dup++;
                
                else{
                    int diffX = x2 - x1, diffY = y2 - y1, diffGCD = getGCD(diffX, diffY);
                    diffX /= diffGCD;
                    diffY /= diffGCD;
                    umap[diffX][diffY]++;
                    subRes = std::max(subRes, umap[diffX][diffY]);
                }
            }
            res = max(res, subRes + dup);
        }
        return res;
    }
};
