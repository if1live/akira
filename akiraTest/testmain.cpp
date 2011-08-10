#include "akira/AKTest.h"

int main(int argc, char *argv[]) {
#if __OBJC__
	NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
#endif

	int result = RUL_ALL_TESTS();

#if __OBJC__
	[pool release];
#endif

	getchar();	//wait
	return result;
}

