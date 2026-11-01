// Your task is to write a C program that opens a BMP file and reads its entire 14-byte BMP File Header.
// Open image.bmp in binary read mode ("rb").
// Check whether the file opened successfully.
// Read the 2-byte signature using fread().
// Check whether both bytes were read.
// Verify that the signature is 42 4D.
// Read the 4-byte file size from byte offset 2.
// Read the 4-byte pixel data offset from byte offset 10.
// Check whether all four bytes were successfully read for each field.
// Convert both 4-byte values from little-endian into decimal numbers.
// Print the results and close the file.

#include <stdio.h>

unsigned int convert_to_decimal(unsigned char[]); // I am making this function to convert the received hexadecimal bytes to decimal This is function prototype

unsigned int convert_to_decimal(unsigned char hexadecimal_bytes[])
{
    unsigned int in_decimal = hexadecimal_bytes[0] + (hexadecimal_bytes[1] * 256) + (hexadecimal_bytes[2] * 256 * 256) + (hexadecimal_bytes[3] * 256 * 256 * 256);

    return in_decimal;
}

int main()
{

    FILE *bmp_image_file_ptr;

    bmp_image_file_ptr = fopen("image.bmp", "rb");

    if (bmp_image_file_ptr == NULL)
    {
        printf("Couldnt Open the BMP file.\n");
        return 1;
    }

    unsigned char signature[2];

    size_t signature_read = fread(signature, sizeof(unsigned char), 2, bmp_image_file_ptr);

    if (signature_read == 2)
    {
        if (signature[0] == 0x42 && signature[1] == 0x4D)
        {
            printf("Signature read successfully . BMP file confirmed.\n");
        }
        else
        {
            printf("Signature read successfully . BMP file not confirmed.\n");
            fclose(bmp_image_file_ptr);
            return 1;
        }
    }

    int fseek_return = fseek(bmp_image_file_ptr, 2, SEEK_SET);

    if (fseek_return == 0)
    {
        printf("Pointer moved to the 2nd byte successfully.\n");
    }
    else
    {
        printf("Error moving the pointer to the 2nd byte.\n");
        return 1;
    }

    unsigned char file_size[4];
    size_t size_returned = fread(file_size, sizeof(unsigned char), 4, bmp_image_file_ptr);

    if (size_returned == 4)
    {
        printf("Size read successfully.\n");
    }
    else
    {
        printf("Couldnt read the file size.\n");
        return 1;
    }
    // unsigned int actual_file_size = (file_size[0]) + (file_size[1] * 256) + (file_size[2] * 256 * 256) + (file_size[3] * 256 * 256 * 256);

    unsigned int actual_file_size = convert_to_decimal(file_size);

    printf("The file size is %u bytes.\n", actual_file_size);
    printf("The file size is %u kilobytes.\n", actual_file_size / 1024);

    fseek_return = fseek(bmp_image_file_ptr, 10, SEEK_SET);

    if (fseek_return == 0)
    {
        printf("Pointer moved to the 10th byte successfully.\n");
    }
    else
    {
        printf("Error moving the pointer to the 10th byte.\n");
        return 1;
    }

    unsigned char pixel_offset[4];

    size_returned = fread(pixel_offset, sizeof(unsigned char), 4, bmp_image_file_ptr);

    if (size_returned == 4)
    {
        // unsigned int pixel_offset_data = pixel_offset[0] + (pixel_offset[1] * 256) + (pixel_offset[2] * 256 * 256) + (pixel_offset[3] * 256 * 256 * 256);
        unsigned int pixel_offset_data = convert_to_decimal(pixel_offset);

        printf("The data begins at byte offset : %u\n", pixel_offset_data);
    }
    else
    {
        printf("Error reading pixel offset.\n");
        fclose(bmp_image_file_ptr);
        return 1;
    }
    fclose(bmp_image_file_ptr);
    return 0;
}