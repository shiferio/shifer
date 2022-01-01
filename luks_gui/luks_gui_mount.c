#include <gtk/gtk.h>
#include <unistd.h>
#include <string.h>

int main () {
    gtk_init(NULL, NULL);
    GtkWidget *dialog = gtk_file_chooser_dialog_new ("Open file",
                                          NULL,
                                          GTK_FILE_CHOOSER_ACTION_OPEN,
                                          "Cancel",  GTK_RESPONSE_CANCEL,
                                          "Open", GTK_RESPONSE_ACCEPT,
                                          NULL);
    if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT) {
        char cmd[3000] = "/usr/bin/sudo /usr/sbin/cryptsetup luksOpen `/usr/bin/sudo /sbin/losetup --show -f \"";
        strlcat(cmd, gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog)), sizeof(cmd)); // don't use g_free because execl
        strlcat(cmd, "\"` crypt_disk || read", sizeof(cmd));
        execl("/usr/bin/xterm", "/usr/bin/xterm", "-e", "/bin/bash", "-c", cmd, (char *) 0);
    }
//    gtk_widget_destroy (dialog); //comment because the program ends
    return 0;
}
