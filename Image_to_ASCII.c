#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdio.h>

int brightness(int, int, int); // I made this function to calculate brightness . This is function prototype

int calculate_brightness(int red, int green, int blue)
{
    int brightness = ((green * 59) + (red * 30) + (blue * 11)) / 100;
    
    return brightness;
}

int main()
{

    int width;
    int height;
    int original_channel;
    const int required_channel = 3;

    unsigned char *image = stbi_load("image.jpg", &width, &height, &original_channel, required_channel);

    if (image == NULL)
    {
        printf("Error opening the image file -> %s \n", stbi_failure_reason());
        return 1;
    }
    else
    {
        printf("Image file opened successfully.\n");
    }

    int total_pixels = width * height;
    int brightness;

    for (int i = 0; i < total_pixels * required_channel; i += 3)
    {
        printf("%d\t%d\t%d\n", image[i], image[i + 1], image[i + 2]);
    }
    return 0;
}