//ASS8
#include <bits/stdc++.h>
using namespace std;

int nsize = 8;
int disk_size=200;

void FCFS(int arr[], int head)
{
	int seek_count = 0;
	int distance, cur_track;

	for (int i = 0; i < nsize; i++) {
		cur_track = arr[i];

		distance = abs(cur_track - head);

		seek_count += distance;

		head = cur_track;
	}

	cout << "Total number of seek operations = "<< seek_count << endl;

	cout << "Seek Sequence is" << endl;

	for (int i = 0; i < nsize; i++) {
		cout << arr[i];if(i<nsize-1) cout<< ",";
	}cout<<endl;
}

void SCAN(int arr[], int head, string direction)
{
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;
 
    if (direction == "left")
        left.push_back(0);
    else if (direction == "right")
        right.push_back(disk_size - 1);
 
    for (int i = 0; i < nsize; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }
 
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
 
    int run = 2;
    while (run--) {
        if (direction == "left") {
            for (int i = left.size() - 1; i >= 0; i--) {
                cur_track = left[i];
 
                seek_sequence.push_back(cur_track);
               
                distance = abs(cur_track - head);
 
                seek_count += distance;
 
                head = cur_track;
            }
            direction = "right";
        }
        else if (direction == "right") {
            for (int i = 0; i < right.size(); i++) {
                cur_track = right[i];

                seek_sequence.push_back(cur_track);
 
                distance = abs(cur_track - head);
 
                seek_count += distance;
 
                head = cur_track;
            }
            direction = "left";
        }
    }
 
    cout << "Total number of seek operations = "
         << seek_count << endl;
 
    cout << "Seek Sequence is" << endl;
 
    for (int i = 0; i < seek_sequence.size(); i++) {
        cout <<seek_sequence[i];if(i<seek_sequence.size()-1) cout<< ",";
    }cout<<endl;
}
 
void shortestSeekTimeFirst(int request[],int head, int n)
{
    vector<int> seeksequence(n,-1);
    int st=INT_MAX,next=0;
    vector<bool> visited(n,false);
    int sum=0;
    seeksequence[0]=50;
    for(int i=1;i<=n;i++){
      for(int j=0;j<n;j++){
        if(visited[j]==false && abs(head-request[j])<=st){
            st=abs(head-request[j]);
            next=j;
        }
      }
        seeksequence[i]=request[next];
        sum+=st;
        visited[next]=true;
        head=request[next];
        st=INT_MAX;
    }

    cout<<"seek operations = "<<sum<<endl;
    for(int i = 0; i <= n; i++) 
    {
        cout<<seeksequence[i];if(i<n)cout<< ",";
    }cout<<endl;
}

void CSCAN(int arr[], int head)
{
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;
 
 
    left.push_back(0);
    right.push_back(disk_size - 1);

    for (int i = 0; i < nsize; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }
 

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
 

    for (int i = 0; i < right.size(); i++) {
        cur_track = right[i];

        seek_sequence.push_back(cur_track);
  
        distance = abs(cur_track - head);

        seek_count += distance;
 
        head = cur_track;
    }
 

    head = 0;
 
    seek_count += (disk_size - 1);
 
    for (int i = 0; i < left.size(); i++) {
        cur_track = left[i];

        seek_sequence.push_back(cur_track);
 
        distance = abs(cur_track - head);
 
        seek_count += distance;
 
        head = cur_track;
    }
 
    cout << "Total number of seek operations = "
         << seek_count << endl;
 
    cout << "Seek Sequence is" << endl;
 
    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i];if(i<seek_sequence.size()-1) cout<< ",";
    }cout<<endl;
}

int main()
{

    int arr[nsize] = { 176, 79, 34, 60, 92, 11, 41, 114 };
    int head = 50;
  
    cout<<"Processes:\t";
    for(auto itr: arr){
        cout<<itr<<" ";
    }cout<<endl;

    cout<<"\nFCFS:"<<endl;
	FCFS(arr, head);
    cout<<"\nSSTF:"<<endl;
    shortestSeekTimeFirst(arr, 50, nsize);
    cout<<"\nSCAN:"<<endl;
    SCAN(arr,head,"right");
    cout<<"\nC-SCAN:"<<endl;
    CSCAN(arr,head);
    cout<<endl;
	return 0;
}
