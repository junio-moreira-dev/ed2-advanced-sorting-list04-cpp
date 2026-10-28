//
// Created by Junio Moreira on 23/09/26.
// Problem 4: Parity Sort with Hoare Bidirectional Partitioning
// Adapted from beecrowd #1259 (Even and Odd)
//
// Strategy:
//  Two-phase sorting algorithm:
//   1. Hoare Partitioning for Parity Segregation:
//      - Convergent pointers (i from left, j from right) swap even and odd numbers in O(N) time and O(1) space.
//      - Guarantees all even numbers precede all odd numbers.
//   2. Divide and Conquer QuickSort:
//      - Even partition [left..splitIndex] is sorted in ascending order.
//      - Odd partition [splitIndex + 1..right] is sorted in descending order.
//
// Complexity: O(N log N) expected time | O(log N) auxiliary recursion space.
//

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

// Type alias for 64-bit integers
using ll = long long;

struct ParitySortResult {
    vector<ll> sortedArray;

    bool operator==(const ParitySortResult& other) const {
        return sortedArray == other.sortedArray;
    }
};

class Solution {
public:
    // Segregates evens and odds via Hoare partitioning, then sorts evens (asc) and odds (desc)
    ParitySortResult sortParity(vector<ll> nums) {
        // TODO: Step 1 - Segregate evens (left) and odds (right) using Hoare bidirectional partition
        // TODO: Step 2 - Sort the even partition in ascending order using QuickSort
        // TODO: Step 3 - Sort the odd partition in descending order using QuickSort
        // TODO: Return ParitySortResult containing the resulting segregated and sorted array

        return {nums};
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
             const vector<ll>& input, const ParitySortResult& expected) {
    ParitySortResult output = solver.sortParity(input);
    bool passed = (output == expected);

    cout << "\nTest " << testNum << " Results (" << testName << "):\n";
    cout << "Input:    "; printVector(input); cout << "\n";
    cout << "Expected: "; printVector(expected.sortedArray); cout << "\n";
    cout << "Output:   "; printVector(output.sortedArray); cout << "\n";
    cout << "Status:   " << (passed ? "Passed" : "Failed") << "\n";
}

int main() {
    FAST_IO;
    Solution solution;

    // --- Test 1 (Assignment Example 1) ---
    // Evens {4, 2, 8} -> [2, 4, 8]
    // Odds  {3, 7, 1} -> [7, 3, 1]
    vector<ll> in1 = {4, 3, 2, 7, 8, 1};
    ParitySortResult exp1 = {{2, 4, 8, 7, 3, 1}};
    runTest(solution, 1, "Assignment Example 1", in1, exp1);

    // --- Test 2 (Assignment Example 2) ---
    // Evens {10, 8, 6} -> [6, 8, 10]
    // Odds  {9, 7}     -> [9, 7]
    vector<ll> in2 = {10, 9, 8, 7, 6};
    ParitySortResult exp2 = {{6, 8, 10, 9, 7}};
    runTest(solution, 2, "Assignment Example 2", in2, exp2);

    // --- Test 3 (All Even Numbers) ---
    vector<ll> in3 = {8, 2, 6, 4, 10};
    ParitySortResult exp3 = {{2, 4, 6, 8, 10}};
    runTest(solution, 3, "All Evens", in3, exp3);

    // --- Test 4 (All Odd Numbers) ---
    vector<ll> in4 = {1, 9, 3, 7, 5};
    ParitySortResult exp4 = {{9, 7, 5, 3, 1}};
    runTest(solution, 4, "All Odds", in4, exp4);

    return 0;
}