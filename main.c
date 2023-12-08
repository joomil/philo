/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:10:12 by jmilesi           #+#    #+#             */
/*   Updated: 2023/12/08 23:13:01 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define	NUM 1000000
#define	NUM2 10000000

float time_diff(struct timeval *start, struct timeval *end) {
 return (end->tv_sec - start->tv_sec) + 1e-6 * (end->tv_usec - start->tv_usec);
}

void loopFunc(size_t num) {
 int tmp = 0;
 for (int i = 0; i < num; ++i) {
   tmp += 1;
 }
}

int main() {
 struct timeval start;
 struct timeval end;

 gettimeofday(&start, NULL);
 loopFunc(NUM);
 gettimeofday(&end, NULL);

 printf("loopFunc(%d) time spent: %0.8f sec\n", NUM, time_diff(&start, &end));

 gettimeofday(&start, NULL);
 loopFunc(NUM2);
 gettimeofday(&end, NULL);

 printf("loopFunc(%d) time spent: %0.8f sec\n", NUM2, time_diff(&start, &end));

 exit(EXIT_SUCCESS);
}

/*
int	main(int ac, char **av)
{
	printf("%d\n", gettimeofday);
	return (0);
}*/
