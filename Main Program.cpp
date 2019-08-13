/*---------------- LPU Finder ---------------
_______________ By: Akash Kumar _____________
_________________ 11702349 __________________
___________________ K17DQ ___________________
______ Lovely Professional University _______
---------------------------------------------*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <process.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
//============================================================================================
	//class to store details of all sections
class student
{
	public:
 	int n,id[50],age[50],rollno[50];
 	long int phno[50];
 	int placecooruid,placementuid,ecelluid,sechoduid,secmentuid;
 	char name[50][50],section[30],secment[40],sechod[50];
 	char ecell[50],placement[50],cr[50],placecoor[50];
 	public:
//=============================================================================================
	//   MEMBER FUNCTION TO ADD RECORDS 
		void insert()
		{
 			cout<<"\n\t****************************** Welcome to add records **********************************";
 			cout<<"\n\t--->Enter the Section name : ";
 			fflush(stdin);					//to clear out standard inputs
 			gets(section);
			cout<<"Enter Section Mentor : ";
			fflush(stdin);					//to clear out standard inputs 			
			gets(secment);
			cout<<"Enter uid no : ";
			cin>>secmentuid;
 			cout<<"\nEnter Section HOD : ";
			fflush(stdin);					//to clear out standard inputs 			
			gets(sechod);
			cout<<"Enter uid no : ";
			cin>>sechoduid;
 			cout<<"\nEnter Placement Mentor : ";
			fflush(stdin);					//to clear out standard inputs 			
			gets(placement);
			cout<<"Enter uid no : ";
			cin>>placementuid;
 			cout<<"\nEnter Class Representive : ";
			fflush(stdin);					//to clear out standard inputs
 			gets(cr);
 			cout<<"\nEnter E-Cell Coordinator : ";
			fflush(stdin);					//to clear out standard inputs
 			gets(ecell); 
 			cout<<"Enter uid no : ";
 			cin>>ecelluid;
 			cout<<"\nEnter Placement Coordinator : ";
			fflush(stdin);					//to clear out standard inputs
 			gets(placecoor);
 			cout<<"Enter uid no : ";
 			cin>>placecooruid;
 			cout<<"\nEnter the total no of students : ";
 			cin>>n;
 			for(int i=0;i<n;i++)
 			{
 				cout<<"\n\t\tEnter Student "<<i+1<<" details";
 				cout<<"\n\tEnter Name : ";
 				fflush(stdin);					//to clear out standard inputs
 				gets(name[i]);
 				cout<<"\tEnter registration id : ";
 				cin>>id[i];
 				cout<<"\tEnter phone number : ";
 				cin>>phno[i];
 				cout<<"\tEnter Age : ";
	 			cin>>age[i];
	 			cout<<"\tEnter roll no :";
	 			cin>>rollno[i];
			}
		}
}stud;
//====================================================================================
	//    FUNCTION TO DELETE A RECORD
void deletefile()
{
	char ch;
	do
	{
		cout<<"\n\t****************************** Welcome to delete records **********************************";
 		char del[40];
		fstream fre;
		fstream fwr;
		int avlid=1;
		cout<<"\nEnter the Section name you want to delete : ";
		cin>>del;
		if (!fre || !fwr)
			cout<<"\nFile does not exists.\n";
 		else
 		{
  			fre.open("Record2.txt", ios::in);
  			fwr.open("TempFile.txt",ios::out);
  			while (fre.read((char *) &stud, sizeof(stud)))
  			{
  				if(strcmp(stud.section,del)==0)
  					avlid=0;
   				if(strcmp(stud.section,del)!=0)
   				{
    				fwr.write((char *) &stud, sizeof(stud));
  				}
  			}
  			if(avlid==1)
 				cout<<"\nSection name not available in record.\n"; 		
  			fre.close();
  			fwr.close();
  			fre.open("Record2.txt",ios::out);
  			fwr.open("TempFile.txt",ios::in);
  			while (fwr.write((char *) &stud, sizeof(stud)))
   				fre.write((char *) &stud, sizeof(stud));
   			if(avlid==0)
  				cout<<"\nRECORD DELETED\n";
  			fre.close();
  			fwr.close();
  			remove("Record2.txt");
  			rename("TempFile.txt","Record2.txt");
 		}
 		cout<<"\nWant to delete more...? (Y/N)  ";
 		cin>>ch;
	}while(ch!='n' && ch!='N');
}
//====================================================================================
	//    FUNCTION TO UPDATE THE RECORD
void update()
{
	cout<<"\n\t****************************** Welcome to Update records **********************************";
	int avl;
	fstream fpt;
	fstream fpo;
	int ch,avlid=1;
	char up[40];
	cout<<"\nEnter Section name to update : ";
	cin>>up;
	if (!fpt || !fpo)
	{
		cout<<"\nFile does not exists.\n";
	}
	else
	{
  		fpo.open("Record2.txt", ios::in);
  		fpt.open("TempFile.txt", ios::out);
  		while (fpo.read((char *) &stud, sizeof(stud)))
  		{
  			if(strcmp(stud.section,up)==0)
  				avlid=0;
   			if(strcmp(stud.section,up)!=0)
    			fpt.write((char *) &stud, sizeof(stud));
			else
  			{
  				do
				{
  					cout<<"\n\t\tPress 1 to Update Section Name.";
    				cout<<"\n\t\tPress 2 to Update Section Mentor.";
					cout<<"\n\t\tPress 3 to Update Section HOD.";
					cout<<"\n\t\tPress 4 to Update Placement Mentor.";
					cout<<"\n\t\tPress 5 to Update Class Representive.";
					cout<<"\n\t\tPress 6 to Update E-Cell Coordinator."; 
					cout<<"\n\t\tPress 7 to Update Placement Coordinator.";
					cout<<"\n\t\tPress 8 to Update all the details of section.";
    				cout<<"\n\t\tPress 0 to exit.";
    				cout<<"\n\t**********************************************************************************************\n";
					cout<<"\nEnter your choice : ";
    				cin>>ch;
    				switch (ch)
    				{	
    					case 1:
    						{
	   							cout<<"Enter new Section name : ";
    							fflush(stdin);					//to clear out standard inputs
    							gets(stud.section);
    							cout<<"\nRECORD UPDATED";
    						}
    					break;
    					case 2:
    						{
    							cout<<"Enter new Section Mentor : ";
    							fflush(stdin);					//to clear out standard inputs
     							gets(stud.secment);
    							cout<<"Enter UID no : ";
    							cin>>stud.secmentuid;
    							cout<<"\nRECORD UPDATED";
    						}
 	   					break;
    					case 3:
    						{
    							cout<<"Enter new Section HOD : ";
    							fflush(stdin);					//to clear out standard inputs
    							gets(stud.sechod);
    							cout<<"Enter UID no : ";
    							cin>>stud.sechoduid;
    							cout<<"\nRECORD UPDATED";
							}
     					break;
     					case 4:
     						{
     							cout<<"Enter new Placement Mentor : ";
     							fflush(stdin);					//to clear out standard inputs
  	   							gets(stud.placement);
     							cout<<"Enter UID no : ";
    	 						cin>>stud.placementuid;
    	 						cout<<"\nRECORD UPDATED";
							}
     					break;
     					case 5:
     						{
     							cout<<"Enter new Class Representative : ";
     							fflush(stdin);					//to clear out standard inputs
   	  							gets(stud.cr);
   	  							cout<<"\nRECORD UPDATED";
							}
						break;
						case 6:
							{
								cout<<"Enter new Ecell Coordinator : ";
     							fflush(stdin);					//to clear out standard inputs
     							gets(stud.ecell);
     							cout<<"Enter UID no : ";
     							cin>>stud.ecelluid;	
     							cout<<"\nRECORD UPDATED";
							}
						break;
						case 7:
							{
								cout<<"Enter new Placement Coordinator : ";
     							fflush(stdin);					//to clear out standard inputs
     							gets(stud.placecoor);
     							cout<<"Enter UID no : ";
     							cin>>stud.placecooruid;	
     							cout<<"\nRECORD UPDATED";
							}
						break;
						case 8:
    						{
     							cout<<"\n\t--->Enter new Section name : ";
 								fflush(stdin);					//to clear out standard inputs
 								gets(stud.section);
								cout<<"Enter new Section Mentor : ";
								fflush(stdin);					//to clear out standard inputs 			
								gets(stud.secment);
								cout<<"Enter new uid no : ";
								cin>>stud.secmentuid;
 								cout<<"\nEnter new Section HOD : ";
								fflush(stdin);					//to clear out standard inputs 			
								gets(stud.sechod);
								cout<<"Enter new uid no : ";
								cin>>stud.sechoduid;
 								cout<<"\nEnter new Placement Mentor : ";
								fflush(stdin);					//to clear out standard inputs 			
								gets(stud.placement);
								cout<<"Enter new uid no : ";
								cin>>stud.placementuid;
					 			cout<<"\nEnter new Class Representive : ";
								fflush(stdin);					//to clear out standard inputs
					 			gets(stud.cr);
 								cout<<"\nEnter new E-Cell Coordinator : ";
								fflush(stdin);					//to clear out standard inputs
 								gets(stud.ecell); 
 								cout<<"Enter new uid no : ";
 								cin>>stud.ecelluid;
 								cout<<"\nEnter new Placement Coordinator : ";
								fflush(stdin);					//to clear out standard inputs
 								gets(stud.placecoor);
 								cout<<"Enter new uid no : ";
 								cin>>stud.placecooruid;
 								cout<<"\nEnter new total no of students : ";
 								cin>>stud.n;
 								cout<<endl;
 								for(int i=0;i<stud.n;i++)
 								{
 									cout<<"\n\t\tEnter Student "<<i+1<<" details";
 									cout<<"\n\tEnter new Name : ";
 									fflush(stdin);					//to clear out standard inputs
			 						gets(stud.name[i]);
 									cout<<"\tEnter new registration id : ";
 									cin>>stud.id[i];
					 				cout<<"\tEnter new phone number : ";
 									cin>>stud.phno[i];
 									cout<<"\tEnter new Age : ";
	 								cin>>stud.age[i];
	 								cout<<"\tEnter new roll no : ";
	 								cin>>stud.rollno[i];
								}
								cout<<"\nRECORD UPDATED";
	 						}
   	 					break;
    					case 0:
    						cout<<"\nThank you.";
    					break;
    					default:
     						cout<<"\nWrong choice";
    						break;
    				}
    			}while(ch!=0);
    			fpt.write((char *) &stud, sizeof(stud));
   			}
  		}
  	}
  	if(avlid==1)
  		cout<<"\nSection name not found in record.";
  	fpo.close();
  	fpt.close();
  	fpo.open("Record2.txt", ios::out);
  	fpt.open("TempFile.txt", ios::in);
  	while (fpt.read((char *) &stud, sizeof(stud)))
  	{
  		fpo.write((char *) &stud, sizeof(stud));
  	}
  	fpo.close();
  	fpt.close();
  	remove("Record2.txt");
  	rename("TempFile.txt","Record2.txt");
}
//====================================================================================
	//    FUNCTION TO DISPLAY Records
void display()
{
	int choice;
	do
  	{
       	cout<<"\n\t******************************** Welcome to display records **********************************";
       	cout<<"\n\t\t\tPress 1 to display all the details of every sections.";
       	cout<<"\n\t\t\tPress 2 to display details of any particular section.";
		cout<<"\n\t\t\tPress 3 to display all Section Mentors.";
		cout<<"\n\t\t\tPress 4 to display all Section HODs.";
		cout<<"\n\t\t\tPress 5 to display all Placement Mentors.";
		cout<<"\n\t\t\tPress 6 to display all Class Representives.";
		cout<<"\n\t\t\tPress 7 to display all E-Cell Coordinators."; 
		cout<<"\n\t\t\tPress 8 to display all Placement Coordinators.";
		cout<<"\n\t\t\tPress 0 to exit.";
		cout<<"\n\t**********************************************************************************************\n";
		cout<<"\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					int j=0;
					ifstream fp;
 					fp.open("Record2.txt",ios::in);
   					if (!fp)
    					cout<<"\nFile does not exits.\n";
   					else
   					{
 						ifstream fp1;
  						fp1.open("Record2.txt",ios::in);
 						while (fp1.read((char *)&stud,sizeof(stud)))
 						{
    						cout<<"\n\t******************** DETAILS OF SECTION "<<j+1<<" ********************\n";
							cout<<"\n\t\t\t---> Section name : "<<stud.section<<" <---";
 							cout<<"\nSection Mentor : "<<stud.secment;
 							cout<<"\nUid no : "<<stud.secmentuid;
 							cout<<"\n\nSection HOD : "<<stud.sechod;
 							cout<<"\nUid no : "<<stud.sechoduid;
 							cout<<"\n\nPlacement Mentor : "<<stud.placement;
 							cout<<"\nUid no : "<<stud.placementuid;
 							cout<<"\n\nClass Representive : "<<stud.cr;
 							cout<<"\nE-Cell Coordinator : "<<stud.ecell;
							cout<<"\nUid no : "<<stud.ecelluid; 
 							cout<<"\n\nPlacement Coordinator : "<<stud.placecoor;
 							cout<<"\nUid no : "<<stud.placecooruid;
 							cout<<"\n\nTotal no of students : "<<stud.n;
 							cout<<"\n";
 							for(int i=0;i<stud.n;i++)
 							{
 								cout<<"\n\tStudent Name : ";
 								puts(stud.name[i]);
 								cout<<"\tRegistration id : "<<stud.id[i];
 								cout<<"\n\tPhone number : "<<stud.phno[i];
 								cout<<"\n\tAge : "<<stud.age[i];
	 							cout<<"\n\tRoll no : "<<stud.rollno[i]<<"\n";
							}
    						j++;
    					}
    					fp1.close();
    				}
    				fp.close();
    			}
    		break;
    		case 2:
    			{
    				char sec[20];
    				int avlid=1;
    				ifstream p;
    				cout<<"\nEnter the Section name : ";
    				cin>>sec;
					p.open("Record2.txt",ios::in);	
					if (!p)
    					cout<<"\nFile does not exits.\n";
					else
					{
						while ( p.read((char *) &stud, sizeof(stud)))
						{
  							if (strcmp(stud.section,sec)==0)
   							{
   								avlid=0;
	   							cout<<"\n\t******************** DETAILS OF SECTION ********************\n";
								cout<<"\n\t\t\t---> Section name : "<<stud.section<<" <---";
 								cout<<"\nSection Mentor : "<<stud.secment;
 								cout<<"\nUid no : "<<stud.secmentuid;
 								cout<<"\n\nSection HOD : "<<stud.sechod;
 								cout<<"\nUid no : "<<stud.sechoduid;
 								cout<<"\n\nPlacement Mentor : "<<stud.placement;
 								cout<<"\nUid no : "<<stud.placementuid;
					 			cout<<"\n\nClass Representive : "<<stud.cr;
					 			cout<<"\nE-Cell Coordinator : "<<stud.ecell;
								cout<<"\nUid no : "<<stud.ecelluid; 
 								cout<<"\n\nPlacement Coordinator : "<<stud.placecoor;
					 			cout<<"\nUid no : "<<stud.placecooruid;
 								cout<<"\n\nTotal no of students : "<<stud.n;
 								for(int i=0;i<stud.n;i++)
 								{				
 									cout<<"\n\tStudent Name : ";
 									puts(stud.name[i]);
 									cout<<"\tRegistration id : "<<stud.id[i];
 									cout<<"\n\tPhone number : "<<stud.phno[i];		
 									cout<<"\n\tAge : "<<stud.age[i];
						 			cout<<"\n\tRoll no : "<<stud.rollno[i]<<"\n";
								}
  							}
						}
					if(avlid==1)
					cout<<"\nSection name not found in record.\n";
					}
				}
			break;
    		case 3:
    			{
    				ifstream fp1;
  					fp1.open("Record2.txt",ios::in);
  					if (!fp1)
    					cout<<"\nFile does not exits.\n";
    				else
    				{
 						while ( fp1.read((char *)&stud,sizeof(stud)))
 						{
 							cout<<"\n\t\t\t---> Section name : "<<stud.section<<" <---";
 							cout<<"\nSection Mentor : "<<stud.secment;
 							cout<<"\nUid no : "<<stud.secmentuid;
 						}
    					fp1.close();
					}
				}
			break;
			case 4:
				{
					ifstream fp1;
  					fp1.open("Record2.txt",ios::in);
  					if (!fp1)
    					cout<<"\nFile does not exits.\n";
    				else
    				{
 						while ( fp1.read((char *)&stud,sizeof(stud)))
 						{
 							cout<<"\n\t\t\t---> Section name : "<<stud.section<<" <---";
 							cout<<"\n\nSection HOD : "<<stud.sechod;
 							cout<<"\nUid no : "<<stud.sechoduid;
 						}
 	   					fp1.close();
					}
				}
			break;
			case 5:
				{
					ifstream fp1;
  					fp1.open("Record2.txt",ios::in);
  					if (!fp1)
    					cout<<"\nFile does not exits.\n";
 					else
					{
						while ( fp1.read((char *)&stud,sizeof(stud)))
	 					{
 							cout<<"\n\t\t\t---> Section name : "<<stud.section<<" <---";
							cout<<"\n\nPlacement Mentor : "<<stud.placement;
 							cout<<"\nUid no : "<<stud.placementuid;
 						}
    					fp1.close();
					}
				}
			break;
			case 6:
				{
					ifstream fp1;
  					fp1.open("Record2.txt",ios::in);
  					if (!fp1)
    					cout<<"\nFile does not exits.\n";
 					else
					{
						while ( fp1.read((char *)&stud,sizeof(stud)))
 						{
 							cout<<"\n\t\t\t---> Section name : "<<stud.section<<" <---";
				 			cout<<"\n\nClass Representive : "<<stud.cr;
 						}
 	   				fp1.close();	
					}
				}
			break;
			case 7:
				{
					ifstream fp1;
  					fp1.open("Record2.txt",ios::in);
 					if (!fp1)
    					cout<<"\nFile does not exits.\n";
					else
					{
						while ( fp1.read((char *)&stud,sizeof(stud)))
 						{
 							cout<<"\n\t\t\t---> Section name : "<<stud.section<<" <---";
				 			cout<<"\nE-Cell Coordinator : "<<stud.ecell;
							cout<<"\nUid no : "<<stud.ecelluid; 
 						}
    				fp1.close();
					}
				}
			break;
			case 8:
				{
					ifstream fp1;
  					fp1.open("Record2.txt",ios::in);
 					if (!fp1)
    					cout<<"\nFile does not exits.\n";
					else
					{
						while ( fp1.read((char *)&stud,sizeof(stud)))
	 					{
 								cout<<"\n\t\t\t---> Section name : "<<stud.section<<" <---";
 								cout<<"\n\nPlacement Coordinator : "<<stud.placecoor;
					 			cout<<"\nUid no : "<<stud.placecooruid;
  						}
    				fp1.close();
					}
				}
			break;
			case 0:
					cout<<"\nTHANK YOU.";
			break;
			default:
					cout<<"\nSorry wrong choice.";
			break;
		}
   	}while(choice!=0);
}
//====================================================================================
	//    FUNCTION TO SEARCH Records
void search()
{
	int n;
	do
  	{
  		cout<<"\n\t******************************** Welcome to search records ***********************************";
  		cout<<"\n\t\t\tPress 1 to search for Section Mentor.";
		cout<<"\n\t\t\tPress 2 to search for Section HOD.";
		cout<<"\n\t\t\tPress 3 to search for Placement Mentor.";
		cout<<"\n\t\t\tPress 4 to search for Class Representive.";
		cout<<"\n\t\t\tPress 5 to search for E-Cell Coordinator."; 
		cout<<"\n\t\t\tPress 6 to search for Placement Coordinator.";
		cout<<"\n\t\t\tPress 7 to search a student.";
		cout<<"\n\t\t\tPress 0 to exit.";
		cout<<"\n\t**********************************************************************************************\n";
		cout<<"\nEnter your choice : ";
		cin>>n;
		switch (n)
		{
			case 1:
				{
					ifstream fp2;
					int avlid=1;
					char secmen[50];
					cout<<"\nEnter the Section Mentor's name to search : ";
 					cin>>secmen;
  					fp2.open("Record2.txt",ios::in);
  					if (!fp2)
    					cout<<"\nFile does not exits.\n";
  					else
					{
						while (fp2.read((char *)&stud,sizeof(stud)))
  						{
  							if (strcmp(stud.secment,secmen)==0)
   							{
   								avlid=0;
   								cout<<"\n\t******************** DETAILS OF SECTION ********************\n";
								cout<<"\n\t\t\t---> Section name : "<<stud.section<<" <---";
 								cout<<"\nSection Mentor : "<<stud.secment;
 								cout<<"\nUid no : "<<stud.secmentuid;
 								cout<<"\n\nSection HOD : "<<stud.sechod;
 								cout<<"\nUid no : "<<stud.sechoduid;
 								cout<<"\n\nPlacement Mentor : "<<stud.placement;
 								cout<<"\nUid no : "<<stud.placementuid;
					 			cout<<"\n\nClass Representive : "<<stud.cr;
					 			cout<<"\nE-Cell Coordinator : "<<stud.ecell;
								cout<<"\nUid no : "<<stud.ecelluid; 
 								cout<<"\n\nPlacement Coordinator : "<<stud.placecoor;
					 			cout<<"\nUid no : "<<stud.placecooruid;
 								cout<<"\n\nTotal no of students : "<<stud.n<<endl;
  							}
  						}//while loop closed
  					}
  					if (avlid == 1)
 	 	 				cout<<"\nSection Mentor's name is not available in the record.\n";
 					fp2.close();
 				} 
 			break;
 			case 2:
 				{
 					ifstream fp2;
					int avlid=1;
					char secmen[50];
					cout<<"\nEnter the Section HOD's name to search : ";
 					cin>>secmen;
  					fp2.open("Record2.txt",ios::in);
  					if (!fp2)
    					cout<<"\nFile does not exits.\n";
					else
					{
						while (fp2.read((char *)&stud,sizeof(stud)))
  						{
 	 						if (strcmp(stud.sechod,secmen)==0)
   							{
   								avlid=0;
   								cout<<"\n\t******************** DETAILS OF SECTION ********************\n";
								cout<<"\n\t\t\t---> Section name : "<<stud.section<<" <---";
 								cout<<"\nSection Mentor : "<<stud.secment;
 								cout<<"\nUid no : "<<stud.secmentuid;
 								cout<<"\n\nSection HOD : "<<stud.sechod;
 								cout<<"\nUid no : "<<stud.sechoduid;
 								cout<<"\n\nPlacement Mentor : "<<stud.placement;
 								cout<<"\nUid no : "<<stud.placementuid;
					 			cout<<"\n\nClass Representive : "<<stud.cr;
					 			cout<<"\nE-Cell Coordinator : "<<stud.ecell;
								cout<<"\nUid no : "<<stud.ecelluid; 
 								cout<<"\n\nPlacement Coordinator : "<<stud.placecoor;
					 			cout<<"\nUid no : "<<stud.placecooruid;
 								cout<<"\n\nTotal no of students : "<<stud.n<<endl;
	  						}
  						}//while loop closed
  					}
  					if (avlid == 1)
 	 	 				cout<<"\nSection HOD's name is not available in the record.\n";
 		   			fp2.close();
 				} 
 			break;
 			case 3:
 				{
 					ifstream fp2;
					int avlid=1;
					char secmen[50];
					cout<<"\nEnter the Placement Mentor's name to search : ";
 					cin>>secmen;
  					fp2.open("Record2.txt",ios::in);
	  				if (!fp2)
    					cout<<"\nFile does not exits.\n";
					else
					{
						while (fp2.read((char *)&stud,sizeof(stud)))
  						{
  							if (strcmp(stud.placement,secmen)==0)
   							{
   								avlid=0;
   								cout<<"\n\t******************** DETAILS OF SECTION ********************\n";
								cout<<"\n\t\t\t---> Section name : "<<stud.section<<" <---";
 								cout<<"\nSection Mentor : "<<stud.secment;
 								cout<<"\nUid no : "<<stud.secmentuid;
 								cout<<"\n\nSection HOD : "<<stud.sechod;
 								cout<<"\nUid no : "<<stud.sechoduid;
 								cout<<"\n\nPlacement Mentor : "<<stud.placement;
 								cout<<"\nUid no : "<<stud.placementuid;
					 			cout<<"\n\nClass Representive : "<<stud.cr;
					 			cout<<"\nE-Cell Coordinator : "<<stud.ecell;
								cout<<"\nUid no : "<<stud.ecelluid; 
 								cout<<"\n\nPlacement Coordinator : "<<stud.placecoor;
					 			cout<<"\nUid no : "<<stud.placecooruid;
 								cout<<"\n\nTotal no of students : "<<stud.n<<endl;
  							}
  						}//while loop closed
  					}
  					
  					if (avlid == 1)
 	 					cout<<"\nPlacement Mentor's name is not available in the record.\n";
 					fp2.close();
 				}
			break;
 			case 4:
 				{
 					ifstream fp2;
					int avlid=1;
					char secmen[50];
					cout<<"\nEnter the Class Representative's name to search : ";
 					cin>>secmen;
  					fp2.open("Record2.txt",ios::in);
  					if (!fp2)
    					cout<<"\nFile does not exits.\n";
					else
					{
						while (fp2.read((char *)&stud,sizeof(stud)))
  						{
  							if (strcmp(stud.cr,secmen)==0)
  	 						{
   								avlid=0;
   								cout<<"\n\t\t\t\t*************** Details of Section ****************";
								cout<<"\n\t******************** DETAILS OF SECTION ********************\n";
								cout<<"\n\t\t\t---> Section name : "<<stud.section<<" <---";
 								cout<<"\nSection Mentor : "<<stud.secment;
 								cout<<"\nUid no : "<<stud.secmentuid;
 								cout<<"\n\nSection HOD : "<<stud.sechod;
 								cout<<"\nUid no : "<<stud.sechoduid;
 								cout<<"\n\nPlacement Mentor : "<<stud.placement;
 								cout<<"\nUid no : "<<stud.placementuid;
					 			cout<<"\n\nClass Representive : "<<stud.cr;
					 			cout<<"\nE-Cell Coordinator : "<<stud.ecell;
								cout<<"\nUid no : "<<stud.ecelluid; 
 								cout<<"\n\nPlacement Coordinator : "<<stud.placecoor;
					 			cout<<"\nUid no : "<<stud.placecooruid;
 								cout<<"\n\nTotal no of students : "<<stud.n<<endl;
  							}
  						}//while loop closed
  					}
  					if (avlid == 1)
 	 		 			cout<<"\nClass Representative's name is not available in the record.\n";
 			   		fp2.close();
 				} 
			break;
			case 5:
				{
					ifstream fp2;
					int avlid=1;
					char secmen[50];
					cout<<"\nEnter the E-Cell Coordinator's name to search : ";
 					cin>>secmen;
  					fp2.open("Record2.txt",ios::in);
  					if (!fp2)
    					cout<<"\nFile does not exits.\n";
					else
					{
						while (fp2.read((char *)&stud,sizeof(stud)))
 						{
  							if (strcmp(stud.ecell,secmen)==0)
   							{
   								avlid=0;
   								cout<<"\n\t******************** DETAILS OF SECTION ********************\n";
								cout<<"\n\t\t\t---> Section name : "<<stud.section<<" <---";
 								cout<<"\nSection Mentor : "<<stud.secment;
 								cout<<"\nUid no : "<<stud.secmentuid;
 								cout<<"\n\nSection HOD : "<<stud.sechod;
 								cout<<"\nUid no : "<<stud.sechoduid;
 								cout<<"\n\nPlacement Mentor : "<<stud.placement;
 								cout<<"\nUid no : "<<stud.placementuid;
					 			cout<<"\n\nClass Representive : "<<stud.cr;
					 			cout<<"\nE-Cell Coordinator : "<<stud.ecell;
								cout<<"\nUid no : "<<stud.ecelluid; 
 								cout<<"\n\nPlacement Coordinator : "<<stud.placecoor;
					 			cout<<"\nUid no	: "<<stud.placecooruid;
 								cout<<"\n\nTotal no of students	: "<<stud.n<<endl;
  							}	
  						}//while loop closed
  					}//else part
  					if (avlid == 1)
 	 					cout<<"\nE-Cell Coordinator's name is not available in the record.\n";
 	   				fp2.close();
 				} 
			break;
 			case 6:
 				{
 					ifstream fp2;
					int avlid=1;
					char secmen[50];
					cout<<"\nEnter the Placement Coordinator's name to search : ";
 					cin>>secmen;
  					fp2.open("Record2.txt",ios::in);
  					if(!fp2)
  						cout<<"\nFile does not exist.\n";
  					else
					{
						while (fp2.read((char *)&stud,sizeof(stud)))
 						{
  							if (strcmp(stud.placecoor,secmen)==0)
   							{
   								avlid=0;
   								cout<<"\n\t******************** DETAILS OF SECTION ********************\n";
								cout<<"\n\t\t\t---> Section name : "<<stud.section<<" <---";
 								cout<<"\nSection Mentor : "<<stud.secment;
 								cout<<"\nUid no : "<<stud.secmentuid;
 								cout<<"\n\nSection HOD : "<<stud.sechod;
 								cout<<"\nUid no : "<<stud.sechoduid;
 								cout<<"\n\nPlacement Mentor : "<<stud.placement;
 								cout<<"\nUid no : "<<stud.placementuid;
					 			cout<<"\n\nClass Representive : "<<stud.cr;
					 			cout<<"\nE-Cell Coordinator : "<<stud.ecell;
								cout<<"\nUid no : "<<stud.ecelluid; 
 								cout<<"\n\nPlacement Coordinator : "<<stud.placecoor;
					 			cout<<"\nUid no : "<<stud.placecooruid;
 								cout<<"\n\nTotal no of students : "<<stud.n<<endl;
  							}
  						}//while loop closed
  					}//else part
  					if (avlid == 1)
 	 	 				cout<<"\nPlacement Coordinator's name is not available in the record.\n";
 		 	  		fp2.close();
				}
 			break;
 			case 7:
 				{
 					int id,avlid=1;
 					ifstream p;
 					p.open("Record2.txt",ios::in);
 					cout<<"\nEnter student registration id : ";
 					cin>>id;
 					if(!p)
 						cout<<"\nFile does not exists.";
 					else
 					{
 						while(p.read((char *)&stud,sizeof(stud)))
 						{
 							for(int i=0;i<stud.n;i++)
 							{
 								if(id==stud.id[i])
 								{
 									avlid=0;
 									cout<<"\nDETAILS OF STUDENT";
 									cout<<"\n\t\t---> Section name : "<<stud.section;
 									cout<<"\n\tName : ";
 									puts(stud.name[i]);
 									cout<<"\nRegistration id : "<<stud.id[i];
 									cout<<"\n\tPhone number : "<<stud.phno[i];
 									cout<<"\n\tAge : "<<stud.age[i];
	 								cout<<"\n\tRoll no :"<<stud.rollno[i];
								}
							}//for loop closed
						}//while loop closed
					}//else part
					if (avlid == 1)
 	 	 				cout<<"\nStudent registration id is not available in record.\n";
 		   			p.close();
				}
			break;
			case 0:
				cout<<"\nTHANK YOU.";
			break;
			default:
				cout<<"\nWRONG CHOICE.";
			break;
		}
	}while(n!=0);
}
//====================================================================================
	// MAIN PROGRAM
main()
{
	system("color 0E");
	char user1[50]="akash123",pass1[]="password";
	char user[20],pass[9];
	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t   Enter username : ";
	cin>>user;
	cout<<"\n\t\t\t\t\t   Enter password : ";
	for(int i=0;i<8;i++)
	{
		pass[i]=getch();
		cout<<"*";
	}
	if(strcmp(pass1,pass)==0 && strcmp(user1,user)==0)
	{
 		int c, emp,n;
 		do
 		{	
 			system("cls");
		 	cout<<"\n\n\n\t\t\t\t  ----------------- LPU Finder ----------------\n";
			cout<<"\t\t\t\t  _______________ By: Akash Kumar _____________\n";
			cout<<"\t\t\t\t  _________________ 11702349 __________________\n";
			cout<<"\t\t\t\t  ___________________ K17DQ ___________________\n";
			cout<<"\t\t\t\t  _______ Lovely Professional University ______\n";
			cout<<"\t\t\t\t  ---------------------------------------------";
			cout<<"\n\tPress Enter to continue...";
  			getche();	
			system("cls");										//Menu driven program
 			cout<<"\n\n\n\t\t\t\t\t\tDate :"<<__DATE__;
  			cout<<"\n\t\t\t\t\t\tTime :"<<__TIME__;
  			cout<<"\n\n\t************************************  Welcome to LPU Finder  *********************************";
  			cout<<"\n\t\t\tPress 1 to Add Record";
			cout<<"\n\t\t\tPress 2 to Display Record";
			cout<<"\n\t\t\tPress 3 to Search Record";
			cout<<"\n\t\t\tPress 4 to Delete Record";
			cout<<"\n\t\t\tPress 5 to Update Record";
			cout<<"\n\t\t\tPress 0 to Exit";
  			cout<<"\n\t**********************************************************************************************\n";
  			cout<<"\nEnter your choice : ";
  			cin>>c;
  			cout<<"\n";
  			switch (c)
  			{
  			case 1:
  			{
   				ofstream fp;
   				fp.open("Record2.txt", ios::app);
   				if(!fp)
   					cout<<"\nFile does not exits.";
   				else
   				{
 					stud.insert();
  	 				fp.write((char *) &stud, sizeof(stud));
   					fp.close();
   				}
   			}
   			break;
  			case 2:
  				display();
  	 		break;
  			case 3:
  				search();
	   	 	break;
			case 4:
   				deletefile();
   			break;
  	  		case 5:
   				update();
   			break;
  			case 0:
   				{
					cout<<"\n\n\t\tClosing...........";
					cout<<"\n\t\t\t\t\t\t............Closing\n";
					cout<<"\n\t\t\t\t*************** THANK YOU ***************\n";
				}	
   			break;
  			default:
 	  			cout<<"\n**************** Your choice is wrong ****************\nPlease try again...\n";
   			break;
  			}
 		}while (c != 0);
	}
	else if(strcmp(pass1,pass)!=0 || strcmp(user1,user)!=0)
		cout<<"\n\n\t\tSorry wrong username or password.";
	getch();
}
