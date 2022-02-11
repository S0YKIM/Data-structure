#include "data_structure.h"

void	test_queue_simulation()
{
	LinkedQueue		*pArrivalQueue;
	LinkedQueue		*pWaitQueue;
	LinkedQueue		*historyQueue;
	LinkedQueueNode	*serviceNode;

	int				isOnService = FALSE;
	int				serviceUserCount = 0;
	int				totalWaitTime = 0;
	int				currentTime = 0;
	int				closingTime = 5;

	pArrivalQueue = createLinkedQueue();
	if (!pArrivalQueue)
		return ;
	pWaitQueue = createLinkedQueue();
	if (!pWaitQueue)
	{
		free(pArrivalQueue);
		return ;
	}
	historyQueue = createLinkedQueue();
	if (!historyQueue)
	{
		free(pArrivalQueue);
		free(pWaitQueue);
		return ;
	}

	insertCustomer(0, 3, pArrivalQueue);
	insertCustomer(2, 2, pArrivalQueue);
	insertCustomer(4, 1, pArrivalQueue);
	insertCustomer(6, 1, pArrivalQueue);
	insertCustomer(8, 3, pArrivalQueue);

	while (currentTime < closingTime)
	{
		if (pArrivalQueue->currentElementCount > 0)
		{
			if (currentTime == pArrivalQueue->pFrontNode->data.arrivalTime)
				processArrival(pArrivalQueue, pWaitQueue);
		}
		if (isOnService == TRUE)
		{
			if (currentTime == serviceNode->data.startTime + serviceNode->data.serviceTime)
			{
				serviceNode = processServiceNodeEnd(currentTime, serviceNode, &serviceUserCount, &totalWaitTime);
				enqueueLQ(historyQueue, *serviceNode);
				free(serviceNode);
				serviceNode = 0;
				isOnService = FALSE;
			}
		}
		if (isOnService == FALSE && pWaitQueue->currentElementCount > 0)
		{
			serviceNode = processServiceNodeStart(currentTime, pWaitQueue);
			isOnService = TRUE;
		}
		currentTime++;
	}

	if (isOnService == TRUE)
	{
		currentTime = serviceNode->data.startTime + serviceNode->data.serviceTime;
		serviceNode = processServiceNodeEnd(currentTime, serviceNode, &serviceUserCount, &totalWaitTime);
		enqueueLQ(historyQueue, *serviceNode);
		free(serviceNode);
		serviceNode = 0;
		isOnService = FALSE;
		printf("Overtime work : %i\n", currentTime - closingTime);
	}
	printReport(pWaitQueue, pArrivalQueue, historyQueue, serviceUserCount, totalWaitTime);
}