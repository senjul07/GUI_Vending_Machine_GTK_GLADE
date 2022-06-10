//compile: gcc `pkg-config --cflags gtk+-3.0` "main.c" -o "main" `pkg-config --libs gtk+-3.0`
//execute: ./main

#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>


const int screenWidth = 1366, screenHight = 768;
int boxU_space, nboxU_space, boxU_side_margin, boxU_main_width;
int logo_width, logo_hight;
int imBack_width, imBack_hight;
int boxU_label_margin;
char *num1 = "0";
char *num2 = "0";
char *num3 = "0";
int pay = 0;
int sugar = 0;
int nummenu = 0;
int pilihmenu = 0;
int pilihharga = 0;
char format[200];
char markup_text[200];

char pilihan[17][50] = {
	"Espresso",
	"Macchiato",
	"Cappuccino",
	"Americano",
	"Mocha",
	"Cafe Latte",
	"Vienna Coffee",
	"Flat White",
	"Chocolate Milk",
	"Latte Macchiato",
	"Frappe",
	"Glace",
	"Cappuccino Freddo",
	"Freddo",
	"Caramel Frappe",
	"Irish Coffee",
	"Espresso Laccino"
};

char imgpilihan[17][50] = {
	"img/logo_bt1.png",
	"img/logo_bt2.png",
	"img/logo_bt3.png",
	"img/logo_bt4.png",
	"img/logo_bt5.png",
	"img/logo_bt6.png",
	"img/logo_bt7.png",
	"img/logo_bt8.png",
	"img/logo_bt9.png",
	"img/logo_bt10.png",
	"img/logo_bt11.png",
	"img/logo_bt12.png",
	"img/logo_bt13.png",
	"img/logo_bt14.png",
	"img/logo_bt15.png",
	"img/logo_bt16.png",
	"img/logo_bt17.png"
};

char harga[17][50] = {
	"Rp50000",
	"Rp60000",
	"Rp55000",
	"Rp52000",
	"Rp59000",
	"Rp60000",
	"Rp63000",
	"Rp65000",
	"Rp58000",
	"Rp50000",
	"Rp60000",
	"Rp55000",
	"Rp52000",
	"Rp59000",
	"Rp60000",
	"Rp63000",
	"Rp65000"
};


char imgpay[5][50] = {
	"img/gopay.png",
	"img/dana.png",
	"img/ovo.png",
	"img/linkaja.png",
	"img/shopeepay.png"
};

GtkCssProvider *cssProvider;
GtkBuilder *builder;

//====================================================================//

//mainWindow
GtkWidget *windowMain;
GtkWidget *boxW; 
GtkWidget *boxW_grid;
GtkWidget *hello_logo;
GtkWidget *btn_hel;
GtkWidget *btn_lb_hel;

//window menu
GtkWidget *windowMenu;
GtkWidget *boxU, *boxU1, *boxU2, *stack1, *sw1, *menuC1, *menuC2;
GtkWidget *boxU1_grid1, *boxU2_grid1, *boxU1_H1, *boxU1_H2;
GtkWidget *btn1_U1, *btn2_U1, *btn3_U1, *btn4_U1, *btn5_U1, *btn6_U1, *btn7_U1, *btn8_U1, *btn9_U1;
GtkWidget *btn1_U2, *btn2_U2, *btn3_U2, *btn4_U2, *btn5_U2, *btn6_U2, *btn7_U2, *btn8_U2;
GtkWidget *btn1_U1_U1, *btn2_U1_U2,  *btn3_U1_U3, *btn4_U1_U4, *btn5_U1_U5, *btn6_U1_U6, *btn7_U1_U7, *btn8_U1_U8, *btn9_U1_U9, *btnU1_cancel;
GtkWidget *btn1_U2_U1, *btn2_U2_U2,  *btn3_U2_U3, *btn4_U2_U4, *btn5_U2_U5, *btn6_U2_U6, *btn7_U2_U7, *btn8_U2_U8;
GtkWidget *btn1_U1_logo, *btn2_U1_logo, *btn3_U1_logo, *btn4_U1_logo, *btn5_U1_logo, *btn6_U1_logo, *btn7_U1_logo, *btn8_U1_logo, *btn9_U1_logo;
GtkWidget *btn1_U2_logo, *btn2_U2_logo, *btn3_U2_logo, *btn4_U2_logo, *btn5_U2_logo, *btn6_U2_logo, *btn7_U2_logo, *btn8_U2_logo;
GtkWidget *btn1_U1_lbl1, *btn2_U1_lbl1, *btn3_U1_lbl1, *btn4_U1_lbl1, *btn5_U1_lbl1, *btn6_U1_lbl1, *btn7_U1_lbl1, *btn8_U1_lbl1, *btn9_U1_lbl1,
		  *btn1_U1_lbl2, *btn2_U1_lbl2, *btn3_U1_lbl2, *btn4_U1_lbl2, *btn5_U1_lbl2, *btn6_U1_lbl2, *btn7_U1_lbl2, *btn8_U1_lbl2, *btn9_U1_lbl2, *btnU1_cancel_lbl, *copywU1_lbl, *boxU1_lbl;
GtkWidget *btn1_U2_lbl1, *btn2_U2_lbl1, *btn3_U2_lbl1, *btn4_U2_lbl1, *btn5_U2_lbl1, *btn6_U2_lbl1, *btn7_U2_lbl1, *btn8_U2_lbl1,
		  *btn1_U2_lbl2, *btn2_U2_lbl2, *btn3_U2_lbl2, *btn4_U2_lbl2, *btn5_U2_lbl2, *btn6_U2_lbl2, *btn7_U2_lbl2, *btn8_U2_lbl2;

//window Temp1
GtkWidget *windowTemp;
GtkWidget *boxT, *MenuT1;
GtkWidget *boxT_H1, *boxT_H2, *boxT1_H1, *boxG_T1, *boxT1, *boxT2;
GtkWidget *boxT2_logo;
GtkWidget *btn1_T1, *btn2_T1, *btn_ok_T1, *btn_exit_T1;
GtkWidget *btn1_T1_B1, *btn2_T1_B1;
GtkWidget *btn1_T1_lbl, *btn2_T1_lbl, *btn_ok_T1_lbl, *btn_exit_T1_lbl, *sugar_lbl, *box_T2_lbl;

