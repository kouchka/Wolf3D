/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:46:32 by allallem          #+#    #+#             */
/*   Updated: 2018/05/28 15:16:15 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define B_PF_SIZE 1024
# define BUFF_SIZE 1024

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_gnlist
{
	char			*tmp;
	int				fd;
	int				j;
	struct s_gnlist	*next;
	struct s_gnlist	*previous;
}					t_gnlist;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_pfspe
{
	va_list			ap;
	char			contenu[B_PF_SIZE];
	int				i;
	int				h;
	int				l;
	int				j;
	int				z;
	int				diese;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				point;
	int				value;
	int				result;
	int				cursor;
	long long int	size_content;
	long long int	field;
	long long int	precision;
}					t_pfspe;

void				ft_flag_plus_space(t_pfspe *point, long long int content);
void				ft_putstr_printf(char const *str, t_pfspe *point);
int					ft_printf(char const *str, ...);
int					ft_verification_last(char const *str, t_pfspe *point);
int					ft_printfdi(char c, t_pfspe *point, long long int content);
void				ft_put_precision(t_pfspe *point);
void				ft_put_field(t_pfspe *point, char c, long long int content);
void				ft_flag_zero(t_pfspe *point, char *c);
void				ft_putaddress_printf(void *add, char c, t_pfspe *p, int b);
void				ft_printfs(t_pfspe *point, char *content);
void				ft_check_buffer(t_pfspe *point, char c);
void				ft_pull_all(t_pfspe *point);
void				ft_bufnbr_printf(long long int n, t_pfspe *point);
void				ft_putnbr_printf(long long int n, t_pfspe *point);
void				ft_flags_zero(char *c, t_pfspe *point);
int					ft_fillstruct_printf(t_pfspe *point, char const *str);
int					ft_printf_spe(char const *s, t_pfspe *p);
void				ft_putpercent(t_pfspe *point);
void				ft_typefor_address(t_pfspe *p, void *ad,
		unsigned long long int *n, char c);
void				ft_init_pfspe(t_pfspe *point);
void				ft_adjustaddress(t_pfspe *p, char c, char *str);
void				ft_calculate_address(t_pfspe *p, char *s, char c);
int					ft_special_address(unsigned long long int n,
					char c, t_pfspe *p);
void				ft_printf_c(t_pfspe *point, unsigned char c);
void				ft_printfcmaj(t_pfspe *point, int32_t ca);
void				ft_printfsmaj(t_pfspe *point, void *address);
void				ft_puts_field(t_pfspe *p, char c);
void				ft_flagscmaj(t_pfspe *p, int32_t address);
void				ft_flagssmaj(t_pfspe *p, void *address);
void				reset_if_l(t_pfspe *p);
void				reset_if_j(t_pfspe *p);
void				reset_if_z(t_pfspe *p);
int					ft_starflag(t_pfspe *p, char const *str, int *i);
int					ft_sizeoflonglongint(long long int address, int preci);
char				*ft_strchr_one_more(char const *s1, int c);
int					ft_sqrt(int nb);
void				ft_bzero(void *s, size_t n);
char				*ft_strchr(char const *s1, int c);
char				*ft_strrchr(char const *s1, int c);
int					ft_atoi(char const *str);
char				*ft_strstr(char const *dest, char const *pattern);
char				*ft_strnstr(char const *dest,
		char const *pattern, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, void const *src, size_t n);
void				*ft_memccpy(void *dest, void const *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(void const *dest, int c, size_t n);
void				ft_strclr(char *s1);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
int					ft_isprint(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
size_t				ft_strlen(char const *s);
char				*ft_strcpy(char *dest, char const *src);
char				*ft_strncpy(char *dest, char const *src, size_t n);
char				*ft_strdup(char const *s);
char				*ft_strcat(char *dest, char const *src);
char				*ft_strncat(char *dest, char const *src, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
size_t				ft_strlcat(char *dest, char const *src, size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *neew);
void				ft_printlist(t_list *list);
t_list				*ft_splitlist(char *str, char c);
char				*ft_realloc(char *str, size_t lenstr, size_t len);
void				ft_putaddress(void *address, int i);
int					ft_putoctal(unsigned int nbr);
int					ft_strstr_int(char const *str, char const pattern);
long long int		ft_atoi_longlongint(char const *str);
void				ft_putnbr_spe(intmax_t n);
long long int		ft_strlen_longlong(char *str);
int					get_next_line(const int fd, char **line);
int					ft_sizeofint(int size);
int					ft_abs(int i);
int					ft_compare(char *str, char *pattern);
int					ft_count_number(char *str);
int					ft_tablen(char **tab);

#endif
