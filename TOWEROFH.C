#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#define max 22
int n=0,lim,c=0;
int tower[max][3];
typedef struct stack
{
int s[max];
int tos;
}stack;
/////////////////////////////////push/////////////////////////////////////
void push1(stack*t1,int ele)
{
t1->s[++t1->tos]=ele;
}

void push2(stack*t2,int ele)
{
t2->s[++t2->tos]=ele;
}

void push3(stack*t3,int ele)
{
t3->s[++t3->tos]=ele;
}

void pusht(stack*t,int ele)
{
t->s[++t->tos]=ele;
}

//////////////////////////////////isempty//////////////////////////////////////

int isempty1(stack*t1)
{
return(t1->tos==-1);
}

int isempty2(stack*t2)
{
return(t2->tos==-1);
}

int isempty3(stack*t3)
{
return(t3->tos==-1);
}

////////////////////////////////////pop/////////////////////////////////////
int pop1(stack*t1)
{int ele;
ele=t1->s[t1->tos];
//t1->s[t1->tos] = 0;
t1->tos--;
return ele;
}


int pop2(stack*t2)
{int ele;
ele=t2->s[t2->tos];
//t2->s[t2->tos] = 0;
t2->tos--;
return ele;
}

int pop3(stack*t3)
{int ele;
ele=t3->s[t3->tos];
//t3->s[t3->tos] = 0;
t3->tos--;
return ele;
}

int popt(stack*t)
{int ele;
ele=t->s[t->tos];
//t->s[t->tos] = 0;
t->tos--;
return ele;
}



//////////////////////////////////stacktop////////////////////////////////

int stacktop1(stack*t1)
{
return (t1->s[t1->tos]);
}

int stacktop2(stack*t2)
{
return (t2->s[t2->tos]);
}

int stacktop3(stack*t3)
{
return (t3->s[t3->tos]);
}

///////////////////////////////////transfer///////////////////////////////
//////////////////////////////////////////////////////////////////////////
void transfer(stack*t1,stack*t2,stack*t3,int c1,int c2)
{int ch1=c1;
int ch2=c2;
int ele;
////////////////////////////////////1->2///////////////////////////////////
if((ch1==1)&&(ch2==2))
{
if(isempty2(t2)) goto a;
if( (isempty1(t1)) || ( stacktop2(t2) < stacktop1(t1)) )
{
printf("INVALID MOVE\n");
c++;
}

else
{
a:
ele=pop1(t1);
push2(t2,ele);
n++;
}
}
//////////////////////////////////////1->3//////////////////////////////////
else if((ch1==1)&&(ch2==3))
{
if(isempty3(t3)) goto b;
if( (isempty1(t1)) || ( stacktop3(t3) < stacktop1(t1)) )
{
printf("INVALID MOVE\n");
c++;
}

else
{
b:
ele=pop1(t1);
push3(t3,ele);
n++;
}
}
//////////////////////////////////2->1////////////////////////////////
else if((ch1==2)&&(ch2==1))
{
if(isempty1(t1)) goto c;
if( (isempty2(t2)) || ( stacktop1(t1) < stacktop2(t2)) )
{
printf("INVALID MOVE\n");
c++;
}

else
{
c:
ele=pop2(t2);
push1(t1,ele);
n++;
}
}
/////////////////////////////////////2->3/////////////////////////////////
else if((ch1==2)&&(ch2==3))
{
if(isempty3(t3)) goto d;
if( (isempty2(t2)) || ( stacktop3(t3) < stacktop2(t2)) )
{
printf("INVALID MOVE\n");
c++;
}

else
{
d:
ele=pop2(t2);
push3(t3,ele);
n++;
}
}
/////////////////////////////////////3=>1//////////////////////////////////
else if((ch1==3)&&(ch2==1))
{
if(isempty1(t1)) goto e;
if( (isempty3(t3)) || ( stacktop1(t1) < stacktop3(t3)) )
{
printf("INVALID MOVE\n");
c++;
}

else
{
e:
ele=pop3(t3);
push1(t1,ele);
n++;
}
}
/////////////////////////////////////3->2///////////////////////////////////
else if((ch1==3)&&(ch2==2))
{
if(isempty2(t2)) goto f;
if( (isempty3(t3)) || ( stacktop2(t2) < stacktop3(t3)) )
{
printf("INVALID MOVE\n");
c++;
}

else
{
f:
ele=pop3(t3);
push2(t2,ele);
n++;
}
}
else
{
printf("INVALID MOVE\n");
c++;
}

}
////////////////////////////////////////////////////////////////////////////



//////////////////////////////////convert/////////////////////////////////


void convert(stack*t1,stack*t2,stack*t3,stack*t)
{
int i, temptos ,ele;
temptos=t1->tos; i=lim-1;
while(t1->tos!=-1)
{
ele=pop1(t1);
pusht(t,ele);
}
t1->tos=temptos;
while(t->tos!=-1)
{
tower[i][0]=popt(t); i--;
}

temptos=t2->tos; i=lim-1;
while(t2->tos!=-1)
{
ele=pop2(t2);
pusht(t,ele);
}
t2->tos=temptos;
while(t->tos!=-1)
{
tower[i][1]=popt(t); i--;
}

temptos=t3->tos; i=lim-1;
while(t3->tos!=-1)
{
ele=pop3(t3);
pusht(t,ele);
}
t3->tos=temptos;
while(t->tos!=-1)
{
tower[i][2]=popt(t); i--;
}



}


//////////////////////////////////initialize stack////////////////////////
void init_stack(stack*t1)
{
int i=0;
for(i=lim-1;i>=0;i--)
{
push1(t1,i+1);
}
//push2 (t2,0);
//push3 (t3,0);
}



