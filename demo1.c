#include <stdio.h>

/* these have symbol values that represent the pointers,
 * they don't actually have a type or location to be a pointer. */
extern const void _binary_testdata1_bin_start;
extern const void _binary_testdata1_bin_end;
extern const void _binary_testdata1_bin_size;

/* load the symbol values into something more practical */
static const char *testdata1 = &_binary_testdata1_bin_start;
static const size_t testdata1_len = (size_t)&_binary_testdata1_bin_size;

/* the second method has an easier interface. */
extern const char binary_testdata2_start[];
extern const int binary_testdata2_size;

static void dump_testdata1(void) {
	fprintf(stderr, "testdata1:\n");
	fprintf(stderr, "\tstart: %p\n", &_binary_testdata1_bin_start);
	fprintf(stderr, "\tend: %p\n", &_binary_testdata1_bin_end);
	fprintf(stderr, "\tsize: %p\n", &_binary_testdata1_bin_size);

	fprintf(stderr, "testdata1 = \"%.*s\"\n", testdata1_len, testdata1);
}

static void dump_testdata2(void) {
	fprintf(stderr, "testdata2:\n");
	fprintf(stderr, "\tstart: %p\n", binary_testdata2_start);
	fprintf(stderr, "\tsize: %d\n", binary_testdata2_size);
	fprintf(stderr, "testdata2 = \"%s\"\n", binary_testdata2_start);
}

int main() {
	dump_testdata1();
	dump_testdata2();
	return 0;
}
