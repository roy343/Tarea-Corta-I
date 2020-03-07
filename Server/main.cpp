#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <limits.h>
#include <stdio.h>

using namespace std;

// Funcion main del server
int main()
{

    // Se crea un socket para el servidor
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        cerr << "Error al crear la conexion, por favor intente de nuevo" << endl;
        return -1;
    }

    // Se le da una IP a servidor
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    // Definir que el socket esta escuchando
    listen(listening, SOMAXCONN);


    sockaddr_in client;
    socklen_t clientSize = sizeof(client);

    int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

    char host[NI_MAXHOST];
    char service[NI_MAXSERV];

    memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);

    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        cout << host << " conexion a puerto " << service << endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " conexion a puerto " << ntohs(client.sin_port) << endl;
    }

    // Se cierra el socket
    close(listening);


    char buf[4096];


    // Ciclo while que obtiene los datos del cliente
    while (true)
    {
        memset(buf, 0, 4096);

        // Funcion que recibe los datos del cliente
        int data = recv(clientSocket, buf, 4096, 0);
        if (data == -1)
        {
            cerr << "Error" << endl;
            break;
        }

        if (data == 0)
        {
            cout << "Cliente desconectado " << endl;
            break;
        }

        cout << string(buf, 0, data) << endl;
        // dijkstra(graph, 4);






    }

    // Se cierra el socket
    close(clientSocket);

    return 0;
}


//Se define la cantidad de vertices que tiene el grafo
#define V 9

// Funcion que encuentra el vertice que se encuentra mas cerca
int minDistance(int dist[], bool sptSet[])
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Imprimir la respuesta
int printRes(int dist[])
{
    printf("Vertice  Distancia\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Algoritmo de Dijkstra
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // Array de salida

    bool sptSet[V];

    // Define todas las distancias como infinitas o en este caso el valor maximo que puede tener un entero
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;


    dist[src] = 0;

    // Encuentra el camino mas corto
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;


        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printRes(dist);
}




