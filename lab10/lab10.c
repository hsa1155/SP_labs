#include "apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

void put_pull_rod(int signum);
void fish_eating();
void exit_game(int signum);
void start_to_wait(int signum);
void wait_to_eat(int signum);
void eat_to_esc(int signum);

int fishNum = 0; // counting fish number
int boolean = 0; // 0 for rod not put 1 for rod is put
int sta = 0;	 //
int main(void)
{

	struct sigaction sig_put_pull_rod;
	sig_put_pull_rod.sa_handler = put_pull_rod;
	sigemptyset(&sig_put_pull_rod.sa_mask);
	sig_put_pull_rod.sa_flags = SA_NODEFER;

	struct sigaction sig_exit_game;
	sig_exit_game.sa_handler = exit_game;
	sigemptyset(&sig_put_pull_rod.sa_mask);
	sig_put_pull_rod.sa_flags = SA_NODEFER;

	sigaction(SIGINT, &sig_put_pull_rod, NULL);
	sigaction(SIGTSTP, &sig_exit_game, NULL);
	//write your code here
	while (1)
	{
		printf("Fishong rod is ready!\n");

		pause();
	}

	return 0;
}

void put_pull_rod(int signum)
{
	if (boolean == 0)
	{
		printf("\nPut the fishing rod.\n");
		alarm(0);
		boolean = 1;
		struct sigaction sig_start_to_wait;
		sig_start_to_wait.sa_handler = start_to_wait;
		sigemptyset(&sig_start_to_wait.sa_mask);
		sig_start_to_wait.sa_flags = SA_NODEFER;
		sigaction(SIGALRM, &sig_start_to_wait, NULL);
		int rng = rand() % 2 + 1;
		alarm(rng);
		pause();
	}
	else
	{
		alarm(0);
		//sigaction(SIGALRM, SIG_DFL, NULL);
		printf("\nPull the fishing rod.\n");
		boolean = 0;
		if (sta == 1||sta==0)
			printf("There is no fish\n");
		if(sta==2)
		{
			printf("Caught a fish!\n");
			fishNum++;
			printf("Totally caught fishes: %d.\n",fishNum);
		}
		if(sta==3)
		{
			printf("The bait was eaten!\n");
		}
	}
	sta = 0;
	return;
}

void fish_eating()
{
	printf("eat1\n");
	sleep(2);
	printf("eat2\n");
	return;
}

void exit_game(int signum)
{
	printf("\nTotally caught fishes: %d\n", fishNum);
	exit(0);
}

void start_to_wait(int signum)
{
	alarm(0);
	sta = 1; //1 for waiting
	printf("bait into water...waiting fish.\n");
	struct sigaction sig_wait_to_eat;
	sig_wait_to_eat.sa_handler = wait_to_eat;
	sigemptyset(&sig_wait_to_eat.sa_mask);
	sig_wait_to_eat.sa_flags = SA_NODEFER;
	sigaction(SIGALRM, &sig_wait_to_eat, NULL);
	int rng = rand() % 4 + 1;
	alarm(rng);
	pause();
	return;
}
void wait_to_eat(int signum)
{
	alarm(0);
	sta = 2; //2 for eating
	printf("A fish is biting!pull the rod!\n");
	struct sigaction sig_eat_to_esc;
	sig_eat_to_esc.sa_handler = eat_to_esc;
	sigemptyset(&sig_eat_to_esc.sa_mask);
	sig_eat_to_esc.sa_flags = SA_NODEFER;
	sigaction(SIGALRM, &sig_eat_to_esc, NULL);
	int rng = rand() % 4 + 1;
	alarm(rng);
	pause();
	return;
}
void eat_to_esc(int signum)
{
	alarm(0);
	sta = 3; //2 for eating
	printf("The fish escaped :< \n");
	
	pause();
	return;
}
