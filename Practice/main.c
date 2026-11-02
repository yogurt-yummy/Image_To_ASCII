#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdio.h>

int main(){

    int width;
    int height;
    int channels;
    const int required_channel = 3;

    unsigned char *image = stbi_load("imaage.jpg",&width,&height,&channels,required_channel);

    if(image == NULL){
        printf("Couldnt read image pixel data %s\n",stbi_failure_reason());
        return 1;
    }

    printf("The width is %d pixels.\n",width);
    printf("The height is %d pixels.\n",height);
    printf("The original channel is %d .\n",channels);

    stbi_image_free(image);
    return 0;
}