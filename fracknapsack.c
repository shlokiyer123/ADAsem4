#include <stdio.h>

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to swap two items
void swap(struct Item* a, struct Item* b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items by value/weight ratio in descending order
void sortItems(struct Item arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            double r1 = (double)arr[j].value / arr[j].weight;
            double r2 = (double)arr[j+1].value / arr[j+1].weight;
            if (r1 < r2) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to calculate the maximum value that can be carried in the knapsack
double fractionalKnapsack(struct Item arr[], int n, int capacity) {
    sortItems(arr, n); // Sort items by value/weight ratio

    double totalValue = 0.0; // Total value in knapsack

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= capacity) {
            capacity -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * ((double)capacity / arr[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n; // Number of items
    int capacity; // Capacity of knapsack

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item arr[n]; // Array of items

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d (weight value): ", i + 1);
        scanf("%d %d", &arr[i].weight, &arr[i].value);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    double maxValue = fractionalKnapsack(arr, n, capacity);

    printf("Maximum value in knapsack = %.2f\n", maxValue);

    return 0;
}
