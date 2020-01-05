/***********************************************************************
 * @file min_char.cpp
 * @brief  leetcode file
 * @history
 * Date       Version Author    description
 * ========== ======= ========= =======================================
 * 2019-11-20 V1.0    HuYe.SJTU   Create
 *
 * @Copyright (C)  2019  .China . all right reserved
***********************************************************************/

#include "stdio.h"
#include "string.h"
#include <stdlib.h>

char * removeDuplicateLetters(char * s){
    int cont = 0;
    int arr[27];
    int outArr[27];
    char *cOut = (char*)malloc(sizeof(char) * 27);
    memset(arr,0,sizeof(arr));
    while(s[cont]!='\0'){
        arr[s[cont]-'a']++;
        cont++;
    }
    int addNum = 0;
    int start = 0;
    int temp = 0;
    for (int i = 0; i < 26; i++){
        if(arr[i]!=0){
            for (int j = start; j < cont;j++){
                temp = s[j] - 'a';
                if(temp<i){
                    continue;//处理过的字符跳过
                }
                if((temp!=i)){
                     if (arr[temp] > 1){
                         arr[temp]--;
                     }else{
                         outArr[addNum] = temp;
                         addNum++;                       
                     }
                     
                }else{
                    outArr[addNum] = temp;
                    addNum++;
                    arr[temp] = 0;   
                    start = j;                 
                    break;
                }
            }            
        }
    }
    for (int i = 0; i < addNum;i++){
        cOut[i] = outArr[i] + 'a';
    }
    cOut[addNum] = '\0';
    return cOut;
}

int main()
{
    int n;
    char inStr[100] = "thesqtitxyetpxloeevdeqifkz";
    removeDuplicateLetters(inStr);
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", n);
    }
    return 0;
}