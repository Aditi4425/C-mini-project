#include<stdio.h>
#include<string.h>

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();
const char *ACCOUNT_FILE = "account.dat";

typedef struct
{
	char name[50];
	int acc_no;
	float balance;
}Account;
int main()
{
	while(1)
	{
		int choice;
		printf("\n**********Welcome to bank management system**********");
		printf("\n1. Create Account");
		printf("\n2. Deposit Money");
		printf("\n3. Withdraw Money");
		printf("\n4. Check Balance");
		printf("\n5. Exit");
		printf("\n Enter your choice : ");
		scanf("%d",&choice);
		if(choice==1)
		{
			create_account();
		}
		else if(choice==2)
		{
			deposit_money();
		}
		else if(choice==3)
		{
			withdraw_money();
		}
		else if(choice==4)
		{
			check_balance();
		}
		else if(choice==5)
		{
			break;
		}
		else
		{
			printf("Enter correct value");
		}
	}
		return 0;
}
	void create_account()
	{
		Account acc;
		FILE *file= fopen(ACCOUNT_FILE,"ab+");
		if (file==NULL)
		{
			printf("\n unable to open file!");
			return;
		}
		char c;
		do
		{
			c=getchar();
		}
		while(c != '\n'&& c != EOF);
		printf("\nEnter your name=");
		fgets(acc.name, sizeof(acc.name), stdin);
		int ind= strcspn(acc.name,"\n");
		acc.name[ind] ='\0';
		printf("\nEnter your account number:");
		scanf("%d",&acc.acc_no);
		acc.balance = 0;
		
		fwrite(&acc,sizeof(acc),1,file);
		fclose(file);
		printf("\nAccount created seccessfully");
	}
	void deposit_money()
	{
			FILE *file = fopen(ACCOUNT_FILE,"rb+");
			if (file == NULL)
			{
				printf("Unable to open account file!");
				return;
			}
			int acc_no;
			float money;
			Account acc_r;
			printf("Enter your account number: ");
			scanf("%d",&acc_no);
			printf("Enter amount to deposit: ");
			scanf("%f",&money);
			
			while(fread(&acc_r,sizeof(acc_r),1,file))
			{
				if(acc_r.acc_no == acc_no)
				{
					acc_r.balance +=money;
					fseek(file,-sizeof(acc_r),SEEK_CUR);
					fwrite(&acc_r,sizeof(acc_r),1,file);
					fclose(file);
					printf("Successfully deposited Rs.%.2f new balance is Rs.%.2f",money,acc_r.balance);
					return;
				}
			}
			fclose(file);
			printf("\nAccount no not found");
	}
	void withdraw_money()
	{
		FILE *file = fopen(ACCOUNT_FILE,"rb+");
			if (file == NULL)
			{
				printf("Unable to open account file!");
				return;
			}
			int acc_no;
			float money;
			Account acc_ro;
			printf("Enter your account number: ");
			scanf("%d",&acc_no);
			printf("Enter amount to withdraw: ");
			scanf("%f",&money);
			
			while(fread(&acc_ro,sizeof(acc_ro),1,file))
			{
				if(acc_ro.acc_no == acc_no)
				{
					if(acc_ro.balance>=money)
					{
						acc_ro.balance -=money;
						fseek(file,-sizeof(acc_ro),SEEK_CUR);
						fwrite(&acc_ro,sizeof(acc_ro),1,file);
						fclose(file);
						printf("Successfully withdraw Rs.%.2f new balance is Rs.%.2f",money,acc_ro.balance);
					}
					else
					{
						printf("This amount is greater than your bank balance so you can not withdraw money");
					}
					return;
				}
			}
			fclose(file);
			printf("\nAccount no not found");
			
	}
	void check_balance()
	{
			FILE *file= fopen(ACCOUNT_FILE,"rb");
			if (file==NULL)
			{
				printf("\n unable to open file!");
				return;
			}
			int acc_no;
			Account acc_read;
			printf("\nEnter your account number:");
			scanf("%d",&acc_no);
			while(fread(&acc_read,sizeof(acc_read),1,file))
			{
				if(acc_read.acc_no == acc_no)
				{
					printf("\nYours current balance is Rs.%2f\n",acc_read.balance);
					fclose(file);
					return;
				}
				
			}
				fclose(file);
				printf("\nAccount no not found");
	}


