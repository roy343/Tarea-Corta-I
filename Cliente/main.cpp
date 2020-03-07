#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

//Funcion main del cliente
int main()
{
    // Se crea un socket para el cliente
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        return 1;
    }

    //	Se define el puerto al cual se va a conectar
    int port = 54000;
    // Se pone el IP de la maquina
    string ipAddress = "127.0.0.1";

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    // Se conecta al socket
    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        return 1;
    }

    //	Ciclo while que le envia los mensajes al server
    char buf[4096];
    string userInput;


    do {
        //	Ingresar datos
        cout << "Ingrese el vertice de origen ";
        getline(cin, userInput);

        //		Send to server
        int sendRes = send(sock, userInput.c_str(), userInput.size() + 1, 0);
        if (sendRes == -1)
        {
            cout << "No se pudo contactar con servidor \r\n";
            continue;
        }

        // Se espera por una respuesta por parte del servidor
        memset(buf, 0, 4096);
        int data = recv(sock, buf, 4096, 0);
        if (data == -1)
        {
            cout << "Error en comunicacion con el servidor\r\n";
        }
        else
        {
            //	Mostrar respuesta en terminal
            cout << " > " << string(buf, data) << "\r\n";
        }
    } while(true);

    // Cerrar el socket
    close(sock);

    return 0;
}
