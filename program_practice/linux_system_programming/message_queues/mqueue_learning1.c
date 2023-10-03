#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

int main() {
	printf("This is process-1 and pid : %d\n", getpid());
	mqd_t mqd = 0;
	struct mq_attr attr;
	int ret = 0;

	attr.mq_maxmsg = 100;
        attr.mq_msgsize = 8092;
	mqd = mq_open ("/mes_queue_demo_file", O_WRONLY | O_CREAT, 0660, &attr);
	//mqd = mq_open ("/mes_queue_demo_file", O_WRONLY | O_CREAT, 0660, NULL);

	if (mqd == -1) {
		printf("Opening message queue failed\n");
		perror("");
		exit(0);
	}
	printf("Message queue opened or created successfully and mqd is %d\n", mqd);

	ret = mq_getattr (mqd, &attr);
	if (ret == -1) {
		perror("get attributes failed : ");
	}
	printf("Attributes are : flag - %ld, max_msg_in_queue - %ld, max_size_of_msg - %ld, curr_msgs - %ld\n",
			attr.mq_flags, attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);

	/* 
	 * root@localhost message_queues]# ./mqueue_learning1
	 * This is process-1 and pid : 14420
	 * Message queue opened or created successfully and mqd is 3
	 * Attributes are : flag - 0, max_msg_in_queue - 100, max_size_of_msg - 8092, curr_msgs - 0
	 * [root@localhost message_queues]# ./mqueue_learning1
	 * This is process-1 and pid : 13425
	 * Message queue opened or created successfully and mqd is 3
	 * Attributes are : flag - 0, max_msg_in_queue - 10, max_size_of_msg - 8192, curr_msgs - 0
	 */
	mq_close(mqd);
	mq_unlink("/mes_queue_demo_file");
}
