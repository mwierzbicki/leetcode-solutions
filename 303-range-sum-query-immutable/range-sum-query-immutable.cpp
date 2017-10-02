// Given an integer array nums, find the sum of the elements between indices i and j (i &le; j), inclusive.
//
// Example:
//
// Given nums = [-2, 0, 3, -5, 2, -1]
//
// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3
//
//
//
// Note:
//
// You may assume that the array does not change.
// There are many calls to sumRange function.
//
//


class NumArray {
public:
    NumArray(vector<int> nums) {
        gnums=nums;
        gnums.insert(gnums.begin(),0);
        for (int i=1; i<gnums.size(); i++) {
            gnums[i]+=gnums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return gnums[j+1]-gnums[i];
    }
private:
vector<int> gnums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
