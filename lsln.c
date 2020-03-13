#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h> 
#include <stdio.h> 
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>

struct stat attributes;
void fileType();
void printAccess();

int main(int argc, char* argv[]) {
DIR *d;
struct dirent *dir;

if(argc == 2){
	d = opendir(argv[1]);
}

if(ENOENT == errno|| argc == 1)
{
	printf("File Not exists, use default \n");
	d = opendir(".");	
}	

while ((dir = readdir(d)) != NULL) {
	
		lstat(dir->d_name,&attributes);
		
		fileType();
		printAccess();
		printf("%-10s",dir->d_name);		
	}
	closedir(d);
	printf("\n");
	return 0;	
}

void fileType() {
	
	if (attributes.st_mode & S_IFLNK) {
        printf("link\n");
    }
    else if (attributes.st_mode & S_IFDIR) {
        printf("dir\n");
    }
    else if (attributes.st_mode & S_IFBLK) {
        printf("block\n");
    }
    else if (attributes.st_mode & S_IFSOCK) {
        printf("socket\n");
    }
    else if (attributes.st_mode & S_IFIFO) {
        printf("fifo\n");
    }

    printf("not found");
}
void printAccess(){
	printf( (S_ISDIR(attributes.st_mode)) ? "d" : "-");
	printf( (attributes.st_mode & S_IRUSR) ? "r" : "-");
	printf( (attributes.st_mode & S_IWUSR) ? "w" : "-");
	printf( (attributes.st_mode & S_IXUSR) ? "x" : "-");
	printf( (attributes.st_mode & S_IRGRP) ? "r" : "-");
	printf( (attributes.st_mode & S_IWGRP) ? "w" : "-");
	printf( (attributes.st_mode & S_IXGRP) ? "x" : "-");
	printf( (attributes.st_mode & S_IROTH) ? "r" :"-");
	printf( (attributes.st_mode & S_IWOTH) ? "w" : "-");
	printf( (attributes.st_mode & S_IXOTH) ? "x" : "-");
	printf(" ");
}