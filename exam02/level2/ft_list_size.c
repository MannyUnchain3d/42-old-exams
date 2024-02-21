/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:52:51 by Manny             #+#    #+#             */
/*   Updated: 2023/03/01 17:52:57 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

int	ft_list_size(t_list *begin_list)
{
	if (begin_list)
		return (ft_list_size(begin_list->next) + 1);
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
// 	t_list *list = NULL;
// 	int size;

// 	// create a linked list with 3 nodes
// 	for (int i = 0; i < 6; i++)
// 	{
// 		t_list *new_node = malloc(sizeof(t_list));
// 		if (new_node == NULL)
// 		{
// 			perror("malloc");
// 			exit(1);
// 		}
// 		new_node->data = NULL;
// 		new_node->next = list;
// 		list = new_node;
// 	}
// 	// test the function with the linked list
// 	size = ft_list_size(list);
// 	// print the result
// 	printf("The size of the linked list is %d\n", size);
// 	// free the memory used by the linked list
// 	while (list != NULL)
// 	{
// 		t_list *next_node = list->next;
// 		free(list);
// 		list = next_node;
// 	}
// 	return 0;
// }