//window payment
GtkWidget *windowPay;
GtkWidget *boxP, *menuP1;
GtkWidget *boxP1_grid1, *boxP1_H1, *boxP1_H2, *boxP1_H3, *boxP1_H4;
GtkWidget *btn1_P1, *btn2_P1, *btn3_P1, *btn4_P1, *btn5_P1, *btn6_P1, *btnP1_cancel;
GtkWidget *btn1_P1_P1, *btn2_P1_P1,  *btn3_P1_P1, *btn4_P1_P1, *btn5_P1_P1, *btn6_P1_P1;
GtkWidget *btn1_P1_logo, *btn2_P1_logo, *btn3_P1_logo, *btn4_P1_logo, *btn5_P1_logo, *btn6_P1_logo, *pilihP1_logo;
GtkWidget *btn1_P1_lbl, *btn2_P1_lbl, *btn3_P1_lbl, *btn4_P1_lbl, *btn5_P1_lbl, *btn6_P1_lbl, *btnP1_cancel_lbl, *copywP1_lbl, *pilihP1_lbl1, *pilihP1_lbl2, *pilihP2_lbl, *boxP1_lbl;

//window Kasbon
GtkWidget *windowKasbon;
GtkWidget *boxK, *boxK_b1, *boxK_b2;
GtkWidget *btn1_k_b2, *boxK_img;
GtkWidget *btn1_k_b2_lbl, *boxK_b1_lbl;

//====================================================================//
void Espresso();
void Macchiato();
void Cappuccino();
void Americano();
void Mocha();
void Cafe_Latte();
void Vienna_Coffee();
void Flat_White();
void Chocolate_Milk();
void Latte_Macchiato();
void Frappe();
void Glace();
void Cappuccino_Freddo();
void Freddo();
void Caramel_Frappe();
void Irish_Coffee();
void Espresso_Laccino();

void gtk_windowMain_init();
void gtk_windowMain_setAttrib();
void gtk_windowMain_connect();

static void start_windowMenu();
static void view_windowMenu();
static void close_windowMenu();
void gtk_windowMenu_init();
void gtk_windowMenu_setAttrib();
void gtk_windowMenu_connect();

static void start_windowTemp();
static void close_windowTemp();
static void view_windowTemp();
void gtk_windowTemp_init();
void gtk_windowTemp_setAttrib();
void gtk_windowTemp_connect();

static void start_windowPay();
static void close_windowPay();
static void view_windowPay();
void gtk_windowPay_init();
void gtk_windowPay_setAttrib();
void gtk_windowPay_connect();

static void start_windowKasbon();
static void close_windowKasbon();
static void view_windowKasbon();
static void gopay();
static void dana();
static void ovo();
static void linkaja();
static void shopeepay();
static void paylater();
void gtk_windowKasbon_init();
void gtk_windowKasbon_setAttrib();
void gtk_windowKasbon_connect();

char *IntToStr(int x);

static void sugarplus();
static void sugarmin();

void gtk_builder_and_attrib_init();
void gtk_image_opt(GtkWidget *widget, char *fileName, int width, int hight, int margin_left);

//====================================================================//
//====================================================================//
int main(int argc, char **argv){
	boxU_space = screenWidth/40;
	boxU_side_margin = screenWidth/19;
	boxU_main_width = screenWidth/7;
	nboxU_space = screenWidth/13;
	boxU_label_margin = screenHight/8;

	logo_width = screenWidth/8;
	logo_hight = screenHight/15;
	imBack_width = screenWidth/100;
	imBack_hight = screenHight/40;
	gtk_init(&argc, &argv);
	//setup
	gtk_builder_and_attrib_init();
	
	gtk_windowMain_init();
	gtk_windowMain_connect();
	gtk_windowMain_setAttrib();

	
	start_windowMenu();
	start_windowTemp();
	start_windowPay();
	start_windowKasbon();
	
	//start
	gtk_builder_connect_signals(builder, NULL);
	gtk_widget_show(windowMain);
	g_object_unref(builder);
	gtk_main();
	return 0;
}
//====================================================================//
//====================================================================//

//====================================================================//
//====================================================================//

void gtk_builder_and_attrib_init(){
	builder=gtk_builder_new();
	gtk_builder_add_from_file (builder, "vending_machine.glade", NULL);

	cssProvider = gtk_css_provider_new();
	gtk_css_provider_load_from_path(cssProvider, "main.css", NULL);
}

void gtk_image_opt(GtkWidget *widget, char *fileName, int width, int hight, int margin_left){
	GdkPixbuf *my_img = gdk_pixbuf_new_from_file(fileName, NULL);
	my_img = gdk_pixbuf_scale_simple(my_img, width, hight, GDK_INTERP_BILINEAR);
	gtk_image_set_from_pixbuf(GTK_IMAGE(widget), my_img);
	gtk_widget_set_margin_start(widget, margin_left);
}

//====================================================================//

//Main window
void gtk_windowMain_init(){
	windowMain=GTK_WIDGET(gtk_builder_get_object(builder, "windowMain"));
	boxW=GTK_WIDGET(gtk_builder_get_object(builder, "boxW"));
	boxW_grid=GTK_WIDGET(gtk_builder_get_object(builder, "boxW_grid"));
	btn_hel=GTK_WIDGET(gtk_builder_get_object(builder, "btn_hel"));
	hello_logo=GTK_WIDGET(gtk_builder_get_object(builder, "hello_logo"));
	btn_lb_hel=GTK_WIDGET(gtk_builder_get_object(builder, "btn_lb_hel"));
}

void gtk_windowMain_setAttrib(){
	
	gtk_window_fullscreen(GTK_WINDOW(windowMain));

	gtk_widget_set_name(windowMain, "windowMain");
	gtk_widget_set_name(boxW, "boxW");
	gtk_widget_set_name(boxW_grid, "boxW_grid");
	gtk_widget_set_name(btn_hel, "btn_hel");
	gtk_widget_set_name(hello_logo, "hello_logo");
	gtk_widget_set_name(btn_lb_hel, "btn_lb_hel");
	
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	//set dimension
	int lbl_width = screenWidth/5;
	int lbl_hight = screenHight/10;
	gtk_widget_set_size_request(btn_hel, lbl_width, lbl_hight);
}

