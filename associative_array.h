#ifndef _ASSOCIATIVE_ARRAY
#define _ASSOCIATIVE_ARRAY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *key;
  void *value;
} hash_element;

typedef struct {
  hash_element **hashes;
  int num;
} hash;

void create_element(hash *array);
int assign_element(hash *array, char *key, void *value, int size);
int search_elements(hash *array, char *key);
void *access_element(hash *array, char *key);
void delete_element(hash *array, char *key);
void destroy(hash *array);
hash init();

#endif
