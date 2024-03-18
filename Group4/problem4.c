#include <stdio.h>
#include <stdlib.h>

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

int subArrays(int* ,int, int);

int main() {
    int nums[]={1,2,1,2,3};
    int k=2;
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    int output = 0;
    int perm = k;
    int result = subArrays(nums,numsSize,k);
    printf("Output is %d\n",result);

    return 0;
}
int subArrays(int *nums,int numsSize,int k) {
    int i=0,perm=k,output=0,x=perm,diff;
    int *temp_arr=(int *)malloc(numsSize*sizeof(int));
    if(k==1) {
        output=numsSize;
        return output;
    }
    while(x<=numsSize+1) {
    //Read array from index[0] to index[k]
        while(i<=numsSize && perm < numsSize+1) {
        //Check if index[k] has reach the end of array
            if(x==numsSize+1) {
            //If true check if k is equal to numsSize
                if(perm==numsSize) {
                    printf("x is %d\n",x);
                    return output;
                }
            //If false perform a recursion
                break;
            }
            for(int j=i,y=0;j<x && x<=numsSize;y++,j++) {
                temp_arr[y]=nums[j];
                printf("%d ",temp_arr[y]);
            }
            printf("*x=%d\n",x);
            diff = differentInt(temp_arr,perm);
            if(diff==k) {
                output+=1;
            }
            x++;
            i++;
        }
        perm+=1;
        printf("perm is %d\n",perm);
    }
}
