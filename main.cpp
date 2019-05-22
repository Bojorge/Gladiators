#include <iostream>
#include <gtk/gtk.h>
#include <gtk/gtkmain.h>
#include  "list.h"
#include "list.cpp"
#include "AStar.h"
#include "Gladiador.h"
#include "Torres.h"
#include <string>
#include "TCPclient.h"
#include "Json.h"
#include "BackTrack.h"
GtkWidget *window;
GtkWidget *tablero, *lienzo, *caja,*barra,*texto, *label;
GdkEvent click;
int mousex,mousey;
int ataq=0;
int alcanc=0;
//Se definen los interrupsotes
int pathfinding=2;
bool RecibirGladiadores=false;
bool EnviarGladiadores=false;
bool RecibirTorres= false;
bool EnviarTorres=false;
bool enJuego=false;
bool Gmuertos=false;
typedef pair<int, int> Pair;

Pair fin=make_pair(19,19);

bool torre_seleccionada=false;
static gboolean movimiento_mouse(GtkWidget *widget, GdkEvent *event, gpointer user_data);

static gboolean my_keypress_function(GtkWidget *widget, GdkEventKey *event, gpointer user_data);

static gboolean btn_press_callback(GtkWidget *widget, GdkEventButton *event, gpointer user_data);

List <Gladiador> gladiadores;
List<Gladiador> gladiadoresTablero;
List<Torres> torres;
List<Torres> torresTablero;
List<Gladiador> gladiadoresmuertos;
Lista listaBT;
Json serial;
AStar caminoAstar;
BackTrack caminobckt;

typedef pair<int, int> Pair;

