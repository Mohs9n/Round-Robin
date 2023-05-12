#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void printWaitingTimes(int arr[],int pnum){
    int sum=0;
    for (int i = 0; i < pnum; i++)
    {
        cout<<"P"<<i+1<<" waiting time: "<<arr[i]<<endl;
        sum+=arr[i];
    }
    double avg = (double)sum/(double)pnum;
    cout << "Average waiting time = "<<avg<<endl;
    cout <<endl;
}

void printGantt(vector<pair<int,int>> vec){
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<"-----";
    }
    cout<<endl;
    
    cout << "| ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout <<"P"<<vec[i].first<<" | ";
    }
    cout <<endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<"-----";
    }
    cout <<endl<<"0    ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout <<vec[i].second<<"   ";
    }
    
}

int main(){
   cout << "Please Enter the Quanum Number"<<endl;
   int quantum;cin>>quantum;
   cout << "Please Enter the Number of Processes"<<endl;
   int pnum;cin>>pnum;
   int bursT[pnum];
   int bursTFixed[pnum];
   int burstSum=0;
   for (int i=0;i<pnum;i++){
       if (i==0) cout << "Enter the " <<i+1<<"st Process"<<endl;
       else if (i==1) cout << "Enter the " <<i+1<<"nd Process"<<endl;
       else if (i==2) cout << "Enter the " <<i+1<<"rd Process"<<endl;
       else cout << "Enter the " <<i+1<<"th Process"<<endl;
       int tempBurst;cin>>tempBurst;
       bursT[i]=tempBurst;
       bursTFixed[i]=tempBurst;
       burstSum+=tempBurst;
   }

   int waitT=0;
   double pt= (double)burstSum/(double)quantum;
   int p = ceil(pt);

   vector<pair<int,int>> waitTimes;

   int Times[pnum];
   int i=0;
   int j=0;
   while(burstSum){
       i=i%pnum;
       if (bursT[i]==0) {
        i++;
        continue;
       }
       
       if (bursT[i]>quantum){
           waitT+=quantum;
           bursT[i]-=quantum;
	       burstSum-=quantum;
           waitTimes.push_back(make_pair(i+1,waitT));
       }else  {
            waitT+=bursT[i];
            burstSum-=bursT[i];
            Times[i]=waitT-bursTFixed[i];
            bursT[i]=0; 
            waitTimes.push_back(make_pair(i+1,waitT));
        }
        j++;i++;
   }

   printWaitingTimes(Times, pnum);
   printGantt(waitTimes);
}
