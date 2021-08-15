#include<iostream>
#include<fstream>
using namespace std;

int size(char[],char[]);
void compare(char[],char[],char[],int[],ofstream&);
int length(char[]);
void output(int,int[],int,char[],ofstream&);

int main()
{
	char word1[10]={"word1.txt"};
	char names[10]={"names.txt"};
	char word[10]={'\0'};
	char name[10]={'\0'};
	int line[10]={0};
	
	ifstream fin;
	fin.open(word1);
	
	ofstream fout;
	fout.open("output.txt");
	
	int Size=size(word,word1);
	
	for(int i=0; i<Size; i++)
	{
		fin>>word;
		
		compare(word,name,names,line,fout);
	}
	
	fin.close();
	fout.close();
	
	return 0;
}
int size(char array[],char filename[])
{
	ifstream fin;
	fin.open(filename);
	
	int size=0;
	
	while(fin>>array)
	{
		size++;
	}
	
	fin.close();
	
	return size;
}
int length(char array[])
{
	int size=0;
	
	for(int i=0; array[i]!='\0'; i++)
	{
		size++;
	}
	
	return size;
}
void compare(char word[],char name[],char filename[],int line[],ofstream &fout)
{
	int check=0,count=0,lsize=0;
	
	ifstream fin;
	fin.open(filename);
	
	int Size=size(name,filename);
	
	for(int i=0; i<Size; i++)
	{
		fin>>name;
		
		check=0;
		
		if(length(name)==length(word))
		{
			for(int j=0; name[j]!='\0'; j++)
			{
				if(word[j]==name[j])
				{
					check++;
				}
			}
			
			if(check==length(name))
			{
				count++;
				
				line[lsize]=i+1;
				lsize++;
			}
		}
	}
	
	output(count,line,lsize,word,fout);
	
	fin.close();
}
void output(int count,int line[],int lsize,char word[],ofstream &fout)
{
	fout<<word<<" "<<count<<" ";
	
	for(int i=0; i<lsize; i++)
	{
		fout<<line[i]<<" ";
	}
	
	fout<<endl;
}
