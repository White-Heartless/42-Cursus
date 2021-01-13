#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_list
{
	void *content;
	struct s_list *next;
}				t_list;

void	*ft_memset(void *ptr, int x, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strcpy(char* destination, const char* source);
char 	*ft_strncpy(char* dest, const char* src, size_t n);
char	*ft_strcat(char* dest, const char* src);
char	*ft_strncat(char* dest, const char* src, size_t n);
size_t	ft_strlcat(char* dest, const char* src, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *s1);
int		ft_isalpha(int character);
int		ft_isdigit(int character);
int		ft_isalnum(int character);
int		ft_isascii(int character);
int		ft_isprint(int character);
int		ft_toupper(int character);
int		ft_tolower(int character);
void	*ft_memalloc(size_t amount);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t amount);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(const char *s, char (*f)(char));
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
char 	**ft_split(char const *s, char c);
t_list	*ft_lstnew(void *content);
void 	ft_lstadd_front(t_list **lst, t_list *new);
int 	ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

# endif
