#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>

int main() {
	mqd_t mqd = 0;
	char buf[50] = {0};
	int ret = 0;
	int priority = 0;

	mqd = mq_open ("/mqueue_demofile", O_RDONLY);

	if (mqd == -1) {
		printf("failed to open message queue\n");
		perror("");
		exit(0);
	}

	printf("message queue opened successfully and mqueue descriptor : %d\n", mqd);

	while (1) {
		printf("The data received : \n");
		ret = mq_receive(mqd, buf, sizeof(buf), &priority);

		if (ret == -1) {
			printf("Receiving the data in message queue failed\n");
			perror("");
			mq_close(mqd);
			exit(0);
		}

		printf("%d bytes od data received from message queue and data : %s\n", ret, buf);
	}
	mq_unlink("/mqueue_demofile");
	mq_close(mqd);
	exit(0);
}
