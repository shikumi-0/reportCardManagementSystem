#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<process.h>
#include<windows.h>


#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;
int rec_flag=0,no=0;
char rec_ind[5];

  void Password();
  void Teacher();
  void Student();
  void Public();
float round(float sgpa)
{
	char str[40]; 
 
    sprintf(str, "%.2f", sgpa);

   	sscanf(str, "%f", &sgpa); 
  
   	return sgpa; 
}
  
struct student
{
  	  char name[20];
	  char fName[10], mName[10], date[15], telNo[11];
      char year[4];
      char sem[2];
      char rno[2],usn[20],ind[5];
      char elective;
      float marks[8];
      char sec_code[5];
      char branch[5];
      float sgpa;
      int subGP[8];
      char grade;

}s[20];


struct index
{
    char usn[20],ind[20];
}in[20],temp;

void sort_index()
{
    int i,j;
    for(i=0;i<no-1;i++)
    for(j=0;j<no-i-1;j++)
    if(strcmp(in[j].usn,in[j+1].usn)>0)
    {
       temp=in[j];
       in[j]=in[j+1];
       in[j+1]=temp;
    }

}


void search(char *ind)
{
    for(int i=0;i<no;i++)
    {
      if(strcmp(s[i].ind,ind)==0)
      {
      strcpy(rec_ind,ind);
      rec_flag=1;
      cout<<"\n\t RECORD FOUND!:\n\n\n";
      	   cout<<"\t---------------------------------";
           cout<<"---------------------------------\n";
           cout<<"                          JSS ACADEMY OF TECHNICAL EDUCATION \n\n";
           cout<<"                               STUDENT REPORT CARD\n";
           cout<<"\t---------------------------------";
           cout<<"---------------------------------\n\n";
           cout<<"                           ------------------------\n";
           cout<<"                               PERSONAL DETAILS\n";
           cout<<"                           ------------------------\n\n";
           cout<<"\t\tNAME: "<<s[i].name<<"\t\t";
           cout<<"USN: "<<s[i].usn<<"\t\t";
//           cout<<"INDEX: "<<s[i].ind<<"\t\t";
           cout<<"SEM: "<<s[i].sem<<"\t\t\n";
           cout<<"\t\tBRANCH: "<<s[i].branch<<"\t\t";
           cout<<"ROLL NO: "<<s[i].rno<<"\t\t\n";
           cout<<"\t\tDATE OF BIRTH: "<<s[i].date<<"\t\t";
           cout<<"TELEPHONE: "<<s[i].telNo<<"\n\n";
           cout<<"\t\tFATHERS NAME: "<<s[i].fName<<"\t\t\t";
           cout<<"MOTHERS NAME: "<<s[i].mName<<"\n\n";
           cout<<"                 ----------------------------------------\n";
           cout<<"                            ACADEMIC PERFORMANCE\n";
           cout<<"                 ----------------------------------------\n\n\n";
           cout<<"                 ----------------------------------------\n";
           cout<<"                                  MARKS\n";
           cout<<"                 ----------------------------------------\n";
           if(s[i].elective=='C')
           {
               cout<<"\t\t  SOFTWARE TESTING:                  : \t"<<s[i].marks[0]<<"\n";
               cout<<"\t\t  FILE STRUCTURE                     : \t"<<s[i].marks[1]<<"\n";
               cout<<"\t\t  MOBILE APPLICATION DEVELOPMENT     : \t"<<s[i].marks[2]<<"\n";
               cout<<"\t\t  ADVANCED LINEAR ALGEBRA            : \t"<<s[i].marks[3]<<"\n";
               cout<<"\t\t  CLOUD COMPUTING                    : \t"<<s[i].marks[4]<<"\n";
               cout<<"\t\t  WEB APPLICATION AND ITS APPLICATION: \t"<<s[i].marks[5]<<"\n";
               cout<<"\t\t  FILE STRUCTURE LAB                 : \t"<<s[i].marks[6]<<"\n";
               cout<<"\t\t  SOFTWARE TESTING LAB               : \t"<<s[i].marks[7]<<"\n";
           }
           else
           {
               cout<<"\t\t  SOFTWARE TESTING                   : \t"<<s[i].marks[0]<<"\n";
               cout<<"\t\t  FILE STRUCTURE                     : \t"<<s[i].marks[1]<<"\n";
               cout<<"\t\t  MOBILE APPLICATION DEVELOPMENT     : \t"<<s[i].marks[2]<<"\n";
               cout<<"\t\t  ADVANCED LINEAR ALGEBRA            : \t"<<s[i].marks[3]<<"\n";
               cout<<"\t\t  ADVANCED JAVA AND J2EE             : \t"<<s[i].marks[4]<<"\n";
               cout<<"\t\t  WEB APPLICATION AND ITS APPLICATION: \t"<<s[i].marks[5]<<"\n";
               cout<<"\t\t  FILE STRUCTURE LAB                 : \t"<<s[i].marks[6]<<"\n";
               cout<<"\t\t  SOFTWARE TESTING LAB               : \t"<<s[i].marks[7]<<"\n\n";
           }     
           cout<<"                -------------------        ------------\n";
           cout<<"                 SGPA: "<<round(s[i].sgpa)<<""<<"           ";
           cout<<"GRADE: "<<s[i].grade<<"\n";
           cout<<"                -------------------        ------------\n\n";
      }
    }
}

