class Solution {
public:



    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        //TODO: use binary search
        int n = arr.size();
       
        int pivot = binarySearch(arr,x);

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
private:
    int binarySearch(vector<int>& arr, int x){
        int l=0, r=arr.size()-1;
        while(l<r){
           int mid = l + (r-l)/2;
           if(arr[mid] < x){
                l = mid+1;
           }
           else{
                r = mid;
           }

        }

        if(l>0 && abs(arr[l-1] - x) <=  abs(arr[l]-x)){
            return l-1;
        }
        return l;

    }
};