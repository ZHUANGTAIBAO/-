#include<stdio.h>
#include<stdlib.h> 

int IfTheSameColor(char *color);
int TheTypeOfCards(int *numb);


int main()
{		
	int i,j;
	int sign1=1 ,sign2= 1;
			
	struct players
	{
			char card[5][3];
	};
	struct players player[2];
	
	
	
	for(j=0;j<2;j++) 
	{
		if (sign1 == 1) 	{printf("Black:\n");sign1=0;}
		
		for(i=0;i<5;i++)
			{
				scanf("%s",&player[j].card[i]);
			}
		if (sign2 == 1)	{printf("White:\n");sign2=0;}	
			
	}	
	
	printf("\n");
		
		
	
	struct turecards
	{
		int numb[5];
		char color[5];
	};
	struct turecards tplayer[2];
	
	
	
	
	for(j=0;j<2;j++)//获取卡牌上的点数 
	{
			for(i=0;i<5;i++)
		{	
		
				if(player[j].card[i][0] == '1' && player[j].card[i][1] == '0') //特别关注卡牌为10的数字 
				{
						tplayer[j].numb[i] = 10 ;
						player[j].card[i][1] = player[j].card[i][2]; 
				}
			
			
			
				else if( player[j].card[i][0]== 'A' || player[j].card[i][0] =='J' || player[j].card[i][0] =='Q' || player[j].card[i][0] =='K') //JQKA情况下 
				{
				switch (player[j].card[i][0])
					{
						case 'A' :
						tplayer[j].numb[i] = 14;break;
				
						case 'J' :
						tplayer[j].numb[i] = 11;break;	
				
						case 'Q' :
						tplayer[j].numb[i] = 12;break;	
				
						case 'K' :
						tplayer[j].numb[i] = 13;break;	
					}
				}		
		
				else 
				{
					tplayer[j].numb[i] = player[j].card[i][0] - '0';
				}
		}	
	}
			
		
		
	 
	 int temp,k; //卡牌点数排序 
	 for(j=0;j<2;j++)
	 {
	 	for(i=0;i<5;i++)
		 	{
	 		for(k=i+1;k<5;k++)
	 			{
	 				if(tplayer[j].numb[i] < tplayer[j].numb[k])
	 					{
	 						temp = tplayer[j].numb[i] ;
	 						tplayer[j].numb[i] = tplayer[j].numb[k] ;
	 						tplayer[j].numb[k] = temp ;	
						}
		 		}
	 		}	
	 }
	 
	 
	 
	 for(j=0;j<2;j++)//获取卡牌花色 
	 {
	 	for(i=0;i<5;i++)
	 		{
	 			tplayer[j].color[i] = player[j].card[i][1]; 
			}
	} 




//比较卡牌类型并排序 
	int type[2]; 

	for(j=0;j<2;j++)
	{
		char *color = tplayer[j].color;
		int *numb = tplayer[j].numb;
		
		
		if ( IfTheSameColor(tplayer[j].color)  )
	
		{
			if (TheTypeOfCards(tplayer[j].numb) == 4) 		type[j] = 6; //同花顺 
			else type[j] = 5;			 //同花 
		}
	
		else 
		type[j] = TheTypeOfCards(tplayer[j].numb);		
		
		
	}

	
	//判定输赢 
	if (type[0] == type[1]) 
	{
		for (i=0;i<5;i++)
		{
			if(tplayer[0].numb[i] == tplayer[1].numb[i])
				continue;
			else if (tplayer[0].numb[i] > tplayer[1].numb[i]  )  
				{
					printf("Black wins\n");
					break;
				}
			else if (tplayer[0].numb[i] < tplayer[1].numb[i]  )
				{
					printf("White wins\n");	
					break;
				}
		}		
		if (i == 5 )
			printf("Tie\n");
	}
	
	
	else if(type[0] > type[1])
		printf("Black wins\n");
	
	else
		printf("White wins\n");	
	
	 
	return 0;
 } 






int TheTypeOfCards(int *numb)//判定卡牌点数类型并排序 

{

	int i,result[4];

	int type =0 ;//type不改变即为散牌 
	
	
		for(i=0;i<4;i++)
		{
			result[i] = numb[i]-numb[i+1];
		}
	
	
	if(result[0] == 1 & result[1] == 1 && result[2] == 1 && result[3] == 1)
		type = 4; //顺子 
		
			
		for(i=0;i<3;i++)
	{
		if(result[i] == 0 && result[i+1]==0 )
		type = 3; //三条 
	}	
	

	{
		if( (result[0] == 0 && result [2] == 0 ) || (result[0] == 0 && result[3] ==0) || (result[1] ==0 && result[3] == 0) )
		type = 2; //俩对子 
	}
	
	for(i=0;i<4;i++)
	{
		if (result[i] == 0 && result[i+1] != 0 && result[i+2]!=0 && result[i+3]!=0 )
		type = 1; //单对子 
	 } 
	 
	return type;

}



int IfTheSameColor(char *color) //判定五张卡牌是否同色 
{
	 
	int i = 0;
	for(i=0;i<4;i++)
	{
		if(color[i] != color[i+1])
		{
			return 0;
			break;
		}
		return 1;
	}
}
