
#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#include <stdlib.h>
#include <winbgim.h>
#include <time.h>
#include <string>
#include <math.h>
#include <ctime>
#include <graphics.h>//
using namespace std;

#define MAXmat 9
#define MAXvec 9
#define latura 40
const int buttonCount = 4;
const int buttonWidth = 350;
const int buttonHeight = 60;
const int spacing = 40;
const int buttonCountVec = 10;
const int buttonCountMat = 23;


//----------------------------------------------------------------
// Structuri
struct Button {
    int x, y;
    const char* label;
};

struct matrice
{
    int x,y; // coordonate stanga sus
    int nrLin, nrCol;
    int long elem[MAXmat][MAXmat];
};
struct Vector
{
    int x, y;
    int dim;
    int val[MAXvec];
};
///Structuri
///-----------------------------------------------------------------------------
///Functii Calcul cu Matrici ...si chestii din astea

void InitMatSpec(matrice& K, int lin, int col, int xx, int yy, int impartitor, int rest)
{
    srand(time(NULL));
    K.nrLin=lin;
    K.nrCol=col;
    K.x=xx;
    K.y=yy;
    for (int i=1; i<=K.nrLin; i++)
        {cout<<endl;
        for (int j=1; j<=K.nrCol; j++)
            {K.elem[i][j]=rand()%impartitor+rest;
        cout<<K.elem[i][j]<<" ";}}
}

void InitMatRand(matrice& K, int lin, int col, int xx, int yy,bool idk)
{
    K.nrLin=lin;
    K.nrCol=col;
    K.x=xx;
    K.y=yy;
    if(idk==true)
    for (int i=1; i<=K.nrLin; i++)
        {cout<<endl;
        for (int j=1; j<=K.nrCol; j++)
            {K.elem[i][j]=rand()%99+1;
        cout<<K.elem[i][j]<<" ";}}
    else
    for (int i=1; i<=K.nrLin; i++)
        {for (int j=1; j<=K.nrCol; j++)
            K.elem[i][j]=0;}
}

void Plus(matrice& M,int a,int b,int color)
{
    setfillstyle(SOLID_FILL,GREEN);
    for(int i=1; i<=M.nrLin;i++)
        if(i!=a)
        floodfill(M.x+latura*b+2,M.y+(i-1)*latura+2,WHITE);
    for(int i=1; i<=M.nrCol;i++)
        if(i!=b)
        floodfill(M.x+(i-1)*latura+2,M.y+a*latura+2,WHITE);

    delay(300);

    setfillstyle(SOLID_FILL,color);
    for(int i=1; i<=M.nrLin;i++)
        floodfill(M.x+latura*b+2,M.y+(i-1)*latura+2,WHITE);
      for(int i=1; i<=M.nrCol;i++)
        floodfill(M.x+(i-1)*latura+2,M.y+a*latura+2,WHITE);
}

void Final(matrice& R)
{
    int latmax=max(R.nrCol*latura+160,360);
    initwindow(latmax,R.nrLin*latura+160,"Salvezi rezultatul?");
    setcolor(WHITE);
    rectangle(10,10,latmax-10,R.nrLin*latura+150);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(1,1,WHITE);
    char sir [50];

    for(int i=1; i<=R.nrLin; i++)
        for (int j=1; j<=R.nrCol; j++)
        {
        rectangle(80+(j-1)*latura,80+(i-1)*latura,80+j*latura,80+i*latura);

        if(R.elem[i][j] > 999)
            sprintf(sir,"%d K",R.elem[i][j]/1000);
        else
            sprintf(sir,"%d",R.elem[i][j]);

        if(R.elem[i][j] > 99 || R.elem[i][j] <0 )
            outtextxy(69+(j-1)*latura+latura/2,75+(i-1)*latura+latura/2,sir);
        else
            outtextxy(75+(j-1)*latura+latura/2,75+(i-1)*latura+latura/2,sir);
        }

    setfillstyle(XHATCH_FILL,DARKGRAY);
    floodfill(12,12,WHITE);

    setcolor(YELLOW);
    outtextxy(80,100+R.nrLin*latura,"Vrei sa salvezi?    Y:Da  N:Nu");
    if(getch()=='y')
    {
    outtextxy(80,120+R.nrLin*latura,"Introdu numele: ");
    setcolor(GREEN);
    char input[50]=" ";
    input[0]=getch();
    int lit=0;
    while(input[strlen(input)-1] != ' ' && strlen(input)<15)
    {
        outtextxy(80+textwidth("Introdu numele: "),120+R.nrLin*latura,input);
        cout<<input<<" ";
        input[++lit]=getch();
    }

    string NumeF; NumeF=input;
		ofstream ListNume("NumeleFisierelor.txt", ios::out | ios::app);
		ListNume << NumeF << endl;
		ListNume.close();

		NumeF = NumeF + ".txt";
		fstream ListMat(NumeF, ios::out | ios::in | ios::trunc);
		if (!ListMat.is_open())
		{
			cout << "nu mere :(" << endl;
		}
        ListMat<<R.nrLin<<" "<<R.nrCol<<endl;
		for (int i = 1; i <= R.nrLin; i++)
		{
			for (int j = 1; j <= R.nrCol; j++)
			{
                ListMat << R.elem[i][j]; if (j != R.nrCol) ListMat << " ";
			}
			if (i != R.nrLin) ListMat << endl; ListMat << endl;
		}
		ListMat.close();
		cout << "Gata!" << endl<<endl;

    }
    closegraph();
}

int Celebreaza(matrice& R)
{
    /*setfillstyle(BKSLASH_FILL,BLUE);
    int maxim=R.nrLin+R.nrCol;
    int DistVal=1;
        while(DistVal <= R.nrLin+R.nrCol)
    for(int i=1; i<=min(DistVal,R.nrLin);i++)
    {for(int j=1; j<=min(DistVal,R.nrCol);j++)
        if(i+j <= DistVal)
        floodfill(-2+R.x+(i-1)*latura+latura/2,R.y+(j-1)*latura+latura/2,WHITE);
     delay(500); DistVal++;}
     Nu mere oooof*/

     int x1,x2,x3,x4;
     int avans=0;
     setfillstyle(SOLID_FILL,YELLOW);
     while (avans <= latura*R.nrCol)
     {
        avans=avans+latura/4;
        if(avans > latura*R.nrCol)
        bar (R.x,R.y,R.x+latura*R.nrCol,R.y+4);
        else
        bar (R.x,R.y,R.x+avans,R.y+4);
        delay(60);
     }
     avans=0;
     while (avans <= latura*R.nrLin)
     {
        avans=avans+latura/3;
        if(avans > latura*R.nrLin)
        bar (R.x+R.nrCol*latura,R.y,R.x+R.nrCol*latura+4,R.y+latura*R.nrLin+4);
        else
        bar (R.x+R.nrCol*latura,R.y,R.x+R.nrCol*latura+4,R.y+avans+4);
        delay(80);
     }
     avans=0;
     while (avans <= latura*R.nrCol)
    {
        avans=avans+latura/2;
        if(avans > latura*R.nrCol)
        bar (R.x+R.nrCol*latura,R.y+latura*R.nrLin,R.x,R.y+latura*R.nrLin+4);
        else
        bar (R.x+R.nrCol*latura,R.y+latura*R.nrLin,R.x+R.nrCol*latura-avans,R.y+latura*R.nrLin+4);
        delay(80);
     }
     avans=0;
     while (avans < latura*R.nrLin)
     {
        avans=avans+latura;
        if(avans >= latura*R.nrLin)
        bar (R.x,R.y+2+latura*R.nrLin,R.x+4,R.y);
        else
        bar (R.x,R.y+2+latura*R.nrLin,R.x+4,R.y+latura*R.nrLin-avans);
        delay(80);
     }
     setcolor(YELLOW);
     for(int i=1; i<=R.nrLin; i++)
        for (int j=1; j<=R.nrCol; j++)
        {rectangle(R.x+(j-1)*latura,R.y+(i-1)*latura,R.x+j*latura,R.y+i*latura); delay(10);}
}


