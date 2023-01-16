// https://leetcode.com/problems/maximum-good-people-based-on-statements/

class Solution {
    int n;
    
    void dfs(vector<int> &v, int i, int j, int &ans, vector<vector<int>> &a){
        if(i==n){
            if(check(a,v))
            ans=max(ans,j);
            return;
        }
        dfs(v, i+1, j, ans, a);
        v[i]=1;
        dfs(v, i+1, j+1, ans, a);
        v[i]=0;
    }
    
    bool check(vector<vector<int>> &a, vector<int> &v){
        for(int i=0; i<n; i++){
            if(v[i]){
                for(int j=0; j<n; j++){
                    if(a[i][j]!=2 && v[j]!=a[i][j])
                    return false;
                }
            }
        }
        return true;
    }

public:
    int maximumGood(vector<vector<int>>& a){
        n=a.size();
        vector<int> v(n);
        int ans=0;
        dfs(v, 0 ,0 ,ans ,a);
        return ans;
    }
};
