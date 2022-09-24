#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "apue.h"

int main(void)
{

	int c;
	int counter=0;
	FILE *fp=fopen("100mb_files","r");
	while( (c = getc(fp)) != EOF )
	{
		counter++;
		if(putc(c,stdout) == EOF)
			err_sys("output error");
	}
	printf("counter=%d\n",counter);
	//if(ferror(stdin))
	//	err_sys("input error");

	exit(0);
}

