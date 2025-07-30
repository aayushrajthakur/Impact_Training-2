#include <iostream>
using namespace std;

int main() {
    int n = 6; // Change this value for a different pattern size
    int size = 2 * n - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Calculate the minimum distance to the edges
            int minDist = min(min(i, j), min(size - 1 - i, size - 1 - j));
            cout << n - minDist << " ";
        }
        cout << endl;
    }
    return 0;
}
