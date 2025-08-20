#include <bits/stdc++.h>
using namespace std;

long long minCost(vector<int>& basket1, vector<int>& basket2) {
    unordered_map<int, int> freq;
    int minFruit = INT_MAX;
    for (int fruit : basket1) {
        freq[fruit]++;
        minFruit = min(minFruit, fruit);
    }

    for (int fruit : basket2) {
        freq[fruit]--;
        minFruit = min(minFruit, fruit);
    }

    vector<int> excess;
    for (auto& [fruit, count] : freq) {
        if (count % 2 != 0) return -1; 
        for (int i = 0; i < abs(count) / 2; ++i)
            excess.push_back(fruit);
    }

    sort(excess.begin(), excess.end());

    long long cost = 0;
    int n = excess.size();
    for (int i = 0; i < n / 2; ++i) {
        cost += min(excess[i], 2 * minFruit);
    }

    return cost;
}

int main() {
    vector<int> basket1 = {4, 2, 2, 2};
    vector<int> basket2 = {1, 4, 1, 2};

    long long result = minCost(basket1, basket2);
    if (result == -1)
        cout << "Impossible to balance the baskets." << endl;
    else
        cout << "Minimum cost to rearrange fruits: " << result << endl;

    return 0;
}
