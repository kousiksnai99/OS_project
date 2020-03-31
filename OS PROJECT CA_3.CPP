
#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,i,j,avgw=0;
 float avgt=0,temp;
 int burst[10],wait[10],process[10];
 cout<<"\n\t\t\tProcess Scheduling(SJFS)\n";
 cout<<"\nEnter the number of process : ";
 cin>>n;
 cout<<"\nEnter the Burst time\n";

for(i=0;i<n;i++)
 {
 	cout<<"Burst time P"<<i+1<<" : ";
    cin>>burst[i];
    process[i] = i;
 }

for(i=0;i<n;i++)

 {
   for(j=i;j<n;j++)

    {
      if(burst[i]>burst[j])

        {
        temp = burst[i];

        burst[i] = burst[j];

        burst[j] = temp;

        temp = process[i];

        process[i] = process[j];

        process[j] = temp;
      }
   }
 }
 cout<<"---------------------------------\n";
 cout<<"Waiting time | Turn around time \n";

j=0;

for(i=0;i<n;i++)
 {
    wait[i] = j;
    j = burst[i] + j;
    cout<<"P"<<process[i]+1<<" : "<<wait[i]<<"\t     |   "<<wait[i]+burst[i]<<"\n";
    cout<<"-------------|-------------------\n";
    avgw+=wait[i];
    avgt+=wait[i]+burst[i];
 }
 cout<<"\n";
 cout<<"Average waiting time: "<<avgw/(float)n<<"\n";
 cout<<"Average Turn around time: "<<avgt/(float)n<<"\n";
 return 0;
}


