#include<iostream>
#include<fstream>
using namespace std;

void ReadFunction(ifstream&,int[],int[],int[]);
void FindMax(int[],int[],int[],int[]);
void FindMin(int[],int[],int[],int[]);
void FindDiff(int[],int[],int[]);
int SmallestDiff(int[],int&);

int main()
{
	int line1[10]={0},line2[10]={0},line3[10]={0};
	
	int Max[10]={0},Min[10]={0};
	
	int Diff[10]={0};
	
	ifstream fin;
	fin.open("file.txt");
	
	if(fin.is_open())
	{
		ReadFunction(fin,line1,line2,line3);
		
		FindMax(line1,line2,line3,Max);
	
		FindMin(line1,line2,line3,Min);
		
		FindDiff(Max,Min,Diff);
		
		int small=Diff[0];
		
		int smallest=0;
		smallest=SmallestDiff(Diff,small);
		
		cout<<"The Smallest Diff is "<<small<<" and Index : "<<smallest;
	}
	else
	{
		cout<<"File Not Found";
	}
	
	fin.close();
	
	return 0;
}
void ReadFunction(ifstream &fin , int line1[] , int line2[] , int line3[])
{
	int l1=0,l2=0,l3=0;
	
	for(int i=1; i<=30; i++)
	{
		if(i<=10)
		{
			fin>>line1[l1];
			l1++;
		}
		else if(i<=20)
		{
			fin>>line2[l2];
			l2++;
		}
		else if(i<=30)
		{
			fin>>line3[l3];
			l3++;
		}
	}
}
void FindMax(int line1[] , int line2[] , int line3[] , int Max[])
{ 
	int index=0;
	
	for(int i=0; i<10; i++)
	{
		if(line1[i]>=line2[i] && line1[i]>=line3[i])
		{
			Max[index]=line1[i];
			index++;
		}
		else if (line2[i]>=line1[i] && line2[i]>=line3[i])
		{
			Max[index]=line2[i];
			index++;
		}
		else if (line3[i]>=line1[i] && line3[i]>=line2[i])
		{
			Max[index]=line3[i];
			index++;
		}
	}
}
void FindMin(int line1[] , int line2[] , int line3[] , int Min[])
{
	int index=0;
	
	for(int i=0; i<10; i++)
	{
		if(line1[i]<=line2[i] && line1[i]<=line3[i])
		{
			Min[index]=line1[i];
			index++;
		}
		else if (line2[i]<=line1[i] && line2[i]<=line3[i])
		{
			Min[index]=line2[i];
			index++;
		}
		else if (line3[i]<=line1[i] && line3[i]<=line2[i])
		{
			Min[index]=line3[i];
			index++;
		}
	}
}
void FindDiff(int Max[], int Min[] , int Diff[])
{
	int diff=0,index=0;
	
	for(int i=0; i<10; i++)
	{
		diff=Max[i]-Min[i];
		
		Diff[index]=diff;
		index++;
	}
}
int SmallestDiff(int Diff[],int &small)
{
	for(int i=0; i<10; i++)
	{
		if(small>Diff[i])
		{
			small=Diff[i];
		}
	}
	
	int count=0;
	
	for(int j=0; Diff[j]!=small; j++)
	{
		count++;
	}
	
	return count;
}
