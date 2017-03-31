#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iomanip.h>
#include<dos.h>
#include<fstream.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void menu();
void welcome_screen();
void time_date();
void bye();
void border();
class directory
{
	public:
	char name[30];
	char pno[30];
	char emailid[30];
	void addition();
	void phone_menu();
	void view();
	void view1();
	int test();
	void search();
	void eddition();
	void deletion();
	void noofrecord();
	char check(char *s);
}d1;
void directory::addition()
{
	textbackground(7);
	clrscr();
	char ans;
	char ch;
	border();
	textcolor(BLINK+BLINK);
	gotoxy(35,1);
	cputs("[ADDITION]");
	textcolor(RED);
	gotoxy(16,10);
	cprintf("PRESS <B> TO EXIT OR ANY KEY TO CONTINUE....");
	ans=getch();
	if(ans=='b'||ans=='B')
	{
		phone_menu();
	}
	else
	{
	  clrscr();
	  gotoxy(30,1);
	  cprintf("[ADDITION]");
	  ifstream fin;
	  fin.open("FILE.txt",ios::in);
	  char pno1[30];
	  gotoxy(3,3);
	  cout<<"ENTER PHONE NUMBER:";
	  cin>>pno1;
	  int n,x,flag=0;
	  n=test();
	  for(int i=0;i<n;i++)
	  {
	     fin.read((char *)&d1,sizeof (d1));
	     x=strcmp(d1.pno,pno1);
	     if(x==0)
	     {
		flag=1;
		break;
	     }
	  }
	  fin.close();
	  if(flag==1)
	  {
	    gotoxy(12,10);
	    cout<<"THE NUMBER IS ALREADY EXIST.PLEASE TRY ANOTHER NUMBER.";
	    view1();
	    gotoxy(30,18);
	    cout<<"PRESS ANY KEY TO CONTINUE.";
	    getch();
	    phone_menu();
	  }
	  else if(flag==0)
	  {
	    strcpy(d1.pno,pno1);
	    gotoxy(3,4);
	    cout<<"ENTER NAME:" ;
	    gets(d1.name);
	    gotoxy(3,5);
	    cout<<"ENTER EMAIL ADDRESS:";
	    gets(d1.emailid);
	    ofstream out;
	    out.open("FILE.txt",ios::out|ios::app|ios::binary);
	    out.write((char *)&d1,sizeof(d1));
	    out.close();
	    gotoxy(20,10);
	    cout<<"Your Details Have Been Successfully Stored";
	    gotoxy(30,18);
	    cout<<"PRESS ANY KEY TO CONTINUE..";
	    getch();
	   }
	}
}
int directory::test()
{
	ifstream fin;
	fin.open("FILE.txt",ios::in);
	fin.seekg(0,ios::end);
	int n;
	n=fin.tellg()/sizeof(d1);
	fin.close();
	return n;
}
void directory::noofrecord()
{
	textbackground(1);
	clrscr();
	int n;
	border();
	n=test();
	gotoxy(20,10);
	cout<<"NUMBER OF RECORDS IN THE DATABASE:"<<n;
	gotoxy(30,18);
	cout<<"PRESS ANY KEY TO CONTINUE";
	getch();
}
void directory::view()
{
	textbackground(1);
	textcolor(WHITE);
	ifstream fin;
	int n,j;
	border();
	fin.open("FILE.txt");
	if(fin.fail()||fin.bad())
	{
	  clrscr();
	  border();
	  gotoxy(30,10);
	  cout<<"FILE IS NOT FOUND!" ;
	  getch();
	  return ;
	}
	clrscr();
	int i=0;
	border();
	n=test();
	if(n==0)
	{
	  gotoxy(30,20);
	  cout<<"THERE IS NO RECORD IN THE DATABASE";
	  gotoxy(30,18);
	  cout<<"PRESS ANY KEY TO CONTINUE.";
	  getch();
	}
	else
	{
	   gotoxy(3,3);
	   cout<<" ALL THE RECORDS OF NUBBER ARE";
	   gotoxy(3,4);
	   cout<<".............................. ";
	   int k=4;
	  for(j=0;j<n;j++)
	  {
	    fin.read((char *)&d1,sizeof(d1));
	    gotoxy(3,k);
	    cout<<"RECORD["<<i+1<<"]->\n";
	    gotoxy(3,k++);
	    cout<<"PHONE NUMBER: "<<d1.pno;
	    gotoxy(3,k++);
	    cout<<"NAME: "<<d1.name;
	    gotoxy(3,k++);
	    cout<<"EMAIL ADDRESS: "<<d1.emailid<<endl;
	    i=i+1;
	    k++;
	    }
	    fin.close();
	    gotoxy(30,18);
	    cout<<"PRESS ANY KEY TO CONTINUE.";
	    getch();
	  }
}
void directory::view1()
{
	textcolor(RED);
	gotoxy(26,6);
	cprintf("THE DETAILS OF THE RECORD");
	gotoxy(26,7);
	cprintf("......................... \n");
	gotoxy(26,8);
	cout<<"PHONE NUMBER: "<<d1.pno;
	gotoxy(26,9);
	cout<<"NAME: "<<d1.name;
	gotoxy(26,10);
	cout<<"EMAIL ID: "<<d1.emailid<<endl;
}
void directory::search()
{
	textbackground(6);
	clrscr();
	border();
	ifstream fin;
	fin.open("FILE.txt");
	if(fin.fail())
	{
	  gotoxy(30,10);
	  cout<<"FILE IS NOT FOUND\n";
	  getch();
	  return;
	}
	clrscr();
	border();
	textcolor(BLINK+BLINK);
	gotoxy(35,1);
	cprintf("[SEARCHING]");
	gotoxy(26,4);
	cout<<"ENTER THE NUMBER TO SEARCH:" ;
	char pn[30];
	cin>>pn;
	int n,x;
	n=test();
	for(int i=0;i<n;i++)
	{
	  fin.read((char *)&d1,sizeof(d1));
	  x=strcmp(d1.pno,pn);
	  if(x==0)
	  {
	    view1();
	    gotoxy(30,18);
	   cout<<"PRESS ANY KEY TO CONTINUE.";
	   getch();
	   break;
	  }
	}
	if(x!=0)
	{
	 textbackground(2);
	 gotoxy(30,8);
	 textcolor(YELLOW);
	 textattr(20);
	 cprintf("RECORD DOES NOT MATCH.");
	 gotoxy(30,13);
	 cout<<"PRESS ANY KEY TO BACK MENU.";
	 getch();
	}
}
char directory::check(char *s)
{
	cout<<"DO YOU WANT TO MODIFY "<<s<<" Y/N:\n";
	char ch;
	ch=getch();
	if((ch=='Y')||(ch=='y'))
	  return 'y';
	else
	  return 'n';
}
void directory::eddition()
{
	char z;
	int flag=0;
	textbackground(7);
	clrscr();
	border();
	textcolor(BLINK+BLINK);
	gotoxy(30,1);
	cprintf("[MODIFICATION]");
	gotoxy(25,5);
	cout<<"DO YOU WANT TO EDIT Y/N";
	z=getch();
	if((z=='y')||(z=='Y'))
	{
	  textcolor(RED);
	  char pn[30];
	  int i,n;
	  ifstream fin;
	  ofstream out;
	  fin.open("FILE.txt");
	  if(fin.fail())
	  {
	   gotoxy(30,10);
	   cout<<"FILE NOT FOUND !";
	   getch();
	  }
	  out.open("NEWFILE.txt");
	  n=test();
	  if(n==0)
	  {
	    gotoxy(30,12);
	    cout<<"FILE IS EMPTY !";
	    getch();
	    return ;
	  }
	  while(fin.good())
	  {
	    fin.read((char *)&d1,sizeof(d1));
	    out.write((char*)&d1,sizeof(d1));
	  }
	  fin.close();
	  out.close();
	  out.open("FILE.txt",ios::trunc);
	  fin.open("NEWFILE.txt");
	  if(fin.fail())
	  {
	    gotoxy(30,10);
	    cout<<"FILE NOT FOUND !";
	    exit(-1);
	  }
	  char ch;
	  int x;
	  clrscr();
	  border();
	  textcolor(BLINK+BLINK);
	  gotoxy(35,1);
	  cprintf("[MODIFICATION]");
	  gotoxy(3,4);
	  cout<<"ENTER THE PHONE NUMBER DO YOU WANT TO MODIFY: ";
	  cin>>pn;
	  cin.get(ch);
	  for(i=0;i<n;i++)
	  {
	    fin.read((char *)&d1,sizeof(d1));
	    x=strcmp(d1.pno,pn);
	    char d;
	    if(x==0)
	    {
	      flag=1;
	      view1();
	      gotoxy(26,11);
	      cout<<"EDITING THE DETAILS OF NUMBER "<<pn;
	      gotoxy(3,12);
	      d=check("PHONE NUMBER");
	      if((d=='y')||(d=='Y'))
	      {
	       gotoxy(3,12);
		cout<<"ENTER NEW PHONE NUMBER: ";
		gets(d1.pno);
	      }
	      gotoxy(3,14);
	      d=check("NAME");
	      if((d=='y')||(d=='Y'))
	      {
		gotoxy(3,15);
		cout<<"ENTER NEW NAME: ";
		gets(d1.name);
	      }
	      gotoxy(3,16);
	      d=check("EMAIL ADDRESS");

	       if((d=='y')||(d=='Y'))
	       {
		gotoxy(3,17);
		cout<<"ENTER NEW EMAIL ADDRESS:";
		gets(d1.emailid);
	       }
	       gotoxy(10,19);
	    cout<<"THE INFORMATION HAS BEEN SUCCESSFULLY EDITED.";
	    gotoxy(30,21);
	    cout<<"PRESS ANY KEY TO CONTINUE.";
	    getch();
	   }
	    out.write((char *)&d1,sizeof(d1));
	   }
	   out.close();
	   fin.close();
	   remove("NEWFILE.txt");
	  }
	  else

	  {
	    clrscr();
	    flag=-1;
	    phone_menu();
	  }
	  if(flag==0&&flag!=-1)
	  {
	    gotoxy(30,10);
	    cputs("THE RECORD DOES NOT EXIST.");
	    gotoxy(30,14);
	    textcolor(3);
	    textattr(22);
	    cprintf("PRESS ANY KEY TO CONTINUE.");
	    getch();
	  }
}
void directory::deletion()
{
	textbackground(BLINK+BLINK);
	clrscr();
	border();
	textcolor(YELLOW);
	gotoxy(35,1);
	printf("[DELETION]");
	ifstream f1;
	f1.open("FILE.txt");
	ofstream f2;
	f2.open("TEMPFILE.txt");
	char pno[30];
	int x;
	gotoxy(3,5);
	cprintf("ENTER THE PNONE NUMBER YOU WANT TO DELETE:");
	cin>>pno;
	int flag=0;
	int n=test();
	for(int i=0;i<n;i++)
	{
	   f1.read((char *)&d1,sizeof(d1));
	   x=strcmp(d1.pno,pno);
	   if(x==0)
	   {
	     view1();
	     cout<<"\n\t\tCONFIRM DELETE?Y/N";
	     char ans;
	     ans=getch();
	     if((ans=='y')||(ans=='Y'))
	     {
	       flag=1;
	     }
	     else
	     {
	       flag=2;
	       f2.write((char *)&d1,sizeof(d1));
	     }
	   }
	   else
	   {
	     f2.write((char *)&d1,sizeof(d1));
	   }
	}//loop close
	f1.close();
	f2.close();
	remove("FILE.txt");
	rename("TEMPFILE.txt","FILE.txt");
	if(flag==1)
	{
	textcolor(MAGENTA);
	cout<<"\n\n\t\t";
	cprintf("THE RECORD HAS BEEN SUCCESSFULLY DELETED.");
	cout<<"\n\t\t";
	cprintf("PRESS ANY KEY TO CONTINUE.");
	getch();
	}
	if(flag!=1 && flag!=2)
	{
	 textcolor(RED);
	 gotoxy(30,10);
	 cprintf("RECORD DOES NOT EXIST.");
	 textcolor(GREEN);
	 gotoxy(30,14);
	 cprintf("PRESS ANY KEY TO CONTINUE.");
	 getch();
	}
}

