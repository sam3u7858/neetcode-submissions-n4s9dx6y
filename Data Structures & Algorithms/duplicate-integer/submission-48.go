func hasDuplicate(nums []int) bool {
    exist := make(map[int]bool);
    for _, n := range nums{

        if(exist[n] == true){
            return true;
        }
        exist[n] = true;
        
    }

    return false;
}
