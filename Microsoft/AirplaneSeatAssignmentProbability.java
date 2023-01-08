// https://leetcode.com/problems/airplane-seat-assignment-probability/description/

class Solution {
    public double nthPersonGetsNthSeat(int n) {
        if(n==1) 
            return 1.00000;

        double[] seats = new double[n];
        double sum = 0;
        
        for (int i=1; i<n; i++) {
            seats[i] = (1+sum)/(i+1);
            sum += seats[i];
        }
        return seats[n - 1];
    }
}
