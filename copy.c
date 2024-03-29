#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <termios.h>

// yes/no를 물어본다.
// 비정규모드(NONE ICANON)모드로 터미널 설정을 변경해서 
// 개행문자의 입력없이 바로 결과가 적용되도록 했다.  
int yorno(char *prompt)
{
	int t;
    struct termios old_set, new_set;
    int loop = 1;
    char in;
    int retval;
    tcgetattr(0, &old_set);
    new_set = old_set;
    new_set.c_lflag &= (~ICANON);
    tcsetattr(0, TCSANOW, &new_set);

    while(loop)
    {
        printf("\n%s", prompt);
        in = getc(stdin);
        switch(in)
        {
            case 'y':
            case 'Y':
                retval = 1;
                loop = 0;
                break;
            case 'n':
            case 'N':
                retval = 0;
                loop = 0;
                break;
            default:
                break;
        }
    }
    tcsetattr(0, TCSANOW, &old_set);
    printf("\n");
    return retval;
}

int copy(const char *src, const char *dst)
{
    int src_fd, dst_fd;
    struct stat srcstat;
    char in;
    int n;
    char buf[1024] = {0x00,};
    if ((src_fd = open(src, O_RDONLY)) <0 )
    {
        fprintf(stdout, "Can not open src file : %s\n", src);
        return -1;
    }

    // 원본파일의 mode를 읽어온다.
    // 나중에 생성될 파일의 mode와 권한변경에 사용된다. 
    fstat(src_fd, &srcstat);

    // 만약 파일이 존재한다면
    // 덮어쓸건지 물어본다.
    if (access(dst, F_OK) == 0)
    {
        if (!yorno("Overwrite file ? "))
        {
            exit(0);
        }
    }

    // 파일을 생성한다. 
    if ((dst_fd = open(dst, O_WRONLY|O_CREAT, srcstat.st_mode)) <0 )
    {
        fprintf(stdout, "Can not open dst file : %s\n", dst);
        close(src_fd);
        return -1;
    }
    // 내용을 복사한다. 
    while((n = read(src_fd, buf, 1024)) > 0)
    {
        write(dst_fd, buf, n);
    }

    // 파일의 소유 권한을 변경한다.
    fchown(dst_fd, srcstat.st_uid, srcstat.st_gid);
    close(src_fd);
    close(dst_fd);

    return 0;
}
