#include <stdio.h>

// COMPATIBILITES FALGS/FORMATS
//
int	main()
{
	char	c = 'a';
	char	*s = "abc";
	int	k = 42;

	printf("mod, zero, five, d :");
	printf("%05d\n", 42);
	printf("mod, moins, five, d :");
	printf("%-5d\n", 42);
	printf("mod, plus, zero, five, d :");
	printf("%+05d\n", 42);
	printf("mod, hashtag, x :");
	printf("%#x\n", 255);
	printf("mod, hashtag, i :");
	printf("%#i\n", 255);
	printf("mod, space, d :");
	printf("% d\n", 42);
	printf("mod, point, 2, i :");
	printf("%.2i\n", 314159);
	printf("mod, space, i :");
	printf("% i\n", 420);
	printf("mod, plus, point, 2, i :");
	printf("%+.2i\n", 314159);
	printf("mod, moins, one, zero, point, 2, i :");
	printf("%-10.2i\n", 314159);
	printf("mod, zero, one, zero, point, two, i :");
	printf("%010.2i\n", 314159);
	printf("mod, hashtag, i :");
	printf("%#i\n", 420);
	printf("mod, moins, plus, one, zero, point, two, i :");
	printf("%-+10.2i\n", 314);
/*
	printf("%s \n\n\n\n", "LAURA J'AI FAIM !!!");
	printf("%%\n");	
	printf("%s", "modulo, char, space, modulo, bsn :");
	printf("%c %\n", c);
	printf("%s", "spa, modulo, c :");
	printf(" %c\n", c);
	printf("%s", "modulo, modulo, string, space, modulo, bsn :");
	printf("%%s %\n", s);
	printf("%s", "modulo, modulo, modulo, decimale, space, bsn, char a :");
	printf("%%%d \na", k);
*/
	return (0);
}