void gtk_windowMain_connect(){
	g_signal_connect(windowMain, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(btn_hel, "clicked", G_CALLBACK (view_windowMenu), NULL);
}


static void close_windowMain(){
	g_signal_connect(windowMain, "destroy", G_CALLBACK(gtk_main_quit), NULL);
}

//====================================================================//

//window Menu
static void start_windowMenu(){
	int argc; char **argv;
	gtk_init(&argc, &argv);
	gtk_builder_and_attrib_init();

	gtk_windowMenu_init();
	gtk_windowMenu_setAttrib();
	gtk_windowMenu_connect();

	gtk_builder_connect_signals(builder, NULL);
	gtk_widget_show(windowMenu);
	gtk_widget_hide(windowMenu);
}

static void view_windowMenu(){
	gtk_widget_show(windowMenu);
	gtk_widget_hide(windowMain);
}

//====================================================================//

// window menu
void gtk_windowMenu_init(){
	windowMenu=GTK_WIDGET(gtk_builder_get_object(builder, "windowMenu"));
	menuC1=GTK_WIDGET(gtk_builder_get_object(builder, "boxU1_grid1"));
	menuC2=GTK_WIDGET(gtk_builder_get_object(builder, "boxU2_grid1"));
	boxU=GTK_WIDGET(gtk_builder_get_object(builder, "boxU"));
	boxU1=GTK_WIDGET(gtk_builder_get_object(builder, "boxU1"));
	boxU2=GTK_WIDGET(gtk_builder_get_object(builder, "boxU2"));
	stack1=GTK_WIDGET(gtk_builder_get_object(builder, "stack1"));
	sw1=GTK_WIDGET(gtk_builder_get_object(builder, "sw1"));
	boxU1_H1=GTK_WIDGET(gtk_builder_get_object(builder, "boxU1_H1"));
	boxU1_H2=GTK_WIDGET(gtk_builder_get_object(builder, "boxU1_H2"));

	//button
	btn1_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_U1"));
	btn2_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_U1"));
	btn3_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_U1"));
	btn4_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_U1"));
	btn5_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_U1"));
	btn6_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_U1"));
	btn7_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn7_U1"));
	btn8_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn8_U1"));
	btn9_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn9_U1"));
	btnU1_cancel=GTK_WIDGET(gtk_builder_get_object(builder, "btnU1_cancel"));
	
	btn1_U2=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_U2"));
	btn2_U2=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_U2"));
	btn3_U2=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_U2"));
	btn4_U2=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_U2"));
	btn5_U2=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_U2"));
	btn6_U2=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_U2"));
	btn7_U2=GTK_WIDGET(gtk_builder_get_object(builder, "btn7_U2"));
	btn8_U2=GTK_WIDGET(gtk_builder_get_object(builder, "btn8_U2"));
	
	//button logo
	btn1_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_U1_logo"));
	btn2_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_U1_logo"));
	btn3_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_U1_logo"));
	btn4_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_U1_logo"));
	btn5_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_U1_logo"));
	btn6_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_U1_logo"));
	btn7_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn7_U1_logo"));
	btn8_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn8_U1_logo"));
	btn9_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn9_U1_logo"));
	
	btn1_U2_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_U2_logo"));
	btn2_U2_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_U2_logo"));
	btn3_U2_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_U2_logo"));
	btn4_U2_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_U2_logo"));
	btn5_U2_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_U2_logo"));
	btn6_U2_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_U2_logo"));
	btn7_U2_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn7_U2_logo"));
	btn8_U2_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn8_U2_logo"));

	//box
	btn1_U1_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_U1_U1"));
	btn2_U1_U2=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_U1_U2"));
	btn3_U1_U3=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_U1_U3"));
	btn4_U1_U4=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_U1_U4"));
	btn5_U1_U5=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_U1_U5"));
	btn6_U1_U6=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_U1_U6"));
	btn7_U1_U7=GTK_WIDGET(gtk_builder_get_object(builder, "btn7_U1_U7"));
	btn8_U1_U8=GTK_WIDGET(gtk_builder_get_object(builder, "btn8_U1_U8"));
	btn9_U1_U9=GTK_WIDGET(gtk_builder_get_object(builder, "btn9_U1_U9"));
	
	btn1_U2_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_U2_U1"));
	btn2_U2_U2=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_U2_U2"));
	btn3_U2_U3=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_U2_U3"));
	btn4_U2_U4=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_U2_U4"));
	btn5_U2_U5=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_U2_U5"));
	btn6_U2_U6=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_U2_U6"));
	btn7_U2_U7=GTK_WIDGET(gtk_builder_get_object(builder, "btn7_U2_U7"));
	btn8_U2_U8=GTK_WIDGET(gtk_builder_get_object(builder, "btn8_U2_U8"));

	//label
	btn1_U1_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_U1_lbl1"));
	btn2_U1_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_U1_lbl1"));
	btn3_U1_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_U1_lbl1"));
	btn4_U1_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_U1_lbl1"));
	btn5_U1_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_U1_lbl1"));
	btn6_U1_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_U1_lbl1"));
	btn7_U1_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn7_U1_lbl1"));
	btn8_U1_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn8_U1_lbl1"));
	btn9_U1_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn9_U1_lbl1"));
	btnU1_cancel_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btnU1_cancel_lbl"));
	copywU1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "copywU1_lbl"));
	boxU1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "boxU1_lbl"));
	
	btn1_U1_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_U1_lbl2"));
	btn2_U1_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_U1_lbl2"));
	btn3_U1_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_U1_lbl2"));
	btn4_U1_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_U1_lbl2"));
	btn5_U1_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_U1_lbl2"));
	btn6_U1_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_U1_lbl2"));
	btn7_U1_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn7_U1_lbl2"));
	btn8_U1_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn8_U1_lbl2"));
	btn9_U1_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn9_U1_lbl2"));
	
	btn1_U2_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_U2_lbl1"));
	btn2_U2_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_U2_lbl1"));
	btn3_U2_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_U2_lbl1"));
	btn4_U2_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_U2_lbl1"));
	btn5_U2_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_U2_lbl1"));
	btn6_U2_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_U2_lbl1"));
	btn7_U2_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn7_U2_lbl1"));
	btn8_U2_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "btn8_U2_lbl1"));
	
	btn1_U2_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_U2_lbl2"));
	btn2_U2_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_U2_lbl2"));
	btn3_U2_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_U2_lbl2"));
	btn4_U2_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_U2_lbl2"));
	btn5_U2_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_U2_lbl2"));
	btn6_U2_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_U2_lbl2"));
	btn7_U2_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn7_U2_lbl2"));
	btn8_U2_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "btn8_U2_lbl2"));
}

