#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 12345

int main()
{
	int fd;
	int ret;
	char buf[BUFFER_SIZE + 1];
//  quand on crée un file un fd est crée qui est récupéré par open
	fd = open("fichier.txt", O_RDONLY);
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	printf("%d\n", ret);
	printf("%s\n", buf);
	return 0;
}