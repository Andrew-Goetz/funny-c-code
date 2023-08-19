/* Simple example of buffer overflow.
 * Input value of size >= 10 and `name` will overflow 
 * into the array `sensitive`, overwritting the data.
 */

#include <stdio.h>
#include <string.h>

enum { 
	NAME_SIZE = 10,
	SENSITIVE_SIZE = 16,
};

struct {
	char name[NAME_SIZE];
	char sensitive[SENSITIVE_SIZE];
} data;

int main(void) {
	strcpy(data.sensitive, "sensitive");
	printf("Enter your name: "); fflush(stdout);
	scanf("%s", data.name);
	printf("sensitive = %s\n", data.sensitive);
	return 0;
}
