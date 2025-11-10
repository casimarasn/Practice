/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:06:10 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/05 12:22:26 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;


// ./ft_atoi.c
int		ft_atoi(const char *str);

// ./ft_bzero.c
void	ft_bzero(void *s, size_t n);

// ./ft_calloc.c
void	*ft_calloc(size_t nmeb, size_t sizem);

// ./ft_isalnum.c
int		ft_isalnum(int a);

// ./ft_isalpha.c
int		ft_isalpha(int c);

// ./ft_isascii.c
int		ft_isascii(int c);

// ./ft_isdigit.c
int		ft_isdigit(int n);

// ./ft_isprint.c
int		ft_isprint(int p);

// ./ft_itoa.c
char	*ft_itoa(int n);

// ./ft_lstadd_back.c
void	ft_lstadd_back(t_list **lst, t_list *new);

// ./ft_lstadd_front.c
void	ft_lstadd_front(t_list **lst, t_list *new);

// ./ft_lstclear.c
void	ft_lstclear(t_list **lst, void (*del)(void*));

// ./ft_lstdelone.c
void	ft_lstdelone(t_list *lst, void (*del)(void*));

// ./ft_lstiter.c
void	ft_lstiter(t_list *lst, void (*f)(void*));

// ./ft_lstlast.c
t_list	*ft_lstlast(t_list *lst);

// ./ft_lstmap.c
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *));

// ./ft_lstnew.c
t_list	*ft_lstnew(void *content);

// ./ft_lstsize.c
int		ft_lstsize(t_list *lst);

// ./ft_memchr.c
void	*ft_memchr(const void *s, int c, size_t n);

// ./ft_memcmp.c
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// ./ft_memcpy.c
void	*ft_memcpy(void *dest, const void *src, size_t n);

// ./ft_memmove.c
void	*ft_memmove(void *dest, const void *src, size_t n);

// ./ft_memset.c
void	*ft_memset(void *s, int c, size_t n);

// ./ft_print_char.c
int		ft_print_char(char c);

// ./ft_print_format.c
int		ft_print_format(va_list args, char c);

// ./ft_print_hexdecma.c
int		ft_print_hexdecma(unsigned long long n);

// ./ft_print_hexdecmi.c
int		ft_print_hexdecmi(unsigned long long int n);

// ./ft_print_nbr.c
int		ft_print_nbr(int n);

// ./ft_print_percent.c
int		ft_print_percent(void);

// ./ft_print_pointer.c
int		ft_print_pointer(void *str);

// ./ft_print_string.c
int		ft_print_string(char *str);

// ./ft_print_unsigned.c
int		ft_print_unsigned(unsigned int n);

// ./ft_printf.c
int		ft_printf(char const *format, ...);

// ./ft_putchar_fd.c
void	ft_putchar_fd(char c, int fd);

// ./ft_putendl_fd.c
void	ft_putendl_fd(char *s, int fd);

// ./ft_putnbr_fd.c
void	ft_putnbr_fd(int n, int fd);

// ./ft_putstr_fd.c
void	ft_putstr_fd(char *s, int fd);

// ./ft_split.c
char	**ft_split(char const *s, char c);

// ./ft_strchr.c
char	*ft_strchr(const char *s, int c);

// ./ft_strdup.c
char	*ft_strdup(const char *s);

// ./ft_striteri.c
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

// ./ft_strjoin.c
char	*ft_strjoin(char const *s1, char const *s2);

// ./ft_strlcat.c
size_t	ft_strlcat(char *dst, const char *src, size_t size);

// ./ft_strlcpy.c
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// ./ft_strlen.c
size_t	ft_strlen(const char *s);

// ./ft_strmapi.c
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// ./ft_strncmp.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// ./ft_strnstr.c
char	*ft_strnstr(const char *big, const char *little, size_t len);

// ./ft_strrchr.c
char	*ft_strrchr(const char *s, int c);

// ./ft_strtrim.c
char	*ft_strtrim(char const *s1, char const *set);

// ./ft_substr.c
char	*ft_substr(char const *s, unsigned int start, size_t len);

// ./ft_tolower.c
int		ft_tolower(int c);

// ./ft_toupper.c
int		ft_toupper(int c);

int		ft_isspace(int c);


#endif
