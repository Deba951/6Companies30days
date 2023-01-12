// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        unordered_map<int, int> um;
        int ans = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            if (um.count(cards[i]))
                ans = min(ans, i - um[cards[i]] + 1);
            um[cards[i]] = i;
        }
    if(ans == INT_MAX) 
        return -1;
    else
        return ans;
    }
};
