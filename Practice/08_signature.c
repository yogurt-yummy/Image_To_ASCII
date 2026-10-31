// Step 3. Your coding challenge
// Write a program that:
// 1. Opens sample.bmp in binary-reading mode.
// 2. Checks whether the file opened successfully.
// 3. Creates an unsigned char array with space for two bytes.
// 4. Uses fread() to read those two bytes.
// 5. Checks whether both bytes were successfully read.
// 6. Prints both bytes in hexadecimal format.
// 7. Checks whether the signature is 42 4D.
// 8. Prints whether the file is a BMP file.
// 9. Closes the file.

#include <stdio.h>

int main()
{

    FILE *image_file_ptr;

    image_file_ptr = fopen("image.bmp", "rb");

    if (image_file_ptr != NULL)
    {
        printf("Opened the BMP image file successfully.\n");
    }
    else
    {
        printf("Failed to open the BMP file .\n");
        return 1;
    }
    unsigned char signature[2];

    size_t data_read = fread(signature, sizeof(unsigned char), 2, image_file_ptr);

    if (data_read == 2)
    {
        printf("Required data obtained successfully.\n");
    }
    else
    {
        printf("Couldnt read required data.\n");
        fclose(image_file_ptr);
        return 1;
    }

    for(int i = 0; i < 2; i++){
        printf("%02X\t",signature[i]);
    }
    if((signature[0] == 0x42) && (signature[1] == 0x4D)){
        printf("It is a BMP file.\n");
    }else{
        printf("\nIt is not a BMP file.\n");
    }
    fclose(image_file_ptr);

    return 0;
}