class Solution {
public:
    int heightChecker(vector<int>& heights) {
 
        int count[101] = {};
        for(int h:heights){
            count[h]++;
        }

        vector<int> expected;
        for(int h=1; h<=100; h++){
            int c = count[h];
            for(int i=0; i<c; i++){
                expected.push_back(h);
            }
        }

        int res = 0;
        for(int i=0; i<heights.size(); i++){
            if(heights[i] != expected[i]){
                res++;
            }
        }

        return res;

    }
};