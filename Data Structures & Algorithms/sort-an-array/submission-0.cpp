class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int left, int right){
        if(left >= right) return;
        int pivot = nums[left + (right - left)/2];
        int i=left;
        int j=right;

        while(i <= j){
            while(nums[i] < pivot) i++;
            while(nums[j] > pivot) j--;

            if(i<=j){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }

        quickSort(nums, left, j);
        quickSort(nums, i, right);
    }
};