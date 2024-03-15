#include <stdio.h>

/*Problem #4:
Given an integer array nums and an integer k, return the number of good subarrays of
nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.
*/

int subArrays(int *nums,int numsSize, int k) {

}

int main() {
    /*Example 1:
    Input: nums = [1,2,1,2,3], k = 2
    Output: 7*/
    int nums[] = {1,2,1,2,3};
    int numsSize=5;
    int k = 2;

    subArrays(nums,numsSize,k);
    return 0;
}