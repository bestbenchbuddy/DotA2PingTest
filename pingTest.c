//DotaPingTest c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define DEBUG
#define LINE_MAX 100

void menu()
{
	printf("Welcome to the Dota 2 ping testing application.\n");
}

void menu2()
{
	printf("Test another server? (1 yes; 2 no)");
}

void menu3()
{
	printf("Please enter the digit corresponding to your operating system.\n");
	printf("Linux(1), Windows(2), Mac(3). [Quit(4)]\n");
}

void menu4()
{
	printf("Select from the list of servers to check your ping from.\n");
	printf("Austrailia (Sydney) [1]\n");
	printf("Chile (Santiago) [2]\n");
	printf("Dubai (UAE) [3]\n");
	printf("Europe East 1 (Vienna, Austria) [4]\n");
	printf("Europe East 2 (Vienna, Austria) [5]\n");
	printf("Europe West 1 (Luxembourg) [6]\n");
	printf("Europe West 2 (Luxembourg) [7]\n");
	printf("India (Kolkata) [8]\n");
	printf("Peru (Lima) [9]\n");
	printf("Russia 1 (Stockholm, Sweden) [10]\n");
	printf("Russia 2 (Stockholm, Sweden) [11]\n");
	printf("SE Asia 1 (Singapore) [12]\n");
	printf("SE Asia 2 (Singapore) [13]\n");
	printf("South Africa 1 (Cape Town) [14]\n");
	printf("South Africa 2 (Cape Town) [15]\n");
	printf("South Africa 3 (Cape Town) [16]\n");
	printf("South Africa 4 (Cape Town) [17]\n");
	printf("South America 1 (Sao Paulo) [18]\n");
	printf("South America 2 (Sao Paulo) [19]\n");
	printf("South America 3 (Sao Paulo [20]\n");
	printf("US East (Sterling, VA) [21]\n");
	printf("US West (Seattle, WA) [22]\n");
}
/*
int serverCheck()
{

}


char* checkValid()
{
	
} 
*/

void pingTest(int OS)
{
	int locationID, iterations=0;
	char IP[LINE_MAX];
	switch(OS)
	{
		case 1: char temp[LINE_MAX] = "ping";
		break;
		case 2: char temp[LINE_MAX] = "ping";
		char temp2[LINE_MAX];
		break;
		//mac work in progress
		case 3: char temp[LINE_MAX] = "ping";
		char temp2[LINE_MAX] = "-t";
		break;
		default:
		break;
	}
	
	menu4();

	do{
		if(iterations>0) {
			printf("Please enter an integer for 1-22.\n");
		}
		
		if(!fgets(buf, sizeof buf, stdin)) {
			printf("Error getting buffer.\n");
			broke=1;
		}
		// remove \n
		buf[strlen(buf) - 1] = 0;

		OS = strtol(buf, &end, 10);
		iterations++;
	}while(end != buf + strlen(buf) || (OS>0 && OS<23));
	iterations=0;

	
	


	//might implement threads for different applications 
	//in a single shell(child processes etc)


	//char* IP[11]="200.73.67.1";
	//if(execvp("ping", IP) == -1)
	//	perror("Error");
}

int main()
{
	char *end;
	char buf[LINE_MAX];
	int OS, broke = 0, iterations=0, completedTasks=0;

	menu();

	while(1)
	{	
		menu3();
		//taking input for first server
		do{
			if(iterations>0) {
				printf("Please enter an integer for 1-4.\n");
				if(iterations>2)
					printf("If on Linux type 1, on Windows type 2, on Mac type 3. (4 to quit)\n");
			}

			completedTasks++;
			if (!fgets(buf, sizeof buf, stdin)) {
				printf("Error getting buffer.\n");
				broke=1;
			}
			// remove \n
			buf[strlen(buf) - 1] = 0;

			OS = strtol(buf, &end, 10);
			
			#ifdef DEBUG
			printf("String part is |%s|.\n",end);
			printf("OS number: |%d|.\n",OS);
			printf("Buf value: |%s|.\n", buf);
			#endif

			iterations++;
		}while(end != buf + strlen(buf) || (OS!=1 && OS!=2 && OS!=3 && OS!=4));

		iterations=0;
		//check if program is ending
		if(OS==4)
		{
			printf("Ending program.\n");
			return 0;
		}

		menu2();
		completedTasks++;

		//test another server or not
		do{
			if(iterations>0) {
				printf("Please enter an integer for 1-2.\n");
				if(iterations>2)
					printf("1 to continue 2 to quit.)\n");
			}
			
			if(!fgets(buf, sizeof buf, stdin)) {
				printf("Error getting buffer.\n");
				broke=1;
			}
			// remove \n
			buf[strlen(buf) - 1] = 0;

			OS = strtol(buf, &end, 10);
			iterations++;
		}while(end != buf + strlen(buf) || (OS!=1 && OS!=2));
		iterations=0;
		if(OS==2)
			break;
	}
	return 0;
}