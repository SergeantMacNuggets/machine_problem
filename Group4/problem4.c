#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct userInput {
    int *nums;
    int numsSize;
    int k;
}userInput;

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

int __rec__fuc(int* ,int, int, int, int);
void displayArr(int *,int);

int subArrays(int *nums,int numsSize,int k) {
    int perm=k;
    int output = 0;
    if(k==1) {
        output=numsSize;
        return output;
    }
    return __rec__fuc(nums,numsSize,k,perm,output);
}
int main() {
    userInput u1;
    printf("How many integer would you like to add? ");
    scanf("%d",&u1.numsSize);
    u1.nums=(int *)malloc(u1.numsSize*sizeof(int));
    printf("Input %d numbers:\n",u1.numsSize);
    for(int i=0;i<u1.numsSize;i++) {
        printf("nums[%d] = ",i);
        scanf("%d",&u1.nums[i]);
    }
    printf("How many different integers to be scanned? ");
    scanf("%d",&u1.k);
    int result = subArrays(u1.nums,u1.numsSize,u1.k);
    printf("Output is %d\n",result);

    return 0;
}
int __rec__fuc(int *nums,int numsSize,int k,int perm,int output) {
    int i=0,diff,x=perm;
    int *temp_arr=(int *)malloc(numsSize*sizeof(int));
    //Read array from index[0] to index[k]
    while(i<=numsSize && perm < numsSize+1) {
        //Check if index[k] has reach the end of array
        if(x==numsSize+1) {
            //If true check if k is equal to numsSize
            if(perm==numsSize) {
                return output;
            }
            //If false perform a recursion
            __rec__fuc(nums,numsSize,k,perm+1,output);
            break;
        }
        for(int j=i,y=0;j<x && x<=numsSize;y++,j++) {
            temp_arr[y]=nums[j];
        }
        diff = differentInt(temp_arr,perm);
        if(diff==k) {
            displayArr(temp_arr,perm);
            output+=1;
        }
        x++;
        i++;
    }
}

void displayArr(int *arr,int perm) {
    printf("| ");
    for(int i=0;i<perm;i++) {
        printf("%d | ",arr[i]);
    }
    printf("\n");
}

