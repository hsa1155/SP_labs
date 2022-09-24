#include "apue.h"
#include <sys/wait.h>

static void	sig_int(int);		/* our signal-catching function */
int
main(void)
{
		char	buf[MAXLINE];	/* from apue.h */
		pid_t	pid;
		int		status;

		if (signal(SIGINT, sig_int) == SIG_ERR)
				err_sys("signal error");

		printf("%% ");	/* print prompt (printf requires %% to print %) */
		while (fgets(buf, MAXLINE, stdin) != NULL) {



				if (buf[strlen(buf) - 1] == '\n')
						buf[strlen(buf) - 1] = 0; /* replace newline with null */


				
				int counter=1;
				char *cmd[20];
				for(int i=0;i<20;i++) cmd[i]=malloc(1024);
				char *token ;
				token=strtok(buf," ");
				cmd[0]=token;

				while(token!=NULL)
				{
					token=strtok(NULL," ");
					cmd[counter]=token;
					counter++;
				}
				cmd[counter]=NULL;


				if(strcmp("cd",cmd[0])==0)
				{
					if(chdir(cmd[1])==-1) printf("%s does not exist\n",cmd[1]);
					printf("%% ");
					continue;
				}


				if ((pid = fork()) < 0) {
						err_sys("fork error");
				} else if (pid == 0) {		/* child */
						/*
						switch (counter)
						{
						case 1:
							execlp(cmd[0], cmd[0], NULL);
							err_ret("couldn't execute: %s", buf);
							exit(127);
							break;
						case 2:
							execlp(cmd[0], cmd[0],cmd[1], NULL);
							err_ret("couldn't execute: %s", buf);
							exit(127);
							break;
						case 3:
							execlp(cmd[0], cmd[0],cmd[1],cmd[2], NULL);
							err_ret("couldn't execute: %s", buf);
							exit(127);
							break;
						case 4:
							execlp(cmd[0], cmd[0],cmd[1],cmd[2],cmd[3], NULL);
							err_ret("couldn't execute: %s", buf);
							exit(127);
							break;
						case 5:
							execlp(cmd[0], cmd[0],cmd[1],cmd[2],cmd[3],cmd[4],NULL);
							err_ret("couldn't execute: %s", buf);
							exit(127);
							break;
						case 6:
							execlp(cmd[0], cmd[0],cmd[1],cmd[2],cmd[3],cmd[4],cmd[5], NULL);
							err_ret("couldn't execute: %s", buf);
							exit(127);
							break;
						case 7:
							execlp(cmd[0], cmd[0],cmd[1],cmd[2],cmd[3],cmd[4],cmd[5],cmd[6],NULL);
							err_ret("couldn't execute: %s", buf);
							exit(127);
							break;
						case 8:
							execlp(cmd[0], cmd[0],cmd[1],cmd[2],cmd[3],cmd[4],cmd[5],cmd[6],cmd[7], NULL);
							err_ret("couldn't execute: %s", buf);
							exit(127);
							break;
						case 9:
							execlp(cmd[0], cmd[0],cmd[1],cmd[2],cmd[3],cmd[4],cmd[5],cmd[6],cmd[7],cmd[8], NULL);
							err_ret("couldn't execute: %s", buf);
							exit(127);
							break;
						case 10:
							execlp(cmd[0], cmd[0],cmd[1],cmd[2],cmd[3],cmd[4],cmd[5],cmd[6],cmd[7],cmd[8],cmd[9], NULL);
							err_ret("couldn't execute: %s", buf);
							exit(127);
							break;
						
						
						}
						*/
					execvp(cmd[0],cmd);
					err_ret("couldn't execute: %s", buf);
							exit(127);
				}

				
				/* parent */
				if ((pid = waitpid(pid, &status, 0)) < 0)
						err_sys("waitpid error");
				printf("%% ");
		}
		exit(0);
}

		void
sig_int(int signo)
{
		printf("interrupt\n%% ");
}

