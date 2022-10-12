/* Neat program that reads a struct from memory.
 * This struct first gets written to memory by the write program,
 * and it can then be accessed from a separate process like a regular
 * struct. In real programs, semaphores needed to avoid race conditions.
 */

#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>

#define SHM_SIZE 784 + sizeof(unsigned)

typedef struct test {
	unsigned char image[784];
	unsigned label;
} Test;

int main(void) {
	/* Setup shared memory */
	int fd = shm_open("test", O_RDWR, 0);
	void *buf = NULL;
  	if((buf = mmap(NULL, SHM_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED)
		printf("uh oh, mmap (try running write program first)\n");
	/* Print the contents of the struct from memory */
	Test *x = (Test*)buf;
	printf("%u, %u, %u\n", x->image[0], x->image[1], x->label);
}
