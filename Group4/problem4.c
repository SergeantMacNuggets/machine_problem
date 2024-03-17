#include <stdio.h>
#include <stdlib.h>

/*Problem #4:
Given an integer array nums and an integer k, return the number of good subarrays of
nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.
*/

/*Example 1:
    Input: nums = [1,2,1,2,3], k = 2
    Output: 7*/
int diffInt(int* nums,int i,int j,int k) {

}

int subArrays(int* ,int, int );

int main() {
    int nums[] = {1,2,1,2,3};
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    int k = 2;
    int output = subArrays(nums,numsSize,k);
    //diffInt(nums,0,2,k);
    printf("Output is %d\n",output);

    return 0;
}

int subArrays(int *nums,int numsSize,int k) {
    int output=0,i=0,x=k;
    if(k==1) {
        output=numsSize;
        return output;
    }

    //Read array from index[0] to index[k]
    while(i<=numsSize && k < 7) {
        //Check if index[k] has reach the end of array
        if(x==numsSize+1) {
            //If true perform a recursion
            subArrays(nums,numsSize,k+1);
            break;
        }
        for(int j=i;j<x && x<=numsSize;j++) {
            printf("%d ", nums[j]);
        }
        printf("\n");
        x++;
        i++;
    }
    return output;
}
