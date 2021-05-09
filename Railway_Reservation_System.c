// RAILWAY RESERVATION SYSTEM //
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<conio.h>


struct time
{
int iHrs,iMins;

};

struct Railway
{
int iRailwayNum;
int iRailwayCode;
char chSeat[8][4][20];
char chDrivers_Name[20];
struct time stDeparture_Time, stArrival_Time;
char chGoesTo[20];
char chGoesFrom[20];
float fFare;
int iTicketSold;
};


char chEmpty[]="Empty";

static int iNumber=1;
char i=':';
struct Railway stRailway[40];




void fnNew_Railway();
void fnMainMenu();
void fnShowRailway();
void fnEmpty();
void fnSeatReservation();
void fnShowStatus();
void fnPrintLine();
void fnDailyReport();


void main()
{
fnMainMenu();
}


void fnMainMenu()
{
int iChoice;
printf("\n\n\t\t\t______________________");
printf("\n\n\t\t\tRAILWAY RESERVATION SYSTEM");
printf("\n\n\t\t\t______________________\n");
fnPrintLine();

printf("\n\n\t\t1.Railway Installation");
printf("\n\t\t2.Alottment");
printf("\n\t\t3.Ticket details");
printf("\n\t\t4.Railway Status");
printf("\n\t\t5.Exit");
printf("\n\n\n\tEnter your choice as(1/2/3/4/5):-\t");
fflush(stdin);
scanf("%d",&iChoice);


switch(iChoice)
{
case 1 :fnNew_Railway();
break;
case 2: fnSeatReservation();
break;
case 3: fnShowRailways();
break;
case 4: fnShowStatus();
break;
case 5: exit(0);
default: printf("\t\t\tU have entered Wrong Choice!!!!");
getch();
fnMainMenu();
}
}


void fnNew_Railway()
{
char chChoice;
printf("\n\n\t\tEnter Information about Railway\n");
do{
fnPrintLine();
printf("\n\n\t\t Railway No:\t%d",iNumber);
RailwayC: printf("\n\n\tEnter Railway Code:\t");
fflush(stdin);

stRailway[iNumber].iRailwayNum=iNumber;
scanf("%d",&stRailway[iNumber].iRailwayCode);
if(stRailway[iNumber].iRailwayCode<1||stRailway[iNumber].iRailwayCode>9999)
{
printf("\n\t\tInvalid Railway Code!!!!");
goto RailwayC;
}
dname: printf("\n\n\tEnter driver's name:\t");
fflush(stdin);
gets(stRailway[iNumber].chDrivers_Name);

if(strlen(stRailway[iNumber].chDrivers_Name)>20)
{
printf("Maximum 20 characters are allowed");
goto dname;
}
artime: printf("\n\tEnter arrival time:\t");
fflush(stdin);
scanf("%d%c%d",&stRailway[iNumber].stArrival_Time.iHrs,&i,&stRailway[iNumber].stArrival_Time.iMins);
if(stRailway[iNumber].stArrival_Time.iHrs==0)
{
printf("\n\n\t\tInvalid tTme!!!!");
goto artime;
}
if((i!=':')||(stRailway[iNumber].stArrival_Time.iHrs>=24)||(stRailway[iNumber].stArrival_Time.iHrs<0)||(stRailway[iNumber].stArrival_Time.iMins>=60)||(stRailway[iNumber].stArrival_Time.iMins<0))
{
printf("\n\t\tInvalid Time!!!!\n");
printf("\t\tEnter only--hh:mm!!!!");
goto artime;
}
deptime: printf("\n\tEnter departure time:\t");
fflush(stdin);
scanf("%d%c%d",&stRailway[iNumber].stDeparture_Time.iHrs,&i,&stRailway[iNumber].stDeparture_Time.iMins);
if(stRailway[iNumber].stDeparture_Time.iHrs==0)
{
printf("\t\tinvalid Time!!!!");
goto deptime;
}
if((i!=':')||(stRailway[iNumber].stDeparture_Time.iHrs>=24)||(stRailway[iNumber].stDeparture_Time.iHrs<0)||(stRailway[iNumber].stDeparture_Time.iMins>=60)||(stRailway[iNumber].stDeparture_Time.iMins<0))
{
printf("\n\t\tInvalid Time!!!!");
printf("\n\t\tEnter only--hh:mm");
goto deptime;
}
from: printf("\n\tFrom:\t");
fflush(stdin);
gets(stRailway[iNumber].chGoesFrom);
if(strlen(stRailway[iNumber].chGoesFrom)>20)
{
printf("Maximum 20 characters are allowed");
goto from;
}

to: printf("\n\tTo:\t");
fflush(stdin);
gets(stRailway[iNumber].chGoesTo);
if(strlen(stRailway[iNumber].chGoesTo)>20)
{
printf("Maximum 20 characters are allowed");
goto to;
}
fnEmpty();
fnPrintLine();

printf("\n\n\n\tDo u want to continue to add information about new Railway(y/n)?? ");
fflush(stdin);
scanf("%c",&chChoice);

iNumber++;
}while(chChoice=='y'||chChoice=='Y');
fnMainMenu();
}



