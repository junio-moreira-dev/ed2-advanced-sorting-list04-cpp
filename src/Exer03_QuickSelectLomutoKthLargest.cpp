//
// Created by Junio Moreira on 23/09/26.
// Problem 3: Linear Selection with Lomuto Partitioning (Quickselect)
// Adapted from LeetCode #215 (Kth Largest Element in an Array)
//
// Strategy:
//  Quickselect using Lomuto Partitioning (Ascending order):
//   1. Maps the K-th largest element to index (N - K) in zero-indexed ascending order.
//   2. Explicit manual swap demonstrates memory manipulation using a temporary variable.
//   3. Effective Swap Rule: only counts writes between strictly distinct indices (i != j).
//   4. Recursively prunes unneeded partitions, converging in O(N) average time.
//
// Complexity: O(N) average time, O(N^2) worst case | O(log N) auxiliary recursion space.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

// Type alias for 64-bit integers
using ll = long long;

struct QuickselectResult {
    ll kthElement;
    vector<ll> finalState;
    ll swapCount;

    bool operator==(const QuickselectResult& other) const {
        return kthElement == other.kthElement &&
               finalState == other.finalState &&
               swapCount == other.swapCount;
    }
};

class Solution {
private:
    // TODO: Implement the private helper method 'manualSwap':
    //  - Signature: void manualSwap(ll& a, ll& b)
    //  - Perform a direct swap of values using pass-by-reference and a temporary variable.

    // TODO: Implement the private helper method 'effectiveSwap':
    //  - Signature: void effectiveSwap(vector<ll>& nums, ll i, ll j, ll& swapCount)
    //  - Condition: Execute manualSwap(nums[i], nums[j]) and increment swapCount ONLY if i != j.

    // TODO: Implement the private helper method 'partitionLomuto':
    //  - Signature: ll partitionLomuto(vector<ll>& nums, ll left, ll right, ll& swapCount)
    //  - Step 1: Set pivot = nums[right] and boundary i = left - 1.
    //  - Step 2: Iterate j from left to right - 1. If nums[j] <= pivot:
    //      * Increment i.
    //      * Call effectiveSwap(nums, i, j, swapCount).
    //  - Step 3: Place pivot into its final position: effectiveSwap(nums, i + 1, right, swapCount).
    //  - Step 4: Return pivot position (i + 1).

    // TODO: Implement the private recursive method 'quickSelect':
    //  - Signature: ll quickSelect(vector<ll>& nums, ll left, ll right, ll targetIndex, ll& swapCount)
    //  - Base case: if left > right, return -1.
    //  - Step 1: Find pivotIndex = partitionLomuto(nums, left, right, swapCount).
    //  - Step 2: If pivotIndex == targetIndex, return nums[pivotIndex].
    //  - Step 3: If targetIndex < pivotIndex, prune right half: recurse on [left..pivotIndex - 1].
    //  - Step 4: Otherwise, prune left half: recurse on [pivotIndex + 1..right].

public:
    // Finds the K-th largest element using Lomuto partitioning and counts effective swaps (i != j)
    QuickselectResult findKthLargest(vector<ll> nums, ll k) {
        ll swapCount = 0;
        ll kthVal = -1;

        // TODO: Validate that nums is not empty and k is in valid range [1..nums.size()]
        // TODO: Compute target ascending index: targetIndex = (ll)nums.size() - k
        // TODO: Call quickSelect(nums, 0, (ll)nums.size() - 1, targetIndex, swapCount) and assign to kthVal

        return {kthVal, nums, swapCount};
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
             const vector<ll>& input, ll k, const QuickselectResult& expected) {
    QuickselectResult output = solver.findKthLargest(input, k);
    bool passed = (output == expected);

    cout << "\nTest " << testNum << " Results (" << testName << "):\n";
    cout << "Input:          "; printVector(input); cout << " | K = " << k << "\n";
    cout << "Expected Val:   "; cout << expected.kthElement << " | Output Val:   " << output.kthElement << "\n";
    cout << "Expected State: "; printVector(expected.finalState); cout << "\n";
    cout << "Output State:   "; printVector(output.finalState); cout << "\n";
    cout << "Expected Swaps: "; cout << expected.swapCount << " | Output Swaps: " << output.swapCount << "\n";
    cout << "Status:         " << (passed ? "Passed" : "Failed") << "\n";
}

int main() {
    FAST_IO;
    Solution solution;

    // --- Test 1 (Assignment Example 1: N=6, K=2) ---
    vector<ll> in1 = {3, 2, 1, 5, 6, 4};
    ll k1 = 2;
    QuickselectResult exp1 = {5, {3, 2, 1, 4, 5, 6}, 2};
    runTest(solution, 1, "Assignment Example 1", in1, k1, exp1);

    // --- Test 2 (Assignment Example 2: N=9, K=4) ---
    vector<ll> in2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    ll k2 = 4;
    QuickselectResult exp2 = {4, {3, 2, 3, 1, 2, 4, 5, 5, 6}, 0};
    runTest(solution, 2, "Assignment Example 2", in2, k2, exp2);

    // --- Test 3 (Single Element: N=1, K=1) ---
    vector<ll> in3 = {42};
    ll k3 = 1;
    QuickselectResult exp3 = {42, {42}, 0};
    runTest(solution, 3, "Single Element", in3, k3, exp3);

    // --- Test 4 (Find Maximum: K=1) ---
    vector<ll> in4 = {7, 10, 4, 3, 20, 15};
    ll k4 = 1;
    QuickselectResult exp4 = {20, {7, 10, 4, 3, 15, 20}, 1};
    runTest(solution, 4, "Find Maximum (K=1)", in4, k4, exp4);

    return 0;
}