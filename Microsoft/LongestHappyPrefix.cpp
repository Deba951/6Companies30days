// https://leetcode.com/problems/longest-happy-prefix/description/

class Solution {
public:
    string longestPrefix(string s) {
        vector<int> v(s.size(), 0);

        int cnt = 0;

        for(int i = 1; i < s.size(); i ++){
            while(cnt && s[i] != s[cnt])
                cnt = v[cnt - 1];

            if(s[i] == s[cnt])
                v[i] = ++ cnt;
        }

        return s.substr(0, v.back());
    }
};
