#include "vector.h"

/**
 * @brief Initiates a vector pointer with a pointer to a vector struct
 *
 * @param vec_ptr The pointer to return the struct to
 * @param init_size The requested starting size of the vector
 * @return int returns VECTOR_INIT_OK on success or VECTOR_INIT_FAIL on fail
 */
static int init_vector(Vector** vec_ptr, int init_size) {

  if (init_size != 0) {

    Vector* vec = malloc(sizeof(Vector));

    if (vec == NULL) {

      return VECTOR_INIT_FAIL;
    }

    vec->elem = calloc(1, init_size * sizeof(int));

    if (vec->elem == NULL) {

      return VECTOR_INIT_FAIL;
    }

    vec->currentSize = 0;
    vec->loadSize = init_size;
    vec->loadFactor = vec->currentSize / vec->loadSize;
    *vec_ptr = vec;

    return VECTOR_INIT_OK;
  }

  Vector* vec = malloc(sizeof(Vector));

  if (vec == NULL) {

    return VECTOR_INIT_FAIL;
  }

  vec->elem = calloc(1, MINBUFSIZE * sizeof(int));

  if (vec->elem == NULL) {

    return VECTOR_INIT_FAIL;
  }

  vec->currentSize = 0;
  vec->loadSize = MINBUFSIZE;
  vec->loadFactor = vec->currentSize / vec->loadSize;
  *vec_ptr = vec;
  return VECTOR_INIT_OK;
}

static void destruct_vector(Vector* vec_ptr) {

  free(vec_ptr->elem);
  free(vec_ptr);
}

/**
 * @brief Add element to Vector** vec_ptr
 *
 * @param vec_ptr Pointer to vector to add to
 * @param elem  The element to be added
 *
 * Will increase array with realloc() if load factor is 0.75 or higher
 *
 */
static void add_elem(Vector** vec_ptr, int elem) {

  Vector* vec = *vec_ptr;
  vec->elem[vec->currentSize] = elem;
  vec->currentSize++;
  vec->loadFactor = vec->currentSize / vec->loadSize;
  calculateLoadFactor(vec_ptr);
  if (cmpFloats(vec->loadFactor, 0.75f) == 1) {

    printf("Resize");
    resize(vec_ptr);
  }

  *vec_ptr = vec;
}

/**
 * @brief Delete element at index
 *
 * @param vec_ptr Pointer to vector to delete from
 * @param idx  Index of element to be deleted
 *
 * Will shift down all elements from deletion point to the left to close gap
 *
 */
static void remove_idx(Vector** vec_ptr, int idx) {

  Vector* vec = *vec_ptr;
  vec->elem[idx] = 0;
  *vec_ptr = vec;
  shift_down(vec_ptr, idx);
}

/**
 * @brief **Internal do not call**
 *
 * Shifts down all elements from idx by one position to the left
 *
 * @param vec_ptr Pointer to vector
 * @param idx Element to start shifting down from
 */
static void shift_down(Vector** vec_ptr, int idx) {

  Vector* vec = *vec_ptr;

  if (idx == vec->currentSize - 1) {

    vec->currentSize--;
    *vec_ptr = vec;
    return;
  }

  for (int i = idx; i < vec->currentSize; i++) {

    if (i + 1 >= vec->currentSize) {

      vec->elem[i] = 0;
      break;
    }

    vec->elem[i] = vec->elem[i + 1];
  }

  vec->currentSize--;
  *vec_ptr = vec;
}

static void calculateLoadFactor(Vector** vec_ptr) {

  Vector* vec = *vec_ptr;
  vec->loadFactor = ((float)vec->currentSize / vec->loadSize);
  *vec_ptr = vec;
}

static void resize(Vector** vec_ptr) {

  Vector* vec = *vec_ptr;
  int* newArray = calloc(1, (vec->loadSize*2) * sizeof(int));
  memcpy(newArray, vec->elem, vec->currentSize * sizeof(int));
  free(vec->elem);
  vec->elem = newArray;
  vec->loadSize = vec->loadSize*2;
  
  *vec_ptr = vec;
  int q = 4;
}

static int cmpFloats(float a, float b) {
  int q = 4;
  int retval = (a-b > 0.0001f);
  return retval;
}
