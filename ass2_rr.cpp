//Ass2_Round Robin
#include<iostream>
#include<queue>
#include<numeric>
using namespace std;

struct process {
    int procN;
    int burstT;
    int arrT;
    int completionT;
};

int tq = 2;

void gant(struct process p[], int n) {
    int ct = 0;
    int burstT[n];
    int vis[n];
    for (int i=0;i<n;i++)
    {
      burstT[p[i].procN-1] = p[i].burstT;
      vis[p[i].procN-1]=0;
    }
    queue <int> q;
    int sum=0;
    while (accumulate(burstT,burstT+n,sum)!=0) 
    {
        for(int i=0;i<n;i++)
        {
          if(p[i].arrT<=ct && vis[p[i].procN-1]==0)
          {
            q.push(p[i].procN-1);
            vis[p[i].procN-1]=1;

          }
        }
        if (q.empty())
        {
            ct++;
        }
        else
        {
          int currProc = q.front();
          q.pop();
          if(burstT[currProc]>tq)
          {
            // printf("%d to %d Process %d\n ",ct,ct+tq,i+1);
            cout<<ct<<" to "<<ct+tq<<" Process "<<currProc+1<<"\n";
            burstT[currProc]-=tq;
            ct+=tq;
            p[currProc].completionT = ct;
            for(int i=0;i<n;i++)
        {
          if(p[i].arrT<=ct && vis[p[i].procN-1]==0)
          {
            q.push(p[i].procN-1);
            vis[p[i].procN-1]=1;

          }
        }
            q.push(currProc);
          }
          else if (burstT[currProc]>0)
          {
            // printf("%d to %d Process %d\n ",ct,ct+p[i].burstT,i+1);
            cout<<ct<<" to "<<ct+burstT[currProc]<<" Process "<<currProc+1<<"\n";
            ct+=burstT[currProc];
            burstT[currProc]=0;
            p[currProc].completionT = ct;
          }
        }

    }
}

void WaitTime(struct process p[], int wt[], int n) {
    for (int i = 0; i < n; i++) {
        wt[i] = p[i].completionT-p[i].arrT - p[i].burstT;
    }
    cout << "\n---Waiting Time for each Process is ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << p[i].procN << " -->" << wt[i] << endl;
    }
}

void TurnArTime(struct process p[], int wt[], int tat[], int n) {
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + p[i].burstT;
    }

    cout << "\n---Turn Around Time for each Process is ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << p[i].procN << " -->" << tat[i] << endl;
    }
}

void AvgT(int tat[], int wt[], int n) {
    int stat = 0, swt = 0;

    for (int i = 0; i < n; i++) {
        stat += tat[i];
        swt += wt[i];
    }

    cout << "Average Turn Around Time is " << stat * 1.0 / n << "\nAverage Waiting Time is " << swt * 1.0 / n << endl;
}

int main() {
  cout<<"In cpp"<<endl;
    cout << "\nEnter number of Processes to be Entered ->";
    int n;
    cin >> n;
    struct process p[n];
    int wt[n];
    int tat[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter Process No. , Burst Time , Arrival Time--> ";
        cin >> p[i].procN >> p[i].burstT>>p[i].arrT;
    }

    cout<<"Enter the Time Quantum to be considered :";
    cin>>tq;

    
  for(int i=n-1;i>=0;i--)
  {
    for (int j=0;j<i;j++)
    {
      if (p[j].arrT>p[j+1].arrT)
      {
        struct process a=p[j];
        p[j] = p[j+1];
        p[j+1] = a;
      }
    }
  }

    cout << "\n--The Processes Are--\n";

    for (int i = 0; i < n; i++) {
        cout << "The Process " << p[i].procN << " -->BT is " << p[i].burstT <<",--->AT is"<<p[i].arrT<< endl;
        wt[i] = 0;
    }

    gant(p, n);
    WaitTime(p, wt, n);
    TurnArTime(p, wt, tat, n);
    AvgT(tat, wt, n);

    return 0;
}
