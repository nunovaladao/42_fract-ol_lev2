/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:30:13 by nuno              #+#    #+#             */
/*   Updated: 2023/04/13 21:55:42 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int red(int val_color)
{
    if (val_color >= 0 && val_color <= 255)
        return (255);
    else if (val_color > 255 && val_color <= 510)
        return (255 - (val_color - 255));
    else if (val_color > 510 && val_color <= 1020)
        return (0);
    else if (val_color > 1020 && val_color <= 1275)
        return (val_color - 1020);
    else 
        return (255);
}

int blue(int val_color)
{
    if (val_color >= 0 && val_color <= 510)
        return (0);
    if (val_color > 510 && val_color <= 765)
        return (val_color - 510);
    else 
        return (255);
}

int green(int val_color)
{
    if (val_color >= 0 && val_color <= 255)
        return (val_color);
    else if (val_color > 255 && val_color <= 765)
        return (255);
    else if (val_color > 765 && val_color <= 1020)
        return (255 - (val_color - 765));
    else if (val_color > 1020 && val_color <= 1275)
        return (0);
    else 
        return (255);
}