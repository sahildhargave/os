#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct MemoryBlock {
    int id;
    int size;
    bool allocated;
};

// Function to allocate memory using First Fit technique
void firstFit(vector<MemoryBlock>& memory, int blockSize, int id) {
    for (int i = 0; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= blockSize) {
            memory[i].allocated = true;
            memory[i].id = id;
            cout << "Memory block " << id << " allocated at position " << i << endl;
            return;
        }
    }
    cout << "Memory block " << id << " cannot be allocated." << endl;
}

// Function to allocate memory using Best Fit technique
void bestFit(vector<MemoryBlock>& memory, int blockSize, int id) {
    int bestFitIndex = -1;
    int minFragmentation = INT_MAX;
    for (int i = 0; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= blockSize) {
            int fragmentation = memory[i].size - blockSize;
            if (fragmentation < minFragmentation) {
                minFragmentation = fragmentation;
                bestFitIndex = i;
            }
        }
    }
    if (bestFitIndex != -1) {
        memory[bestFitIndex].allocated = true;
        memory[bestFitIndex].id = id;
        cout << "Memory block " << id << " allocated at position " << bestFitIndex << endl;
    } else {
        cout << "Memory block " << id << " cannot be allocated." << endl;
    }
}

// Function to allocate memory using Next Fit technique
void nextFit(vector<MemoryBlock>& memory, int blockSize, int id, int& nextFitIndex) {
    for (int i = nextFitIndex; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= blockSize) {
            memory[i].allocated = true;
            memory[i].id = id;
            cout << "Memory block " << id << " allocated at position " << i << endl;
            nextFitIndex = i + 1;
            return;
        }
    }
    // Wrap around if not found from nextFitIndex to end
    for (int i = 0; i < nextFitIndex; ++i) {
        if (!memory[i].allocated && memory[i].size >= blockSize) {
            memory[i].allocated = true;
            memory[i].id = id;
            cout << "Memory block " << id << " allocated at position " << i << endl;
            nextFitIndex = i + 1;
            return;
        }
    }
    cout << "Memory block " << id << " cannot be allocated." << endl;
}

// Function to allocate memory using Worst Fit technique
void worstFit(vector<MemoryBlock>& memory, int blockSize, int id) {
    int worstFitIndex = -1;
    int maxFragmentation = INT_MIN;
    for (int i = 0; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= blockSize) {
            int fragmentation = memory[i].size - blockSize;
            if (fragmentation > maxFragmentation) {
                maxFragmentation = fragmentation;
                worstFitIndex = i;
            }
        }
    }
    if (worstFitIndex != -1) {
        memory[worstFitIndex].allocated = true;
        memory[worstFitIndex].id = id;
        cout << "Memory block " << id << " allocated at position " << worstFitIndex << endl;
    } else {
        cout << "Memory block " << id << " cannot be allocated." << endl;
    }
}

int main() {
    int memorySize, blockSize;
    cout << "Enter total memory size: ";
    cin >> memorySize;
    cout << "Enter number of memory blocks: ";
    int numBlocks;
    cin >> numBlocks;
    vector<MemoryBlock> memory(numBlocks);
    for (int i = 0; i < numBlocks; ++i) {
        cout << "Enter size of block " << i+1 << ": ";
        cin >> memory[i].size;
        memory[i].allocated = false;
    }
    
    int choice;
    do {
        cout << "\nMemory Allocation Techniques:\n";
        cout << "1. First Fit\n";
        cout << "2. Best Fit\n";
        cout << "3. Next Fit\n";
        cout << "4. Worst Fit\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter size of block to allocate: ";
                cin >> blockSize;
                firstFit(memory, blockSize, choice);
                break;
            case 2:
                cout << "Enter size of block to allocate: ";
                cin >> blockSize;
                bestFit(memory, blockSize, choice);
                break;
            case 3:
                cout << "Enter size of block to allocate: ";
                cin >> blockSize;
                nextFit(memory, blockSize, choice, choice);
                break;
            case 4:
                cout << "Enter size of block to allocate: ";
                cin >> blockSize;
                worstFit(memory, blockSize, choice);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
