#include <stdio.h>
#include <stdlib.h>
#include "image.h"
int main() 
{

	char **im=image();
	int tarama[3][3]={0,1,0,  1,1,1,  0,1,0};
	int zaa[100][120];
	int kirpilmis[100][120];
	int biber[9];
	int son_sekil[100][120];
	int m,n,a,b,i,j,x,temp,temp1;
	

	for(a=0;a<100;a++)
		for(b=0;b<120;b++)
			zaa[a][b]=im[a][b];
		

	printf("%d",zaa[2][3]);
	for(a=0;a<100;a++)
	{
		for(b=0;b<120;b++)
		{
			biber[0]=zaa[a-1][b-1];
			biber[1]=zaa[a-1][b];
			biber[2]=zaa[a-1][b+1];
			biber[3]=zaa[a][b-1];
			biber[4]=zaa[a][b];
			biber[5]=zaa[a][b+1];
			biber[6]=zaa[a+1][b-1];
			biber[7]=zaa[a+1][b];
			biber[8]=zaa[a+1][b+1];	
				
			for (i = 0; i < 8; ++i)
			{
				for (j = 0; j < 8; ++j)
    			{
					if (biber[j] > biber[j+1])
					{
						temp = biber[j];
						temp1= biber[j+1];
						biber[j] = temp1;
						biber[j+1] = temp;
	  				}
     			}	
			}

			zaa[a][b]=biber[4];
		}
	}
	
	printf("%d",zaa[2][3]);
	
		for(i=0;i<100;i++)//100 satýr       resmi çizdiren for döngüsü
	{
		printf("\r\n");
		for(j=0;j<120;j++)//120 sütun
		{
			if(zaa[i][j]=='0') printf(" ");//48 0 ýn ascii kodu
			else printf("#");
		}
	}

	for(a=0;a<100;a++)
	{
		printf("\r\n");
		for(b=0;b<120;b++)
		{
			//kirpilmis[a][b]=((zaa[a][b])&&tarama[1][1])&&((zaa[a][b+1])&&tarama[1][2])&&((zaa[a][b-1])&&tarama[1][0])&&((zaa[a-1][b])&&tarama[0][1])&&((zaa[a+1][b])&&tarama[2][1]);
			kirpilmis[a][b]=((zaa[a][b])-48)*((zaa[a][b+1])-48)*((zaa[a][b-1])-48)*((zaa[a-1][b])-48)*((zaa[a+1][b])-48);
			son_sekil[a][b]=zaa[a][b]-kirpilmis[a][b];
			if(son_sekil[a][b]==49) printf("#");
			else printf(" ");
		}
	}

	return 0;
}