void fnShowRailways()
{
int i1;
printf("\n\n\t\t\t______________________");
printf("\n\n\t\t\t RAILWAY AVALAIBLE");
printf("\n\n\t\t\t______________________\n");

for(i1=1;i1<iNumber;i1++)
{
printf("\n");
fnPrintLine();
printf("\n\t\tRailway no-\t\t%d",stRailway[i1].iRailwayNum);
printf("\n\t\tRailway code-\t%d",stRailway[i1].iRailwayCode);
printf("\n\t\tDrivers Name-\t%s",stRailway[i1].chDrivers_Name);
printf("\n\t\tFrom-\t\t%s",stRailway[i1].chGoesFrom);
printf("\n\t\tTo-\t\t%s",stRailway[i1].chGoesTo);
printf("\n\t\tArrival time-\t%d%c%d",stRailway[i1].stArrival_Time.iHrs,i,stRailway[i1].stArrival_Time.iMins);
printf("\n\t\tDeparture time-\t%d%c%d",stRailway[i1].stDeparture_Time.iHrs,i,stRailway[i1].stDeparture_Time.iMins);
printf("\n");
fnPrintLine();
}
getch();
fnMainMenu();
}


void fnSeatReservation()
{
char chName[20];
int iRailwayN;
int iSeat;
char chChoice;
printf("\n\n\t\t\t______________________");
printf("\n\n\t\t\t ALLOTMENT");
printf("\n\n\t\t\t______________________\n");
fnPrintLine();
printf("\n\n\t\tEnter the Railway Number-\t");
fflush(stdin);
scanf("%d",&iRailwayN);
if(iRailwayN>=iNumber)
{
printf("\n\t\t\tSorry Railway Doesn,t Exist!!!!");
fnSeatReservation();
}

seat: printf("\n\t\tEnter the Seat number-\t");
fflush(stdin);
scanf("%d",&iSeat);
if(iSeat>32)
{
printf("\n\t\tSorry!! There r only 32 seats in the Railway!!!!") ;
goto seat;
}
else if(strcmp(stRailway[iRailwayN].chSeat[iSeat/4][(iSeat%4)-1],"Empty")==0)
{
printf("\n\t\tEnter the passenger's name-\t");
name: fflush(stdin);
gets(chName);
if(strlen(chName)>20)
{
printf("\n\t\tplz enter only 20 characters!!!!");
goto name;
}
else
{
strcpy(stRailway[iRailwayN].chSeat[iSeat/4][iSeat%4-1],chName);
printf("\n\t\tYour seat is reserved now!!");
stRailway[iRailwayN].iTicketSold++;
printf("\n\t do u want to continue with reservation(y/n)??");
fflush(stdin);
chChoice=getchar();
if(chChoice=='y'||chChoice=='Y')
fnSeatReservation();
else
fnMainMenu();
}
}else
{
printf("\n\tThis seat is already reserved!!!!");
printf("\n\t do u want to try again??");
fflush(stdin);
chChoice=getchar();
if(chChoice=='y'||chChoice=='Y')
fnSeatReservation();
else
fnMainMenu();
}
}


void fnEmpty()
{
for(int i=0;i<8;i++)
{
for(int j=0;j<4;j++)
{
strcpy(stRailway[iNumber].chSeat[i][j],chEmpty);
}
}
}



void fnShowStatus()
{
int iRailwayN,index=0,j,k;
char chChoice;
printf("\n\n\t\tEnter Railway no.-\t");
fflush(stdin);
scanf("%d",&iRailwayN);
if(iRailwayN>=iNumber)
{
printf("\n\t\tRailway doesn't Exist!!!!");
fnShowStatus();
}
else
{
fnPrintLine();
printf("\nBus code-\t%d\t\tDriver's Name-\t%s",stRailway[iRailwayN].iRailwayCode,stRailway[iRailwayN].chDrivers_Name);
printf("\nArrival Time-\t%d%c%d\t\tDeparture Time\t%d%c%d",stRailway[iRailwayN].stArrival_Time.iHrs,i,stRailway[iRailwayN].stArrival_Time.iMins,stRailway[iRailwayN].stDeparture_Time.iHrs,i,stRailway[iRailwayN].stDeparture_Time.iMins);
printf("\nFrom-\t\t%s\t\tTo-\t\t%s",stRailway[iRailwayN].chGoesFrom,stRailway[iRailwayN].chGoesTo);
printf("\n");
fnPrintLine();
for(j=0;j<8;j++)
{
printf("\n");
for(k=0;k<4;k++)
{ index++;
printf("%d .%s\t",index,stRailway[iRailwayN].chSeat[j][k]);
}
}
}
printf("\n\n\t\tDo u want to continue with another Railway(y/n)??");
fflush(stdin);
chChoice=getchar();
if(chChoice=='y'||chChoice=='Y')
fnShowStatus();
else
fnMainMenu();
}


void fnPrintLine()
{ int j;
for(j=0;j<60;j++)
printf("*");
}

