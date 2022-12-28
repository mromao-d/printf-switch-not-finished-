#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

void	ft_putnmbr(int	i)
{
	if (i < 0)
	{
		ft_putchar('-');
		i = -i;
	}
	if (i / 10 > 0)
	{	
		ft_putnmbr(i / 10);
		i %= 10;
	}
	ft_putchar(i + 48);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void foo(char *fmt, ...)
{
	va_list 		ap;
	int				d;
	int				go;
	int				i;
	unsigned long	p;
	unsigned int	u;
	unsigned int	x;
	unsigned int	X;
	char			c;
	char			*s;

	go = 0;
	va_start(ap, fmt);
	while (*fmt)
	{	
		if (*++fmt != '%')
			ft_putchar(*fmt);
		else
		{
			switch(*++fmt)
			{
				case 'c':                       // char 
					// Note: char is promoted to int.
					c = va_arg(ap, int);
					ft_putchar(c);
					break;
				case 's':                       // char 
					// Note: char is promoted to int.
					s = va_arg(ap, char *);
					ft_putstr(s);
					break;
				case 'p':						// pointer
					p = va_arg(ap, unsigned long);
					ft_putstr((void *) &p);
				case 'd':                       // decimal
					d = va_arg(ap, int);
					ft_putnmbr(d);
					break;
				case 'i':
					i = va_arg(ap, int);
					ft_putnmbr(i);
					break;
				case 'u':
					u = va_arg(ap, unsigned int);
					ft_putnmbr(u);
					break;
				case 'x':
					x = va_arg(ap, unsigned int);
					putchar(x);
					break;
				case 'X':
					X = va_arg(ap, unsigned int);
					ft_putnmbr(X);
					break;
				case '%':
					ft_putchar(37);
					break;
			}
			/*  */
		}
	}
	va_end(ap);
}

int	main	(void)
{
	int i;
	/* float	o; */
	char *str;

	i = 37;
	str = "My name is Manuel";
	/* o = 11.233444; */
	foo("o número é %%%%%iabc\n e a string é: %p,\n feito?", i, str);
	printf("\n\n\no número é %%%%%iabc\n e a string é: %p,\n feito?\n\n\n", i, str);
	/* printf("número é %%%%%d\n e a string é: %s,\n feito?\n\n\n%s", i, str, "O meu nome é Manuel\n\n\n\n");
	foo("\n\n\n%p\n\n\n", &str);
	printf("o: %f\n", o);
	printf("d: %d\n", i);*/
	/* printf("i: %c\n", i); */
	/* printf("p: %p\n", &str); */ 
	return (0);
}