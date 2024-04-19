#include <bits/stdc++.h>

using namespace std;

struct Block {
    int id;
    int size;
    bool allocated;
};

void firstFit(vector<Block>& memory, int processId, int processSize) {
    for (int i = 0; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            memory[i].allocated = true;
            cout << "Process " << processId << " allocated to block " << memory[i].id << " using First Fit." << endl;
            return;
        }
    }
    cout << "Process " << processId << " cannot be allocated using First Fit." << endl;
}

void bestFit(vector<Block>& memory, int processId, int processSize) {
    int bestFitIndex = -1;
    int minBlockSize = INT_MAX;

    for (int i = 0; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= processSize && memory[i].size < minBlockSize) {
            bestFitIndex = i;
            minBlockSize = memory[i].size;
        }
    }

    if (bestFitIndex != -1) {
        memory[bestFitIndex].allocated = true;
        cout << "Process " << processId << " allocated to block " << memory[bestFitIndex].id << " using Best Fit." << endl;
    } else {
        cout << "Process " << processId << " cannot be allocated using Best Fit." << endl;
    }
}

void nextFit(vector<Block>& memory, int& lastAllocated, int processId, int processSize) {
    for (int i = lastAllocated; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            memory[i].allocated = true;
            lastAllocated = i;
            cout << "Process " << processId << " allocated to block " << memory[i].id << " using Next Fit." << endl;
            return;
        }
    }

    for (int i = 0; i < lastAllocated; ++i) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            memory[i].allocated = true;
            lastAllocated = i;
            cout << "Process " << processId << " allocated to block " << memory[i].id << " using Next Fit." << endl;
            return;
        }
    }

    cout << "Process " << processId << " cannot be allocated using Next Fit." << endl;
}

void worstFit(vector<Block>& memory, int processId, int processSize) {
    int worstFitIndex = -1;
    int maxBlockSize = INT_MIN;

    for (int i = 0; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= processSize && memory[i].size > maxBlockSize) {
            worstFitIndex = i;
            maxBlockSize = memory[i].size;
        }
    }

    if (worstFitIndex != -1) {
        memory[worstFitIndex].allocated = true;
        cout << "Process " << processId << " allocated to block " << memory[worstFitIndex].id << " using Worst Fit." << endl;
    } else {
        cout << "Process " << processId << " cannot be allocated using Worst Fit." << endl;
    }
}

int main() {
    int memorySize, blockSize, processCount;
    cout << "Enter the memory size: ";
    cin >> memorySize;
    cout << "Enter the number of blocks: ";
    cin >> blockSize;
    cout << "Enter the number of processes: ";
    cin >> processCount;

    vector<Block> memory(blockSize);
    for (int i = 0; i < blockSize; ++i) {
        memory[i].id = i + 1;
        memory[i].size = memorySize / blockSize;
        memory[i].allocated = false;
    }

    int lastAllocated = 0; // For Next Fit

    for (int i = 0; i < processCount; ++i) {
        int processId, processSize;
        cout << "Enter process ID and size: ";
        cin >> processId >> processSize;

        // First Fit
        firstFit(memory, processId, processSize);

        // Best Fit
        bestFit(memory, processId, processSize);

        // Next Fit
        nextFit(memory, lastAllocated, processId, processSize);

        // Worst Fit
        worstFit(memory, processId, processSize);
    }

    return 0;
}
