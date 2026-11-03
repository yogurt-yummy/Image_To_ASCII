#define STB_IMAGE_IMPLEMENTATION // Defining this macro , so that i could use (along with its implementation)
#include "stb_image.h"           // I am including this header file/library to use the image realted function
#include <stdio.h>               // This is the standard library which we use to do normal stuff like print and more;
#include <conio.h>               // I am including this funciton to use getch , so that the program doesnt close itself in a blink if i open the exe file via double click
#include <stdlib.h>              // I am including this function to use system("cls") in my code

int calculate_brightness(int, int, int); // we make this function to calculate brightness of the certain pixel , by taking its channels r , g , b . though this is just a function prototype

int calculate_resized_height(int, int, int); // I am aking this function to calculate the resized height and ya this is function prototype

int calculate_resized_height(int width, int height, int target_width)
{
    int resized_height = (target_width * height) / width; // The formual is (new ascii image aspect ratio) = (original image aspect ratio)
    return resized_height;
}
int calculate_brightness(int red, int green, int blue)
{

    int brightness;
    brightness = ((green * 59) + (red * 30) + (blue * 11)) / 100; // this is the formula for the brightness calculation

    return brightness;
}

int main()
{

    char file_name[100];
    printf("Enter your image name (in the same directory) along with its extension. \n");
    printf("For sample I have added images named image 1.jpg and image_2.jpg for the reviewer. \n");
    printf("Image name here -> ");
    gets(file_name);

    int width;                      // for the width of image
    int height;                     // for the height of image
    const int required_channel = 3; // this is the number of channel we will use . 3 -> rgb
    int original_channel;           // here i am representing original channel to the number of channel of the actual image (the real property)

    int target_width = 100; // I am making target width so that the images actually fit in the normal terminal size
    int resized_height;     // I am making resized_height becuase we need to calculate and preserve the image actual image aspect ratio . thats why we calculate resized heigth accordingly

    unsigned char *image = stbi_load(file_name, &width, &height, &original_channel, required_channel); // using this function , we get the info about the image , here i am taking my image.jpg

    resized_height = calculate_resized_height(width, height, target_width);

    const char ascii_symbols[10] = " .:-=+*#%@"; // these are the symbols usually used for the ascii representation in the image (chatgpt told me this)

    // now we check if we have successfully got the image or not . if something has went wrong then the stbi_load function return NULL . so lets check that now
    if (image == NULL)
    {
        printf("Error opening the image file -> %s ", stbi_failure_reason()); // stbi_failure_reason give is the reason of the failing
        printf("\nPress any key to close the program...");
        _getch();
        return 1;
    }

    int brightness; // making this varibale to store brightness , thats all

    system("cls");
    for (int rows = 0; rows < (height); rows++)
    {
        for (int columns = 0; columns < width; columns++)
        {
            // Now we calculate pixel index , so basically pixel index is like finding out the actual pixel whose brightness will be found by us later on . and it has got this formula
            int pixel_index = ((rows * width) + columns) * required_channel;                                       // so basically row * width takes us to the end of pixel block preceeding the current position and adding columns takes us forward to the current position horizontally .  later we multiply with 3 because each pixl has 3 channels i.e r , g , b
            brightness = calculate_brightness(image[pixel_index], image[pixel_index + 1], image[pixel_index + 2]); // here , we are sending the r , g , b value of the pixel to calucualte the brightness;
            int brightness_index = (brightness * 10) / 256;
            printf("%c", ascii_symbols[brightness_index]);
        }
        printf("\n");
    }
    stbi_image_free(image); // freeing the image , good for memory
    _getch();

    return 0;
}