void gtk_windowMenu_setAttrib(){
	gtk_window_fullscreen(GTK_WINDOW(windowMenu));
	
	gtk_widget_set_name (windowMenu, "windowMenu");
	gtk_widget_set_name (menuC1, "menuC1");
	gtk_widget_set_name (menuC2, "menuC2");
	gtk_widget_set_name (boxU, "boxU");
	gtk_widget_set_name (boxU1, "boxU1");
	gtk_widget_set_name (boxU2, "boxU2");
	gtk_widget_set_name (stack1, "stack1");
	gtk_widget_set_name (sw1, "sw1");
	gtk_widget_set_name (boxU1_H1, "boxU1_H1");
	gtk_widget_set_name (boxU1_H2, "boxU1_H2");

	//button
	gtk_widget_set_name (btn1_U1, "btn1_U1");
	gtk_widget_set_name (btn2_U1, "btn2_U1");
	gtk_widget_set_name (btn3_U1, "btn3_U1");
	gtk_widget_set_name (btn4_U1, "btn4_U1");
	gtk_widget_set_name (btn5_U1, "btn5_U1");
	gtk_widget_set_name (btn6_U1, "btn6_U1");
	gtk_widget_set_name (btn7_U1, "btn7_U1");
	gtk_widget_set_name (btn8_U1, "btn8_U1");
	gtk_widget_set_name (btn9_U1, "btn9_U1");
	gtk_widget_set_name (btnU1_cancel, "btnU1_cancel");
	
	gtk_widget_set_name (btn1_U2, "btn1_U2");
	gtk_widget_set_name (btn2_U2, "btn2_U2");
	gtk_widget_set_name (btn3_U2, "btn3_U2");
	gtk_widget_set_name (btn4_U2, "btn4_U2");
	gtk_widget_set_name (btn5_U2, "btn5_U2");
	gtk_widget_set_name (btn6_U2, "btn6_U2");
	gtk_widget_set_name (btn7_U2, "btn7_U2");
	gtk_widget_set_name (btn8_U2, "btn8_U2");

	//box
	gtk_widget_set_name (btn1_U1_U1, "btn1_U1_U1");
	gtk_widget_set_name (btn2_U1_U2, "btn2_U1_U2");
	gtk_widget_set_name (btn3_U1_U3, "btn3_U1_U3");
	gtk_widget_set_name (btn4_U1_U4, "btn4_U1_U4");
	gtk_widget_set_name (btn5_U1_U5, "btn5_U1_U5");
	gtk_widget_set_name (btn6_U1_U6, "btn6_U1_U6");
	gtk_widget_set_name (btn7_U1_U7, "btn7_U1_U7");
	gtk_widget_set_name (btn8_U1_U8, "btn8_U1_U8");
	gtk_widget_set_name (btn9_U1_U9, "btn9_U1_U9");
	
	gtk_widget_set_name (btn1_U2_U1, "btn1_U2_U1");
	gtk_widget_set_name (btn2_U2_U2, "btn2_U2_U2");
	gtk_widget_set_name (btn3_U2_U3, "btn3_U2_U3");
	gtk_widget_set_name (btn4_U2_U4, "btn4_U2_U4");
	gtk_widget_set_name (btn5_U2_U5, "btn5_U2_U5");
	gtk_widget_set_name (btn6_U2_U6, "btn6_U2_U6");
	gtk_widget_set_name (btn7_U2_U7, "btn7_U2_U7");
	gtk_widget_set_name (btn8_U2_U8, "btn8_U2_U8");

	//label
	gtk_widget_set_name(btn1_U1_lbl1, "btn1_U1_lbl1");
	gtk_widget_set_name(btn2_U1_lbl1, "btn2_U1_lbl1");
	gtk_widget_set_name(btn3_U1_lbl1, "btn3_U1_lbl1");
	gtk_widget_set_name(btn4_U1_lbl1, "btn4_U1_lbl1");
	gtk_widget_set_name(btn5_U1_lbl1, "btn5_U1_lbl1");
	gtk_widget_set_name(btn6_U1_lbl1, "btn6_U1_lbl1");
	gtk_widget_set_name(btn7_U1_lbl1, "btn7_U1_lbl1");
	gtk_widget_set_name(btn8_U1_lbl1, "btn8_U1_lbl1");
	gtk_widget_set_name(btn9_U1_lbl1, "btn9_U1_lbl1");
	gtk_widget_set_name(btnU1_cancel_lbl, "btnU1_cancel_lbl");
	gtk_widget_set_name(copywU1_lbl, "copywU1_lbl");
	gtk_widget_set_name(boxU1_lbl, "boxU1_lbl");
	
	gtk_widget_set_name(btn1_U1_lbl2, "btn1_U1_lbl2");
	gtk_widget_set_name(btn2_U1_lbl2, "btn2_U1_lbl2");
	gtk_widget_set_name(btn3_U1_lbl2, "btn3_U1_lbl2");
	gtk_widget_set_name(btn4_U1_lbl2, "btn4_U1_lbl2");
	gtk_widget_set_name(btn5_U1_lbl2, "btn5_U1_lbl2");
	gtk_widget_set_name(btn6_U1_lbl2, "btn6_U1_lbl2");
	gtk_widget_set_name(btn7_U1_lbl2, "btn7_U1_lbl2");
	gtk_widget_set_name(btn8_U1_lbl2, "btn8_U1_lbl2");
	gtk_widget_set_name(btn9_U1_lbl2, "btn9_U1_lbl2");
	
	gtk_widget_set_name(btn1_U2_lbl1, "btn1_U2_lbl1");
	gtk_widget_set_name(btn2_U2_lbl1, "btn2_U2_lbl1");
	gtk_widget_set_name(btn3_U2_lbl1, "btn3_U2_lbl1");
	gtk_widget_set_name(btn4_U2_lbl1, "btn4_U2_lbl1");
	gtk_widget_set_name(btn5_U2_lbl1, "btn5_U2_lbl1");
	gtk_widget_set_name(btn6_U2_lbl1, "btn6_U2_lbl1");
	gtk_widget_set_name(btn7_U2_lbl1, "btn7_U2_lbl1");
	gtk_widget_set_name(btn8_U2_lbl1, "btn8_U2_lbl1");
	
	gtk_widget_set_name(btn1_U2_lbl2, "btn1_U2_lbl2");
	gtk_widget_set_name(btn2_U2_lbl2, "btn2_U2_lbl2");
	gtk_widget_set_name(btn3_U2_lbl2, "btn3_U2_lbl2");
	gtk_widget_set_name(btn4_U2_lbl2, "btn4_U2_lbl2");
	gtk_widget_set_name(btn5_U2_lbl2, "btn5_U2_lbl2");
	gtk_widget_set_name(btn6_U2_lbl2, "btn6_U2_lbl2");
	gtk_widget_set_name(btn7_U2_lbl2, "btn7_U2_lbl2");
	gtk_widget_set_name(btn8_U2_lbl2, "btn8_U2_lbl2");
	
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	//set dimension
	int imWidth, imHight;
	int im_margin = screenHight/60;
	imWidth=imHight=screenWidth/15;
	gtk_image_opt(btn1_U1_logo, "img/logo_bt1.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn2_U1_logo, "img/logo_bt2.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn3_U1_logo, "img/logo_bt3.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn4_U1_logo, "img/logo_bt4.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn5_U1_logo, "img/logo_bt5.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn6_U1_logo, "img/logo_bt6.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn7_U1_logo, "img/logo_bt7.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn8_U1_logo, "img/logo_bt8.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn9_U1_logo, "img/logo_bt9.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn1_U2_logo, "img/logo_bt10.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn2_U2_logo, "img/logo_bt11.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn3_U2_logo, "img/logo_bt12.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn4_U2_logo, "img/logo_bt13.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn5_U2_logo, "img/logo_bt14.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn6_U2_logo, "img/logo_bt15.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn7_U2_logo, "img/logo_bt16.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn8_U2_logo, "img/logo_bt17.png", imWidth, imHight, im_margin);

	int lbl_width = screenWidth/8;
	int lbl_hight = screenHight/8;
	gtk_widget_set_size_request(btn1_U1_U1, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn2_U1_U2, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn3_U1_U3, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn4_U1_U4, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn5_U1_U5, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn6_U1_U6, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn7_U1_U7, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn8_U1_U8, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn9_U1_U9, lbl_width, lbl_hight);
	
	gtk_widget_set_size_request(btn1_U2_U1, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn2_U2_U2, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn3_U2_U3, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn4_U2_U4, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn5_U2_U5, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn6_U2_U6, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn7_U2_U7, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn8_U2_U8, lbl_width, lbl_hight);
	
	int lbls_width = screenWidth/30;
	int lbls_hight = screenHight/30;
	gtk_widget_set_size_request(btnU1_cancel, lbls_width, lbls_hight);
	
	int lblc_width = screenWidth/80;
	int lblc_hight = screenHight/80;
	gtk_widget_set_size_request(sw1, lblc_width, lblc_hight);

	int gspace_row = screenWidth/65; 
	int gspace_col = screenWidth/65;
	gtk_grid_set_row_spacing(GTK_GRID(menuC1), gspace_row);
	gtk_grid_set_column_spacing(GTK_GRID(menuC1), gspace_col);
	gtk_grid_set_row_spacing(GTK_GRID(menuC2), gspace_row);
	gtk_grid_set_column_spacing(GTK_GRID(menuC2), gspace_col);
	gtk_box_set_spacing(GTK_BOX(boxU), gspace_row);
	gtk_widget_set_margin_top(boxU, boxU_space);
	gtk_widget_set_margin_bottom(boxU, boxU_space);
	gtk_widget_set_margin_start(boxU, boxU_side_margin);
	gtk_widget_set_margin_end(boxU, boxU_side_margin);
}

