/***********************************************************************
 * @file arry_dense.cpp
 * @brief  leetcode file
 * @history
 * Date       Version Author    description
 * ========== ======= ========= =======================================
 * 2019-11-17 V1.0    HuYe.SJTU   Create
 *
 * @Copyright (C)  2019  .China . all right reserved
***********************************************************************/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAX_DAT_LEN   50000
int g_numsProc[MAX_DAT_LEN];

int CmpFunc(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int GetMaxNumIdxInArr(int* arr, int size) {
    int cont = 0;
    int i;
    int temp = arr[0];
    for (i = 0; i < size; i++) {
        if (arr[i] > temp) {
            temp = arr[i];
            cont = i;
        }
    }
    return cont;
}

int GetArrDense(int* nums, int size, int num) {
    int i;
    int start =-1;
    int end = 1;
    for (i = 0; i < size; i++) {
        if (nums[i] == num) {
            if(start == -1){
                start = i;
            }
            end = i;
        }
    }
    return (end - start + 1);
}

int findShortestSubArray(int* nums, int numsSize){
    //memcpy_s(&g_numsProc[0], numsSize, nums, numsSize);
    //qsort(g_numsProc, numsSize, sizeof(int), CmpFunc);
    int i;
    int maxIdx = 0;
    int minDense = MAX_DAT_LEN;
    int temp = 0;
    memset(&g_numsProc[0],0,MAX_DAT_LEN*sizeof(int));
    for (i = 0; i < numsSize;i++) {
        g_numsProc[nums[i]]++;
    }
    maxIdx = GetMaxNumIdxInArr(g_numsProc,MAX_DAT_LEN);
    for (i = 0; i < MAX_DAT_LEN;i++){
        if(g_numsProc[i] == g_numsProc[maxIdx]) {
            temp = GetArrDense(nums, numsSize, i);
            if(temp < minDense){
                minDense = temp;
            }
        }
    }
    return minDense;
}

int main()
{
    int n;
    //int arr[] ={1,2,2,3,1};
    //findShortestSubArray(arr, 5);
    int arr[] ={49999,0,0};
    findShortestSubArray(arr, 3);
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", n);
    }
    return 0;
}