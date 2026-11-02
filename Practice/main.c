#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdio.h>

int calculate_brightness(int,int,int); // This is function declaration

int calculate_brightness(int red , int green, int blue){

    int brightness = ((red * 30) + (green * 59) + (blue * 11)) / (100) ;
    return brightness;
}
int main(){

    int width;
    int height;
    int channels;
    const int required_channel = 3;

    unsigned char *image = stbi_load("image.jpg",&width,&height,&channels,required_channel);

    if(image == NULL){
        printf("Couldnt read image pixel data %s\n",stbi_failure_reason());
        return 1;
    }

    printf("The width is %d pixels.\n",width);
    printf("The height is %d pixels.\n",height);
    printf("The original channel is %d .\n",channels);

    printf("The First RGB Value -> \n");
    printf("Red -> %d\n",image[0]);
    printf("Green -> %d\n",image[1]);
    printf("Blue -> %d\n",image[2]);

    int total_pixels = width * height;

    int brightness;

    printf("\nRed\tGreen\tBlue\n");
    for(int i = 0; i < total_pixels * required_channel; i += 3){
        printf("%d\t%d\t%d\n",image[i],image[i+1],image[i+2]);
        brightness = calculate_brightness(image[i],image[i+1],image[i+2]);
        printf("Brightness = %d\n",brightness);
    }

    stbi_image_free(image);
    return 0;
}