int grid[COLUMNA][FILA] =
        {
                { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
        };

Torres torr1;
Torres torr2;
Torres torr3;
Torres torr4;
Torres torr5;
Torres torr6;
Torres torr7;
Torres torr8;
Torres torr9;
Torres torr10;
Gladiador g1;
Gladiador g2;
Gladiador g3;
Gladiador g4;
Gladiador g5;



int sockfd;
TCPclient *cliente=new TCPclient();
string mensaje;

void *coneccion(void*) {

    while (true){
        mensaje = cliente->pruebabuff();
        sockfd=cliente->get_sockfd();
    }
}
void *controlComunicacion(void*){

    cliente->iniciar();
    string pedir = "1";
    cliente->enviarPaquete(sockfd, pedir);
    printf("enviando POST \n");
    string GyT = cliente->pruebabuff();
    vector<string> GldsyTrrs = serial.split(GyT, "-");
    //cliente->terminarConexion();
    string pqglads = GldsyTrrs[0];
    vector<string> gds = serial.split(pqglads, ";");
    for (int m = 0; m <= gds.size() - 1; m++) {
        Gladiador gladiadorDes = serial.deserealizarGladiador(gds[m]);
        cout << "agregando a " << gladiadorDes.getResistencia() << endl;
        gladiadores.add_head(gladiadorDes);
    }
    string paqetdetorres=GldsyTrrs[1];
    cout << paqetdetorres << endl;

    string pqtorres = GldsyTrrs[1];
    vector<string> trrs = serial.split(pqtorres, ";");
    for (int m = 0; m <= trrs.size() - 1; m++) {
        Torres torreDes = serial.desearilzarTorre(trrs[m]);
        cout << "agregando a " << torreDes.getAlcance() << endl;
        torres.add_head(torreDes);
        enJuego = true;
    }
    //---------------------------------CONTROL DE POST Y GET------------------
    while(true){
        //--------POST GLADIADORES--------
        if(EnviarGladiadores==true){
            sleep(1);
            string paquete="8";
            for(int i=0;i<=gladiadoresmuertos.size()-1;i++){
                string gldrs=serial.serializadorGladiador(gladiadoresmuertos.getbyposicion(i));
                if (i==0){
                    paquete=paquete+gldrs;
                }else {
                    cout << "agregando" << gldrs << endl;
                    paquete = paquete + ";" + gldrs;
                }
            }
            cliente->iniciar();
            cliente->enviarPaquete(sockfd, paquete);
            cout<<"enviando"<<paquete<<endl;
            EnviarGladiadores=false;
            //sleep(1);
            RecibirGladiadores=true;
        }
        //-------------GET GLADIADORES-----------
        if(RecibirGladiadores==true){

            string glads = mensaje;
            cliente->terminarConexion();
            cout<<"gladiadores que llegan "<<glads<<endl;
            vector<string> gds = serial.split(glads, ";");
            for (int m = 0; m <= gds.size() - 1; m++) {
                Gladiador gladiadorDes = serial.deserealizarGladiador(gds[m]);
                cout << "agregando a " << gladiadorDes.getName() << endl;
                gladiadores.add_head(gladiadorDes);
            }
            RecibirGladiadores=false;
            EnviarTorres=true;
        }
        //--------POST TORRES--------
        if (EnviarTorres==true){
            string paqueteTrs="#";
            for(int i=0;i<=torres.size()-1;i++){
                string trrs=serial.serializarTorreta(torres.getbyposicion(i));
                if (i==0){
                    paqueteTrs=paqueteTrs+trrs;
                }else {
                    paqueteTrs = paqueteTrs + ";" + trrs;
                }
            }
            cout<<"enviando"<<paqueteTrs<<endl;
            cliente->iniciar();
            cliente->enviarPaquete(sockfd, paqueteTrs);
            EnviarTorres=false;
            RecibirTorres=true;
            sleep(1);
        }
        //-------------GET TORRES-----------
        if(RecibirTorres==true){
            //string paquete="3";
            //cliente->enviarPaquete(sockfd, paquete);
            string pqtrs=mensaje;
            cout<<"recibiendo  "<<pqtrs<<endl;
            cliente->terminarConexion();
            //pqtrs = cliente->pruebabuff();
            vector<string> trs = serial.split(pqtrs, ";");
            for (int m = 0; m <= trs.size() - 1; m++) {
                Torres torreDes = serial.desearilzarTorre(trs[m]);
                cout << "agregando a " << torreDes.getAlcance() << endl;
                torres.add_head(torreDes);
            }
            RecibirGladiadores=false;
            enJuego=true; //SE INICIA LA RONDA
        }
    }
}
void *mensajes(void*) {
    //torr7.setX(14);
    //torr7.setY(12);
    torr1.setDano(2);
    torr1.setAlcance(1);
    torr2.setDano(2);
    torr2.setAlcance(1);
    torr3.setDano(2);
    torr3.setAlcance(1);
    torr4.setDano(2);
    torr4.setAlcance(1);
    torr5.setDano(2);
    torr5.setAlcance(1);

    torr8.setX(14);
    torr8.setY(13);
    torr8.setDano(2);
    torr8.setAlcance(1);

    //torr9.setX(14);
    //torr9.setY(14);
    torr9.setDano(2);
    torr9.setAlcance(1);

    //torr10.setX(14);
    //torr10.setY(15);
    torr10.setDano(5);
    torr10.setAlcance(2);


    g1.setResistencia(200);
    g2.setResistencia(300);
    g3.setResistencia(300);
    g4.setResistencia(300);

    g1.setName("Peter 1");
    g2.setName("Peter 2");
    g3.setName("Peter 3");
    g4.setName("Peter 4");

/*
    gladiadores.add_end(g3);
    gladiadores.add_end(g4);
    gladiadores.add_end(g1);
    gladiadores.add_end(g2);

    torres.add_end(torr10);
    torres.add_end(torr8);
    torres.add_end(torr9);
    enJuego = true;
    //sleep(1);
*/
    while (true) {
        //si se esta en partida y ya no hay torres-------------------------------> SE TERMINA LA RONDA
        if (enJuego == true) {
            if (gladiadoresTablero.size() == 0 && gladiadoresmuertos.size() >= 2) {
                printf("se termina la ronda \n");
                enJuego = false;    // se pausa para la comunicacion
                EnviarGladiadores = true;  //se inicia el proceso de POST Y GET
                if (pathfinding == 1) {
                    pathfinding = 2;
                } else {
                    pathfinding = 1;
                }
            }
        }
        //--------------------------------------------------------------------------------------------------------------------------------
        for (int t = 0; t <= gladiadoresTablero.size() - 1; t++) {
            if (gladiadoresTablero.getbyposicion(t).getX() == 19 && gladiadoresTablero.getbyposicion(t).getY() == 19) {
                Gladiador final = gladiadoresTablero.getbyposicion(t);
                gladiadoresmuertos.add_head(final);
                gladiadoresTablero.del_by_position(t+1);
                cout << "un gladiador llego a la meta" << endl;
            }
        }

        //espacio para funcion que ataque
        for (int i = 0; i < torresTablero.size(); i++) {
            Torres temp = torresTablero.getbyposicion(i);
            int Xtrr = temp.getX();
            int Ytrr = temp.getY();
            int Alct = temp.getAlcance();

            //cout<< " De la torre: " << Xtrr <<" " << Ytrr <<" " << Alct<<endl;

            for (int j = 0; j < gladiadoresTablero.size(); j++) {
                Gladiador gltemp = gladiadoresTablero.getbyposicion(j);
                if (gltemp.getResistencia() <= 0) {
                    gladiadoresmuertos.add_head(gltemp);
                    gladiadoresTablero.del_by_position(j + 1);
                    printf("gladiador muerto \n");
                    //cout << gladiadoresTablero.size() << " gladiadores tablero \n";
                    //cout << gladiadoresmuertos.size() << " gladiadores muertos \n";
                } else {
                    int Xgl = gltemp.getX() + 1;
                    int Ygl = gltemp.getY() + 1;
                    //cout <<"esta es la resistencia de gl"<< j << ": " <<  gltemp.getResistencia()<<endl;
                    //cout<< " Del gladiador: " << Xgl <<" " << Ygl <<endl;
                    if (Xgl <= (Xtrr + Alct) && Xgl >= (Xtrr - Alct) && Ygl <= (Ytrr + Alct) &&
                        Ygl >= (Ytrr - Alct)) {
                        gltemp.setAtacado(true);
                        //cout << "Esta Disparando a: gl"<< j << endl;
                        gltemp.setResistencia(gltemp.getResistencia() - temp.getDano());
                        gladiadoresTablero.change_by_position(gltemp, j + 1);
                        //sleep(1);
                    } else {
                        gltemp.setAtacado(false);
                        gladiadoresTablero.change_by_position(gltemp, j + 1);
                    }
                }
            }
        }
        //--------------------------------------------------------------------------------------------------------------------------------

        //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-ASTAR=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
        if (gladiadoresTablero.size() >= 0 && pathfinding == 1) {
            for (int i = 0; i <= gladiadoresTablero.size() - 1; i++) {

                if (gladiadoresTablero.getbyposicion(i).getX() == 19 &&
                    gladiadoresTablero.getbyposicion(i).getY() == 19) {
                    //Gladiador final = gladiadoresTablero.getbyposicion(i);
                    gladiadoresmuertos.add_head(gladiadoresTablero.getbyposicion(i));
                    gladiadoresTablero.del_by_position(i);
                    cout << "un gladiador llego a la meta" << endl;
                    if (gladiadoresTablero.size()==0){
                        Gmuertos=true;
                    }
                }
            }
            //For que hace que los gladiadores del tablero se muevan
                for (int i = 0; i <= gladiadoresTablero.size() - 1; i++) {

                    cout << "gladiadores en tablero:" << gladiadoresTablero.size() << endl;
                    Gladiador glad = gladiadoresTablero.getbyposicion(i);
                    cout << "glad " << i << endl;
                    int psx = glad.getX();
                    int psy = glad.getY();
                    Pair inic = make_pair(psx, psy);
                    Lista sig;
                    sig = caminoAstar.aStarSearch(grid, inic, fin); //se busca el paso siguiente que tiene que dar
                    glad.setX(sig.obtener_dato(2));
                    glad.setY(sig.obtener_dato(3));
                    sig.borrar_Dato(0);
                    sig.borrar_Dato(0);
                    gladiadoresTablero.change_by_position(glad, i + 1); //se le inserta al gladiador la nueva posicion
                    cout << gladiadoresTablero.getbyposicion(i).getX() << endl;
                    cout << gladiadoresTablero.getbyposicion(i).getY() << endl;
                    sleep(1); //tiempo de espera entre cada gladiador

                }
                //FOR que agrega los gladiadores de la lista a el tablero si estan en la lista de espera
                if (gladiadores.size() >= 1 && pathfinding == 1 && Gmuertos==false) {//si hay gladiadores sin colocar
                    printf("metiendo");
                    Gladiador gl = gladiadores.getbyposicion(0);
                    gl.setX(0);
                    gl.setY(0);
                    gladiadoresTablero.add_end(gl);
                    enJuego = true;
                    gladiadores.del_by_position(1);
                    sleep(1);
                }

    }
    //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=BACKTRAKING=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
        if (pathfinding==2) {
            for (int t = 0; t <= gladiadoresTablero.size() - 1; t++) {
                if (gladiadoresTablero.getbyposicion(t).getX() == 19 && gladiadoresTablero.getbyposicion(t).getY() == 19) {
                    Gladiador final = gladiadoresTablero.getbyposicion(t);
                    gladiadoresmuertos.add_head(final);
                    gladiadoresTablero.del_by_position(t+1);
                    cout << "un gladiador llego a la meta" << endl;
                }
            }
            //si hay gladiadores en la lista de espera se agreagan al tablero
            if (gladiadoresTablero.size() > 0) {
                for (int i = 0; i <= gladiadoresTablero.size() - 1; i++) {
                    Gladiador gdr = gladiadoresTablero.getbyposicion(i);
                    int x = gdr.getX();
                    int y = gdr.getY();
                    int nextx = listaBT.obtener_dato(gdr.getPos());
                    int nexty = listaBT.obtener_dato(gdr.getPos() + 1);
                    gdr.setX(nextx);
                    gdr.setY(nexty);
                    gdr.setPos(gdr.getPos() + 2);
                    gladiadoresTablero.change_by_position(gdr, i + 1); //se le inserta al gladiador la nueva posicion
                    sleep(1);

                };
            }
            //si ya todas las torres estan colocadas inician los gladiadores
            if (torres.size() == 0) {
                listaBT = caminobckt.backTracking(grid);
                listaBT.borrar_Dato(0);
                listaBT.borrar_Dato(0);
                listaBT.print_lista();
                if (gladiadores.size() > 0) {
                    Gladiador gl = gladiadores.getbyposicion(0);
                    gl.setX(0);
                    gl.setY(0);
                    gladiadoresTablero.add_end(gl);
                    enJuego=true;
                    gladiadores.del_by_position(1);
                    sleep(1);
                }
        }
        }

        }
    };

    void *grafica(void *) {
        gtk_main();

    };

    int main(int argc, char *argv[]) {
        //torres.add_end(torr1);
        //torres.add_end(torr3);
        //torres.add_end(torr4);
        //torres.add_end(torr5);
        ////torr6.setX(4);

        typedef pair<int, int> Pair;
        AStar pathfinding;
        /* Descripcion de la cuadricula
        1--> La celda esta habilitada
        0--> La celda esta bloqueada */

        gtk_init(NULL, NULL);

        gdouble mx, my;

        //printf("cordenaas: (%u,%u)\n", mousex, mousey);

// SE INICIAN LA CREACION DE LA VENTANA
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        lienzo = gtk_fixed_new();
        caja = gtk_event_box_new();
        label = gtk_label_new("Torres");
        gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window),1200,830);
        gtk_window_set_resizable(GTK_WINDOW(window),FALSE);
        gtk_widget_add_events(window, GDK_KEY_PRESS_MASK);
        gtk_window_set_title(GTK_WINDOW(window), " Tablero Gladiators");
        tablero = gtk_image_new_from_file("tab.jpg");
        gtk_container_add(GTK_CONTAINER(lienzo), tablero);
        gtk_container_add(GTK_CONTAINER(window), lienzo);
        g_signal_connect(G_OBJECT(window), "destroy",
                         G_CALLBACK(gtk_main_quit), NULL);
        g_signal_connect(G_OBJECT(window), "motion-notify-event", G_CALLBACK(movimiento_mouse), NULL);
        gtk_widget_set_events(window, GDK_POINTER_MOTION_MASK);
        g_signal_connect (G_OBJECT(window), "key_press_event", G_CALLBACK(my_keypress_function), NULL);
        g_signal_connect(G_OBJECT(window), "button-press-event", G_CALLBACK(btn_press_callback), NULL);
        //gtk_fixed_put(GTK_FIXED(lienzo), pieza_a, 5, 3);

        //for (int i=0;i<=palabras_tablero->tamano();i+3){

        gtk_widget_show_all(window);
        //SE INICIAN LOS THREADS
        pthread_t t3;
        pthread_create(&t3, NULL, &grafica, NULL);
        void *result;
        pthread_t t1;
        pthread_create(&t1, NULL, &coneccion, NULL);
        pthread_t t2;
        pthread_create(&t2, NULL, &mensajes, NULL);
        pthread_t t4;
        pthread_create(&t3, NULL, &controlComunicacion, NULL);
        pthread_join(t2, &result);
        pthread_join(t1, &result);
        pthread_join(t3, &result);


        return 0;
    }


    static gboolean movimiento_mouse(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
        gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("tab.jpg"), 0, 0);

        //gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("gladiador.gif"), gx * 39 + 265, gy * 39 + 32);

        int a = torres.size();
        gchar trrs[20] = "Torres: ";
        sprintf(trrs, "%s%d", trrs, a);

        gchar ataque[20] = "Ataque: ";
        sprintf(ataque, "%s%d", ataque, ataq);

        gchar alc[20] = "Alcance: ";
        sprintf(alc, "%s%d", alc, alcanc);

        gtk_fixed_put(GTK_FIXED(lienzo), gtk_label_new(trrs), 1065, 169);
        gtk_fixed_put(GTK_FIXED(lienzo), gtk_label_new(ataque), 1065, 189);
        gtk_fixed_put(GTK_FIXED(lienzo), gtk_label_new(alc), 1065, 209);

