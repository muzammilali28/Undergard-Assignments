#include<iostream>
#include<fstream>
using namespace std;

int size(char[]);
int length(char[]);

int main()
{
	char textfromfile[50]={'\0'};
	
	ifstream fin;
	fin.open("datafile.txt");
	
	ofstream fout;
	fout.open("output.txt");
	
	if(!(fin.is_open()))
	{
		cout<<"File not found";
	}
	else
	{
		int Size=size(textfromfile);
	
	
		for(int i=0; i<Size; i++)
		{
			fin>>textfromfile;
		
			int l=length(textfromfile);
			
			fout<<textfromfile<<" : "<<l<<endl;
		}
	}
	
	fin.close();
	fout.close();
	
	return 0;
	
}
int size(char filesize[])
{
	ifstream fin;
	fin.open("datafile.txt");
	
	int size=0;
	
	while(fin>>filesize)
	{
		size++;
	}
	
	fin.close();
	
	return size;
}
int length(char word[])
{
	int l=0;
	
	for(int i=0; word[i]!='\0'; i++)
	{
		if(word[i]!=';' && word[i]!='.')
		{
			l++;
		}
	}
	
	return l;
}
