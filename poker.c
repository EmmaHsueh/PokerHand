#include "poker.h"
#include <stdint.h>
#include <stdbool.h>

// Helper function to extract the rank of the card
int get_rank(int8_t card) {
    int rank = (card - 1) % 13; // Normalize rank to 0-12
    if (rank == 0) return 14;  // Ace becomes 14
    if (rank == 1) return 15;  // 2 becomes 15
    return rank + 2;           // Other ranks (3-10, J=11, Q=12, K=13)
}

// Helper function to extract the suit of the card
int get_suit(int8_t card) {
    return (card - 1) / 13; // Suit order: ♠=0, ♡=1, ♢=2, ♣=3
}

// Compare function for sorting
bool compare_cards(int8_t card1, int8_t card2) {
    int rank1 = get_rank(card1);
    int rank2 = get_rank(card2);
    if (rank1 != rank2) {
        return rank1 < rank2; // Compare by rank first
    }
    return get_suit(card1) < get_suit(card2); // Compare by suit if ranks are equal
}

// Bubble sort to sort cards
void bubble_sort(int8_t cards[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (!compare_cards(cards[j], cards[j + 1])) {
                // Swap cards[j] and cards[j + 1]
                int8_t temp = cards[j];
                cards[j] = cards[j + 1];
                cards[j + 1] = temp;
            }
        }
    }
}

// Main sorting function for Big Two
int32_t big_two_sort(int8_t cards[]) {
    if (!cards) return -1; // Check for invalid input
    
    // Check if all cards are in the valid range and for duplicates
    int count[53] = {0}; // Create an array to track card occurrences
    for (int i = 0; i < 13; i++) {
        if (cards[i] < 1 || cards[i] > 52) {
            return -1; // Invalid card
        }
        count[cards[i]]++;
        if (count[cards[i]] > 1) {
            return -1; // Duplicate card
        }
    }

    bubble_sort(cards, 13); // Sort the cards using the custom bubble sort
    return 0;
}


/*
#include "poker.h"
#include <stdint.h>
#include <stdbool.h>

// Helper function to extract the rank of the card
int get_rank(int8_t card) {
    int rank = (card - 1) % 13; // Normalize rank to 0-12
    if (rank == 0) return 14;  // Ace 對應 14
    if (rank == 1) return 15;  // 2 對應 15
    return rank;               // 其他牌維持原本的值 (3~K)
}

// Helper function to extract the suit of the card
int get_suit(int8_t card) {
    return (card - 1) / 13; // Suit order: ♠, ♡, ♢, ♣
}

// Compare function for sorting
bool compare_cards(int8_t card1, int8_t card2) {
    int rank1 = get_rank(card1);
    int rank2 = get_rank(card2);
    if (rank1 != rank2) {
        return rank1 < rank2; // Compare by rank
    }
    return get_suit(card1) < get_suit(card2); // Compare by suit if ranks are equal
}

void bubble_sort(int8_t cards[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (!compare_cards(cards[j], cards[j + 1])) {
                // Swap cards[j] and cards[j + 1]
                int8_t temp = cards[j];
                cards[j] = cards[j + 1];
                cards[j + 1] = temp;
            }
        }
    }
}

int32_t big_two_sort(int8_t cards[]) {
    if (!cards) return -1; // Check for invalid input
    
    // Check if all cards are in the valid range and for duplicates
    int count[53] = {0}; // Create an array to track card occurrences
    for (int i = 0; i < 13; i++) {
        if (cards[i] < 1 || cards[i] > 52) {
            return -1; // Invalid card
        }
        count[cards[i]]++;
        if (count[cards[i]] > 1) {
            return -1; // Duplicate card
        }
    }

    bubble_sort(cards, 13); // Sort the cards using the custom bubble sort
    return 0;
}
*/