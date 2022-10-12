/* Program loops, allocating memory until your system runs out.
 * Fun watch RAM usage go up in htop.
 */

#include <stdlib.h>

int main() {
	for(;;) malloc(0xffff);
}
