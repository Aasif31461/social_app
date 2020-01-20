//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************


#include<fstream.h>
#include<ctype.h>
#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class whatsapp
{
	long double mbno;
	long double pass;
	char name[50],gender,st[200],ab[350];
	int dd,mm,yy;
public: void report();	//function to show data in tabular format
	long double retacno();	//function to return Mobile number
	char *getname(){ return name;}
	long double retpass();	//function to return Password
	void create_account();	//function to get data from user
	void show_account();	//function to show data on screen
		 //function to send massage
	void home();           //home function
	void modify();   //function to get new data from user
};         //class ends here
void main(void);
class massag
{  public:
   char mess[180];
   char Names[30];
   char Namer[30];
   char *getns(){ return Names;}
   char *getnr(){ return Namer;}
   void getdata(){
		   cout<<"\nEnter Your Name: ";
		 gets(Namer);
		 cout<<"\nEnter Name of Your Friend  : ";
		 gets(Namer);
		 cout<<"\nEnter Massage to send : ";
		 gets(mess);
		 }
   void putdata(){
		 cout<<"\nMassage From  : ";
		 puts(Namer);
		 cout<<"\n Massage: ";
		 puts(mess);
		 }
}M,L;
struct contact

{

    long ph;

    char name[20],add[20],email[30];

} list;

char query[20],name[20];

FILE *fp, *ft;

int i,n,ch,l,found;

void message()
{
   int ch;
		clrscr();
		cout<<"\n\n\n\tMESSAGE MENU";
		cout<<"\n\n\t01. SEND MESSAGE";
		cout<<"\n\n\t02. View Massage";
		cout<<"\n\n\t03. RETURN TO PREVIOUS MENU";
		cout<<"\n\n\tSelect Your Option (1-3) : ";
		cin>>ch;
		clrscr();
		if(ch==1)
		{
			    M.getdata();
				fstream outFile;
				outFile.open("message.dat",ios::binary|ios::app);
				outFile.write((char *) &M,sizeof(M));
				cout<<"\nMassage sent";
				outFile.close();
				}

		else if(ch==2)
		      {	       char N[30];
				cout<<"\nEnter Name :";
				gets(N);
				fstream outFil;
				outFil.open("message.dat",ios::binary|ios::app);
				outFil.seekp(0);
				outFil.read((char*) &L,sizeof(L));
				if(strcmp(N,L.getns())==0)
				 {
				   L.putdata();
				   }
				 else
				 cout<<" No New Massage !!!!!";
				 outFil.close();
		      }
		else if(ch==3)
		     getch();
		else
		 cout<<"\nINVALID INPUT !!!!!!!!";
   getch();
}




void whatsapp::create_account()
{
	cout<<"\nEnter Your Mobile No. :";
	cin>>mbno;
	cout<<"\n\nEnter Your Name: ";
	gets(name);
	cout<<"\nChoose and Enter Password: ";
	cin>>pass;
	label:
	cout<<"\nEnter Your Date of Birth(dd/mm/yy): ";
	cin>>dd>>mm>>yy;
	if(dd>0&&dd<31)
	{ if(mm>0&&mm<13)
	     if(yy>1991&&yy<2017)
	       cout<<"\nOk. It is Valid ";
	}
	else
	{ cout<<"\nInvalid Date Enterd !!!!..";
	   goto label;
	   }
	cout<<"\nEnter Your Gender(M/F): ";
	cin>>gender;
	cout<<"\nUpdate Your status... :";
	gets(st);
	cout<<"\nWrite Something About Yourself... :";
	gets(ab);
	cout<<"\nEverything done !,Press Enter to continue...";
	getch();
	cout<<"\n\n\nAccount Created Successfully......";
	cout<<"\nPress Enter to continue...";
	getch();
}

