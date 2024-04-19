#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int FIFO(int req[],int n,int head){
    int primary_movement = abs(req[0] - head);
    int total = 0;
    for(int i=0;i<n-1;i++){
       total += abs(req[i]-req[i+1]);
    }  
    return primary_movement+total;
}

int SSTF(int req[], int n, int head) {
    int total = 0;
    vector<int> requests(req, req + n);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        int temp = 9999999;
        int ci = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && abs(head - requests[j]) < temp) {
                temp = abs(head - requests[j]);
                ci = j;
            }
        }
        visited[ci] = true;
        total += temp;
        head = requests[ci];
    }
    return total;
}

int SCAN(int req[],int n,int md,int head,int dir){
    int ans = 0;
    if(dir==0){
      int a = abs(md-head);
      int minval = 999999;
      for(int i=0;i<n;i++){
        if(req[i]<minval){
            minval = req[i];
        }
      }
      int b = abs(md-minval);
      int c = a+b;
      ans = c;
    }
    else if(dir==1){
        int a = abs(head);
        int maxval = 0;
        for(int i=0;i<n;i++){
        if(req[i]>maxval){
            maxval = req[i];
        }
        }
        int b = abs(maxval);
        int c = a+b;
        ans = c;
    }
    return ans;
}

int CSCAN(int req[],int n,int md,int head,int dir){
    int ans = 0;
    //right
    if(dir==0){
        int temp = 0;
        for(int i=0;i<n;i++){
            if(req[i]<head && req[i]>temp){
                temp = req[i];
            }
        }
        int a = abs(head-md);
        int c = a + md + temp;
        ans = c;
    }
    //left
    else if(dir==1){
        int temp = 999999;
        for(int i=0;i<n;i++){
            if(req[i]>head && req[i]<temp){
                temp = req[i];
            }
        }
        int c = head + md + temp;
        ans = c; 
    }
    return ans;
}


int main() {
    int r_size = 7;
    int requests[] = {82,170,43,140,24,16,190};
    int requests2[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;
    int max_diskSize = 199; 

    cout << "FIFO: " << FIFO(requests,r_size, head) << endl;
    cout << "SSTF: " << SSTF(requests,r_size, head) << endl;
    // 0 means right, 1 means left
    cout << "SCAN: " << SCAN(requests,r_size,max_diskSize,head,0) << endl;
    cout << "SCAN: " << SCAN(requests2,r_size,max_diskSize,head,1) << endl;
    cout << "C-SCAN: " << CSCAN(requests,r_size,max_diskSize,head,0) << endl;
    cout << "C-SCAN: " << CSCAN(requests2,r_size,max_diskSize,head,0) << endl;
    return 0;
}
