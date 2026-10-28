//
// Created by Junio Moreira on 27/10/26.
// Problem 1: Inversion Count with Merge Sort (Adapted from beecrowd #1088)
//
// Strategy:
//  Divide and Conquer (Merge Sort):
//   1. Preserve the identical classroom structure: merge and mergeSort.
//   2. The only enhancement: merge and mergeSort now return the number of inversions.
//   3. When helper[i] > helper[j], it creates (middle - i + 1) inversions with
//      all remaining elements in the left subarray.
//
// Complexity: O(N log N) time | O(N) auxiliary space.
//

#include <iostream>
#include <vector>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

// Type alias for 64-bit integers (prevents overflow since max inversions can reach ~5*10^9)
using ll = long long;

struct InversionResult {
    ll count;
    vector<ll> sortedArray;

    bool operator==(const InversionResult& other) const {
        return count == other.count && sortedArray == other.sortedArray;
    }
};

class Solution {
public:
    // Public entry point wrapper matching classroom style
    InversionResult countInversions(vector<ll> nums) {
        // TODO: Implement mergeSort and merge functions adapting Merge Sort
        // TODO: Count inversions when helper[i] > helper[j] via (middle - i + 1)
        // TODO: Return InversionResult containing the total inversion count and sorted vector

        return {0, nums};
    }
};

// Helper function to print numeric vectors
void printVector(const vector<ll>& nums) {
    ll n = (ll)nums.size();
    cout << "[";
    for (ll i = 0; i < n; i++) {
        cout << nums[i] << (i + 1 < n ? ", " : "");
    }
    cout << "]";
}

// Test runner function matching the standard testing format
void runTest(Solution& solver, int testNum, const string& testName,
             const vector<ll>& input, const InversionResult& expected) {
    InversionResult output = solver.countInversions(input);
    bool passed = (output == expected);

    cout << "\nTest " << testNum << " Results (" << testName << "):\n";
    cout << "Input:    "; printVector(input); cout << "\n";
    cout << "Expected: "; printVector(expected.sortedArray); cout << " | Inversions = " << expected.count << "\n";
    cout << "Output:   "; printVector(output.sortedArray); cout << " | Inversions = " << output.count << "\n";
    cout << "Status:   " << (passed ? "Passed" : "Failed") << "\n";
}

int main() {
    FAST_IO;
    Solution solution;

    // --- Test 1: Assignment Example 1 ---
    vector<ll> in1 = {2, 3, 8, 6, 1};
    InversionResult exp1 = {5, {1, 2, 3, 6, 8}};
    runTest(solution, 1, "Assignment Example 1", in1, exp1);

    // --- Test 2: Assignment Example 2 (Already Sorted) ---
    vector<ll> in2 = {1, 2, 3, 4};
    InversionResult exp2 = {0, {1, 2, 3, 4}};
    runTest(solution, 2, "Assignment Example 2 (Already Sorted)", in2, exp2);

    // --- Test 3: Completely Inverted ---
    vector<ll> in3 = {5, 4, 3, 2, 1};
    InversionResult exp3 = {10, {1, 2, 3, 4, 5}};
    runTest(solution, 3, "Reverse Sorted", in3, exp3);

    // --- Test 4: Array with Negative Numbers ---
    vector<ll> in4 = {-1, -5, 10, 2};
    InversionResult exp4 = {2, {-5, -1, 2, 10}};
    runTest(solution, 4, "Array with Negatives", in4, exp4);

    return 0;
}