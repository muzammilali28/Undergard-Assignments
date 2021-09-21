#include<stdio.h>
#include<stdbool.h>

int main()
{
	int integer;
	int *intptr;
	
	float flt;
	float *fltptr;
	
	double dbl;
	double *dblptr;
	
	char character;
	char *charptr;
	
	long lng;
	long *lngptr;
	
	bool boolean;
	bool *boolptr;
	
	void *Voidptr;
	
	printf("Size of Interger : %zu bytes\n",sizeof(integer));
	printf("Size of IntergerPTR : %zu bytes\n\n",sizeof(intptr));
	printf("Size of Float : %zu bytes\n",sizeof(flt));
	printf("Size of FloatPTR : %zu bytes\n\n",sizeof(fltptr));
	printf("Size of Double : %zu bytes\n",sizeof(dbl));
	printf("Size of DoublePTR : %zu bytes\n\n",sizeof(dblptr));
	printf("Size of Character : %zu bytes\n",sizeof(character));
	printf("Size of CharacterPTR : %zu bytes\n\n",sizeof(charptr));
	printf("Size of Long : %zu bytes\n",sizeof(lng));
	printf("Size of LongPTR : %zu bytes\n\n",sizeof(lngptr));
	printf("Size of Bool : %zu bytes\n",sizeof(boolean));
	printf("Size of BoolPTR : %zu bytes\n\n",sizeof(boolptr));
	printf("Size of VoidPTR : %zu bytes\n",sizeof(Voidptr));
	
	return 0;
}