void directory::phone_menu()
{
	textbackground(2);
	char c;
	clrscr();
	textcolor(WHITE);
	//time_date();
	cout<<endl;
	border();
	for(int i=1;i<=79;i++)
	{
		gotoxy(i,3);
		printf("%c",219);
	}
	for(i=3;i<=23;i++)
	{
		gotoxy(43,i);
		printf("%c%c",219,219);
	}
	for(i=45;i<=78;i++)
	{       textcolor(7);
		gotoxy(i,7);
		cprintf("%c",219);
		gotoxy(i,9);
		cprintf("%c",219);
		gotoxy(i,11);
		cprintf("%c",219);
		gotoxy(i,13);
		cprintf("%c",219);
		gotoxy(i,15);
		cprintf("%c",219);
		gotoxy(i,17);
		cprintf("%c",219);
		gotoxy(i,19);
		cprintf("%c",219);
		gotoxy(i,21);
		cprintf("%c",219);

	}
	gotoxy(35,2);
	textcolor(1);
	textattr(2);
	cputs("[PHONEBOOK]");
	gotoxy(12,13);
	textcolor(6);
	cprintf("ENTER YOUR CHOICE:");
	//textattr(CYAN);
	gotoxy(60,5);
	cprintf("OPTIONS");
	textattr(CYAN);
	gotoxy(45,8);
	cprintf("[a]FOR ADD NUMBER.");
	gotoxy(45,10);
	cprintf("[v]FOR VIEW ALL RECORDS.");
	gotoxy(45,12);
	cprintf("[s]FOR SEARCHING NUMBER.");
	gotoxy(45,14);
	cprintf("[e]FOR EDIT INFORMATION.");
	gotoxy(45,16);
	cprintf("[d]FOR DELETE NUMBER.");
	gotoxy(45,18);
	cprintf("[n]FOR VIEW THE NUMBER OF RECORDS.");
	gotoxy(45,20);
	cprintf("[m]FOR MENU");
	gotoxy(45,22);
	cprintf("[x]FOR EXIT.");
	c=getch();
	switch(c)
	{
	  case'a': addition();
	  break;
	  case'v': view();
	  break;
	  case's':search();
	  break;
	  case'e':eddition();
	  break;
	  case'd':deletion();
	  break;
	  case'n':noofrecord();
	  break;
	  case'm':menu();
	  break;
	  case'x':bye();
	  exit(0);
	}
}