///////////////////////////////initialize tower/////////////////////////////
void init_tower()
{
int i,j;
for(i=0;i<lim;i++)
{
for(j=0;j<3;j++)
{
tower[i][0]=i+1;
tower[i][1]=0;
tower[i][2]=0;
}
}

}

///////////////////////////////////display////////////////////////////////
void display()
{
int i,j;
for(i=0;i<lim;i++)
{
for(j=0;j<3;j++)
{
printf("   %d	",tower[i][j]);
}
printf("\n");
}
printf("\n");
//getch();
}


/////////////////////////////////zer0 tower///////////////////////////////
void zerotower()
{
int i,j;
for(i=0;i<lim;i++)
{
for(j=0;j<3;j++)
{
tower[i][j]=0;
}
}
}

/////////////////////////////////////info////////////////////////////////
void info()
{
printf("\t\t\t\t\t        Created by - YOUNUS JAMEEL\n");
printf("INFO\n");
printf(" 1.The level of tower must be less or equal to 20. \n");
printf(" 2.Choose diffrent coloumns \n");
printf(" 3.Type '1' ,'2' or '3' for first second or third coloumn respectively\n");
printf(" 4.Enter '0' to exit the game at any moment\n");
printf("RULES\n");
printf(" 1.ONLY ONE ELEMENT CAN BE MOVED AT A TIME\n");
printf(" 2.GREATER ELEMENT CANNOT BE PLACED OVER LESSER VALUE ELEMENT\n");
printf("\n\t\t\tGood luck  ,  play wisely\n\n\n");
}
////////////////////////////////////main()////////////////////////////////
void main()
{
int exit=0;int min=1; int gd=DETECT,gm;
int c1,c2,i,ele;// int cond=-1;
stack x;stack z;stack y;stack tmp;
FILE * p;
int tempscore,maxmoves;
int score1,score2,score3;
char name1[20],name2[20],name3[20];
char tempname[20];
x.tos=-1; z.tos=-1; y.tos=-1;tmp.tos=-1;
clrscr();
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(GREEN);
setcolor(RED);
settextstyle(4,0,4);
outtextxy(150,10,"TOWER OF HANOI");
line(0,50,900,50);
line(0,250,900,250);
printf("\n\n\n\n") ;
info();
printf("PRESS ANY KEY TO CONTINUE\n");
getch();
closegraph();
clrscr();
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(GREEN);
l:
printf("Enter Your Name\t");
scanf("%s",tempname);
printf("\n");
printf("Enter the number of Disc:  ");
scanf("%d",&lim);
printf("\n");
if(lim>10)
{
printf("MAXIMUM 10 DISC ALLOWED\n");
goto l;
}
if(lim==0)
{
goto o;
}
init_stack(&x);
init_tower();
display();
while(z.tos!=lim-1)
{
printf(">FROM:\t");
scanf("%d",&c1);
if(c1==0)
{
exit++;
break;
}
printf(">TO:\t");
scanf("%d",&c2);
if(c2==0)
{
exit++;
break;
}
printf("\n");
transfer(&x,&y,&z,c1,c2);
zerotower();
convert(&x,&y,&z,&tmp);
display();
}
if(exit==0)
{
for(i=0;i<lim;i++)
{
min=min*2;
}
setbkcolor(LIGHTGREEN);
if(n+c==min-1)
printf("\n\t\t\t\t    EXCELLENT!!!");
else if(n+c<min+6)
printf("\n\t\t\t\t      GREAT!");
else
printf("\n\t\t\t\t       GOOD");

printf("\n\t\t\t\tNUMBER OF MOVES= %d",n);
printf("\n\t\t\t\t MINIMUM MOVES= %d",min-1);
printf("\n\t\t\t\t  GAME SOLVED!!!");
getch();
printf("\n\n\n\n\n\n\n\n\n")    ;
closegraph();
clrscr();
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(GREEN);
if(lim<5)
maxmoves=(min-1)*3;
else maxmoves= (min-1)*5;
tempscore=maxmoves-n-c;

name1[0]='\0';
name2[0]='\0';
name3[0]='\0';
p= fopen("towerscore.txt","r+");
if(p==NULL)
{
printf("Unable to open file\n");
}
else
{
fscanf(p,"%s %d",name1,&score1);
fscanf(p,"%s %d",name2,&score2);
fscanf(p,"%s %d",name3,&score3);

if(tempscore>score1)
{
score3=score2;
strcpy(name3,name2);//name3=name2;
score2=score1;
strcpy(name2,name1);//name2=name1;
score1=tempscore;
strcpy(name1,tempname);//name1=tempname;
}
else if(tempscore>score2)
{
score3=score2;
strcpy(name3,name2);//name3=name2;
score2=tempscore;
strcpy(name2,tempname);//name2=tempname;
}
else if(tempscore>score3)
{
score3=tempscore;
strcpy(name3,tempname);//name3=tempname;
}
else printf("\n\t\t\t    BETTER LUCK NEXT TIME\n");
printf("\n\t\t\t       YOUR SCORE = %d\n",tempscore);
printf("\n\t\t\t\t HIGH SCORE\n");
printf("\t\t\t\t%s\t %d\n",name1,score1);
printf("\t\t\t\t%s\t %d\n",name2,score2);
printf("\t\t\t\t%s\t %d\n",name3,score3);

fclose(p);
p= fopen("towerscore.txt","a+");
rewind(p);
fprintf(p,"%s\t%d",name1,&score1);
fprintf(p,"%s\t%d",name2,&score2);
fprintf(p,"%s\t%d",name3,&score3);
fclose(p);
}


}
else
{
o:
setbkcolor(LIGHTBLUE);
printf("\n\t\t\tTHANK YOU FOR PLAYING\n\t\t\tDO COMPLETE THE GAME NEXT TIME\n");
}
getch();
}










