#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
char	*ft_strdup(const char *src);

char	*ft_strchr(char *str, int c);
char	*get_next_line(int fd);
char	*erase_newline(char *note);
char	*get_line(char *str);
char	*read_until_newline(int fd, char *note);

#endif
