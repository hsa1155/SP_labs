#include "apue.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(void)
{
	char buf[MAXLINE];
	int counter=0;
	FILE *fp=fopen("100mb_files","r");
	setvbuf(fp, buf, _IONBF	, MAXLINE);

	while( (fgets(buf,MAXLINE,fp)) != NULL )
	{
		counter++;
		if(fputs(buf,stdout) == EOF)
			err_sys("output error");
	}
	printf("counter=%d\n",counter);	
	//if(ferror(stdin))
	//		err_sys("input error");

	exit(0);
}

