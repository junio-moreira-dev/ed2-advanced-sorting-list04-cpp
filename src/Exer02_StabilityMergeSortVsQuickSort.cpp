//
// Created by Junio Moreira on 23/09/26.
// Problem 2: The Challenge of Stability - Merge Sort vs. Quick Sort
// Adapted from beecrowd #1244 (Sort by Length)
//
// Strategy:
//  Sort a collection of words in descending order by string length:
//   1. Merge Sort (Stable): The merge routine enforces stability using '>=' on length comparisons.
//      On a length tie, the element from the left partition (which appeared earlier in the original
//      sequence) is prioritized, preserving relative order.
//   2. Quick Sort (Unstable): Hoare partitioning with left pivot reverses symmetrically positioned
//      elements with equal lengths, visibly breaking the input order as expected by the assignment.
//
// Complexity: O(N log N) time | O(N) auxiliary space.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

// Type alias for 64-bit integers
using ll = long long;

struct StabilityResult {
    vector<string> mergeSortWords;
    vector<string> quickSortWords;

    bool operator==(const StabilityResult& other) const {
        return mergeSortWords == other.mergeSortWords &&
               quickSortWords == other.quickSortWords;
    }
};

class Solution {
private:
    // TODO: Implement the private helper method 'merge':
    //  - Signature: void merge(vector<string>& words, vector<string>& helper, ll left, ll middle, ll right)
    //  - Step 1: Copy elements from range [left..right] of 'words' into 'helper'.
    //  - Step 2: Set pointers i = left, j = middle + 1, k = left.
    //  - Step 3: While i <= middle and j <= right:
    //      * Compare string lengths: if helper[i].length() >= helper[j].length(), assign helper[i++] to words[k++].
    //        (Crucial: '>=' guarantees stability by prioritizing the leftmost original occurrence on tie).
    //      * Otherwise, assign helper[j++] to words[k++].
    //  - Step 4: Copy any remaining elements from the left subarray (while i <= middle).

    // TODO: Implement the private recursive method 'mergeSort':
    //  - Signature: void mergeSort(vector<string>& words, vector<string>& helper, ll left, ll right)
    //  - Base case: if left >= right, return.
    //  - Step 1: Calculate midpoint: middle = left + (right - left) / 2.
    //  - Step 2: Recursively call mergeSort on left half [left..middle].
    //  - Step 3: Recursively call mergeSort on right half [middle + 1..right].
    //  - Step 4: Merge both halves with merge(words, helper, left, middle, right).

    // TODO: Implement the private helper method 'partitionHoareDesc':
    //  - Signature: ll partitionHoareDesc(vector<string>& words, ll left, ll right)
    //  - Step 1: Choose the left element length as pivot: size_t pivotLen = words[left].length().
    //  - Step 2: Initialize convergent pointers: i = left - 1, j = right + 1.
    //  - Step 3: Loop infinitely:
    //      * Increment i while words[i].length() > pivotLen.
    //      * Decrement j while words[j].length() < pivotLen.
    //      * If i >= j, return boundary index j.
    //      * Otherwise, swap words[i] and words[j].

    // TODO: Implement the private recursive method 'quickSort':
    //  - Signature: void quickSort(vector<string>& words, ll left, ll right)
    //  - Base case: if left >= right, return.
    //  - Step 1: Partition using partitionHoareDesc to find splitIndex.
    //  - Step 2: Recursively sort left partition [left..splitIndex].
    //  - Step 3: Recursively sort right partition [splitIndex + 1..right].

public:
    // Compares sorting stability between Merge Sort and Quick Sort
    StabilityResult compareStability(const vector<string>& inputWords) {
        vector<string> mergeWords = inputWords;
        vector<string> quickWords = inputWords;

        // TODO: If inputWords is not empty:
        //  - Allocate helper vector: vector<string> helper(mergeWords.size())
        //  - Execute stable mergeSort on mergeWords: mergeSort(mergeWords, helper, 0, (ll)mergeWords.size() - 1)
        //  - Execute unstable quickSort on quickWords: quickSort(quickWords, 0, (ll)quickWords.size() - 1)

        return {mergeWords, quickWords};
    }
};

// Helper function to print string vectors
void printVector(const vector<string>& words) {
    cout << "[";
    for (size_t i = 0; i < words.size(); ++i) {
        cout << "\"" << words[i] << "\"" << (i + 1 < words.size() ? ", " : "");
    }
    cout << "]";
}

// Test runner function matching the standard testing format
void runTest(Solution& solver, int testNum, const string& testName,
             const vector<string>& input, const StabilityResult& expected) {
    StabilityResult output = solver.compareStability(input);
    bool passed = (output == expected);

    cout << "\nTest " << testNum << " Results (" << testName << "):\n";
    cout << "Input:          "; printVector(input); cout << "\n";
    cout << "Expected Merge: "; printVector(expected.mergeSortWords); cout << "\n";
    cout << "Output Merge:   "; printVector(output.mergeSortWords); cout << "\n";
    cout << "Expected Quick: "; printVector(expected.quickSortWords); cout << "\n";
    cout << "Output Quick:   "; printVector(output.quickSortWords); cout << "\n";
    cout << "Status:         " << (passed ? "Passed" : "Failed") << "\n";
}

int main() {
    FAST_IO;
    Solution solution;

    // --- Test 1 (Assignment Example 1) ---
    vector<string> in1 = {"mar", "Coder", "sol", "broad"};
    StabilityResult exp1 = {
        {"Coder", "broad", "mar", "sol"},
        {"Coder", "broad", "sol", "mar"}
    };
    runTest(solution, 1, "Assignment Example 1", in1, exp1);

    // --- Test 2 (Assignment Example 2) ---
    vector<string> in2 = {"sol", "lua", "estrela", "mar", "ceu"};
    StabilityResult exp2 = {
        {"estrela", "sol", "lua", "mar", "ceu"},
        {"estrela", "ceu", "mar", "lua", "sol"}
    };
    runTest(solution, 2, "Assignment Example 2", in2, exp2);

    // --- Test 3 (Distinct Lengths (No Ties)) ---
    vector<string> in3 = {"a", "bbb", "cc", "dddd"};
    StabilityResult exp3 = {
        {"dddd", "bbb", "cc", "a"},
        {"dddd", "bbb", "cc", "a"}
    };
    runTest(solution, 3, "Distinct Lengths (No Ties)", in3, exp3);

    return 0;
}