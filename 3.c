#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	const char *filename = "3.txt";
	int fd = creat(filename,0644);

	if (fd==-1){
		perror("Error using creat");
		return 1;
	}
	
	printf("The '%s' with file descriptor %d created successfully\n",filename,fd);
	close(fd);
	return 0;
}

/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ nano 3.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ gcc -o 3 3.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ ./3
The '3.txt' with file descriptor 3 created successfully
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ 

*/