void gtk_windowMenu_connect(){
	g_signal_connect(windowMenu, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(btnU1_cancel, "clicked", G_CALLBACK (close_windowMenu), NULL);
	g_signal_connect(btn1_U1, "clicked", G_CALLBACK (Espresso), NULL);
	g_signal_connect(btn2_U1, "clicked", G_CALLBACK (Macchiato), NULL);
	g_signal_connect(btn3_U1, "clicked", G_CALLBACK (Cappuccino), NULL);
	g_signal_connect(btn4_U1, "clicked", G_CALLBACK (Americano), NULL);
	g_signal_connect(btn5_U1, "clicked", G_CALLBACK (Mocha), NULL);
	g_signal_connect(btn6_U1, "clicked", G_CALLBACK (Cafe_Latte), NULL);
	g_signal_connect(btn7_U1, "clicked", G_CALLBACK (Vienna_Coffee), NULL);
	g_signal_connect(btn8_U1, "clicked", G_CALLBACK (Flat_White), NULL);
	g_signal_connect(btn9_U1, "clicked", G_CALLBACK (Chocolate_Milk), NULL);
	
	g_signal_connect(btn1_U2, "clicked", G_CALLBACK (Latte_Macchiato), NULL);
	g_signal_connect(btn2_U2, "clicked", G_CALLBACK (Frappe), NULL);
	g_signal_connect(btn3_U2, "clicked", G_CALLBACK (Glace), NULL);
	g_signal_connect(btn4_U2, "clicked", G_CALLBACK (Cappuccino_Freddo), NULL);
	g_signal_connect(btn5_U2, "clicked", G_CALLBACK (Freddo), NULL);
	g_signal_connect(btn6_U2, "clicked", G_CALLBACK (Caramel_Frappe), NULL);
	g_signal_connect(btn7_U2, "clicked", G_CALLBACK (Irish_Coffee), NULL);
	g_signal_connect(btn8_U2, "clicked", G_CALLBACK (Espresso_Laccino), NULL);
}

static void close_windowMenu(){
	gtk_main_quit();
}

//====================================================================//
//====================================================================//

// Window Temp
static void start_windowTemp(){
	int argc; char **argv;
	gtk_init(&argc, &argv);
	gtk_builder_and_attrib_init();

	gtk_windowTemp_init();
	//gtk_windowTemp_setAttrib();
	gtk_windowTemp_connect();

	gtk_builder_connect_signals(builder, NULL);
	gtk_widget_show(windowTemp);
	gtk_widget_hide(windowTemp);
}

void Espresso(){
	view_windowTemp(0,0,0);
}

void Macchiato(){
	view_windowTemp(1,1,1);
}

void Cappuccino(){
	view_windowTemp(2,2,2);
}

void Americano(){
	view_windowTemp(3,3,3);
}

void Mocha(){
	view_windowTemp(4,4,4);
}

void Cafe_Latte(){
	view_windowTemp(5,5,5);
}

void Vienna_Coffee(){
	view_windowTemp(6,6,6);
}

void Flat_White(){
	view_windowTemp(7,7,7);
}

void Chocolate_Milk(){
	view_windowTemp(8,8,8);
}

void Latte_Macchiato(){
	view_windowTemp(9,9,9);
}

void Frappe(){
	view_windowTemp(10,10,10);
}

void Glace(){
	view_windowTemp(11,11,11);
}

void Cappuccino_Freddo(){
	view_windowTemp(12,12,12);
}

void Freddo(){
	view_windowTemp(13,13,13);
}

void Caramel_Frappe(){
	view_windowTemp(14,14,14);
}

void Irish_Coffee(){
	view_windowTemp(15,15,15);
}

void Espresso_Laccino(){
	view_windowTemp(16,16,16);
}

static void view_windowTemp(int num1, int num2, int num3){
	nummenu = num1;
	pilihmenu =  num2;
	pilihharga =  num3;
	gtk_windowTemp_setAttrib();
	gtk_widget_show(windowTemp);
	gtk_widget_hide(windowMenu);
}

//====================================================================//

// Window Temp
void gtk_windowTemp_init(){
	windowTemp=GTK_WIDGET(gtk_builder_get_object(builder, "windowTemp"));
	boxT=GTK_WIDGET(gtk_builder_get_object(builder, "boxT"));
	boxT1_H1=GTK_WIDGET(gtk_builder_get_object(builder, "boxT1_H1"));
	boxT1=GTK_WIDGET(gtk_builder_get_object(builder, "boxT1"));
	boxT2=GTK_WIDGET(gtk_builder_get_object(builder, "boxT2"));
	boxG_T1=GTK_WIDGET(gtk_builder_get_object(builder, "boxG_T1"));
	MenuT1=GTK_WIDGET(gtk_builder_get_object(builder, "gridT"));
	boxT2_logo=GTK_WIDGET(gtk_builder_get_object(builder, "boxT2_logo"));

	//button
	btn1_T1=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_T1"));
	btn2_T1=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_T1"));
	btn_ok_T1=GTK_WIDGET(gtk_builder_get_object(builder, "btn_ok_T1"));
	btn_exit_T1=GTK_WIDGET(gtk_builder_get_object(builder, "btn_exit_T1"));
	
	//box
	btn1_T1_B1=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_T1_B1"));
	btn2_T1_B1=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_T1_B1"));
	boxT_H1=GTK_WIDGET(gtk_builder_get_object(builder, "boxT_H1"));
	boxT_H2=GTK_WIDGET(gtk_builder_get_object(builder, "boxT_H2"));

	//label
	btn1_T1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_T1_lbl"));
	btn2_T1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_T1_lbl"));
	sugar_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "sugar_lbl"));
	box_T2_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "box_T2_lbl"));
	btn_ok_T1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn_ok_T1_lbl"));
	btn_exit_T1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn_exit_T1_lbl"));
}

