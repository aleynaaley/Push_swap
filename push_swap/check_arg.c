/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:59:32 by alerkul           #+#    #+#             */
/*   Updated: 2024/07/01 14:59:35 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error() 
{
		write(1, "Error", 5);
        write(1, "\n", 1);
}

void    ft_argfree(char **arg) //dinamik tahsis edilmiş iki boyutlu bir char tek tek freelemelisin
{
    int i;

    i = 0;
    while(arg[i])
        i++;
    while(i >= 0)
        free(arg[i--]);
}
int  repeat(long tmp, char **arg, int i)
{
    i++;
    while(arg[i])
    {
        if(ft_atoi(arg[i]) == tmp)
            return(1);
        i++;
    }
    return(0);
}
void    check_arg(int argc, char **argv)
{
    int i;
    long    tmp;
    char    **arg;

    i=0;
    if(argc == 2)
    {
        arg = ft_split(argv[1], ' ');   //char olduğu için mesela "2 3 45 64 9" bazıldı o zaman bölüp bakıyor 2 3 45 şeklinde gönderse zaten sorun yok 
    }
    else
    {
        i = 1;
        arg = argv; // eğer öyle bir durum zaten yoksa tüm argümanları direkt atıyorum arg ye 
    }
    while(arg[i])
    {
        tmp = ft_atoi(arg[i]); //aldığım argümanları int e çevir
        if(!ft_isnum(arg[i]))  //numerik mi kontrol 
            error();
        if(repeat(tmp,arg,i))  //tekrarlanan var mı kontrol
            error();
        if(tmp < -2147483648 || tmp > 2147483647)  //int aşıyormu kontrol
            error();
        i++;
    }
    if(argc == 2)
        ft_argfree(arg);       //splitte malloc kullandın
}
