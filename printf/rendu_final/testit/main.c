#include "ft_printf.h"
#include <stdio.h>

int     main()
{
        int		i = 2147483648;

	printf("\nTESTING NORMAL\n");
	ft_printf("for b;ba;ba :% 32i test", i);
	printf("\n");
	return (0);
}
/*
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
}*/
