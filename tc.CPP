#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
int w=50,z=440,p,q,s,pt=50;
int h,g;
char *a;
void score()
{
  
  if(s==0 && p<=90 && p>=50)
      pt+=10;
  else if(s==1 && p>=150 && p<=190 )
	  pt+=10;
  else if(s==2 && p>=270 && p<=310)
	       pt+=10;
  else if(s==3 && p>=390&&p<=430)
                     pt+=10;
  else 
	pt-=10;
  
   if(pt==0)
   {
    cleardevice();
    setcolor(15);
    outtextxy(120,100,"GAME OVER");
    getch();exit(1);
   }
 	   setfillstyle(1,4);
	   fillellipse(580,130,40,30);
	   itoa(pt,a,10);
	   outtextxy(560,110,a);

}
void drawb(int x,int y)
{
	int poly[8];
	poly[0]=x;
	poly[1]=y;
	poly[2]=x+10;
	poly[3]=y+40;
	poly[4]=x+50;
	poly[5]=y+40;
	poly[6]=x+60;
	poly[7]=y;
	setcolor(15);
	setfillstyle(SOLID_FILL,13);
	fillpoly(4,poly);
	//drawobject(x+10,y);
	setcolor(2);
}

void drawflow(int x,int y)
{
	line(x+20,y+20,x+40,y);
	setcolor(15);
	setfillstyle(SOLID_FILL,14);
	fillellipse(x+20,y+10,10,10);
	fillellipse(x+20,y+30,10,10);
	fillellipse(x+10,y+20,10,10);
	fillellipse(x+30,y+20,10,10);
	setfillstyle(SOLID_FILL,4);
	fillellipse(x+20,y+20,10,10);
	setcolor(2);
 }
void drawfruit(int x,int y)
{
	setcolor(15);
	line(x+20,y+10,x+8,y+32);
	line(x+20,y+10,x+32,y+32);
	setfillstyle(SOLID_FILL,4);
	fillellipse(x+8,y+32,8,8);
	fillellipse(x+32,y+32,8,8);
	setcolor(2);
}
void drawchoc(int x,int y)
{
	setcolor(15);
	int poly1[6],poly2[8],poly3[6];
	poly1[0]=x; poly1[1]=y+10;
	poly1[2]=x; poly1[3]=y+30;
	poly1[4]=x+10; poly1[5]=y+20;

	poly2[0]=x+10; poly2[1]=y+10;
	poly2[2]=x+10; poly2[3]=y+30;
	poly2[4]=x+30; poly2[5]=y+30;
	poly2[6]=x+30; poly2[7]=y+10;

	poly3[0]=x+30; poly3[1]=y+20;
	poly3[2]=x+40; poly3[3]=y+10;
	poly3[4]=x+40; poly3[5]=y+30;

	setfillstyle(SOLID_FILL,3);
	fillpoly(3,poly1);
	fillpoly(4,poly2);
	fillpoly(3,poly3);
        setcolor(2);
 }
void drawbisc(int x,int y)
{
	setcolor(15);
        setfillstyle(SOLID_FILL,6);
	fillellipse(x+20,y+20,20,20);
	putpixel(x+12,y+13,0);
	putpixel(x+12,y+26,0);
	putpixel(x+30,y+13,0);
	putpixel(x+30,y+26,0);
        setcolor(2);
}


int ran()
{
	randomize();
	return rand()%4;
}
void obj(int s)
{
			switch(s)
			{
				case 0: drawchoc(p,q);
					break;
				case 1: drawbisc(p,q);
					break;
				case 2: drawflow(p,q);
					break;
				case 3: drawfruit(p,q);
					break;
			}
}
void draw()
{
		       int  i,r[8];

			r[0]=0;r[1]=0;
			r[2]=0;r[3]=440;
			r[4]=540;r[5]=440;
			r[6]=540;r[7]=0;
			setfillstyle(1,2);
			fillpoly(4,r);
			setcolor(4);
			line(0,400,540,400);
			obj(s);
}

