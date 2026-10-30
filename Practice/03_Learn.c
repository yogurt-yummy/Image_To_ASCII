// Exercise 3 — Character mapping
// Consider:
// const char chars[] = " .:-=+*#%@";

// Suppose the brightness of a pixel is:
// - 0
// - 128
// - 255
// Which character should represent each brightness?

// Hint: There are 10 characters, indexed from 0 to 9.

#include <stdio.h>

int main()
{

    const char chars[] = " .:-=+*#%@";

    printf("For Brightness of pixl 0 -> We use %c \n", chars[0]);
    printf("For Brightness of pixl 128 -> We use %c \n", chars[4]);
    printf("For Brightness of pixl 255 -> We use %c \n", chars[9]);
    return 0;
}