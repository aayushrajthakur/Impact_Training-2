#include <iostream>
using namespace std;
int main() {
    int arr[] = {45, 67, 23, 56, 84, 93, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = 5;
    int visited[size] = {0}; 
    for (int j = 0; j < n; j++) {
        int max_val = -1;
        int max_index = -1;
        for (int i = 0; i < size; i++) {
            if (!visited[i] && (max_val < arr[i])) {
                max_val = arr[i];
                max_index = i;
            }
        }

        if (max_index != -1) {
            visited[max_index] = true; 
            if (j == n - 1) {
                cout<<n<<"th largest element: " << max_val;
            }
        }
    }
    return 0;
}
