class Solution {

private:

    int getNumber(stack<char>& st){
        int res = 0;
        string tmp;
        tmp.reserve(3);
        while(!st.empty()){
            char c = st.top();
            if(c - '0' <= 9 && c - '0' >=0){
                st.pop();
                tmp+=c;
            }
            else{
                break;
            }
        }

        reverse(tmp.begin(), tmp.end());
        if (tmp.empty()) return 1;
        return stoi(tmp);
    }

    void handleRepeat(stack<char>& st, string& s){
        string tmp ="";
        tmp.reserve(s.size());

        while(!st.empty()){
            char tmpc = st.top(); st.pop();
            if(tmpc == '['){
                int rep = getNumber(st);
            
                reverse(tmp.begin(), tmp.end());     

                for(int i=0; i<rep; i++){
                    for(int j=0; j<tmp.size(); j++){
                        st.push(tmp[j]);
                        
                        cout << tmp[j] << endl;
                    }

                } 
                break;
            }

            else{
                tmp+=tmpc;
            }

        }

    }

public:
    
    


    string decodeString(string s) {
        stack<char> st;
        string res ="";
        res.reserve(s.size()*2);
        
        for(const auto c:s){
            if(c == ']'){
                handleRepeat(st, s);   
            }
            else{
                st.push(c);
            }
        }


        while(!st.empty()){
            res+=st.top(); st.pop();
        }

        reverse(res.begin(), res.end());   
        return res;
    }
};