#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "fetcher.h"

/**
 * write_callback - libcurl callback to write fetched data
 * @data: Pointer to incoming data chunk
 * @data_size: Size of each chunk received in these callback
 * @user_data: User-defined pointer to our Memory struct where data is stored
 *
 * Return: Total size of written data
 */

static size_t write_callback(void *data, size_t data_size, size_t numchunks, void *user_data)
{
	size_t total_data_size = data_size * numchunks;
	struct Memory *memory = user_data;

	char *temp_ptr = realloc(memory->response, memory->size + total_data_size +1);
	if (!temp_ptr)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		return 0; // Return 0 to signal failure
	}

	// if Realloc succeeded , update memory ->respone
	memory->response = temp_ptr;

	//copy the data into buffer
	//memecpy note the destination, source and size or numbers of byte to be copied
	memcpy(&(memory->response[memory->size]), data, total_data_size);
	memory->size += total_data_size;

	// Null-terminate the string
	memory->response[memory->size] = '\0';

	return total_data_size; //Return the size of data written
}

/**
 * fetch_url - Fetches HTML content from a URL using libcurl
 * @url: The URL to fetch
 * @memory: Pointer to a memory struct to hold the response
 * Return: 0 on Success, 1 on failure
 */

int fetch_url(const char *url, struct Memory *memory)
{
	CURL *curl = curl_easy_init();
	if (!curl)
	{
		fprintf(stderr, "Failed to initialize libcurl.\n");
		return 1;
	}

	memory->response = malloc(1);
	memory->size = 0;

	curl_easy_setopt(curl, CURLOPT_URL,url);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)memory);

	CURLcode res = curl_easy_perform(curl);

	if (res != CURLE_OK)
	{
		fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		curl_easy_cleanup(curl);
		return 1;
	}
	curl_easy_cleanup(curl);
	return 0;
}