void aprinde2(matrice M,matrice N, int i, int j, int culoare)
{

    setfillstyle(SOLID_FILL,GREEN);
    char sir2[10],sir3[10];
    sprintf(sir2,"%d", M.elem[i][j]);
    sprintf(sir3,"%d", N.elem[i][j]);
    int clipiri=4;
    while(clipiri!=0)
    {
        setcolor(culoare);
        floodfill(-2+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,WHITE);
        floodfill(-2+N.x+(j-1)*latura+latura/2,-5+N.y+(i-1)*latura+latura/2,WHITE);
        outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir2);
        outtextxy(-5+N.x+(j-1)*latura+latura/2,-5+N.y+(i-1)*latura+latura/2,sir3);
        delay(80);

        setcolor(WHITE);
        outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir2);
        outtextxy(-5+N.x+(j-1)*latura+latura/2,-5+N.y+(i-1)*latura+latura/2,sir3);
        floodfill(-6+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,WHITE);
        floodfill(-6+N.x+(j-1)*latura+latura/2,-5+N.y+(i-1)*latura+latura/2,WHITE);
        delay(80);
        clipiri--;
    }
}

void aprinde1(matrice R, int i, int j, int culoare,int fundaldes, int fundalcol,int clipiri)
{

    setfillstyle(fundaldes, fundalcol);
    char sir2[10]; int distanta=-5;
    if(R.elem[i][j]>999)
            sprintf(sir2,"%d K",R.elem[i][j]/1000);
        else
            sprintf(sir2,"%d",R.elem[i][j]);
    if(R.elem[i][j] > 99 || R.elem[i][j] < -9) distanta=-11;
    while(clipiri!=0)
    {
        setcolor(culoare);
        floodfill(-2+R.x+(j-1)*latura+latura/2,-5+R.y+(i-1)*latura+latura/2,WHITE);
        outtextxy(distanta+R.x+(j-1)*latura+latura/2,-5+R.y+(i-1)*latura+latura/2,sir2);
        delay(80);

        setcolor(WHITE);
        floodfill(-2+R.x+(j-1)*latura+latura/2,-5+R.y+(i-1)*latura+latura/2,WHITE);
        outtextxy(distanta+R.x+(j-1)*latura+latura/2,-5+R.y+(i-1)*latura+latura/2,sir2);
        floodfill(-2+R.x+(j-1)*latura+latura/2,-5+R.y+(i-1)*latura+latura/2,WHITE);
        delay(80);
        clipiri--;
    }
}

void AnimInvs(matrice& A,matrice& C)
{

       for(int a=1; a<=A.nrLin; a++)
                for(int b=1;b<=A.nrCol;b++)
            if(A.elem[a][b]==C.elem[a][b])
            {aprinde1(A,a,b,YELLOW,SOLID_FILL,BLACK,3);
            aprinde1(C,a,b,YELLOW,SOLID_FILL,BLACK,3);}

}

void AnimatieSiCalculBuble(matrice& A)
{
    char sir1[50];char sir2[50];
    bool modificat;
    int i,j;
    for (i = 1; i <= A.nrCol; i++)
    {
        modificat = false;
        for(j=1;j <= A.nrCol-i;j++)
        if(A.elem[1][j] > A.elem[1][j+1])
        {
        aprinde1(A,1,j,YELLOW,LTBKSLASH_FILL,LIGHTBLUE,3);
        aprinde1(A,1,j+1,YELLOW,LTBKSLASH_FILL,LIGHTBLUE,3);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(-2+A.x+(j-1)*latura+latura/2,-5+A.y+latura/2,WHITE);
        floodfill(-2+A.x+(j)*latura+latura/2,-5+A.y+latura/2,WHITE);
        swap(A.elem[1][j],A.elem[1][j+1]);
        setcolor(WHITE);
        if(A.elem[1][j]<10)
        {sprintf(sir1,"%d  ", A.elem[1][j]);
        sprintf(sir2,"%d  ", A.elem[1][j+1]);}
        else
        {sprintf(sir1,"%d", A.elem[1][j]);
        sprintf(sir2,"%d", A.elem[1][j+1]);}
        outtextxy(-5+A.x+(j-1)*latura+latura/2,-5+A.y+latura/2,sir1);
        outtextxy(-5+A.x+(j)*latura+latura/2,-5+A.y+latura/2,sir2);
        delay(200);
        modificat = true;
        }
    }
}


void mrg(matrice& A, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = A.elem[1][l + i];
    for (int j = 0; j < n2; j++) R[j] = A.elem[1][m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A.elem[1][k] = L[i];
            aprinde1(A,1,k,LIGHTGREEN,LTBKSLASH_FILL,LIGHTBLUE,3);
            i++;
        }
        else
        {
            A.elem[1][k] = R[j];
            aprinde1(A,1,k,LIGHTGREEN,LTBKSLASH_FILL,LIGHTBLUE,3);
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        A.elem[1][k] = L[i];
        aprinde1(A,1,k,LIGHTGREEN,LTBKSLASH_FILL,LIGHTBLUE,3);
        i++;
        k++;
    }

    while (j < n2)
    {
        A.elem[1][k] = R[j];
        aprinde1(A,1,k,LIGHTGREEN,LTBKSLASH_FILL,LIGHTBLUE,3);
        j++;
        k++;
    }
}
void AnimatieSiCalculMerge(matrice& A,int st,int dr,int culoare)
{
    for (int j=1;j<=A.nrCol;j++)
        {setfillstyle (LTBKSLASH_FILL,culoare);
        floodfill(A.x+(j-1)*latura+2,A.y+2,WHITE);}
    if (st < dr)
    {
        int m = st + (dr - st) / 2;

        AnimatieSiCalculMerge(A, st, m,culoare+1);
        AnimatieSiCalculMerge(A, m + 1, dr,culoare-1);

        mrg(A, st, m, dr);
    }
}

/*int vec[8];
    void AnimatieSiCalcuMerge(matrice& A,int st,int dr)
   {
       for (int j=1;j<=A.nrCol;j++)
        {setfillstyle (LTBKSLASH_FILL,DARKGRAY);
        floodfill(A.x+(j-1)*latura+2,A.y+2,WHITE);}

    if(st < dr)
	{
		int mij =st+(dr-1)/2;
		AnimatieSiCalcuMerge(A,st,mij);
		AnimatieSiCalcuMerge(A,mij+1,dr);

		for (int j=st;j<=dr;j++)
        {setfillstyle (LTSLASH_FILL,LIGHTBLUE);
        floodfill(A.x+(j-1)*latura+2,A.y+2,WHITE);}

		int i=st, j=mij+1, k=0;
		while( i <= mij && j <= dr )
			if( A.elem[1][i] < A.elem[1][j])
				{vec[++k]=A.elem[1][i];
				aprinde1(A,1,i++,LIGHTGREEN,LIGHTBLUE,3);
				delay(100);}
			else
				{vec[++k]=A.elem[1][j];
				aprinde1(A,1,j++,LIGHTGREEN,LIGHTBLUE,3);
				delay(100);}
		while(i <= mij)
                {vec[++k]=A.elem[1][i];
                aprinde1(A,1,i++,YELLOW,LIGHTBLUE,1);
                delay(150);}
		while(j <= dr)
                {vec[++k]=A.elem[1][j];
                aprinde1(A,1,i++,YELLOW,LIGHTBLUE,1);
                delay(150);}
		for(i=st ,j =1 ; i<=dr ; i++ ,j ++)
			A.elem[1][i]=vec[j];
	}

}

*/
int maximus(matrice& A,int& i, int a)
{
    if(i+a<A.nrCol)
        return i+a;
    else
        return (i+a-A.nrCol);
}

