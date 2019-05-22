//
// Created by gerom on 16/05/19.
//

#ifndef GLADIATORS_JSON_H
#define GLADIATORS_JSON_H
#include "Gladiador.h"
//#include "list.h"
//#include "list.cpp"
#include "Torres.h"
#include <vector>
#include <bits/stdc++.h>

using namespace std;


//clase que serealiza y deserealiza los objetos tipo Torre y tipo Gladiador
class Json{

public:
    //metodo que serializa un objeto Gladiador a objeto Json para ser pasado entre el sevidor y cliente
    string serializadorGladiador(Gladiador gla){
        string String =
                "{\"name\": \""+gla.getName() + "\"" +"," +
                "\"edad\": "+ to_string(gla.getEdad()) + "," +
                "\"probSupervivencia\": "+ to_string(gla.getprobSupervivencia()) + "," +
                "\"generaciones\": "+ to_string(gla.getGeneraciones()) + "," +
                "\"inteligeniaEmocional\": "+ to_string(gla.getinteligenciaEmocional()) + "," +
                "\"condFisica\": "+ to_string(gla.getcondFisica()) + "," +
                "\"fuerzaSuperior\": "+ to_string(gla.getfuerzaSuperior()) + "," +
                "\"fuerzaInferior\": "+ to_string(gla.getfuerzaInferior()) + "," +
                "\"resistencia\": "+ to_string(gla.getResistencia()) + "," +
                "\"x\": "+ to_string(gla.getX()) + "," +
                "\"y\": "+ to_string(gla.getY()) + "}";

        return String;
      }
    //metodo que serealiza un objeto Torre a objeto Json para ser pasado entre servidor y clientes
     string serializarTorreta(Torres tor) {
        string string =
                "{\"name\": \""+ tor.getNombre() + "\"" + "," +
                "\"generaciones\": " + to_string(tor.generaciones) + "," +
                "\"danoInferior\": " + to_string(tor.danoInferior) + "," +
                "\"danoSuperior\": " + to_string(tor.danoSuperior) + "," +
                "\"potencia\": " + to_string(tor.potencia) + "," +
                "\"tipobala\": " + to_string(tor.tipobala) + "," +
                "\"fuerzalanzador\": " + to_string(tor.fuerzalanzador) + "," +
                "\"velocidadlanzador\": " + to_string(tor.velocidadlanzador) + "," +
                "\"altotorre\": " + to_string(tor.altotorre) + "," +
                "\"dano\": " + to_string(tor.dano) + "," +
                "\"alcance\": " + to_string(tor.alcance) + "}";
        return string;
    }
    //metodo split que se encarga de serparar un string cada vez que aparezca un string llamado delimitador
    vector<string> split (string s, string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
            token = s.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back (token);
        }

        res.push_back (s.substr (pos_start));
        return res;
    }
    //metodo que deserealizado un objeto Json en String y lo convierte a un objeto Torre con todos sus atributos
    Torres desearilzarTorre(string tor){
        string na = "";
        string r = tor;
        int ge = 0; int di = 0; int ds = 0;int po = 0;
        int ti = 0;int fl = 0;int vl = 0;int alt = 0;
        int atq=0;int alc=0;
        int cont=1;
        vector<string> torreta = split (r, ",");

        for(int j = 0; j < torreta.size();j++ ){
            string h = torreta[j];
            vector<string> parte = split (h, " ");

            if (cont == 1) {
                string div1 = ( parte[1]);
                string div2 = (parte[2]);
                vector<string> div1name = split (div1, "\"");
                vector<string> div2name = split (div2, "\"");
                na = div1name[1] + " " + div2name[0];
            }
            if(cont == 2) { ge = std::stoi(parte[1]);}
            if(cont == 3) { di = std::stoi(parte[1]);}
            if(cont == 4) { ds = std::stoi(parte[1]);}
            if(cont == 5) { po = std::stoi(parte[1]);}
            if(cont == 6) { ti = std::stoi(parte[1]);}
            if(cont == 7) { fl = std::stoi(parte[1]);}
            if(cont == 8) { vl = std::stoi(parte[1]);}
            if(cont == 9) {
                string u = parte[1];
                vector<string> o = split (u, "}");alt = std::stoi(o[0]);

            }
            cont++;
        }
        Torres g;
        g.setNombre(na);
        g.setGeneraciones(ge);
        g.setDanoInferior(di);
        g.setDanoSuperior(ds);
        g.setPotencia(po);
        g.setTipobala(ti);
        g.setFuerzalanzador(fl);
        g.setVelocidadlanzador(vl);
        g.setAltotorre(alt);
        g.setDano((di+ds+po+ti)/4);
        g.setAlcance((fl+vl+alt+ti)/4);
        cont = 1;
        return  g;
    }
    
    //metodo que deserealizado un objeto Json en String y lo convierte a un objeto Gladiador con todos sus atributos
    Gladiador deserealizarGladiador(string glad){
        string na = "";
        int ed = 0; int ps = 0; int ge = 0;int ie = 0;
        int cf = 0;int fs = 0;int fi = 0;int x = 0;int y = 0;
        int res;
        string r =glad;
        vector<string> gladiador = split (r, ",");
        int cont=1;
        for(int j = 0; j < gladiador.size();j++ ){
            string h = gladiador[j];
            vector<string> parte = split (h, " ");
            if (cont == 1) {
                string div1 = ( parte[1]);
                string div2 = (parte[2]);
                vector<string> div1name = split (div1, "\"");
                vector<string> div2name = split (div2, "\"");
                na = div1name[1] + " " + div2name[0];
            }
            if(cont == 2) { ed = std::stoi(parte[1]);}
            if(cont == 3) { ps = std::stoi(parte[1]);}
            if(cont == 4) { ge = std::stoi(parte[1]);}
            if(cont == 5) { ie = std::stoi(parte[1]);}
            if(cont == 6) { cf = std::stoi(parte[1]);}
            if(cont == 7) { fs = std::stoi(parte[1]);}
            if(cont == 8) { fi = std::stoi(parte[1]);}
            if(cont == 9) {}
            if(cont == 10) { y = std::stoi(parte[1]);}
            if(cont == 11) {
                string u = parte[1];
                vector<string> o = split (u, "}");
                 y = std::stoi(o[0]);
            }
            cont++;
        }
        Gladiador g;
        g.setName(na);
        g.setEdad(ed);
        g.setprobSupervivencia(ps);
        g.setGeneraciones(ge);
        g.setinteligenciaEmocional(ie);
        g.setcondFisica(cf);
        g.setfuerzaSuperior(fs);
        g.setfuerzaInferior(fi);
        g.setX(x);
        g.setY(y);
        g.setResistencia((ps+ge+ie+cf+fs+fi)/6);
        cont = 1;
        return g;

    }
};
#endif //GLADIATORS_JSON_H
