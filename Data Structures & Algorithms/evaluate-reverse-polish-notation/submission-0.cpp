class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stck;
        int a=0;
        int b=0;

        for(auto s : tokens){
            if((s == "+") || (s == "-") || (s == "*") || (s == "/")){
               b = stck.top(); stck.pop();
               a = stck.top(); stck.pop();
            }
            else{
                stck.push(stoi(s));
            }

            if(s == "+") stck.push(a + b);
            if(s == "-") stck.push(a - b);
            if(s == "*") stck.push(a * b);
            if(s == "/") stck.push(a / b);
        }

        return stck.top();

    }
};
