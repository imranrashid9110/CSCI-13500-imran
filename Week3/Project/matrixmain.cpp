#include <iostream>

// Reminder: Information about functions is on the specification PDF

void Print2DArray(const int matrix_local[][3], const int matrix_local_rows_total){

std::cout << "Function Called: Print2DArray" << std::endl; // prints start message for function

for (int row = 0; row < matrix_local_rows_total; row++) { // loops through the rows and time complexity is 0(n)
    std::cout << "[";

    for (int col = 0; col < 3; col++) { // loops through columns and time complexity is 0(n)
        std::cout << matrix_local[row][col]; // prints the values of row and column

        if (col < 2) { // condition to check if its not the last column
            std::cout << "|";
        }
    }

    std::cout << "]" << std::endl; // at the end, the time complexity is 0(n^2) because of the nested loops
    
std::cout << "End of Print2DArray function" << std::endl;
}

void MatrixAddition(const int matrix_one[][3], const int matrix_one_rows_total,
                    const int matrix_two[][3], const int matrix_two_rows_total)
    {
        std::cout << "Function name: MatrixAddition" << std::endl; // introduces the function
        int added_matrix[3][3]; // make a 3x3 matrix and stores the values
        for (int row = 0; row < matrix_one_rows_total; row++) {
            for (int col = 0; col < 3; col++) { // loops through the columns one by one
                added_matrix[row][col] = matrix_one[row][col] + matrix_two[row][col]; // it adds the results of each position of the matrix when going through the loop
            }
        } // the time complexity is 0(n^2)

        Print2DArray(added_matrix, matrix_one_rows_total); // shows the total added matrix
        std::cout << "End of MatrixAddition" << std::endl; // end of the function




    }

void TransposeMatrix(const int matrix_local[][3], const int matrix_local_rows_total){
    std::cout << "Function name: TransposeMatrix" << std::endl; // introduces the function

    int flipped_matrix[3][3]; // makes a 3x3 matrix
    for (int row = 0; row < matrix_local_rows_total; row++) {  // loops through each row 
        for (int col = 0; col < 3; col++) {  // loops through each column 
            flipped_matrix[col][row] = matrix_local[row][col];  // swaps the value of row and columns because thats what traspose does
        }  
    }  

     std::cout << "Transposed Matrix" << std::endl; // gives it a name before it trasposes the matrix
    for (int row = 0; row < 3; row++) {  // loops through each row 
        std::cout << "[";  

        for (int col = 0; col < matrix_local_rows_total; col++) {  // loops through each column 
            std::cout << flipped_matrix[row][col];  // prints the values of row and column

            if (col < matrix_local_rows_total - 1) {  // checks if this is not the last column
                std::cout << "|";  
            }  // 
        }  // colomn loop is finished

        std::cout << "]" << std::endl; 
    }  // loop of row and column is done and time complexirt is 0(n^2) because there is a row and colmn loop, nested loops

     std::cout << "End of TransposeMatrix function" << std::endl;  // ends the function, idk why the std is giving me a error
}

void Determinant(const int matrix_local[][3], const int size){
    std::cout << "Function name: Determinant" << std::endl;  // introduces the function

    if (size != 2 && size != 3) {  // checks if the matrix is not 2x2 or 3x3 using a and conditional
        std::cout << "Invalid input. Please enter a 2x2 or 3x3 matri" << std::endl; // prints invalid input if the user doesnt input a 2x2 or 3x3 matrix


    } else if (size == 2) {  // checks if the matrix is 2x2
        int det = (matrix_local[0][0] * matrix_local[1][1]) - (matrix_local[0][1] * matrix_local[1][0]);  // uses the 2x2 formula
        std::cout << "Determinant =  " << det << std::endl;  // prints the 2x2 determinant 
        } else {  // this will be used if the matrix is 3x3
            int det =
        (matrix_local[0][0] * ((matrix_local[1][1] * matrix_local[2][2]) - (matrix_local[1][2] * matrix_local[2][1]))) -
        (matrix_local[0][1] * ((matrix_local[1][0] * matrix_local[2][2]) - (matrix_local[1][2] * matrix_local[2][0]))) +
        (matrix_local[0][2] * ((matrix_local[1][0] * matrix_local[2][1]) - (matrix_local[1][1] * matrix_local[2][0])));  // this is the 3x3 formula for determinant
        std::cout << "Determinant: " << det << std::endl; // prints the 3x3 det 
        
        }
        std::cout << "End of determinate function" << std::endl;  // ends the function
    } // the time complexity is 0(1) because are arent any loops
}


