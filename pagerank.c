#include <stdio.h>
#include <math.h>
#include "pagerank.h"

/*FN****************************************************************************
*
*   int number_nodes();
*
*   Function Return Type: int
*
*   Purpose: Return number of columns and rows of the matrix
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024   Maria Fernanda Tafur Rosero
*
*******************************************************************************/
int number_nodes() 
{
  FILE *archivo;
  int nodos_totales;
  archivo = fopen("matriz_resultante1.txt", "r");
  fscanf(archivo, "%d", &nodos_totales);
  fclose(archivo);
  return nodos_totales;
}
/*FN****************************************************************************
*
*   void read_matrixA(int ROWS, int COLS, long double (*datos)[COLS]);
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Read and save matrix from matrix.txt file
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024   Maria Fernanda Tafur Rosero
*
*******************************************************************************/
void read_matrixA(int ROWS, int COLS, long double (*datos)[COLS])
{
  FILE *archivo;
  archivo = fopen("matriz_resultante1.txt", "r");
  int nodos_totales;
  nodos_totales = number_nodes();
  char buffer[100];
  fgets(buffer, sizeof(buffer), archivo);
   for (int i = 0; i < nodos_totales; i++)
     {
    for (int j = 0; j < nodos_totales; j++){
      fscanf(archivo, "%Lf\t", &datos[i][j]);
    }
  }

  fclose(archivo);
}
/*FN****************************************************************************
*
*   void print_matrix(int COLS,long double (*matrix)[COLS], int ROWS);
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Print the matrix
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024   Maria Fernanda Tafur Rosero
*
*******************************************************************************/
void print_matrix(int COLS,long double (*matrix)[COLS], int ROWS) 
{
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%.3Lf\t", matrix[i][j]);
    }
    printf("\n");
  }
}
/*FN****************************************************************************
*
*   void zeros_matrix( int ROWS,long double (*matrix)[ROWS], int COLS);
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Create the zeros matrix
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024   Maria Fernanda Tafur Rosero
*
*******************************************************************************/
void zeros_matrix( int ROWS,long double (*matrix)[ROWS], int COLS) 
{
  // Llenar la matriz con ceros
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      matrix[i][j] = 0.0;
    }
  }
}
/*FN****************************************************************************
*
*   void print_vectorI(long double(*vector), int rows);
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Print the vector
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024   Maria Fernanda Tafur Rosero
*
*******************************************************************************/
void print_vectorI(long double(*vector), int ROWS) 
{
    for (int i = 0; i < ROWS; i++) {
        printf("%.3Lf\n", *(vector + i)); 
    }
    printf("\n");
}
/*FN****************************************************************************
*
*   void remove_nodes(int ROWS, int i, long double (*matrix)[ROWS]);
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Performs the division by the total number of nodes
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024   Maria Fernanda Tafur Rosero
*
*******************************************************************************/
void remove_nodes(int ROWS, int i, long double (*matrix)[ROWS]) {
  for (int r = 0; r < ROWS; r ++) {
    matrix[i][r] = (1.0 / ROWS);
  }
}
/*FN****************************************************************************
*
*   void remove_nodesAbs(int ROWS, int COLS, long double (*matrix)[COLS]);
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Remove absorbing nodes from the matrix
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024   Maria Fernanda Tafur Rosero
*******************************************************************************/
void remove_nodesAbs(int ROWS, int COLS, long double (*matrix)[COLS]) 
{
  for (int i = 0; i < ROWS; i++) {
  long double addFila = 0.0;
  for (int j = 0; j < COLS; j++) {
      addFila += matrix[i][j];
  }
    printf("Suma de la fila %d: %.5Lf\n", i, addFila);
    if (addFila == 0.0) 
    {
      remove_nodes(COLS, i, matrix);
    }
  }
} 
/*FN****************************************************************************
*
*   void stochastic_matrix(int ROWS, int COLS, long double (*matrix)[COLS],long double alfa);
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Convert the stochastic matrix and distribute the probability
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024  Maria Fernanda Tafur Rosero
*
*******************************************************************************/
void stochastic_matrix(int ROWS, int COLS, long double (*matrix)[COLS],long double alfa) 
{
          for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
              matrix[i][j] = (alfa * matrix[i][j]) + (1.0 - alfa) * (1.0 / COLS);
        }
    }
}
/*FN****************************************************************************
*
*   void create_vectorI(int ROWS, long double(*vector));
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Create the iterative vector
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024  Maria Fernanda Tafur Rosero
*
*******************************************************************************/
void create_vectorI(int ROWS, long double(*vector)) 
{
  for (int i = 0; i < ROWS; i++) {
    vector[i] = (1.0 / ROWS);
  }
  }
