// https://leetcode.com/problems/fraction-to-recurring-decimal/description/

class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        StringBuilder ans = new StringBuilder();
        if (numerator < 0 ^ denominator < 0)
            ans.append("-");
        long num = Math.abs((long)numerator);
        long den = Math.abs((long)denominator);
        long quotient = num / den;
        long remainder = (num % den) * 10;
        ans.append(quotient);
        if (remainder == 0)
            return ans.toString();
        else {
            ans.append(".");
            Map<Long, Integer> previousRemainders = new HashMap<>();
            while (remainder != 0) {
                if (previousRemainders.containsKey(remainder)) {
                    int pos = previousRemainders.get(remainder);
                    ans.insert(pos, "(");
                    ans.append(")");
                    return ans.toString();
                }
                previousRemainders.put(remainder, ans.length());
                quotient = Math.abs(remainder / denominator);
                remainder = (remainder % denominator) * 10;
                ans.append(quotient);
            }
        }
        return ans.toString();
    }
}
