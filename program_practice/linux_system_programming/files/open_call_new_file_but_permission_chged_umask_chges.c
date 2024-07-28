/* As part of open system call, when we specify the O_CREAT flag with permission, the created file is not having the specified
 * permissions. It's modified and on checking further on it, understood that permission that we mentioned will be X-ORed with
 * umask which is present /etc/bashrc (or) /etc/profile. So, the permission we mentioned will be altered.
 *
 * Let'see how it'll work.
 * Default umask value - 022 --> 000 010 010 (U G O)
 * Consider the specified permission is 0777 --> 111 111 111 (U G O).
 *
 * Ex-OR will be performed, (perm) ^ (umask) = (111 111 111) ^ (000 010 010) = 111 101 101 (Finalized permission).
 *
 * Thus, file will be created with RWX for User, R_X for Group and Others.
 *
 * If we need to ignore the umask and file should be created with actual permission, we need to set umask to 0 and then need to do bitwise AND in open call.
 *
 * # Set default umask for non-login shell only if it is set to 0
 *   [ `umask` -eq 0 ] && umask 022
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h> //For umask

int main() {
	int fd = 0;
	mode_t umask_val = umask(0);

	umask(0); //Temporaily initialized the umask to 0.
	fd = open("Desiredperfile", O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	umask(umask_val); //Restored umask to original value
	printf("fd - %d\n", fd);

	/* Output:
	 * [root@localhost files]# ls -lrt Desiredperfile
	 * -rwxrwxrwx. 1 root root 0 May 11 01:40 Desiredperfile
	 */
}
