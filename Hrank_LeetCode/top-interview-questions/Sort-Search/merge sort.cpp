// merge sort

#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int>& left, std::vector<int>& right) {
    std::vector<int> output;
    int lSz = left.size(), rSz = right.size();

    while (lSz and rSz)
    {
        auto leftItr = left.begin();
        auto rightItr = right.begin();

        if (*leftItr < *rightItr) {
            output.push_back(*leftItr);
            left.erase(leftItr);
            lSz--;
        }
        else {
            output.push_back(*rightItr);
            right.erase(rightItr);
            rSz--;
        }
    }

    while (lSz) {
        auto n = left.begin();
        output.push_back(*n);
        left.erase(n);
        lSz--;
    }

    while (rSz) {
        auto rightItr = right.begin();
        output.push_back(*rightItr);
        right.erase(rightItr);
        rSz--;
    }

    return output;
}

std::vector<int> merge_sort(std::vector<int>& list) {
    int list_length = list.size();

    if (list_length == 1)
        return list;

    int mid_point = list_length / 2;

    std::vector<int> left_half(list.begin(), list.begin() + mid_point);
    std::vector<int> right_half(list.begin() + mid_point, list.end());

    left_half = merge_sort(left_half);
    right_half = merge_sort(right_half);

    return merge(left_half, right_half);
}

int main() {
    std::vector<int> unsorted_list = { 2, 4, 1, 5, 7, 2, 6, 1, 1, 6, 4, 10, 33, 5, 7, 23 };
    std::vector<int> sorted_list = merge_sort(unsorted_list);

    std::cout << "Unsorted List:\n";
    for (int num : unsorted_list) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted List:\n";
    for (int num : sorted_list) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
