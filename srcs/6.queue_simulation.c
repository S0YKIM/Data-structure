/*
이중 연결 리스트 덱을 활용한 은행 시뮬레이션
*/

#include "data_structure.h"

void	insertCustomer(int arrivalTime, int serviceTime, LinkedQueue *pArrivalQueue)
{
	LinkedQueueNode	node;
	int				result;

	if (!pArrivalQueue)
		return ;
	node.data.status = arrival;
	node.data.arrivalTime = arrivalTime;
	node.data.serviceTime = serviceTime;
	node.data.startTime = 0;
	
	result = enqueueLQ(pArrivalQueue, node);
	if (!result)
		return ;
}

void	processArrival(LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
	LinkedQueueNode	*node;
	int				result;

	if (!pArrivalQueue || !pWaitQueue)
		return ;
    node = dequeueLQ(pArrivalQueue);
	if (!node)
		return ;
	result = enqueueLQ(pWaitQueue, *node);
    if (!result)
        return ;
}

LinkedQueueNode*	processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	LinkedQueueNode	*serviceNode;

	if (!pWaitQueue)
		return NULL;
	serviceNode = dequeueLQ(pWaitQueue);
	if (!serviceNode)
		return NULL;
	serviceNode->data.startTime = currentTime;
	serviceNode->data.status = start;
	return (serviceNode);
}

LinkedQueueNode*	processServiceNodeEnd(int currentTime, LinkedQueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	if (!pServiceUserCount || !pServiceUserCount || !pTotalWaitTime)
        return NULL;
	pServiceNode->data.endTime = currentTime;
	*pTotalWaitTime += pServiceNode->data.startTime - pServiceNode->data.arrivalTime;
	(*pServiceUserCount)--;
	return (pServiceNode);
}

void	printSimCustomer(int currentTime, SimCustomer customer)
{
	printf("Current time : %i\n", currentTime);
	if (customer.status == arrival)
		printf("Customer arrived.\n");
	else if (customer.status == start)
		printf("Customer service started.\n");
	else if (customer.status == end)
		printf("Customer service ended.\n");
}


void	printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
	LinkedQueueNode	*ptr;

	if (!pWaitQueue)
		return ;
	printf("---------------------------------------\n");
	printf("Current time : %i\n", currentTime);
	ptr = pWaitQueue->pFrontNode;
	while (ptr)
    {
        printf("Status : %i (Arrival Time : %i, Service Time : %i)\n", ptr->data.status, ptr->data.arrivalTime, ptr->data.serviceTime);
		ptr = ptr->pElement;	
    }
	printf("---------------------------------------\n");
}

void	printReport(LinkedQueue *pWaitQueue, LinkedQueue *pArrivalQueue, int serviceUserCount, int totalWaitTime)
{
	if (!pWaitQueue || !pArrivalQueue)
    {
        printf("Error\n");
		return ;
    }
	printf("---------------------------------------\n");
	if (pWaitQueue->currentElementCount > 0 || pArrivalQueue->currentElementCount > 0)
    	printf("There are remaining customers.\n");
	printf("Number of customers who got serviced: %i\n", serviceUserCount);
    printf("Total waiting time : %i\n", totalWaitTime);
	printf("---------------------------------------\n");
}