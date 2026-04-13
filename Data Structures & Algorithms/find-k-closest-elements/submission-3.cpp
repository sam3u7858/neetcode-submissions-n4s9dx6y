class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        //TODO: use binary search
        int n = arr.size();
       
        int pivot = 0;
        int minDiff = abs(arr[0] - x);
        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - x) < minDiff) {
                minDiff = abs(arr[i] - x);
                pivot = i;
            } else if (abs(arr[i] - x) == minDiff) {
            } else {
                break;
            }
        }

        int l = pivot;
        int r = pivot;
        int count = 1;


        while(count < k){
            if(l>0 && r<n-1){
                if(abs(arr[l-1]-x) <= abs(arr[r+1]-x)){
                    l--;
                }
                else {
                    r++;
                }
               
            }
            else if(l>0){
                l--;
            }
            else if(r < n-1){
                r++;
            }

            count+=1;
        }



        vector<int> res(arr.begin()+l, arr.begin()+1+r);
        return res;


    }
};