/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 23:49:40 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/10 00:29:36 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

char	**read_instructions(standard_input)
{
	//Read from stdin the list of instructions
	//Each one is followed by a '\n' -> instruction = Get_Next_Line(1)
	//Store instructions in an array
}

int		main(int argc, char **argv)
{
	char	**instructions;

	if (argc == 1)
	{
		return (0);
	}	
	else if ( argc == 2)
	{
		//Count int in the argument list
		//Create 2 stacks
		//Put the value inside the A stack !Warning : The order
		instructions = read_instructions(standard_input);
		//Execute instructions on the A stack
		//If A is stored and B is empty -> OK on STDOUT
		//Else -> KO on STDERR
	}
	else
	{
		//Error, too much arguments
	}
	return (0);
}
