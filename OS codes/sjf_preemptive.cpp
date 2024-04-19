#include<iostream>
using namespace std;

//waiting time of all process  
void findWaitingTime(int process[], int arrival[], int burst[], int wt[], int n) {  
   int rt[n];  
   for (int i = 0; i < n; i++)  
   rt[i] = burst[i];  
   int complete = 0, t = 0, minm = 9876543;  
   int shortest = 0, finish_time;  
   bool check = false;  
   while (complete != n) {  
      for (int j = 0; j < n; j++) {  
         if ((arrival[j] <= t) && (rt[j] < minm) && rt[j] > 0) {  
            minm = rt[j];  
            shortest = j;  
            check = true;  
         }  
      }  
      if (check == false) {  
         t++;  
         continue;  
      }  
      // decrementing the remaining time  
      rt[shortest]--;  
      minm = rt[shortest];  
      if (minm == 0)  
         minm = 9876543;  
         // If a process gets completely  
         // executed  
         if (rt[shortest] == 0) {  
            complete++;  
            check = false;  
            finish_time = t + 1;  
            // Calculate waiting time  
            wt[shortest] = finish_time -  
            burst[shortest] -  
            arrival[shortest];  
            if (wt[shortest] < 0)  
               wt[shortest] = 0;  
         }  
         // Increment time  
         t++;  
   }  
}

int main(){
  int n;
  cout<<"Enter the number of processes : ";
  cin>>n;
  int process[n];
   int arrival[n];
    int burst[n];
  cout<<"Enter the arrival time for processes : ";
  for(int i=0;i<n;i++){
     int x;
     cin>>x;
     process[i] = i+1;
     arrival[i] = x;
  }
  cout<<"Enter the burst time for processes : ";
  for(int i=0;i<n;i++){
     int y;
     cin>>y;
     burst[i] = y;
  }

   //sort the process
for(int i=0;i<n;i++){
int pos = i;
for(int j=i+1;j<n;j++){
 if(arrival[j]<arrival[pos])
     pos = j;
 }

 int temp;
 temp = arrival[i];
 arrival[i] = arrival[pos];
 arrival[pos] = temp;

 int temp1;
 temp1 = burst[i];
 burst[i] = burst[pos];
 burst[pos] = temp1;

 int temp2;
 temp2 = process[i];
 process[i] = process[pos];
 process[pos] = temp2;
}

  int wt[n];
  int tt[n];

  findWaitingTime(process,arrival,burst,wt,n);  

  //Turnaround Time
  for(int i=0;i<n;i++){
     tt[i] = wt[i] + burst[i];
  }
    float totalwt = 0;
  for(int i=0;i<n;i++){
    totalwt += wt[i];
  }
  float totaltt = 0;
  for(int i=0;i<n;i++){
    totaltt += tt[i];
  }
   cout<<"Process id"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Waiting Time"<<"\t"<<"Tunraround Time"<<endl;
   for(int i=0;i<n;i++){
    cout<<process[i]<<"\t\t"<<arrival[i]<<"\t\t"<<burst[i]<<"\t\t"<<wt[i]<<"\t\t"<<tt[i]<<endl;
  }
  cout<<"Average Waiting time for process is : ";
  float avgwt = totalwt/n;
  cout<<avgwt;
  cout<<"\n";
  cout<<"Average Turnaround time for process is : ";
  float avgtt = totaltt/n;
  cout<<avgtt;
  cout<<"\n";
  return 0;
}