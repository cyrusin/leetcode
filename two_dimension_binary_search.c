#include <stdio.h>
/*binary search in two dimension array.
 *
 * such as:
 *  1 2 8 9
 *  2 4 9 12
 *  4 7 10 13
 *  6 8 11 15
 *
 */

#define bool char
#define true 1
#define false 0

bool Find(int *matrix, int rows, int columns, int target){
    if (matrix == NULL){
        return false;
    }

    bool found = false;
    if (rows > 0 && columns > 0){
        int row = 0;
        int column = columns - 1;
        while (column >= 0 && row < rows){
            int current = matrix[row * columns + column];
            if (current < target) {
                row++;
            }else if (current > target){
                column--;
            }else{
                found = true;
                break;
            }
        }
    }
    return found;
}
int main(void){
    int matrix[] = {1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15};
    int rows = 4, columns = 4;
    int target = 7;
    bool found = Find(matrix, rows, columns, target);

    if (found){
        printf("found\n");
    }else{
        printf("not found\n");
    }

    return 0;
}
