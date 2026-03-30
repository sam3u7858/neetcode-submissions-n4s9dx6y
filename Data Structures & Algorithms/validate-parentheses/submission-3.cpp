class Solution {
public:
    bool isValid(string s) {
        stack<char> cars;
        for(char c:s){
            if(c=='[' || c=='{' ||  c=='('){
                // push in stack
                cars.push(c);
            }

            else{
                if(cars.empty()){
                    return false;
                }

                if( ( c == ')' && cars.top() == '(') || 
                    ( c == ']' && cars.top() == '[') ||
                    ( c == '}' && cars.top() == '{')){
                            cars.pop();
                    }
                    else{
                        return false;
                    }
            }

           

        }

        return cars.empty();
    }

};
