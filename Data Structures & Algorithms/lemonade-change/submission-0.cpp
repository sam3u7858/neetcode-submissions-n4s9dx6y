class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> credits(3, 0);
        for(int i=0; i<bills.size(); i++){
            int curr = bills[i];
            if(curr == 5){
                credits[0]++;
            }
            else if(curr == 10){
                if(credits[0] == 0) return false;
                else{
                    credits[1]++;
                    credits[0]--;
                }

            }
            else{
                // 20 -> 15 (5+5+5) or (10+5) 

                if(credits[1] >0 && credits[0]>0) {
                    credits[1]--;
                    credits[0]--;
                    credits[2]++;
                }
                else if(credits[0]>=3){
                    credits[0] -= 3;
                    credits[2]++;
                }
                else{
                    return false;
                }

            }
        }
        return true;
    }
};