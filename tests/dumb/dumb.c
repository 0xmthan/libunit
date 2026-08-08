/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 14:23:43 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/08 14:45:02 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumb_test.h"

int     dumb(int value)
{
    int *ptr;
    
    ptr = NULL;
    if (value == 1)
        return(1);
    else if (value == 2)
        return(-1);
    else if (value == 3)
    {
        *ptr = 42;  
        return (0);
    }
    else if (value == 4)
        ; // todo
    return (value);
}
