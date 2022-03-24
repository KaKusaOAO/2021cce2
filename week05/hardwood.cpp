#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct {
	char *name;
	int count;
} Entry;

int comparer(const void *a, const void *b) {
	Entry *_a = (Entry*) a;
	Entry *_b = (Entry*) b;
	return strcmp(_a->name, _b->name);
}

int main() {
	char line[2048] = {};
	int n;
	scanf("%d\n\n", &n);

	for (int i=0; i<n; i++) {
		if (i>0) printf("\n");

		Entry entries[10000] = {};
		int entryCount = 0;
		int total = 0;

		while(gets(line)) {
			if (line[0] == '\0') break;
			int len = strlen(line);

			Entry *e = 0;
			for (int j=0; j<entryCount; j++) {
				if (strcmp(entries[j].name, line) == 0) {
					e = &entries[j];
					break;
				}
			}

			if (!e) {
				char *buf = (char*) malloc(len + 1);
				memset(buf, 0, len + 1);
				strncpy(buf, line, len);
				entries[entryCount].name = buf;
				e = &entries[entryCount++];
			}
			e->count++;
			total++;
		}

		qsort(entries, entryCount, sizeof(Entry), comparer);

		for (int j=0; j<entryCount; j++) {
			Entry *e = &entries[j];
			double p = (double)e->count / (double)total * 100.0;
			printf("%s %.4f\n", e->name, p);
			free(e->name);
		}
	}
}