void login()
{      long double m,p;
	cout<<"\nEnter Your Mobile No. :";
	cin>>m;
	cout<<"\nChoose and Enter Password: ";
	cin>>p;
	whatsapp ac;
	int flag=0;
	ifstream inFile;
    inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(inFile.read((char *) &ac, sizeof(whatsapp)))
	{
		if(ac.retacno()==m&&ac.retpass()==p)
		{
			cout<<"\nSuccessfully Login Press Enter to Continue... :";
			getch();
		       ac.home();
			flag=1;
		}
	}
    inFile.close();
	if(flag==0)
		cout<<"\n\nAccount number does not exist";
}

void whatsapp::home()
{ clrscr();
  cout<<"\n******************************************************************";
  cout<<"\n\t\t--------------------------* WELCOME *---------------------------";
  cout<<"\n******************************************************************";
  cout<<"\n\nYou can Type Here Usual Dailystuff,status,massage Your Friends,Your";
  cout<<" mood Today\n\n So What are You Waiting For? Start Typing.......!";
  cout<<"\n------------------------------MENU--------------------------------";
  do
	{
		cout<<"\n\n\t01. CREATE CONTACTS";
		cout<<"\n\n\t02. VIEW ALL CONTACT";
		cout<<"\n\n\t03. SEARCH CONTACT";
		cout<<"\n\n\t04. MODIFY CONTACT";
		cout<<"\n\n\t05. DELETE CONTACT";
		cout<<"\n\n\t06. MASSAGE";
		cout<<"\n\n\t07. RETURN TO PREVIOUS MENU";
		cout<<"\n\n\tSelect Your Option (1-7) ";
		cin>>ch;

    switch(ch)

    {

	/* *********************Add new contacts************  */

    case 1:
    
	break;

	/* *********************list of contacts*************************  */

    case 2:

	clrscr();

	
	break;

	/* *******************search contacts**********************  */

    case 3:

	clrscr();

	
	break;

	/* *********************edit contacts************************/

    case 4:

	//To Be 

	break;

	/* ********************delete contacts**********************/

    case 5:

	clrscr();

	fflush(stdin);

	printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");

	scanf("%[^\n]",&name);

	fp=fopen("contact.dll","r");

	ft=fopen("temp.dat","w");

	while(fread(&list,sizeof(list),1,fp)!=0)

	    if (stricmp(name,list.name)!=0)

		fwrite(&list,sizeof(list),1,ft);

	fclose(fp);

	fclose(ft);

	remove("contact.dll");

	rename("temp.dat","contact.dll");

	break;
    case 6: message();
	    break;
    case 7: main();
	    exit(0);
	   break;

    default:

	printf("Invalid choice");

	break;

    }

    }while(ch!='7');
}


void whatsapp::show_account()
{
	cout<<"\nMobile No. : "<<mbno;
	cout<<"\nName : ";
	cout<<name;
	cout<<"\nDate of Birth: "<<dd<<"/"<<mm<<"/"<<yy;
	cout<<"\nGender : "<<gender;
	cout<<"\nStatus : ";
	puts(st);
	cout<<"\nAbout You : ";
	puts(ab);

}


void whatsapp::modify()
{       cout<<"\nEnter New Details.....";
	cout<<"\nEnter Your Mobile No. :";
	cin>>mbno;
	cout<<"\n\nEnter Your Name: ";
	gets(name);
	cout<<"\nChoose and Enter Password: ";
	cin>>pass;
	label:
	cout<<"\nEnter Your Date of Birth(dd/mm/yy): ";
	cin>>dd>>mm>>yy;
	if(dd>0&&dd<31)
	{ if(mm>0&&mm<13)
	     if(yy>1991&&yy<2017)
	       cout<<"\nOk. It is Valid ";
	}
	else
	{ cout<<"\nInvalid Date Enterd !!!!..";
	   goto label;
	   }
	cout<<"\nEnter Your Gender(M/F): ";
	cin>>gender;
	cout<<"\nUpdate Your status... :";
	gets(st);
	cout<<"\nWrite Something About Yourself... :";
	gets(ab);
	cout<<"\nEverything done !,Press Enter to continue...";
	getch();
	cout<<"\n\n\nChange Made Successfully......";
	cout<<"\nPress Enter to continue...";
}

