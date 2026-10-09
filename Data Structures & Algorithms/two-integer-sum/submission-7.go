func twoSum(nums []int, target int) []int {
    vb := make(map[int]int) 

    for i, num := range nums {
        diff := target - num
        if j, ok := vb[diff]; ok {
            return []int{j, i}
        }
        vb[num] = i
    }

  
    return []int{}
}
