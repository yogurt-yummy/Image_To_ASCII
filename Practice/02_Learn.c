// Calculate brightness
// A pixel has these values:
// int r = 200;
// int g = 100;
// int b = 50;


// Calculate its approximate brightness using the formula we learned.

#include <stdio.h>

int main(){

    int r = 200;
    int g = 100;
    int b = 50;

    float brightness = ((g * 59) + (b * 11) + (r * 30))/100.0;
    
    printf("Brightness = %.2f\n",brightness);
    return 0;
}