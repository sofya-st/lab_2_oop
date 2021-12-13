
#include <iostream>
#include <conio.h>
#include <stdio.h>

class Computer{
public:
    int number;
    Computer(){
        number = 0;
        printf("Computer()\n");
    }
    Computer(int number) {
       this->number = number;
        printf("Computer(int number)\n");
    }
    Computer(const Computer &pc) {
        number = pc.number;
        printf("Computer(const Computer &pc)\n");
    }
    ~Computer() {
        printf("%d\n", number);
        printf("~Computer()\n");
    }

    void Id(){
        int id = number % 100000;
        printf("%d", id);
    }
    void changeId(int newId);
};

void Computer :: changeId(int newId) {
    number = (number / 100000) * 100000 + newId;
}

class Laptop: public Computer {
public:
    bool sen;
    Laptop() : Computer() {
        sen = false;
        printf("Laptop()\n");
    }
    Laptop(int number, bool sen) : Computer(number) {
       this->sen = sen;
        printf("Laptop(int number, bool sen)\n");
    }
    Laptop(const Laptop &pc) {
        sen = pc.sen;
        number = pc.number;
        printf("Laptop(const Laptop &pc)\n");
    }
    ~Laptop() {
        printf("%d, sen is ", number);
        printf(sen ? "true\n" : "false\n");
        printf("~Laptop()\n");
    }

    void changeSen(bool newSen) {
        sen = newSen;
    }
   
};

class localNet {
protected:
    Computer server;
    Computer* pc1;
    Computer* pc2;
public:
    localNet() {
        server = 0;
        pc1 = new Computer;
        pc2 = new Computer;
        printf("localNet()\n");
    }
    localNet(int serv, int pc1,int pc2) {
        this->server = serv;
        this->pc1 = new Computer(pc1);
        this->pc2 = new Computer(pc2);
        printf("localNet(int serv, int pc1,int pc2)\n");
    }
    localNet(const localNet& net) {
       server = net.server;
        pc1 = new Computer(*(net.pc1));
        pc2 = new Computer(*(net.pc2));
        printf("localNet(const localNet& net)\n");
    }

    ~localNet() {
        delete pc1;
        delete pc2;
        printf("~localNet()\n");
    }

};

int main()
{  
 
       /* Laptop* pc = new Laptop();
        Laptop *pc2 = new Laptop(10020032, true);
        Laptop *pc3 = new Laptop(*pc2);

        delete pc;
        delete pc2;
        delete pc3;*/

    localNet *net1 = new localNet(79345710, 23386437, 14788132);
    localNet* net2 = new localNet(*net1);
    delete net1;
    delete net2;
       
    _getch();
    return 0;
}

