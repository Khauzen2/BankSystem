#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user {
	char name[50];
	char phone[20];
	char account[50];
	char password[50];
	float balance;
};

int main() {
	struct user usr,usr1, usr2, usr3, usr4;
	strcpy(usr1.name, "Mdeva");
	strcpy(usr2.name, "Thato");
	strcpy(usr3.name, "Thabiso");
	strcpy(usr4.name, "Koroloso");
	FILE *fp;
	char filename[50],phone[50],pword[50],name[50];
	int opt, choice,i, continu;
	char cont = 'y';
	float amount;
	
	for(;;) {
		system("cls");
	    //printf("Name1 is %s\n", usr1.name);
	    printf("Name2 is %s\n", usr2.name);
	    printf("Name3 is %s\n", usr3.name);
	    printf("Name4 is %s\n", usr4.name);
	    
		printf("\n\n\n\t\t\tWhat do you want to do today?\n\n");
		printf("\t\t\t1.Register an Account.\n");
		printf("\t\t\t2.Login to Account.");
		
		printf("\n\n\t\t\tYour choice:\n\t\t\t");
		scanf("%d", &opt);
		
		if(opt == 1) {
			system("cls");
			
			printf("\n\t\t\tEnter your username:\n\t\t\t");
			scanf("%s", usr.name);
			printf("\n\t\t\tEnter your account number:\n\t\t\t");
			scanf("%s", usr.account);
			printf("\n\t\t\tEnter your phone number:\n\t\t\t");
			scanf("%s", usr.phone);
			printf("\n\t\t\tEnter your new password:\n\t\t\t");
			scanf("%s", usr.password);
			usr.balance = 0;
			strcpy(filename,usr.name);
			fp = fopen(strcat(filename,".txt"), "w");
			fwrite(&usr,sizeof(struct user),1,fp);
			if(fwrite != 0) {
				printf("\n\nAccount successfully registered!");
				scanf("%s", &cont);
			}
			else {
				printf("Something whent wrong. Please try again!");
			}
			fclose(fp);
		}
		if(opt == 2)
		{
			system("cls");
			printf("\n\t\t\tUsername:\n\t\t\t");
			scanf("%s", name);
			printf("\n\t\t\tPassword:\n\t\t\t");
			scanf("%s", pword);
			strcpy(filename,name);
			fp = fopen(strcat(filename,".txt"),"r");
			if(fp == NULL)
			{
				printf("\nAccount number not registered\nTry existing account\nPress 1 and hit Enter."); 
				scanf("%d", &opt);
			}
			else 
			{
			
				fread(&usr,sizeof(struct user),1,fp);
				fclose(fp);
				if(!strcmp(pword,usr.password))
				{
					for(;;) {
						
				
					
						while(cont == 'y')
						{
							system("cls");
							printf("\t%s\n",__DATE__);
							printf("\t%s",__TIME__);
							printf("\n\t\t\tWelcome %s\n", name);
							printf("Your balance: R%.2f", usr.balance);
							printf("\n\t\t\tPress 1 for balance enquiry.");
							printf("\n\t\t\tPress 2 for cash deposit.");
							printf("\n\t\t\tPress 3 for cash withdrawal.");
							printf("\n\t\t\tPress 4 for online transfer.");
							printf("\n\t\t\tPress 5 for password change.");
							printf("\n\t\t\tPress 6 for history.");
							printf("\n\t\t\tPress 7 for exit.");
							printf("\n\n\t\t\tYour choice.\n\t\t\t");
							scanf("%d", &choice);
							
							if(choice == 1){
								printf("\n\t\t\tYour current balance is R%.2f",usr.balance);
								break;
							}
							else if(choice == 2) {
									printf("Enter the amount:\t");
									scanf("%f", &amount);
									usr.balance += amount;
									fp = fopen(filename, "w");
									fwrite(&usr,sizeof(struct user),1,fp);
									if(fwrite != NULL) 
									{
										printf("\nSuccessfully Deposited");
									}
									else {
										printf("\n\nNot working mike...fix it!!!");
									}
									fclose(fp);
									break;
							}				
							else if(choice == 3) {
								printf("Enter the amount:\t");
								scanf("%f", &amount);
								usr.balance -= amount;
								fp = fopen(filename, "w");
								fwrite(&usr,sizeof(struct user),1,fp);
								if(fwrite != NULL) 
								{
									printf("\nYou have withdrawn R%.2f", amount);
								}
								else {
									printf("\n\nNot working mike...fix it!!!");
								}
								fclose(fp);
								break;
							}	
							else if(choice == 4) {
								printf("\nPlease enter the username of the you want to send to:\t");
								scanf("%s", name);
								printf("\nPlease enter the amount to transfer\t");
								scanf("%f", &amount);
								strcpy(filename,name);
								fp = fopen(strcat(filename,".txt"),"r");
								if(fp==NULL) {
									printf("\nAccount number not registered\nTry existing account\nPress 1 and hit ENTER"); 
									scanf("%s", &cont);
								} 
								else {
									fread(&usr1,sizeof(struct user),1,fp);
									fclose(fp);
								
									if(amount > usr.balance) 
									{
									
									printf("\nInsufficient balance"); 
									getch();
									}
									else {
										fp = fopen(filename,"w");
										usr1.balance += amount;
										fwrite(&usr1,sizeof(struct user),1,fp);
										fclose(fp);
										if(fwrite != NULL){
											printf("\nYou have successfully transfered R%.2f to %s", amount, name);
											strcpy(filename,usr.name);
											fp = fopen(strcat(filename,".txt"),"w");
											usr.balance -= amount;
											fwrite(&usr,sizeof(struct user),1,fp);
											fread(&usr1,sizeof(struct user),1,fp);
											fclose(fp);
											break;
											/*if(amount > usr.balance) printf("\nInsufficient balance");
											else {
												strcpy(filename,phone);
										
												fp = fopen(filename,"w");
												usr1.balance += amount;
												fwrite(&usr1,sizeof(struct user),1,fp);
												fclose(fp);
												if(fwrite != NULL){
													printf("\nYou have successfully transfered R%.2f to %s", amount, name);
													strcpy(filename,usr.name);
													fp = fopen(strcat(filename,".txt"),"w");
													usr.balance -= amount;
													fwrite(&usr,sizeof(struct user),1,fp);
													fclose(fp);
													break;
												}*/
											}
										}
									}
								}
								else if(choice == 5)
								{
									printf("Enter new password");
									scanf("%s", pword);
									fp = fopen(filename, "w");
									strcpy(usr.password,pword);
									fwrite(&usr,sizeof(struct user),1,fp);
									if(fwrite != NULL)
									printf("Password successfully changed!!!\n");
									printf("Do you want to continue? Y = Yes/ N = No.");
									scanf("%s", &cont);
									fclose(fp);
								}
								else if(choice == 6)
								{
									system("cls");
									printf("Your history is as follows\n\n");
									printf("Username: %s\n", usr.name);
									printf("Phone number: %s\n", usr.phone);
									printf("Transections: %f\n", amount);
									printf("Time and Date: %s, %s\n", __DATE__, __TIME__);
									getch();
								}
								else if(choice == 7)
								{
									printf("Thank you for showing interest in our banking system...Till next time!!!");
									exit(1);
								}
								else {
									printf("Inavild input!!");
									scanf("%s", &cont);
								}
						}
						printf("\n\t\t\tDo you want to continue with the transection? [Y/N]\n\t\t\t");
						scanf("%s", &cont);	
						if(cont != 'y') {
							exit(0);
						}
					}
								
				} else {
					printf("\nInvalid password!!");
					scanf("%d", &continu);
					getch();
				}
			} 
		}
		else
		{
			printf("Invalid input please try again!");
			scanf("%d", &continu);
			getch();
		}
	}
	return 0;
}
	
	
