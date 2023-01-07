// https://leetcode.com/problems/bulls-and-cows/description/

class Solution {
    public String getHint(String secret, String guess) {
        int[] a = new int[10];
        int p=0, q=0;

        char[] s = secret.toCharArray();
        char[] g = guess.toCharArray();
        
        for(int i=0; i<s.length; i++){
            if(s[i] == g[i]) 
                p++;
            
            else{
                if(a[g[i] - '0']-- > 0) 
                    q++;
                if(a[s[i] - '0']++ < 0) 
                    q++;
            }
        }
    return p + "A" + q + "B";
    }
}
