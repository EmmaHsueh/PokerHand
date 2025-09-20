
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


/*
#include <stdio.h>
#include <stdint.h>
#include "poker.h"

int main() {
    int8_t cards[13]; // 儲存使用者輸入的卡牌編碼

    printf("請輸入 13 張卡牌的編碼（範圍 1-52)，以空格分隔：\n");

    // 從使用者獲取輸入
    for (int i = 0; i < 13; i++) {
        if (scanf("%hhd", &cards[i]) != 1) {
            printf("輸入錯誤，請輸入有效的整數編碼。\n");
            return -1;
        }
    }

    // 呼叫 big_two_sort 函式進行排序
    int result = big_two_sort(cards);

    if (result == -1) {
        printf("輸入的卡牌無效（超出範圍或有重複卡牌）。\n");
    } else {
        printf("排序後的卡牌編碼: ");
        for (int i = 0; i < 13; i++) {
            printf("%d ", cards[i]);
        }
        printf("\n");

        // 顯示對應的卡牌
        const char *suits[] = {"♠", "♡", "♢", "♣"};
        printf("排序後的卡牌: ");
        for (int i = 0; i < 13; i++) {
            int rank = (cards[i] - 1) % 13 + 1; // 計算點數
            const char *rank_str;
            if (rank == 1) {
                rank_str = "A";
            } else if (rank == 11) {
                rank_str = "J";
            } else if (rank == 12) {
                rank_str = "Q";
            } else if (rank == 13) {
                rank_str = "K";
            } else {
                static char rank_buf[3];
                snprintf(rank_buf, sizeof(rank_buf), "%d", rank);
                rank_str = rank_buf;
            }
            printf("%s%s ", rank_str, suits[(cards[i] - 1) / 13]);
        }
        printf("\n");
    }

    return 0;
}
*/