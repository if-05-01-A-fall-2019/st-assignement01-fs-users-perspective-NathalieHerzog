#include <stdio.h>
#include <fcntl.h> 
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

const char* getType(struct stat attributes);

const char* getType(struct stat attributes){
  if (attributes.st_mode & S_IFLNK) {
    return 'link\n';
  }
  else if (attributes.st_mode & S_IFDIR) {
    return 'dir\n';
  }
  else if (attributes.st_mode & S_IFBLK) {
  return 'block\n';
  }
  else if (attributes.st_mode & S_IFSOCK) {
    return 'socket\n';
  }
  else if (attributes.st_mode & S_IFIFO) {
    return 'fifo\n';
  }
  return 'not found';
}

int main(int argc, char const *argv[]) {
    struct stat attributes;

    printf("------------------------ %s --------------------\n", argv[1]);
    printf("File type                : %s\n", getType(attributes));
    printf("Access privileges        : ");
    printf( (S_ISDIR(attributes.st_mode)) ? "d" : "-");
    printf( (attributes.st_mode & S_IRUSR) ? "r" : "-");
    printf( (attributes.st_mode & S_IWUSR) ? "w" : "-");
    printf( (attributes.st_mode & S_IXUSR) ? "x" : "-");
    printf( (attributes.st_mode & S_IRGRP) ? "r" : "-");
    printf( (attributes.st_mode & S_IWGRP) ? "w" : "-");
    printf( (attributes.st_mode & S_IXGRP) ? "x" : "-");
    printf( (attributes.st_mode & S_IROTH) ? "r" : "-");
    printf( (attributes.st_mode & S_IWOTH) ? "w" : "-");
    printf( (attributes.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
    printf("File Type         | %d\n", getType(attributes));
    printf("Access privileges | %hu\n", attributes.st_mode); 
    printf("inode-Number      | %llu\n", attributes.st_ino); 
    printf("Device numbers    | %d\n", attributes.st_dev);
    printf("Links count       | %hu\n", attributes.st_nlink); 
    printf("UID               | %u\n", attributes.st_uid);
    printf("GID               | %u\n", attributes.st_gid);
    printf("File size         | %lld\n", attributes.st_size); 
    printf("Last access       | %ld\n", attributes.st_atime); 
    printf("Last modification | %ld\n", attributes.st_mtime);
    printf("Last inode change | %ld\n", attributes.st_ctime);

    return 0;
}