void displayall(){
	ifstream f("Record1.txt");
	
		cout<<"\n\n\t\t\t  ---------------------------"<<"\n";
         cout<<"\t\t\t     LIST OF CLASS RECORDS"<<"\n";
         cout<<"\t\t\t  ---------------------------"<<"\n\n";
         
         if(!f)
     		{
        		 cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tFILE NOT FOUND!";
        		 cout<<"\n\n\n\n\n\n\n\n";
    		}
   else
   {
   
	for(int i=0;i<no;i++)
		{
		   cout<<"\t---------------------------------";
           cout<<"---------------------------------\n\n\n";
		   cout<<"\t\tNAME:  "<<s[i].name<<"\n";
           cout<<"\t\tFATHER: "<<s[i].fName<<"\t"<<"MOTHER: "<<s[i].mName<<"\n";
           cout<<"\t\tROLL NO: "<<s[i].rno<<"\t"<<"SECURE CODE: "<<s[i].sec_code<<"\n";
           
           cout<<"\t\tUSN: "<<s[i].usn<<"\n";
           cout<<"\t\tYEAR: "<<s[i].year<<"\n\n";
           cout<<"\t\tSEM: "<<s[i].sem<<"\n";
           cout<<"\t\tELECTIVE: "<<s[i].elective<<"\n";
           cout<<"\t\tTELEPHONE NO: "<<s[i].telNo<<"\n\n";
           cout<<"\t\t                -----MARKS-----"<<"\n\n";
           cout<<"\t\tST\tFS\tMAD\tALA\tCC/JAVA\t\tWEB\tFSL\tSTL"<<"\n\n";
           cout<<"\t\t"<<s[i].marks[0]<<"\t"<<s[i].marks[1]<<"\t"<<s[i].marks[2]<<"\t";
           cout<<s[i].marks[3]<<"\t"<<s[i].marks[4]<<"\t\t"<<s[i].marks[5]<<"\t";
           cout<<s[i].marks[6]<<"\t"<<s[i].marks[7]<<"\t\n\n";
           cout<<"\n\t\tSGPA: "<<round(s[i].sgpa)<<"\t\t"<<"GRADE: "<<s[i].grade<<"\n\n\n"; 
           cout<<"\t---------------------------------";
           cout<<"---------------------------------\n\n";
		}	
	}
}

int search_index(char *usn)
{
      int flag=0;
      for(int i=0;i<no;i++)
      {
	  if(strcmp (in[i].usn,usn)==0)
	  {
	     search(in[i].ind);
	     flag=1;
	  }
      }
      if(flag)
	  return 1;
      else
	  return -1;
}


 int search_usn(char *usn,int j)
{
      int flag=0;
      for(int i=0;i<j;i++)
      {
	  if(strcmp (s[i].usn,usn)==0)
	  {
	     flag=1;
//	     search(s[i].usn);
		 break;
	  }
      }
      if(flag)
	  return 1;
      else
	  return -1;
}
void dispall()
{	 
     student s;
     ifstream f("Record1.txt");
     if(!f)
     {
         cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tFILE NOT FOUND!";
         cout<<"\n\n\n\n\n\n\n\n";
     }
     else
     {
         cout<<"\t\t\t  ---------------------------"<<"\n";
         cout<<"\t\t\t     LIST OF CLASS RECORDS"<<"\n";
         cout<<"\t\t\t  ---------------------------"<<"\n\n";
         while(f.read((char*)&s,sizeof(s)))
         {
//             s.display_all();
             cout<<"\n\n\n\t\t---------------------------------------------\n\n\n";
         }
     }
     f.close();
}