/*FN****************************************************************************
*
*   void euclidean_vector(long double(*vectresult), int ROWS, long double(*vector), long double(*vectEu));
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Create the euclidean vector
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024  Maria Fernanda Tafur Rosero
*
*******************************************************************************/
void euclidean_vector(long double(*vector_resul), int ROWS, long double(*vector), long double(*vect_eucl)) 
{
  for (int i = 0; i < ROWS; i++) 
  {
      vect_eucl[i] = (vector[i] - vector_resul[i]) * (vector[i] - vector_resul[i]);
  }
}
/*FN****************************************************************************
*
*   long double euclidean_distance(int ROWS, long double(*vector));
*
*   Function Return Type: long double
*
*   Purpose: Gives the distance of the euclidean vector
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024   Maria Fernanda Tafur Rosero
*
*******************************************************************************/
long double euclidean_distance(int ROWS, long double(*vector)) 
{
  long double distance = 0;
  long double add = 0;
  for (int i = 0; i < ROWS; i++) 
  {
    add += vector[i];
  }
  distance = sqrt(add);
  return distance;
}
/*FN****************************************************************************
*
*   void transpose_matrix(int COLS,long double (*matrix)[COLS], int ROWS);
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Transpose the stochastic matrix
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*  Mar 11/2024  Maria Fernanda Tafur Rosero
*
*******************************************************************************/
void transpose_matrix(int COLS,long double (*matrix)[COLS], int ROWS) 
{
  long double temp;
  for (int i = 0; i < ROWS; i++) {
    for (int j = i + 1; j < COLS; j++) {
      temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
}
/*FN****************************************************************************
*
*   void mult_matrix_vector(int COLS,long double (*matrix)[COLS], long double(*vectorproba),long double(*result));
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Create the iterative vector
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024   Maria Fernanda Tafur Rosero
*
*******************************************************************************/
void mult_matrix_vector(int COLS,long double (*matrix)[COLS], long double(*vectorproba),long double(*result)) {
  for (int i = 0; i < COLS; ++i) {
    result[i] = 0;
    for (int j = 0; j < COLS; ++j) {
      result[i] += matrix[i][j] * vectorproba[j];
    }
  }
}
/*FN****************************************************************************
*
*   void copypaste_vectorR(int ROWS,long double(*vector), long double(*vector2));
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Copy the resulting vector to change it in each iteration
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024  Maria Fernanda Tafur Rosero
*
*******************************************************************************/
void copypaste_vectorR(int ROWS,long double(*vector), long double(*vector2)) {
  for (int i = 0; i < ROWS; i++) {
    vector[i] = vector2[i];
  }
}
/*FN****************************************************************************
*
*   void iterativae_matrix(int COLS,long double (*matrix)[COLS], int ROWS, long double(*vector), long double epsilon, long double(*vectoresult), long double(*vectEu)) ;
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Iterates the multiplication of matrix by vector until the Euclidean distance is hands than epsilon
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024  Maria Fernanda Tafur Rosero
*
*******************************************************************************/
void iterativae_matrix(int COLS,long double (*matrix)[COLS], int ROWS, long double(*vector), long double epsilon, long double(*vector_resul), long double(*vect_eucl)) {
  long double distance;
  long double temp[ROWS];
  copypaste_vectorR(ROWS,temp, vector);
  do {
    mult_matrix_vector(ROWS,matrix, temp, vector_resul);
    euclidean_vector(vector_resul, ROWS, temp, vect_eucl);
    copypaste_vectorR(ROWS,temp, vector_resul);
    distance = euclidean_distance(ROWS, vect_eucl);
  } while (distance > epsilon);
}
/*FN****************************************************************************
*
*   void order_ranking(long double(*vectoresult), int ROWS, int COLS);
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Order the vector resulting from the ranking
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024   Maria Fernanda Tafur Rosero
*
*******************************************************************************/
void order_ranking(long double(*vectoresult), int ROWS, int COLS) {
  
      for (int i = 0; i < ROWS - 1; i++) {
          for (int j = i + 1; j < ROWS; j++) {
              if (vectoresult[i] < vectoresult[j]) {
                  long double temp = vectoresult[i];
                  vectoresult[i] = vectoresult[j];
                  vectoresult[j] = temp;
              }
          }
      }
  }

/*FN****************************************************************************
*
*   void verification_index(long double(*vectoresult_c), long double(*vectoresult), int ROWS, long double(*vecInd));
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Verify with the copy of the ranking vector, the position of the largest node
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024  Maria Fernanda Tafur Rosero
*
*******************************************************************************/
void verification_index(long double(*vectoresult_c), long double(*vectoresult), int ROWS, int (*vecInd)) 
{
  int indiceUtilizado[ROWS]; 
  for (int i = 0; i < ROWS; i++) {
      indiceUtilizado[i] = 0; 
  }

  for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < ROWS; j++) {
          if (vectoresult_c[i] == vectoresult[j] && !indiceUtilizado[j]) {
              vecInd[i] = j;
              indiceUtilizado[j] = 1; 
              break; 
          }
      }
  }  
}
/*FN****************************************************************************
*
*   void print_vectorRanking(long double(*vectoresult_c), int ROWS, long double(*vecInd));
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Print ranking vector
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024   Maria Fernanda Tafur Rosero
*******************************************************************************/
void print_vectorRanking(long double(*vectoresult_c), int ROWS, int(*vecInd)) {
  for (int i = 0; i < ROWS; i++) {
    printf("\n");
    printf("Nodo ");
    printf("%.3d\t", vecInd[i]+1);
    printf("\n");
    printf("Puntaje ");
    printf("%.10Lf\t", vectoresult_c[i]);
    printf("\n");
  }
}
/*FN****************************************************************************
*
*   void final_score(long double(*vectoresult), long double(*vectresult_c), int ROWS,long double(*vecInd), int COLS);
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Prints the vector organized from highest to lowest with the nodes ranked
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024   Maria Fernanda Tafur Rosero
*
*******************************************************************************/
void final_score(long double(*vector_resul), long double(*vector_resulC), int ROWS, int(*vector_ind), int COLS) {
  copypaste_vectorR(ROWS,vector_resulC, vector_resul);
  order_ranking(vector_resulC, ROWS, COLS);
  verification_index(vector_resulC, vector_resul, ROWS, vector_ind);
  print_vectorRanking(vector_resulC, ROWS, vector_ind);
}

