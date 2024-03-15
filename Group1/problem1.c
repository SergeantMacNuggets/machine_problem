#include <stdio.h>

/*
Problem #1:
You are given an array nums that consists of positive integers.
The GCD of a sequence of numbers is defined as the greatest integer that divides all the
numbers in the sequence evenly.
For example, the GCD of the sequence [4,6,16] is 2.
A subsequence of an array is a sequence that can be formed by removing some elements
(possibly none) of the array.
*/

int* gcdArray(int *nums, int output) {
    int GCD;
    //Use dynamic memory allocator functions such as
    //malloc(),calloc(),free(),realloc()
    // O(n^2) time complexity is the worst approach and O(log n)
    // is the best approach of looping
    //Advice using a pointer

    //O(n^2) Looping
    /*for(int i=0;i<=n;i++)
        for(int j=i+i;j<=n;j++)
            nums[i] && nums[j]
        */
    //O(log n) Looping
    /*Binary Search Loop*/

    return GCD;
}

/*
  Input: nums = [6,10,3]
  Output: 5
  Explanation: The figure shows all the non-empty subsequences and their GCDs.
  The different GCDs are 6, 10, 3, 2, and 1.
*/

int main() {
    int nums[]={6,10,3};
    int output = 5;

    //Do not dereference the pointer nums
    gcdArray(nums,output);


    return 0;
}