void del(char *st_usn)
{
	
	fstream file1;
	rec_flag=0;
	int fr=0;
	search_index(st_usn);
	if(!rec_flag)
	{
		cout<<"Deletion failed.Record not found\n";
		return;
	}
	for(int i=0;i<no;i++)
	{
		if(strcmp(s[i].ind,rec_ind)==0)
		{
			fr=i;
			break;
		}
	}
	for(int i=fr;i<no-1;i++)
	{
		s[i]=s[i+1];
		char str[3];
		sprintf(str,"%d",i);
		strcpy(s[i].ind,str);
	}
	no--;
	fstream f1,f2;
    f1.open("record1.txt",ios::out);
	f2.open("index.txt",ios::out);
	for(int i=0;i<no;i++)
	{
		strcpy(in[i].usn,s[i].usn);
		strcpy(in[i].ind,s[i].ind);
	}
	sort_index();
	for(int i=0;i<no;i++)
	{
     f1<<s[i].ind<<"|"<<s[i].usn<<"|"<<s[i].name<<"|"<<s[i].sem<<"|"<<s[i].date<<"|"<<s[i].branch<<s[i].sgpa<<"|"<<s[i].grade<<"|"<<s[i].year<<"|"<<s[i].elective<<"\n";
     f2<<in[i].usn<<"|"<<in[i].ind<<"\n";
	}
	f1.close();
	f2.close();
	cout<<"Deletion Successful\n";
	
}

/******************SEARCING FOR A RECORD (STUDENT)******************/
void search_student()
{
     
     fstream f("Record1.txt",ios::in);
     char n[10];
	 char flag=0;
     char a[5];
     if(!f)
     {
         cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tFILE NOT FOUND!";
         cout<<"\n\n\n\n\n\n\n\n";
     }
     else
     {
         cout<<"\n\n\n\n\n\n\n\n\n\t\t\t";
         cout<<"ENTER YOUR USN NUMBER: ";
         cin>>n;
         cout<<"\n\t\t\t";
//         cout<<"ENTER YOUR SECURE CODE: ";
//         cin.ignore();
         cin.getline(a,5);
         system("cls");
         
             for (int i=0; i<no; i++)
             {
             	if(strcmp(s[i].usn,n)==0)
           	   {
           	   	search_index(n);
                 flag=1;  
               }		 
         }
         if(flag==0)
         {
             cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tRECORD NOT FOUND!";
             cout<<"\n\n\n\n\n\n\n\n";
         }
     }
     f.close();
}


