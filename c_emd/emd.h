/**************************************/
/* EMD - compute earth mover distance */
/* Header File                        */
/**************************************/

#define EPSILON 1e-15
#define FALSE 0
#define TRUE 1

double emd(int n_x, double *weight_x,
           int n_y, double *weight_y,
           double **cost);

double **array_malloc(int rows, int cols);
void array_free(double **X, int rows);
double *vector_malloc(int n);
double *vector_copy(double *v, int n);
void vector_free(double *v);

//double vector_sum(double *v, int n);

enum COLOR {
    WHITE = 0,
    GRAY,
    BLACK
};

struct basic_variable {
    int row;
    int col;
    double flow;
    struct adj_node *adjacency;
    struct adj_node *current_adj;
    struct basic_variable *back_ptr;
    enum COLOR color;
};

struct adj_node {
    struct basic_variable *variable;
    struct adj_node *next;
};
