#include <iostream>
#include <string>
#include <gtk/gtk.h>
#include <stdio.h>
using std::string;
using std::to_string;

using std::cout;
using std::cin;

string cardType(int n){
	switch(n){
		case 3:
			return "Amex";
		case 4:
			return "Visa";
		case 5:
			return "Mastercard";
		default:
			return "is not a Visa/mastercard or Amex";
	}
}

void verify(GtkWidget *widget, GtkWidget *credit_num){
	int total = 0;
	// cout << "Enter your card number: ";
	// cin >> card_num; // enter card number
	GtkEntryBuffer *buf = gtk_entry_get_buffer(GTK_ENTRY(credit_num));
	const char* name = gtk_entry_buffer_get_text(buf);
	string card_num(name);
	int card_size = card_num.size();

	if(card_size != 16){
		cout << "The credit card is not valid\n";
		return;
	}
	
	for (int i=0;i<card_size;i++){ // look through each number
		
		if (i % 2 == 0 || i==0){ // if the number is not even add it to the total
			int product = (card_num[i] - '0') * 2;
			if (product >=10){
				string number = to_string(product);	
				int add = (number[0] - '0') + (number[1] - '0');
				total += add;
			}
			else{
				total += product;
			}	
		}
		else if (i%2 != 0){
			int product = (card_num[i] - '0') * 1;
			total += product;
		}
	}

	if (total %10 ==0){
		cout << "The credit card is valid\n";
		cout << "This is a card " << cardType((card_num[0] - '0')) << " card";
	}
	else{
		cout << "The credit card is not valid\n";
	}

}

void activate(GtkApplication *app, gpointer user_data) {
	GtkWidget *window, *button, *box, *dropdown, *credit_num;

	
	window = gtk_application_window_new(app);
	button = gtk_button_new_with_label("Validate");
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	credit_num = gtk_entry_new();

	gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
	gtk_widget_set_valign(box, GTK_ALIGN_CENTER);

	gtk_window_set_child(GTK_WINDOW(window), box);
	gtk_box_append(GTK_BOX(box), credit_num);
	gtk_box_append(GTK_BOX(box), button);

	g_signal_connect(button, "clicked", G_CALLBACK(verify), credit_num);

	gtk_window_set_title(GTK_WINDOW(window), "Main application window");
	gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

	gtk_widget_show(window);
}

int main(int argc, char *argv[]) {
	GtkApplication *app;
	int status;

	app = gtk_application_new("org.bigbois.example",
	                          G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);

	g_object_unref(app);

	return status;
}


