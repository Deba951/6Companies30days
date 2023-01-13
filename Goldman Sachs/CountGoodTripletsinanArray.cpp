// https://leetcode.com/problems/count-good-triplets-in-an-array/description/

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        vector<int> v(N);
        
        for (int i=0; i<N; ++i) 
            v[nums1[i]] = i;
        long long ans = 0;
        vector<int> tree(N+1);
        
        for (int i=1; i<N-1; ++i){
            for (int j=v[nums2[i-1]]+1; j<=N; j+=j&-j) 
                ++tree[j]; 
            int y = v[nums2[i]], less = 0;
            
            for (int j=y; j; j&=j-1) 
                less += tree[j]; 
            
            ans += (long)less * (N-1-y-(i-less));
        }
        return ans;
    }
};
