#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array; 
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

bool isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

bool isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

void BFS(int** graph, int n, int start, int* distances) {
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        distances[i] = -1;
    }
    
    struct Queue* queue = createQueue(n);
    
    visited[start] = true;
    distances[start] = 0;
    enqueue(queue, start);
    
    while (!isEmpty(queue)) {
        int node = dequeue(queue);
        
        for (int i = 0; i < n; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = true;
                distances[i] = distances[node] + 2; 
                enqueue(queue, i);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u - 1][v - 1] = graph[v - 1][u - 1] = 1; 
    }
    
    int start;
    scanf("%d", &start);
    
    int distances[n];
    BFS(graph, n, start - 1, distances);
    
    
    for (int i = 0; i < n; i++) {
        printf("%d ", i + 1);
    }
    
    printf("\n");
    
    // Output distances
    for (int i = 0; i < n; i++) {
        printf("%d ", distances[i]);
    }
    
    printf("\n");
    
    return 0;
}
