// https://leetcode.com/problems/valid-square/description/

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int, int> um;
        vector<vector<int>> v{p1, p2, p3, p4};
        
        for (int i=0; i<4; ++i) {
            for (int j=i+1; j<4; ++j) {
                int x1 = v[i][0], y1 = v[i][1], x2 = v[j][0], y2 = v[j][1];
                int d = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
                if (d == 0) return false;
                ++um[d];
            }
        }
        
        return um.size() == 2;
    }
};
