#ifndef FETCHER_H
#define FETCHER_h

/**
 * struct Memory - Dynamics buffer for storing HTTP response
 * @response: Pointer to buffer with HTML content
 * @size: Size of the buffer
 */

struct Memory
{
	char *response;
	size_t size;
};

int fetch_url(const char *url, struct Memory *mem);

#endif /* FETCHER_H */
