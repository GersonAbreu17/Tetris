#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <conio2.h>
#include <time.h>

struct tpBloco
{
	int x[4], y[4], id, r, xp, yp;
};

struct tpJogo
{
	float speed, vel;
	int score;
	int next;
	bool run;
};

void d0(int x, int y)
{
	x+= 24;
	y+= 4;
	gotoxy(x*2+1, y+1);
	printf("  ");
}

void d1(int x, int y, int color)
{
	x+= 24;
	y+= 4;
	gotoxy(x*2+1, y+1);
	if(color == 6)
		textbackground(13);
	else if(color == 7)
		textbackground(9);
	else
		textbackground(color);
	printf("' ");
	textbackground(0);
}

void d2(int x, int y, int color)
{
	x+= 24;
	y+= 4;
	gotoxy(x*2+1, y+1);
	if(color == 6)
		textbackground(13);
	else if(color == 7)
		textbackground(9);
	else
		textbackground(color);
	printf("' ");
	textbackground(0);
}

void inicio(int matriz[10][20])
{
	srand( (unsigned)time(NULL) );
	
	for(int i=0;i<10;i++)
		for(int j=0;j<20;j++)
			matriz[i][j] = 0;
	
	textbackground(4);
	clrscr();
	textbackground(0);
	
	for(int i=0;i<10;i++)
		for(int j=0;j<20;j++)
			d0(i,j);
}

