class Solution {
public:
    bool checkValidString(string s) {
        // base case;
        if(s.size () == 0) return true;
        stack<int> p;
        stack<int> sp;
        
       
        for(int i=0; i<s.size(); i++){
            char curr = s[i];
            if(curr == '('){
               p.push(i);
            }
            else if(curr == '*'){
               sp.push(i);
            }
            else{ // "*" or 
                if (!p.empty()) {
                    p.pop(); //
                }
                else if(!sp.empty()){
                    sp.pop();
                }
                else{
                    return false;
                }
            }
        }

        while(!sp.empty() && !p.empty()){
            if(p.top() > sp.top()){
                return false;
            }
            p.pop();
            sp.pop();
        }

        return p.empty();

        
    }
};