void modify()
{    fstream file1,file3;
	char ind[5],st_usn[20],name[20];
	 char fName[10], mName[10], date[15], telNo[11];
      char year[4];
      char sem[2];
      char rno[2],usn[20];
      char elective;
      float marks[8];
      char sec_code[5];
      char branch[5];
      float sgpa;
      int subGP[8];
      char grade;
	
      int i, found = -1;
	file1.open("record1.txt",ios::app|ios::out);
		
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t";
         cout<<"ENTER THE USN OF THE STUDENT: ";
         cin>>usn;
         found=search_index(usn);
    if (found == -1)
        cout <<"Record Not Found";
    else
    {
    	for(int i=0;i<no;i++)
    		if(strcmp(s[i].usn,usn)==0)
    		{
    			found=i;
    			break;
    		}
		   cout<<"\t\t\t  -------------------------------"<<"\n";
           cout<<"\t\t\t     ENTER THE MODIFIED STUDENT DETAILS"<<"\n";
           cout<<"\t\t\t  -------------------------------"<<"\n\n";
		
		  
           cout<<"\t\t\t"<<"\n\n";
           cout<<"\t\tNAME OF THE STUDENT      : "; 
           cin.ignore();
           cin.getline(name,20);
           cout<<"\t\tFATHER'S NAME            : ";
           cin.getline(fName,20);
           cout<<"\t\t MOTHER'S NAME           : ";
           cin>>mName;
           cout<<"\t\tUSN                      : ";
           cin>>usn;
           cout<<"\t\t DATE OF BIRTH(DD/MM/YY) : ";
           cin>>date;
           cout<<"\t\t TELEPHONE NUMBER        : ";
           cin>>telNo;
           cout<<"\t\t SECURITY CODE           : ";
           cin>>sec_code;
           cout<<"\t\t Year                    : ";
           cin>>year;
           cout<<"\t\t Sem                     : ";
           cin>>sem;
           cout<<"\t\t ROLL NUMBER             : ";
           cin>>rno;
           cout<<"\t\t Branch                  : ";
           cin>>branch;
           cout<<"\n\t\t Elective('C' FOR CLOUD OR 'A' FOR ADVANCED JAVA): ";
           cin>>elective;
           cout<<"\n";
           if(elective=='C')
           {
              cout<<"\t\t\t  -----------------------------"<<"\n";
              cout<<"\t\t\t     ENTER THE SUBJECT MARKS"<<"\n";
              cout<<"\t\t\t  -----------------------------"<<"\n\n";
              cout<<"\t\t\t       SOFTWARE TESTING                    : ";
              cin>>marks[0];
              cout<<"\t\t\t       FILE STRUCTURE                      : ";
              cin>>marks[1];
              cout<<"\t\t\t       MOBILE APPLICATION DEVELOPMENT LAB  : ";
              cin>>marks[2];
              cout<<"\t\t\t       ADVANCED LINEAR ALGEBRA             : ";
              cin>>marks[3];
              cout<<"\t\t\t       CLOUD COMPUTING                     : ";
              cin>>marks[4];
              cout<<"\t\t\t       WEB APPLICATION AND ITS APPLICATION : ";
              cin>>marks[5];
              cout<<"\t\t\t       FILE STRUCTURE LAB                  : ";
              cin>>marks[6];
              cout<<"\t\t\t       SOFTWARE TESTING LAB                : ";
              cin>>marks[7];   
           }     
           else
           {
              cout<<"\t\t\t  -----------------------------"<<"\n";
              cout<<"\t\t\t     ENTER THE SUBJECT MARKS"<<"\n";
              cout<<"\t\t\t  -----------------------------"<<"\n\n";
              cout<<"\t\t\t       SOFTWARE TESTING               : ";
              cin>>marks[0];
              cout<<"\t\t\t       FILE STRUCTURE                 : ";
              cin>>marks[1];
              cout<<"\t\t\t       MOBILE APPLICATION DEVELOPMENT : ";
              cin>>marks[2];
              cout<<"\t\t\t       ADVANCED LINEAR ALGEBRA        : ";
              cin>>marks[3];
              cout<<"\t\t\t       ADVANCED JAVA AND J2EE         : ";
              cin>>marks[4];
              cout<<"\t\t\t       WEB APPLICATION AND ITS APPLICATION : ";
              cin>>marks[5];
              cout<<"\t\t\t       FILE STRUCTURE LAB                  : ";
              cin>>marks[6];
              cout<<"\t\t\t       SOFTWARE TESTING LAB                : ";
              cin>>marks[7];
           }
           	for (int j=0; j <8; j++)
			  {
			  		if (marks[j]>=90&& marks[j]<100)
					{
					  	subGP[j]=10;
					}
					else if (marks[j]>=80 && marks[j]<90)
					{
					  	subGP[j]=9;
					}
					else if (marks[j]>=70 && marks[j]<80)
					{
					  	subGP[j]=8;
					}
					else if (marks[j]>=60 && marks[j]<70)
					{
					  	subGP[j]=7;
					}
					else if (marks[j]>=50 && marks[j]<60)
					{
					  	subGP[j]=6;
					}
					else if (marks[j]>=45 && marks[j]<50)
					{
					  	subGP[j]=5;
					}
					else if (marks[j]>=40&& marks[j]<45)
					{
					  	subGP[j]=4;
					}		  
			  }
			  
			  sgpa=((subGP[0]*4)+(subGP[1]*4)+(subGP[2]*3)+(subGP[3]*3)+(subGP[4]*4)+(subGP[5]*2)+(subGP[6]*2)+(subGP[7]*2))/24;
			  
		   if(sgpa==10)
           grade='O';
           else if((sgpa>=9)&&(sgpa<10))
           grade='S';
           else if((sgpa>=8)&&(sgpa<9))
           grade='A';
           else if((sgpa>=7)&&(sgpa<8))
           grade='B';
           else if((sgpa>=6)&&(sgpa<7))
           grade='C';
           else if((sgpa>=5)&&(sgpa<6))
           s[i].grade='D';
           else if((sgpa>=3.5)&&(sgpa<5))
           grade='E';
           else if(sgpa<3.5)
           grade='F';
		  
		char str[3];    
		sprintf(str,"%d",found);
		strcpy(s[found].ind,str);
		strcpy(s[found].usn,usn);
    	strcpy(s[found].name,name);
    	strcpy(s[found].fName,fName);
    	strcpy(s[found].mName,mName);
    	strcpy(s[found].sem,sem);
    	strcpy(s[found].date,date);
    		strcpy(s[found].branch,branch);
    	strcpy(s[found].sec_code,sec_code);
    
    	strcpy(s[found].year,year);
	    for(int i=0;i<no;i++)
        {
            strcpy(in[i].ind,s[i].ind);
            strcpy(in[i].usn,s[i].usn);
        }
        sort_index();
        file1.open("record1.txt",ios::out);
        file3.open("index1.txt",ios::out);
        for(int i=0;i<=no;i++)
        {
        	file1<<s[i].ind<<"|"<<s[i].usn<<"|"<<s[i].name<<"|"<<s[i].fName<<"|"<<s[i].mName<<"|"<<s[i].sem<<"|"<<s[i].date<<"|"<<s[i].branch<<"|"<<s[i].sec_code<<"|"<<s[i].year<<"\n";
            file3<<in[i].usn<<"|"<<in[i].ind<<"\n";
        }
    	cout<<"\t DETAILS UPDATED.\n";
    	file1.close();
    }
}

