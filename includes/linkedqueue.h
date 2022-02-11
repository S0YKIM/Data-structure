#ifndef _LINKED_QUEUE_
#define _LINKED_QUEUE_

#define f(x) #x

typedef enum SimStatusType 
{ 
	arrival, // 도착(=대기 중)
	start, // 시작(=서비스 중)
	end // 종료(=서비스 끝)
} SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;	// 고객 도착 시각
	int serviceTime;	// 서비스 소요 시간
	int startTime;		// 서비스 시작 시각
	int endTime;		// 서비스 종료 시각: 시작 시각 + 서비스 시간
} SimCustomer;

typedef struct					LinkedQueueNodeType
{
	SimCustomer					data;
	struct LinkedQueueNodeType*	pElement;
}								LinkedQueueNode;

typedef struct		LinkedQueueType
{
	int				currentElementCount;
	LinkedQueueNode	*pFrontNode;
	LinkedQueueNode	*pRearNode;
} 					LinkedQueue;

LinkedQueue		*createLinkedQueue();
int				enqueueLQ(LinkedQueue* pQueue, LinkedQueueNode element);
LinkedQueueNode	*dequeueLQ(LinkedQueue* pQueue);
LinkedQueueNode	*peekLQ(LinkedQueue* pQueue);
void			deleteLinkedQueue(LinkedQueue** pQueue);
int				isLinkedQueueEmpty(LinkedQueue* pQueue);
void			displayLinkedQueue(LinkedQueue* pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif