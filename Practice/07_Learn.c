// Next: Your coding challenge — Binary File Reader & Writer
// Create a new C file and write a program that:
// 1. Creates an unsigned char array containing five values: 10, 20, 30, 40, 50.
// 2. Opens a file named data.bin in binary-writing mode.
// 3. Writes all five values using fwrite().
// 4. Closes the file.
// 5. Reopens the same file in binary-reading mode.
// 6. Reads the five values into a new unsigned char array using fread().
// 7. Checks how many items were successfully read.
// 8. Prints the values stored in the new array.
// 9. Closes the file.

#include <stdio.h>

int main()
{

    unsigned char number_value[] = {10, 20, 30, 40, 50};

    FILE *file_ptr;

    file_ptr = fopen("data.bin", "wb");

    if (file_ptr == NULL)
    {
        printf("Error opening the file data.bin\n");
        return 1;
    }

    size_t file_written = fwrite(number_value, sizeof(unsigned char), (sizeof(number_value) / sizeof(number_value[0])), file_ptr);

    if (file_written == (sizeof(number_value) / sizeof(number_value[0])))
    {
        printf("Data written to the bin file successfully.\n");
    }
    else
    {
        printf("Data could not be written partially or completely.\n");
        fclose(file_ptr);
        return 1;
    }

    fclose(file_ptr);

    file_ptr = fopen("data.bin", "rb");

    if (file_ptr == NULL)
    {
        printf("Error opening the file data.bin\n");
        fclose(file_ptr);
        return 1;
    }

    unsigned char number_received[5];

    size_t file_received = fread(number_received, sizeof(unsigned char), (sizeof(number_value) / sizeof(number_value[0])), file_ptr);

    if (file_received == (sizeof(number_value) / sizeof(number_value[0])))
    {
        printf("Data received from the bin file successfully.\n");
    }
    else
    {
        printf("Data lost partially or completely.\n");
        return 1;
    }

    for (int i = 0; i < (sizeof(number_value) / sizeof(number_value[0])); i++)
    {
        printf("%hhu\t", number_received[i]);
    }

    fclose(file_ptr);

    return 0;
}