// LOOP QUE IMPRIME LAS TORRES
        if (0 < torresTablero.size()) {
            for (int cont = 0; cont <= torresTablero.size() - 1; cont++) {
                int trrx = torresTablero.getbyposicion(cont).getX();
                int trry = torresTablero.getbyposicion(cont).getY();
                gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("torre2.png"), trrx * 39 + 265,
                              trry * 39 + 32);
                //gtk_widget_show_all(window);
            }
        }
 //LOOP QUE IMPRIME LAS TORRES
        if (0 < gladiadoresTablero.size()) {
            for (int cont2 = 0; cont2 <= gladiadoresTablero.size() - 1; cont2++) {
                int glx = gladiadoresTablero.getbyposicion(cont2).getX();
                int gly = gladiadoresTablero.getbyposicion(cont2).getY();
                gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("torre3.png"), glx * 39 + 265,
                              gly * 39 + 32);
                //gtk_widget_show_all(window);
            }
        }
        //LOOP QUE IMPRIME LA TORRE SELECCIONADA
        if (torre_seleccionada == true) {
            gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("torre2.png"), mousex, mousey);
        }
        gtk_widget_show_all(window);


        if (event->type == GDK_MOTION_NOTIFY) {
            GdkEventMotion *e = (GdkEventMotion *) event;
            mousex = (guint) e->x;
            mousey = (guint) e->y;

        }

    }

    gboolean my_keypress_function(GtkWidget *widget, GdkEventKey *event, gpointer data){


    }
