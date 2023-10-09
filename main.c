#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

extern void ft_write(int fd, const char *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern ssize_t ft_strlen(const char *buf);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern char *ft_strdup(const char *s);

int main() {

	// ft_write
	printf("\033[1;33m--* ft_write *--\033[0m\n");
	printf("- normal string to file -\n");
	printf("Please see output.txt\n");
	char *str = "Hello World!\n";
	int fd_write = open("./output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_write == -1) {
		printf("error in opening file.");
		exit(1);
	} else {
		ft_write(fd_write, str, 13);
		close(fd_write);
	}
	printf("- stdout -\n");
	ft_write(STDOUT_FILENO, str, 13);
	printf("- wrong fd -\n");
	ft_write(3000, str, 13);
	printf(" >-errno: %d\n", errno);
	write(3000, str, 13);
	printf(" >-errno: %d\n", errno);

	// ft_read
	printf("\033[1;33m--* ft_read *--\033[0m\n");
	printf("- normal string from file -\n");
	int fd = open("./test.txt", O_RDONLY);
	if (fd == -1) {
		printf("error in opening file.");
		exit(1);
	} else {
		char *buf = malloc(3);
		ssize_t size = ft_read(fd, buf, 3);
		printf(" ft_read size: %zu\n", size);
		printf(" ft_read buf: %s\n", buf);
		ssize_t size1 = read(fd, buf, 3);
		printf(" read size: %zu\n", size1);
		printf(" read buf: %s\n", buf);
		close(fd);
		free(buf);
	}
	printf("- stdin -\n");
	printf("Please input 3 characters\n");
	char *buf_read = malloc(3);
	ssize_t size = ft_read(STDIN_FILENO, buf_read, 3);
	printf(" ft_read size: %zu\n", size);
	printf(" ft_read buf: %s\n", buf_read);
	free(buf_read);
	printf("- wrong fd -\n");
	char *buf_read1 = malloc(3);
	int size1 = ft_read(3000, buf_read1, 3);
	printf(" ft_read size: %d\n", size1);
	printf(" >-errno: %d\n", errno);
	int size2 = read(3000, buf_read1, 3);
	printf(" read size: %d\n", size2);
	printf(" >-errno: %d\n", errno);
	free(buf_read1);

	// ft_strlen
	printf("\033[1;33m--* ft_strlen *--\033[0m\n");
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
	printf("\033[1;33m--* ft_strcpy *--\033[0m\n");
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
		ssize_t bytesRead = read(fd_dump2, buf, 10000);
		if (bytesRead == -1) {
			perror("Error reading from file");
			exit(1);
		}
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
	printf("\033[1;33m--* ft_strcmp *--\033[0m\n");
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
	printf("\033[1;33m--* ft_strdup *--\033[0m\n");
	printf("- normal string 1 -\n");
	const char *srcDup = "Bonjour le monde!";
	char *dstFtDup = ft_strdup(srcDup);
	printf("ft_strdup: %s\n", dstFtDup);
	char *dstDup = strdup(srcDup);
	printf("strdup: %s\n", dstDup);
	free(dstDup);

	printf("- empty string -\n");
	const char *srcDup1 = "";
	char *dstFtDup1 = ft_strdup(srcDup1);
	printf("ft_strdup: %s\n", dstFtDup1);
	free(dstFtDup1);
	char *dstDup1 = strdup(srcDup1);
	printf("strdup: %s\n", dstDup1);
	free(dstDup1);
	
	printf("- long string -\n");
	int fd_dump3 = open("./dump.txt", O_RDONLY);
	if (fd_dump3 == -1) {
		printf("error in opening file.");
		exit(1);
	} else {
		char *buf = malloc(10001);
		ssize_t bytesRead = read(fd_dump3, buf, 10000);
		if (bytesRead == -1) {
			perror("Error reading from file");
			exit(1);
		}
		buf[10000] = '\0';
		char *dstFtDup1 = ft_strdup(buf);
		printf("ft_strdup: %zu\n", strlen(dstFtDup1));
		free(dstFtDup1);
		char *dstDup1 = strdup(buf);
		printf("strdup: %zu\n", strlen(dstDup1));
		free(dstDup1);
		free(buf);
		close(fd_dump3);
	}

	system("leaks a.out");
	return (0);
}