void gtk_windowTemp_setAttrib(){
	gtk_window_fullscreen(GTK_WINDOW(windowTemp));
	
	gtk_widget_set_name (windowTemp, "windowTemp");
	gtk_widget_set_name (boxT, "boxT");
	gtk_widget_set_name (boxT1, "boxT1");
	gtk_widget_set_name (boxT2, "boxT2");
	gtk_widget_set_name (boxG_T1, "boxG_T1");
	gtk_widget_set_name (boxT1_H1, "boxT1_H1");
	gtk_widget_set_name (boxT2_logo, "boxT2_logo");

	//button
	gtk_widget_set_name (btn1_T1, "btn1_T1");
	gtk_widget_set_name (btn2_T1, "btn2_T1");
	gtk_widget_set_name (btn_ok_T1, "btn_ok_T1");
	gtk_widget_set_name (btn_exit_T1, "btn_exit_T1");
	
	//box
	gtk_widget_set_name (btn1_T1_B1, "btn1_T1_B1");
	gtk_widget_set_name (btn2_T1_B1, "btn2_T1_B1");
	gtk_widget_set_name (boxT_H1, "boxT_H1");
	gtk_widget_set_name (boxT_H1, "boxT_H1");

	//label
	gtk_widget_set_name(btn1_T1_lbl, "btn1_T1_lbl");
	gtk_widget_set_name(btn2_T1_lbl, "btn2_T1_lbl");
	gtk_widget_set_name(sugar_lbl, "sugar_lbl");
	gtk_widget_set_name(box_T2_lbl, "box_T2_lbl");
	gtk_widget_set_name(btn_ok_T1_lbl, "btn_ok_T1_lbl");
	gtk_widget_set_name(btn_exit_T1_lbl, "btn_exit_T1_lbl");
	
	//set dimension
	int imWidth, imHight;
	int im_margin = screenHight/60;
	imWidth=imHight=screenWidth/15;
	char imgstr[100];
	strcpy(imgstr, imgpilihan[nummenu]);
	gtk_image_opt(boxT2_logo, imgstr, imWidth, imHight, im_margin);
	
	char pilihstr1[100];
	char format1[100];
	strcpy(format1, "<span font_desc='cursive 15' foreground='#000000' >%s</span>");
	strcpy(pilihstr1, g_markup_printf_escaped (format1, pilihan[pilihmenu]));
	gtk_label_set_markup(GTK_LABEL(box_T2_lbl), (const gchar *) pilihstr1);
	
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	//set dimension
	int lbl_width = screenWidth/15;
	int lbl_hight = screenHight/15;
	gtk_widget_set_size_request(btn1_T1_lbl, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn2_T1_lbl, lbl_width, lbl_hight);
	gtk_widget_set_size_request(sugar_lbl, lbl_width, lbl_hight);
	
	int lblc_width = screenWidth/10;
	int lblc_hight = screenHight/10;
	
	gtk_widget_set_size_request(box_T2_lbl, lblc_width, lblc_hight);
	
	int lbls_width = screenWidth/30;
	int lbls_hight = screenHight/30;
	gtk_widget_set_size_request(btn_exit_T1_lbl, lbls_width, lbls_hight);
	gtk_widget_set_size_request(btn_ok_T1_lbl, lbls_width, lbls_hight);
	
	int gspace_row = screenWidth/60; 
	int gspace_col = screenWidth/60;
	gtk_grid_set_row_spacing(GTK_GRID(MenuT1), gspace_row);
	gtk_grid_set_column_spacing(GTK_GRID(MenuT1), gspace_col);
	gtk_box_set_spacing(GTK_BOX(boxT), gspace_row);
	gtk_widget_set_margin_top(boxT, boxU_space);
	gtk_widget_set_margin_bottom(boxT, boxU_space);
	gtk_widget_set_margin_start(boxT, boxU_side_margin);
	gtk_widget_set_margin_end(boxT, boxU_side_margin);
}

