#include <unistd.h>
#include <error.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
int open_txt(const char* txtstring)
{
	int tmp = -1;

	tmp = open(txtstring, O_RDONLY);
	if (tmp == -1)
	{
		perror(txtstring);
		exit(-1);
	}

	return tmp;
}

int main(void)
{
	char buf[20] = {0};
	int fd = -1;
	int op = -1;
	system("cat /proc/partitions > test.txt");
	fd = open_txt("test.txt");//proc/partitions
	//printf("%d\n", fd);
	op = lseek(fd, -5, SEEK_END);
	if (op == -1)
	{
		perror("lseek");
	}
	int ret = read(fd, buf, 4);
	if (ret == -1)
	{
		perror("read error");
		exit(-1);
	}
	printf("%s\n", buf);
	if (strncmp("sdb1", buf, 4) == 0)
	{
		printf("device is sdb1\n");
		system("fdisk -l /dev/sdb1");
		//system("export name=sdb1 && fdisk -l /dev/$name");
		//system("echo $name");
	}

	/*char *ip = "127.0.0.1";
	char cmd[1024];
	sprintf(cmd, "ping %s", ip);
	system(cmd);*/	

	return 0;
}

