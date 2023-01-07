// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> s;
        for (auto i : tokens){
            
            if (ops.find(i) == ops.end()) 
                s.push(stoi(i));
            
            else{ 
                int p = s.top();    //Second number present at the top
                s.pop();
                int q = s.top();    //First number present at the top after pop
                s.pop();
                
            //Calculating the popped elements and pushing again 

                if (i == "+") 
                    s.push(q+p);
                
                else if (i == "-") 
                    s.push(q-p);
                
                else if (i == "*") 
                    s.push(q*p);
                
                else 
                    s.push(q/p);
            }
        }        
        return s.top();
    }
};
