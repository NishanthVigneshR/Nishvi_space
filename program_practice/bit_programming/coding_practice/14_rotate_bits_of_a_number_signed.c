#include <stdio.h>
#include <stdint.h>

int8_t left_to_right_rotation (int8_t num, int rotation) {
        /* Left to right rotation logic.
         * 0000 0111 --> 1000 0011 --> 1000 0000
         * 1 - Take LSB and store it one variable. Do AND operation with 1.
         * 2 - Right shift the variable 1 time.
         * 3 - left shift the result value to sizeof(datatype) times.
         * 4 - Perform OR operation b/w variable and result.
         * 5 - Do it in loop.
         */

        int8_t lsb = 0;
        int i = 0;
        while (i < rotation) {
                lsb = num & 1;
                num = num >> 1;
                lsb = lsb << ((sizeof(int8_t) * 8) -1);
                num = num | lsb;
                i++;
        }
        return num;
}

int8_t right_to_left_rotation (int8_t num, int rotation) {
        /* Right-Left rotation Logic.
         * 0000 0111 --> 0000 1110 --> 0001 1100
         * 1 - Take MSB and store it in temp variable. Left shift 1 sizeof(datatype) - 1 times and do AND operation.
         * 2 - Left shift the number once.
         * 3 - do OR operation between previous MSB and number.
         * 4 - Loop it.
         */

        int8_t msb = 0;
        int i = 0;
        while (i < rotation) {
                msb = 1 << ((sizeof(int8_t) * 8) -1);
                if (num & msb)
                        msb = 1;
                else
                        msb = 0;
                num = num << 1;
                num = num | msb;
                i++;
        }
        return num;
}

int main() {
        int8_t var = 0;
        int n = 0;
        int8_t result = 0;

        printf ("Enter the number\n");
        scanf ("%d", &var);

        printf ("Enter the rotation\n");
        scanf("%d", &n);

        printf ("Provided number is %d and need to rotate %d times\n", var, n);

        result = left_to_right_rotation (var, n);
        printf("Variable %d after %d times L-R rotation is %d\n", var, n, result);

        result = right_to_left_rotation (var, n);
        printf("Variable %d after %d times R-L rotation is %d\n", var, n, result);
}
