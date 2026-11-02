#define STB_IMAGE_IMPLEMENTATION // Defining this marco , so that i could use (along with its implementation)
#include "stb_image.h"           // I am including this header file/library to use the image realted function
#include <stdio.h>               // This is the standard library which we use to do normal stuff like print and more;
#include <conio.h>               // I am including this funciton to use getch , so that the program doesnt close itself in a blink if i open the exe file via double click

int calculate_brightness(int, int, int); // we make this function to calculate brightness of the certain pixel , by taking its channels r , g , b . though this is just a function prototype

int calculate_brightness(int red, int green, int blue)
{

    int brightness;
    brightness = ((green * 59) + (red * 30) + (blue * 11)) / 100; // this is the formula for the brightness calculation

    return brightness;
}

int main()
{

    int width;                      // for the width of image
    int height;                     // for the height of image
    const int required_channel = 3; // this is the number of channel we will use . 3 -> rgb
    int original_channel;           // here i am representing original channel to the number of channel of the actual image (the real property)

    unsigned char *image = stbi_load("image.jpg", &width, &height, &original_channel, required_channel); // using this function , we get the info about the image , here i am taking my image.jpg

    const char ascii_symbols[10] = " .:-=+*#%@"; // these are the symbols usually used for the ascii representation in the image (chatgpt told me this)

    // now we check if we have successfully got the image or not . if something has went wrong then the stbi_load function return NULL . so lets check that now
    if (image == NULL)
    {
        printf("Error opening the image file -> %s ", stbi_failure_reason()); // stbi_failure_reason give is the reason of the failing
        return 1;
    }

    int brightness_index; // making this varibale to store brightness , thats all

    for (int rows = 0; rows < (width); rows++)
    {
        for (int columns = 0; columns < height; columns++)
        {
            // Now we calculate pixel index , so basically pixel index is like finding out the actual pixel whose brightness will be found by us later on . and it has got this formula
            int pixel_index = ((rows * width) + columns) * 3;                                                            // so basically row * width tell us the horizonatal position and adding columns tells us the vertical position .  later we multiply with 3 because each pixl has 3 channels i.e r , g , b
            brightness_index = calculate_brightness(image[pixel_index], image[pixel_index + 1], image[pixel_index + 2]); // here , we are sending the r , g , b value of the pixel to calucualte the brightness;
            printf("%c", ascii_symbols[brightness_index]);
        }
        printf("\n");
    }
    _getch();

    return 0;
}