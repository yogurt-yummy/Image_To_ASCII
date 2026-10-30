// Write a C program that:
// 1. Creates a 2D integer array representing a grayscale image with 3 rows and 4 columns.
// 2. Fills it with 12 brightness values ranging from 0 (black) to 255 (white).
// 3. Creates a character array containing these 10 ASCII characters: " .:-=+*#%@".
// 4. Calculates the number of rows and columns using sizeof().
// 5. Uses nested for loops to visit every pixel.
// 6. Converts each pixel's brightness into its corresponding ASCII character.
// 7. Prints the resulting ASCII image while preserving its original row and column structure.
// 8. Prints the number of rows and columns before displaying the ASCII image.
// Write the entire program from scratch in a new C file.

#include <stdio.h>

int main()
{

    char brightness_chars[] = " .:-+*#%&";

    int pixl_brightness_array[3][4] = {
        {21, 42, 63, 212},
        {84, 105, 127, 233},
        {148, 169, 190, 255}};

    int row = sizeof(pixl_brightness_array) / sizeof(pixl_brightness_array[0]);
    int column = sizeof(pixl_brightness_array[0]) / sizeof(pixl_brightness_array[0][0]);

    for (int rows = 0; rows < row; rows++)
    {

        for (int columns = 0; columns < column; columns++)
        {

            int brightness_index = (255 - pixl_brightness_array[rows][columns]) * 9 / 255;
            printf("%c\t", brightness_chars[brightness_index]);
        }
        printf("\n");
    }

    return 0;
}