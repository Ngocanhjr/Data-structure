#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// First algorithm: Only computes and returns the maximum value
int unboundedKnapsackValueOnly(int W, int n, vector<int>& weights, vector<int>& values) {
    // Initialize array to store maximum values for each capacity
    vector<int> K(W + 1, 0);

    // Fill the K array using dynamic programming
    for (int x = 1; x <= W; x++) {
        for (int i = 0; i < n; i++) {
            if (weights[i] <= x) {
                K[x] = max(K[x], K[x - weights[i]] + values[i]);
            }
        }
    }

    return K[W];
}

// Second algorithm: Computes the maximum value and keeps track of selected items
vector<int> unboundedKnapsackWithItems(int W, int n, vector<int>& weights, vector<int>& values) {
    // Initialize array to store maximum values for each capacity
    vector<int> K(W + 1, 0);

    // Initialize 2D vector to store the items selected for each capacity
    vector<vector<int>> ITEMS(W + 1);

    // Fill the K and ITEMS arrays using dynamic programming
    for (int x = 1; x <= W; x++) {
        for (int i = 0; i < n; i++) {
            if (weights[i] <= x) {
                int new_value = K[x - weights[i]] + values[i];
                if (new_value > K[x]) {
                    K[x] = new_value;

                    // Update items - take items from smaller capacity and add current item
                    ITEMS[x] = ITEMS[x - weights[i]];
                    ITEMS[x].push_back(i);
                }
            }
        }
    }

    return ITEMS[W];  // Return the list of selected items for capacity W
}

// Function to demonstrate usage of the algorithms
int main() {
    int W = 10;  // Knapsack capacity
    int n = 3;   // Number of items

    vector<int> weights = {2, 3, 5};
    vector<int> values = {3, 4, 7};

    // Calculate maximum value only
    int maxValue = unboundedKnapsackValueOnly(W, n, weights, values);
    cout << "Maximum value: " << maxValue << endl;

    // Calculate maximum value and get the selected items
    vector<int> selectedItems = unboundedKnapsackWithItems(W, n, weights, values);
    cout << "Selected items (0-indexed): ";
    for (int item : selectedItems) {
        cout << item << " ";
    }
    cout << endl;

    // Print details of selected items
    int totalWeight = 0, totalValue = 0;
    cout << "Item details (index, weight, value):" << endl;
    for (int item : selectedItems) {
        cout << "Item " << item << ": weight = " << weights[item] << ", value = " << values[item]
             << endl;
        totalWeight += weights[item];
        totalValue += values[item];
    }
    cout << "Total weight: " << totalWeight << ", Total value: " << totalValue << endl;

    return 0;
}