#include<iostream>
#include<fstream>
using namespace std;

void ReadFunction(ifstream&,int[],int[],int[]);
void FindSum(int[],int[],int[],int[]);
int LargestSum(int[]);

int main()
{
	int line1[10]={0},line2[10]={0},line3[10]={0};
	int sumArr[10]={0};
	
	ifstream fin;
	fin.open("file.txt");
	
	if(fin.is_open())
	{
		ReadFunction(fin,line1,line2,line3);
		
		FindSum(line1,line2,line3,sumArr);
		
		int index=0;
		index=LargestSum(sumArr);
		
		cout<<"Sum Array : ";
		for(int i=0; i<10; i++)
		{
			cout<<sumArr[i]<<" ";
		}
		
		cout<<endl<<"Max Sum (index): "<<index<<endl;
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
void FindSum(int line1[] , int line2[] , int line3[] , int sumArr[])
{
	int sum=0 , j=0;
	for(int i=0; i<10; i++)
	{
		sum=line1[i]+line2[i]+line3[i];
		
		sumArr[j]=sum;
		j++;
	}
}
int LargestSum(int sumArr[])
{
	int max=0,count=0;
	
	for(int i=0; i<10; i++)
	{
		if(sumArr[i]>max)
		{
			max=sumArr[i];
		}
	}
	
	for(int j=0; sumArr[j]!=max; j++)
	{
		count++;
	}
	
	return count;
}