void add()
{   
   		char ind[5],st_usn[20],name[20],date[15],sem[5],branch[5],usn[20], year[4];
     char fName[10], mName[10], telNo[11];
      int i;
      float sgpa;
      char elective;
      char sec_code[5];
       fstream file1, file3;; 
      
	file1.open("record1.txt",ios::app|ios::out);
		if(!file1)
		{
		  cout<<"File creation error\n";
		  exit(0);
		}
		int n;
		cout<<"\t ENTER NUMBER OF STUDENTS \n";
		cin>>n;
		
		for(int i=no;i<no+n;i++)
		{
			
		cout<<"\t\t\t  -------------------------------"<<"\n";
           cout<<"\t\t\t     ENTER THE STUDENT DETAILS"<<"\n";
           cout<<"\t\t\t  -------------------------------"<<"\n\n";
		  
           cout<<"\t\t\t"<<"\n\n";
           label: cout<<"\t\tNAME OF THE STUDENT    : "; 
           cin.ignore();
           cin.getline(s[i].name,20);
           cout<<"\t\tFATHER'S NAME          : ";
           cin>>s[i].fName;
           cout<<"\t\t MOTHER'S NAME          : ";
           cin>>s[i].mName;
           cout<<"\t\tUSN         : ";
           cin>>s[i].usn;
           cout<<"\t\t DATE OF BIRTH(DD/MM/YY): ";
           cin>>s[i].date;
           cout<<"\t\t TELEPHONE NUMBER       : ";
           cin>>s[i].telNo;
           cout<<"\t\t SECURITY CODE          : ";
           cin>>s[i].sec_code;
           cout<<"\t\t Sem              : ";
           cin>>s[i].sem;
           cout<<"\t\t Year                  : ";
           cin>>s[i].year; 
           cout<<"\t\t ROLL NUMBER            : ";
           cin>>s[i].rno;
           cout<<"\t\t Branch           : ";
           cin>>s[i].branch;
           cout<<"\n\t\t Elective('C' FOR CLOUD OR 'A' FOR ADVANCED JAVA): ";
           cin>>s[i].elective;
           cout<<"\n";
           if(s[i].elective=='C')
           {
              cout<<"\t\t\t  -----------------------------"<<"\n";
              cout<<"\t\t\t     ENTER THE SUBJECT MARKS"<<"\n";
              cout<<"\t\t\t  -----------------------------"<<"\n\n";
              cout<<"\t\t\t       SOFTWARE TESTING                    : ";
              cin>>s[i].marks[0];
              cout<<"\t\t\t       FILE STRUCTURE                      : ";
              cin>>s[i].marks[1];
              cout<<"\t\t\t       MOBILE APPLICATION DEVELOPMENT LAB  : ";
              cin>>s[i].marks[2];
              cout<<"\t\t\t       ADVANCED LINEAR ALGEBRA             : ";
              cin>>s[i].marks[3];
              cout<<"\t\t\t       CLOUD COMPUTING                     : ";
              cin>>s[i].marks[4];
              cout<<"\t\t\t       WEB APPLICATION AND ITS APPLICATION : ";
              cin>>s[i].marks[5];
              cout<<"\t\t\t       FILE STRUCTURE LAB                  : ";
              cin>>s[i].marks[6];
              cout<<"\t\t\t       SOFTWARE TESTING LAB                : \n\n";
              cin>>s[i].marks[7];   
           }     
           else
           {
              cout<<"\t\t\t  -----------------------------"<<"\n";
              cout<<"\t\t\t     ENTER THE SUBJECT MARKS"<<"\n";
              cout<<"\t\t\t  -----------------------------"<<"\n\n";
              cout<<"\t\t\t       SOFTWARE TESTING                    : ";
              cin>>s[i].marks[0];
              cout<<"\t\t\t       FILE STRUCTURE                      : ";
              cin>>s[i].marks[1];
              cout<<"\t\t\t       MOBILE APPLICATION DEVELOPMENT      : ";
              cin>>s[i].marks[2];
              cout<<"\t\t\t       ADVANCED LINEAR ALGEBRA             : ";
              cin>>s[i].marks[3];
              cout<<"\t\t\t       ADVANCED JAVA AND J2EE              : ";
              cin>>s[i].marks[4];
              cout<<"\t\t\t       WEB APPLICATION AND ITS APPLICATION : ";
              cin>>s[i].marks[5];
              cout<<"\t\t\t       FILE STRUCTURE LAB                  : ";
              cin>>s[i].marks[6];
              cout<<"\t\t\t       SOFTWARE TESTING LAB                : \n\n";
              cin>>s[i].marks[7];
              int q=search_usn(s[i].usn,i);
					if(q==1)
					{
					cout<<"\t\t USN ALREADY EXISTS \n\t\t PLEASE ENTER AGAIN\n";
					goto label;
					}
           }
           	for (int j=0; j <8; j++)
			  {
			  		if (s[i].marks[j]>=90&& s[i].marks[j]<100)
					{
					  	s[i].subGP[j]=10;
					}
					else if (s[i].marks[j]>=80 && s[i].marks[j]<90)
					{
					  	s[i].subGP[j]=9;
					}
					else if (s[i].marks[j]>=70 && s[i].marks[j]<80)
					{
					  	s[i].subGP[j]=8;
					}
					else if (s[i].marks[j]>=60 && s[i].marks[j]<70)
					{
					  	s[i].subGP[j]=7;
					}
					else if (s[i].marks[j]>=50 && s[i].marks[j]<60)
					{
					  	s[i].subGP[j]=6;
					}
					else if (s[i].marks[j]>=45 && s[i].marks[j]<50)
					{
					  	s[i].subGP[j]=5;
					}
					else if (s[i].marks[j]>=40&& s[i].marks[j]<45)
					{
					  	s[i].subGP[j]=4;
					}		  
			  }
			
			  
			  s[i].sgpa=((s[i].subGP[0]*4)+(s[i].subGP[1]*4)+(s[i].subGP[2]*3)+(s[i].subGP[3]*3)+(s[i].subGP[4]*4)+(s[i].subGP[5]*2)+(s[i].subGP[6]*2)+(s[i].subGP[7]*2))/24;
			  
		   if(s[i].sgpa==10)
           s[i].grade='O';
           else if((s[i].sgpa>=9)&&(s[i].sgpa<10))
           s[i].grade='S';
           else if((s[i].sgpa>=8)&&(s[i].sgpa<9))
           s[i].grade='A';
           else if((s[i].sgpa>=7)&&(s[i].sgpa<8))
           s[i].grade='B';
           else if((s[i].sgpa>=6)&&(s[i].sgpa<7))
           s[i].grade='C';
           else if((s[i].sgpa>=5)&&(s[i].sgpa<6))
           s[i].grade='D';
           else if((s[i].sgpa>=3.5)&&(s[i].sgpa<5))
           s[i].grade='E';
           else if(s[i].sgpa<3.5)
           s[i].grade='F';
		  
		    
		file1<<i<<"|"<<s[i].usn<<"|"<<s[i].name<<"|"<<s[i].fName<<"|"<<s[i].mName<<"|"<<s[i].sem<<"|"<<s[i].date<<"|"<<s[i].branch<<"|"<<s[i].sec_code<<"|"<<s[i].year<<"\n";
	       }
	       file1.close();
	       no=no+n;
	       sort_index(); 
	       fstream file2;
	       file2.open("index1.txt",ios::out);
	       file1.open("record1.txt",ios::in);
	      
	       
	    for(int i=0;i<no;i++)
	    {
		  file1.getline(ind,5,'|');
		  file1.getline(usn,20,'|');
		  file1.getline(name,20,'|');
		  file1.getline(fName,20,'|');
		  file1.getline(mName,20,'|');
		  file1.getline(sem,5,'|');
		  file1.getline(date,15,'|');
		  file1.getline(branch,5,'|');
		  file1.getline(sec_code,5,'|');
		  file1.getline(year,4,'\n');
		  strcpy(s[i].ind,ind);
		  strcpy(in[i].ind,ind);
		  strcpy(in[i].usn,usn);
		  
	       }
	       
	       sort_index();
	       
	       for(int i=0;i<no;i++)
	       {
		   file2<<in[i].usn<<"|"<<in[i].ind<<"\n";
	       }
	       sort_index();
	       file3.close();
	       file2.close();
}




