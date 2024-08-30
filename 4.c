#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	const char  *filename = "3.txt";
	int fd;

	fd = open(filename, O_RDWR);
	if (fd == -1){
		perror("Coundn't open the file");
		return 1;
	}
	printf("Opened the file successfully.filedescriptor=%d\n",fd);
	close(fd);
	
	fd = open(filename,O_RDWR | O_EXCL);
	if (fd==-1){
		perror("Couldn't open the file with O_RDWR | O_EXCL");
		return 1;
	}
	printf("File opened successfully with O_RDWR | O_EXCL.file descriptor=%d\n",fd);
	close(fd);
	return 0;
}

