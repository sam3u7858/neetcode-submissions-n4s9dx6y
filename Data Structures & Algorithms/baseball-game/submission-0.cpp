class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        
        for(auto const& s:operations){
            if(s == "+"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                
                st.push(b);
                st.push(a);
                
                st.push(a+b);
            }
            else if(s == "C"){
                st.pop();
            }
            else if(s == "D"){
                int a = st.top(); st.pop();
                st.push(a);
                st.push(a*2);
            }
            else{
                st.push(stoi(s));
            }
        }

        int res = 0;
        while(!st.empty()){
            res+= st.top(); st.pop();
        }

        return res;
    }
};