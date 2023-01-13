// https://leetcode.com/problems/maximum-points-in-an-archery-competition/

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> ans(12,0);
        int max=0;
        
        for(int i=0;i<(1<<12);i++){
            int sum=0;
            vector<int> v(12,0);
            int count=numArrows;
            
            for(int j=0;j<12;j++){
                if(i&(1<<j)){
                    if(aliceArrows[j]+1<=count){
                        count-=aliceArrows[j]+1;
                        v[j]=aliceArrows[j]+1;
                    }
                }
            }
            
            if(count){
                int pos=0,mini=INT_MAX;
                for(int i=0;i<12;i++){
                    if(v[i]<mini){
                        mini=v[i];
                        pos=i;
                    }
                }
                v[pos]=count;
                count=0;

            }
            sum=0;
            
            for(int i=0;i<12;i++){
                if(v[i]>aliceArrows[i]){
                    sum+=(i);
                }
            }
            
            if(sum>max){
                max=sum;
                ans=v;
            }
        }
        return ans;
    }
};
