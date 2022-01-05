//#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h> 

using namespace std;
//#include<stdio.h>

/* A Linked list node */
struct Node {
	int burst_time;
	int arrival_time;
	int priority;
	int wt;
	struct Node* next;
};

void push_back(struct Node **head){
	
	int newBurstTime;
	int newArrivalTime;
	int newPriority;
	
	Node *newNode = new Node();
	
	cout<<"Please enter burst time: ";
	cin>>newBurstTime;
	
	  
	cout<<" Please enter arrival time: ";
	cin>>newArrivalTime;
	
	cout<<"Please enter priority: ";
	cin>>newPriority;
	
	newNode->burst_time = newBurstTime;
	newNode->arrival_time = newArrivalTime;
	newNode->priority = newPriority;
	
	newNode->next = NULL;
	
	if(*head == NULL)
		*head = newNode;
     
     
    else{
    	Node* temp = *head;
    	while(temp->next != NULL)
    	  temp = temp->next;
    	  temp->next = newNode;
	} 	   
	
} 

void PrintList(struct Node *head){
	
   Node* temp = head;
   
   if(temp!= NULL){
   	  cout<<"\n\n\t\tThe data is collected";
   	  while(temp != NULL){
   	  	
   	  	cout<<"\n\t\t\t"<<temp->burst_time<<":"<<temp->arrival_time<<":"<<temp->priority;
   	  	      
   	  	      temp = temp->next;
		 }
		 
		 cout<<endl; 
	}
	else
	{
		cout<<"\nThe list is empty";
		
	}
   }

int getCount(Node* head) 
{ 
    int count = 0; // Initialize count 
    Node* current = head; // Initialize current 
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    } 
    return count; 
} 

int firstcome_firstserve(struct Node *head, int n,int waitingTime){
	 
	
	int total_waiting_time = 0, average_waiting_time;
	Node* pay = head;
	
	cout<<"\nScheduling Method: First Come First Served"
	      "\n   Process Waiting Times:";
	      
       for(int i = 0; i< n ; i++){
	 	cout<<"\n\tP"<<i+1<<": "<<waitingTime<<" ms";
	 	total_waiting_time += waitingTime;
	 	waitingTime += pay->burst_time;
	 	pay = pay->next;
	 	
}
	  cout<<"\nTotal Waiting Time: "<< total_waiting_time;
	  //Calculating average waiting time
	  average_waiting_time = (double)(1.0 *total_waiting_time) /(double)(1.0 * n);
	  return average_waiting_time;
};
// function to find the sum of
// nodes of the given linked list
int sjf_none(struct Node* head, int n,int waitingTime)
{
	struct Node* ptr = head;
	int sum = 0;
	struct Node* *h;
	//int waitingTime = 0;;
	 Node* cur1 = head;
     Node* cur2 = head;
     int total_waiting_time = 0, average_waiting_time;
     
     	cout<<"\nScheduling Method: Shortest Job First(None)"
	       "\n Process Waiting Times: ";
	 //bubble sort
	
	 for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (cur1->burst_time < cur2->burst_time ){
                int temp = cur1->burst_time;
                cur1->burst_time = cur2->burst_time;
                cur2->burst_time = temp;

            }
            cur2 = cur2->next;
        }
         cur2 = head;
         cur1 = head->next;
         for (int k = 0; k < i; k++) {
                cur1 = cur1->next;
         }
         
        
	} 
  
	 for(int i = 0; i< n ; i++){
	 	cout<<"\n\tP"<<i+1<<": "<<waitingTime<<" ms";
	 	total_waiting_time += waitingTime;
	 	waitingTime += ptr->burst_time;
	 	ptr = ptr->next;
	 	//total_waiting_time += waitingTime; 
}
	  cout<<"\nTotal Waiting Time: "<< total_waiting_time;
	  //Calculating average waiting time
	  average_waiting_time = (double)(1.0 *total_waiting_time) /(double)(1.0 * n);
	  return average_waiting_time;
}

