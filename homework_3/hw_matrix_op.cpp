#include <iostream>
#include <fstream>

#define PRINT 0

#define FILENAME "matrix_add_1.txt"
//#define FILENAME "matrix_add_2.txt"
//#define FILENAME "matrix_mul_1.txt"
//#define FILENAME "matrix_mul_2.txt"

/*  ---------------------------------------------------------------------
    Task #1:
    1. Compile the code and run
    2. Check the output
    3. Change to your own name and repeat 1&2 above
    4. Screen capture the output on your terminal and put into your report
    5. Move to Task #2
 */


/*  ---------------------------------------------------------------------
    Task #2:
    1. Change Line 4 of the code to
        #define PRINT 1
    2. Compile the code and run
    3. Fix this print function to output the items of mat to your terminal in a nice format.
    For example, the first matrix A may be printed as
    >>
        1   2   3   4
        4   3   2   1
    4. Move to Task #3
 */
void Print_Matrix(double** mat, int n_row, int n_col) {
    for (int i=0; i<n_row; i++) {
        for (int j=0; j<n_col; j++) {
            // ----- Fix the line below ------
            std::cout << mat[i][j] << std::endl;
        }
        // ----- Add printing newline here if necessary -----
    }
}


/*  ---------------------------------------------------------------------
    Task #3:
    1. Complete this matrix addition function by using loops
        without any hard-coded dimension numbers

    - input: 
    double** mat_A, int row_A, int col_A
    double** mat_B, int row_B, int col_B

    - output: 
    double** &mat_Y, int &row_Y, int &col_Y

        Step 1. Compute the output size row_Y and col_Y
        Step 2. Allocate memory for mat_Y using "new" by following the example in main() for A & B
        Step 3. Use loops to compute matrix addition

    2. Compile and run your code.  Check your output and fix any issues.
    3. Record your screen output and put into the submission document
    4. Move to Task #4
*/
int Add_Matrics(double** mat_A, int row_A, int col_A,
                double** mat_B, int row_B, int col_B,
                double** &mat_Y, int &row_Y, int &col_Y) {

    // your code starts here


    // your code ends here

    return 0;
}


/*  ---------------------------------------------------------------------
    Task #4:
    1. Comment Line 6 of this code
    2. Uncomment Line 7 of this code
    3. Compile and run to test your code. Check your output.
    4. Record your screen output and put into the submission document
    5. Move to Task #5
 */



/*  ---------------------------------------------------------------------
    Task #5:
    1. Complete this matrix multiplication function by using loops
        without any hard-coded dimension numbers

    - input: 
    double** mat_A, int row_A, int col_A
    double** mat_B, int row_B, int col_B

    - output: 
    double** &mat_Y, int &row_Y, int &col_Y

        Step 1. Compute the output size row_Y and col_Y
        Step 2. Allocate memory using "new" by following the example in main() for A & B
        Step 3. Use loops to compute matrix multiplication

    2. Comment Line 7 of this code
    3. Uncomment Line 8 of this code
    4. Compile and run your code.  Check your output and fix any issues.
    5. Record your screen output and put into the submission document
    6. Move to Task #6
*/
int Mul_Matrics(double** mat_A, int row_A, int col_A,
                double** mat_B, int row_B, int col_B,
                double** &mat_Y, int &row_Y, int &col_Y) {

    // your code starts here

    // your code ends here

    return 0;
}


/*  ---------------------------------------------------------------------
    Task #6:
    1. Comment Line 8 of this code
    2. Uncomment Line 9 of this code
    3. Compile and run to test your code. Check your output.
    4. Record your screen output and put into the submission document
    5. Congratulations! You have successfully finished your matrix operation programming!
 */


int main(int argc, char* argv[]) {
    // Change "My Name" to your own name
    if (PRINT == 0) {
        std::cout << std::endl;
        std::cout << "This is the C++ matrix operation code of " << "My Name" << std::endl;
        std::cout << std::endl;
    }
    
    std::ifstream infile(FILENAME, std::ifstream::in);

    std::string operation;
    std::getline(infile, operation);
    if (PRINT) {
        std::cout << "Current operation: " << operation << std::endl;
    }
    
    // Load matrix into A 
    int n_rows_A, n_columns_A;
    infile >> n_rows_A;
    infile >> n_columns_A;

    // Allocate memory for matrix A
    double** A = new double*[n_rows_A];
    for(int i=0; i<n_rows_A; i++)
        A[i] = new double[n_columns_A];    

    // read data from file
    for (int i = 0; i < n_rows_A; i++)
        for (int j = 0; j < n_columns_A; j++)
            infile >> A[i][j];

    // Load matrix into B 
    int n_rows_B, n_columns_B;
    infile >> n_rows_B;
    infile >> n_columns_B;

    // Allocate memory for matrix B
    double** B = new double*[n_rows_B];
    for(int i=0; i<n_rows_B; i++)
        B[i] = new double[n_columns_B];    

    for (int i = 0; i < n_rows_B; i++)
        for (int j = 0; j < n_columns_B; j++)
            infile >> B[i][j];

    // Print the loaded matrics
    if (PRINT) {
        std::cout << "Matrix A:" << std::endl;
        Print_Matrix(A, n_rows_A, n_columns_A);

        std::cout << "Matrix B:" << std::endl;
        Print_Matrix(B, n_rows_B, n_columns_B);
    }

    double** Y = NULL;
    int n_rows_Y=0, n_columns_Y=0;

    if (operation.compare("add") == 0)
        Add_Matrics(A, n_rows_A, n_columns_A,
                    B, n_rows_B, n_columns_B,
                    Y, n_rows_Y, n_columns_Y);

    if (operation.compare("mul") == 0)
        Mul_Matrics(A, n_rows_A, n_columns_A,
                    B, n_rows_B, n_columns_B,
                    Y, n_rows_Y, n_columns_Y);

    if (PRINT) {
        if (n_rows_Y > 0 && n_columns_Y > 0)
            std::cout << "The result of " << operation << " is:" << std::endl;
        Print_Matrix(Y, n_rows_Y, n_columns_Y);
    }

    //Free the allocated memory in sub-arrays
    for(int i = 0; i < n_rows_A; i++) {
        delete[] A[i];
    }
    //Free the array of pointers
    delete[] A;

    //Free the allocated memory in sub-arrays
    for(int i = 0; i < n_rows_B; i++) {
        delete[] B[i];
    }
    //Free the array of pointers
    delete[] B;


    //Free the allocated memory in sub-arrays
    for(int i = 0; i < n_rows_Y; i++) {
        delete[] Y[i];
    }
    //Free the array of pointers
    if (Y)
        delete[] Y;
}