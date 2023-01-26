// https://leetcode.com/problems/minimum-genetic-mutation/description/

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        q.push(startGene);
        
        unordered_set<string> um;
        um.insert(startGene);
        
        int mutation = 0;
        while (!q.empty()){
            size_t size = q.size();
            
            while (size--){
                string curr = std::move(q.front()); q.pop();
                
                if (curr == endGene) 
                    return mutation;
                
                for (const string& gene : bank){
                    
                    if (um.count(gene) || !validMutation(curr, gene)) 
                        continue;

                    um.insert(gene);
                    q.push(gene);
                }
            }
            ++mutation;
        }    
        return -1;
    }

    private:
    bool validMutation(const string& s1, const string& s2) {
        int cnt = 0;

        for (int i=0; i<s1.length(); ++i){
            if (s1[i] != s2[i] && cnt++) 
                return false;
        }

        return true;
    }
};
