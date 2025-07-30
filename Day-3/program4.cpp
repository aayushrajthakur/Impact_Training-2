//Rain water trap problem

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (n <= 2) {
        cout << "Sum is : 0" << endl; 
        return 0;
    }
    int left = 0, right = n - 1;
    int leftmax = arr[left], rightmax = arr[right];
    int sum = 0;

    while (left < right) {
        if (arr[left] < arr[right]) {
            if (arr[left] >= leftmax) {
                leftmax = arr[left];
            } else {
                sum += leftmax - arr[left];
            }
            left++;
        } else {
            if (arr[right] >= rightmax) {
                rightmax = arr[right];
            } else {
                sum += rightmax - arr[right];
            }
            right--;
        }
    }

    cout << "Sum is : " << sum << endl;
    return 0;
}