/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
   public:

    int binarySearch(int target, MountainArray& mountainArr, int l, int r, int mode){
        while(r >= l){
            int mid = (r-l)/2 + l;
            int mdp = mountainArr.get(mid);
            if( mdp > target ) {
                if(mode==1) r = mid - 1;
                if(mode==2) l = mid + 1;

            }
            else if(mdp == target) return mid;
            else{
                if(mode==1) l = mid+1;
                if(mode==2) r = mid-1;
            }

        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();
        int inflection_point = -1;
        int l = 0;
        int r = n;

        int res = 0;

        int calls = 0;

        while (l <= r) {
            int mid = (r - l) / 2 + l;
            int midValue = mountainArr.get(mid);
            int midValueP1 = mountainArr.get(mid+1);
            calls +=2;
            if (mid < n - 1 &&  midValue > midValueP1 &&
                midValue > mountainArr.get(mid - 1)) {
                inflection_point = mid;
                calls += 1;
                break;
            } else if (mid < n - 1 && midValue >midValueP1) {
                r = mid - 1;
                
            } else {
                l = mid + 1;
            }
        }

        cout << inflection_point << ":" << calls << endl;
 
        
        int a = binarySearch(target, mountainArr, 0, inflection_point, 1);
        int b = 0;

      
        cout <<  inflection_point+1 <<":"<< n-1 << endl;
        if(a==-1) b =  binarySearch(target, mountainArr, inflection_point+1, n-1, 2);
        else{
            return a;
        }


      
        return b;

        
       
    
    }
};