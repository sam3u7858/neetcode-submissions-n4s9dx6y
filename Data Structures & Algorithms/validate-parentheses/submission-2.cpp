class Solution {
public:
    bool isValid(string s) {
        stack<char> cars;
        for(char c:s){
            if(c=='[' || c=='{' ||  c=='('){
                // push in stack
                cars.push(c);
            }

            if(cars.size()>0){
               if(c==')'){
                if(cars.top()!='('){
                    return false;
                }
                else{
                    cars.pop();
                }
            }
               if(c=='}'){
                if(cars.top()!='{'){
                    return false;
                }
                else{
                    cars.pop();
                }
            }
              if(c==']'){
                if(cars.top()!='[' ){
                    return false;
                }
                else{
                    cars.pop();
                }
            }
            }
            else{
                return false;
            }
        }

        if(cars.size()>0){
            return false;
        }
        return true;
    }

};
