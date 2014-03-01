/*
** sudoku.h for rush in /home/chapui_s/travaux/rush_sudoku
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sat Mar  1 01:36:22 2014 chapui_s
** Last update Sat Mar  1 02:53:22 2014 chapui_s
*/

#ifndef SUDOKU_H_
# define SUDOKU_H_

typedef struct	s_root
{
  int		**tabb;
  int		nb;
  struct s_root	*prev;
  struct s_root	*next;
}		t_root;

t_root	*list;

void	my_putstr(char *str);
void	my_putnbr(int nb);
void	disp_sudoku(t_root *list_cur, t_root *root, int **tab);
t_root	*read_map(void);
char	*get_next_line(const int fd);
t_root	*init(void);
char	*my_memset(char *str, int i);
int	is_good(int **tab, int nb_to_test, int line, int col);
int	my_strlen(char *str);
void	pushbefore(t_root *element, int nb);
int	resolve_sudoku(int **tab, int line, int col);
int	find_nb(int **tab, int line, int col);

#endif /* !SUDOKU_H_ */
