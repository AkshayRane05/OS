//ASS7
#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> input={2,6,9,2,4,2,9,7};
  int frame_size=3;
  vector<int> frame(frame_size,-1);

//----FIFO---/////
  int remove=0;
  bool miss=true;
  int cnt=0;
  cout<<"\nFIFO:"<<endl;
  cout<<"page\tslot 1\tslot 2\tslot 3"<<endl;  
  for(int i=0;i<input.size();i++){
    miss=true;
    cout<<input[i]<<"\t";
    for(int j=0;j<frame_size;j++){
        if(input[i]==frame[j]){
            miss=false;
            cout<<"H\t"<<"I\t"<<"T"<<endl;
            break;
        }
    }
    if(miss){cnt++;
        frame[remove]=input[i];
        remove=(remove+1)%frame.size();
        cout<<frame[0]<<"\t"<<frame[1]<<"\t"<<frame[2]<<endl;
    }
  } 
  cout<<"Total page faults = "<<cnt<<endl;
///--------------------------------------------------///

//----LRU---/////
//   {2,6,9,2,4,2,1,7}
    int m=0;
    for(auto itr:input){
        m=max(m,itr);
    }

    vector<int> recent(m+1,-1);
    
    frame.clear();
    frame.resize(frame_size,-1);
    int temp,rmv;
    cnt=0;
    cout<<"\nLRU:"<<endl;
    cout<<"page\tslot 1\tslot 2\tslot 3"<<endl;  
    for(int i=0;i<input.size();i++){
    miss=true;
    cout<<input[i]<<"\t";
    for(int j=0;j<frame_size;j++){
        if(input[i]==frame[j]){
            miss=false;
            recent[frame[j]]=i;
            cout<<"H\t"<<"I\t"<<"T"<<endl;
            break;
        }
    }
    if(miss){cnt++;
        for(int j=0;j<frame_size;j++){
            if(frame[j]==-1){
                frame[j]=input[i];
                recent[frame[j]]=i;
                goto end;
            }
        }
        temp=recent[frame[0]],rmv=0;
        for(int j=1;j<frame_size;j++){
            if(recent[frame[j]]<temp){
                temp=recent[frame[j]];
                rmv=j;
            }
        }
        frame[rmv]=input[i];
        recent[frame[rmv]]=i;
        end:
        cout<<frame[0]<<"\t"<<frame[1]<<"\t"<<frame[2]<<endl;
    } 
  } 
  cout<<"Total page faults = "<<cnt<<endl;
///--------------------------------------------------///  

//----Optimal---/////
//   {2,6,9,2,4,2,1,7}

vector<queue<int>> buf(m+1);
for(int i=0;i<input.size();i++){
    buf[input[i]].push(i);
}

for(int i=0;i<input.size();i++){
    if(!buf[input[i]].empty()){
        cout<<buf[input[i]].front()<<" ";    
        // buf[input[i]].pop();
    }
}

recent.clear();
recent.resize(m+1,-1);
frame.clear();
frame.resize(frame_size,-1);
cnt=0;
cout<<"\nOptimal:"<<endl;
    cout<<"page\tslot 1\tslot 2\tslot 3"<<endl;  
    for(int i=0;i<input.size();i++){
    miss=true;
    cout<<input[i]<<"\t";
    for(int j=0;j<frame_size;j++){
        if(input[i]==frame[j]){
            miss=false;
            // recent[frame[j]]=i;
            cout<<"H\t"<<"I\t"<<"T"<<endl;
            break;
        }
    }
    if(miss){cnt++;
        for(int j=0;j<frame_size;j++){
            if(frame[j]==-1){
                frame[j]=input[i];
                // recent[frame[j]]=i;
                goto end1;
            }
        }
        temp=buf[frame[0]].front(),rmv=0;
        for(int j=1;j<frame_size;j++){
            // cout<<buf[frame[j]].front()<<" ";
            while(buf[frame[j]].front()<i && !buf[frame[j]].empty())buf[frame[j]].pop();

            if(buf[frame[j]].empty() || buf[frame[j]].front()>temp){
                temp=buf[frame[j]].front();
                rmv=j;
            }
        }//cout<<endl;
        frame[rmv]=input[i];
        // recent[frame[rmv]]=i;

        end1:
        cout<<frame[0]<<"\t"<<frame[1]<<"\t"<<frame[2]<<endl;
    } 
  } 
  cout<<"Total page faults = "<<cnt<<endl;

cout<<endl;
return 0;
}
