#include<iostream>
#include<fstream>
using namespace std;

void ReadFunction(ifstream& , int[]);
int FindAverage(int[]);
void ReplaceAboveAverage(int[],int&);

int main()
{
	int arr[20]={0};
	
	ifstream fin;
	fin.open("file.txt");
	
	if(fin.is_open())
	{
	
		ReadFunction(fin, arr);
	
		int avg=0;
		avg=FindAverage(arr);
	
		ReplaceAboveAverage(arr,avg);
	
		cout<<"Output Array : ";
		for(int i=0; i<20; i++)
		{
			cout<<arr[i]<<" ";
		}
	}
	else
	{
		cout<<"File not found";
	}
	
	fin.close();
	
	return 0;
}
void ReadFunction(ifstream &fin , int arr[])
{
	for(int i=0; i<20; i++)
	{
		fin>>arr[i];
	}
}
int FindAverage(int arr[])
{
	int ttl=0,avg=0;
	
	for(int i=0; i<20; i++)
	{
		ttl=ttl+arr[i];
	}
	
	avg=ttl/20;
	
	return avg;
}
void ReplaceAboveAverage(int arr[],int &avg)
{
	for(int i=0; i<20; i++)
	{
		if(arr[i]>avg)
		{
			arr[i]=avg;
		}
		else
		{
			arr[i]=arr[i];
		}
	}
}
