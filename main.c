#include <stdio.h>
#include <stdlib.h>
#include "fetcher.h"


int main(void)
{
	struct Memory page;
	printf("Fetching https://www.w3schools.com/ ...\n");

	if (fetch_url("https://www.w3schools.com/", &page) !=0)
	{
		fprintf(stderr, "Error: Failed to fetch page.\n");
		return 1;
	}

	printf("=== HTML Content ===\n\n%s\n", page.response);

	free(page.response);
	return 0;
}

