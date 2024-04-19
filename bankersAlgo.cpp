#include <bits/stdc++.h>

using namespace std;

bool isSafe(const vector<vector<int>>& max, const vector<vector<int>>& allocated, const vector<int>& available, vector<bool>& finish) {
    int processCount = max.size();
    int resourceCount = available.size();

    vector<int> work = available;
    int count = 0;

    while (count < processCount) {
        bool allocatedSomething = false;
        for (int i = 0; i < processCount; ++i) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < resourceCount; ++j) {
                    if (max[i][j] - allocated[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    allocatedSomething = true;
                    count++;
                    for (int j = 0; j < resourceCount; ++j) {
                        work[j] += allocated[i][j];
                    }
                    finish[i] = true;
                }
            }
        }
        if (!allocatedSomething) {
            return false; // Deadlock detected
        }
    }
    return true; // No deadlock detected
}

int main() {
    int processCount, resourceCount;
    cin >> processCount >> resourceCount;

    vector<vector<int>> max(processCount, vector<int>(resourceCount));
    vector<vector<int>> allocated(processCount, vector<int>(resourceCount));
    vector<int> available(resourceCount);
    vector<bool> finish(processCount, false);

    for (int i = 0; i < processCount; ++i)
        for (int j = 0; j < resourceCount; ++j)
            cin >> max[i][j];

    for (int i = 0; i < processCount; ++i)
        for (int j = 0; j < resourceCount; ++j)
            cin >> allocated[i][j];

    for (int i = 0; i < resourceCount; ++i)
        cin >> available[i];

    if (isSafe(max, allocated, available, finish))
        cout << "Safe state! No deadlock detected." << endl;
    else
        cout << "Unsafe state! Deadlock detected." << endl;

    return 0;
}
