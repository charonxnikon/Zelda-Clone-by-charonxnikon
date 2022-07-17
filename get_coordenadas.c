#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define IGNORE 0

void scanner()
{
    double x=0,y=0; 
    int c,i,comma=0,flag=IGNORE;
    while((c=getchar())!=EOF){
        switch (c)
        {
            case ' ':
                fprintf(stderr,"%f / %f\n",x,y);
                fprintf(stderr,"*\n");
		x = x - 50;
                break;
            case '*':
		fprintf(stderr,"%f / %f\n",x,y);
		fprintf(stderr,"*\n");
                break;
            case '#':
		fprintf(stderr,"%f / %f\n",x,y);
		fprintf(stderr,"#\n");
		break;
            case '@':
		fprintf(stderr,"%f / %f\n",x,y);
		fprintf(stderr,"@\n");
      		break;
            case 'x':
		fprintf(stderr,"%f / %f\n",x,y);
		fprintf(stderr,"x\n");
                break;
            case 'k':
		fprintf(stderr,"%f / %f\n",x,y);
		fprintf(stderr,"k\n");
                break;
            case '\n':
                y = y+50;
		x = 0;
                break;
        }
	x = x + 50;
    }
}

int main(int argc,char **argv)
{
    int fd;
    if (argc!=2){
        fprintf(stderr,"Wrong amount of arguments\n");
        exit(1);
    }
    fd=open(argv[1],O_RDONLY);
    if (fd==-1){
        perror(argv[1]);
        exit(1);
    }
    dup2(fd,0);
    close(fd);
    scanner();
    return 0;
}
