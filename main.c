/***************************************************************************
*  Author: Maria Fernanda Tafur Rosero
*  Email: mariaf.tafurr@javeriana.edu.co
*  References: All the functions were developed with Miguel Angel Medina Rodriguez, Lina Maria Velásquez Peña and Samuel Niño González
*
*  Mar 11/2024
*
******************************************************************************/

#include <stdio.h>
#include "pagerank.h"
#define ROWS 3293
#define COLS 3293

long double matrix[ROWS][COLS]; 
long double vector_iter[ROWS];
long double vect_eucl[ROWS];
long double vector_resul[ROWS];
long double vector_resulC[ROWS];
int vector_ind[ROWS];

int main(void) {

  long double Alfa = 0.85;
  long double Epsilon = 0.0000001;

  PAGERANK(ROWS, COLS, matrix, Alfa, Epsilon, vector_resul, vector_resulC, vector_ind, vector_iter, vect_eucl);


  return 0;
}