#include<iostream>
#include<algorithm>
using namespace std;

int min_ind(int b[], int j){
	 int indx;
	 indx= min_element(b, b+j+1)-b;
	 
	 while(b[indx]==0){
	 	b[indx] = 2000;
		indx= min_element(b, b+j+1)-b;
	 }
	 return indx;
}
void shortest_job_first(int n, int arrival_time[], int burst_time[]){
	int j,index_b,index_same=-1;
	for(j=0; j<n-1; j++){
		while(arrival_time[j]==arrival_time[j+1]){
			j++;
		}
		index_b = min_ind(burst_time, j);
		burst_time[index_b] -= arrival_time[j+1]-arrival_time[j];
		
		if(index_b != index_same){
			cout<<"J"<<index_b+1<<" ";
			index_same = index_b;
		}
	}
	index_b = min_ind(burst_time, n);
	while(burst_time[index_b]!=2000){
		if(index_b != index_same){
			cout<<"J"<<index_b+1<<" ";
			index_same = index_b;
		}
			burst_time[index_b] = 2000;
			index_b = min_ind(burst_time, n);
	}
}
int main(){
	int a[] = {0,1,2,3,4};
	int b[] = {3,1,3,2,1};
	
	shortest_job_first(5, a, b);
}
