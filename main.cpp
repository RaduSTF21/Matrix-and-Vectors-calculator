#include "header.h"



Button mainMenuButtons[buttonCount] = {
    {300, 0, "Operatii cu vectori"},
    {300, 0, "Operatii cu matrici"},
    {300, 0, "Despre proiect"},
    {300, 0, "Iesire"}
};

Button submenuButtons[buttonCountVec - 1] = {
    {300, 0, "Adunarea elementelor"},
    {300, 0, "Scaderea elementelor"},
    {300, 0, "Produsul elementelor"},
    {300, 0, "Impartirea elementelor"},
    {300, 0, "Shiftare la dreapta"},
    {300, 0, "Shiftare la stanga"},
    {300, 0, "Bubble sort"},
    {300, 0, "Merge sort"},
    {300, 0, "Inapoi"},

};

Button additionalSubmenuButtons[buttonCountMat - 1] = {
    {300, 0, "Adunarea elementelor"},
    {300, 0, "Scaderea elementelor"},
    {300, 0, "Produsul elementelor"},
    {300, 0, "Impartirea elementelor"},
    {300, 0, "Determinant"},
    {300, 0, "Ridicarea la putere"},
    {300, 0, "Suma diagonalei principale"},
    {300, 0, "Suma diagonalei secundare"},
    {300, 0, "Suma deasupra diagonalei principale"},
    {300, 0, "Suma sub diagonala principala"},
    {300, 0, "Suma deasupra diagonalei secundare"},
    {300, 0, "Suma sub diagonala secundara"},
    {300, 0, "Produsul diagonalei principale"},
    {300, 0, "Produsul diagonalei secundare"},
    {300, 0, "Produsul deasupra diagonalei principale"},
    {300, 0, "Produsul sub diagonala principala"},
    {300, 0, "Produsul deasupra diagonalei secundare"},
    {300, 0, "Produsul sub diagonala secundara"},
    {300, 0, "Inversa"},
    {300, 0, "Transpusa"},
    {300, 0, "Adjuncta"},
    {300, 0, "Inapoi"},
};

Button Extras[1] = {
    {300, 0, "Inapoi"},

};

Button AlegereDeUnde[3]={ {300,0, "Genereaza o pereche aleatorie"}, {300,0,"Alege din Memorie"},{300, 0, "Inapoi"}};

void CenterButtons(Button buttons[], int count, int screenWidth, int screenHeight) {
    int totalHeight = count * buttonHeight + (count - 1) * spacing;
    int startY = (screenHeight - totalHeight) / 2 - 50;

    for (int i = 0; i < count; ++i) {
        buttons[i].x = (screenWidth - buttonWidth) / 2;
        buttons[i].y = startY + i * (buttonHeight + 10 + spacing);
    }
}

void CenterAdditionalButtons(Button buttons[], int count, int screenWidth, int screenHeight, int columns) {
    int totalHeight = count * buttonHeight + (count - 1) * spacing;
    int startY = (screenHeight - totalHeight) / 2 + 700;
    int startX = (screenWidth - columns * buttonWidth - (columns - 1) * spacing) / 2 - 250;

    for (int i = 0; i < count; ++i) {
        buttons[i].x = startX + (i % columns) * (buttonWidth + 180 + spacing);
        buttons[i].y = startY + (i / columns) * (buttonHeight + spacing);


    }
}

void DrawButtons(Button buttons[], int count) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, BLACK);
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);

    for (int i = 0; i < count; ++i) {
        bar(buttons[i].x, buttons[i].y, buttons[i].x + 150 + buttonWidth, buttons[i].y + buttonHeight);
        rectangle(buttons[i].x - 10, buttons[i].y - 10, buttons[i].x + buttonWidth + 160, buttons[i].y + buttonHeight + 10);
        rectangle(buttons[i].x - 15, buttons[i].y - 15, buttons[i].x + buttonWidth + 165, buttons[i].y + buttonHeight + 15);

        char buttonTextCopy[100];
        strcpy(buttonTextCopy, buttons[i].label);
        outtextxy(buttons[i].x + 100, buttons[i].y + 20, buttonTextCopy);
    }
}

int CheckButtonClick(Button buttons[], int count, int mouseX, int mouseY) {
    for (int i = 0; i < count; ++i) {
        if (mouseX >= buttons[i].x && mouseX <= buttons[i].x + buttonWidth &&
            mouseY >= buttons[i].y && mouseY <= buttons[i].y + buttonHeight) {
            return i;
        }
    }
    return -1;
}

void initVect( Vector& v, int dim, int xx, int yy)
{
    v.dim = dim;
    v.x = xx;
    v.y = yy;
    for(int i = 1; i <= v.dim; i++)
    {
        v.val[i] = rand()%99+1;
    }
}


void DrawMat2(matrice& M, matrice& N)
{
    char sir[10];
    for (int i=1; i<=M.nrLin; i++)
        for (int j=1; j<=M.nrCol; j++)
        {
            rectangle(M.x+(j-1)*latura,M.y+(i-1)*latura,M.x+j*latura,M.y+i*latura);
            {
                // itoa(M.elem[i][j],sir,10);
                sprintf(sir, "%d", M.elem[i][j]);
                outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);}}

    for (int i=1; i<=N.nrLin; i++)
        for (int j=1; j<=N.nrCol; j++)
        {
            rectangle(N.x+(j-1)*latura,N.y+(i-1)*latura,N.x+j*latura,N.y+i*latura);
            {
                // itoa(M.elem[i][j],sir,10);
                sprintf(sir,"%d", N.elem[i][j]);
                outtextxy(-5+N.x+(j-1)*latura+latura/2,-5+N.y+(i-1)*latura+latura/2,sir);}}

}


