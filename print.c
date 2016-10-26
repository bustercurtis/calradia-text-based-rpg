#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdarg.h>
void print(char *string, ...)
{
  const char *curr;
  int valret;
  double fltret;
  char *charret;
  char buffer[32];
  va_list args;
  va_start(args, string);
  for(curr = string; *curr != '\0'; curr++)
  {
    if(*curr != '%')
    {
      putchar(*curr);
      fflush(stdout);
    }
    else
    {
      switch(*++curr)
      {
        case 'c':
          valret = va_arg(args, int);
	  putchar(valret);
	  break;
	case 'd':
	  valret = va_arg(args, int);
	  snprintf(buffer, sizeof(buffer), "%d", valret);
	  printf("%s", buffer);
	  break;
	case 's':
	  charret = va_arg(args, char *);
	  fputs(charret, stdout);
	  break;
        case '%':
          putchar('%');
          break;
        case 'g':
	  fltret = va_arg(args, double);
	  snprintf(buffer, sizeof(buffer), "%g", fltret);
          printf("%s", buffer);
          break;
      }
    }
    usleep(12000);
  }
}
