#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void ft_write(int fd, const char *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern ssize_t ft_strlen(const char *buf);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern char *ft_strdup(const char *s);

int main() {

	// ft_write
	printf("* ft_write\n");
	char *str = "Hello World!";
	ft_write(1, str, 12);

	// ft_read
	printf("* ft_read\n");
	int fd = open("./test.txt", O_RDONLY);
	if (fd == -1) {
		printf("error in opening file.");
		exit(1);
	} else {
		char *buf = malloc(3);
		ssize_t size = ft_read(fd, buf, 3);
		printf("\nsize: %zu\n", size);
		printf("buf: %s\n", buf);
		close(fd);
		free(buf);
	}

	// ft_strlen
	printf("\n--* ft_strlen *--\n");
	printf("- normal string -\n");
	printf(" ft_strlen: %zu\n", ft_strlen(str));
	printf(" strlen: %zu\n", ft_strlen(str));
	printf("- empty string -\n");
	char *emp = "";
	printf(" ft_strlen: %zu\n", ft_strlen(emp));
	printf(" strlen: %zu\n", ft_strlen(emp));
	printf("- long string -\n");
	int fd_dump = open("./dump.txt", O_RDONLY);
	if (fd_dump == -1) {
		printf("error in opening file.");
		exit(1);
	} else {
		char *buf = malloc(10001);
		read(fd_dump, buf, 10000);
		buf[10000] = '\0';
		printf(" ft_strlen: %zu\n", ft_strlen(buf));
		printf(" strlen: %zu\n", ft_strlen(buf));
		close(fd_dump);
		free(buf);
	}

	// ft_strcpy
	printf("\n--* ft_strcpy *--\n");
	printf("- normal string -\n");
	char *dst = malloc(12);
	ft_strcpy(dst, str);
	printf(" ft_strcpy: %s\n", dst);
	strcpy(dst, str);
	printf(" strcpy: %s\n", dst);
	free(dst);
	printf("- long string -\n");
	int fd_dump2 = open("./dump.txt", O_RDONLY);
	if (fd_dump2 == -1) {
		printf("error in opening file.");
		exit(1);
	} else {
		char *buf = malloc(10001);
		read(fd_dump2, buf, 10000);
		buf[10000] = '\0';
		char *dst1 = malloc(10001);
		ft_strcpy(dst1, buf);
		char *dst2 = malloc(10001);
		strcpy(dst2, buf);
		printf(" diff of ft_strcpy and strcpy: %d\n", strcmp(dst1, dst2));
		close(fd_dump2);
		free(buf);
		free(dst1);
		free(dst2);
	}

	// ft_strcmp
	printf("\n-- *ft_strcmp* --\n");
	printf("- normal string 1 -\n");
	char *s1 = "abd";
	char *s2 = "abc";
	printf(" ft_strcmp: %d\n", ft_strcmp(s1, s2));
	printf(" strcmp: %d\n", strcmp(s1, s2));
	printf("- normal string 2 -\n");
	char *s3 = "abc";
	char *s4 = "abd";
	printf(" ft_strcmp: %d\n", ft_strcmp(s3, s4));
	printf(" strcmp: %d\n", strcmp(s3, s4));
	printf("- empty string 1 -\n");
	char *s5 = "";
	char *s6 = "";
	printf(" ft_strcmp: %d\n", ft_strcmp(s5, s6));
	printf(" strcmp: %d\n", strcmp(s5, s6));
	printf("- empty string 2 -\n");
	char *s7 = "a";
	char *s8 = "";
	printf(" ft_strcmp: %d\n", ft_strcmp(s7, s8));
	printf(" strcmp: %d\n", strcmp(s7, s8));
	printf("- empty string 3 -\n");
	char *s9 = "";
	char *s10 = "a";
	printf(" ft_strcmp: %d\n", ft_strcmp(s9, s10));
	printf(" strcmp: %d\n", strcmp(s9, s10));

	// ft_strdup
	const char *srcDup = "Bonjour le monde!";
	char *dstFtDup = ft_strdup(srcDup);
	printf("ft_strdup: %s\n", dstFtDup);
	char *dstDup = strdup(srcDup);
	printf("strdup: %s\n", dstDup);
	free(dstDup);

	system("leaks a.out");
	return (0);
}