void func()
{
	char ch;
	       while(1)
		{



			if((kbhit()!=0)&&(q<360))

				 ch=getche();
			 switch(ch)
				{
					case 75: p=p-20;
						 q=q+5;
						 draw();

						 break;

					case 77: p=p+20;

						 draw();
						 break;
					case 'q': exit(0);
                                                  
                                         default: q=q+5;
						 draw();
 						 break;
				}
			  ch='\0';


			delay(g);
			if(p<=0||p>=500)

			{
				cleardevice();
				settextstyle(1,0,5);
				outtextxy(300,300,"GAME OVER");
				getch();
				getch();
				exit(1);
			}
			if(q>395)
			{
			  score();
			  return;
			}
		}

}
void game(void)
{
  FILE *fp=fopen("help.txt","r");
  char *z,c1,c2,c3;
  pqr:
  cleardevice();
  setbkcolor(2);
  setcolor(5);
  settextstyle(1,0,3);
  outtextxy(200,1,"THING COLLECTOR");
  setcolor(15);
  outtextxy(230,30,"MAIN MENU");
  outtextxy(60,60,"START");
  outtextxy(60,100,"HELP");
  outtextxy(60,140,"QUIT");
  settextstyle(4,0,3);
  outtextxy(30,360,"press 's' to start the game");
  outtextxy(30,380,"press 'h' for help");
  outtextxy(30,400,"press 'q' to quit the game");
  c3=getch();
  switch(c3)
  {
   case 's': cleardevice();
	     asd:
	     setbkcolor(2);
	     settextstyle(1,0,3);
	     outtextxy(1,1,"Select the Level");
	     outtextxy(50,50,"1.Beginner");
	     outtextxy(50,90,"2.Intermediate");
	     outtextxy(50,130,"3.Expert");

	     settextstyle(4,0,3);
	     outtextxy(50,270,"Press Coressponding Level Numbers");
	     outtextxy(50,300," To Enter In To The Game ");
	     *z=getch();
	     h=atoi(z);
	     if(h==1)
		g=50;
	     else if(h==2)
		     g=30;
		  else if(h==3)
			  g=15;
		       else
			 goto asd;
	   return;
   case 'h':cleardevice();
	    setbkcolor(4);
	    while(!feof(fp))
	    {
	     c2=getc(fp);
	     printf("%c",c2);
	    }
	    rewind(fp);
	    getch();
	    goto pqr;
   case 'q':klm:
	    outtextxy(120,180,"Are you sure,you want to quit the game?");
	    outtextxy(150,200,"Yes");
	    outtextxy(340,200,"No");
	    c1=getch();
	    if(c1=='y')
	       exit(1);
	    else if(c1=='n')
		    goto pqr;
		 else
		     goto klm;
   default  :goto pqr;
  }
}

void main()
{
  int gd=DETECT,gm,ec;
  initgraph(&gd,&gm,"");
  ec=graphresult();
  if(ec!=grOk)
  {
   printf("Graphic error");
   exit(0);
  }
  int r[8];//x=50,y=440;

   game();
    setbkcolor(0);
    setviewport(0,0,540,440,0);
    int k,i;p=250;q=0;

		r[0]=0;r[1]=440;
			r[2]=0;r[3]=480;
			r[4]=540;r[5]=480;
			r[6]=540;r[7]=440;
			setcolor(2);
			setfillstyle(1,2);
			fillpoly(4,r);

		       for(i=0,w=50;i<4;i++,w+=120)
			   drawb(w,z);
			drawchoc(60,440);
			drawflow(300,440);
			drawbisc(180,440);
			drawfruit(420,440);
	   outtextxy(560,40,"SCORE");
	   setfillstyle(1,4);
	   fillellipse(580,130,40,30);
	   itoa(pt,a,10);
	   outtextxy(560,110,a);

      while(1)
	{
		s=ran();
		p=250;q=0;
		draw();
		func();
	 }

 }