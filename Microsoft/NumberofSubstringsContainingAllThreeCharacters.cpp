// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int lp=0, rp=0; // left and right pointer

        vector <int> v(3,0);
        int sol=0;

        for(int rp=0; rp<s.length(); rp++){
            v[s[rp]-'a']++;
            
            while(v[0]>0 && v[1]>0 && v[2]>0 && lp<=rp){
                v[s[lp]-'a']--;
                sol+=(s.length()-rp);
                lp++;
            }
        }
        return sol;
    }
};
