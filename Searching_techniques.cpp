#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform Index Sequential Search
int indexSequentialSearch(const vector<int>& data, int key) {
    int n = data.size();
    int blockSize, blockIndex;

    cout << "Enter the block size: ";
    cin >> blockSize;

    blockIndex = (key - data[0]) / blockSize;

    if (blockIndex < 0 || blockIndex >= n / blockSize) {
        return -1; // Key is outside the range
    }

    for (int i = blockIndex * blockSize; i < (blockIndex + 1) * blockSize; i++) {
        if (data[i] == key) {
            return i;
        }
    }

    return -1; // Key not found in the block
}

// Function to perform Interpolation Search
int interpolationSearch(const vector<int>& data, int key) {
    int low = 0;
    int high = data.size() - 1;

    while (low <= high && key >= data[low] && key <= data[high]) {
        if (low == high) {
            if (data[low] == key) {
                return low;
            }
            return -1;
        }

        int pos = low + ((key - data[low]) * (high - low)) / (data[high] - data[low]);

        if (data[pos] == key) {
            return pos;
        }

        if (data[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;
}

int main() {
    int choice;
    cout << "Menu:\n";
    cout << "1. Index Sequential Search\n";
    cout << "2. Interpolation Search\n";
    cout << "Enter your choice (1-2): ";
    cin >> choice;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> data(n);

    cout << "Enter " << n << " sorted integers: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    int key;
    cout << "Enter the key to search for: ";
    cin >> key;

    int result = -1;

    switch (choice) {
        case 1:
            result = indexSequentialSearch(data, key);
            break;
        case 2:
            result = interpolationSearch(data, key);
            break;
        default:
            cout << "Invalid choice." << endl;
            return 1;
    }

    if (result != -1) {
        cout << "Key found at index " << result << endl;
    } else {
        cout << "Key not found." << endl;
    }

    return 0;
}
