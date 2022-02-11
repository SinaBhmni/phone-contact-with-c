#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#define max 30
#define numbers 100
void eexit();
int choice,count=0;
struct contact{
	char fname[max],lname[max],number[max];
	int id;
}info[numbers];
char search1[30];
void main_menu();
void list();
void add();
void edit();
void del();
void search();
int i;
main(){
	main_menu();
}
void main_menu(){				//MAIN MENU
	system("cls");
	printf("======================================================================================\n");
	printf("\n\t\t\t\t  User Menu\n\n");
	printf("..::please choose your command and prees Enter key\n\n");
	printf("\t 1 . Contacts List\n");
	printf("\t 2 . Add New Contact\n");
	printf("\t 3 . Edit a Contact\n");
	printf("\t 4 . Delete a Contact\n");
	printf("\t 5 . Search a contact by number\n");
	printf("\t 6 . Exit\n");
	printf("\n\n======================================================================================\n");
	int choice;
	scanf("%d",&choice);
	switch(choice){
		case 1:{				//list of contact
			list();
			break;
		}
		case 2:{				//add new contact
			add();
			break;
		}
		case 3:{				//edit contact
			edit();
			break;
		}
		case 4:{				//delete
			del();
			break;
		}
		case 5:{				//search
		 	search();
			break;
		}
		case 6:{
			exit(0);			//
			break;
		}
	}	
}
void list(){					//LIST OF CONTACT
	system("cls");
	printf("..::Contacts List\n");
	printf("\n\n======================================================================================\n");
	printf("   %-30s%-30s%-12s\n","First name","Last name","Number");
	printf("____________________________________________________________________________\n");
	for(i=1;i<=numbers;i++){
		if(info[i].id!=0){
			printf("  %-30s%-30s%-12s\n",info[i].fname,info[i].lname,info[i].number);			
		}
	}
	eexit();
}
void add(){						//ADD NEW CONTACT
	system("cls");
	printf("..::Add New Contact\n");
	printf("\n\n======================================================================================\n");
	count++;
	info[count].id=count;		
	printf("Please Enter First name   :  ");
	scanf("%s",&info[count].fname);
	printf("\nPlease Enter Last name    :  ");
	scanf("%s",&info[count].lname);
	printf("\nPlease Enter phone number :  ");
	scanf("%s",&info[count].number);
	printf("first name \tlast name  \tnumber      ");
	printf("\n___________________________________________");
	printf("\n%-16s%-16s%-16s",info[count].fname,info[count].lname,info[count].number);
	printf("\n\n\n\tYour contact  is saved\n\n");
	eexit();
}
void edit(){					//EDIT CONTACT
	system("cls");
	printf("..::Edit a Contact\n");
	printf("\n\n======================================================================================\n");
	printf("\t\t*****pleasee slect contact*****\n\t\t  *****Enter contact id***** \n");
	for(i=1;i<=numbers;i++){
		if(info[i].id!=0){
			printf("\n%d _ %s\t%s\t%s\n",i,info[i].fname,info[i].lname,info[i].number);			
		}
	}
	int e_id;
	scanf("%d",&e_id);
	system("cls");
	for(i=1;i<=numbers;i++){
		if(e_id==info[i].id){
			printf("first name : <<%s>>  last name : <<%s>> number : <<%s>>\n",info[i].fname,info[i].lname,info[i].number);
			printf("  select \n  1 . edit first name\n  2 . edit last name\n  3 . edit number\n");
			int j;
			scanf("%d",&j);
			switch(j){
			case 1:{
				printf("Enter new first name :  ");
				scanf("%s",&info[i].fname);
				break;
			}
			case 2:{
				printf("Enter new last name :  ");
				scanf("%s",&info[i].lname);
				break;
			}
			case 3:{
				printf("Enter new number :  ");
				scanf("%s",&info[i].number);
				break;
			}
			}		
			printf("your edit done");
		}	
	}
	eexit();
}
void del(){						//DELETE
system("cls");
	printf("..::delete a Contact\n");
	printf("\n\n======================================================================================\n\n\n");
	printf("%-30s\t%-30s\t%-15s\t%-5s\t\n","First name","Last name","Number","id");
	printf("____________________________________________________________________________________\n\n");		
	for(i=1;i<=numbers;i++){
		if(info[i].id!=0){
			printf("\n%-30s\t%-30s\t%-15s\t%-5d\t\n",info[i].fname,info[i].lname,info[i].number,info[i].id);			
		}
	}
	printf("Enter id : ");
	int d_id;
	scanf("%d",&d_id);
	printf("\n\tAre sure you to delete the contact\n\t\t 1 = yes\n\t\t 2 = no\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:{
			for(i=1;i<=numbers;i++){
				if(info[i].id==d_id){
					info[i].id=0;
				}
			}
			printf("\n\t\tyour contact is delete\n");
			break;
		}
		case 2:{
			break;
		}
	}			
	eexit();
}
void search(){					//SEARCH 
	system("cls");
	printf("\t 1 . search by number\n\t 2 . search by first name\n\t 3 . search by last name\n");
	int choice;
	scanf("%d",&choice);
	switch(choice){
		case 1:{				//Search by number
			printf("Enter number : ");
			scanf("%s",&search1);
			printf("%-30s\t%-30s\t%-15s\t%-5s\t\n","First name","Last name","Number","id");
			printf("____________________________________________________________________________________\n");
			for(i=1;i<=100;i++){
				if(strcmpi(search1,info[i].number)==0){
					printf("\n%-30s\t%-30s\t%-15s\t%-5d\t\n",info[i].fname,info[i].lname,info[i].number,info[i].id);
				}
			}
			break;
		}
		case 2:{				//Search by first name
			printf("Enter first name : ");
			scanf("%s",&search1);
			printf("%-30s\t%-30s\t%-15s\t%-5s\t\n","First name","Last name","Number","id");
			printf("____________________________________________________________________________________\n");
			for(i=1;i<=100;i++){
				if(strcmpi(search1,info[i].fname)==0){
					printf("\n%-30s\t%-30s\t%-15s\t%-5d\t\n",info[i].fname,info[i].lname,info[i].number,info[i].id);
				}
			}
			break;
		}
		case 3:{				//search by last name
			printf("Enter last name : ");
			scanf("%s",&search1);
			printf("%-30s\t%-30s\t%-15s\t%-5s\t\n","First name","Last name","Number","id");
			printf("____________________________________________________________________________________\n");
			for(i=1;i<=100;i++){
				if(strcmpi(search1,info[i].lname)==0){	
					printf("\n%-30s\t%-30s\t%-15s\t%-5d\t\n",info[i].fname,info[i].lname,info[i].number,info[i].id);	
				}
			}
			break;
		}
		}
		eexit();
}
void eexit(){
	printf("\n\n========================================================");
	printf("\n\n\t\t***Enter your choise***\n");
	printf("\n   1 . Main menu\n   2 . Quit\n");
	printf("\n\n========================================================\n\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:{
			system("cls");
			main_menu();	
		}
		case 2:{
			break;
		}
	}	
}
