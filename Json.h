//
// Created by gerom on 16/05/19.
//

#ifndef GLADIATORS_JSON_H
#define GLADIATORS_JSON_H
#include "Gladiador.h"
#include "list.h"
#include "list.cpp"
#include "Torres.h"
#include <vector>
#include <bits/stdc++.h>

using namespace std;



class Json{

public:
    string serializadorGladiador(Gladiador gla){
        string String =
                "{\"name\":"+gla.getName() + "\"" +"," +
                "\"edad\":"+ to_string(gla.getEdad()) + "," +
                "\"probSupervivencia\":"+ to_string(gla.getprobSupervivencia()) + "," +
                "\"edad\":"+ to_string(gla.getEdad()) + "," +
                "\"generaciones\":"+ to_string(gla.getGeneraciones()) + "," +
                "\"inteligeniaEmocional\":"+ to_string(gla.getinteligenciaEmocional()) + "," +
                "\"condFisica\":"+ to_string(gla.getcondFisica()) + "," +
                "\"fuerzaSuperior\":"+ to_string(gla.getfuerzaSuperior()) + "," +
                "\"fuerzaInferior\":"+ to_string(gla.getfuerzaInferior()) + "," +
                "\"x\":"+ to_string(gla.getX()) + "," +
                "\"y\":"+ to_string(gla.getY()) + "}";

        return String;
      }
     string serializarTorreta(Torres tor) {
        string string =
                "{\"name\": " + tor.getNombre() + "\"" + "," +
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
    List<Gladiador> deserializarG(string s){
        List<Gladiador> n;
        string na = "";
        int ed = 0; int ps = 0; int ge = 0;int ie = 0;
        int cf = 0;int fs = 0;int fi = 0;int x = 0;int y = 0;
        vector<string> accion = split (s, ";");
        int cont = 1;
        for(int i = 0; i < accion.size(); i++) {
            string r = accion[i];
            vector<string> gladiador = split (r, ",");
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
                if(cont == 2) {int ed = std::stoi(parte[1]);}
                if(cont == 3) {int ps = std::stoi(parte[1]);}
                if(cont == 4) {int ge = std::stoi(parte[1]);}
                if(cont == 5) {int ie = std::stoi(parte[1]);}
                if(cont == 6) {int cf = std::stoi(parte[1]);}
                if(cont == 7) {int fs = std::stoi(parte[1]);}
                if(cont == 8) {int fi = std::stoi(parte[1]);}
                if(cont == 9) {}
                if(cont == 10) {int y = std::stoi(parte[1]);}
                if(cont == 11) {
                    string u = parte[1];
                    vector<string> o = split (u, "}");
                    int y = std::stoi(o[0]);
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
            g.getfuerzaSuperior(fs);
            g.setfuerzaInferior(fi);
            g.setX(x);
            g.setY(y);
            n.add_end(g);
            cont = 1;
        }
        return n;
    }
     List<Torres> deserializarT(string s){
        List<Torres> n;
        string na = "";
        int ge = 0; int di = 0; int ds = 0;int po = 0;
        int ti = 0;int fl = 0;int vl = 0;int at = 0;
        vector<string> accion = split (s, ";");

        int cont = 1;
        for(int i = 0; i < accion.size(); i++) {
            string r = accion[i];
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
                if(cont == 2) {int ge = std::stoi(parte[1]);}
                if(cont == 3) {int di = std::stoi(parte[1]);}
                if(cont == 4) {int ds = std::stoi(parte[1]);}
                if(cont == 5) {int po = std::stoi(parte[1]);}
                if(cont == 6) {int ti = std::stoi(parte[1]);}
                if(cont == 7) {int fl = std::stoi(parte[1]);}
                if(cont == 8) {int vl = std::stoi(parte[1]);}
                if(cont == 9) {
                    string u = parte[1];
                    vector<string> o = split (u, "}");

                    int at = std::stoi(o[0]);

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


                                na,ge,di,ds,po,ti,fl,vl,at);
            n.add_end(g);
            cont = 1;
        }
        return n;
    }

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

};




#endif //GLADIATORS_JSON_H
