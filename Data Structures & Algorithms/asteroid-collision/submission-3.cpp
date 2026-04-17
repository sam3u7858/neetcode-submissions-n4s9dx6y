class Solution {
private:
    vector<int> prepareAnswer(stack<int>& st){
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool isSameWay(int left, int right){
        if(left > 0 && right < 0){
            return false;
        }
        return true;
    }

public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int& i : asteroids){
            if(st.empty() || isSameWay(st.top(), i)){ st.push(i); continue;}

            while(true){
                if(st.empty() || isSameWay(st.top(), i)){
                    st.push(i);
                    break;
                }

                int a = st.top();
                if(abs(a) > abs(i))break; // NOT ADD TO THE LIST
                if(abs(a) < abs(i))st.pop();
                else{
                    st.pop();
                    break;
                }
            } 
            
        }

        return prepareAnswer(st);

    }
};