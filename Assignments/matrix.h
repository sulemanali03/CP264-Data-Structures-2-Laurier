/*
 -------------------------------------
 File:    matrix.h
 Project: a2
 file description
 -------------------------------------
 Author:  Suleman Ali
 ID:      169044667
 Email:   alix4667@mylaurier.ca
 Version  2024-01-22
 -------------------------------------
 */

#ifndef MATRIX_H_
#define MATRIX_H_

float norm(float *v, int n);
float dot_product(float *v1, float *v2, int n);
void matrix_multiply_vector(float *m, float *v, float *vout, int n);
void matrix_multiply_matrix(float *m1, float *m2, float *m3, int n);

#endif /* MATRIX_H_ */
