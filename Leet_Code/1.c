int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(target==nums[i]+nums[j]){
                returnSize[0]=i;
                returnSize[1]=j;
                int* ret = malloc(sizeof(int) * 2);
                 *returnSize = 2;
                return returnSize;
            }
        }
    }
    *returnSize = 0;
    return NULL;

}