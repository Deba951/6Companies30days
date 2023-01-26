// https://leetcode.com/problems/number-of-matching-subsequences/description/

class Solution {
public:
    int numMatchingSubseq(const string& s, vector<string>& words) {
        
        vector<vector<int>> v(128);    
        
        for (int i=0; i<s.length(); ++i)
            v[s[i]].push_back(i);
        
        int ans = 0;
        
        for (const string& word : words)
            ans += isMatch(word, v);
        return ans;
    }
  
    private:
    unordered_map<string, bool> m_;
    bool isMatch(const string& word, const vector<vector<int>>& v) {
        
        if (m_.count(word)) return m_[word];       
            int cnt = -1;
        
        for (const char c : word){
            const vector<int>& p = v[c];
            const auto it = std::lower_bound(p.begin(), p.end(), cnt+1);      
            
            if (it == p.end()) 
                return m_[word] = false;

            cnt = *it;      
        }
        
        return m_[word] = true;
    }
};
