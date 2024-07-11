/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:34:47 by alerkul           #+#    #+#             */
/*   Updated: 2024/07/01 18:34:47 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct stack
{
	int				value;
	int				index;
	struct stack	*next;
}	t_list;

void	check_arg(int argc, char **argv);
void	ft_argfree(char **arg);
char	**ft_split(const char *s, char c);
long	ft_atoi(const char *str);
int		ft_isnum(char *num);

void	create_stack(t_list **stack, int argc, char **argv);
void	stack_index(t_list **stack);
t_list	*last_node_find(t_list *head);

int		is_it_sorted(t_list **stack);
int		list_size(t_list *node);
int		find_max_bits(t_list **stack);
int		swap_sa(t_list **a);
int		swap_ra(t_list **a);
int		swap_rra(t_list **a);
int		swap_pa(t_list **a, t_list **b);
int		swap_pb(t_list **a, t_list **b);
int		push(t_list **stack_to, t_list **stack_from);
int		reverse_rotate(t_list **stack);
int		rotate(t_list **stack);
int		swap(t_list **stack);
void	sort(t_list **a, t_list **b);
void	sort_3(t_list **a);
void	sort_4(t_list **a, t_list **b);
void	sort_5(t_list **a, t_list **b);
void	radix_sort(t_list **a, t_list **b);
void	sort_3_if(t_list **a);
void	sort_3_else(t_list **a);
void	error(void);

#endif
