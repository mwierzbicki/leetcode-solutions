// Given an integer array nums, find the sum of the elements between indices i and j (i &le; j), inclusive.
//
// The update(i, val) function modifies nums by updating the element at index i to val.
//
// Example:
//
// Given nums = [1, 3, 5]
//
// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8
//
//
//
// Note:
//
// The array is only modifiable by the update function.
// You may assume the number of calls to update and sumRange function is distributed evenly.
//
//


class NumArray {
vector<int> tree;
int r=1;
public:
    NumArray(vector<int> nums) {
        while (r<nums.size()) {
            r*=2;
        }
        for (int i=0; i<=2*r; i++) {
            tree.push_back(0);
        }
        for (int i=0; i<nums.size(); i++) {
            update(i,nums[i]);
        }
    }
    
    void update(int i, int val) {
        i+=r;
        tree[i]=val;
        i/=2;
        while (i>0) {
            tree[i]=tree[2*i]+tree[(2*i)+1];
            i/=2;
        }
    }
    
    int sumRange(int i, int j) {
        i+=r; j+=r;
        int ans=tree[i];
        if (i!=j) {
            ans+=tree[j];
        }
        while ((i/2)!=(j/2)) {
            if (!(i%2)) {
                ans+=tree[i+1];
            }
            if (j%2) {
                ans+=tree[j-1];
            }
            i/=2; j/=2;
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
