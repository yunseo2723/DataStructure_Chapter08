#include <stdio.h>
#include <stdlib.h>
#include "adjMatrix.h"

//공백 그래프 생성
void createGraph(graphType* g) {
	int i, j;
	g->n = 0;									//정점 개수를 0으로 초기화
	for (i = 0; i < MAX_VERTEX; i++) {
		for (j = 0; j < MAX_VERTEX; j++)
			g->adjMatrix[i][j] = 0;
	}
}

//그래프 g에 정점 v 삽입
void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("\n 그래프 정점의 개수 초과");
		return;
	}
	if (v < (g->n)) return;						//이미 있는 정점이라 삽입 불가
	g->n++;										//정점의 개수 n을 1 증가시킴
}

//그래프 g에 간선 (u,v)를 삽입하는 연산
void insertEdge(graphType* g, int u, int v) {
	//간선 (u,v)를 삽입하기 위해 정점 u와 v가 그래프에 존재하는지 확인
	if (u >= g->n || v >= g->n) {				//총 정점의 수보다 해당 정점의 번호가 작아야함
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	g->adjMatrix[u][v] = 1;						//삽입한 간선에 대한 2차원 배열의 원소값을 1로 설정
}

//그래프 g의 2차원 배열값을 순서대로 출력하는 연산
void print_adjMatrix(graphType* g) {
	int i, j;
	for (i = 0; i < (g->n); i++) {
		printf("\n\t\t");
		for (j = 0; j < (g->n); j++)
			printf("%2d", g->adjMatrix[i][j]);
	}
}