#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdio.h>

int main(){

    int width;
    int height;
    int original_channel;
    const int required_channel = 3;

    unsigned char *image = stbi_load("imaage.jpg", &width, &height, &original_channel,required_channel);

    if(image == NULL){
        printf("Error opening the image file -> %s \n",stbi_failure_reason());
        return 1;
    }else{
        printf("Image file opened successfully.\n");
    }

    return 0;
}