void AnimatieDeter(matrice& A)
{
    int contor=A.nrCol; int spacerand=0; int lungrand=0;char sir [50];
    int a=0; int b=0;
    while(contor!=0)
    {
        for(int i=0; i<A.nrCol; i++)
    {
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(A.x+latura*i+2,A.y+latura*maximus(A,i,a)+2,WHITE);
        delay(200);
    }

        for(int i=0; i<A.nrCol; i++)
    {
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(A.x+latura*i+2,A.y+latura*maximus(A,i,a)+2,WHITE);
        delay(200);
    }

        a++;
        contor--;
    }

    contor=A.nrCol;
    while(contor!=0)
    {
        for(int i=A.nrCol-1; i>=0; i--)
    {
        setfillstyle(SOLID_FILL,BLUE);
        floodfill(A.x+latura*maximus(A,i,b)+2,A.y+latura*i+2,WHITE);
        delay(200);
    }

        for(int i=A.nrCol-1; i>=0; i--)
    {
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(A.x+latura*maximus(A,i,b)+2,A.y+latura*i+2,WHITE);
        delay(200);
    }

        b++;
        contor--;
    }



}
void Animatie4(matrice& M, matrice& R,int pos)
{
    delay(50);
    int spacerand=0; int lungrand=0;char sir [50];
    for(int i=1; i<=R.nrLin; i++)
        for (int j=1; j<=R.nrCol; j++)
        {rectangle(R.x+(j-1)*latura,R.y+(i-1)*latura,R.x+j*latura,R.y+i*latura); delay(10);}

        for (int j=pos; j<=M.nrCol;j++)
            {setfillstyle (LTSLASH_FILL,RED);
        floodfill(M.x+(j-1)*latura+2,M.y+2,WHITE);delay(10);}

        for (int j=1; j<R.nrCol; j++)
    {aprinde1(R,1,j,YELLOW,LTBKSLASH_FILL,LIGHTBLUE,4);
    setcolor (LIGHTGREEN);
    sprintf(sir,"(%d)X ; ",j+pos);
     if(lungrand+textwidth(sir) >= getmaxx()/2-5)
            if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(47,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(10+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
    aprinde1(R,1,j,YELLOW,LTBKSLASH_FILL,LIGHTBLUE,4);}
}


void Animatie3(matrice& M, matrice& R,int pos)
{
    delay(50);
    int spacerand=0; int lungrand=0;char sir [50];
    for(int i=1; i<=R.nrLin; i++)
        for (int j=1; j<=R.nrCol; j++)
        {rectangle(R.x+(j-1)*latura,R.y+(i-1)*latura,R.x+j*latura,R.y+i*latura); delay(10);}

        for (int j=1; j<=pos;j++)
            {setfillstyle (LTSLASH_FILL,RED);
        floodfill(M.x+(j-1)*latura+2,M.y+2,WHITE);delay(10);}

        for (int j=1; j<=R.nrCol; j++)
    {aprinde1(M,1,j+pos,YELLOW,LTBKSLASH_FILL,LIGHTBLUE,4);
    setcolor (LIGHTGREEN);
    sprintf(sir,"(%d)->(%d); ",j+pos,j);
     if(lungrand+textwidth(sir) >= getmaxx()/2-5)
            if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(47,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(10+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
    aprinde1(R,1,j,YELLOW,LTBKSLASH_FILL,LIGHTBLUE,4);}
}

void Animatie2(matrice& M, matrice& N, matrice& R,int caz)
{
    delay(50);
    int spacerand=0; int lungrand=0;char sir [50];
    for(int i=1; i<=R.nrLin; i++)
        for (int j=1; j<=R.nrCol; j++)
        {rectangle(R.x+(j-1)*latura,R.y+(i-1)*latura,R.x+j*latura,R.y+i*latura); delay(10);}


    for (int i=1;i<=M.nrLin;i++)
        {
            for(int k=1;k<=M.nrCol;k++)
        {
        if (i>1)
        {setfillstyle (BKSLASH_FILL,GREEN);
        floodfill(M.x+(k-1)*latura+1,M.y+(i-2)*latura+1,WHITE);}

        setfillstyle (SOLID_FILL,GREEN);
        floodfill(M.x+(k-1)*latura+1,M.y+(i-1)*latura+1,WHITE);}


    for (int j=1;j<=N.nrCol;j++)
            {{for(int o=1;o<=N.nrLin;o++)
         {
        setfillstyle (SOLID_FILL,GREEN);
        floodfill(N.x+(j-1)*latura+1,N.y +(o-1)*latura+1,WHITE);

        if(j>1)
        {if(i%2==0)
        setfillstyle(BKSLASH_FILL,GREEN);
        else
        setfillstyle(LINE_FILL,GREEN);
        floodfill(N.x+(j-2)*latura+1,N.y+(o-1)*latura+1,WHITE);}
        }
        delay(300);}

        for(int o=1;o<=N.nrLin;o++)
        {aprinde1(M,i,o,YELLOW,SOLID_FILL,GREEN,2);
        aprinde1(N,o,j,YELLOW,SOLID_FILL,GREEN,2);}
        if(j==N.nrCol)
        for(int o=1;o<=N.nrLin;o++)
        {if(i%2==0)
        setfillstyle (BKSLASH_FILL,GREEN);
                else
        setfillstyle(LINE_FILL,GREEN);
        floodfill(N.x+(N.nrCol-1)*latura+1,N.y+(o-1)*latura+1,WHITE);}

        setcolor (LIGHTGREEN);
        sprintf(sir,"(%d%d)=%d; ",i,j,R.elem[i][j]);
        if(lungrand+textwidth(sir) >= getmaxx()/2-5)
            if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(20);

        aprinde1(R,i,j,YELLOW,LTBKSLASH_FILL,LIGHTBLUE,3);}

        }
        setfillstyle (BKSLASH_FILL,GREEN);
        for(int b=1; b<=M.nrCol; b++)
            floodfill(M.x+(b-1)*latura+2,M.y+(M.nrLin-1)*latura+2,WHITE);
}

void Animatie(matrice& M, matrice& N, matrice& R,int caz)
{
    delay(50);
    int spacerand=0; int lungrand=0;char sir [50];
    for(int i=1; i<=R.nrLin; i++)
        for (int j=1; j<=R.nrCol; j++)
        {rectangle(R.x+(j-1)*latura,R.y+(i-1)*latura,R.x+j*latura,R.y+i*latura); delay(10);}


        for (int j=1;j<=M.nrCol;j++)
        {
            for (int i=1;i<=M.nrLin;i++)
        {setfillstyle (SOLID_FILL,GREEN);
        floodfill(M.x+(j-1)*latura+1,M.y+(i-1)*latura+1,WHITE);
        floodfill(N.x+(j-1)*latura+1,N.y+(i-1)*latura+1,WHITE);}delay(500);


            for(int i=1;i<=M.nrLin;i++)
        {
            switch (caz) //cadran jos stanga
        {
        case 1:
        aprinde2(M,N,i,j,YELLOW);
        setcolor (LIGHTGREEN);
        sprintf(sir,"(%d%d)=%d + %d; ",i,j,M.elem[i][j],N.elem[i][j]);
        if(lungrand+textwidth(sir) >= getmaxx()/2-5)
            if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(20);
        break;

        case 2:
        aprinde2(M,N,i,j,YELLOW);
        setcolor (LIGHTGREEN);
        sprintf(sir,"(%d%d)=%d - %d; ",i,j,M.elem[i][j],N.elem[i][j]);
        if(lungrand+textwidth(sir) >= getmaxx()/2-5)
            if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(20);
        break;
        case 3:
        aprinde2(M,N,i,j,YELLOW);
        setcolor (LIGHTGREEN);
        sprintf(sir,"(%d%d)=%d x %d=%d; ",i,j,M.elem[i][j],N.elem[i][j],R.elem[i][j]);
        if(lungrand+textwidth(sir) >= getmaxx()/2-5)
            if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(20);
        }

        //cadran jos dreapta
                if(R.elem[i][j] > 999)
                sprintf(sir,"%d K",R.elem[i][j]/1000);
                else
                sprintf(sir,"%d",R.elem[i][j]);
        if(R.elem[i][j] > 99 || R.elem[i][j] <0 )
            outtextxy(-5+R.x+(j-1)*latura+latura/2,-5+R.y+(i-1)*latura+latura/2,sir);
        else
            outtextxy(-12+R.x+(j-1)*latura+latura/2,-5+R.y+(i-1)*latura+latura/2,sir);
        aprinde1(R,i,j,YELLOW,LTBKSLASH_FILL,LIGHTBLUE,4);

        }
            setfillstyle (LTBKSLASH_FILL,LIGHTGREEN);
            for (int i=1;i<=M.nrLin;i++)
        {floodfill(M.x+(j-1)*latura+1,M.y+(i-1)*latura+1,WHITE);
        floodfill(N.x+(j-1)*latura+1,N.y+(i-1)*latura+1,WHITE);}}

    }


/*void Animatie(matrice& M, matrice& N, matrice& R,int caz)
{
    delay(50);
    int spacerand=0; int lungrand=0;char sir [50];
    for(int i=1; i<=R.nrLin; i++)
        for (int j=1; j<=R.nrCol; j++)
        {rectangle(R.x+(j-1)*latura,R.y+(i-1)*latura,R.x+j*latura,R.y+i*latura); delay(10);}


        for (int j=1;j<=M.nrCol;j++)
        {
            for (int i=1;i<=M.nrLin;i++)
        {setfillstyle (SOLID_FILL,GREEN);
        floodfill(M.x+(j-1)*latura+1,M.y+(i-1)*latura+1,WHITE);}

        for (int i=1;i<=N.nrCol;i++)
            for (int i=1;i<=N.nrLin;i++)
            {floodfill(N.x+(j-1)*latura+1,N.y+(i-1)*latura+1,WHITE);}


            for(int i=1;i<=M.nrLin;i++)
        {
                                switch (caz) //cadran jos stanga
        {
        case 1:
        aprinde2(M,N,i,j,YELLOW);
        setcolor (LIGHTGREEN);
        sprintf(sir,"(%d%d)=%d + %d; ",i,j,M.elem[i][j],N.elem[i][j]);
        break;

        case 2:
        aprinde2(M,N,i,j,YELLOW);
        setcolor (LIGHTGREEN);
        sprintf(sir,"(%d%d)=%d - %d; ",i,j,M.elem[i][j],N.elem[i][j]);
        break;

        case 3:
        aprinde2(M,N,i,j,YELLOW);
        setcolor (LIGHTGREEN);
        sprintf(sir,"(%d%d)=%d x %d=%d; ",i,j,M.elem[i][j],N.elem[i][j],R.elem[i][j]);
        break;
        }

        if(lungrand+textwidth(sir) >= getmaxx()/2-5)
            if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(20);


        //cadran jos dreapta
         if(R.elem[i][j] > 999)
                sprintf(sir,"%d K",R.elem[i][j]/1000);
                else
                sprintf(sir,"%d",R.elem[i][j]);
        if(R.elem[i][j] > 99 || R.elem[i][j] <0 )
            outtextxy(-5+R.x+(j-1)*latura+latura/2,-5+R.y+(i-1)*latura+latura/2,sir);
        else
            outtextxy(-12+R.x+(j-1)*latura+latura/2,-5+R.y+(i-1)*latura+latura/2,sir);
        aprinde1(R,i,j,YELLOW,LTBKSLASH_FILL,LIGHTBLUE,4);

        }
            setfillstyle (LTBKSLASH_FILL,LIGHTGREEN);
            for (int i=1;i<=M.nrLin;i++)
        {floodfill(M.x+(j-1)*latura+1,M.y+(i-1)*latura+1,WHITE);
        floodfill(N.x+(j-1)*latura+1,N.y+(i-1)*latura+1,WHITE);}}

    }*/
void Rezultat(char* sir,int rez)
{
    setcolor(WHITE);
    outtextxy(getmaxx()/2+20,getmaxy()-getmaxy()/4,"Rezultatul:");
    line(getmaxx()/2+20,getmaxy()-getmaxy()/4+20,getmaxx()/2+20+textwidth("Rezultatul: "),getmaxy()-getmaxy()/4+20);
    sprintf(sir,"%d",rez); bool repeta=true;
    while(repeta==true)
    {setcolor(YELLOW);
    outtextxy(getmaxx()/2+50,getmaxy()-getmaxy()/4+25,sir);
    delay(100);
    setcolor(BLUE);
    outtextxy(getmaxx()/2+50,getmaxy()-getmaxy()/4+25,sir);
    delay(100);
    setcolor(YELLOW);
    outtextxy(getmaxx()/2+50,getmaxy()-getmaxy()/4+25,sir);
    repeta=false;}
}

void ImparteEcranMat2(matrice& M,char semn,bool alege)

{

    rectangle(5,5,getmaxx()-5,getmaxy()-5);
    floodfill (1,1, WHITE);
    rectangle(7,7,getmaxx()-7,getmaxy()-7);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill (6,6,WHITE);

    setfillstyle(LTSLASH_FILL,DARKGRAY);
    floodfill (8,8,WHITE);

    setfillstyle(SOLID_FILL,WHITE);
    bar(0,(getmaxy()/2),getmaxx(),(getmaxy()/2+10));
    bar((getmaxx()/2),getmaxy()/2,(getmaxx()/2+10), getmaxy());

        if(alege==true)
    {outtextxy((getmaxx()/2+20),getmaxy()/2+15,"Rezultatul:");
    line((getmaxx()/2+20),(getmaxy()/2+30),(getmaxx()/2+20)+textwidth("Rezultatul:"),(getmaxy()/2+30));
    outtextxy(45,20,"Matricea 1:");
    line(45,35,(45+textwidth("Matricea 1:")),35);
    outtextxy((getmaxx()/2+20),20,"Matricea 2:");
    line((getmaxx()/2+20),35,(getmaxx()/2+20+textwidth("Matricea 2:")),35);}


    switch(semn)
    {
    case '0':
        break;
    case '+':
        bar((getmaxx()/2), getmaxy()/4-5,(getmaxx()/2+6),getmaxy()/4+35);
        bar(getmaxx()/2-8, getmaxy()/4+10,getmaxx()/2+14,getmaxy()/4+18);
        break;
    case '-':
        bar(getmaxx()/2-8, getmaxy()/4+10,getmaxx()/2+14,getmaxy()/4+18);
        break;
    case 'x':
        outtextxy(M.x+latura*M.nrCol+25,getmaxy()/4+5,"X");
    case '>':
        outtextxy(M.x+latura*M.nrCol+15,getmaxy()/4+5,"-->");
        break;
    case '/':
        outtextxy(M.x+latura*M.nrCol+25,getmaxy()/4-10,"A");
        bar(M.x+latura*M.nrCol+15,getmaxy()/4+10,M.x+latura*M.nrCol+40,getmaxy()/4+15);
        outtextxy(M.x+latura*M.nrCol+25,getmaxy()/4+20,"B");
        break;
    default:
        break;
    }

}

void AnimatieSimpla(matrice& A, matrice B)
{
    int contor=4;
    while(contor!=0){
    for(int i=1; i<=A.nrLin;i++)
        for(int j=1;j<=A.nrCol;j++)
        {setfillstyle(SOLID_FILL,BLUE);
        floodfill(A.x+latura*(j-1)+2,A.y+latura*(i-1)+2,WHITE);}
        delay(300);
    for(int i=1; i<=A.nrLin;i++)
        for(int j=1;j<=A.nrCol;j++)
        {setfillstyle(SOLID_FILL,BLACK);
        floodfill(A.x+latura*(j-1)+2,A.y+latura*(i-1)+2,WHITE);}
        delay(300);contor--;}

    for(int i=1; i<=A.nrLin;i++)
        for(int j=1;j<=A.nrCol;j++)
            aprinde1(B,A.x+latura*(j-1)+2,A.y+latura*(i-1)+2,YELLOW,LTSLASH_FILL,BLUE,1);


}

void Semn(matrice& M,bool gata,char caz,int& spacerand,int& lungrand)
{
    if(gata==false)
        switch(caz)
    {
    case '+':
        setcolor (LIGHTBLUE);
        if(lungrand+textwidth("+ ") >= getmaxx()/2-8)
            if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,"+ ");
        lungrand=lungrand+textwidth("+ ");
        delay(100);
    break;

    case '-':
        setcolor (LIGHTBLUE);
        if(lungrand+textwidth("- ") >= getmaxx()/2-8)
            if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,"- ");
        lungrand=lungrand+textwidth("- ");
        delay(100);
    break;

    case 'x':
        setcolor (LIGHTBLUE);
        if(lungrand+textwidth("x ") >= getmaxx()/2-8)
            if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,"x ");
        lungrand=lungrand+textwidth("x ");
        delay(100);
    break;

    }
    else
    {   setcolor (LIGHTBLUE);
        if(lungrand+textwidth(";") >= getmaxx()/2-5)
            if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,";");
        lungrand=lungrand+textwidth(";");
        delay(20);}

}

