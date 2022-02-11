#ifndef _SIM_UTIL_
#define _SIM_UTIL_

/*
 * serviceNode가 점유되어었으면(=state가 start)
 * 현재 serviceNode를 끝낼 시간이니?
 * 맞으면 점유 해제, 아니면 계속 점유
 * serviceNode 비어있니?
 * 그럼 서비스 start
 */

/*
	Arrival Queue : ㅁ(4) - ㅁ(6) - ㅁ(8)
	Wait Queue    : ㅁ(2)
	servicenode  =  processServiceNodeStart 
	main : isOnService = 1 
	free -> processServiceNodeEnd(service)
	servicenode : ㅁ(2)  status : start
	main : isOnService = 0 
*/

// 고객 도착(=시스템 타임과 고객 도착 시간이 일치)하면 도착 큐에 추가
void insertCustomer(int arrivalTime, int serviceTime, LinkedQueue *pArrivalQueue);

// 고객 도착(=시스템 타임과 고객 도착 시간이 일치)하면 도착 큐의 고객을 대기 큐에 추가
void processArrival(LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue);

// 서비스 시작 처리
LinkedQueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue);

// 서비스 종료 처리(노드 반환하여 Free)
LinkedQueueNode* processServiceNodeEnd(int currentTime, LinkedQueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);

// 고객의 상태 출력
void printSimCustomer(int currentTime, SimCustomer customer);

// 대기 큐의 상태 출력
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);

// 최종 시뮬레이션 결과 출력
void printReport(LinkedQueue *pWaitQueue, LinkedQueue *pArrivalQueue, int serviceUserCount, int totalWaitTime);

#endif