/*void deseneazaMat(matrice& M, bool aleatoriu)
{
    for (int i=1; i<=M.nrLin; i++)
        for (int j=1; j<=M.nrCol; j++)
        {
            rectangle(M.x+(j-1)*latura,M.y+(i-1)*latura,M.x+j*latura,M.y+i*latura);
        }
        delay(100);
    for (int i=1; i<=M.nrCol; i++)
        {for (int j=1; j<=M.nrLin; j++)
        {
            char sir[10];
            sprintf(sir, "%d", M.elem[i][j]);
            outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
        }delay(80);}
}
Asta este una dintre cele mai proaste piese de cod pe care am scris-o vreodata.*/




         void BasicSetUp(int CurrentPageSet,int&currentPage,Button*&currentButtons,int&currentButtonCount)
{
    currentPage = CurrentPageSet;
    currentButtons = Extras;
    currentButtonCount = 1;
    CenterButtons(Extras, 1, getmaxx() - 1200, getmaxy() + 800);
    readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, getmaxx(), getmaxy());
}


void RunMenu() {
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    initwindow(screenWidth, screenHeight, "BibMat");
    CenterButtons(mainMenuButtons, buttonCount, screenWidth - 150, screenHeight + 50);
    CenterButtons(submenuButtons, buttonCountVec - 1, screenWidth, screenHeight);
    CenterButtons(additionalSubmenuButtons, buttonCountMat - 1, screenWidth, screenHeight);

    int currentPage = 0;
    bool exitRequested = false;
    srand(time(NULL));

    while (!exitRequested) {
        cleardevice();

        Button* currentButtons;
        int currentButtonCount;

        if (currentPage == 0) {
            currentButtons = mainMenuButtons;
            currentButtonCount = buttonCount;
            readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat.jpg", 0, 0, screenWidth, screenHeight);
        } else if (currentPage == 1) {
            currentButtons = submenuButtons;
            currentButtonCount = buttonCountVec - 1;
            cleardevice();
             readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat4.jpg", 0, 0, screenWidth, screenHeight);
        } else if (currentPage == 2) {
            currentButtons = additionalSubmenuButtons;
            currentButtonCount = buttonCountMat - 1;
            CenterAdditionalButtons(additionalSubmenuButtons, buttonCountMat - 1, screenWidth, screenHeight, 3);
            readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat2.jpg", 0, 0, screenWidth, screenHeight);
        }else if(currentPage == 3){
            setfillstyle(LTSLASH_FILL,YELLOW);
            floodfill(1,1,YELLOW);
            outtextxy(10,10,"BibMat(Biblioteca Matematica) este un program care rolul de a efectua diverse operatii cu vectori si matrici.");
            outtextxy(10,28,"Proiectu; a fost realizat de catre Radu Stefan Alexandru, Cristian Andrei si Dinu Dragos, studenti in primul an, grupa A5.");
            outtextxy(10,46,"Instruirea studentilor a fost realizata de catre profesorul disciplinei 'Introducere in programare', Bogdan Patrut.");
             currentButtons = Extras;
             currentButtonCount = 1;
             CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
             readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat5.jpg", 0, 0, screenWidth, screenHeight);
        }else if(currentPage == 4){
             currentButtons = Extras;
             currentButtonCount = 1;
             CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
             readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
        }else if(currentPage == 5){
             currentButtons = Extras;
             currentButtonCount = 1;
             CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
             readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
        }
        DrawButtons(currentButtons, currentButtonCount);

        int mouseX, mouseY;
        while (!ismouseclick(WM_LBUTTONDOWN)) {
            delay(100);
        }
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);

        int clickedButton = CheckButtonClick(currentButtons, currentButtonCount, mouseX, mouseY);

        if (clickedButton != -1) {
            if (currentPage == 0) {
                if (clickedButton == buttonCount - 1) {
                    exitRequested = true;
                } else if (clickedButton == 0) {
                    currentPage = 1;
                } else if (clickedButton == 1) {
                    currentPage = 2;
                }else if(clickedButton = 2){
                    currentPage = 3;
                }
            } else if (currentPage == 1 && clickedButton == buttonCountVec - 2) {
                currentPage = 0;
            }else if(currentPage == 1 && clickedButton == 0){
                cout<<currentPage<<"->";
    ///AdunareVec
    srand(time(NULL));
    int nr_linii=1;
    int nr_coloane=rand()%8+1;
    initwindow(latura*nr_coloane*2+150,latura*nr_linii*2+150,"BibMatTabel");

    matrice A; matrice B; matrice C;
    InitMatRand(A,nr_linii, nr_coloane,50,50,true);cout<<endl;
    InitMatRand(B, nr_linii, nr_coloane,100+nr_coloane*latura,50,true);


    InitMatRand(C,nr_linii, nr_coloane,100+nr_coloane*latura,120+nr_linii*latura,false);

    for (int i=1;i<=A.nrLin;i++)
        for (int j=1;j<=A.nrCol;j++)
        C.elem[i][j]=A.elem[i][j]+B.elem[i][j];

    DrawMat2(A,B);
    ImparteEcranMat2(A,'+',true);
    Animatie(A,B,C,1);
    Celebreaza(C);
    Final(C);
    RunMenu();
                currentPage = 4;
                cout<<currentPage<<"# ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);




            }else if(currentPage == 4 && clickedButton == 0){
                cout<<currentPage<<"->";
                currentPage = 1;
                cout<<currentPage<<"% ";
            }else if(currentPage == 3 && clickedButton == 0){
                cout<<currentPage<<"->";
                currentPage = 0;
                cout<<currentPage<<"& ";
            }else if(currentPage == 1 && clickedButton == 1){
                cout<<currentPage<<"->";
    ///ScadereVec
    bool ok=false;
    srand(time(NULL));
    int nr_linii=1;
    int nr_coloane=rand()%8+1;
    initwindow(latura*nr_coloane*2+150,latura*nr_linii*2+150,"BibMatTabel");

    matrice A; matrice B; matrice C;
    AlegeDeUnde(A,nr_linii, nr_coloane,50,50,ok);
    if(ok==true);
    InitMatRand(A,nr_linii, nr_coloane,50,50,true);
    ok=false;
    AlegeDeUnde(B, nr_linii, nr_coloane,100+nr_coloane*latura,50,true);
    if(ok==true);
    InitMatRand(B, nr_linii, nr_coloane,100+nr_coloane*latura,50,true);

    InitMatRand(C,nr_linii, nr_coloane,100+nr_coloane*latura,120+nr_linii*latura,false);

    SubMat(A,B,C);

    DrawMat2(A,B);
    ImparteEcranMat2(A,'-',true);
    Animatie(A,B,C,2);
    Celebreaza(C);
    Final(C);
    RunMenu();
                currentPage = 4;
                cout<<currentPage<<"~ ";

                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
             }else if(currentPage == 1 && clickedButton == 2){
                 cout<<currentPage<<"->";
    ///ProdVec
    srand(time(NULL));
    int nr_linii=1;
    int nr_coloane=rand()%8+1;
    initwindow(latura*nr_coloane*2+150,latura*nr_linii*2+150,"BibMatTabel");

    matrice A; matrice B; matrice C;
    InitMatRand(A,nr_linii, nr_coloane,50,50,true);cout<<endl;
    InitMatRand(B, nr_linii, nr_coloane,100+nr_coloane*latura,50,true);
    InitMatRand(C,nr_linii, nr_coloane,100+nr_coloane*latura,120+nr_linii*latura,true);

    for(int j=1;j<=nr_coloane;j++)
        C.elem[1][j]=A.elem[1][j]*B.elem[1][j];

    DrawMat2(A,B);
    ImparteEcranMat2(A,'x',true);
    Animatie(A,B,C,3);
    Celebreaza(C);
    Final(C);
    RunMenu();
                currentPage = 4;
                cout<<currentPage<<"$ ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
             }else if(currentPage == 1 && clickedButton == 3){
                currentPage = 4;
                cout<<currentPage<<"##1 ";
    ///DivideVec
    srand(time(NULL));
    int nr_linii=1;
    int nr_coloane=rand()%8+1;
    initwindow(latura*nr_coloane*2+150,latura*nr_linii*2+150,"BibMatTabel");

    matrice A; matrice B; matrice C;
    InitMatRand(A,nr_linii, nr_coloane,50,50,true);cout<<endl;
    InitMatRand(B, nr_linii, nr_coloane,100+nr_coloane*latura,50,true);
    InitMatRand(C,nr_linii, nr_coloane,100+nr_coloane*latura,120+nr_linii*latura,false);

    for(int j=1;j<=nr_coloane;j++)
        C.elem[1][j]=A.elem[1][j]/B.elem[1][j];

    DrawMat2(A,B);
    ImparteEcranMat2(A,'/',true);
    Animatie(A,B,C,3);
    Celebreaza(C);
    Final(C);
    RunMenu();
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
             }else if(currentPage == 1 && clickedButton == 4){
                currentPage = 4;
                cout<<currentPage<<"##2 ";
    ///ShiftDrept
    srand(time(NULL));
    char sir[50];
    int nr_linii=1;
    int nr_coloane=rand()%4+5;
    int pos=rand()%4+1;
    initwindow(latura*nr_coloane*2+150,latura*2+150,"BibMatTabel");

    matrice A; matrice C;
    InitMatRand(A,1, nr_coloane,getmaxx()/2-latura*(nr_coloane/2)-(latura/2)*(nr_coloane%2),50,true);cout<<endl;
    InitMatRand(C,1, nr_coloane,100+nr_coloane*latura,120+latura,false);

    for(int nr=1;nr<=nr_coloane;nr++)
        C.elem[1][nr]=A.elem[1][nr];
        RightShiftVec(C,pos);

    DrawMat1(A);
        sprintf(sir,"Nr. pozitii shiftate: %d",pos);
        outtextxy(A.x-15,A.y-30,sir);
        line(A.x-15,35,A.x-15+textwidth("Nr. pozitii shiftate: 9"),35);
    ImparteEcranMat2(A,'0',false);
    Animatie3(A,C,pos);
    Celebreaza(C);
    Final(C);
    RunMenu();
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
             }else if(currentPage == 1 && clickedButton == 5){
                currentPage = 4;
    ///ShiftStang
    srand(time(NULL));
    char sir[50];
    int nr_linii=rand()%4+5;
    int nr_coloane=rand()%4+5;
    int pos=rand()%4+1;
    initwindow(latura*nr_coloane*2+150,latura*2+150,"BibMatTabel");

    matrice A; matrice C;
    InitMatRand(A,1, nr_coloane,getmaxx()/2-latura*(nr_coloane/2)-(latura/2)*(nr_coloane%2),50,true);cout<<endl;
    InitMatRand(C,1, nr_coloane,100+nr_coloane*latura,120+latura,false);

    for(int nr=1;nr<=nr_coloane;nr++)
        C.elem[1][nr]=A.elem[1][nr];
        LeftShiftVec(C,pos);

    DrawMat1(A);
        sprintf(sir,"Nr. pozitii shiftate: %d",pos);
        outtextxy(A.x-15,A.y-30,sir);
        line(A.x-15,35,A.x-15+textwidth("Nr. pozitii shiftate: 9"),35);
    ImparteEcranMat2(A,'0',false);
    Animatie3(A,C,pos);
    Celebreaza(C);
    Final(C);
    RunMenu();

                cout<<currentPage<<"##3 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
             }else if(currentPage == 1 && clickedButton == 6){
                currentPage = 4;
    ///BubbleSortVec
    srand(time(NULL));
    int nr_linii=1;
    int nr_coloane=8;
    initwindow(latura*nr_coloane*2+150,latura+150,"BibMatTabel");

    matrice A;
    InitMatRand(A,1, nr_coloane,getmaxx()/2-latura*(nr_coloane/2),50,true);cout<<endl;

    rectangle(5,5,getmaxx()-5,getmaxy()-5);
    floodfill (1,1, WHITE);
    rectangle(7,7,getmaxx()-7,getmaxy()-7);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill (6,6,WHITE);

    DrawMat1(A);
        setfillstyle(XHATCH_FILL,DARKGRAY);
        floodfill (8,8,WHITE);
    AnimatieSiCalculBuble(A);
    Celebreaza(A);
    Final(A);
    RunMenu();
                cout<<currentPage<<"##4 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 1 && clickedButton == 7){
                currentPage = 4;
    ///NuMaiStiuCeNaibaSeAflaAiciVec
    srand(time(NULL));
    int nr_linii=1;
    int nr_coloane=8;
    initwindow(latura*nr_coloane*2+150,latura+150,"BibMatTabel");

    matrice A;
    InitMatRand(A,1, nr_coloane,getmaxx()/2-latura*(nr_coloane/2),50,true);cout<<endl;

    rectangle(5,5,getmaxx()-5,getmaxy()-5);
    floodfill (1,1, WHITE);
    rectangle(7,7,getmaxx()-7,getmaxy()-7);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill (6,6,WHITE);

    DrawMat1(A);
        setfillstyle(XHATCH_FILL,DARKGRAY);
        floodfill (8,8,WHITE);
    AnimatieSiCalculMerge(A,1,A.nrCol,3);
    Celebreaza(A);
    Final(A);
    RunMenu();
                cout<<currentPage<<"##5 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 1 && clickedButton == buttonCountVec - 1){
                cleardevice();
                currentPage = 3;
                setbkcolor(BLACK);
            } else if (currentPage == 2 && clickedButton == buttonCountMat - 2) {
                currentPage = 0;
            }else if(currentPage == 2 && clickedButton == 0){
                cout<<currentPage<<"->";
                int nr_linii=1;
    ///AdunareMat


    ///~Tutorial: AlegeDeUnde~///
    /// Tasta cu > duce la dreapta, tasta , inapoi la inceput.
    /// 1. Selecteaza, 2.nimic momentan, 3.construieste una random, 75% sanse sa dea crash
    srand(time(NULL));
    nr_linii=rand()%8+1;
    int nr_coloane=rand()%8+1;

    bool ok=false;
   initwindow(latura*nr_coloane*2+150,latura*nr_linii*2+150,"BibMatTabel");

        matrice A; matrice B; matrice C;
        ///TEST FISERE

    AlegeDeUnde(A,50,50,nr_linii,nr_coloane,ok);
    if( ok==true )
    InitMatRand(A,nr_linii, nr_coloane,50,50,true);cout<<endl;


    InitMatRand(B, nr_linii, nr_coloane,100+nr_coloane*latura,50,true);
    InitMatRand(C,nr_linii, nr_coloane,100+nr_coloane*latura,120+nr_linii*latura,false);
    //AlegeDeUnde(A,nr_linii, nr_coloane,50,50,ok);

    for (int i=1;i<=A.nrLin;i++)
        for (int j=1;j<=A.nrCol;j++)
        C.elem[i][j]=A.elem[i][j]+B.elem[i][j];

    DrawMat2(A,B);
    ImparteEcranMat2(A,'+',true);
    Animatie(A,B,C,1);
    Celebreaza(C);
    Final(C);
    RunMenu();
                currentPage = 5;
                cout<<currentPage<<"^^ ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 5 && clickedButton == 0){\
                cout<<currentPage<<"->";
                currentPage = 2;
                cout<<currentPage<<"| ";
            }else if(currentPage == 2 && clickedButton == 1){
                cout<<currentPage<<"->";
    ///ScadereMat
    srand(time(NULL));
    int nr_linii=rand()%8+1;
    int nr_coloane=rand()%8+1;
    initwindow(latura*nr_coloane*2+150,latura*nr_linii*2+150,"BibMatTabel");

    matrice A; matrice B; matrice C;
    InitMatRand(A,nr_linii, nr_coloane,50,50,true);cout<<endl;
    InitMatRand(B, nr_linii, nr_coloane,100+nr_coloane*latura,50,true);
    InitMatRand(C,nr_linii, nr_coloane,100+nr_coloane*latura,120+nr_linii*latura,false);

    SubMat(A,B,C);

    DrawMat2(A,B);
    ImparteEcranMat2(A,'-',true);
    Animatie(A,B,C,2);
    Celebreaza(C);
    Final(C);
    RunMenu();
                currentPage = 5;
                cout<<currentPage<<"@ ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 2){
    ///ProdusMat...De ce e pagina asta diferita?
    srand(time(NULL));
    int nr_comun=rand()%7+2;
    int nr_linii_A=rand()%7+2;
    int nr_col_B=rand()%7+2;
    int max_lin=max(nr_comun,nr_linii_A);
    int max_col=max(nr_comun,nr_col_B);
    initwindow(latura*max_col*2+150,latura*max_lin*2+150,"BibMatTabel");

    matrice A; matrice B; matrice C;
    InitMatSpec(A,nr_linii_A, nr_comun,50,50,8,1);
    InitMatSpec(B, nr_comun, nr_col_B,100+nr_comun*latura,50,8,1);
    InitMatRand(C,nr_linii_A, nr_col_B,100+max_col*latura,120+max_lin*latura,false);

    ProdMat(A,B,C);

    DrawMat2(A,B);
    ImparteEcranMat2(A,'x',true);
    Animatie2(A,B,C,1);
    Celebreaza(C);
    Final(C);
    RunMenu();
                currentPage = 5;
                cout<<currentPage<<"##6 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 3){
                currentPage = 5;
    ///ÎmpărțireMat
    srand(time(NULL));
    int nr_tot=rand()%7+1;
    initwindow(latura*nr_tot*2+150,latura*nr_tot*2+150,"BibMatTabel");

    matrice A; matrice B; matrice C;
    InitMatRand(A,nr_tot, nr_tot,50,50,true);cout<<endl;
    InitMatRand(B, nr_tot, nr_tot,100+nr_tot*latura,50,true);
    InitMatRand(C,nr_tot, nr_tot,100+nr_tot*latura,120+nr_tot*latura,true);

    DivMat(A,B,C);

    DrawMat2(A,B);
    ImparteEcranMat2(A,'/',true);
    Animatie2(A,B,C,1);
    Celebreaza(C);
    Final(C);
    RunMenu();
                cout<<currentPage<<"##7 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 4){
                currentPage = 5;
    ///DeterMat
    srand(time(NULL));
    char sir[50];
    int nr_linii=rand()%3+3;
    int nr_coloane=nr_linii;
    initwindow(latura*nr_coloane+100,latura*nr_linii+150,"BibMatTabel");

    matrice A; matrice C;
    InitMatRand(A,nr_linii, nr_coloane,getmaxx()/2-latura*(nr_coloane/2)-(latura/2)*(nr_coloane%2),50,true);cout<<endl;
    InitMatRand(C,nr_linii, nr_coloane,100+nr_coloane*latura,120+latura,false);

    rectangle(5,5,getmaxx()-5,getmaxy()-5);
    floodfill (1,1, WHITE);
    rectangle(7,7,getmaxx()-7,getmaxy()-7);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill (6,6,WHITE);

    DrawMat1(A);
    setfillstyle(XHATCH_FILL,DARKGRAY);
    floodfill (8,8,WHITE);

    AnimatieDeter(A);

    sprintf(sir,"Determinantul Matricei este: %d",DeterMat(A));
    setcolor(YELLOW);
    outtextxy(getmaxx()/2-(textwidth("Determinantul Matricei este: 99")/2),getmaxy()-40,sir);
    getch();
    RunMenu();

                cout<<currentPage<<"##8 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 5){
                currentPage = 5;
    ///MatLaPow
    srand(time(NULL));
    char sir[50];
    int nr_comun=rand()%2+2;
    int nr_linii_A=nr_comun;
    int x=rand()%3+2;
    initwindow(latura*nr_comun*2+150,latura*nr_linii_A*2+150,"BibMatTabel");

    matrice A; matrice B; matrice C;
    InitMatSpec(A,nr_linii_A, nr_comun,50,50,2,1);
    InitMatRand(B, A.nrLin, A.nrCol,100+A.nrCol*latura,50,false);
    InitMatRand(C,A.nrLin,A.nrCol,100+A.nrCol*latura,120+A.nrLin*latura,false);

    for(int i=1; i<=A.nrLin;i++)
        for(int j=1; j<=A.nrCol; j++)
        {B.elem[i][j]=A.elem[i][j], C.elem[i][j]=A.elem[i][j]; }

    PowMat(C,x);

    DrawMat2(A,B);
    ImparteEcranMat2(A,'x',true);
    sprintf(sir,"Puterea este: %d",x);
    setcolor(YELLOW);
    outtextxy(C.x,C.y+latura*C.nrLin+5,sir);
    line(C.x,C.y+latura*C.nrLin+25,C.x+textwidth("Puterea este: 9"),C.y+latura*C.nrLin+25);
    setcolor(WHITE);

    Animatie2(A,B,C,1);

    Celebreaza(C);
    Final(C);
    RunMenu();

                cout<<currentPage<<"##9 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 6){
                currentPage = 5;
                 cout<<currentPage<<"##800 ";
    ///SumDiagPrin
    srand(time(NULL));
    char sir[50];
    int nr_linii=rand()%6+3;
    int nr_coloane=nr_linii;
    initwindow(latura*nr_linii+100,latura*2*nr_linii+150,"BibMatTabel");

    matrice A; matrice C;
    InitMatRand(A,nr_linii, nr_coloane,getmaxx()/2-latura*(nr_coloane/2)-(latura/2)*(nr_coloane%2),50,true);cout<<endl;
    InitMatRand(C,nr_linii, nr_coloane,100+nr_coloane*latura,120+latura,false);

    DrawMat1(A);
    ImparteEcranMat2(A,'0',false);
    Animatie100(A,0,'s',1);

    int rez=DiagSum(A);
    Rezultat(sir,rez);

    getch();
    RunMenu();


                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 7){
                currentPage = 5;
                cout<<currentPage<<"##69 ";

    ///SumDiagSec
    srand(time(NULL));
    char sir[50];
    int nr_linii=rand()%6+3;
    int nr_coloane=nr_linii;
    initwindow(latura*nr_linii+100,latura*2*nr_linii+150,"BibMatTabel");

    matrice A; matrice C;
    InitMatRand(A,nr_linii, nr_linii,getmaxx()/2-latura*(nr_coloane/2)-(latura/2)*(nr_coloane%2),50,true);cout<<endl;
    InitMatRand(C,nr_linii, nr_coloane,100+nr_coloane*latura,120+latura,false);

    DrawMat1(A);
    ImparteEcranMat2(A,'0',false);
    Animatie100(A,0,'s',2);

    int rez=DiagSecSum(A);
    Rezultat(sir,rez);

    getch();
    RunMenu();



                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 8){
                currentPage = 5;
                cout<<currentPage<<"##10 ";
///SumoverdiagPr
    srand(time(NULL));
    char sir[50];
    int nr_linii=rand()%6+3;
    int nr_coloane=nr_linii;
    initwindow(latura*nr_linii+100,latura*2*nr_linii+150,"BibMatTabel");

    matrice A; matrice C;
    InitMatRand(A,nr_linii, nr_coloane,getmaxx()/2-latura*(nr_coloane/2)-(latura/2)*(nr_coloane%2),50,true);cout<<endl;
    InitMatRand(C,nr_linii, nr_coloane,100+nr_coloane*latura,120+latura,false);

    DrawMat1(A);
    ImparteEcranMat2(A,'0',false);
    Animatie100(A,1,'s',3);

    int rez=SumOverDiag(A);
    Rezultat(sir,rez);

    getch();
    RunMenu();

                cout<<currentPage<<"##10 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 9){
                currentPage = 5;
                cout<<currentPage<<"##11 ";
   ///suma sub diag prin
                srand(time(NULL));
    char sir[50];
    int nr_linii=rand()%7+2;
    int nr_coloane=nr_linii;
    matrice A;
    srand(time(NULL));
    initwindow(latura*nr_linii+100,latura*2*nr_linii+150,"BibMatTabel");
    matrice C;
    InitMatRand(A,nr_linii, nr_linii,getmaxx()/2-latura*(nr_coloane/2)-(latura/2)*(nr_coloane%2),50,true);cout<<endl;
    InitMatRand(C,nr_linii, nr_linii,100+nr_coloane*latura,120+latura,false);

    DrawMat1(A);
    ImparteEcranMat2(A,'0',false);
    Animatie100(A,1,'s',4);

    int rez=SumUnderDiag(A);
    Rezultat(sir,rez);

    getch();
    RunMenu();

   getch();
    RunMenu();

                cout<<currentPage<<"##11 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 10){
                currentPage = 5;
                ///
                cout<<currentPage<<"##12 ";

                 srand(time(NULL));
    char sir[50];
    int nr_linii=rand()%7+2;
    int nr_coloane=nr_linii;
    matrice A;
    srand(time(NULL));
    initwindow(latura*nr_linii+100,latura*2*nr_linii+150,"BibMatTabel");
    matrice C;
    InitMatRand(A,nr_linii, nr_linii,getmaxx()/2-latura*(nr_linii/2)-(latura/2)*(nr_coloane%2),50,true);cout<<endl;
    InitMatRand(C,nr_linii, nr_linii,100+nr_coloane*latura,120+latura,false);

    DrawMat1(A);
    ImparteEcranMat2(A,'0',false);
    Animatie100(A,-1,'s',5);

    int rez=SumOverDiag(A);
    Rezultat(sir,rez);


   getch();
    RunMenu();


                cout<<currentPage<<"##12 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 11){
                currentPage = 5;
                cout<<currentPage<<"##13 ";
                    srand(time(NULL));
    char sir[50];
    int nr_linii=rand()%7+2;
    int nr_coloane=nr_linii;
    matrice A;
    srand(time(NULL));
    initwindow(latura*nr_linii+100,latura*2*nr_linii+150,"BibMatTabel");
    matrice C;
    InitMatRand(A,nr_linii, nr_linii,getmaxx()/2-latura*(nr_linii/2)-(latura/2)*(nr_coloane%2),50,true);cout<<endl;
    InitMatRand(C,nr_linii, nr_linii,100+nr_coloane*latura,120+latura,false);

    DrawMat1(A);
    ImparteEcranMat2(A,'0',false);
    Animatie100(A,-1,'s',7);

    int rez=SumUnderDiag(A);
    Rezultat(sir,rez);


   getch();
    RunMenu();

                cout<<currentPage<<"##13 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 12){
                currentPage = 5;
                cout<<currentPage<<"##14 ";
                    srand(time(NULL));
    char sir[50];
    int nr_linii=rand()%7+2;
    int nr_coloane=nr_linii;
    matrice A;
    srand(time(NULL));
    initwindow(latura*nr_linii+100,latura*2*nr_linii+150,"BibMatTabel");
    matrice C;
    InitMatRand(A,nr_linii, nr_linii,getmaxx()/2-latura*(nr_linii/2)-(latura/2)*(nr_coloane%2),50,true);cout<<endl;
    InitMatRand(C,nr_linii, nr_linii,100+nr_coloane*latura,120+latura,false);

    DrawMat1(A);
    ImparteEcranMat2(A,'0',false);
    Animatie100(A,0,'p',8);

    int rez=DiagSecProd(A);
    Rezultat(sir,rez);


   getch();
    RunMenu();


                cout<<currentPage<<"##14 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 13){
                currentPage = 5;
                    srand(time(NULL));
                    cout<<currentPage<<"##15 ";
    char sir[50];
    int nr_linii=rand()%7+2;
    int nr_coloane=nr_linii;
  initwindow(latura*nr_linii+100,latura*2*nr_linii+150,"BibMatTabel");

    matrice A;matrice C;

    InitMatRand(A,nr_linii, nr_linii,getmaxx()/2-latura*(nr_linii/2)-(latura/2)*(nr_coloane%2),50,true);cout<<endl;
    InitMatRand(C,nr_linii, nr_linii,100+nr_coloane*latura,120+latura,false);

    DrawMat1(A);
    ImparteEcranMat2(A,'0',false);
    Animatie100(A,0,'p',10);

    int rez=DiagSecProd(A);
    Rezultat(sir,rez);


   getch();
    RunMenu();

                cout<<currentPage<<"##15 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 14){
                currentPage = 5;
                    srand(time(NULL));
                    cout<<currentPage<<"##16 ";
    char sir[50];
    int nr_linii=rand()%7+2;
    int nr_coloane=nr_linii;
  initwindow(latura*nr_linii+100,latura*2*nr_linii+150,"BibMatTabel");

    matrice A;matrice C;

    InitMatRand(A,nr_linii, nr_linii,getmaxx()/2-latura*(nr_linii/2)-(latura/2)*(nr_coloane%2),50,true);cout<<endl;
    InitMatRand(C,nr_linii, nr_linii,100+nr_coloane*latura,120+latura,false);

    DrawMat1(A);
    ImparteEcranMat2(A,'0',false);
    Animatie100(A,1,'p',10);

    int rez=ProdOverDiag(A);
    Rezultat(sir,rez);


   getch();
    RunMenu();


                cout<<currentPage<<"##16 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 15){
                currentPage = 5;
                    srand(time(NULL));
                    cout<<currentPage<<"##17 ";

                        char sir[50];
    int nr_linii=rand()%7+2;
    int nr_coloane=nr_linii;
  initwindow(latura*nr_linii+100,latura*2*nr_linii+150,"BibMatTabel");

    matrice A;matrice C;

    InitMatRand(A,nr_linii, nr_linii,getmaxx()/2-latura*(nr_linii/2)-(latura/2)*(nr_coloane%2),50,true);cout<<endl;
    InitMatRand(C,nr_linii, nr_linii,100+nr_coloane*latura,120+latura,false);

    DrawMat1(A);
    ImparteEcranMat2(A,'0',false);
    Animatie100(A,1,'p',11);

    int rez=ProdOverDiag(A);
    Rezultat(sir,rez);


   getch();
    RunMenu();


                cout<<currentPage<<"##17 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 16){
                currentPage = 5;
                  cout<<currentPage<<"##18 ";
                        char sir[50];
    int nr_linii=rand()%7+2;
    int nr_coloane=nr_linii;
  initwindow(latura*nr_linii+100,latura*2*nr_linii+150,"BibMatTabel");

    matrice A;matrice C;

    InitMatRand(A,nr_linii, nr_linii,getmaxx()/2-latura*(nr_linii/2)-(latura/2)*(nr_coloane%2),50,true);cout<<endl;
    InitMatRand(C,nr_linii, nr_linii,100+nr_coloane*latura,120+latura,false);

    DrawMat1(A);
    ImparteEcranMat2(A,'0',false);
    Animatie100(A,-1,'p',12);

    int rez=ProdOverSec(A);
    Rezultat(sir,rez);


   getch();
    RunMenu();

                cout<<currentPage<<"##18 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 17){
                currentPage = 5;
                cout<<currentPage<<"##19 ";
    char sir [50];
   int nr_linii=rand()%7+2;
    int nr_coloane=nr_linii;
  initwindow(latura*nr_linii+100,latura*2*nr_linii+150,"BibMatTabel");

    matrice A;matrice C;

    InitMatRand(A,nr_linii, nr_linii,getmaxx()/2-latura*(nr_linii/2)-(latura/2)*(nr_coloane%2),50,true);cout<<endl;
    InitMatRand(C,nr_linii, nr_linii,100+nr_coloane*latura,120+latura,false);

    DrawMat1(A);
    ImparteEcranMat2(A,'0',false);
    Animatie100(A,-1,'p',13);

    int rez=ProdUnderSec(A);
    Rezultat(sir,rez);


   getch();
    RunMenu();
                cout<<currentPage<<"##19 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 18){
                currentPage = 5;
                cout<<currentPage<<"##20 ";
                    srand(time(NULL));

    srand(time(NULL));
    int nr_linii=rand()%7+2;
    int nr_coloane=rand()%7+2;

   initwindow(latura*nr_coloane+100,latura*nr_linii+100,"BibMatTabel");

    matrice A;matrice C;
    InitMatRand(A,nr_linii, nr_coloane,50,50,true);
    InitMatRand(C,nr_linii, nr_coloane,100+nr_coloane*latura,120+nr_linii*latura,false);

    setcolor(WHITE);
    rectangle(10,10,getmaxx()-10,getmaxy()-10);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(1,1,WHITE);
    setfillstyle(LTSLASH_FILL,DARKGRAY);
    floodfill(11,11,WHITE);

    DrawMat1(A);
    delay(500);
    InvMat(A);
    DrawMat1(A);
    Celebreaza(A);
    Final(A);
    RunMenu();
                cout<<currentPage<<"##20 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 19){
                currentPage = 5;
                cout<<currentPage<<"##21 ";
                    srand(time(NULL));

    srand(time(NULL));
    int nr_linii=rand()%7+2;
    int nr_coloane=rand()%7+2;

   initwindow(latura*nr_coloane+100,latura*nr_linii+100,"BibMatTabel");

    matrice A; matrice C;
    InitMatRand(A,nr_linii, nr_coloane,50,50,true);
    InitMatRand(C,nr_linii, nr_coloane,100+nr_coloane*latura,120+nr_linii*latura,false);
    setcolor(WHITE);
    rectangle(10,10,getmaxx()-10,getmaxy()-10);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(1,1,WHITE);
    setfillstyle(LTSLASH_FILL,DARKGRAY);
    floodfill(11,11,WHITE);

    DrawMat1(A);
    delay(500);
    TraMat(A);
    DrawMat1(A);
    Celebreaza(A);
    Final(A);
    RunMenu();
                cout<<currentPage<<"##21 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 20){
                currentPage = 5;
                cout<<currentPage<<"##22 ";
                    srand(time(NULL));
                    srand(time(NULL));

    srand(time(NULL));
    int nr_linii=rand()%7+2;
    int nr_coloane=rand()%7+2;

   initwindow(latura*nr_coloane+100,latura*nr_linii+100,"BibMatTabel");

    matrice A; matrice C;
    InitMatRand(A,nr_linii, nr_coloane,50,50,true);
    InitMatRand(C,nr_linii, nr_coloane,100+nr_coloane*latura,120+nr_linii*latura,false);
    setcolor(WHITE);
    rectangle(10,10,getmaxx()-10,getmaxy()-10);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(1,1,WHITE);
    setfillstyle(LTSLASH_FILL,DARKGRAY);
    floodfill(11,11,WHITE);

    DrawMat1(A);
    delay(500);
    AdjMat(A);
    DrawMat1(A);
    Celebreaza(A);
    Final(A);
    RunMenu();

                cout<<currentPage<<"##22 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 2 && clickedButton == 21){
                currentPage = 5;
                cout<<currentPage<<"##23 ";
                    srand(time(NULL));
    char sir[50];
    int nr_linii=1;
    int nr_coloane=rand()%4+5;
    int pos=rand()%4+1;
    initwindow(latura*nr_coloane*2+150,latura*2+150,"BibMatTabel");

    matrice A; matrice C;
    InitMatRand(A,1, nr_coloane,getmaxx()/2-latura*(nr_coloane/2)-(latura/2)*(nr_coloane%2),50,true);cout<<endl;
    InitMatRand(C,1, nr_coloane,100+nr_coloane*latura,120+latura,false);

    for(int nr=1;nr<=nr_coloane;nr++)
        C.elem[1][nr]=A.elem[1][nr];
        LeftShiftVec(C,pos);

    DrawMat1(A);
        sprintf(sir,"Nr. pozitii shiftate: %d",pos);
        outtextxy(A.x-15,A.y-30,sir);
        line(A.x-15,35,A.x-15+textwidth("Nr. pozitii shiftate: 9"),35);
    ImparteEcranMat2(A,'0',false);
    Animatie3(A,C,pos);
    Celebreaza(C);
    Final(C);
    RunMenu();

                cout<<currentPage<<"##23 ";
                currentButtons = Extras;
                currentButtonCount = 1;
                CenterButtons(Extras, 1, screenWidth - 1200, screenHeight + 800);
                readimagefile("C:\\Users\\ADmin\\Downloads\\BibMat6.jpg", 0, 0, screenWidth, screenHeight);
            }else if(currentPage == 3 && clickedButton == 20){
                currentPage = 0;

            }
        }
    }
    closegraph();
}


int main() {

    RunMenu();
    return 0;
}
