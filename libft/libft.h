/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:45:13 by mtaheri           #+#    #+#             */
/*   Updated: 2026/01/14 17:03:30 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/* Checks for an alphabetic character */
int		ft_isalpha(int c);
/* Checks for a digit */
int		ft_isdigit(int c);
/* Checks for an alphanumeric character */
int		ft_isalnum(int c);
/* Checks for a 7-bit ASCII character */
int		ft_isascii(int c);
/* Checks for a printable character */
int		ft_isprint(int c);
/* Returns the length of a string */
size_t	ft_strlen(const char *s);
/* Fills memory with a constant byte */
void	*ft_memset(void *b, int c, size_t len);
/* Sets memory to zero */
void	ft_bzero(void *s, size_t n);
/* Copies memory area */
void	*ft_memcpy(void *dst, const void *src, size_t n);
/* Copies memory area safely */
void	*ft_memmove(void *dst, const void *src, size_t n);
/* Appends string with size limit */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
/* Copies string with size limit */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
/* Converts character to uppercase */
int		ft_toupper(int c);
/* Converts character to lowercase */
int		ft_tolower(int c);
/* Locates first occurrence of character */
char	*ft_strchr(const char *s, int c);
/* Locates last occurrence of character */
char	*ft_strrchr(const char *s, int c);
/* Compares strings up to n bytes */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/* Locates byte in memory */
void	*ft_memchr(const void *s, int c, size_t n);
/* Compares memory areas */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/* Locates substring within length */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
/* Converts string to integer */
int		ft_atoi(const char *str);
/* Allocates zero-initialized memory */
void	*ft_calloc(size_t count, size_t size);
/* Duplicates a string */
char	*ft_strdup(const char *s1);

/* Extracts a substring */
char	*ft_substr(char const *s, unsigned int start, size_t len);
/* Concatenates two strings */
char	*ft_strjoin(char const *s1, char const *s2);
/* Trims characters from both ends */
char	*ft_strtrim(char const *s1, char const *set);
/* Splits string by delimiter into an array */
char	**ft_split(char const *s, char c);
/* Converts integer to string */
char	*ft_itoa(int n);
/* Applies function to each char with index */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/* Applies function to each char by address */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
/* Writes a character to a file descriptor */
void	ft_putchar_fd(char c, int fd);
/* Writes a string to a file descriptor */
void	ft_putstr_fd(char *s, int fd);
/* Writes a string followed by newline */
void	ft_putendl_fd(char *s, int fd);
/* Writes an integer to a file descriptor */
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
/* Creates a new list node */
t_list	*ft_lstnew(void *content);
/* Adds a node at the beginning of the list */
void	ft_lstadd_front(t_list **lst, t_list *new);
/* Counts the number of nodes in a list */
int		ft_lstsize(t_list *lst);
/* Returns the last node of the list */
t_list	*ft_lstlast(t_list *lst);
/* Adds a node at the end of the list */
void	ft_lstadd_back(t_list **lst, t_list *new);
/* Frees a node using a delete function */
void	ft_lstdelone(t_list *lst, void (*del)(void*));
/* Deletes and frees all nodes of a list */
void	ft_lstclear(t_list **lst, void (*del)(void*));
/* Applies a function to each node’s content */
void	ft_lstiter(t_list *lst, void (*f)(void *));
/* Creates a new list by applying a function to each node */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