int priority_none(struct Node *head, int waitingTime , int n){
	struct Node* *y;
	Node* use = head;
	Node* arr1 = head;
     Node* arr2 = head;
	int i,j,swapped;
	int total_waiting_time = 0;
	double average_waiting_time;
	
	cout<<"\nScheduling Method: Priority Scheduling - None-Preemptive"
	       "\n Process Waiting Times:";
	        //bubble sort descending order
  
  
   for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i- 1; j++) {
            if (arr1->priority < arr2->priority ){
                int lay = arr1->priority;
                arr1->priority = arr2->priority;
                arr2->priority = lay;

            }
            arr2 = arr2->next;
        }
         arr2 = head;
         arr1 = head->next;
         for (int k = 0; k < i; k++) {
                arr1 = arr1->next;
         }     
	} 
   cout<<"\nSorted list:";
   cout<<"\nProcesses\tPriority\tWaiting Time";
	for(int i = 0; i< n; i++){
	
	
	  cout<<"\nP"<<i+1<<": "<<"\t\t"<<use->priority;
	  cout<<"\t\t"<<waitingTime<<"ms";
	  total_waiting_time += waitingTime;
	  waitingTime = waitingTime + use->burst_time;
	  use = use->next;
	  
     }
     
     cout<<"\nTotal Waiting Time: "<<total_waiting_time;
	
     
    // Calculating average waiting time
     average_waiting_time =  (double)(1.0*total_waiting_time)/(double) (1.0 * n) ;
     
      return average_waiting_time;	    

}

 // Working on it
int round_robin_scheduling(struct Node *head, int waitingTime, int n, int time_quantum){
	
	Node* pal = head;
	int remainingTime[n];
	int wt[n];
	int total_waiting_time = 0, average_waiting_time;
		int rem_bt[n]; 
	for (int i = 0 ; i < n ; i++) 
		remainingTime[i] = pal->burst_time; 
	int t = 0; 
     
     	cout<<"\nScheduling Method: Round Robin Scheduling - None-Preemptive"
	       "\n Process Waiting Times:";
	while (1) 
	{ 
		bool done = true; 
		for (int i = 0 ; i < n; i++) 
		{ 
			if (remainingTime[i] > 0) 
			{ 
				done = false; 
				if (remainingTime[i] > time_quantum) 
				{ 
					t += time_quantum; 
					remainingTime[i] -= time_quantum; 
				} 
				else
				{ 
					t = t + remainingTime[i]; 
					wt[i] = t - pal->burst_time; 
					remainingTime[i] = 0; 
					pal->next;
				} 
			} 
		} 
		if (done == true) 
		break; 
	} 
	
	for (int i=0; i<n; i++) 
	{  
	    cout << "\n\tP" << i+1 << ": "<< wt[i] <<" ms"; 
		total_waiting_time += wt[i];
		wt[i] += pal->burst_time;
		
		pal = pal->next;
	} 
	
	 average_waiting_time =  (float)total_waiting_time / (float)n; 
	return average_waiting_time;
}


// Driver program to test above
int main (void){
	
	double awt,awt2,awt3,awt4;
	int size;
	int waitingTime = 0;
	int time_quantum = 2;			
	char choice;
	int n;
	
   	//Node *head = new Node();
   	Node* head = NULL;
   	
	//for(int i = 0; i<n; i++){
	while(true){
	cout<<"\nPress any character to continue or 'q' to quit: ";
	cin>>choice;
	
	if(choice == 'q')
	   break;
	   
	push_back(&head);
	PrintList(head);
	size = getCount(head);
  }
    
    cout<<"Count of nodes is "<<size; 
	
    int x;

 		cout<<"\n\n\t\t\t CPU Scheduler Simulator"
 		     "\n\t 1. Scheduling Method(None)"
 		     "\n\t 2. Preemptive Mode(Off)"
 		     "\n\t 3. End Program"
			 "\n\n\t Option > ";
 		     
	   
	  cin>>x;
	  
	  if( x == 1){
	  	awt = firstcome_firstserve(head, size,waitingTime); 
	  	cout<<"\n\tAverage Waiting Time: "<<awt<<" ms";
	  	
    	awt2 = sjf_none(head,size,waitingTime);
	  	cout<<"\n\tAverage Waiting Time: "<<awt2<<" ms";
	  	
	  	awt3 = priority_none(head,waitingTime, size);
	  	cout<<"\n\tAverage Waiting Time: "<<awt3<<" ms";
	  	
	  	awt4 = round_robin_scheduling(head,waitingTime,size,time_quantum);
	  	cout<<"\n\tAverage Waiting Time: "<<awt4<<" ms";
	  		
	  	
	  }
	  else if (x ==2){
	  	cout<<"Working on it";
	  }
	  
	  else if(x == 3)
	  
	    EXIT_SUCCESS;
	     
	  else
	   cout<<"Invalid Input";   
	    
	  
	  
	  
	  return 0;
}
