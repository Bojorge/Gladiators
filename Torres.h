//
// Created by gerom on 04/05/19.
//

#ifndef GLADIADOR_TORRES_H
#define GLADIADOR_TORRES_H


class Torres {

    int alcance;
    int dano;
    int tipobala;

public:
    int getTipobala() const {
        return tipobala;
    }

    void setTipobala(int tipobala) {
        if (tipobala == 1){
            Torres :: dano = 1;
            Torres :: alcance = 5;

        }
        if (tipobala == 2){
            Torres :: dano = 2;
            Torres :: alcance = 4;

        }
        if (tipobala == 3){
            Torres :: dano = 3;
            Torres :: alcance = 3;

        }
        if (tipobala == 4){
            Torres :: dano = 4;
            Torres :: alcance = 2;

        }
        if (tipobala == 5){
            Torres :: dano = 5;
            Torres :: alcance = 1;

        }
        Torres::tipobala = tipobala;
    }

    int getAlcance() const {
        return alcance;
    }

    int getDano() const {
        return dano;
    }


};


#endif //GLADIADOR_TORRES_H
