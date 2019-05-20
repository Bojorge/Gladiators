//
// Created by manuel on 01/04/19.
//

#ifndef CLIENTE_TCPCLIENT_H
#define CLIENTE_TCPCLIENT_H

#include <iostream>

// Write CPP code here
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <zconf.h>

#include <arpa/inet.h>

#define MAX 1000000
#define PORT 6611
#define SA struct sockaddr

class TCPclient {

private:

    char buff[MAX];
    std::string readed="INICIO";
    int sockfd;
    string lista;

public:
    string pruebabuff(){
        //std::cout<<"\n se saco del buff "<<readed<<std ::endl;
        return readed;
    }
    int get_sockfd(){
        return sockfd;
    }

    void leerPaquete(int sockfd){

        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        auto prueba =buff;
        std::string retornar="";
        retornar=prueba;
        this->readed=retornar;
        pruebabuff();
    }

    void enviarPaquete(int sockfd,string lista_preliminar){
        string cc="primer elemento";
        cout<<"lista a enviar>>>: "<<lista_preliminar<<endl;
        char elemento[500];
        strcpy(elemento,lista_preliminar.c_str());
        //bzero(buff, sizeof(buff));
        write(sockfd, elemento, sizeof(buff));
        lista=elemento;
        leerPaquete(sockfd);


    };

    bool terminarConexion(){{}
        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Cliente finalizado...\n");
            return true;
        }
        return false;
    }


    void puerto(int sockfd,string lista) {

        //for (;;) {
            char elemento[80];
            strcpy(elemento,lista.c_str());
            enviarPaquete(sockfd,lista);
            //if(terminarConexion()){
                //break;
            //}

            leerPaquete(sockfd);
        //}
    };


    int iniciar(){

        int connfd;
        struct sockaddr_in servaddr, cli;

        // socket create and varification
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            printf("creacion del socket fallida ...\n");
            exit(0);
        }
        else
            printf("Socket exitosamente creado ...\n");
        bzero(&servaddr, sizeof(servaddr));

        // assign IP, PORT
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("192.168.100.25");
        servaddr.sin_port = htons(PORT);

        // connect the client socket to server socket
        if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
            printf("conexion con el server fallida...\n");
            exit(0);
        }
        else
            printf("se ha conectado al server..\n");

        // function for chat
        //puerto(sockfd);

        // close the socket
        //close(sockfd);


    };

};


#endif //CLIENTE_TCPCLIENT_H