/*******************SPLITTING INTO DIFFERENT USERS*******************/
void Segregation()
{
     int n;
     start:
     system("cls");
     cout<<"\n\n\n\n\n";
     cout<<"\t\t\t      ---------------"<<"\n";
     cout<<"\t\t\t         MAIN MENU"<<"\n";
     cout<<"\t\t\t      ---------------"<<"\n\n\n";
     cout<<"\t\t\t     SELECT DESIGNATION"<<"\n\n";
     cout<<"\t\t-------------------------------------------"<<"\n";
     cout<<"\t\t\t  1. TEACHER\t2. STUDENT\t"<<"\n";
     cout<<"\t\t-------------------------------------------"<<"\n\n";
     cout<<"\t\t             (PRESS 3 TO EXIT)"<<"\n\n\n"; 
     cout<<"\t\t       ENTER AN OPTION: ";
     cin>>n;
     system("cls");
     switch(n)
     {
              case 1: system("cls");
                      Password();
                      break;
              case 2: Student();
                      break;
//              case 3: Public();
//                      break;
              case 3: exit(0);
                      break;        
              default:cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tWRONG OPTION!";
                      cout<<"\n\n\n\n\n\n\n\n";
                      system("PAUSE");
     }
     goto start; 
}


void Intro()
{
     cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tA PROGRAM BY SHIVANG, SITANSHU AND NITISH";
     Sleep(1000);
     system("cls");
     for(int i=0;i<=100;++i)
     {
         Sleep(5);
         system("cls");
         cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tWELCOME TO";
         cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLOADING "<<i<<"%";
         if(i==100)
         {
             Sleep(1000);
         }
     }
     system("cls");
     cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tREPORT CARD MANAGEMENT SYSTEM";
     Sleep(1000);
     system("cls"); 
}
/*************************TEACHER FUNCTION*************************/
void Teacher()
{	char a[20];
	char st_usn[20];
     int n;
     start:
     system("cls");
     cout<<"\n\n\n\n\n\n";
     cout<<"\t\t\t\t  ------------"<<"\n";
     cout<<"\t\t\t\t      MENU"<<"\n";
     cout<<"\t\t\t\t  ------------"<<"\n";
     cout<<"\t\t\t     1. ADD A NEW RECORD"<<"\n";
     cout<<"\t\t\t     2. SEARCH FOR A RECORD"<<"\n";
     cout<<"\t\t\t     3. MODIFY A RECORD"<<"\n";
     cout<<"\t\t\t     4. DELETE A RECORD"<<"\n";
     cout<<"\t\t\t     5. DISPLAY ALL THE RECORDS"<<"\n";
//     cout<<"\t\t\t     6. CLASS STATISTICS"<<"\n";
     cout<<"\t\t\t     6. GO TO MAIN MENU"<<"\n\n";
     cout<<"\t\t\t     ENTER YOUR OPTION: ";
     cin>>n;
     system("cls");
     switch(n)
     {
              case 1: add();
                      break;
              case 2: 
			  		  {
					  cout<<"\nENTER USN OF THE STUDENT \n";
					  cin>>st_usn;
					  int q=search_index(st_usn);
		              if(q==1)
		              { 
		                search(st_usn);
		            	cout<<"\t SEARCH SUCCESSFUL\n";
		              }
		              else
		              cout<<"\t RECORD NOT FOUND\n";
					  break;}
					  
              case 3: modify();
                      break;
              case 4: 
        		      cout<<"ENTER THE USN NUMBER OF STUDENT YOU WANT TO DELETE: \n";
      				  cin>>a;   
         			  del(a);            
                      break;
              case 5:  
						
			  		  displayall();    				  
                      break;
//              case 6: statistics();
//                      break;
              case 6: Segregation();
                      break;
              default:cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tWRONG OPTION!";
                      cout<<"\n\n\n\n\n\n\n\n";
     }
     system("PAUSE");
     goto start;
}