class message
{
	char text[512];
	char pno[30];
	int t1,t2,t3;
	int x,y,z;
	public:
	void write();
	void inbox();
	void outbox();
	void draft();
	void send();
	void message_menu();
	int test1();
	int test2();
	void end();
}m;
void message::write()
{
	textbackground(27);
	char ch;
	int i=0;
	clrscr();
	for(int j=1;j<=79;j++)
	{
		gotoxy(j,1);
		printf("%c",219);
	}
	gotoxy(15,1);
	textattr(7);
	cprintf("Writing Message Until Press (Ctrl+q Then Enter)");
	cout<<endl;
	while(!cin.eof())
	{
	   cin.peek();
	   while(((ch=cin.get())!='\n')&&(ch!=17))
	   {
	     m.text[i++]=ch;
	   }
	   if(ch==17)
	   break;
	   m.text[i++]='\n';
	}
	m.text[i]=NULL;
	//cout<<"\n\nOUTBOX: "<<m.text<<endl;
	cout<<"\n\n\n\n\t\t\t\tOPTION:>\n\t\t\t1 for Save Message.\n\t\t\t2 for Send Message.\n\t\t\t3 for Back From Write Message\n";
	char ans;
	ans=getch();
	     if(ans=='1')
	     {
	     textbackground(9);
	     ofstream out;
	     clrscr();
	     struct time t;
	     gettime(&t);
	     m.t1=t.ti_hour;
	     m.t2=t.ti_min;
	     m.t3=t.ti_sec;
	     struct date d;
	     getdate(&d);
	     m.x=d.da_year;
	     m.y=d.da_mon;
	     m.z=d.da_day;
	     out.open("ms1.txt",ios::out|ios::binary|ios::app);
	     out.write((char *)&m,sizeof(m));
	     gotoxy(20,10);
	     cout<<"The Message Has Been Successfully Saved.\n";
	     gotoxy(30,14);
	     cout<<"Press Any key To Continue.\n";
	     out.close();
	     getch();
	    }
	    else if(ans=='2')
	    {
	    textbackground(1);
	    ofstream out;
	    clrscr();
	    gotoxy(30,10);
	    cout<<"Enter Number: ";
	    cin>>m.pno;
	    struct time t;
	    gettime(&t);
	    m.t1=t.ti_hour;
	    m.t2=t.ti_min;
	    m.t3=t.ti_sec;
	    struct date d;
	    getdate(&d);
	    m.x=d.da_year;
	    m.y=d.da_mon;
	    m.z=d.da_day;

	    out.open("ms2.txt",ios::out|ios::binary|ios::app);
	    out.write((char *)&m,sizeof(m));
	    out.close();
	    cout<<"\n";
	    for(int i=0;i<80;i++)
	    {
		  char s;
		  cprintf("%c",177);
		  delay(100);
	    }
	     textbackground(3);
	     clrscr();
	     gotoxy(20,8);
	     cout<<"The Message Has Been Successfully Send.\n";
	     gotoxy(30,22);
	     cout<<"Press any Key to continue\n";
	     getch();
	    }
	    else
	    {
	    clrscr();
	    message_menu();
	    getch();
	    }
}
void message::draft()
{
	textbackground(1);
	ifstream fin;
	clrscr();
	for(int i=1;i<=80;i++)
	{
		gotoxy(i,1);
		printf("%c",219);
	}
	textcolor(WHITE);
	textattr(7);
	gotoxy(35,1);
	cputs("[DRAFTS]");
	cout<<endl;
	int n=test1();
	if(n==0)
	{
	  gotoxy(30,5);
	  cout<<"SMS is Empty";
	  gotoxy(25,14);
	  cout<<"Press Any Key to Continue.";
	}
	else
	{
	  fin.open("ms1.txt",ios::in);
	  gotoxy(1,3);
	  for(int i=0;i<n;i++)
	  {
	   cout<<"SMS["<<i+1<<"/"<<n<<"]\n";
	   fin.read((char *)&m,sizeof(m));
	   cout<<"Time:"<<m.t1<<":"<<m.t2<<":"<<m.t3<<"\n";
	   cout<<"Date:"<<m.z<<":"<<m.y<<":"<<m.x<<"\n";
	   cout<<m.text<<"\n________________________________________________________________________________\n";
	  }
	 fin.close();
	}
	getch();
}
int message::test1()
{
	ifstream fin;
	fin.open("ms1.txt");
	fin.seekg(0,ios::end);
	int n=fin.tellg()/sizeof(m);
	fin.close();
	return n;
}
int message::test2()
{
	ifstream fin;
	fin.open("ms2.txt");
	fin.seekg(0,ios::end);
	int n=fin.tellg()/sizeof(m);
	fin.close();
	return n;
}
void message::message_menu()
{
       textbackground(2);
       clrscr();
       directory d;
       time_date();
       gotoxy(35,4);
       printf("MESSAGE");
       for(int i=1;i<=78;i++)
       {
		gotoxy(i,1);
		cprintf("%c",219);
		gotoxy(i,23);
		cprintf("%c",219);
       }
       for(i=1;i<=23;i++)
       {
		gotoxy(1,i);
		cprintf("%c%c",219,219);
		gotoxy(78,i);
		cprintf("%c%c",219,219);
       }
       textcolor(MAGENTA);
       gotoxy(30,10);
       cprintf("Enter your choice:");
       gotoxy(30,12);
       cprintf("w for write SMS.");
       gotoxy(30,13);
       cprintf("d for draft.");
       gotoxy(30,14);
       cprintf("i for Inbox.");
       gotoxy(30,15);
       cprintf("s for Send Item");
       gotoxy(30,16);
       cprintf("m for Manu");
       gotoxy(30,17);
       cprintf("x for exit");
       char c;
       c=getch();
       textcolor(WHITE);
       switch(c)
       {
	    case'w':write();break;
	    case'd':draft();break;
	    case'i':inbox();break;
	    case's':send();break;
	    case'm':menu();break;
	    case'x':
		     bye();
		     exit(0);

       }
}
void message::send()
{
	textbackground(1);
	clrscr();
	textcolor(WHITE);
	ifstream fin;
	for(int i=1;i<=79;i++)
	{
		gotoxy(i,1);
		printf("%c",219);
	}
	gotoxy(35,1);
	textattr(7);
	cprintf("[SEND BOX]");
	cout<<endl;
	int n=test2();
	if(n==0)
	{
	 gotoxy(35,7);
	 cprintf("EMPTY");
	 gotoxy(25,14);
	 cprintf("Press Any Key to Continue.");
	}
	else
	{
	  fin.open("ms2.txt",ios::in);
	  gotoxy(1,3);
	  for(int i=0;i<n;i++)
	  {
	   cout<<"SMS["<<i+1<<"/"<<n<<"]\n";
	   fin.read((char *)&m,sizeof(m));
	   cout<<"Time:"<<m.t1<<":"<<m.t2<<":"<<m.t3<<"\n";
	   cout<<"Date:"<<m.z<<":"<<m.y<<":"<<m.x<<"\n";
	   cout<<"Sending Number:"<<m.pno;
	   cout<<"\n\n"<<m.text<<"\n_______________________________________________________________________________\n";
	  }
	 fin.close();
	}
	getch();
}

