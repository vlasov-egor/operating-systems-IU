#include <stdio.h>
#include <float.h>
#include <limits.h>

int main() {
	int var1 = INT_MAX;
	float var2 = FLT_MAX;
	double var3 = DBL_MAX;

	printf("Int: size = %lu, value = %d\n", sizeof(var1), var1);
	printf("Float: size = %lu, value = %f\n", sizeof(var2), var2);
	printf("Double: size = %lu, value = %f\n", sizeof(var3), var3);
}