/*************************STUDENT FUNCTION*************************/
void Student()
{
     int n;
     start:
     system("cls");
     cout<<"\n\n\n\n\n\n\n";
     cout<<"\t\t\t\t ------------"<<"\n";
     cout<<"\t\t\t\t     MENU"<<"\n";
     cout<<"\t\t\t\t ------------"<<"\n";
     cout<<"\t\t\t   1. SEARCH FOR YOUR RECORD"<<"\n";
//     cout<<"\t\t\t   2. VIEW CLASS STATISTICS"<<"\n";
     cout<<"\t\t\t   2. GO TO MAIN MENU"<<"\n\n";
     cout<<"\t\t\t   ENTER YOUR OPTION: ";
     cin>>n;
     system("cls");
     switch(n)
     {
              case 1:search_student();
                     break;
//              case 2:statistics();
//                     break;
              case 2:Segregation();
                     break;
              default:cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tWRONG OPTION!!";
                      cout<<"\n\n\n\n\n\n\n\n";
     }
     system("PAUSE");
     goto start;
}



/*************************PASSWORD FUNCTION*************************/
void Password()
{
     char pass[7];
     pass[6]='\0';
     int t=0;
     start:
     cout<<"\n\n\n\n\n\n\n\n\n\t\t\tENTER THE PASSWORD: ";
     for(int i=0;i<6;++i)
     {
             pass[i]=getch();
             cout<<"*";
     }
     cout<<"\n\n";
     if(strcmp(pass,"123456")==0)
     {
         cout<<"\t\t\t      ACCESS GRANTED";
         Sleep(1000);
//         system("cls");
         Teacher();
     }
     else
     {
         if(t==2)
         {
             cout<<"\t\t\t      ACCESS DENIED"<<"\n\n\n\n\n\n\n\n";
             system("PAUSE");
             system("cls");
             Segregation();
         }
         cout<<"\t\t\t      TRY AGAIN";
         ++t;
         Sleep(3000);
         system("cls");
         goto start;
     }
}

/*********************SETTING FUNCTION SEQUENCE*********************/
void SEQUENCE()
{
     Intro();
     Segregation();
}

/***************************MAIN FUNCTION***************************/
int main()
{
     system("title REPORT CARD MANAGEMENT SYSTEM");
    
     
     system("COLOR b");
     
     fstream file1, file3;
     SEQUENCE();
     getch();
     return 0;
}
