#nclude <stdio.h>
/*
void	other_tests(unsigned int hex, int i, int d, int x, char c, char *s, void *p)
{
	printf("CORRECT / INCORRECT POUR C\n");
	printf("Le caractère est : %c\n", c); // Correct
	printf("Le caractère est : %c\n", i); // Incorrect

	printf("CORRECT / INCORRECT POUR S\n");
	printf("La chaîne est : %s\n", s); // Correct
	printf("La chaîne est : %s\n", &i); // Incorrect

   	printf("CORRECT / INCORRECT POUR I et D\n")
	printf("L'entier signé est (%%i) : %i\n", i); // Correct (i ou d peuvent être utilisés)
	printf("L'entier signé est (%%d) : %d\n", d); // Correct
	printf("L'entier signé est (%%i) : %i\n", s); // Incorrect

	printf("CORRECT / INCORRECT POUR U\n");
	printf("L'entier non signé est : %u\n", u); // Correct
	printf("L'entier non signé est : %u\n", d); // Incorrect

	printf("CORRECT / INCORRECT POUR X\n");
	printf("L'entier en hexadécimal est (%%x) : %x\n", hex); // Correct (en minuscule)
	printf("L'entier en hexadécimal est (%%X) : %X\n", hex); // Correct (en majuscule)
	printf("L'entier en hexadécimal est (%%x) : %x\n", s); // Incorrect

	printf("CORRECT / INCORRECT POUR P\n");
	printf("Le pointeur est : %p\n", p); // Correct
	printf("Le pointeur est : %p\n", i); // Incorect
}
*/
int	main()
{
	unsigned int	u = 12345;
	unsigned int	hex = 0xABCD;
	int		i = 12345;
	int		d = -12345;
	int		x = 12345;
	char		c = 'z';
	char		*s = "Hello";
	void		*p = (void*)0x11111111;

	printf("TESTING SPACES\n");
	printf("for decimal     : % 11d test \n", d);
	printf("for integer     : % 11i test \n", i);
	printf("for unsigned    : % 12u test\n", u);
	printf("for hexadecimal : % 13x test\n", x);
	printf("for hexa maj    : % 14X test\n", x);
	printf("for void p      : % 15p test\n", p);
	printf("for character   : % 16c test\n", c);
	printf("for string      : % 17s test\n\n", s);

	printf("TESTING POINT PRECISION\n");
	printf("for unsigned    :%.3u\n", u);
	printf("for decimal     :%.3d\n", d);
	printf("for integer     :%.3i\n", i);
	printf("for hexadecimal :%.3x\n", x);
	printf("for hexa maj    :%.3X\n", x);
	printf("for void p      :%.3p\n", p);
	printf("for character   :%.3c\n", c);
	printf("for string      :%.3s\n\n", s);

	printf("TESTING HASHTAG\n");
	printf("for decimal   :%#d\n", d);
	printf("for integer   :%#i\n", i);
	printf("for unsigned  :%#u\n", u);
	printf("for void p    :%#p\n", p);
	printf("for hex       :%#x test \n", x);
	printf("for hex maj   :%#X test \n", x);
	printf("for character :%#c\n", c);
	printf("for string    :%#s\n\n", s);

	printf("TESTING PLUS SIGN\n");
	printf("for unsigned    :%+u\n", u);
	printf("for hexadecimal :%+x\n", x);
	printf("for hexa maj    :%+X\n", x);
	printf("for void p      :%+p\n", p);
	printf("for character   :%+c\n", c);
	printf("for string      :%+s\n\n", s);

	printf("TESTING ZEROS\n");
	printf("for character  :%09c\n", c);
	printf("for string     :%09s\n", s);
	printf("for integer    :%09i\n", i);
	printf("for decimal    :%09i\n", d);
	printf("for hexadec    :%09i\n", hex);
	printf("for void p     :%09i\n", p);
	printf("for unsigned   :%09i\n", u);
	
	printf("TESTING ALIGNMENT\n");
	printf("for character    :%-2c test\n", c);
	printf("for string       :%-2s test\n", s);
	printf("for decimal      :%-2d test\n", d);
	printf("for integer      :%-2i test\n", i);
	printf("for unsigned     :%-2u test\n", u);
	printf("for hexadecimal  :%-2x test\n", x);
	printf("for pointer      :%-2p test\n", p);
	return (0);
}