void rotacoes(tpBloco &bloco)
{
	if(bloco.id == 0)
	{
		//[][]
		//[][]
		//
		//
		bloco.x[0] = bloco.xp + 0;
		bloco.y[0] = bloco.yp + 0;
		
		bloco.x[1] = bloco.xp + 1;
		bloco.y[1] = bloco.yp + 0;
		
		bloco.x[2] = bloco.xp + 0;
		bloco.y[2] = bloco.yp + 1;
		
		bloco.x[3] = bloco.xp + 1;
		bloco.y[3] = bloco.yp + 1;
	}
	if(bloco.id == 1)
	{
		if(bloco.r == 0)
		{
			//[]
			//[][][]
			//
			//
			bloco.x[0] = bloco.xp + 0;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 0;
			bloco.y[1] = bloco.yp + 1;
			
			bloco.x[2] = bloco.xp + 1;
			bloco.y[2] = bloco.yp + 1;
			
			bloco.x[3] = bloco.xp + 2;
			bloco.y[3] = bloco.yp + 1;
		}
		else if(bloco.r == 1)
		{
			//[][]
			//[]
			//[]
			//
			bloco.x[0] = bloco.xp + 0;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 0;
			bloco.y[1] = bloco.yp + 1;
			
			bloco.x[2] = bloco.xp + 0;
			bloco.y[2] = bloco.yp + 2;
			
			bloco.x[3] = bloco.xp + 1;
			bloco.y[3] = bloco.yp + 0;
		}
		else if(bloco.r == 2)
		{
			//[][][]
			//    []
			//
			//
			bloco.x[0] = bloco.xp + 0;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 1;
			bloco.y[1] = bloco.yp + 0;
			
			bloco.x[2] = bloco.xp + 2;
			bloco.y[2] = bloco.yp + 0;
			
			bloco.x[3] = bloco.xp + 2;
			bloco.y[3] = bloco.yp + 1;
		}
		else if(bloco.r == 3)
		{
			//  []
			//  []
			//[][]
			//
			bloco.x[0] = bloco.xp + 1;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 1;
			bloco.y[1] = bloco.yp + 1;
			
			bloco.x[2] = bloco.xp + 1;
			bloco.y[2] = bloco.yp + 2;
			
			bloco.x[3] = bloco.xp + 0;
			bloco.y[3] = bloco.yp + 2;
		}
	}
	else if(bloco.id == 2)
	{
		if(bloco.r == 0)
		{
			//[][][]
			//[]
			//
			//
			bloco.x[0] = bloco.xp + 0;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 1;
			bloco.y[1] = bloco.yp + 0;
			
			bloco.x[2] = bloco.xp + 2;
			bloco.y[2] = bloco.yp + 0;
			
			bloco.x[3] = bloco.xp + 0;
			bloco.y[3] = bloco.yp + 1;
		}
		else if(bloco.r == 1)
		{
			//[][]
			//  []
			//  []
			//
			bloco.x[0] = bloco.xp + 0;
			bloco.y[0] = bloco.yp + 0;
			bloco.x[1] = bloco.xp + 1;
			bloco.y[1] = bloco.yp + 0;
			bloco.x[2] = bloco.xp + 1;
			bloco.y[2] = bloco.yp + 1;
			bloco.x[3] = bloco.xp + 1;
			bloco.y[3] = bloco.yp + 2;
		}
		else if(bloco.r == 2)
		{
			//    []
			//[][][]
			//
			//
			bloco.x[0] = bloco.xp + 2;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 0;
			bloco.y[1] = bloco.yp + 1;
			
			bloco.x[2] = bloco.xp + 1;
			bloco.y[2] = bloco.yp + 1;
			
			bloco.x[3] = bloco.xp + 2;
			bloco.y[3] = bloco.yp + 1;
		}
		else if(bloco.r == 3)
		{
			//[]
			//[]
			//[][]
			//
			bloco.x[0] = bloco.xp + 0;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 0;
			bloco.y[1] = bloco.yp + 1;
			
			bloco.x[2] = bloco.xp + 0;
			bloco.y[2] = bloco.yp + 2;
			
			bloco.x[3] = bloco.xp + 1;
			bloco.y[3] = bloco.yp + 2;
		}
	}
	else if(bloco.id == 3)
	{
		if(bloco.r == 0 || bloco.r == 2)
		{
			//[][]
			//  [][]
			//
			//
			bloco.x[0] = bloco.xp + 0;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 1;
			bloco.y[1] = bloco.yp + 0;
			
			bloco.x[2] = bloco.xp + 1;
			bloco.y[2] = bloco.yp + 1;
			
			bloco.x[3] = bloco.xp + 2;
			bloco.y[3] = bloco.yp + 1;
		}
		else if(bloco.r == 1 || bloco.r == 3)
		{
			//  []
			//[][]
			//[]
			//
			bloco.x[0] = bloco.xp + 1;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 1;
			bloco.y[1] = bloco.yp + 1;
			
			bloco.x[2] = bloco.xp + 0;
			bloco.y[2] = bloco.yp + 1;
			
			bloco.x[3] = bloco.xp + 0;
			bloco.y[3] = bloco.yp + 2;
		}
	}
	else if(bloco.id == 4)
	{
		if(bloco.r == 0 || bloco.r == 2)
		{
			//  [][]
			//[][]
			//
			//
			bloco.x[0] = bloco.xp + 1;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 2;
			bloco.y[1] = bloco.yp + 0;
			
			bloco.x[2] = bloco.xp + 0;
			bloco.y[2] = bloco.yp + 1;
			
			bloco.x[3] = bloco.xp + 1;
			bloco.y[3] = bloco.yp + 1;
		}
		else if(bloco.r == 1 || bloco.r == 3)
		{
			//[]
			//[][]
			//  []
			//
			bloco.x[0] = bloco.xp + 0;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 0;
			bloco.y[1] = bloco.yp + 1;
			
			bloco.x[2] = bloco.xp + 1;
			bloco.y[2] = bloco.yp + 1;
			
			bloco.x[3] = bloco.xp + 1;
			bloco.y[3] = bloco.yp + 2;
		}
	}
	else if(bloco.id == 5)
	{
		if(bloco.r == 0 || bloco.r == 2)
		{
			//[][][][]
			//
			//
			//
			bloco.x[0] = bloco.xp + 0;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 1;
			bloco.y[1] = bloco.yp + 0;
			
			bloco.x[2] = bloco.xp + 2;
			bloco.y[2] = bloco.yp + 0;
			
			bloco.x[3] = bloco.xp + 3;
			bloco.y[3] = bloco.yp + 0;
		}
		else if(bloco.r == 1 || bloco.r == 3)
		{
			//[]
			//[]
			//[]
			//[]
			bloco.x[0] = bloco.xp + 0;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 0;
			bloco.y[1] = bloco.yp + 1;
			
			bloco.x[2] = bloco.xp + 0;
			bloco.y[2] = bloco.yp + 2;
			
			bloco.x[3] = bloco.xp + 0;
			bloco.y[3] = bloco.yp + 3;
		}
	}
	else if(bloco.id == 6)
	{
		if(bloco.r == 0)
		{
			//  []
			//[][][]
			//
			//
			bloco.x[0] = bloco.xp + 1;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 0;
			bloco.y[1] = bloco.yp + 1;
			
			bloco.x[2] = bloco.xp + 1;
			bloco.y[2] = bloco.yp + 1;
			
			bloco.x[3] = bloco.xp + 2;
			bloco.y[3] = bloco.yp + 1;
		}
		else if(bloco.r == 1)
		{
			//[]
			//[][]
			//[]
			//
			bloco.x[0] = bloco.xp + 0;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 0;
			bloco.y[1] = bloco.yp + 1;
			
			bloco.x[2] = bloco.xp + 1;
			bloco.y[2] = bloco.yp + 1;
			
			bloco.x[3] = bloco.xp + 0;
			bloco.y[3] = bloco.yp + 2;
		}
		else if(bloco.r == 2)
		{
			//[][][]
			//  []
			//
			//
			bloco.x[0] = bloco.xp + 0;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 1;
			bloco.y[1] = bloco.yp + 0;
			
			bloco.x[2] = bloco.xp + 2;
			bloco.y[2] = bloco.yp + 0;
			
			bloco.x[3] = bloco.xp + 1;
			bloco.y[3] = bloco.yp + 1;
		}
		else if(bloco.r == 3)
		{
			//  []
			//[][]
			//  []
			//
			bloco.x[0] = bloco.xp + 1;
			bloco.y[0] = bloco.yp + 0;
			
			bloco.x[1] = bloco.xp + 0;
			bloco.y[1] = bloco.yp + 1;
			
			bloco.x[2] = bloco.xp + 1;
			bloco.y[2] = bloco.yp + 1;
			
			bloco.x[3] = bloco.xp + 1;
			bloco.y[3] = bloco.yp + 2;
		}
	}
}

