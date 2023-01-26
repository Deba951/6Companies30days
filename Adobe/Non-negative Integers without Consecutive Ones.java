// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/

class Solution {
    public int findIntegers(int n) {
        int[] fib = new int[32];
        fib[0] = 1;
        fib[1] = 2;
        
        for (int i=2; i<32; ++i) 
            fib[i] = fib[i-1] + fib[i-2];

        List<Integer> l = new LinkedList<>();
        while (n > 0) {
            l.add(n % 2);
            n /= 2;
        }

        int ans = 0;
        for (int i=l.size()-1; i>=0; --i) {
            ans += l.get(i) * fib[i];
            
            if (i == l.size() - 1 || l.get(i) == 0 || l.get(i+1) == 0) 
                continue;
            
            --ans;
            break;
        }
        return ans + 1;
    }
}
