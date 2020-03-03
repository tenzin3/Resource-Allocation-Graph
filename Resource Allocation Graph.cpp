#include<iostream>

using namespace std;

int main()
{
	// Can store maximum five resource with five instances
	int Resource[5][5];
	
	//Can store maximum five process with five request
	int Process[5][5];
	
	
	//Store the Resource Allocation Graph
	int Adjacency[10][10];
	
	//User input
	int Rno;
	cout<<"Enter the no of resource"<<endl;
	cin>>Rno;
	
	int Pno;
	cout<<"Enter the no of processes"<<endl;
	cin>>Pno;
	
	int N=Rno+Pno;
	
	//In the adjacency matrix, 
	//Resources vertex is stored first
	//Process vertex is stored next

	for(int k=0;k<N;k++)
	{
		for(int l=0;l<N;l++)
		Adjacency[k][l]=0;
	}
	
	int temp;
	
	
	//Entering the each of resource instances
	for (int i=0;i<Rno;i++)
	{
	   cout<<"Enter the no of instances for resource no"<<i+1<<endl;
	   cin>>temp;
	   cout<<"1.Enter process no if the instances is allocated"<<endl;
	   cout<<"2.Enter 0 if none is allocated"<<endl;
	   for (int j=0;j<temp;j++)
	   {
	      	cin>>Resource[i][j];
	      	
	      	//It is stored 1 in adjacency matrix, if the any instances is allocated in a resource
			if(Resource[i][j]!=0)
	      	{
	      		int temp_Pno=Resource[i][j];
	      	  	Adjacency[i][Rno+temp_Pno-1]=1;
			}
	   }	
	}
	
	//Entering each of process resouce
	for (int i=0;i<Pno;i++)
	{
	   cout<<"Enter the no of request for process no"<<i+1<<endl;
	   cin>>temp;
	   cout<<"Enter the resource numbers that are bieng requested"<<endl;
	   for (int j=0;j<temp;j++)
	   {
	      	cin>>Process[i][j];
	      	int temp_Rno=Process[i][j];
	      	Adjacency[Rno+i][temp_Rno-1]=1;
	   }	
	}
	
	//Showing the Resource Allocation Graph
	for (int m=0;m<N;m++)
	{
		for(int n=0;n<N;n++)
		cout<<Adjacency[m][n];
		
		cout<<endl;
	}
	
	
	
	
	return 0;
}