void SearchValue(const int matrix_local[][3], const int rows, const int target){
    std::cout << "Function name: SearchValue" << std::endl;  // introduces the function

    bool found_target = false;  // starts as false because the target has not been found yet
        for (int row = 0; row < rows; row++) {  // loops through the row
    for (int col = 0; col < 3; col++) {  // loops through the column
        if (matrix_local[row][col] == target) {  // checks if the value of row and column is equal to the target
            std::cout << "Found " << target << " at [" << row << "][" << col << "]" << std::endl;  // prints where the target was found
            found_target = true;  // its set to true because the target was found
        }  // ends the if statement
    }  // ends the column loop
}  // ends the row loop
if (found_target == false) {  // checks if its false
    std::cout << target << " not found in the matrix. " << std::endl;  // 
}  // time complexity is 0(n^2) because of the nested loops

    std::cout << "End of search value function" << std::endl;  // end of function
}

void MatrixMultiplication(const int matrix_a[][3], const int matrix_b[][3], 
                    const int rows_a, const int cols_a, 
                    const int rows_b, const int cols_b){
    
    std::cout << "Function name: MatrixMultiplication" << std::endl;  // introduces the function
    
    if (cols_a != rows_b) { // checks if they match
        std::cout << "Invalid dimensions. Matrix cannot be multiplied." << std::endl;  // prints error if they dont match
        } else {  // runs if the matrices can be multiplied


    int matrix[3][3] = {0};  // creates a 3x3 matrix and with all values = 0 
    for (int row = 0; row < rows_a; row++) {  // loops through the row
        for (int col = 0; col < cols_b; col++) {  // loops through the column
            for (int spot = 0; spot < cols_a; spot++) {  // value increases by 1 and loops through the columns of matrix_a and rows of matrix_b
                matrix[row][col] += matrix_a[row][spot] * matrix_b[spot][col];  // multiplies and adds to the answer by +=
            }  
        }  
    }  // time complexity is 0(n^3) it has 3 loops in the nested loop

    std::cout << "Multiplied Matrix:" << std::endl;  // gives a message before printing the multiplied matrix
    Print2DArray(matrix, rows_a); // i used chatgpt for this line, i didnt know what the next step was after the multiplication, so i just printed the multiplied matrix using the print2darray function

    }  //

    std::cout << "End of matrix multiplication function" << std::endl;  // ends the function
}

int main(){
    // Use these two matrices for basic testing.

    int testing_matrix_one[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    int testing_matrix_two[3][3] = {
        {12,65,82},
        {83,2,8},
        {10,96,67}
    };
    Print2DArray(testing_matrix_one, 3);

MatrixAddition(testing_matrix_one, 3, testing_matrix_two, 3);

TransposeMatrix(testing_matrix_one, 3);

Determinant(testing_matrix_one, 3);

SearchValue(testing_matrix_one, 3, 5);

MatrixMultiplication(testing_matrix_one, testing_matrix_two, 3, 3, 3, 3);


// Not used in this class, but it is nice to know other ways to find the size of primitive array.
// This method below is similar to how you will find the size of vectors (future material)
    // DO NOT USE IN THIS PROJECT FUNCTION, but you could test it yourselves.
    // int size_row_one = std::size(testing_matrix_one);
    // int size_col_one = std::size(testing_matrix_one[0]);


    // This is a way to find the dimensions of an array without hardcoding values.
    // It dynamically reflects the array's actual declared size, so if you change
    // the array dimensions, the calculation updates automatically.
    //
    // How it works:
    //
    // To find the number of ROWS:
    //   sizeof(testing_matrix_one)      = total bytes of the whole array = 3*9*4 = 108 bytes
    //   sizeof(testing_matrix_one[0])   = total bytes of one row         = 1*9*4 =  36 bytes
    //   108 / 36 = 3 rows
    
    int size_row_one = sizeof(testing_matrix_one)/sizeof(testing_matrix_one[0]);

    // To find the number of COLUMNS:
    //   sizeof(testing_matrix_one[0])      = total bytes of one row          = 1*9*4 = 36 bytes
    //   sizeof(testing_matrix_one[0][0])   = total bytes of one element(int) = 1*4   =  4 bytes
    //   36 / 4 = 9 cols
    
    int size_col_one = sizeof(testing_matrix_one[0])/sizeof(testing_matrix_one[0][0]);

    std::cout << "row: " << size_row_one<< " col: " << size_col_one<< std::endl << std::endl;

    Print2DArray(testing_matrix_one, size_row_one);

    return 0; 
}