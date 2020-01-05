/***********************************************************************
 * @file m132.cpp
 * @brief  leetcode file
 * @history
 * Date       Version Author    description
 * ========== ======= ========= =======================================
 * 2019-11-18 V1.0    HuYe.SJTU   Create
 *
 * @Copyright (C)  2019  .China . all right reserved
***********************************************************************/

#include "stdio.h"
// 左值为左侧最小，中间值遍历整个
int GetEffectIndex(int *nums, int numSize, int maxValue, int minValue)
{
    for (int i = 0; i < numSize; i++) {
        if((maxValue>nums[i]) &&(minValue< nums[i])) {
            return 1;
        }
    }
    return 0;
}


bool find132pattern(int* nums, int numsSize)
{
    if(numsSize < 3){
        return false;
    }
    int leftMin = nums[0];
    int result = 0;
    for (int i = 1; i < numsSize - 1;i++) {
        if(nums[i]<=leftMin){
            leftMin = nums[i];
            continue;
        }
        result = GetEffectIndex(&nums[i+1],numsSize - i - 1, nums[i], leftMin);
        if(result == 1){
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", n);
    }
    return 0;
}