void gtk_windowTemp_connect(){
	g_signal_connect(windowTemp, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(btn1_T1, "clicked", G_CALLBACK (sugarmin), NULL);
	g_signal_connect(btn2_T1, "clicked", G_CALLBACK (sugarplus), NULL);
	g_signal_connect(btn_ok_T1, "clicked", G_CALLBACK (view_windowPay), NULL);
	g_signal_connect(btn_exit_T1, "clicked", G_CALLBACK (close_windowTemp), NULL);
}

static void close_windowTemp(){
	gtk_widget_hide(windowTemp);
	gtk_widget_show(windowMenu);
}

//====================================================================//
//====================================================================//

//window Pay
static void start_windowPay(){
	int argc; char **argv;
	gtk_init(&argc, &argv);
	gtk_builder_and_attrib_init();

	gtk_windowPay_init();
	//gtk_windowPay_setAttrib();
	gtk_windowPay_connect();

	gtk_builder_connect_signals(builder, NULL);
	gtk_widget_show(windowPay);
	gtk_widget_hide(windowPay);
}

static void view_windowPay(int num1, int num2, int num3){
	gtk_windowPay_setAttrib();
	gtk_widget_show(windowPay);
	gtk_widget_hide(windowTemp);
}

// window Pay
void gtk_windowPay_init(){
	windowPay=GTK_WIDGET(gtk_builder_get_object(builder, "windowPay"));
	menuP1=GTK_WIDGET(gtk_builder_get_object(builder, "boxP1_grid1"));
	boxP=GTK_WIDGET(gtk_builder_get_object(builder, "boxP"));
	boxP1_H1=GTK_WIDGET(gtk_builder_get_object(builder, "boxP1_H1"));
	boxP1_H2=GTK_WIDGET(gtk_builder_get_object(builder, "boxP1_H2"));
	boxP1_H3=GTK_WIDGET(gtk_builder_get_object(builder, "boxP1_H3"));
	boxP1_H4=GTK_WIDGET(gtk_builder_get_object(builder, "boxP1_H4"));

	//button
	btn1_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_P1"));
	btn2_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_P1"));
	btn3_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_P1"));
	btn4_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_P1"));
	btn5_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_P1"));
	btn6_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_P1"));
	btnP1_cancel=GTK_WIDGET(gtk_builder_get_object(builder, "btnP1_cancel"));
	
	//button logo
	btn1_P1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_P1_logo"));
	btn2_P1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_P1_logo"));
	btn3_P1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_P1_logo"));
	btn4_P1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_P1_logo"));
	btn5_P1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_P1_logo"));
	btn6_P1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_P1_logo"));
	pilihP1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "pilihP1_logo"));

	//box
	btn1_P1_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_P1_P1"));
	btn2_P1_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_P1_P1"));
	btn3_P1_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_P1_P1"));
	btn4_P1_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_P1_P1"));
	btn5_P1_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_P1_P1"));
	btn6_P1_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_P1_P1"));

	//label
	btn1_P1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_P1_lbl"));
	btn2_P1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_P1_lbl"));
	btn3_P1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_P1_lbl"));
	btn4_P1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_P1_lbl"));
	btn5_P1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_P1_lbl"));
	btn6_P1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_P1_lbl"));
	btnP1_cancel_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btnP1_cancel_lbl"));
	pilihP1_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "pilihP1_lbl1"));
	pilihP1_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "pilihP1_lbl2"));
	pilihP2_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "pilihP2_lbl"));
	copywP1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "copywP1_lbl"));
	boxP1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "boxP1_lbl"));
}

void gtk_windowPay_setAttrib(){
	gtk_window_fullscreen(GTK_WINDOW(windowPay));

	gtk_widget_set_name (windowPay, "windowPay");
	
	gtk_widget_set_name (menuP1, "menuP1");
	gtk_widget_set_name (boxP, "boxP");
	gtk_widget_set_name (boxP1_H1, "boxP1_H1");
	gtk_widget_set_name (boxP1_H2, "boxP1_H2");
	gtk_widget_set_name (boxP1_H3, "boxP1_H3");
	gtk_widget_set_name (boxP1_H4, "boxP1_H4");

	//button
	gtk_widget_set_name (btn1_P1, "btn1_P1");
	gtk_widget_set_name (btn2_P1, "btn2_P1");
	gtk_widget_set_name (btn3_P1, "btn3_P1");
	gtk_widget_set_name (btn4_P1, "btn4_P1");
	gtk_widget_set_name (btn5_P1, "btn5_P1");
	gtk_widget_set_name (btn6_P1, "btn6_P1");
	gtk_widget_set_name (btnP1_cancel, "btnP1_cancel");

	//box
	gtk_widget_set_name (btn1_P1_P1, "btn1_P1_P1");
	gtk_widget_set_name (btn2_P1_P1, "btn2_P1_P1");
	gtk_widget_set_name (btn3_P1_P1, "btn3_P1_P1");
	gtk_widget_set_name (btn4_P1_P1, "btn4_P1_P1");
	gtk_widget_set_name (btn5_P1_P1, "btn5_P1_P1");
	gtk_widget_set_name (btn6_P1_P1, "btn6_P1_P1");

	//label
	gtk_widget_set_name(btn1_P1_lbl, "btn1_P1_lbl");
	gtk_widget_set_name(btn2_P1_lbl, "btn2_P1_lbl");
	gtk_widget_set_name(btn3_P1_lbl, "btn3_P1_lbl");
	gtk_widget_set_name(btn4_P1_lbl, "btn4_P1_lbl");
	gtk_widget_set_name(btn5_P1_lbl, "btn5_P1_lbl");
	gtk_widget_set_name(btn6_P1_lbl, "btn6_P1_lbl");
	gtk_widget_set_name(btnP1_cancel_lbl, "btnP1_cancel_lbl");
	gtk_widget_set_name(pilihP1_lbl1, "pilihP1_lbl1");
	gtk_widget_set_name(pilihP1_lbl2, "pilihP1_lbl2");
	gtk_widget_set_name(pilihP2_lbl, "pilihP2_lbl");
	gtk_widget_set_name(copywP1_lbl, "copywP1_lbl");
	gtk_widget_set_name(boxP1_lbl, "boxP1_lbl");
	
	gtk_widget_set_name (pilihP1_logo, "pilihP1_logo");
	
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	//set dimension
	int imWidth, imHight;
	int im_margin = screenHight/60;
	imWidth=imHight=screenWidth/15;
	gtk_image_opt(btn1_P1_logo, "img/logo_pay1.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn2_P1_logo, "img/logo_pay2.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn3_P1_logo, "img/logo_pay3.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn4_P1_logo, "img/logo_pay4.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn5_P1_logo, "img/logo_pay5.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn6_P1_logo, "img/logo_pay6.png", imWidth, imHight, im_margin);
	
	char imgstr[100];
	strcpy(imgstr, imgpilihan[nummenu]);
	gtk_image_opt(pilihP1_logo, imgstr, imWidth, imHight, im_margin);
	
	char pilihstr1[100];
	char format1[100];
	strcpy(format1, "<span font_desc='cursive 15' foreground='#000000' >%s</span>");
	strcpy(pilihstr1, g_markup_printf_escaped (format1, pilihan[pilihmenu]));
	gtk_label_set_markup(GTK_LABEL(pilihP1_lbl1), (const gchar *) pilihstr1);
	
	char pilihstr2[100];
	char format2[100];
	strcpy(format2, "<span font_desc='cursive 15' foreground='#000000' >%s</span>");
	strcpy(pilihstr2, g_markup_printf_escaped (format2, harga[pilihharga]));
	gtk_label_set_markup(GTK_LABEL(pilihP1_lbl2), (const gchar *) pilihstr2);
	
	num3 = IntToStr(sugar);
	strcpy(format, "<span font_desc='cursive 15' foreground='#000000' >%s</span>");
	strcpy(markup_text, g_markup_printf_escaped (format, num3));
	gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) markup_text);
	
	int lbl_width = screenWidth/9;
	int lbl_hight = screenHight/9;
	gtk_widget_set_size_request(btn1_P1_P1, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn2_P1_P1, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn3_P1_P1, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn4_P1_P1, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn5_P1_P1, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn6_P1_P1, lbl_width, lbl_hight);
	
	int lbls_width = screenWidth/30;
	int lbls_hight = screenHight/30;
	gtk_widget_set_size_request(btnP1_cancel, lbls_width, lbls_hight);

	int gspace_row = screenWidth/65; 
	int gspace_col = screenWidth/65;
	gtk_grid_set_row_spacing(GTK_GRID(menuP1), gspace_row);
	gtk_grid_set_column_spacing(GTK_GRID(menuP1), gspace_col);
	gtk_box_set_spacing(GTK_BOX(boxP), gspace_row);
	gtk_widget_set_margin_top(boxP, boxU_space);
	gtk_widget_set_margin_bottom(boxP, boxU_space);
	gtk_widget_set_margin_start(boxP, boxU_side_margin);
	gtk_widget_set_margin_end(boxP, boxU_side_margin);
}