/*FN****************************************************************************
*
*   void porcentuar(int COLS, int i, long double (*matrix)[COLS], long double suma);
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Give percentage to nodes given 0 and 1
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024   Maria Fernanda Tafur Rosero
*
*******************************************************************************/

void porcentuar(int COLS, int i, long double (*matrix)[COLS], long double suma) {
  for (int r = 0; r < COLS; r++) {
    if (suma == 0) {
    } else {
      matrix[i][r] = (matrix[i][r] / suma);
    }
  }
}

/*FN****************************************************************************
*
*  void porcentaje(int ROWS, int COLS, long double (*matrix)[COLS]);
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Gives percentages
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024   Maria Fernanda Tafur Rosero
*
*******************************************************************************/

void porcentaje(int ROWS, int COLS, long double (*matrix)[COLS]) {
  for (int i = 0; i < ROWS; i++) {
    long double sumaFila = 0.00;
    for (int j = 0; j < COLS; j++) {
      sumaFila += matrix[i][j];
    }
    porcentuar(COLS, i, matrix, sumaFila);
  }
}
/*FN****************************************************************************
*
*   void PAGERANK (int ROWS, int COLS, long double (*matrix)[COLS], long double alfa, long double epsilon, long double(*vectresult), long double(*vectresult_c), int (*vecInd),long double(*vector),long double(*vectEu));
*
*   Function Return Type: The function doesn't return any value
*
*   Purpose: Results in ranking
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Mar 11/2024   Maria Fernanda Tafur Rosero
*
*******************************************************************************/
void PAGERANK (int ROWS, int COLS, long double (*matrix)[COLS], long double alfa, long double epsilon, long double(*vector_resul), long double(*vectresult_c), int (*vecInd),long double(*vector),long double(*vectEu))
{
  printf("Matriz inicial\n");
  zeros_matrix(COLS, matrix, ROWS);

  read_matrixA(COLS, ROWS, matrix);

  porcentaje(ROWS,COLS,matrix);

  remove_nodesAbs(COLS, ROWS, matrix);

  stochastic_matrix(ROWS, COLS, matrix, alfa);

  remove_nodesAbs(COLS, ROWS, matrix);

  create_vectorI(ROWS, vector);

  transpose_matrix(COLS, matrix, ROWS);
  //print_vectorI(vector, ROWS);
  printf("\n");
  printf("Ranking\n");
  iterativae_matrix(COLS, matrix, ROWS, vector, epsilon, vector_resul,vectEu);
  //print_vectorI(vectresult, ROWS);
  final_score(vector_resul, vectresult_c, ROWS, vecInd, COLS);
}