
#include <stdio.h>
#include <stdint.h>
#include "poker.h"

int main() {
    int8_t cards[13]; // 儲存使用者輸入的卡牌編碼

    printf("請輸入 13 張卡牌的編碼（範圍 1-52），以空格分隔：\n");

    // 從使用者獲取輸入
    for (int i = 0; i < 13; i++) {
        if (scanf("%hhd", &cards[i]) != 1) {
            printf("輸入錯誤，請輸入有效的整數編碼。\n");
            return -1;
        }
    }

    // 顯示排序前的卡牌
    printf("Cards before sorting:\n");
    
    for (int i = 0; i < 13; i++) {
        printf("%d ", cards[i]);
    }
    printf("\n");

    // 調用 big_two_sort 進行排序
    if (big_two_sort(cards) != 0) {
        printf("Error: Invalid cards or duplicates found.\n");
        return -1;
    }

    // 顯示排序後的卡牌
    printf("Cards after sorting:\n");
    for (int i = 0; i < 13; i++) {
        printf("%d ", cards[i]);
    }
    printf("\n");

    return 0;
}
