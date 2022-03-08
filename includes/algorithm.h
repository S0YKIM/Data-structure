#ifndef _ALGORITHM_
# define _ALGORITHM_

ArrayGraph	*floyd(ArrayGraph *graph);
void	print_minimum_path(ArrayGraph *path, int start, int end);

void	dijkstra(LinkedGraph *graph, int start);
void	print_dijkstra(int *distance, int cnt);

#endif