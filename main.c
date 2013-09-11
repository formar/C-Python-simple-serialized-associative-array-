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

  //Gathers up the data from the steam. Cannot use gets or scanf because of NULL char's
  FILE *myfile=fopen("debug","r");
  char dataStream[1000];
  int size=0;
  do{
    dataStream[size++]=fgetc(myfile);
  }while(!feof(myfile));
  int test_int = 3, *tmp;
  // initialize the hash
  hash test = init();


  construct_from_serial(dataStream,size,&test);

  // retrieve the value of the testing element
  tmp = (int*)access_element(&test, "Second");
  if(tmp!=NULL)
    printf("Second: %d\n", *tmp);

    tmp = (int*)access_element(&test, "Forth");
  if(tmp!=NULL)
    printf("Forth: %d\n", *tmp);

  // delete the hash
  destroy(&test);
}
