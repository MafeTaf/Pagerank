#ifndef PAGERANK_H
#define PAGERANK_H

int number_nodes(); 
void read_matrixA(int ROWS, int COLS, long double (*datos)[COLS]);
void print_matrix(int COLS,long double (*matrix)[COLS], int ROWS);
void print_vectorI(long double(*vector), int ROWS);
void remove_nodes(int ROWS, int i, long double (*matrix)[ROWS]);
void remove_nodesAbs(int ROWS, int COLS, long double (*matrix)[COLS]);
void stochastic_matrix(int ROWS, int COLS, long double (*matrix)[COLS],long double alfa);
void create_vectorI(int ROWS, long double(*vector));
void euclidean_vector(long double(*vectresult), int ROWS, long double(*vector), long double(*vectEu));
long double euclidean_distance(int ROWS, long double(*vector));
void transpose_matrix(int COLS,long double (*matrix)[COLS], int ROWS);
void mult_matrix_vector(int COLS,long double (*matrix)[COLS], long double(*vectorproba),long double(*result));
void copypaste_vectorR(int ROWS,long double(*vector), long double(*vector2));
void iterativae_matrix(int COLS,long double (*matrix)[COLS], int ROWS, long double(*vector), long double epsilon, long double(*vectoresult), long double(*vectEu));
void order_ranking(long double(*vectoresult), int ROWS, int COLS);
void zeros_matrix( int ROWS,long double (*matrix)[ROWS], int COLS);
void verification_index(long double(*vectoresult_c), long double(*vectoresult), int ROWS, int(*vecInd));
void print_vectorRanking(long
double(*vectoresult_c), int ROWS, int(*vecInd));
void final_score(long double(*vectoresult), long double(*vectresult_c), int ROWS,int(*vecInd), int COLS);
void PAGERANK (int ROWS, int COLS, long double (*matrix)[COLS], long double alfa, long double epsilon, long double(*vectresult), long double(*vectresult_c), int(*vecInd),long double(*vector),long double(*vectEu));
void porcentuar(int COLS, int i, long double (*matrix)[COLS], long double suma);
void porcentaje(int ROWS, int COLS, long double (*matrix)[COLS]);

#endif