#ifndef VECTOR_H
#define VECTOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MINBUFSIZE 10
#define VECTOR_INIT_FAIL 1
#define VECTOR_INIT_OK 0
#define EPSILON 1e-5

typedef struct Vector {

  int currentSize; //The actual occupied space by elements
  int loadSize; //The maximum size of entire array-backing
  float loadFactor; //The current load factor
  int* elem; //Array for backing

} Vector;

static int init_vector(Vector** vec_ptr, int init_size);
static void destruct_vector(Vector* vec_ptr);
static void add_elem(Vector** vec_ptr, int elem);
static void remove_idx(Vector** vec_ptr, int idx);
static void shift_down(Vector** vec_ptr, int idx);
static void calculateLoadFactor(Vector** vec_ptr);
static void resize(Vector** vec_ptr);
static int cmpFloats(float a, float b);


#endif /* GRANDPARENT_H */