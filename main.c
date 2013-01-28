/*
  main.c
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
