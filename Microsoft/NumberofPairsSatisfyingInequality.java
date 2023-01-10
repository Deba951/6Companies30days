// https://leetcode.com/problems/number-of-pairs-satisfying-inequality/

class Solution {
    public long numberOfPairs(int[] nums1, int[] nums2, int diff) {
        for(int i=0; i<nums1.length; i++) 
            nums1[i] -= nums2[i];
        
        List<Integer> l = new ArrayList<>();
        long sol = 0;
        
        for(int i=0; i<nums1.length; i++){
            sol += binarySearch(l, nums1[i]+diff);
            l.add(binarySearch(l, nums1[i]), nums1[i]);
        }
        return sol;
    }

    private int binarySearch(List<Integer> l, int num){
        int start = 0;
        int end = l.size();
        
        while(start<end){
            int mid = start+(end-start)/2;
            if(l.get(mid)<=num){
                start = mid+1;
            }
            else 
                end = mid;
        }
        return start;
    }
}
