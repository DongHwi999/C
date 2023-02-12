#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <termios.h>

// yes/no�� �����.
// �����Ը��(NONE ICANON)���� �͹̳� ������ �����ؼ� 
// ���๮���� �Է¾��� �ٷ� ����� ����ǵ��� �ߴ�.  
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

    // ���������� mode�� �о�´�.
    // ���߿� ������ ������ mode�� ���Ѻ��濡 ���ȴ�. 
    fstat(src_fd, &srcstat);

    // ���� ������ �����Ѵٸ�
    // ������� �����.
    if (access(dst, F_OK) == 0)
    {
        if (!yorno("Overwrite file ? "))
        {
            exit(0);
        }
    }

    // ������ �����Ѵ�. 
    if ((dst_fd = open(dst, O_WRONLY|O_CREAT, srcstat.st_mode)) <0 )
    {
        fprintf(stdout, "Can not open dst file : %s\n", dst);
        close(src_fd);
        return -1;
    }
    // ������ �����Ѵ�. 
    while((n = read(src_fd, buf, 1024)) > 0)
    {
        write(dst_fd, buf, n);
    }

    // ������ ���� ������ �����Ѵ�.
    fchown(dst_fd, srcstat.st_uid, srcstat.st_gid);
    close(src_fd);
    close(dst_fd);

    return 0;
}