void message::inbox()
{
   textbackground(1);
   clrscr();
   for(int i=1;i<80;i++)
   {
	gotoxy(i,1);
	printf("%c",219);
   }
   textattr(7);
   gotoxy(35,1);
   cprintf("[INBOX]");
   gotoxy(35,10);
   cout<<"Empty";
   getch();
}
class calculator
{
	public:
	float add(float a,float b);
	float sub(float a,float b);
	float mul(float a,float b);
	float div(float a,float b);
	float power(float a,float b);
	float root(float a);
	//double sub(double a,double b);
	void calculation();
	void cal_index();
};
float calculator::add(float a,float b)
{
	float c=a+b;
	gotoxy(6,8);
	cout<<a<<"+"<<b<<"=";
	return c;
}
float calculator::sub(float a,float b)
{

	float c=a-b;
	gotoxy(6,8);
	cout<<a<<"-"<<b<<"=";
	return c;
}
float calculator::mul(float a,float b)
{
	float c=a*b;
	gotoxy(6,8);
	cout<<a<<"*"<<b<<"=";
	return c;
}
float calculator::div(float a,float b)
{
	float c=a/b;
	gotoxy(6,8);
	cout<<a<<"/"<<b<<"=";
	return c;
}
float calculator::power(float a,float b)
{
	float c;
	c=pow(a,b);
	gotoxy(6,8);
	cout<<a<<" to the power "<<b<<" = ";
	return c;
}
float calculator::root(float a)
{
	float c;
	c=sqrt(a);
	gotoxy(6,8);
	cout<<"Root of "<<a<<" = ";
	return c;
}
void calculator::calculation()
{
	char c,ch;
	float m,n,r,d;
	clrscr();
	cal_index();
	gotoxy(6,5);
	cout<<"Enter a Number:";
	cin>>m;
	alam:
	gotoxy(6,6);
	cout<<"Enter an Operator:";
	c=getch();
	cout<<c;
	gotoxy(6,7);
	switch(c)
	{
		case'+':cout<<"Enter an Other Number:";
			cin>>n;
		       d=add(m,n);
			break;
		case'-':cout<<"Enter an other Number:";
			cin>>n;
			 d=sub(m,n);
			break;
	       case'*':cout<<"Enter an other Number:";
		       cin>>n;
			d=mul(m,n);
		       break;
	       case'/':cout<<"Enter an other Number:";
		       cin>>n;
		       d=div(m,n);
		       break;
	       case'p':cout<<"Enter Power:";
		       cin>>n;
		       d=power(m,n);
		       break;
	       case'r':d=root(m);
			break;
		default:clrscr();
			calculation();
	}
	cout<<d<<endl;
	gotoxy(16,15);
	cout<<"Use The Result?(y/any key/x/m)";
	ch=getch();
	if(ch=='y')
	{
		m=d;
		clrscr();
		cal_index();
		goto alam;
	}
	else if(ch=='x')
	{
		directory d;
		bye();
		exit(0);
	}
	else if(ch=='m')
	{
		clrscr();
		message m;
		menu();
		getch();
	}
	else
	{
		calculation();
	}
}
void calculator::cal_index()
{
	textcolor(RED);
	gotoxy(19,2);
	cprintf("SIMPLE CALCULATOR");
	textcolor(WHITE);
	for(int i=1;i<=79;i++)
	{
		gotoxy(i,1);
		cprintf("%c",219);
		gotoxy(i,3);
		cprintf("%c",219);
		gotoxy(i,23);
		cprintf("%c",219);
	}
	for(int j=1;j<=23;j++)
	{
		gotoxy(1,j);
		cprintf("%c%c",219,219);
		gotoxy(50,j);
		cprintf("%c%c",219,219);
		gotoxy(79,j);
		cprintf("%c%c",219,219);
	}
	textcolor(RED);
	gotoxy(60,2);
	cprintf("OPERATORS");
	textcolor(1);
	gotoxy(55,5);
	cprintf("[+]FOR Addition");
	gotoxy(55,6);
	cprintf("[-]For Subtruction");
	gotoxy(55,7);
	cprintf("[*]For Multipication");
	gotoxy(55,8);
	cprintf("[/]For Divission");
	gotoxy(55,9);
	cprintf("[p]For Power");
	gotoxy(55,10);
	cprintf("[r]For Root");
	gotoxy(55,11);
	cprintf("[x]For Exit");
}
class BMI
{
	public:
	void bmi_index();
	float body();
	void condition();
	void status();
};
void BMI::bmi_index()
{       textbackground(9);
	int i,j;
	clrscr();
	gotoxy(20,3);
	textcolor(RED);
	textattr(3);
	cprintf("BODY MASS INDEX[BMI]");
	gotoxy(68,3);
	cprintf("OPTION");
	textcolor(3);
	//textattr(7);
	for(i=1;i<=79;i++)
	{
		gotoxy(i,1);
		cprintf("%c",219);
		gotoxy(i,5);
		cprintf("%c",219);
		gotoxy(i,23);
		cprintf("%c",219);
	}
	for(j=1;j<=23;j++)
	{
		gotoxy(1,j);
		cprintf("%c%c",219,219);
		gotoxy(79,j);
		cprintf("%c%c",219,219);
		gotoxy(60,j);
		cprintf("%c%c",219,219);
	}
}
float BMI::body()
{
	float m,mass,bmi,hight;
	gotoxy(5,7);
	cout<<"Enter Your Wight[kg]:";
	cin>>m;
	gotoxy(5,8);
	cout<<"Enter Your Hight[Inch]:";
	cin>>hight;
	mass=m*2.205;//convert in lb
	bmi=(mass*703)/(hight*hight);
	return bmi;
}
void BMI::condition()
{
	float bmi;
	clrscr();
	bmi_index();
	bmi=body();
	gotoxy(5,9);
	printf("Your BMI is %f",bmi);
	status();
	gotoxy(30,12);
	textcolor(2);
	if(bmi<=12)
	{
		cprintf("YOU ARE TOO THIK");
	}
	else if((bmi>=13)&&(bmi<18.5))
	{
		cprintf("YOU ARE THIK");
	}
	else if((bmi>=18.5)&&(bmi<=24.9))
	{
		cprintf("YOU ARE NORMAL");
	}
	else if((bmi>=25)&&(bmi<=29.9))
	{
		cprintf("YOU ARE FAT");
	}
	else if(bmi>=30)
	{
		cprintf("YOU ARE TOO FAT");
	}
	else
	{
		cprintf("INVALID");
	}
	char ch;
	ch=getch();
	if(ch=='b')
	{       textbackground(9);
		clrscr();
		condition();
	}
	else if(ch=='m')
	{
		menu();
	}
	else if(ch=='x')
	{
		 directory d;
		 bye();
		 exit(0);
	}
}
void BMI::status()
{

	int i;
	gotoxy(5,16);
	textcolor(YELLOW);
	cprintf("BMI Status:");
	for(i=18;i<=58;i++)
	{
			gotoxy(i,16);
			textcolor(5);
			cprintf("%c",223);
	}
	gotoxy(18,17);
	printf("Too Thik");
	gotoxy(25,17);
	printf("|  Thik");
	gotoxy(33,17);
	printf("|  Normal");
	gotoxy(42,17);
	printf("|  Fat");
	gotoxy(50,17);
	printf("|Too Fat");
	gotoxy(25,18);
	printf("13");
	gotoxy(30,18);
	printf("18.5");
	gotoxy(40,18);
	printf("24.9");
	gotoxy(48,18);
	printf("29.9");
	gotoxy(66,8);
	printf("[b]For BMI");
	gotoxy(66,9);
	printf("[m]FOR MENU");
	gotoxy(66,10);

	printf("[x]FOR EXIT");


}

