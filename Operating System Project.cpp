#include <iostream>
using namespace std;

int firstcome_firstserve(int n, int waiting_time[],int burst_time[]){
	
	
	int total_waiting_time = 0, average_waiting_time;
	cout<<"\nScheduling Method: First Come First Served"
	      "\n   Process Waiting Times:";
	      
	  //Calculating waiting time     
	for(int y = 0; y < n; y++){
	     cout<<"\n\tP"<<y+1<<": "<<waiting_time[y]<<" ms";
	     waiting_time[y + 1] = burst_time[y] + waiting_time[y];
	     total_waiting_time += waiting_time[y];
     };
     
     //Calculating average waiting time
     average_waiting_time =  (double)(1.0*total_waiting_time)/(double) (1.0 * n) ;
     
      return average_waiting_time;
};

int sjf_none(int n,int waiting_time[], int burst_time[]){
	int i,j,temp;
	int total_waiting_time = 0,average_waiting_time2;
	 
	cout<<"\nScheduling Method: Shortest Job First - None-Preemptive"
	       "\n Process Waiting Times:";
	//bubble_sort
	 for(i = 0; i<n; i++){
	 	for( j = i+1; j<n; j++){
	 		if(burst_time[j] < burst_time[i]){
	 			temp = burst_time[i];
	 			burst_time[i] = burst_time[j];
	 			burst_time[j] = temp;
			 }
	    }
	 }
	 for(i = 0; i<n; i++){
	    //	cout<<"\n"<<burst_time[i]<<"\t";
	 	cout<<"\n\tP"<<i+1<<": "<<waiting_time[i]<<" ms";
	 	waiting_time[i + 1] = burst_time[i] + waiting_time[i];
	 	total_waiting_time += waiting_time[i];
	 }
	  
	  //Calculating average waiting time
	  average_waiting_time2 = (double)(1.0 *total_waiting_time) /(double)(1.0 *n);
	  return average_waiting_time2;
}

int round_robin_scheduling(int n,int waiting_time[],int burst_time[],int time_quantum){
	bool result;
	int remaining_time[n];
	int t = 0,total_waiting_time= 0,average_waiting_time3;
	
	cout<<"\nScheduling Method: Round Robin Scheduling - time_quatum = 2"
	       "\n Process Waiting Times: ";
	       
	for(int i = 0; i<n; i++)
	   remaining_time[i] = burst_time[i];
	   
	while(1){
		result = true;
		for(int i = 0; i <n; i++){
			cout<<"\n\tP"<<i+1<<": ";
			if(remaining_time[i] > 0){
				result = false;
			if(remaining_time[i] > time_quantum){
				t += time_quantum;
				remaining_time[i] -= time_quantum;
				cout<<remaining_time[i]<<" ms";
			}
			else{
			    t += remaining_time[i];
				waiting_time[i] = t - burst_time[i];
				cout<<waiting_time[i]<<" ms";
				remaining_time[i] = 0;	
			}
		}
	} 
	
	if(result == true)
	   break;
    }
	  
	  //Calculating average waiting time
	  for(int i = 0; i < n; i++){
	  	total_waiting_time += waiting_time[i];
	  }
	  
	  average_waiting_time3 = (double)(1.0 * total_waiting_time)/ (double)(1.0 * n);
	  return average_waiting_time3;
}


int main (void){
	
	int burst_time[] = {10,5};
	int arrival_time[] = {0,0};
	int priority[] = {0,0};
	int waiting_time[] = {0};
	int time_quantum = 2;
	int size = sizeof burst_time / sizeof burst_time[0];
	double awt,awt2,awt3;
	
	for(int i = 0; i <size ; i++){
		cout<<"\n\t\t"<<burst_time[i]<<":"<<arrival_time[i]<<":"<<priority[i];
	}
	
	
    int x;

 		cout<<"\n\n\t\t\t CPU Scheduler Simulator"
 		     "\n\t 1. Scheduling Method(None)"
 		     "\n\t 2. Preemptive Mode(Off)"
 		     "\n\t 3. Show Result"
 		     "\n\t 4. End Program"
			 "\n\n\t Option > ";
 		     
	   
	  cin>>x;
	  
	  if( x == 1){
	  	awt = firstcome_firstserve(size,waiting_time,burst_time); 
	  	cout<<"\n\tAverage Waiting Time: "<<awt<<" ms";
	  	
	  	awt2 = sjf_none(size,waiting_time,burst_time);
	  	cout<<"\n\tAverage Waiting Time: "<<awt2<<" ms";
	  	
	  	awt3 = round_robin_scheduling(size,waiting_time,burst_time, time_quantum);
	  	cout<<"\n\tAverage Waiting Time: "<<awt3<<" ms";
	  	
	  }
	  
	 return 0;
};
