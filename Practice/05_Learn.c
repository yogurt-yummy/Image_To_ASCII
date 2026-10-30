// Write a C program that:
// 1. Creates the image[2][3] array shown above.
// 2. Creates the chars array.
// 3. Uses nested loops to visit every pixel.
// 4. Converts each pixel's brightness into an index.
// 5. Prints the corresponding ASCII character.
// 6. Moves to a new line after each row.

#include <stdio.h>

int main()
{

    int pixl_brightness_array[2][3] = {
        {0, 42, 85},
        {127, 170, 212}};

    const char brightness_chars[] = {" .:-=+*#%@"};

    for (int row = 0; row < 2; row++)
    {

        for (int column = 0; column < 3; column++)
        {

            int brightness_index = (255 - pixl_brightness_array[row][column]) * 9 / 255;
            printf("%c\t", brightness_chars[brightness_index]);
        }
        printf("\n");
    }
    // printf("%c is at index 8",brightness_chars[8]);
    return 0;
}