#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd = 0;
	int ret = 0;
	char *add = NULL;

	fd = shm_open("/shm_file", O_RDWR, 0);

	printf("ret val of shm_open %d\n", fd);

	add = mmap(NULL, 10, PROT_READ, MAP_SHARED, fd, 0);

	if (add == NULL) {
		printf("mmap failed\n");
		return 0;
	}
	printf("received data - %s\n", add);
}
