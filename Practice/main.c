#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdio.h>

int main(){

    int width;
    int height;
    int channels;
    const int required_channel = 3;

    unsigned char *image_pixel_data = stbi_load("image.jpg",&width,&height,&channels,required_channel);

    printf("The width is %d pixels.\n",width);
    printf("The height is %d pixels.\n",height);
    printf("The original channel is %d .\n",channels);

    return 0;
}