//LOOP que permite el funcionamiento de los botones------------------------
    gboolean btn_press_callback(GtkWidget *btn, GdkEventButton *event, gpointer userdata) {
        if (event->type == GDK_BUTTON_PRESS && event->button == 1) { //SI EL BOTON IZQUIERDO DEL MOUSE SE PULSO
            int matx = (mousex - 265) / 39; //CON LAS COORDENADAS  MOUSEX,MOUSEY
            int maty = (mousey - 32) / 39;
    //SI HABIA UNA TORRE SELECCIONADA  Y EL ESPACIO ESTA DISPONIBLE EN LA MATRIZ
            if (torre_seleccionada && grid[matx][maty] == 0) {
                Torres t = torres.getbyposicion(torres.size() - 1);
                t.setX(matx);               //Se le asignana las coordenadas de donde se pulso
                t.setY(maty);
                grid[matx][maty] = 1;
                torresTablero.add_end(t);   //Se agrega la torre al tablero
                torres.del_by_position(torres.size());  //se elimina de la lista de espera
                printf("se agrego una torre al tablero \n");
                torre_seleccionada = false;
            }
    //Si no habia torre seleccionada
            if (torre_seleccionada == false) {
                // Se busca si hay una torre en esa casilla para dar la informacion
                for (int i = 0; i <= torresTablero.size() - 1; i++) {
                    if (torresTablero.getbyposicion(i).getX() == matx &&
                        torresTablero.getbyposicion(i).getY() == maty) {
                        ataq = torresTablero.getbyposicion(i).getDano();   //Se muestra informacion del ataque de la torre
                        alcanc = torresTablero.getbyposicion(i).getAlcance(); // Se muestra el alcance
                    }
                }
            }
    //Si se preciono en el boton de la torre
            if (torres.size() > 0 && mousey > 298 && mousey < 423 && mousex > 1062 && mousex < 1147 &&
                torre_seleccionada == false) {
                printf("torre 2 seleccionada \n");
                torre_seleccionada = true;  //se activa el arrastre de la torre
            }
        }
    }

