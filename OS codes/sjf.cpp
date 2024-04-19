#include<iostream>
using namespace std;

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

  //sort 
for(int i=0;i<n;i++){
int pos = i;
for(int j=i+1;j<n;j++){
 if(burst[j]<burst[pos])
     pos = j;
 }

 int temp;
 temp = burst[i];
 burst[i] = burst[pos];
 burst[pos] = temp;

 int temp2;
 temp2 = arrival[i];
 arrival[i] = arrival[pos];
 arrival[pos] = temp2;

 int temp1;
 temp1 = process[i];
 process[i] = process[pos];
 process[pos] = temp1;
}

  int wt[n];
  int tt[n];
  wt[0] = 0;
  for(int i=1;i<n;i++){
     wt[i] = burst[i-1] + wt[i-1];
  }
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