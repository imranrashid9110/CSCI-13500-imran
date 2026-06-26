#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int arraySize3 = 3;
   const int arraySize6 = 6;
   int array3 [arraySize3][arraySize3] = {};
   int array6 [arraySize6][arraySize6] = {};

   cout << "Task 1: 3x3 array and 6x6 array" << endl;

   for (int i = 0; i < arraySize3; i++) {
      for (int k = 0; k < arraySize3; k++) {
         if (i+ k <= arraySize3 - 1) {
            array3[i][k] = 1;
            } else {
            array3[i][k] = 0;
            }
            

            }
         }
   

   for (int i = 0; i < arraySize3; i++) {
      cout << "[" ;
      for (int k = 0; k < arraySize3; k++) {
        cout << array3[i][k];
        if (k != arraySize3 - 1) {
            cout << " |";
         }
      }
      cout << "]" << endl;

    cout << endl;
   }


   for (int i = 0; i < arraySize6; i++) {
      for (int k = 0; k < arraySize6; k++) {
         if (i+ k <= arraySize6 - 1) {
            array6[i][k] = 1;
            } else {
            array6[i][k] = 0;}
            

            }
         }
   

   for (int i = 0; i < arraySize6; i++) {
      cout << "["
      for (int k = 0; k < arraySize6; k++) {
        cout << array6[i][k];
        if (k != arraySize6 - 1) {
            cout << " |";
         }
      }
      cout << "]" << endl;

    cout << endl;

   }

   cout << "Task 2: X shape for 3x3 array and 6x6 array" << endl;

   for (int i = 0; i < arraySize3; i++) {
      for (int k = 0; k < arraySize3; k++) {
         if (i == k || i + k == arraySize3 - 1) {
            array3[i][k] = 1;
            } else {
            array3[i][k] = 0;
            

            }
         }
   }

for (int i = 0; i < arraySize3; i++) {
      cout << "["
      for (int k = 0; k < arraySize3; k++) {
        cout << array3[i][k];
        if (k != arraySize3 - 1) {
            cout << " |";
         }
      }
      cout << "]" << endl;

    cout << endl;
   }

   for (int i = 0; i < arraySize6; i++) {
      for (int k = 0; k < arraySize6; k++) {
         if (i == k || i + k == arraySize6 - 1) {
            array6[i][k] = 1;
            } else {
            array6[i][k] = 0;
            

            }
         }
   }

   for (int i = 0; i < arraySize6; i++) {
      cout << "["
      for (int k = 0; k < arraySize6; k++){
        cout << array6[i][k];
        if (k != arraySize6 - 1) {
            cout << " |";
         }
      }
      cout << "]" << endl;

    cout << endl;
   }

   cout << "Task 3: Vector and sum of values" << endl;

   vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
   };
   int size = 3;
   vector<vector<int>> sums(2, vector<int>(size, 0));

    for (int i = 0; i < size; i++) {
        int rowtotal = 0;
        int columntotal = 0;

        for (int k = 0; k < size; k++) {
            rowtotal += matrix[i][k];
            columntotal = columntotal +matrix[i][k];
        }
        sums[0][1] = rowtotal;
        sums[1][i] = columntotal;

    }
    
    for (int i = 0; i < size; i++) {
        cout << "[";
        for (int k = 0; k < size; k++) {
            cout << sums[i][k];
            if (k != size - 1) {
                cout << " |";

        }
        cout << "]" << endl;

    }

    cout << endl;

    cout << "Task 4:Sum of diagonal values" << endl;

    int diagonal1 = 0;
    int diagonal2 = 0;
    int center = 0;

    for (int i = 0; i < size; i++) {
        diagonal1 = matrix[i][i];
        diagonal2 = diagonal2 + matrix[i][size - 1 - i];

    }
    int total = diagonal1 + diagonal2 - center;

    cout << "Diagonal 1: " << diagonal1 << endl;
    cout << "Diagonal 2: " << diagonal2 << endl;
    cout << "Center: " << center << endl;
    cout << "Total and sum : " << total << endl;

        
    }
        