void novoBloco(int matriz[10][20], tpBloco &bloco, tpJogo &game)
{
	bool flag = true;
	tpBloco aux;
	bloco.id = game.next;
	game.next = rand() %7;
	bloco.r = 0;
	if(bloco.id == 5)
	{
		bloco.xp = 3;
		bloco.yp = 0;
	}
	else
	{
		bloco.xp = 4;
		bloco.yp = 0;
	}
	rotacoes(bloco);
	for(int i=0;i<4;i++)
		if(matriz[bloco.x[i]][bloco.y[i]] != 0)
			flag = false;
	if(flag)
	{
		for(int i=0;i<4;i++)
			d1(bloco.x[i],bloco.y[i], bloco.id+1);
		
		aux.id = game.next;
		aux.r = 0;
		if(game.next != 0)
		{
			aux.xp = 0;
			aux.yp = 0;
		}
		else
		{
			aux.xp = 1;
			aux.yp = 0;
		}
		rotacoes(aux);
		for(int i=0;i<4;i++)
		{
			gotoxy(30,10+i);
			printf("            ");
		}
		for(int i=0;i<4;i++)
		{
			gotoxy(aux.x[i]*2+32,aux.y[i]+11);
			if(aux.id+1 == 6)
				textbackground(13);
			else if(aux.id+1 == 7)
				textbackground(9);
			else
				textbackground(aux.id+1);
			printf("' ");
			textbackground(0);
		}
		textcolor(15);
	}
	else
	{
		gotoxy(53, 3);
		printf(" Game over! ");
		game.run = false;
	}
}

bool busca(int matriz[10][20], int y)
{
	int i=0;
	while(i<10 && matriz[i][y] != 0)
		i++;
	if(i == 10)
		return true;
	return false;
}

void pontuar(int matriz[10][20], int y, tpJogo &game)
{
	int i,j,c=1;
	
	for(j=y;j>0 && c==1;j--)
	{
		c=0;
		for(i=0;i<10;i++)
		{
			matriz[i][j] = matriz[i][j-1];
			if(matriz[i][j-1] == 0)
				d0(i,j);
			else
			{
				c=1;
				d2(i,j,matriz[i][j]);
			}
		}
	}
	for(i=0;i<10;i++)
	{
		game.score+=1;
		matriz[i][j] = 0;
		d0(i,j);
	}
	game.vel*=0.98;
	gotoxy(38,6);
	printf("%.8d",game.score);
	gotoxy(38,8);
	printf("%f",game.vel);
}

void ordena(tpBloco &bloco)
{
	int TL = 4, x, y;
	for(int i=0;i<TL-1;i++)
	{
		for(int j=1;j<TL;j++)
		{
			if(bloco.y[i] > bloco.y[j])
			{
				x = bloco.x[i];
				y = bloco.y[i];
				bloco.x[i] = bloco.x[j];
				bloco.y[i] = bloco.y[j];
				bloco.x[j] = x;
				bloco.y[j] = y;
			}
		}
		TL--;
	}
}

void verificar(int matriz[10][20], tpBloco &bloco, tpJogo &game)
{
	int i;
	ordena(bloco);
	for(i=0;i<4;i++)
	{
		if(busca(matriz, bloco.y[i]))
			pontuar(matriz, bloco.y[i], game);
	}
}

