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
    // Merges two sorted subarrays preserving stability (>= prioritizes left elements)
    void merge(vector<string>& words, vector<string>& helper, ll left, ll middle, ll right) {
        for (ll m = left; m <= right; m++) {
            helper[m] = words[m];
        }

        ll i = left;          // Left subarray pointer
        ll j = middle + 1;    // Right subarray pointer
        ll k = left;          // Destination pointer

        while (i <= middle && j <= right) {
            // '>= ensures stability: on a length tie, choose the element that appeared first (left partition)
            if (helper[i].length() >= helper[j].length()) {
                words[k++] = helper[i++];
            } else {
                words[k++] = helper[j++];
            }
        }

        // Copy remaining elements from the left subarray (if any)
        while (i <= middle) {
            words[k++] = helper[i++];
        }
    }

    void mergeSort(vector<string>& words, vector<string>& helper, ll left, ll right) {
        if (left < right) {
            ll middle = left + (right - left) / 2;
            mergeSort(words, helper, left, middle);
            mergeSort(words, helper, middle + 1, right);
            merge(words, helper, left, middle, right);
        }
    }

    // Hoare partitioning for descending order using left element as pivot
    ll partitionHoareDesc(vector<string>& words, ll left, ll right) {
        size_t pivotLen = words[left].length();
        ll i = left - 1;
        ll j = right + 1;

        while (true) {
            do {
                i++;
            } while (words[i].length() > pivotLen);

            do {
                j--;
            } while (words[j].length() < pivotLen);

            if (i >= j) {
                return j;
            }

            swap(words[i], words[j]);
        }
    }

    void quickSort(vector<string>& words, ll left, ll right) {
        if (left < right) {
            ll splitIndex = partitionHoareDesc(words, left, right);
            quickSort(words, left, splitIndex);
            quickSort(words, splitIndex + 1, right);
        }
    }

public:
    StabilityResult compareStability(const vector<string>& inputWords) {
        vector<string> mergeWords = inputWords;
        vector<string> quickWords = inputWords;

        if (!inputWords.empty()) {
            vector<string> helper(mergeWords.size());
            mergeSort(mergeWords, helper, 0, (ll)mergeWords.size() - 1);
            quickSort(quickWords, 0, (ll)quickWords.size() - 1);
        }

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