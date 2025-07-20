#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
void fill_time(char*,int);
void fill_date(char*);
int inputformat();
void clear_screen();

int main()
{
	
	char time[100];//defined a string
	char date[100];
	int format=inputformat();
	while(1)
	{
		fill_time(time,format);
		fill_date(date);
		clear_screen();
		printf("\nCurrent Time: %s",time);
		printf("\ndate is: %s",date);
		sleep(1);
	}
	return 0;
}
void clear_screen()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear")
	#endif
		
}


int inputformat()
{
	int format;
	printf("\nChoose the time format: ");
	printf("\n 24 hour format");
	printf("\n 12 hour formar(default)");
	printf("\n make a choice(1/2): ");
	scanf("%d",&format);
}
void fill_date(char*buffer)
{
	time_t rawtime;
	struct tm *current_date;
		time(&rawtime);
	current_date=localtime(&rawtime);
		strftime(buffer,100,"%A %B %d %Y",current_date);
}

void fill_time(char* buffer,int format)
{
	time_t rawtime;//time_t is datatype and rawtime is variable
	struct tm *current_time;//defined a structure
		time(&rawtime);
	current_time=localtime(&rawtime);// local time is a function of time.h header file
	if(format==1)
	{
		strftime(buffer,100,"%H:%M:%S",current_time);
	}
	else if(format==2)
	{
		strftime(buffer,100,"%I:%M:%S %p",current_time);
	}
}
