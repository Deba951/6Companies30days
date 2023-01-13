// https://leetcode.com/problems/ipo/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> v; 
        for (int i=0; i<profits.size(); ++i) 
            v.emplace_back(capital[i], profits[i]); 
        
        sort(v.begin(), v.end()); 
        
        priority_queue<int> pq; 
        
        for (int i = 0; k; --k){
            for (; i < profits.size() && v[i].first <= w; ++i) 
                pq.push(v[i].second); 
            if (pq.size()){ 
                w += pq.top(); 
                pq.pop(); 
            }
        }
        return w; 
    }
};
