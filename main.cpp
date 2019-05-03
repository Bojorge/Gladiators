#include <iostream>
#include <gtk/gtk.h>
#include <gtk/gtkmain.h>
#include  "Lista.h"
#include "AStar.h"
#include "Torre.h"

GtkWidget *window;
GtkWidget *tablero, *lienzo, *caja,*barra,*texto;
GdkEvent click;
int mousex,mousey;
int gx=0;
int gy=0;
int torre_seleccionada=0;
static gboolean movimiento_mouse(GtkWidget *widget, GdkEvent *event, gpointer user_data);

static gboolean my_keypress_function(GtkWidget *widget, GdkEventKey *event, gpointer user_data);

static gboolean btn_press_callback(GtkWidget *widget, GdkEventButton *event, gpointer user_data);

Lista *gladiadores=new Lista();
Lista *gladiadoresTablero=new Lista();
Lista *torres=new Lista();

void *coneccion(void*){
}

void *mensajes(void*){
}
void *grafica(void*){
    gtk_main();
};
int main(int argc,char *argv[]) {
    typedef pair<int, int> Pair;
    AStar pathfinding;
    /* Descripcion de la cuadricula
    1--> La celda esta habilitada
    0--> La celda esta bloqueada */
    int grid[FILA][COLUMNA] =
            {
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
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

            };

    gtk_init(NULL, NULL);

    printf("asdf \n");

    gdouble mx, my;

    //printf("cordenaas: (%u,%u)\n", mousex, mousey);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    lienzo = gtk_fixed_new();
    caja = gtk_event_box_new();
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
    pthread_create(&t3,NULL,&grafica,NULL);


    void*result;
    pthread_t t1;
    pthread_create(&t1,NULL,&coneccion,NULL);
    pthread_t t2;
    pthread_create(&t2,NULL,&mensajes,NULL);
    pthread_join(t2, &result);
    pthread_join(t1,&result);
    pthread_join(t3,&result);


    return 0;
}


static gboolean movimiento_mouse(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    if(torre_seleccionada!=0){
        if (torre_seleccionada==1){
            gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("torre1.png"),mousex,mousey);
        }
        if (torre_seleccionada==2){
            gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("torre2.png"),mousex,mousey);
        }
        if (torre_seleccionada==3){
            gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("torre3.png"),mousex,mousey);
        }
    }
    gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("tab.jpg"),0,0);

    gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("torre1.png"), 15*39+265,16*39+32);
    gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("torre2.png"), 15*39+265,17*39+32);
    gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("torre3.png"), 15*39+265,18*39+32);
    gtk_fixed_put(GTK_FIXED(lienzo), gtk_image_new_from_file("gladiador.gif"), gx*39+265,gy*39+32);


    if (event->type == GDK_MOTION_NOTIFY) {
        GdkEventMotion *e = (GdkEventMotion *) event;
        mousex = (guint) e->x;
        mousey = (guint) e->y;
        //SE PONEN LAS LETRAS DE LAS PALABRAS PRELIMINARES



        gtk_widget_show_all(window);

    }
}

gboolean my_keypress_function(GtkWidget *widget, GdkEventKey *event, gpointer data) {
    if (event->keyval == GDK_KEY_a) {
        gx=gx-1;
        printf("letra presionada!");
    }
    if (event->keyval == GDK_KEY_s) {
        gy=gy+1;
        printf("letra presionada!");
    }
    if (event->keyval == GDK_KEY_d) {
        gx=gx+1;
        printf("letra presionada!");
    }
    if (event->keyval == GDK_KEY_w) {
        gy=gy-1;
        printf("letra presionada!");
    }

}

gboolean btn_press_callback(GtkWidget *btn, GdkEventButton *event, gpointer userdata) {
    if (event->type == GDK_BUTTON_PRESS && event->button == 1)
        //
        if (mousey>158 && mousey<283 && mousex>1062 && mousex<1147){
            torre_seleccionada=1;
        }
        if (mousey>298 && mousey<423 && mousex>1062 && mousex<1147){
            torre_seleccionada=2;
        }
        if (mousey>439 && mousey<564 && mousex>1062 && mousex<1147){
            torre_seleccionada=3;
        }
        //MANEJO DE LA MATRIZ GRAFICA
        if(torre_seleccionada!=0){
            Torre *torre1=new Torre();
            torre1->setX(mousex);
            torre1->setY(mousey);
            //torres->anadir_final(torre1*);
            torre_seleccionada=0;
        }
}