/* This code increments x from 1-100 in a loop using longjmp and setjmp.
 * Horrible practice, but an interesting example nonetheless.
 */

#include <stdio.h>
#include <setjmp.h>

static jmp_buf buf;
static int x;

void loop(void) {
    printf("x=%d\n", x+=1);
    longjmp(buf, 1);
}

int main(void) {
	setjmp(buf);
	if(x != 100)
		loop();
    return 0;
}
