#include "main.h"

/*
 **_printf - Function to write input to standard output.
 *return: the total number of characters printed.
 */
int _printf (const char *format, ...)
{int count = 0;
va_list args;
        if (format == NULL)
        {
                return (-1);

        }
va_start(args, format);
        while (*format)
        {
                if (*format != '%')
                {write(1, format, 1);
                count++; }
                else
                {
                    format++;
                }
                if (*format == '\0')
                break;
                if (*format == '%')
                {       write(1, format, 1);
                        count++;
                }
                else if (*format == 'c')
                {       char c = va_arg(args, int);
                        write(1, &c, 1);
                        count++;
                }
                else if (*format == 's')
                {       char *wrd = va_arg(args, char*);
                        int wrd_len = 0;

                        while (wrd[wrd_len] != '\0')
                        wrd_len++;
                        write(1, wrd, wrd_len);
                        count += wrd_len;
                }
        format++;
        }
va_end(args);
return (count);
}