class security
{
	public:
	char password[100];
	void set_password();
	void edit_password();
	void remove_password();
	int test_password();
	void password_option();
}s;
void security::set_password()
{

	char pass[100];
	int setp=test_password();
	clrscr();
	border();
	for(int i=1;i<=78;i++)
	{
		gotoxy(i,3);
		printf("%c",219);
	}
	gotoxy(30,2);
	cout<<"[SET PASSWORD]";
	if(setp==0)
	{
		gotoxy(30,8);
		cout<<"Enter password:";
		gets(pass);
		gotoxy(30,9);
		cout<<"Enter confrim password:";
		gets(s.password);
		int d=strcmp(s.password,pass);
		if(d==0)
		{
			ofstream out;
			out.open("password.dat",ios::out|ios::app|ios::binary);
			out.write((char *)&s,sizeof(s));
			out.close();
			gotoxy(30,18);
			cout<<"The password has been successfully set." ;
		}
		else
		{
			gotoxy(30,18);
			cout<<"password has not been match.";
		}
	}
	else
	{
		gotoxy(30,10);
		cout<<"Password has been set.";
	}
	getch();
}
int security::test_password()
{
	ifstream fin;
	fin.open("password.dat",ios::in);
	fin.seekg(0,ios::end);
	int test;
	test=fin.tellg()/sizeof(s);
	fin.close();
	return test;
}
void security::edit_password()
{
	char currentp[100],confrimp[100];
	int d;
	clrscr();
	int n=test_password();
	border();
	for(int i=1;i<=78;i++)
	{
		gotoxy(i,3);
		printf("%c",219);
	}
	gotoxy(30,2);
	cout<<"[EDIT PASSWORD]";
	if(n==0)
	{
		gotoxy(30,13);
		cout<<"Password has not been set.";
		gotoxy(30,14);
		cout<<"Plz first set the password.";
	}
	else
	{
		gotoxy(30,10);
		cout<<"Enter Current Password.";
		gets(currentp);
		ifstream fin;
		fin.open("password.dat");
		fin.read((char*)&s,sizeof(s));
		d=strcmp(s.password,currentp);
		fin.close();
		if(d==0)
		{
			gotoxy(30,12);
			cout<<"Enter New Password:";
			gets(s.password);
			gotoxy(30,13);
			cout<<"Enter Confrim Password:";
			gets(confrimp);
			int c=strcmp(s.password,confrimp);
			if(c==0)
			{
				ofstream fout;
				fout.open("newpassword.dat",ios::out);
				fout.write((char*)&s,sizeof(s));
				fout.close();
				fout.open("password.dat",ios::trunc);
				fin.open("newpassword.dat");
				fout.write((char*)&s,sizeof(s));
				fout.close();
				fin.close();
				remove("newpassword.dat");
				gotoxy(25,18);
				cout<<"Password has been successfully edit";
			}
			else
			{
				gotoxy(30,16);
				cout<<"Password has not been match";
			}
		}
		else
		{       gotoxy(30,16);
			cout<<"Password has not match";
		}
	}
	getch();

}
void security::remove_password()
{
	char currentp[100];
	int n,d;
	clrscr();
	border();
	for(int i=1;i<=78;i++)
	{
		gotoxy(i,3);
		printf("%c",219);
	}
	gotoxy(30,2);
	cout<<"[REMOVE PASSWORD]";
	n=test_password();
	if(n==0)
	{
		gotoxy(30,13);
		cout<<"Password has not been set." ;
		gotoxy(30,14);
		cout<<"Plz first set the password.";
	}
	else
	{
		gotoxy(30,10);
		cout<<"Enter Current Password:";
		gets(currentp);
		ifstream fin;
		fin.open("password.dat",ios::in);
		fin.read((char*)&s,sizeof(s));
		d=strcmp(s.password,currentp);
		fin.close();
		if(d==0)
		{
			remove("password.dat");
			gotoxy(25,16);
			cout<<"Password has been successfully removed";
		}
		else
		{
			gotoxy(30,14);
			cout<<"Password has not match";
		}
	}
	getch();
}

