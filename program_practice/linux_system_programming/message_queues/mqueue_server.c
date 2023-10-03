#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>

int main() {
	mqd_t mqd = 0;
	int ret = 0;
	char buf[50] = {0};

	mqd = mq_open ("/mqueue_demofile", O_WRONLY | O_CREAT, 0666, NULL);

	/* I missed to provide '/' symbol and got below error.
	 * [root@localhost message_queues]# ./mqueue_server
	 * message queue open failed and error : : Invalid argument
	 */


	if (mqd == -1) {
		perror("message queue open failed and error : ");
		exit(0);
	}
	printf("message queue opened succesfully and mqueue descriptor : %d\n", mqd);

	while (1) {
		printf("Enter the buffer to be sent\n");
		fgets(buf, sizeof(buf), stdin);

		ret = mq_send(mqd, buf, strlen(buf), 0);
		if (ret == -1) {
			printf("sending data via messgae queue failed\n");
			perror("");
			mq_close(mqd);
			exit(0);
		}
		printf("message queue send success\n");
	}
	mq_close(mqd);
	mq_unlink("/mqueue_demofile");
	exit(0);
}
