// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int result = 0;
//         for (auto num: nums){
//             result ^= num;
//         }
//         return result;
//     }
// };

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-1; i+=2){
            if (nums[i] == nums[i+1]){
                continue;
            }
            else{
                return nums[i];
            }
        }
        return nums[nums.size()-1];
    }
};