void queda(int matriz[10][20], tpBloco &bloco, tpJogo &game)
{
	bool flag = 1;
	
	//Verificando se para ou continua
	for(int i=0;i<4;i++)
		if(bloco.y[i] == 19 || matriz[bloco.x[i]][bloco.y[i]+1] != 0)
			flag = 0;
	
	//descendo os blocos
	if(flag)
	{
		bloco.yp++;
		for(int i=0;i<4;i++)
		{
			d0(bloco.x[i], bloco.y[i]);
			bloco.y[i]++;
		}
		for(int i=0;i<4;i++)
		{
			d1(bloco.x[i], bloco.y[i], bloco.id+1);
		}
	}
	//parando os blocos
	else
	{
		for(int i=0;i<4;i++)
		{
			matriz[bloco.x[i]][bloco.y[i]] = bloco.id+1;
			d2(bloco.x[i], bloco.y[i], matriz[bloco.x[i]][bloco.y[i]]);
		}
		verificar(matriz,bloco, game);
		novoBloco(matriz, bloco, game);
	}
}

void direita(int matriz[10][20], tpBloco &bloco)
{
	bool flag = 1;
	
	//Verificando se move
	for(int i=0;i<4;i++)
		if(bloco.x[i] == 9 || matriz[bloco.x[i]+1][bloco.y[i]] != 0)
			flag = 0;
			
	//movendo os blocos
	if(flag)
	{
		bloco.xp++;
		for(int i=0;i<4;i++)
		{
			d0(bloco.x[i], bloco.y[i]);
			bloco.x[i]++;
		}
		for(int i=0;i<4;i++)
		{
			d1(bloco.x[i], bloco.y[i], bloco.id+1);
		}
	}
}

void esquerda(int matriz[10][20], tpBloco &bloco)
{
	bool flag = 1;
	
	//Verificando se move
	for(int i=0;i<4;i++)
		if(bloco.x[i] == 0 || matriz[bloco.x[i]-1][bloco.y[i]] != 0)
			flag = 0;
			
	//movendo os blocos
	if(flag)
	{
		bloco.xp--;
		for(int i=0;i<4;i++)
		{
			d0(bloco.x[i], bloco.y[i]);
			bloco.x[i]--;
		}
		for(int i=0;i<4;i++)
		{
			d1(bloco.x[i], bloco.y[i], bloco.id+1);
		}
	}
}

void giro(int matriz[10][20], tpBloco &bloco, int direcao)
{
	int r,i;
	bool flag = true;
	tpBloco aux;
	
	//verificando
	aux = bloco;
	
	if(direcao == 1)
	{
		aux.r++;
		if(aux.r == 4)
			aux.r = 0;
	}
	else
	{
		aux.r--;
		if(aux.r == -1)
			aux.r = 3;
	}
	rotacoes(aux);
	for(i=0;i<4;i++)
		if(matriz[aux.x[i]][aux.y[i]] != 0 || aux.x[i] < 0 || aux.x[i] > 9 || aux.y[i] < 0 || aux.y[i] > 19)
			flag = false;
	
	if(flag)
	{
		//girando
		for(i=0;i<4;i++)
		{
			d0(bloco.x[i],bloco.y[i]);
		}
		bloco = aux;
		for(i=0;i<4;i++)
			d1(bloco.x[i],bloco.y[i], bloco.id+1);
	}
}

int main()
{
	int matriz[10][20];
	char tecla;
	
	tpBloco bloco;
	
	tpJogo game;
	game.speed = 1;
	game.vel = 1;
	game.score = 0;
	clock_t f, i;
	
	inicio(matriz);
	
	game.next = rand()%7;
	game.run = true;
	
	gotoxy(30,6);
	printf(" Score: %d",game.score);
	printf("0000000 ");
	gotoxy(30,8);
	printf(" Delay: %f ",game.speed);
	
	for(int i=0;i<4;i++)
	{
		gotoxy(30,10+i);
		printf("            ");
	}
	gotoxy(30,10);
	
	novoBloco(matriz, bloco, game);
	
	i = clock();
	do
	{
		if(kbhit())
		{
		    tecla = toupper(getch());
		
		    switch(tecla)
			{
		        case 'S':
		        	game.speed = 0;
		            break;
		    	case 'D':
		    		direita(matriz, bloco);
		    		break;
		    	case 'A':
		    		esquerda(matriz, bloco);
		    		break;
		    	case 'M':
		    		giro(matriz, bloco, 1);
		    		break;
		    	case 'N':
		    		giro(matriz, bloco, 0);
		    		break;
		    }
		}
		f = clock();
		if(f > i + game.speed * CLOCKS_PER_SEC) // Queda do bloco
		{
			i = clock();
			queda(matriz, bloco, game);
		}
		game.speed = game.vel;
		gotoxy(120,30);
	}while(tecla != 27 && game.run);
	while(toupper(getch()) != 27)
		getch();
}


