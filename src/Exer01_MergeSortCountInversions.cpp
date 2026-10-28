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
#include <string>

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
private:
    // TODO: Implement the private helper method 'merge':
    //  - Signature: ll merge(vector<ll>& nums, vector<ll>& helper, ll left, ll middle, ll right)
    //  - Step 1: Copy the range [left..right] from 'nums' to 'helper'.
    //  - Step 2: Set pointers i = left, j = middle + 1, k = left, and inv_count = 0.
    //  - Step 3: While i <= middle and j <= right:
    //      * If helper[i] <= helper[j], copy helper[i++] to nums[k++].
    //      * Otherwise, copy helper[j++] to nums[k++] and increment inv_count by (middle - i + 1).
    //  - Step 4: Copy any remaining elements from the left subarray (while i <= middle).
    //  - Step 5: Return inv_count.

    // TODO: Implement the private recursive method 'mergeSort':
    //  - Signature: ll mergeSort(vector<ll>& nums, vector<ll>& helper, ll left, ll right)
    //  - Base case: If left >= right, return 0.
    //  - Step 1: Calculate midpoint: middle = left + (right - left) / 2.
    //  - Step 2: Recursively sort left half and accumulate inversions.
    //  - Step 3: Recursively sort right half and accumulate inversions.
    //  - Step 4: Merge both halves using 'merge' and accumulate cross-inversions.
    //  - Step 5: Return total inversions.

public:
    // Public entry point wrapper matching classroom style
    InversionResult countInversions(vector<ll> nums) {
        ll totalInversions = 0;

        // TODO: Allocate a helper buffer vector of the same size as nums: vector<ll> helper(nums.size())
        // TODO: If nums is not empty, invoke mergeSort(nums, helper, 0, (ll)nums.size() - 1)
        // TODO: Store the returned value in totalInversions

        return {totalInversions, nums};
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