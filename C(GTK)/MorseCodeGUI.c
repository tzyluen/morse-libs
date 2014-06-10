#include <gtk/gtk.h>
#include <string.h>
#include "morse.h"

void btn_translate_clicked(GtkWidget *, gpointer);
void close_app(GtkWidget *, gpointer);
static Morse_map *mm;
static GtkWidget *entry_input, *entry_output;

int main (int argc, char *argv[])
{
    /* declares GtkWidget pointer variables */
    GtkWidget *window;
    GtkWidget *lbl_input, *lbl_output;
    GtkWidget *hbox1, *hbox2;
    GtkWidget *vbox1;
    GtkWidget *btn_translate;

    /* gtk_init initializes GTK+ and all of its supporting libraries */
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);                         /* create the top level window */
    gtk_window_set_title(GTK_WINDOW(window), "Morse Code Translator");    /* set window title */
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);      /* set window position to center */
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);            /* set window default size */

    /* connect the 'destroy' signal to 'close_app' */
    g_signal_connect(window, "destroy", G_CALLBACK(close_app), NULL);

    /* create the GUI objects */
    lbl_input = gtk_label_new("Input");
    lbl_output = gtk_label_new("Output");
    entry_input = gtk_entry_new();
    entry_output = gtk_entry_new();
    btn_translate = gtk_button_new_with_label("Translate");

    /* connect the 'clicked' signal to 'btn_translate_clicked', pass 'entry_input' data to the caller */
    g_signal_connect(btn_translate, "clicked", G_CALLBACK(btn_translate_clicked), entry_input);

    /* organize the GUI objects positions */
    hbox1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    hbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    vbox1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    gtk_label_set_justify(GTK_LABEL(lbl_input), GTK_JUSTIFY_RIGHT);
    gtk_label_set_justify(GTK_LABEL(lbl_output), GTK_JUSTIFY_RIGHT);

    gtk_box_pack_start(GTK_BOX(hbox1), lbl_input, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox1), entry_input, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox1), btn_translate, FALSE, FALSE, 5);

    gtk_box_pack_start(GTK_BOX(hbox2), lbl_output, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox2), entry_output, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(vbox1), hbox1, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(vbox1), hbox2, FALSE, FALSE, 5);

    gtk_container_add(GTK_CONTAINER(window), vbox1);

    gtk_widget_show_all(window);    /* show all widget(components) */
    gtk_main(); /* start main loop; do nothing (block) until application is closed */
 
    return 0;
}


/* btn_translate's clicked signal handler */
void btn_translate_clicked(GtkWidget *button, gpointer data)
{
    mm = Morse_map_create();
    const char *str_input = gtk_entry_get_text(GTK_ENTRY((GtkWidget *)data));

    if (strlen(str_input) > 0)
        gtk_entry_set_text(GTK_ENTRY(entry_output), line_to_morse(str_input, mm));
    else
        gtk_entry_set_text(GTK_ENTRY(entry_output), "insert something");
}


/* clean-up function */
void close_app(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}
