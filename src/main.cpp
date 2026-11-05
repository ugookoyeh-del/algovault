#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

int linearSearch(const std::vector<int>& values, int target) {
    for (std::size_t i = 0; i < values.size(); ++i)
        if (values[i] == target) return static_cast<int>(i);
    return -1;
}

// Requires a sorted input. Returns the matching index or -1.
int binarySearch(const std::vector<int>& values, int target) {
    int left = 0, right = static_cast<int>(values.size()) - 1;
    while (left <= right) {
        const int mid = left + (right - left) / 2;
        if (values[mid] == target) return mid;
        if (values[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

std::vector<int> bubbleSort(std::vector<int> values) {
    for (std::size_t end = values.size(); end > 1; --end) {
        bool swapped = false;
        for (std::size_t i = 1; i < end; ++i) {
            if (values[i - 1] > values[i]) {
                std::swap(values[i - 1], values[i]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return values;
}

std::vector<int> breadthFirstSearch(const std::vector<std::vector<int>>& graph, int start) {
    if (start < 0 || start >= static_cast<int>(graph.size())) return {};
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> pending;
    std::vector<int> order;
    visited[start] = true;
    pending.push(start);
    while (!pending.empty()) {
        int node = pending.front(); pending.pop();
        order.push_back(node);
        for (int next : graph[node]) {
            if (next >= 0 && next < static_cast<int>(graph.size()) && !visited[next]) {
                visited[next] = true;
                pending.push(next);
            }
        }
    }
    return order;
}

int main() {
    const std::vector<int> data{9, 2, 7, 1, 5, 3};
    std::cout << "AlgoVault - C++ algorithms showcase\n";
    std::cout << "Linear search for 7: index " << linearSearch(data, 7) << '\n';
    auto sorted = bubbleSort(data);
    std::cout << "Bubble sort: ";
    for (int value : sorted) std::cout << value << ' ';
    std::cout << "\nBinary search for 5: index " << binarySearch(sorted, 5) << '\n';

    const std::vector<std::vector<int>> graph{{1, 2}, {0, 3}, {0, 3}, {1, 2, 4}, {3}};
    std::cout << "BFS from node 0: ";
    for (int node : breadthFirstSearch(graph, 0)) std::cout << node << ' ';
    std::cout << '\n';
    return 0;
}