void security::password_option()
{
	char c;
	clrscr();
	border();
	for(int i=1;i<=78;i++)
	{
		gotoxy(i,3);
		printf("%c",219);
	}
	for(i=3;i<=22;i++)
	{
		gotoxy(53,i);
		printf("%c%c",219,219);
	}
	gotoxy(30,2);
	cout<<"[SECURITY SYSTEM]";
	gotoxy(60,5);
	cout<<"[OPTION]";
	gotoxy(56,8);
	cout<<"[s]for set password";
	gotoxy(56,9);
	cout<<"[e]for edit password";
	gotoxy(56,10);
	cout<<"[r]for remove password";
	gotoxy(56,11);
	cout<<"[m]for menu";
	gotoxy(56,12);
	cout<<"[x]for exit";
	gotoxy(56,13);
	gotoxy(20,10);
	cout<<"Enter Your Option:";
	c=getch();
	switch(c)
	{
		case's':set_password();
		break;
		case'e':edit_password();
		break;
		case'r':remove_password();
		break;
		case'm':menu();
		break;
		case'x':
			bye();
			exit(0);
			break;
		default:password_option();
	}
}
class world
{
	public:
		void time_calculation(int i,int j,int k);
		void timezone_index();
};
void world::time_calculation(int hour,int min,int sec)
{
	struct time t;
	gettime(&t);
	int i=t.ti_sec;
	int j=t.ti_min;
	int k=t.ti_hour;
	sec=sec+i;
	min=min+j;
	hour=hour+k;
	if(sec>=60)
	{
	int m=sec/60;
	int sec=sec%60;
	min=min+m;
	}
	if(min>=60)
	{
		int h=min/60;
		int min=min%60;
		hour=hour+h;
	}
	if(hour>=24)
	{
		hour=hour-24;
		if(hour>=12)
		{
			hour=hour-12;
			cout<<hour<<":"<<min<<":"<<sec;
			cout<<" PM";
		}
		else
		{
		cout<<hour<<":"<<min<<":"<<sec;
		cout<<" AM";
		}
	}
	else
	{
		if(hour>=12)
		{
			hour=hour-12;
			cout<<hour<<":"<<min<<":"<<sec;
			cout<<" PM";
		}
		else
		{
		cout<<hour<<":"<<min<<":"<<sec;
		cout<<" AM";
		}

	}
	getch();


}
void world::timezone_index()
{
	int j;
	char c;
	clrscr();
	border();
	gotoxy(35,2);
	cout<<"[TIME ZONE]";
	for(int a=1;a<=78;a++)
	{
		gotoxy(a,3);
		printf("%c",219);
	}
	gotoxy(20,12);
	cout<<"Press [c]For Continue and [m]For Menu[x]For Exit.";
	c=getch();
	if(c=='x')
	{
	       bye();
	       exit(0);
	}
	else if(c=='m')
	{
		menu();
	}
	else if(c=='c')
	{
		gotoxy(25,10);
		for(int i=1;i<=10;i++)
		{
			int code=0;
			if(kbhit())
			{
				code=getch();
			}

	     //	arrow=getch();
		clrscr();
		border();
		gotoxy(35,2);
		cout<<"[TIME ZONE]";
		for(a=1;a<=78;a++)
		{
			gotoxy(a,3);
			printf("%c",219);
		}
		gotoxy(25,10);
		if(code==75||code==80)
		{
			j++;
		}
		else if(code==77||code==72)
		{
			j--;
		}
		else
		{
			j=5;
		}
		switch(j)
		{
			case 1: cout<<"Now The Indian Time is:";
				time_calculation(5,30,0);
				break;
			case 2: cout<<"Now The Pakisthan Time is:";
				time_calculation(6,0,0);
				break;
			case 3: cout<<"Now The USA time is:";
				time_calculation(12,0,0);
				break;
			case 4: cout<<"Now The UK time is:";
				time_calculation(12,0,0);
				break;
			case 5: cout<<"Now The BANGLADESH time is:";
				time_calculation(0,0,0);

				break;
			case 6: cout<<"Now The SINGAOURE time is:";
				time_calculation(9,30,0);
				break;
			case 7: cout<<"Now The MALAYSHYA time is:";
				time_calculation(5,30,0);
		}
		if(j==7||j==1)
		{
			timezone_index();
		}
	     }
	}
	else
	{
		timezone_index();
	}
}

