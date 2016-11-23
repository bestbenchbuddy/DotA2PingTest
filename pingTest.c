//DotaPingTest c
//Nicholas Bastian
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//#define DEBUG
#define LINE_MAX 100

void menu()
{
	printf("Welcome to the Dota 2 ping testing application.\n");
}

void menu2()
{
	printf("Test another server? (1 yes; 2 no)\n");
}

void menu3()
{
	printf("Please enter the digit corresponding to your operating system.\n");
	printf("Four pings(1), Looped pings(2), Mac(3). [Quit(4)]\n");
	printf("[(1) and (2) work for windows and Linux]\n");
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
	int locationID, iterations=0;// broke=0;
	char IP[LINE_MAX];
	char temp[LINE_MAX];
	char temp2[LINE_MAX];
	char *end;
	char buf[LINE_MAX];
	switch(OS)
	{
		case 1: strcpy(temp, "ping ");//4 pings
		break;
		case 2: strcpy(temp, "ping ");//Looped
		strcpy(temp2, " -t");
		break;
		//mac work in progress
		case 3: //char temp[LINE_MAX] = "ping ";//mac
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
			//broke=1;
		}
		// remove \n
		buf[strlen(buf) - 1] = 0;

		locationID = strtol(buf, &end, 10);
		iterations++;
	}while(end != buf + strlen(buf) || (OS<=0 && OS>=23));
	iterations=0;

	switch(locationID)
	{
		case 1: strcpy(IP, "syd.valve.net");
		break;
		case 2: strcpy(IP, "200.73.67.1");;
		break;
		case 3: strcpy(IP, "dxb.valve.net");
		break;
		case 4: strcpy(IP, "vie.valve.net");
		break;
		case 5: strcpy(IP, "185.25.182.1");
		break;
		case 6: strcpy(IP, "lux.valve.net");
		break;
		case 7: strcpy(IP, "146.66.158.1");
		break;
		case 8: strcpy(IP, "116.202.224.146");
		break;
		case 9: strcpy(IP, "191.98.144.1");
		break;
		case 10: strcpy(IP, "sto.valve.net");
		break;
		case 11: strcpy(IP, "185.25.180.1");
		break;
		case 12: strcpy(IP, "sgp-1.valve.net");
		break;
		case 13: strcpy(IP, "sgp-2.valve.net");
		break;
		case 14: strcpy(IP, "cpt-1.valve.net");
		break;
		case 15: strcpy(IP, "197.80.200.1");
		break;
		case 16: strcpy(IP, "197.84.209.1");
		break;
		case 17: strcpy(IP, "196.38.180.1");
		break;
		case 18: strcpy(IP, "gru.valve.net");
		break;
		case 19: strcpy(IP, "209.197.25.1");
		break;
		case 20: strcpy(IP, "209.197.29.1");
		break;
		case 21: strcpy(IP, "iad.valve.net");
		break; 
		case 22: strcpy(IP, "eat.valve.net");
		break;
		
	}

	if(OS==1) {
		strcat(temp, IP);
		printf("Please wait for the pinging to complete...\n");
		#ifdef DEBUG
		printf("%s\n", temp);
		#endif
	}
	else if (OS==2) {
		strcat(temp, IP); 
		strcat(temp, temp2);
		printf("(Ctrl + c will end the loop)\n");
		#ifdef DEBUG
		printf("%s\n", temp);
		#endif
	}
	else
		strcat(temp, IP);

	system(temp);


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
	int OS, iterations=0, completedTasks=0;//broke = 0

	menu();

	while(1)
	{	
		menu3();
		//taking input for first server
		do{
			if(iterations>0) {
				printf("Please enter an integer for 1-4.\n");
				if(iterations>2)
					printf("If four pings type 1, if looped type 2, on Mac type 3. (4 to quit)\n");
			}

			completedTasks++;
			if (!fgets(buf, sizeof buf, stdin)) {
				printf("Error getting buffer.\n");
				//broke=1;
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
		pingTest(OS);
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
				//broke=1;
			}
			// remove \n
			buf[strlen(buf) - 1] = 0;

			OS = strtol(buf, &end, 10);
			iterations++;
		}while(end != buf + strlen(buf) || (OS!=1 && OS!=2));
		iterations=0;
		if(OS==2)
		{
			printf("Ending program.\n");
			break;
		}
	}
	return 0;
}