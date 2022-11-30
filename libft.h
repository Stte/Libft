/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:09:24 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/30 17:08:54 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @brief ASCII to integer.
 *
 * Returns integer from number string.
 * @param str Number as a string
 * @return Number as a integer
 */
int		ft_atoi(const char *str);
/**
 * @brief Zero a byte string.
 *
 * Zeroes \b n number of bytes in memory
 * starting from location pointed by \b s.
 * @param s Pointer to memory
 * @param n Number of bytes
 */
void	ft_bzero(void *s, size_t n);
/**
 * @brief Allocate and zero.
 *
 * Allocates memory and sets every byte to 0.
 * @param count How many elements
 * @param size Size of a element (eg. 4 bytes)
 * @returns Pointer to the allocated memory
 * @attention Allocates memory
 */
void	*ft_calloc(size_t count, size_t size);
/**
 * @brief Is an alphabet or a number.
 *
 * Checks if character is an alphabet or a number.
 * @param c Character as an ASCII desimal
 * @returns 1 if true, 0 if false
 */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
/**
 * @brief Integer to ASCII.
 *
 * Returns a number as a string.
 * @param n Number
 * @returns Number \b n as a string
 * @attention Allocates memory
 */
char	*ft_itoa(int n);
/**
 * @brief Scan memory for a character.
 *
 * Scans \b n bytes of memory from address \b s for a character \b c.
 *
 * @param s Starting address
 * @param c Character to find
 * @param n Till how many bytes from the starting address \b s
 * @returns Address of the found character or a NULL if character not found
 */
void	*ft_memchr(const void *s, int c, size_t n);
/**
 * @brief Memory compare
 *
 * Compares \b n number of bytes from two addresses \b s1 and \b s1.
 * @param s1 First address
 * @param s2 Second address
 * @param n Number of bytes

 * @returns If \b s1 and \b s2 are equal returns 0.
 * Else returns difference of the byte that was not equal.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/**
 * @brief Copies memory to destination.
 *
 * Copies \b n bytes of memory from source to destination.
 * @param dst Address of the destination
 * @param src Address of the source
 * @returns Address of destination
 * @attention Does not handle overlapping.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);
/**
 * @brief Copy memory area.
 *
 * Copies \b len bytes of memory from source to destination.
 * @param dst Address of the destination
 * @param src Address of the source
 * @param len Number of bytes
 * @returns Address of the destination
 */
void	*ft_memmove(void *dst, const void *src, size_t len);
/**
 * @brief Fill memory area with a contant byte
 *
 * Fills \b len number of bytes of memory with \b c.
 * @param b Memory address
 * @param c Value to set the bytes to
 * @param len Number of bytes
 * @returns Address of \b b
 */
void	*ft_memset(void *b, int c, int len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
/**
 * @brief Splits string to substrings.
 *
 * Splits string \b s by character \b c to substrings.
 * @param s String
 * @param c Character
 * @returns Array of substrings
 * @attention Allocates memory
 */
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

#endif