void gtk_windowPay_connect(){
	g_signal_connect(windowPay, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(btnP1_cancel, "clicked", G_CALLBACK (close_windowPay), NULL);
	g_signal_connect(btn1_P1, "clicked", G_CALLBACK (gopay), NULL);
	g_signal_connect(btn2_P1, "clicked", G_CALLBACK (dana), NULL);
	g_signal_connect(btn3_P1, "clicked", G_CALLBACK (ovo), NULL);
	g_signal_connect(btn4_P1, "clicked", G_CALLBACK (linkaja), NULL);
	g_signal_connect(btn5_P1, "clicked", G_CALLBACK (shopeepay), NULL);
	g_signal_connect(btn6_P1, "clicked", G_CALLBACK (paylater), NULL);
}

static void close_windowPay(){
	gtk_widget_hide(windowPay);
	gtk_widget_show(windowTemp);
}
//====================================================================//
//====================================================================//

// Window Kasbon
static void start_windowKasbon(){
	int argc; char **argv;
	gtk_init(&argc, &argv);
	gtk_builder_and_attrib_init();

	gtk_windowKasbon_init();
	gtk_windowKasbon_connect();

	gtk_builder_connect_signals(builder, NULL);
	gtk_widget_show(windowKasbon);
	gtk_widget_hide(windowKasbon);
}

void gopay(){
	view_windowKasbon(0);
}

void dana(){
	view_windowKasbon(1);
}

void ovo(){
	view_windowKasbon(2);
}

void linkaja(){
	view_windowKasbon(3);
}

void shopeepay(){
	view_windowKasbon(4);
}

void paylater(){
	
}

static void view_windowKasbon(int num1){
	pay =  num1;
	gtk_windowKasbon_setAttrib();
	gtk_widget_show(windowKasbon);
	
}

// Window Kasbon
void gtk_windowKasbon_init(){
	windowKasbon=GTK_WIDGET(gtk_builder_get_object(builder, "windowKasbon"));
	boxK=GTK_WIDGET(gtk_builder_get_object(builder, "boxK"));

	//button
	btn1_k_b2=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_k_b2"));
	
	//box
	boxK_b1=GTK_WIDGET(gtk_builder_get_object(builder, "boxK_b1"));
	boxK_b2=GTK_WIDGET(gtk_builder_get_object(builder, "boxK_b2"));
	
	//logo
	boxK_img=GTK_WIDGET(gtk_builder_get_object(builder, "boxK_img"));

	//label
	boxK_b1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "boxK_b1_lbl"));
	btn1_k_b2_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_k_b2_lbl"));
}

void gtk_windowKasbon_setAttrib(){
	//gtk_window_fullscreen(GTK_WINDOW(windowKasbon));
	
	gtk_widget_set_name (windowKasbon, "windowKasbon");
	gtk_widget_set_name (boxK, "boxK");

	//button
	gtk_widget_set_name (btn1_k_b2, "btn1_k_b2");
	
	//box
	gtk_widget_set_name (boxK_b1, "boxK_b1");
	gtk_widget_set_name (boxK_b2, "boxK_b2");
	
	//logo
	gtk_widget_set_name (boxK_img, "boxK_img");

	//label
	gtk_widget_set_name(boxK_b1_lbl, "boxK_b1_lbl");
	gtk_widget_set_name(btn1_k_b2_lbl, "btn1_k_b2_lbl");
	
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	int imWidth, imHight;
	int im_margin = screenHight/30;
	imWidth=imHight=screenWidth/5;
	char imgstr[100];
	strcpy(imgstr, imgpay[pay]);
	gtk_image_opt(boxK_img, imgstr, imWidth, imHight, im_margin);
	
	//set dimension
	int lbl_width = screenWidth/10;
	int lbl_hight = screenHight/10;
	gtk_widget_set_size_request(boxK_b1_lbl, lbl_width, lbl_hight);
	
	int lbls_width = screenWidth/30;
	int lbls_hight = screenHight/30;
	gtk_widget_set_size_request(btn1_k_b2_lbl, lbls_width, lbls_hight);
	
	int gspace_row = screenWidth/60; 
	int gspace_col = screenWidth/60;
	gtk_box_set_spacing(GTK_BOX(boxK), gspace_row);
	gtk_widget_set_margin_top(boxK, boxU_space);
	gtk_widget_set_margin_bottom(boxK, boxU_space);
	gtk_widget_set_margin_start(boxK, boxU_side_margin);
	gtk_widget_set_margin_end(boxK, boxU_side_margin);

}

void gtk_windowKasbon_connect(){
	g_signal_connect(windowKasbon, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(btn1_k_b2, "clicked", G_CALLBACK (close_windowKasbon), NULL);
}

static void close_windowKasbon(){
	gtk_widget_hide(windowKasbon);
	gtk_widget_show(windowPay);
}

//====================================================================//
//====================================================================//

//====================================================================//
//====================================================================//

char *IntToStr(int x){
	char *str=(char *)malloc(10 * sizeof (char));
	sprintf(str, "%d", x);
	return str;
}

static void sugarplus(){
	if(sugar < 100){
		sugar += 25;
	}

	num3 = IntToStr(sugar);

	strcpy(format, "<span font_desc='cursive 25' foreground='#000000' ><b>%s</b></span>");
	strcpy(markup_text, g_markup_printf_escaped (format, num3));
	gtk_label_set_markup(GTK_LABEL(sugar_lbl), (const gchar *) markup_text);
	
}

static void sugarmin(){
	if(sugar > 0){
		sugar -= 25;
	}

	num3 = IntToStr(sugar);

	strcpy(format, "<span font_desc='cursive 25' foreground='#000000' ><b>%s</b></span>");
	strcpy(markup_text, g_markup_printf_escaped (format, num3));
	gtk_label_set_markup(GTK_LABEL(sugar_lbl), (const gchar *) markup_text);

}

//====================================================================//
//====================================================================//
