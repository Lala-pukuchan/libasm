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
	printf("*ft_strlen\n");
	printf("len: %zu\n", ft_strlen(str));

	// ft_strcpy
	printf("* ft_strcpy\n");
	char *dst = malloc(12);
	ft_strcpy(dst, str);
	printf("dst: %s\n---\n", dst);
	free(dst);

	// ft_strcmp
	printf("* ft_strcmp\n");
	char *s1 = "abd";
	char *s2 = "abc";
	printf("ft_strcmp: %d\n", ft_strcmp(s1, s2));
	printf("strcmp: %d\n", strcmp(s1, s2));
	char *s3 = "abc";
	char *s4 = "abd";
	printf("ft_strcmp: %d\n", ft_strcmp(s3, s4));
	printf("strcmp: %d\n", strcmp(s3, s4));

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
