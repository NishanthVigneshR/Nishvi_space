#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int fd = 0;
	int ret = 0;
	char *addr;
	char buff[10] = "hi";
	fd = shm_open("/shm_file", O_RDWR | O_CREAT, 0777);

	printf("Ret val of shm_open - %d\n", fd);

	ret = ftruncate(fd, 50);

	printf("truncate ret val - %d\n", ret);

	addr = mmap(NULL, 50, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED) {
		printf("mmap failed\n");
		return 0;
	}

	memcpy(addr, buff, strlen(buff));
}



