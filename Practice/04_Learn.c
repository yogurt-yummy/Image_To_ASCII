// Exercise 4 — Your first C implementation
// Create a small C program that:
// 1. Creates an array containing five brightness values.
// 2. Uses a loop to visit each brightness value.
// 3. Converts each brightness into an ASCII character.
// 4. Prints the resulting characters.

#include <stdio.h>

int main(){

    const char chars[] = " .:-=+*#%@";

    int brightness_array[] = {0 , 50 , 128 , 200 , 255};

    for(int i = 0; i < 5; i++){
        int brightness_index = ((255 - brightness_array[i]) * 9) / 255;
        printf("The character for brightess %d is %c .\n",i,chars[brightness_index]);
    }
    return 0;
}