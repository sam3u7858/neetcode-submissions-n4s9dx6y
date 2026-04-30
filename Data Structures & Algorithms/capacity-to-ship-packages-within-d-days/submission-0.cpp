class Solution {
public:

    bool canShip(vector<int>& weights, int days, int capa){
        int daysNeeded = 1;
        int current = 0;

        for(int w: weights){
            if(current + w > capa){
                daysNeeded++;
                current = 0;
            }
            current += w;
        }
        return daysNeeded <= days;
    }
 
    int shipWithinDays(vector<int>& weights, int days) {
        int res = 0;

        int sum = accumulate(weights.begin(), weights.end(), 0);
        int l = *max_element(weights.begin(), weights.end());
        int r = sum;

        while(l<r){
            int mid = (r-l)/2+l;
            if(canShip(weights, days, mid)){
                r = mid;
            }   
            else{
                l = mid+1;
            }
            
        }

     

        return l;
        
    }
};