#include <bits/stdc++.h>
using namespace std;

/* A Linked list node */
struct Node {
	int burst_time;
	int arrival_time;
	int priority;
	struct Node* next;
};

int firstcome_firstserve(struct Node *head, int n, int waitingTime){
	 
	
	int total_waiting_time = 0, average_waiting_time;
	
	Node* temp = head;
	cout<<"\nScheduling Method: First Come First Served"
	      "\n   Process Waiting Times:";
	      
	  //Calculating waiting time     
	for(int y = 0; y < 2; y++){
	     
	     waitingTime = waitingTime + temp->burst_time;
	     cout<<"\n\tP"<<y+1<<": "<<waitingTime<<" ms";
	     temp = temp->next;
	     total_waiting_time += waitingTime;
	     
     };
     
     //Calculating average waiting time
     average_waiting_time =  (double)(1.0*total_waiting_time)/(double) (1.0 * n) ;
     
      return average_waiting_time;
};
// function to find the sum of
// nodes of the given linked list
int sumOfNodes(struct Node* head)
{
	struct Node* ptr = head;
	int sum = 0, n = 3;
	struct Node* *h;
	int waitingTime = 0;;
	 Node* cur1 = head;
     Node* cur2 = head;
     int total_waiting_time = 0, average_waiting_time;
     
     	cout<<"\nScheduling Method: Round Robin Scheduling - time_quatum = 2"
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
  
	 for(int i = 0; i< n - 1; i++){
	 	//while(ptr != NULL){
	 	
	 	waitingTime += ptr->burst_time;
	 	cout<<"\n\tP"<<i+1<<": "<<waitingTime<<" ms";
	 	ptr = ptr->next;
	 	total_waiting_time += waitingTime;
    
	// }
	 
}
	  cout<<"\nTotal Waiting Time: "<< total_waiting_time;
	  //Calculating average waiting time
	  average_waiting_time = (double)(1.0 *total_waiting_time) /(double)(1.0 * n);
	  return average_waiting_time;

	//return sum;
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
	for(int i = 0; i< 3; i++){
	
	  cout<<"\n"<<use->priority;
	  cout<<"\t"<<use->burst_time;
	  waitingTime = waitingTime + use->burst_time;
	  use = use->next;
	  total_waiting_time += waitingTime;
     }
     
     cout<<"\nTotal Waiting Time: "<<total_waiting_time;
	
     
    // Calculating average waiting time
     average_waiting_time =  (double)(1.0*total_waiting_time)/(double) (1.0 * n) ;
     
      return average_waiting_time;	    

}


int round_robin_scheduling(struct Node *head, int n,int waitingTime, int time_quantum){
	bool result;
	int remaining_time;
	int t = 0,total_waiting_time= 0,average_waiting_time3;
	
	Node* pot = head;//int waiting_time[] = {0};
	
	cout<<"\nScheduling Method: Round Robin Scheduling - time_quatum = 2"
	       "\n Process Waiting Times: ";
	       
	for(int i = 0; i<n; i++)
	   remaining_time = pot->burst_time;
	   
	while(1){
		result = true;
		for(int i = 0; i <n; i++){
			cout<<"\n\tP"<<i+1<<": ";
			if(remaining_time > 0){
				result = false;
			if(remaining_time > time_quantum){
				
				t += time_quantum;
				//remaining_time[i] -= time_quantum;
				remaining_time = remaining_time - time_quantum;
				cout<<t<<" ms";
			}
				
			else{
			    t += remaining_time;
				waitingTime = t - pot->burst_time;
				pot = pot->next;
				//cout<<t<<" ms";
				remaining_time = 0;	
			}
		}
	} 
	
	if(result == true)
	   break;
    }
	  
	  //Calculating average waiting time
	  for(int i = 0; i < n; i++){
	  	total_waiting_time += waitingTime;
	  }
	  
	  average_waiting_time3 = (double)(1.0 * total_waiting_time)/ (double)(1.0 * n);
	  return average_waiting_time3;
}



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
    int count = 0; 
    Node* current = head; 
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    } 
    return count; 
} 

// Driver program to test above
int main (void){
	
	double awt,awt2,awt3,awt4;
	int size;
	int waitingTime = 0;
	int time_quantum = 2;
	
	
	
	char choice;
	int n;
		
   	Node *head = new Node();
   	size = getCount(head);
   	
	
	//for(int i = 0; i<n; i++){
	while(true){
	cout<<"\nPress any character to end: ";
	cin>>choice;
		if(choice == 'q')
	   break;
	   
	push_back(&head);
		PrintList(head);
	
  }
    
    cout<<"Count of nodes is "<<size; 
	
	/*for(int i = 0; i <size ; i++){
		cout<<"\n\t\t"<<burst_time[i]<<":"<<arrival_time[i]<<":"<<priority[i];
	}*/
	
	
    int x;

 		cout<<"\n\n\t\t\t CPU Scheduler Simulator"
 		     "\n\t 1. Scheduling Method(None)"
 		     "\n\t 2. Preemptive Mode(Off)"
 		     "\n\t 3. Show Result"
 		     "\n\t 4. End Program"
			 "\n\n\t Option > ";
 		     
	   
	  cin>>x;
	  
	  if( x == 1){
	  	awt = firstcome_firstserve(head, size, waitingTime); 
	  	cout<<"\n\tAverage Waiting Time: "<<awt<<" ms";
	  	
	  	//awt2 = sjf_none(head, waitingTime, size);
	  		  //	cout<<"\n\tAverage Waiting Time: "<<awt2<<" ms";
	  	//awt2 = sumofNodes(head);
	  	cout<<"\n\tAverage Waiting Time: "<<sumOfNodes(head)<<" ms";
	  	awt3 = round_robin_scheduling(head,size, waitingTime,time_quantum);
	  	cout<<"\n\tAverage Waiting Time: "<<awt3<<" ms";
	  		
	  	awt4 = priority_none(head,waitingTime, size);
	  	cout<<"\n\tAverage Waiting Time: "<<awt4<<" ms";
	  }
	  
	  return 0;
}