void DrawMat3(matrice& M)
{
    setfillstyle(SOLID_FILL,BLACK);
    char sir[10];
    for (int i=1; i<=M.nrLin; i++)
        for (int j=1; j<=M.nrCol; j++)
        {
            rectangle(M.x+(j-1)*latura,M.y+(i-1)*latura,M.x+j*latura,M.y+i*latura);
            floodfill(M.x+(j-1)*latura+2,M.y+(i-1)*latura+2,LIGHTGREEN);
            {
                // itoa(M.elem[i][j],sir,10);
                sprintf(sir, "%d", M.elem[i][j]);
                if(M.elem[i][j]>99 || M.elem[i][j]<-99)
                outtextxy(-10+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
                else
                outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
                }
        }
}

void DrawMat1(matrice& M)
{
    setfillstyle(SOLID_FILL,BLACK);
    char sir[10];
    for (int i=1; i<=M.nrLin; i++)
        for (int j=1; j<=M.nrCol; j++)
        {
            rectangle(M.x+(j-1)*latura,M.y+(i-1)*latura,M.x+j*latura,M.y+i*latura);
            floodfill(M.x+(j-1)*latura+2,M.y+(i-1)*latura+2,WHITE);
            {
                // itoa(M.elem[i][j],sir,10);
                sprintf(sir, "%d", M.elem[i][j]);
                outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
                }
        }
}

void IncarcaValRand(matrice X,int lin,int col)
{
    for(int i=0; i<=X.nrLin;i++)
        for(int j=0; j<=X.nrCol;j++)
        X.elem[i][j]=rand()%100+1;
}

void Animatie100(matrice& M,int diagonaleBLU,char cazTip,int cazCer)
{
    char sir[50]; int spacerand=0; int lungrand=0; bool gata=false;

    setfillstyle(SOLID_FILL,BLUE);
        for(int i=1; i<=M.nrLin; i++)
            if(diagonaleBLU==1)
            floodfill(M.x+latura*(i-1)+2,M.y+latura*(i-1)+2,WHITE);
                else
            if(diagonaleBLU==-1)
            floodfill(M.x+latura*(i-1)+2,M.y+latura*(M.nrLin-i)+2,WHITE);
                else
            if(diagonaleBLU==2)
            {
             floodfill(M.x+latura*(i-1)+2,M.y+latura*(i-1)+2,WHITE);
             floodfill(M.x+latura*(i-1)+2,M.y+latura*(M.nrLin+1-i)+2,WHITE);
            }
            delay(400);

    switch(cazTip)
    {
    case 's':
        setcolor (YELLOW);
        sprintf(sir,"SUMA= ");
        if(lungrand+textwidth(sir) >= getmaxx()/2-8)
            if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(200);
    break;

    case 'p':
        setcolor (YELLOW);
        sprintf(sir,"PRODUS= ");
        if(lungrand+textwidth(sir) >= getmaxx()/2-8)
            if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(200);
    break;
    }

    switch(cazCer)
    {
        case 1:
        for(int i=1; i<=M.nrLin; i++)
        {aprinde1(M,i,i,YELLOW,SOLID_FILL,GREEN,3);

        setcolor (LIGHTGREEN);
        sprintf(sir,"%d(%d%d) ",M.elem[i][i],i,i);
        if(lungrand+textwidth(sir) >= getmaxx()/2-8)
        if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(100);
        Semn(M,gata,'+',spacerand,lungrand);
        if(i==M.nrLin-1)
        gata=true;}
        break;

        case 2:
        for(int i=1; i<=M.nrLin; i++)
        {aprinde1(M,i,M.nrLin+1-i,YELLOW,SOLID_FILL,GREEN,3);

        setcolor (LIGHTGREEN);
        sprintf(sir,"%d(%d%d) ",M.elem[i][M.nrLin+1-i],i,(M.nrLin+1-i));
        if(lungrand+textwidth(sir) >= getmaxx()/2-8)
        if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(100);
        Semn(M,gata,'+',spacerand,lungrand);}
        break;

                case 3:
        for(int i=1; i<=M.nrLin; i++)
            for(int j=1; j<=M.nrCol; j++)
                if(i!=j && i<j)
        {aprinde1(M,i,j,YELLOW,SOLID_FILL,GREEN,3);

        setcolor (LIGHTGREEN);
        sprintf(sir,"%d(%d%d) ",M.elem[i][j],i,j);
        if(lungrand+textwidth(sir) >= getmaxx()/2-8)
        if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(100);
        Semn(M,gata,'+',spacerand,lungrand);
        if(i==M.nrLin-1 && j==M.nrLin-1)
            gata=true;
        break;}

            case 4:
        for(int i=1; i<=M.nrLin; i++)
            for(int j=1; j<=M.nrCol; j++)
                if(i>j)
        {aprinde1(M,i,j,YELLOW,SOLID_FILL,GREEN,3);

        setcolor (LIGHTGREEN);
        sprintf(sir,"%d(%d%d) ",M.elem[i][j],i,j);
        if(lungrand+textwidth(sir) >= getmaxx()/2-8)
        if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(100);
        Semn(M,gata,'+',spacerand,lungrand);
        if(i==M.nrLin-1 && j==M.nrLin-1)
        gata=true;}
        break;

        case 5:
        for(int i=1; i<=M.nrLin; i++)
            for(int j=1; j<=M.nrCol; j++)
            if(i+j<M.nrLin+1)
        {aprinde1(M,i,j,YELLOW,SOLID_FILL,GREEN,3);

        setcolor (LIGHTGREEN);
        sprintf(sir,"%d(%d%d) ",M.elem[i][j],i,j);
        if(lungrand+textwidth(sir) >= getmaxx()/2-8)
        if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(100);
        Semn(M,gata,'+',spacerand,lungrand);
        if(i==M.nrLin-1 && j==M.nrLin-1)
        gata=true;}
        break;

        case 6:
        for(int i=1; i<=M.nrLin; i++)
            for(int j=1; j<=M.nrLin; j++)
        {aprinde1(M,i,j,YELLOW,SOLID_FILL,GREEN,3);

        setcolor (LIGHTGREEN);
        sprintf(sir,"%d(%d%d) ",M.elem[i][M.nrLin+1-i],i,(M.nrLin+1-i));
        if(lungrand+textwidth(sir) >= getmaxx()/2-8)
        if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(100);
        Semn(M,gata,'*',spacerand,lungrand);}
        break;

        case 7:
        for(int i=1; i<=M.nrLin; i++)
            for(int j=1; j<=M.nrLin; j++)
                if(i+j>M.nrLin+1)
        {aprinde1(M,i,j,YELLOW,SOLID_FILL,GREEN,3);

        setcolor (LIGHTGREEN);
        sprintf(sir,"%d(%d%d) ",M.elem[i][M.nrLin+1-i],i,(M.nrLin+1-i));
        if(lungrand+textwidth(sir) >= getmaxx()/2-8)
        if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(100);
        Semn(M,gata,'+',spacerand,lungrand);
        if(i==M.nrLin-1 && j==M.nrLin-1)
        gata=true;}
        break;

        case 8:
        for(int i=1; i<=M.nrLin; i++)
        {aprinde1(M,i,i,YELLOW,SOLID_FILL,GREEN,3);

        setcolor (LIGHTGREEN);
        sprintf(sir,"%d(%d%d) ",M.elem[i][i],i,i);
        if(lungrand+textwidth(sir) >= getmaxx()/2-8)
        if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(100);
        Semn(M,gata,'*',spacerand,lungrand);
        if(i==M.nrLin-1)
        gata=true;}
        break;

        case 9:
        for(int i=1; i<=M.nrLin; i++)

        {aprinde1(M,i,M.nrLin+1-i,YELLOW,SOLID_FILL,GREEN,3);

        setcolor (LIGHTGREEN);
        sprintf(sir,"%d(%d%d) ",M.elem[i][M.nrLin+1-i],i,M.nrLin+1-i);
        if(lungrand+textwidth(sir) >= getmaxx()/2-8)
        if(getmaxy()/2+40+spacerand >= getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(100);
        Semn(M,gata,'*',spacerand,lungrand);
        if(i==M.nrLin-1)
        gata=true;}
        break;

        case 10:
        for(int i=1; i<=M.nrLin; i++)
            for(int j=1; j<=M.nrCol; j++)
                if(i<j)
        {aprinde1(M,i,j,YELLOW,SOLID_FILL,GREEN,3);

        setcolor (LIGHTGREEN);
        sprintf(sir,"%d(%d%d) ",M.elem[i][j],i,j);
        if(lungrand+textwidth(sir) >= getmaxx()/2-8)
        if(getmaxy()/2+40+spacerand > getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(100);
        Semn(M,gata,'*',spacerand,lungrand);
        if(i==M.nrLin-1 && j==M.nrLin-1)
            gata=true;}
        break;

        case 11:
        for(int i=1; i<=M.nrLin; i++)
            for(int j=1; j<=M.nrLin; j++)
                if(i>j)
        {aprinde1(M,i,j,YELLOW,SOLID_FILL,GREEN,3);

        setcolor (LIGHTGREEN);
        sprintf(sir,"%d(%d%d) ",M.elem[i][j],i,j);
        if(lungrand+textwidth(sir) >= getmaxx()/2-8)
        if(getmaxy()/2+40+spacerand >= getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(100);
        Semn(M,gata,'*',spacerand,lungrand);
        if(i==M.nrLin-1 && j==M.nrLin-1)
        gata=true;}
        break;

        case 12:
        for(int i=1; i<=M.nrLin; i++)
            for(int j=1; j<=M.nrLin; j++)
                if(i+j<M.nrLin+1)
        {aprinde1(M,i,j,YELLOW,SOLID_FILL,GREEN,3);

        setcolor (LIGHTGREEN);
        sprintf(sir,"%d(%d%d) ",M.elem[i][j],i,j);
        if(lungrand+textwidth(sir) >= getmaxx()/2-8)
        if(getmaxy()/2+40+spacerand >= getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(100);
        Semn(M,gata,'*',spacerand,lungrand);
        if(i==M.nrLin-1 && j==M.nrLin-1)
        gata=true;}
        break;

        case 13:
        for(int i=1; i<=M.nrLin; i++)
            for(int j=1; j<=M.nrLin; j++)
                if(i+j>M.nrLin+1)
        {aprinde1(M,i,j,YELLOW,SOLID_FILL,GREEN,3);

        setcolor (LIGHTGREEN);
        sprintf(sir,"%d(%d%d) ",M.elem[i][j],i,j);
        if(lungrand+textwidth(sir) >= getmaxx()/2-8)
        if(getmaxy()/2+40+spacerand >= getmaxy()-25)
        {setfillstyle(LTSLASH_FILL,DARKGRAY);
        floodfill(M.x-3,getmaxy()/2+10,WHITE);
        spacerand=0;lungrand=0;}
        else
        {spacerand=spacerand+20; lungrand=0;}

        outtextxy(M.x-40+lungrand,getmaxy()/2+20+spacerand,sir);
        lungrand=lungrand+textwidth(sir);
        delay(100);
        Semn(M,gata,'*',spacerand,lungrand);
        if(i==M.nrLin-1 && j==M.nrLin-1)
        gata=true;}
        break;




    }
}
///Citirea din fisiere/Gunoi V V V

void AlegeDeUnde(matrice& M,int coordx,int coordy,int lin, int col,bool gol)
{
    initwindow(latura*8+200,latura*8+300,"Librarie");
    setcolor(WHITE);

    setfillstyle(SOLID_FILL,WHITE);
    rectangle(5,5,getmaxx()-5,getmaxy()-5);
    floodfill (1,1, WHITE);
    rectangle(7,7,getmaxx()-7,getmaxy()-7);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill (6,6,WHITE);

    setfillstyle(SOLID_FILL,WHITE);
    bar(0,100,getmaxx(),110);

    setfillstyle(LTSLASH_FILL,DARKGRAY);
    floodfill(10,10,WHITE);

    setfillstyle(SOLID_FILL,WHITE);
    bar(0,getmaxy()-100,getmaxx(),getmaxy()-110);

    setfillstyle(LTSLASH_FILL,DARKGRAY);
    floodfill(getmaxx()-50,getmaxy()-50,WHITE);

    setfillstyle(LTBKSLASH_FILL,DARKGRAY);
    floodfill(110,110,WHITE);

    setcolor(LIGHTGREEN);
    outtextxy(getmaxx()/2-(textwidth("2.Adauga un nou tabel.")/2),getmaxy()-80,"2.Adauga o noua matrice");
    outtextxy(getmaxx()/2-(textwidth("3.Genereaza aleatoriu, un tabel.")/2),getmaxy()-40,"3.Genereaza aleatoriu, un tabel.");

    ifstream ListNum("NumeleFisierelor.txt", ios::in);
    ListNum.seekg(0);
    string NumeSt,NumeMj,NumeDr,NumeFis;
    matrice N; char sir1[50];char sir2[50];char sir3[50];

    getline(ListNum, NumeMj);
    getline(ListNum,NumeDr);

    for(int x=0; x<NumeMj.length()+1;x++)
    {sir2[x]=NumeMj[x];}
    for(int x=0; x<NumeDr.length()+1;x++)
    {sir3[x]=NumeDr[x];}

    outtextxy(getmaxx()/2-(textwidth(sir2)/2),40,sir2);
    outtextxy(getmaxx()/2+30,60,sir3);
    outtextxy(getmaxx()/2+75,40,"-->");
    outtextxy(getmaxx()/2-77,40,"<--");

    NumeFis=NumeMj+".txt";
    fstream ListMat(NumeFis, ios::in | ios::out);
            ListMat.seekg(0);

			int nrlin, nrcol;
			ListMat >> nrlin >> nrcol;
            InitMatRand(N,nrlin,nrcol,getmaxx()/2-(latura*nrcol)/2,getmaxy()/2-(latura*nrlin)/2,false);
			for (int i = 1; i <=nrlin; i++)
			{for (int j = 1; j <=nrcol; j++)
			{ListMat >> N.elem[i][j];}}

            setcolor(LIGHTGREEN);
			DrawMat3(N);
			ListMat.close();

			bool decizie=false;

        while(decizie==false)
        {
            char imput=getch();
        if(imput=='.' && ListNum.good())
            {setfillstyle(LTBKSLASH_FILL,DARKGRAY);
            floodfill(15,115,WHITE);
            setfillstyle(LTSLASH_FILL,DARKGRAY);
            floodfill(10,10,WHITE);

            strcpy(sir1,sir2);
            strcpy(sir2,sir3);
            NumeSt=NumeMj;
            NumeMj=NumeDr;
            getline(ListNum,NumeDr);
            for(int x=0; x<NumeDr.length()+1;x++)
            sir3[x]=NumeDr[x];

            outtextxy(getmaxx()/2-(textwidth(sir2)/2),40,sir2);
            outtextxy(getmaxx()/2+30,60,sir3);
            outtextxy(getmaxx()/2-textwidth(sir1)-30,60,sir1);
            outtextxy(getmaxx()/2+75,40,"-->");
            outtextxy(getmaxx()/2-77,40,"<--");

                NumeFis=NumeMj+".txt";
            fstream ListMat(NumeFis, ios::in | ios::out);
            ListMat.seekg(0);

			int nrlin, nrcol;
			ListMat >> nrlin >> nrcol;
            InitMatRand(N,nrlin,nrcol,getmaxx()/2-(latura*nrcol)/2,getmaxy()/2-(latura*nrlin)/2,false);
			for (int i = 1; i <=nrlin; i++)
			for (int j = 1; j <=nrcol; j++)
			ListMat >> N.elem[i][j];

            setcolor(LIGHTGREEN);
			DrawMat3(N);
			ListMat.close();}
        else
        if(imput==',')
        {
            closegraph();
            AlegeDeUnde(M,coordx,coordy,lin,col,gol);
        }
        else
        if(imput=='1')
        {
            M.x=coordx;
            M.y=coordy;
            M.nrLin=lin;
            M.nrCol=col;

            decizie =true;
            for(int a=1;a<=lin;a++)
                for(int b=1;b<=col;b++)
                M.elem[a][b]==N.elem[a][b];
        }
        if(imput=='2')
        {
            cout<<"out of work;";
        }
        else
        if(imput=='3')
        {
            gol=true;
            decizie =true;
        }
        }
}

///==============================================

void AddMat(matrice A, matrice B, matrice C)
{

    //outtextxy(50+latura*A.nrCol+25,50+latura*A.nrLin/2,"+");
    //outtextxy(50+latura*(A.nrCol+B.nrCol)+50+25,50+latura*A.nrLin/2,"=");
    //ADUNAREA A DOUA MATRICE A si B => rezultatul va fi in C
    for (int i=1; i<=A.nrLin; i++)
        for (int j=1; j<=A.nrCol; j++)
        {
            //aprinde(A,i,j,LIGHTRED);
            //aprinde(B,i,j,LIGHTCYAN);
            C.elem[i][j]=A.elem[i][j]+B.elem[i][j];
            //aprinde(C,i,j,LIGHTGREEN);
        }
    //outtextxy(50+latura*A.nrCol+25,50+latura*A.nrLin/2," ");

}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void SubMat(matrice& A, matrice& B, matrice& C)
{

    //outtextxy(50+latura*A.nrCol+25,50+latura*A.nrLin/2,"-");
    //SCADEREA A DOUA MATRICE A si B => rezultatul va fi in C
    for (int i=1; i<=A.nrLin; i++)
        for (int j=1; j<=A.nrCol; j++)
        {
            //aprinde(A,i,j,LIGHTRED);
            //aprinde(B,i,j,LIGHTCYAN);
            C.elem[i][j]=A.elem[i][j]-B.elem[i][j];
            //aprinde(C,i,j,LIGHTGREEN);
        }
    //outtextxy(50+latura*A.nrCol+25,50+latura*A.nrLin/2," ");
}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void ProdMat(matrice& A, matrice& B, matrice& C)
{
    if(A.nrCol != B.nrLin)
        cout<<" EROARE: DIM STUPIDE DAHIBDUG ";
        else
    {
        for(int i = 1; i <=A.nrLin; i++)
        {
            for(int j = 1; j<= B.nrCol; j++)
            {
                for(int k =1 ; k<=B.nrLin; k++)
                {
                    //aprinde(A,i,k,RED);
                    //aprinde(B,k,j,GREEN);
                    C.elem[i][j] += A.elem[i][k] * B.elem[k][j];
                    //aprinde(C,i,j,BLUE);
                }
                    cout<< C.elem[i][j] << " ";
            }
            cout<<endl;
        }
    }
        //outtextxy(50+latura*A.nrCol+25,100+latura*A.nrLin,"Nu se respecta conditia inmultirii");
}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Cl(matrice C)
{
    for(int i = 1; i<= C.nrLin; i++)
    {
        for(int j = 1; j<= C.nrCol; j++)
        {
            C.elem[i][j] = 99999999;
            char sir[10];
            snprintf(sir, sizeof(sir), "%d", C.elem[i][j]);
            // itoa(M.elem[i][j],sir,10);
            for (int k=1; k<=5; k++)
            {
                outtextxy(-5+C.x+(j-1)*latura+latura/2,-5+C.y+(i-1)*latura+latura/2,sir);
                delay(80);
                setcolor(BLACK);
            }
        }
    }

}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void PowMat(matrice& A, int x)
{
    matrice r = A;
    for(int i = 1; i < x; i++)
        ProdMat(A,r,A);

}

///~~~~~????~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int co(int x)
{
    int r = -1;
    for(int i = 1; i< x; i++)
        r = r*-1;
    return r;
}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*int AltDet (matirce A)
{
    const int MAXN = 105;
double a[MAXN][MAXN];

double determinant(int n) {
    double det = 1.0;
    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i+1; j<n; j++) {
            if (abs(a[j][i]) > abs(a[pivot][i])) {
                pivot = j;
            }
        }
        if (pivot != i) {
            swap(a[i], a[pivot]);
            det *= -1;
        }
        if (a[i][i] == 0) {
            return 0;
        }
        det *= a[i][i];
        for (int j = i+1; j<n; j++) {
            double factor = a[j][i] / a[i][i];
            for (int k = i+1; k<n; k++) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }
    return det;
}

int main() {
    int n = 4;
    double matrix[4][4] = {{1, 0, 2, -1},
                           {3, 0, 0, 5},
                           {2, 1, 4, -3},
                           {1, 0, 5, 0}};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = matrix[i][j];
        }
    }
    double det = determinant(n);
    cout << "Determinant = " << det << endl;
    return 0;
}
}*/

int DeterMat(matrice& A)
{
    int det = 0;
    if(A.nrLin == 1)
    {
        return A.elem[1][1];
    }
    if(A.nrLin == 2)
    {
        return ((A.elem[1][1] * A.elem[2][2]) - (A.elem[1][2] * A.elem[2][1]));
    }
    if(A.nrLin > 2)
    {
        int sign = 1;
        for(int i = 1 ; i <= A.nrCol; i++)
        {
            matrice v;
            //InitMatRand(v, A.nrLin-1,A.nrCol-1,50,50,false);
            int lin = 1, col =1;
            for(int j = 2; j <= A.nrLin; j++)
                for(int k = 1; k<=A.nrCol; k++)
                {
                    if(k!= i)
                    {
                        v.elem[lin][col++] = A.elem[j][k];
                    }
                    if(col == A.nrCol)
                    {
                        col = 1;
                        lin++;
                    }
                }
            det+= sign * A.elem[1][i]*DeterMat(v);
            sign = sign *-1;
        }
        return det;
    }
}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void TraMat(matrice& A)
{
    matrice r;
    //initializeazaMatrice(r,A.nrLin,A.nrCol,50,50,false);
    for (int i = 1; i <= A.nrLin; i++)
    {
        for (int j = 1; j <= A.nrCol; j++)
        {
            r.elem[i][j] = A.elem[j][i];
            ////aprinde(r,i,j,LIGHTGREEN);
        }

    }
    A = r;
}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void AdjMat(matrice& A)
{
    matrice r = A;
    TraMat(r);
    for (int i = 1; i <= r.nrLin; i++)
    {
        for (int j = 1; j <= r.nrCol; j++)
        {
            matrice v;
            //initializeazaMatrice(v, r.nrLin-1, r.nrCol-1, r.x, r.y, false);
            int lin = 1, col = 1;
            for (int k = 1; k <= r.nrLin; k++)
            {
                for (int l = 1; l <= r.nrCol; l++)
                {
                    if (k != i && l != j)
                    {
                        int aux = r.elem[k][l];
                        v.elem[lin][col] = aux;
                        //cout << v.elem[lin][col] << " " << r.elem[k][l] << "    ";
                        col++;


                        if (col == r.nrCol)
                        {
                            col = 1;
                            lin++;
                        }
                    }
                }
                //cout << "\n";
            }

            A.elem[i][j] = co(i+j) * DeterMat(v);
        }

    }

}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void InvMat(matrice& A)
{
    double det = DeterMat(A);
    for(int i = 1; i<= A.nrLin; i++)
        for(int j = 1; j<= A.nrCol; j++)
        {
            A.elem[i][j] = A.elem[i][j]/det;
        }
}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void DivMat(matrice A, matrice B, matrice C)
{
        if(A.nrCol != B.nrLin)
        cout<<" EROARE: DIM STUPIDE DAHIBDUG ";
        else
    {
        for(int i = 1; i <=A.nrLin; i++)
        {
            for(int j = 1; j<= B.nrCol; j++)
            {
                for(int k =1 ; k<=B.nrLin; k++)
                {
                    //aprinde(A,i,k,RED);
                    //aprinde(B,k,j,GREEN);
                    C.elem[i][j] += A.elem[i][k] / B.elem[k][j];
                    //aprinde(C,i,j,BLUE);
                }
                    cout<< C.elem[i][j] << " ";
            }
            cout<<endl;
        }
    }

    //InvMat(B);
    //ProdMat(A,B,C);
}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double DiagSum(matrice& A)
{
        double sum = 0;
        for(int i = 1; i<= A.nrLin; i++)
        {
            sum+=A.elem[i][i];
        }
        return sum;
        //outtextxy(50+latura*A.nrCol+25,100+latura*A.nrLin,"Matricea nu este patratica");
}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double DiagSecSum(matrice A)
{
    if(A.nrLin == A.nrCol)
    {
        double sum = 0;
        for(int i = 1; i<= A.nrLin; i++)
        {
            sum+=A.elem[i][A.nrLin+1-i];
        }
        return sum;
    }
    else
    {
        outtextxy(50+latura*A.nrCol+25,100+latura*A.nrLin,"Matricea nu este patratica");
        return 0;
    }

}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double SumOverDiag(matrice A)
{
    if(A.nrLin == A.nrCol)
    {
        double sum = 0;

        for(int i = 1; i<A.nrLin; i++)
            for(int j = i+1; j<=A.nrCol; j++)
                sum+=A.elem[i][j];

        return sum;
    }
    else
    {
        outtextxy(50+latura*A.nrCol+25,100+latura*A.nrLin,"Matricea nu este patratica");
        return 0;
    }

}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double SumUnderDiag(matrice A)
{
    if(A.nrLin == A.nrCol)
    {
        double sum = 0;

        for(int i = 2; i<A.nrLin; i++)
            for(int j = 1; j < i; j++)
                sum+=A.elem[i][j];

        return sum;
    }
    else
    {
        outtextxy(50+latura*A.nrCol+25,100+latura*A.nrLin,"Matricea nu este patratica");
        return 0;
    }

}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double SumOverSec(matrice A)
{
    if(A.nrLin == A.nrCol)
    {
        double sum = 0;

        for(int i = 1; i<A.nrLin; i++)
            for(int j = 1; j < A.nrCol-i; j++)
                sum+=A.elem[i][j];

        return sum;
    }
    else
    {
        outtextxy(50+latura*A.nrCol+25,100+latura*A.nrLin,"Matricea nu este patratica");
        return 0;
    }

}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double SumUnderSec(matrice A)
{
    if(A.nrLin == A.nrCol)
    {
        double sum = 0;

        for(int i = 2; i<=A.nrLin; i++)
            for(int j = A.nrCol-i+1; j <= A.nrCol; j++)
                sum+=A.elem[i][j];

        return sum;
    }
    else
    {
        outtextxy(50+latura*A.nrCol+25,100+latura*A.nrLin,"Matricea nu este patratica");
        return 0;
    }

}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double DiagProd(matrice A)
{
    if(A.nrLin == A.nrCol)
    {
        double sum = 1;
        for(int i = 1; i<= A.nrLin; i++)
        {
            sum*=A.elem[i][i];
        }
        return sum;
    }
    else
    {
        outtextxy(50+latura*A.nrCol+25,100+latura*A.nrLin,"Matricea nu este patratica");
        return 0;
    }

}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double DiagSecProd(matrice A)
{
    if(A.nrLin == A.nrCol)
    {
        double sum = 1;
        for(int i = 1; i<= A.nrLin; i++)
        {
            sum*=A.elem[i][A.nrLin+1-i];
        }
        return sum;
    }
    else
    {
        outtextxy(50+latura*A.nrCol+25,100+latura*A.nrLin,"Matricea nu este patratica");
        return 0;
    }

}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double ProdOverDiag(matrice A)
{
    if(A.nrLin == A.nrCol)
    {
        double sum = 1;

        for(int i = 1; i<A.nrLin; i++)
            for(int j = i+1; j<=A.nrCol; j++)
                sum*=A.elem[i][j];

        return sum;
    }
    else
    {
        outtextxy(50+latura*A.nrCol+25,100+latura*A.nrLin,"Matricea nu este patratica");
        return 0;
    }

}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double ProdUnderDiag(matrice A)
{
    if(A.nrLin == A.nrCol)
    {
        double sum = 1;

        for(int i = 2; i<A.nrLin; i++)
            for(int j = 1; j < i; j++)
                sum*=A.elem[i][j];

        return sum;
    }
    else
    {
        outtextxy(50+latura*A.nrCol+25,100+latura*A.nrLin,"Matricea nu este patratica");
        return 0;
    }

}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double ProdOverSec(matrice A)
{
    if(A.nrLin == A.nrCol)
    {
        double sum = 1;

        for(int i = 1; i<A.nrLin; i++)
            for(int j = 1; j < A.nrCol-i; j++)
                sum*=A.elem[i][j];

        return sum;
    }
    else
    {
        outtextxy(50+latura*A.nrCol+25,100+latura*A.nrLin,"Matricea nu este patratica");
        return 0;
    }

}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double ProdUnderSec(matrice A)
{
    if(A.nrLin == A.nrCol)
    {
        double sum = 1;

        for(int i = 2; i<=A.nrLin; i++)
            for(int j = A.nrCol-i+1; j <= A.nrCol; j++)
                sum*=A.elem[i][j];

        return sum;
    }
    else
    {
        outtextxy(50+latura*A.nrCol+25,100+latura*A.nrLin,"Matricea nu este patratica");
        return 0;
    }

}
///Functii Calcul cu Matrici
///-------------------------------------------------------------------------------
///Functii Calcul cu Vectori si asa mai departe???

void IncepeDistractia(int a,int b)
{
    int nr_linii=a;
    int nr_coloane=b;
    initwindow(latura*nr_coloane*2+150,latura*nr_linii*2+150,"BibMatTabel");
}

void  sumVect(Vector s)
{
    int sum = 0;
    for(int i = 1; i <= s.dim; i++)
        sum+=s.val[i];

}
void subVect(Vector s)
{
    int scd = 0;
    for(int i = 1; i <= s.dim; i++)
        scd-=s.val[i];

}
int prodVect (Vector a)
{
    int prod = 1;
    for(int i = 1; i<= a.dim; i++)
    {
        prod *= a.val[i];
    }
}
void divVect(Vector a, Vector b, Vector c)
{
    for(int i = 1; i<= a.dim; i++)
    {
        c.val[i] = a.val[i] / b.val[i];
    }

}
int part(Vector a, int low, int high)
{
    int pivot = a.val[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; ++j)
    {
        if (a.val[j] < pivot)
        {
            swap(a.val[++i], a.val[j]);
        }
    }

    swap(a.val[i + 1], a.val[high]);
    return i + 1;
}

void quickSort(Vector a, int low, int high)
{
    if (low < high)
    {
        int pi = part(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void RightShiftVec(matrice& a, int pos)
{
    for(int i = 1; i<=a.nrCol-pos;i++)
    {
        a.elem[1][i] = a.elem[1][i+pos];
    }
    a.nrCol = a.nrCol-pos;
}
void LeftShiftVec(matrice& a, int pos)
{
    for(int i = pos+1; i<=a.nrCol;i++)
    {
        a.elem[1][i-pos] = a.elem[1][i];
    }
    a.nrCol = a.nrCol-pos;
}
void ScalProd(Vector& a, int x)
{
    for(int i = 1; i<= a.dim;i++)
        a.val[i]*=x;
}

void Bubble(matrice& a)
{
    bool modificat;
    int i,j;
    for (i = 1; i <a.nrCol; i++)
    {
        modificat = false;
        for(j=1;j<a.nrCol-i;j++)
        if(a.elem[1][j] > a.elem[1][j+1])
        {swap(a.elem[1][j],a.elem[1][j+1]);
        modificat = true;}
    }

}