void menu()     //call all class
{
	textbackground(1);
	textcolor(8);
	char c;
	int i;
	clrscr();
	directory d;
	time_date();
	textcolor(19);
	for(i=1;i<=79;i++)
	{       gotoxy(i,1);
		cprintf("%c",219);
		gotoxy(i,4);
		cprintf("%c",219);
		gotoxy(i,18);
		cprintf("%c",219);
		gotoxy(i,23);
		cprintf("%c",219);
	}
		for(i=1;i<=52;i++)
	{
		gotoxy(i,11);
		cprintf("%c",219);
	}
	for(i=1;i<=23;i++)
	{
		gotoxy(1,i);
		cprintf("%c%c",219,219);
		gotoxy(79,i);
		cprintf("%c%c",219,219);
	}
	for(i=4;i<=18;i++)
	{
		gotoxy(1,i);
		cprintf("%c%c",219,219);
		gotoxy(25,i);
		cprintf("%c%c",219,219);
		gotoxy(52,i);
		cprintf("%c%c",219,219);
	}
	gotoxy(35,2);
	textcolor(12);
	cprintf("MENU");
	textcolor(YELLOW);
	gotoxy(10,7);
	cprintf("PHONEBOOK");
	gotoxy(38,7);
	cprintf("MESSAGE");
	gotoxy(10,14);
	cprintf("SECUTRITY");
	gotoxy(38,14);
	cprintf("EXTRA");
	gotoxy(62,7);
	cprintf("OPTION");
	gotoxy(58,9);
	cprintf("[p]FOR PHONEBOOK");
	gotoxy(58,10);
	cprintf("[m]FOR MESSAGE");
	gotoxy(58,11);
	cprintf("[s]FOR SECURITY");
	gotoxy(58,12);
	cprintf("[e]FOR EXTRA");
	gotoxy(58,13);
	cprintf("[x]FOR EXIT");
	gotoxy(30,20);
	textcolor(WHITE);
	cprintf("ENTER YOUR CHOICE:");
	c=getch();
	switch(c)
	{
		case'p':directory d;
			clrscr();
			for(;;)
			{
				d.phone_menu();
			}
			break;
		case'm':message ms;
			for(;;)
			{
				ms.message_menu();
			}
			break;
		case's':security ss;
			clrscr();
			for(;;)
			{
				ss.password_option();
			}
			getch();
			break;
		case'e': textcolor(18);
			clrscr();
			time_date();
			textcolor(19);
			for(i=1;i<=79;i++)
			{
				gotoxy(i,1);
				cprintf("%c",219);
				gotoxy(i,4);
				cprintf("%c",219);
				gotoxy(i,18);
				cprintf("%c",219);
				gotoxy(i,23);
				cprintf("%c",219);
			}
			for(i=1;i<=52;i++)
			{
				gotoxy(i,11);
				cprintf("%c",219);
			}
			for(i=1;i<=23;i++)
			{
				gotoxy(1,i);
				cprintf("%c%c",219,219);
				gotoxy(79,i);
				cprintf("%c%c",219,219);
			}
			for(i=4;i<=18;i++)
			{
				gotoxy(1,i);
				cprintf("%c%c",219,219);
				gotoxy(25,i);
				cprintf("%c%c",219,219);
				gotoxy(52,i);
				cprintf("%c%c",219,219);
			}

			gotoxy(35,2);
			textcolor(12);
			cprintf("EXTRA");
			textcolor(YELLOW);
			gotoxy(10,8);
			cprintf("CALCULATOR");
			gotoxy(37,8);
			cprintf("BMI");
			gotoxy(10,14);
			cprintf("TIME ZONE");
			gotoxy(37,14);
			cprintf("GAME");
			gotoxy(62,7);
			cprintf("OPTION");
			gotoxy(57,9);
			cprintf("[c]FOR CALCULATOR");
			gotoxy(57,10);
			cprintf("[b]FOR BMI");
			gotoxy(57,11);
			cprintf("[t]FOR TIME ZONE");
			gotoxy(57,12);
			cprintf("[g]FOR GAME");
			gotoxy(57,13);
			cprintf("[m]FOR MENU");
			gotoxy(57,14);
			cprintf("[x]FOR EXIT");
			gotoxy(30,20);
			textcolor(WHITE);
			cprintf("ENTER YOUR CHOICE:");
			textbackground(2);
			char cc;
			for(;;)
			{
			cc=getch();
			switch(cc)
			{
				case'c':
					calculator cal;
					clrscr();
					cal.calculation();
					getch();
					break;
				case'b':
					BMI bmi;
					clrscr();
					bmi.condition();
					getch();
					break;

				case't':world w;
					for(;;)
					{
						w.timezone_index();
					}
					break;
				case'm':
					menu();
					break;
				case'x':
					bye();
					exit(0);
			}
			}
			break;
		case'x':
			bye(); exit(0);
	}
}
void time_date()
{
	struct time t;
	gettime(&t);
	int i=t.ti_sec;
	int j=t.ti_min;
	int k=t.ti_hour;
	gotoxy(3,2);
	cout<<k<<":"<<j<<":"<<i<<endl;
	struct date d;
	getdate(&d);
	int l=d.da_day;
	int m=d.da_mon;
	int n=d.da_year;
	gotoxy(66,2);
	cout<<l<<":"<<m<<":"<<n<<endl;
}

