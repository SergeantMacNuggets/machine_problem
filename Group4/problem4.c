#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Container for the User Input Variables
typedef struct userInput {
    int *nums;
    int numsSize;
    int k;
}userInput;

//Function to find how many different integer are in the array
int differentInt(int *nums,int k) {
    int diff=1,j;
    //Used nested loop
    for(int i=1;i<k;i++) {
        for(j=0;j<i;j++) {
            if(nums[i]==nums[j])
                break;
        }
        //Check if value i is equal to j and if true increment diff variable;
        if(i==j)
            diff++;
    }
    //Return the diff variable the total number of different integer in the array
    return diff;
}

/*A function that check if there are inputted number that are within the constraints and if true it
  will loop until it's outside the constraints and will return the inputed value*/
int indexConstraints(int n,int numsSize,int i) {
    //An option if i would like to read the contraints if its the nums index or the k

    //if i is greater or equal to 0 then the function will read the nums index
    if(i>=0) {
        while(true) {
            printf("nums[%d] = ",i);
            scanf("%d",&n);
            if(n < 1)
                printf("Nums[i] must be > or = to 1 and < or = to size of the array\n");
            else
                break;
        }
    }
    //if i is less than 0 then it will read the k
    else if(i==-1) {
        while(true) {
            printf("How many different integers to be scanned? k = ");
            scanf("%d",&n);
            //variable k
            if(n > numsSize)
                printf("k must be > or = to 1 and < or = to size of the array\n");
            else 
                break;
        }
    }
    else if(i==-2) {
        while(true) {
            printf("How many integer would you like to add? ");
            scanf("%d",&n);
            //variable k
            if(1>n || n>20000)
                printf("Size of the array must be > or == to 1 and < or = 2 x 10^4\n");
            else 
                break;
        }
    }
    //Depending on the option it will return the inputted value
    return n;
}
int __rec__fuc(int* ,int, int, int, int);
void displaySubArr(int *,int,int);

//Pre call subArrays function before calling __rec__fuc
int subArrays(int *nums,int numsSize,int k) {
    int perm=k;
    int output = 0;
    //If k=1 the automatic output is equal to it's nums size
    if(k==1) {
        output=numsSize;
        return output;
    }
    return __rec__fuc(nums,numsSize,k,perm,output);
}
int main() {
    //Declaring struct
    userInput u1;
    //Ask for the size of the array with constraints
    u1.numsSize=indexConstraints(0,0,-2);
    //Dynamically Allocating Memory for better preserving the bytes
    u1.nums=(int *)malloc(u1.numsSize*sizeof(int));
    printf("Input %d numbers:\n",u1.numsSize);

    //Start the input of number in an array with constraints
    for(int i=0;i<u1.numsSize;i++) {
        u1.nums[i]=indexConstraints(0,u1.numsSize,i);
    }
    //Ask how many integer to scan of the subArrays k=x
    u1.k=indexConstraints(u1.k,u1.numsSize,-1);
    //Clear the screen after inputting all the required variables
    system("cls");
    //Display the Sub Arrays
    displaySubArr(u1.nums,u1.numsSize,-1);
    printf("Sub Arrays:\n");
    //The result is the output of how many subarray form with exactly k different integers
    int result = subArrays(u1.nums,u1.numsSize,u1.k);
    //Print the output
    printf("\nA total of %d subarrays formed with exactly %d different integers\n",result,u1.k);

    return 0;
}

//The function to find how many subarray will form with the given k
int __rec__fuc(int *nums,int numsSize,int k,int perm,int output) {
    int i=0,diff,x=perm;
    //Same as num, dynamically allocating memory
    int *temp_arr=(int *)malloc(numsSize*sizeof(int));
    //Read array from index[0] to index[k]
    while(i<=numsSize && perm < numsSize+1) {
        //Check if index[k] has reach the end of array
        if(x==numsSize+1) {
            //If true check if k is equal to numsSize
            if(perm==numsSize)
                return output;
            //If false perform a recursion
            __rec__fuc(nums,numsSize,k,perm+1,output);
            break;
        }
        //Scan all the index inside of the num
        //The scanned integers are distributed to the temp_arr which is the sub array
        for(int j=i,y=0;j<x && x<=numsSize;y++,j++)
            temp_arr[y]=nums[j];
        //Read the temp_arr and how many different integers inside
        diff = differentInt(temp_arr,perm);
        //If the amount of different integers equal to k
        if(diff==k) {
            //Output will be incremented
            output++;
            //Display the sub arrays
            displaySubArr(temp_arr,perm,output);
        }
        x++;
        i++;
    }
}
void displaySubArr(int *arr,int perm,int output) { 
    //If output is < 0 then display the array in the terminal
    if(output < 0) {
        printf("Arrays:\n");
        for(int u=0;u<perm;u++)
            printf(" ___");
        printf("\n");
        printf("| ");
        for(int i=0;i<perm;i++)
            printf("%d | ",arr[i]);
        printf("\n");
        for(int u=0;u<perm;u++)
            printf("*---");
        printf("*\n\n");
    }
    //If output is >= 0 then display the subarrays in the terminal
    else {
        for(int u=0;u<perm;u++)
            printf(" ___");
        printf("\n");
        printf("| ");
        for(int i=0;i<perm;i++)
            printf("%d | ",arr[i]);
        printf("= subArray%d\n",output);
        for(int u=0;u<perm;u++)
            printf("*---");
        printf("*\n");
    }
}

