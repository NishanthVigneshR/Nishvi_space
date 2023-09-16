#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t process_id = 0;
	pid_t parent_id = 0;

	process_id = getpid();
	parent_id = getppid();
	printf("PID of the process : %d, PPID of the process : %d\n", process_id, parent_id);
}
