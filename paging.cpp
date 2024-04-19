#include <bits/stdc++.h>


using namespace std;

int FCFS(const vector<int>& pages, int frameSize) {
    int pageFaults = 0;
    unordered_map<int, bool> inMemory;

    queue<int> pageQueue;
    for (int i = 0; i < pages.size(); ++i) {
        if (!inMemory[pages[i]]) {
            pageFaults++;
            if (pageQueue.size() == frameSize) {
                inMemory[pageQueue.front()] = false;
                pageQueue.pop();
            }
            inMemory[pages[i]] = true;
            pageQueue.push(pages[i]);
        }
    }

    return pageFaults;
}

int LRU(const vector<int>& pages, int frameSize) {
    int pageFaults = 0;
    unordered_map<int, int> indexMap;
    vector<int> frames;

    for (int i = 0; i < pages.size(); ++i) {
        if (indexMap.find(pages[i]) != indexMap.end()) {
            frames.erase(frames.begin() + indexMap[pages[i]]);
        } else {
            pageFaults++;
            if (frames.size() == frameSize) {
                indexMap.erase(frames.back());
                frames.pop_back();
            }
        }
        frames.insert(frames.begin(), pages[i]);
        indexMap[pages[i]] = 0;
        for (int j = 1; j < frames.size(); ++j) {
            indexMap[frames[j]]++;
        }
    }

    return pageFaults;
}

int Optimal(const vector<int>& pages, int frameSize) {
    int pageFaults = 0;
    unordered_map<int, int> nextOccurrence;
    vector<int> frames;

    for (int i = 0; i < pages.size(); ++i) {
        if (nextOccurrence.find(pages[i]) == nextOccurrence.end()) {
            nextOccurrence[pages[i]] = i;
        }

        if (find(frames.begin(), frames.end(), pages[i]) == frames.end()) {
            pageFaults++;
            if (frames.size() < frameSize) {
                frames.push_back(pages[i]);
            } else {
                int farthest = 0, farthestIndex = 0;
                for (int j = 0; j < frames.size(); ++j) {
                    if (nextOccurrence[frames[j]] > farthest) {
                        farthest = nextOccurrence[frames[j]];
                        farthestIndex = j;
                    }
                }
                frames[farthestIndex] = pages[i];
            }
        }
    }

    return pageFaults;
}

int main() {
    int numPages, frameSize;
    cout << "Enter the number of pages: ";
    cin >> numPages;
    cout << "Enter the frame size: ";
    cin >> frameSize;

    vector<int> pages(numPages);
    cout << "Enter the page reference sequence: ";
    for (int i = 0; i < numPages; ++i) {
        cin >> pages[i];
    }

    cout << "FCFS Page Faults: " << FCFS(pages, frameSize) << endl;
    cout << "LRU Page Faults: " << LRU(pages, frameSize) << endl;
    cout << "Optimal Page Faults: " << Optimal(pages, frameSize) << endl;

    return 0;
}
