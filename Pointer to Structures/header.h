#ifndef header_h
#define header_h

struct entry {
	char *quote;
	int count;
	struct entry* next;
};

struct entry* process_quotes();

char* read_quotes();

void print_result();

#endif