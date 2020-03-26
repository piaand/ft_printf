/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:11:54 by pandersi          #+#    #+#             */
/*   Updated: 2020/03/26 13:43:14 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
int					ft_atoi(const char *str);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s1);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
					size_t n);
void				*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strset(size_t len, char c);
void				ft_strdel(char **as);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strchr(const char *s, int c);
long long			ft_strchri(const char *s, int c);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
					size_t dstsize);
char				*ft_strncat(char *restrict s1, const char *restrict s2,
					size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_itoa(int n);
char				*ft_itoa_base(long long int value, int base);
char				*ft_itoa_base_unsigned(size_t value, int base);
char				*ft_float_to_a(long double nb, unsigned int precision);
size_t				ft_count_nbr_length(long long n);
unsigned int		ft_count_digits(size_t n, int base);
void				ft_strclr(char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strrchr(const char *s, int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstlen(t_list **alst);
void				*ft_realloc(void *ptr, size_t res, size_t size);
int					ft_isupper(int c);
void				ft_lstappend(t_list **alst, t_list *new);
char				*ft_write_base(size_t i, size_t len, int base, char *ascii);

#endif
