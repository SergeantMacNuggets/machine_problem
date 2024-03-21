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

int indexContraints(int n,int numsSize,int i) {
    if(i>=0) {
        while(true) {
            printf("nums[%d] = ",i);
            scanf("%d",&n);
            if(1>n||n>numsSize)
                printf("Nums[i] must be > or = to 1 and < or = to size of the array\n");
            else
                break;
        }
    }
    else if(i<0) {
        while(true) {
            printf("How many different integers to be scanned? k = ");
            scanf("%d",&n);
            if(1 > n || n > numsSize)
                printf("k must be > or = to 1 and < or = to size of the array\n");
            else 
                break;
        }
    }
    return n;
}

bool numsConstraint(int numsSize) {
    if(1>numsSize || numsSize>20000)
        return true;
    return false;
}

int __rec__fuc(int* ,int, int, int, int);
void displaySubArr(int *,int,int);

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
    if(numsConstraint(u1.numsSize)==true) {
        printf("Size of the array must be > or == to 1 and < or = 2 x 10^4\n");
        main();
    }
    printf("Input %d numbers:\n",u1.numsSize);
    for(int i=0;i<u1.numsSize;i++) {
        u1.nums[i]=indexContraints(u1.nums,u1.numsSize,i);
    }
    u1.k=indexContraints(u1.k,u1.numsSize,-1);
    system("cls");
    displaySubArr(u1.nums,u1.numsSize,-1);
    printf("Sub Arrays:\n");
    int result = subArrays(u1.nums,u1.numsSize,u1.k);
    printf("\nOutput is %d\n",result);

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
            output+=1;
            displaySubArr(temp_arr,perm,output);
        }
        x++;
        i++;
    }
}
void displaySubArr(int *arr,int perm,int output) { 
    if(output < 0) {
        printf("Arrays:\n");
        for(int u=0;u<perm;u++) {
            printf(" ___");
        }
        printf("\n");
        printf("| ");
        for(int i=0;i<perm;i++) {
            printf("%d | ",arr[i]);
        }
        printf("\n");
        for(int u=0;u<perm;u++) {
            printf("*---");
        }
        printf("*\n\n");
    }
    else {
        for(int u=0;u<perm;u++) {
            printf(" ___");
        }
        printf("\n");
        printf("| ");
        for(int i=0;i<perm;i++) {
            printf("%d | ",arr[i]);
        }
        printf("= subArray%d\n",output);
        for(int u=0;u<perm;u++) {
            printf("*---");
        }
        printf("*\n");
    }
}

