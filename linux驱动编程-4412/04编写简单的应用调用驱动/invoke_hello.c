#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

main(){
	int fd;
	char *hello_node = "/dev/hello_ctl123";
	
/*O_RDWRֻ����,O_NDELAY��������ʽ*/	
	if((fd = open(hello_node,O_RDWR|O_NDELAY))<0){
		printf("APP open %s failed",hello_node);
	}
	else{
		printf("APP open %s success",hello_node);
		ioctl(fd,1,6);
	}
	
	close(fd);
}