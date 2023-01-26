// https://leetcode.com/problems/magical-string/description/

class Solution {
public:
    int magicalString(int n) {
        
        if (n == 0) 
            return 0;
        
        if (n <= 3) 
            return 1;
        
        int s[n+1], i = 2, j = 3, ans = 1, num = 1;
        s[0] = 1, s[1] = 2, s[2] = 2;
        
        while (j<n){
            
            for (int k=0; k<s[i]; ++k){
                if (num == 1 && j < n) 
                    ++ans;
                s[j++] = num;
            }

            num ^= 3;
            ++i;
        }
        
        return ans;
    }
};