void welcome_screen()
{

	textbackground(3);
	int j=35,k=38,l=20;
	char name1[7]="WELCOME";
	char name2[2]="TO";
	char name3[45]="MOBILE PHONE DATABASE SYSTEM MANAGEMENT";
	textcolor(WHITE);
	clrscr();
	time_date();
	border();
	gotoxy(30,8);
	textcolor(RED);
	for(int i=0;i<7;i++)
	{
		gotoxy(j,10);
		cprintf("%c",name1[i]);
		j++;
		delay(100);
	}
	for(i=0;i<2;i++)
	{
		gotoxy(k,11);
		cprintf("%c",name2[i]);
		k++;
		delay(100);
	}
	for(i=0;i<=38;i++)
	{
		gotoxy(l,12);
		cprintf("%c",name3[i]);
		l++;
		delay(100);
	}
	gotoxy(30,16);
	textcolor(BLINK);
	cputs("PRESS ANY KEY TO CONTINUE");
	getch();
}
void border()
{
	int i;
	time_date();
	for(i=1;i<=79;i++)
	{
		gotoxy(i,1);
		printf("%c",219);
		gotoxy(i,23);
		printf("%c",219);
	}
	for(i=1;i<=23;i++)
	{
	gotoxy(1,i);
	printf("%c%c",219,219);
	gotoxy(79,i);
	printf("%c%c",219,219);
	}
}
void bye()
{
       textbackground(BLACK);
       clrscr();
       border();
       textattr(7);
       gotoxy(30,10);
       delay(200);
       cprintf("T");
       textattr(9);
       gotoxy(32,10);
       delay(200);
       cprintf("H");
       textattr(10);
       gotoxy(34,10);
       delay(200);
       cprintf("A");
       textattr(11);
       gotoxy(36,10);
       delay(200);
       cprintf("N");
       textattr(12);
       gotoxy(38,10);
       delay(200);
       cprintf("K");
       gotoxy(40,10);
       delay(200);
       cprintf(" ");
       textattr(15);
       gotoxy(42,10);
       delay(200);
       cprintf("Y");
       textattr(7);
       gotoxy(44,10);
       delay(200);
       cprintf("O");
       textattr(2);
       gotoxy(46,10);
       delay(200);
       cprintf("U");
       textattr(9);
       gotoxy(48,10);
       delay(200);
       cprintf(".");
       textattr(10);
       gotoxy(50,10);
       delay(200);
       cprintf(".");
       textattr(11);
       gotoxy(52,10);
       delay(200);
       cprintf(".");
 }
void main()
{
	int d,c,i;
	char pass[10];
	security ss;
	welcome_screen();
	c=ss.test_password();
	if(c==0)
	{
		for(;;)
		{
			menu();
		}
	}
	else
	{

		for(i=1;i<=10;i++)
		{

			clrscr();
			border();
			gotoxy(30,10);
			cout<<"Enter Password:";
			gets(pass);
			ifstream fin;
			fin.open("password.dat");
			fin.read((char*)&s,sizeof(s));
			d=strcmp(s.password,pass);
			fin.close();
			if(d==0)
			{
				for(;;)
				{
					menu();
				}
			}
			else
			{       clrscr();
				border();
				gotoxy(30,10);
				cout<<"Wrong Password";
				getch();
			}
			if(i==3)
			{
			  bye();
			  break;
			}
		}
	}
      //	getch();
}




