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
int differentInt(int *nums,int k) {
    int diff=1,j;
    for(int i=1;i<k;i++) {
        for(j=0;j<i;j++) {
            if(nums[i]==nums[j])
                break;
        }
        if(i==j)
            diff++;
    }
    return diff;
}

int subArrays(int* ,int, int,int,int );

int main() {
    int nums[] = {1,2,1,2,3};
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    int k = 2;
    int perm=k;
    int output = 0;
    int result = subArrays(nums,numsSize,k,perm,output);
    printf("Output is %d\n",result);

    return 0;
}
int subArrays(int *nums,int numsSize,int k,int perm,int output) {
    int i=0,x=k,y,diff;
    int *temp_arr=(int *)malloc(numsSize*sizeof(int));
    if(k==1) {
        output=numsSize;
        return output;
    }
    //Read array from index[0] to index[k]
    while(i<=numsSize && k < numsSize+1) {
        //Check if index[k] has reach the end of array
        if(x==numsSize+1) {
            //If true check if k is equal to numsSize
            if(k==numsSize) {
                return output;
            }
            //If false perform a recursion
            subArrays(nums,numsSize,k+1,perm,output);
            break;
        }
        for(int j=i,y=0;j<x && x<=numsSize;y++,j++) {
            temp_arr[y]=nums[j];
            printf("%d ",temp_arr[y]);
        }
        printf("\n",k);
        diff = differentInt(temp_arr,k);
        if(diff==perm) {
            output+=1;
        }
        x++;
        i++;
    }
}
