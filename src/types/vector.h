/**
 * @brief Functions and structures to represent a vector.
 * @author George Peppard
 */
#ifndef CAVERNA_VECTOR_H
#define CAVERNA_VECTOR_H

#include <assert.h>
#include <stdint.h>

/**
 * @brief A vector data structure.
 */
struct vector {
  uint32_t size;              /**< the current element count in the vector */
  uint32_t capacity;          /**< the capacity of the vector */
  char *data;                 /**< the data stored in the vector stored as a char (as they are always 8 bytes) */
  uint32_t element_size;      /**< the size of each element in the vector */
};

/**
 * @brief Initialises a vector.
 *
 * The vector to initialise is passed as a parameter so it can be both on the
 * heap or on the stack.
 *
 * @param vect            the vector struct to initialise
 * @param capacity        the capacity of the vector
 * @param element_size    the size of each element in the vector
 */
void vector_init(struct vector *vect, uint32_t capacity, uint32_t element_size);

/**
 * @brief Adds an element to a vector.
 *
 * @param vect    the vector to add to
 * @param elem    a pointer to the element to add
 */
void vector_add(struct vector *vect, void *elem);

/**
 * @brief Removes an element from the vector.
 *
 * @param vect    the vector to remove an element from
 * @param index   the index of the element to remove
 */
void vector_remove(struct vector *vect, uint32_t index);

/**
 * @brief Gets an element in the vector at the specified index.
 *
 * @param vect    the vector to get the element from
 * @param index   the index of the element to fetch
 *
 * @returns the element at the specified index in the vector
 */
void *vector_get(struct vector *vect, uint32_t index);

/**
 * @brief Tears down a vector and releases any memory back to the computer.
 *
 * After the vector is destroyed, the variable (or pointer) should be set to
 * NULL to prevent it from being used again, which will cause errors.
 *
 * @param vect    the vector to destroy
 */
void vector_destroy(struct vector *vect);

#endif // CAVERNA_VECTOR_H
