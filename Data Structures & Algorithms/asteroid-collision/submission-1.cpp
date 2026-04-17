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

    bool isSameWay(int a, int b){
   
        if(a==0 && b==0) return true; // UB
        if(a==0 || b==0) return false; 

        // for -2, 2 (this will no collide)
        if(a < 0 || b > 0) return true;


        if(abs(a)+abs(b) == abs(a+b)){
            return true;
        }
        else{
            return false;
        }
    }

public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int& i : asteroids){
            if(st.empty())st.push(i);
            else{
                if(isSameWay(st.top(), i)) st.push(i);
                else{
                    while(true){
                        if(st.empty() || isSameWay(st.top(), i)){
                            st.push(i);
                            break;
                        }

                        int b = st.top();
                        if(abs(b) > abs(i))break;
                        if(abs(b) < abs(i))st.pop();
                        else{
                            st.pop();
                            break;
                  

                    }
                }
            }
        }
        }

        return prepareAnswer(st);

    }
};