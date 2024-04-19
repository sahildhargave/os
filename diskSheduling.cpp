#include <bits/stdc++.h>

using namespace std;

// First In First Out (FIFO) Disk Scheduling Algorithm
int FIFO(const vector<int>& requests, int head) {
    int totalSeek = 0;
    for (int i = 0; i < requests.size(); ++i) {
        totalSeek += abs(requests[i] - head);
        head = requests[i];
    }
    return totalSeek;
}

// Shortest Seek Time First (SSTF) Disk Scheduling Algorithm
int SSTF(const vector<int>& requests, int head) {
    int totalSeek = 0;
    vector<bool> visited(requests.size(), false);

    for (int i = 0; i < requests.size(); ++i) {
        int minDist = INT_MAX;
        int index = -1;
        for (int j = 0; j < requests.size(); ++j) {
            if (!visited[j]) {
                int dist = abs(requests[j] - head);
                if (dist < minDist) {
                    minDist = dist;
                    index = j;
                }
            }
        }
        visited[index] = true;
        totalSeek += minDist;
        head = requests[index];
    }
    return totalSeek;
}

// SCAN (Elevator) Disk Scheduling Algorithm
int SCAN(const vector<int>& requests, int head, bool direction) {
    int totalSeek = 0;
    vector<int> lower, upper;
    for (int i = 0; i < requests.size(); ++i) {
        if (requests[i] < head)
            lower.push_back(requests[i]);
        else
            upper.push_back(requests[i]);
    }

    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());

    if (direction) {
        for (int i = upper.size() - 1; i >= 0; --i) {
            totalSeek += abs(upper[i] - head);
            head = upper[i];
        }
        for (int i = 0; i < lower.size(); ++i) {
            totalSeek += abs(lower[i] - head);
            head = lower[i];
        }
    } else {
        for (int i = 0; i < lower.size(); ++i) {
            totalSeek += abs(lower[i] - head);
            head = lower[i];
        }
        for (int i = upper.size() - 1; i >= 0; --i) {
            totalSeek += abs(upper[i] - head);
            head = upper[i];
        }
    }

    return totalSeek;
}

// C-SCAN (Circular SCAN) Disk Scheduling Algorithm
int CSCAN(const vector<int>& requests, int head) {
    int totalSeek = 0;
    vector<int> lower, upper;
    for (int i = 0; i < requests.size(); ++i) {
        if (requests[i] < head)
            lower.push_back(requests[i]);
        else
            upper.push_back(requests[i]);
    }

    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());

    for (int i = 0; i < upper.size(); ++i) {
        totalSeek += abs(upper[i] - head);
        head = upper[i];
    }

    totalSeek += abs(head - 199); // Move to the end of the disk

    head = 0; // Move to the beginning of the disk

    for (int i = 0; i < lower.size(); ++i) {
        totalSeek += abs(lower[i] - head);
        head = lower[i];
    }

    return totalSeek;
}

int main() {
    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;

    cout << "FIFO: " << FIFO(requests, head) << endl;
    cout << "SSTF: " << SSTF(requests, head) << endl;
    cout << "SCAN (Elevator): " << SCAN(requests, head, true) << endl;
    cout << "C-SCAN (Circular SCAN): " << CSCAN(requests, head) << endl;

    return 0;
}
