#include "main.h"


/************************* PRINT UNSIGNED NUMBER *************************/

/**

 * print_unsigned - Prints an unsigned number

 * @types: Lists arguments

 * @buffer: buffer arrays to handle prints

 * @flags: calculates active flags

 * @width: width

 * @precision: Precision specifications

 * @size: size specifier

 * Return: number of characters print

 */

int print_unsigned(va_list types, char buffer[],

        int flags, int width, int precision, int size)

{

        int i = BUFF_SIZE - 2;

        unsigned long int num = va_arg(types, unsigned long int);


        num = convert_size_unsgnd(num, size);


        if (num == 0)

                buffer[i--] = '0';


        buffer[BUFF_SIZE - 1] = '\0';


        while (num > 0)

        {

                buffer[i--] = (num % 10) + '0';

                num /= 10;

        }


        i++;


        return (write_unsgnd(0, i, buffer, flags, width, precision, size));

}


/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/

/**

 * print_octal - Prints an unsigned number in octal notation

 * @types: Lists  arguments

 * @buffer: buffer arrays to handle prints

 * @flags: Calculates active flags

 * @width: width

 * @precision: Precision specifications

 * @size: Size specifier

 * Return: Number of characters to print

 */

int print_octal(va_list types, char buffer[],

        int flags, int width, int precision, int size)

{


        int i = BUFF_SIZE - 2;

        unsigned long int num = va_arg(types, unsigned long int);

        unsigned long int init_num = num;


        UNUSED(width);


        num = convert_size_unsgnd(num, size);


        if (num == 0)

                buffer[i--] = '0';


        buffer[BUFF_SIZE - 1] = '\0';


        while (num > 0)

        {

                buffer[i--] = (num % 8) + '0';

                num /= 8;

        }


        if (flags & F_HASH && init_num != 0)

                buffer[i--] = '0';


        i++;


        return (write_unsgnd(0, i, buffer, flags, width, precision, size));

}


/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/

/**

 * print_hexadecimal - Prints an unsigned number in hexadecimal notation

 * @types: Lists arguments

 * @buffer: buffer array to handle print

 * @flags: calculates active flags

 * @width: width

 * @precision: precision specifications

 * @size: Size specifiers

 * Return: Number of characters to print

 */

int print_hexadecimal(va_list types, char buffer[],

        int flags, int width, int precision, int size)

{

        return (print_hexa(types, "0123456789abcdef", buffer,

                flags, 'x', width, precision, size));

}


/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/

/**

 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation

 * @types: Lists arguments

 * @buffer: Buffer array to handle print

 * @flags: calculate the active flags

 * @width: width

 * @precision: Ppecision specifications

 * @size: Size of specifiers

 * Return: number of characters to print

 */

int print_hexa_upper(va_list types, char buffer[],

        int flags, int width, int precision, int size)

{

        return (print_hexa(types, "0123456789ABCDEF", buffer,

                flags, 'X', width, precision, size));

}


/************** PRINT HEXX NUM IN LOWER OR UPPER **************/

/**

 * print_hexa - prints a hexadecimal number in lower or upper

 * @types: Lists arguments

 * @map_to: Arrays to values to map the number to

 * @buffer: buffers arrays to handle prints

 * @flags:  calculate the active flags

 * @flag_ch: calculate the active flags

 * @width: width

 * @precision: precision specifications

 * @size: size specifiers

 * @size: size specifications

 * Return: Number of characters to print

 */

int print_hexa(va_list types, char map_to[], char buffer[],

        int flags, char flag_ch, int width, int precision, int size)

{

        int i = BUFF_SIZE - 2;

        unsigned long int num = va_arg(types, unsigned long int);

        unsigned long int init_num = num;


        UNUSED(width);


        num = convert_size_unsgnd(num, size);


        if (num == 0)

                buffer[i--] = '0';


        buffer[BUFF_SIZE - 1] = '\0';


        while (num > 0)

        {

                buffer[i--] = map_to[num % 16];

                num /= 16;

        }


        if (flags & F_HASH && init_num != 0)

        {

                buffer[i--] = flag_ch;

                buffer[i--] = '0';

        }


        i++;


        return (write_unsgnd(0, i, buffer, flags, width, precision, size));

}