void whatsapp::report()
{
	cout<<mbno<<"       "<<name<<"       "<<gender<<"        "<<dd<<"/"<<mm<<"/"<<yy<<endl;
}

long double whatsapp::retacno()
{
	return mbno;
}
long double whatsapp::retpass()
{
	return pass;
}


//***************************************************************
//    	function declaration
//****************************************************************
void write_account();	//function to write record in binary file
void display_sp(long double,long double);	//function to display account details given by user
void modify_account(long double,long double);	//function to modify record of file
void delete_account(long double,long double);	//function to delete record of file
void display_all();		//function to display all account details
void intro();	//introductory screen function

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

void main()
{

	char ch;
	long double pass, num;
	clrscr();
	intro();
	do
	{
		clrscr();
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. Login";
		cout<<"\n\n\t03. ALL ACCOUNT LIST";
		cout<<"\n\n\t04. DISPLAY MY ACCOUNT";
		cout<<"\n\n\t05. CLOSE AN ACCOUNT";
		cout<<"\n\n\t06. MODIFY AN ACCOUNT";
		cout<<"\n\n\t07. EXIT";
		cout<<"\n\n\tSelect Your Option (1-7) ";
		cin>>ch;
		clrscr();
		switch(ch)
		{
		case '1':
			write_account();
			break;

		case '2':
			login();
			break;

		case '3':
			display_all();
			break;
		case '4':
			cout<<"\n\n\tEnter The Mobile No. : "; cin>>num;
			 cout<<"\n\n\tEnter The Password : "; cin>>pass;
			display_sp(num,pass);
			break;
		case '5':
			cout<<"\n\n\tEnter The Mobile No. : "; cin>>num;
			 cout<<"\n\n\tEnter The Password : "; cin>>pass;
			delete_account(num,pass);
			break;
		 case '6':
			cout<<"\n\n\tEnter The Mobile No. : "; cin>>num;
			 cout<<"\n\n\tEnter The Password : "; cin>>pass;
			modify_account(num,pass);
			break;
		 case '7':
			cout<<"\n\n\tThanks For Using Whatsapp";
			break;
		 default :cout<<"\a";
		}
		getch();
    }while(ch!='7');
    getch();

}


//***************************************************************
//    	function to write in file
//****************************************************************

void write_account()
{
	whatsapp ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write((char *) &ac, sizeof(whatsapp));
	outFile.close();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(long double n,long double p )
{
	whatsapp ac;
	int flag=0;
	ifstream inFile;
    inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}

    while(inFile.read((char *) &ac, sizeof(whatsapp)))
	{
		if(ac.retacno()==n&&ac.retpass()==p)
		{
			ac.show_account();
			flag=1;
		}
	}
    inFile.close();
	if(flag==0)
		cout<<"\n\nAccount number does not exist";
}


//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_account(long double n,long double p)
{
	int found=0;
	whatsapp ac;
	fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(File.read((char *) &ac, sizeof(whatsapp)) && found==0)
	{
		if(ac.retacno()==n&&ac.retpass()==p)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*sizeof(whatsapp);
			File.seekp(pos,ios::cur);
		    File.write((char *) &ac, sizeof(whatsapp));
		    cout<<"\n\n\t Record Updated";
		    found=1;
		  }
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}

//***************************************************************
//    	function to delete record of file
//****************************************************************


void delete_account(long double n,long double p)
{
	whatsapp ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &ac, sizeof(whatsapp)))
	{
		if(ac.retacno()!=n&&ac.retpass()!=p)
		{
			outFile.write((char *) &ac, sizeof(whatsapp));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
}

//***************************************************************
//    	function to display all accounts deposit list
//****************************************************************

void display_all()
{
	whatsapp ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"Ph.no.      NAME           Gender    DOB\n";
	cout<<"====================================================\n";
	while(inFile.read((char *) &ac, sizeof(whatsapp)))
	{
		ac.report();
	}
	inFile.close();
}

//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
	cout<<"\n\n\n\t  A";
	cout<<"\n\n\tPROJECT ON";
	cout<<"\n\n\t 'SOCIAL_APP IN C++' ";
	getch();
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************