class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Upper bound is the max value in the pile
        int upper_bound = maxAt(piles);

       

        //Binary Search
        int left = 1;
        int right = upper_bound;
        int result = upper_bound;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            bool ifPossible = checkIfPossible(piles, h, mid);
            if(ifPossible){
                result = mid;  // Update the result to the current valid speed
                right = mid - 1;
                
            }
            else{
                left = mid + 1;
               
            }
        }
        return result;
    }

    bool checkIfPossible(vector<int> &piles, int h, int k){
        // O(M)
        int timeConsumed = 0;
        for(int p:piles){
            timeConsumed += (p + k - 1) / k; 
            if(timeConsumed > h){
                return false;
            }
        }
        return true;

    }

    int maxAt(std::vector<int>& vector_name) {
        int max = INT_MIN;
        for (auto val : vector_name) {
            if (max < val) max = val;
        }
        return max;
    }
};
