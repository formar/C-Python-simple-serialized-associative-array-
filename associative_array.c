/*
  associative_array.c
  (C) 2012 jtRIPper
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 1, or (at your option)
  any later version.
   
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
   
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include "associative_array.h"

void create_element(hash *array) {
  int index = search_elements(array, "\0");

  if (index >= 0) {
    array->num++;
    array->hashes                    = (hash_element**)realloc(array->hashes, sizeof(hash_element*) * array->num + 1);
    index = array->num;
  }
  else {
    free(array->hashes[index]->key);
  }

  array->hashes[index]        = (hash_element*)malloc(sizeof(hash_element));
  array->hashes[index]->key   = (char*)malloc(1);
  array->hashes[index]->value = malloc(1);
}

int assign_element(hash *array, char *key, void *value, int size) {
  int i, index;

  index = search_elements(array, key);

  if (index == -1) { 
    create_element(array); 
    index = array->num;
  }

  array->hashes[index]->key = (char*)realloc(array->hashes[index]->key, strlen(key));
  strcpy(array->hashes[index]->key, key);

  array->hashes[index]->value = realloc(array->hashes[index]->value, size);
  memcpy(array->hashes[index]->value, value, size);

  return index;
}

int search_elements(hash *array, char *key) {
  int i, broke = 0;

  for (i=0; i <= array->num; i++) {
    if (!strcmp(key, array->hashes[i]->key)) {
      broke = 1;
      break;
    }
  }

  if (broke == 1)
    return i;
  else
    return -1;
}

void *access_element(hash *array, char *key) {
  int index = search_elements(array, key);
  if (index == -1)
    return NULL;
  else
    return array->hashes[index]->value;
}

void delete_element(hash *array, char *key) {
  int index = search_elements(array, key);

  if (index == -1) { return; }

  free(array->hashes[index]->value);

  strcpy(array->hashes[index]->key, "\0");
  array->hashes[index]->value = NULL;
}

void destroy(hash *array) {
  int i;

  for (i = 0; i <= array->num; i++) {
    if (!strcmp(array->hashes[i]->key, "\0")) {
      free(array->hashes[i]->key);
    }
    else {
      free(array->hashes[i]->value);
      free(array->hashes[i]->key);
    }
    free(array->hashes[i]);
  }
  free(array->hashes);
}

hash init() {
  hash array;

  array.hashes           = (hash_element**)malloc(sizeof(hash_element*));
  array.num              = 0;
  array.hashes[0]        = (hash_element*)malloc(sizeof(hash_element));
  array.hashes[0]->key   = (char*)malloc(1);
  array.hashes[0]->value = malloc(1);

  return array;
}
