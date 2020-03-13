#include <stdio.h>
#include <fcntl.h> 
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

const char* getType(struct stat attributes);

const char* getType(struct stat attributes){
  if (attributes.st_mode & S_IFLNK) {
    return "link\n";
  }
  else if (attributes.st_mode & S_IFDIR) {
    return "dir\n";
  }
  else if (attributes.st_mode & S_IFBLK) {
  return "block\n";
  }
  else if (attributes.st_mode & S_IFSOCK) {
    return "socket\n";
  }
  else if (attributes.st_mode & S_IFIFO) {
    return "fifo\n";
  }
  return "not found";
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
     printf("inode-Number             : %ld\n",(long) attributes.st_ino);
    printf("Device Numbers           : %ld\n", attributes.st_dev);
    printf("Link count               : %ld\n",(long) attributes.st_nlink);
    printf("UID                      : %ld\n",(long) attributes.st_uid);
    printf("GID                      : %ld\n",(long) attributes.st_gid);
    printf("File size                : %lld\n",(long long) attributes.st_size);
    printf("Last access              : %s",ctime(&attributes.st_atime));
    printf("Last modification        : %s",ctime(&attributes.st_mtime));
    printf("Last inode change        : %s",ctime(&attributes.st_ctime));

    return 0;
}