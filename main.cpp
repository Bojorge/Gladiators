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

int pathfinding=1;

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
int contadorBT=1;

typedef pair<int, int> Pair;

int grid[COLUMNA][FILA] =
        {
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
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


bool RecibirGladiadores=false;
bool EnviarGladiadores=false;
bool enJuego=true;
int sockfd;
TCPclient *cliente=new TCPclient();
string mensaje;

void *coneccion(void*) {
    /*
    //Se envia el POPULATIONS Y SE RECIBEN LAS DOS LISTAS
    cliente->iniciar();
    sockfd = cliente->get_sockfd();
    string pedir = "1";
    cliente->enviarPaquete(sockfd, pedir);
    mensaje = cliente->pruebabuff();
    vector<string> gen = serial.split(mensaje, "-");
    string glads = gen[0];
    vector<string> gds = serial.split(glads, ";");
    for (int m = 0; m <= gds.size() - 1; m++) {
        Gladiador gladiadorDes = serial.deserealizarGladiador(gds[m]);
        cout << "agregando a " << gladiadorDes.getName() << endl;
        gladiadores.add_head(gladiadorDes);
        //SE ENVIA LA POBLACION DE GLADIADORES
        string glsAenviar;
        for (int k = 0; gladiadoresmuertos.size() - 1 <= k; k++) {
            string gladAenviar = serial.serializadorGladiador(gladiadoresmuertos.getbyposicion(k));
        }
        cout << mensaje << endl;
        //string pedir2="2";
        //cliente->enviarPaquete(sockfd,pedir2);
        if (mensaje.compare("algo") == true) {
            //}
        }
    }
     */
}

void *controlComunicacion(void*){
    /*
    while(true){
        if(EnviarGladiadores==8){
            //gladiadoresmuertos.Serializador
            //string paquete=gladiadoresserealizador
            //cliente->enviarPaquete(sockfd, paquete);
            EnviarGladiadores=false;
            sleep(1);
            RecibirGladiadores=true;
        }
        if(RecibirGladiadores==8){
            string paquete="GetGladiadores";
            cliente->enviarPaquete(sockfd, paquete);
            RecibirGladiadores=false;
        }



    }
*/
}

void *mensajes(void*) {


    torr7.setX(14);
    torr7.setY(12);
    torr7.setDano(2);
    torr7.setAlcance(2);


    torr8.setX(14);
    torr8.setY(13);
    torr8.setDano(5);
    torr8.setAlcance(8);

    torr9.setX(14);
    torr9.setY(14);
    torr9.setDano(5);
    torr9.setAlcance(87);

    torr10.setX(14);
    torr10.setY(15);
    torr10.setDano(5);
    torr10.setAlcance(83);

    torresTablero.add_end(torr7);
    sleep(1);
    torresTablero.add_end(torr8);
    sleep(1);
    torresTablero.add_end(torr9);
    //sleep(1);

    while (true) {
        if (enJuego==8){
            if (gladiadoresTablero.size() == 0) {
                //enJuego=false;
                //EnviarGladiadores=true;
            }
        }
        //--------------------------------------------------------------------------------------------------------------------------------

        //espacio para funcion que ataque

        //--------------------------------------------------------------------------------------------------------------------------------
        //funcion que revisa si hay gladiadores muertos o en la meta
        //si hay gladiadores en tablero y la iteracion en Astar
        if (gladiadoresTablero.size() >= 0 && pathfinding==1) {
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


                }
            }
        //FOR que agrega los gladiadores de la lista a el tablero
        if (gladiadores.size() > 0 && pathfinding==1) {//si hay gladiadores sin colocar
            printf("metiendo");
            Gladiador gl = gladiadores.getbyposicion(0);
            gl.setX(0);
            gl.setY(0);
            gladiadoresTablero.add_end(gl);
            gladiadores.del_by_position(1);
            sleep(1);
        }
        if (pathfinding==2){
            if(torres.size()==0){
                Gladiador gl = gladiadores.getbyposicion(0);
                gl.setX(0);
                gl.setY(0);
                gladiadoresTablero.add_end(gl);
                gladiadores.del_by_position(1);
            }
            if(gladiadoresTablero.size()>0){
                listaBT=caminobckt.backTracking(grid);
                for (int i = 0; i <= gladiadoresTablero.size() - 1; i++) {
                    Gladiador gdr=gladiadoresTablero.getbyposicion(i);
                    int x=gdr.getX();
                    int y=gdr.getY();
                    int nextx=listaBT.obtener_dato(contadorBT-i);
                    int nexty=listaBT.obtener_dato(contadorBT-i-1);
                    gdr.setX(nextx);
                    gdr.setY(nexty);
                    gladiadoresTablero.change_by_position(gdr, i + 1); //se le inserta al gladiador la nueva posicion

                }
                contadorBT++;
            }
        }

        if (gladiadoresTablero.size() > 0 && pathfinding==2) {
            //si hay gladiadores en tablero


        }
        if (torres.size()==0 && pathfinding==2){

            if (gladiadores.size() > 0) {//si hay gladiadores sin colocar

            }
        }


            //FOR que agrega los gladiadores de la lista a el tablero

        }
    };

    void *grafica(void *) {
        gtk_main();

    };
    void colocar(int x, int y) {
        Torres t = torres.getbyposicion(0);

        torres.getbyposicion(0).setX(x);
        torres.getbyposicion(0).setY(y);
        grid[x][y] = 1;
        torresTablero.add_end(torres.getbyposicion(0));
        torres.del_by_position(0);
        printf("se agrego una torre al tablero \n");


    }


    int main(int argc, char *argv[]) {
        torres.add_end(torr1);
        torres.add_end(torr3);
        torres.add_end(torr4);
        torres.add_end(torr5);
        torr6.setX(4);
        torr6.setY(5);
        torresTablero.add_end(torr6);

        typedef pair<int, int> Pair;
        AStar pathfinding;
        /* Descripcion de la cuadricula
        1--> La celda esta habilitada
        0--> La celda esta bloqueada */

        gtk_init(NULL, NULL);

        gdouble mx, my;

        //printf("cordenaas: (%u,%u)\n", mousex, mousey);


        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        lienzo = gtk_fixed_new();
        caja = gtk_event_box_new();
        label = gtk_label_new("Torres");

        gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
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
        gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("torre1.png"), 15 * 39 + 265, 16 * 39 + 32);
        gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("torre2.png"), 15 * 39 + 265, 17 * 39 + 32);
        gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("torre3.png"), 15 * 39 + 265, 18 * 39 + 32);
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


        if (0 < torresTablero.size()) {
            for (int cont = 0; cont <= torresTablero.size() - 1; cont++) {
                int trrx = torresTablero.getbyposicion(cont).getX();
                int trry = torresTablero.getbyposicion(cont).getY();
                gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("torre2.png"), trrx * 39 + 265,
                              trry * 39 + 32);
                //gtk_widget_show_all(window);
            }
        }
        if (0 < gladiadoresTablero.size()) {
            for (int cont2 = 0; cont2 <= gladiadoresTablero.size() - 1; cont2++) {
                int glx = gladiadoresTablero.getbyposicion(cont2).getX();
                int gly = gladiadoresTablero.getbyposicion(cont2).getY();
                gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("gladiador.gif"), glx * 39 + 265,
                              gly * 39 + 32);
                //gtk_widget_show_all(window);
            }
        }
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
//Funcion que permite el funcionamiento de los botones
    gboolean btn_press_callback(GtkWidget *btn, GdkEventButton *event, gpointer userdata) {
        if (event->type == GDK_BUTTON_PRESS && event->button == 1) {
            int matx = (mousex - 265) / 39;
            int maty = (mousey - 32) / 39;
            if (torre_seleccionada && grid[matx][maty] == 0) {
                Torres t = torres.getbyposicion(torres.size() - 1);
                t.setX(matx);
                t.setY(maty);
                grid[matx][maty] = 1;
                torresTablero.add_end(t);
                torres.del_by_position(torres.size());
                printf("se agrego una torre al tablero \n");
                torre_seleccionada = false;
            }
            if (torre_seleccionada == false) {
                for (int i = 0; i <= torresTablero.size() - 1; i++) {
                    if (torresTablero.getbyposicion(i).getX() == matx &&
                        torresTablero.getbyposicion(i).getY() == maty) {
                        ataq = torresTablero.getbyposicion(i).getDano();
                        alcanc = torresTablero.getbyposicion(i).getAlcance();
                    }
                }
            }
            if (torres.size() > 0 && mousey > 298 && mousey < 423 && mousex > 1062 && mousex < 1147 &&
                torre_seleccionada == false) {
                printf("torre 2 seleccionada \n");
                torre_seleccionada = true;
            }

        }
    }

