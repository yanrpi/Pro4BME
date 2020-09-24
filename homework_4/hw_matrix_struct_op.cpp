/*  -----------------------------------
    C++ coding practice
    
    By Pingkun Yan, Ph.D.
    Department of Biomedical Engineering
    Rensselaer Polytechnic Institute
    ----------------------------------- */

#include <iostream>
#include <fstream>

/* --------------------------------------
        Function declarations
   -------------------------------------- */

struct Matrix {
    double* X;
    int n_columns, n_rows;
};

struct Vector {
    double* X;
    int dimension;
};

void Print_Vector(Vector vec) {
    for (int i=0; i<vec.dimension; i++) {
        std::cout << vec.X[i] << "\t";
    }
    std::cout << std::endl << std::endl;
}


void Print_Matrix(Matrix mat) {
    for (int i=0; i<mat.n_rows; i++) {
        for (int j=0; j<mat.n_columns; j++) {
            // ----- Fix the line below ------
            std::cout << mat.X[i*mat.n_columns + j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void DefineVector(Vector &vec, int dimension) {
    vec.dimension = dimension;
    vec.X = new double[dimension];
}


void DefineMatrix(Matrix &mat, int rows, int columns) {
    mat.n_rows = rows;
    mat.n_columns = columns;
    mat.X = new double[rows * columns];
}


void LoadMatrix(std::string filename, Matrix &mat) {
    std::ifstream infile(filename, std::ifstream::in);

    // Load matrix into mat 
    int rows=0, columns=0;
    infile >> rows;
    infile >> columns;

    // Define matrix
    DefineMatrix(mat, rows, columns);

    // read data from file
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            infile >> mat.X[i*columns + j];
}


void LoadVector(std::string filename, Vector &vec) {
    std::ifstream infile(filename, std::ifstream::in);

    // Load matrix into mat 
    int dimension = 0;
    infile >> dimension;

    // Define vector
    DefineVector(vec, dimension);

    // read data from file
    for (int i = 0; i < dimension; i++)
        infile >> vec.X[i];
}


// %%%%%%% Add your own functions below %%%%%%%%





/* -------------------------------------
    Main function starts below 
   ------------------------------------- */
int main(int argc, char* argv[]) {
    // Declare matrix A and B
    Matrix A, B;

    // Load matrix into A and B 
    LoadMatrix("matrix_A.txt", A);
    LoadMatrix("matrix_B.txt", B);
    
    // Print the loaded matrics
    std::cout << "Matrix A:" << std::endl;
    Print_Matrix(A);
    std::cout << "Matrix B:" << std::endl;
    Print_Matrix(B);



    /*  ---------------------------------------------------------------------
        Task #1: Matrix addition
        1. Declare and implement your own function above main() to add matrics A and B, 
            and put output into a new matrix Y.
            (*Optional: modify your addition function to support
            both addition and subtraction, with an additional
            input parameter to control the operation.)
        2. Call your function here
        3. Use the Print_Matrix() function to print out the result Y
        4. Add the screenshot of output to your submission file with correspoinding illustration.
        5. Move to Task #2
    */



    /*  ---------------------------------------------------------------------
        Task #2: Matrix transpose
        1. Declare and implement your own function above main() to transpose a matrix
            and put output into T. For example, a matrix of
            1 2 3
            4 5 6
            will become
            1 4
            2 5
            3 6
            after transpose operation.
        2. Call your function here to transpose A
        3. Use the Print_Matrix() function to print out the result T
        4. Add the screenshot of output to your submission file with correspoinding illustration.
        5. Repeat 2-4 for matrix B
        5. Move to Task #3
    */


    Vector a;
    LoadVector("vector_a.txt", a);
    // Print the loaded vector a
    std::cout << "Vector a:" << std::endl;
    Print_Vector(a);

    /*  ---------------------------------------------------------------------
        Task #3:
        1. Declare and implement your own function above main() to multiply a matrix with a vector.
        2. Call your function here to multiply A and a
        3. Use the Print_Vector() function to print out the result y
        4. Add the screenshot of output to your submission file with correspoinding illustration.
        5. Repeat steps 2-4 by multiplying matrix B and vector a
        6. Move to Task #4
    */


    /*  ---------------------------------------------------------------------
        Task #4: (no coding required in this file)
        1. Create your own 7x6 matrices and a length of 7 vector
        2. Replace the matrics and vector in the text files (*.txt) with your own creation
        3. Run your program to see if your code gives correct answers. Fix problems
            if there is any.
        4. Add the screenshots of output to your submission file with correspoinding illustration.
        5. Move to Task #5 
    */


    /*  ---------------------------------------------------------------------
        Task #5: (no coding required in this file)
        Compare the code in this homework assignment (#4) with the code in the previous 
        homework assingment (#3). Describe the main differences and list the pros and cons
        of each style.
    */

}