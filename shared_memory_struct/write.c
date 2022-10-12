/* Neat program that writes a struct to memory.
 * This struct can then be cast as a struct by the program read
 * and accessed like a regular struct.
 * In real programs, semaphores needed to avoid race conditions.
 */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

#define SHM_SIZE 784 + sizeof(unsigned)

#define ALL_RW_PERMS (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWGRP)

typedef struct test {
	unsigned char image[784];
	unsigned label;
} Test;

int main(void) {
	/* Create shared memory of desired size */
	int fd = shm_open("test", O_RDWR|O_CREAT, ALL_RW_PERMS);
	ftruncate(fd, SHM_SIZE);

	/* Setup shared memory */
	void *buf = NULL;
  	if((buf = mmap(NULL, SHM_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED)
		printf("uh oh, mmap\n");
	printf("memory mapped to VA=%p\n", buf);

	/* Initialzing test struct, then writing it to memory */
	Test *x = buf;
	x->image[0] = 1;
	x->image[1] = 2;
	x->label = 34;
	Test *y = (Test*)buf;
	printf("%u, %u, %u\n", y->image[0], y->image[1], y->label);
}
