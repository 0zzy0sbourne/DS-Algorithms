// using binary search 
class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1 ; 
        while(low <= high){
            int mid = ( low + high ) / 2  ;  
            if(nums[mid] < target)
                low = mid + 1 ; 
            else {
                high = mid - 1 ; 
            }
        }
        return low ; 
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1}; 
        int size = nums.size(); 
        int first = -1 , last = -1  ; 
        first = lowerBound(nums, target);
        last = lowerBound(nums,  target+1) - 1 ; 
        if(first>=0 && first < size && last >= 0 && last<size && nums[last] == target && nums[first] == target) return {first, last}; 
        return {-1,-1}; 
    }
};