#include <stdio.h>
#include <fcntl.h> 
#include <sys/stat.h>
#include <sys/types.h>

#define CONST 256


int main (int argc, char const * argv[]){
    if(argc != 3)
    {
        printf("only arguments 3 arguments possible!");
        return 0;
    }

    int src;
	int cpy;
	
	src = open(argv[1], O_RDONLY);
	cpy = open(argv[2], O_CREAT | O_WRONLY, COPYMODE);

	int num;
	char buffer[CONST];

	while((num = read(src, &buffer, CONST)) > 0){
		write(cpy, &buffer, num);
	}
	
	close(src);
	close(cpy);
	return 0;
}