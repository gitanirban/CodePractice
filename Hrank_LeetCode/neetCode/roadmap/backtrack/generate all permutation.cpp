#include <iostream>
#include <vector>
using namespace std;

void generatePermutations(vector<vector<int>>& result, vector<int>& nums, vector<int>& permutation, vector<bool>& used) {
    if (permutation.size() == nums.size()) {
        result.push_back(permutation);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (!used[i]) {
            used[i] = true;
            permutation.push_back(nums[i]);
            generatePermutations(result, nums, permutation, used);
            permutation.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> permutation;
    vector<bool> used(nums.size(), false);
    generatePermutations(result, nums, permutation, used);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);
    cout << "Output:" << endl;
    for (const auto& perm : result) {
        cout << "[ ";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
