class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> pattern;

        int k = 0;
        string currstr = "";

        for(const char& c: s){
           

            if(isdigit(c)){

                k = k * 10 + (c-'0');

            }

            else if(c == '['){
                counts.push(k);
                pattern.push(currstr);
                currstr = "";
                k = 0;

            }
            else if(c == ']'){
                string tmp = currstr;

                currstr = pattern.top();
                pattern.pop();
                int repeats = counts.top();
                counts.pop();

                while(repeats-- ){
                    currstr += tmp;
                }
            }
            else{
                currstr += c;
            }
        }

        return currstr;

    }
};