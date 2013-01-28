#include <stdio.h>
#include "associative_array.h"

int main() {
  int test_int = 3, *tmp;

  // initialize the hash
  hash test = init();

  // assign the testing element with the value of test_int
  assign_element(&test, "testing", (void*)&test_int, sizeof(test_int));

  // retrieve the value of the testing element
  tmp = (int*)access_element(&test, "testing");
  printf("%d\n", *tmp);

  // delete the testing element
  delete_element(&test, "testing");

  // create a new element "test1" and assign the string "testing123"
  assign_element(&test, "test1", (void*)"testing123", strlen("testing123"));
  printf("%s\n", (char*)access_element(&test, "test1"));

  // reassign "test1" to store test_int
  assign_element(&test, "test1", (void*)&test_int, sizeof(test_int));
  tmp = (int*)access_element(&test, "test1");
  printf("%d\n", *tmp);

  // delete the hash
  destroy(&test);
}
