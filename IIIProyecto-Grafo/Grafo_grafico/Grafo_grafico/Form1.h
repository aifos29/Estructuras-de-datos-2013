#pragma once
#include "libxl.h"
#include "Vertice.h"
#include "ListaVertices.h"
#include <sstream>

using namespace libxl;



namespace Grafo_grafico {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{

			InitializeComponent();
			
		
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}


	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;
	public:
			Book * book;
	private: System::Windows::Forms::Button^  bCargar;
	private: System::Windows::Forms::Label^  lblhoja;
	private: System::Windows::Forms::TextBox^  txthoja;
	private: System::Windows::Forms::TextBox^  txtpartida;


	private: System::Windows::Forms::Button^  bhoja;
	private: System::Windows::Forms::TextBox^  txtgrafo;
	private: System::Windows::Forms::Button^  bruta;
	private: System::Windows::Forms::TextBox^  txtrutamascorta;


	private: System::Windows::Forms::Label^  lblpartida;
	private: System::Windows::Forms::Label^  lblllegada;
	private: System::Windows::Forms::TextBox^  txtllegada;
	private: System::Windows::Forms::TextBox^  txtiteraciones;
	private: System::Windows::Forms::PictureBox^  grafoimagen;
	private: System::Windows::Forms::Label^  lblconexiones;
	private: System::Windows::Forms::Label^  lblrutamascorta;
	private: System::Windows::Forms::Label^  lbltabla;
	private: System::Windows::Forms::Button^  button1;





	public: 
		ListaVertices ^ listavertices;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bCargar = (gcnew System::Windows::Forms::Button());
			this->lblhoja = (gcnew System::Windows::Forms::Label());
			this->txthoja = (gcnew System::Windows::Forms::TextBox());
			this->txtpartida = (gcnew System::Windows::Forms::TextBox());
			this->bhoja = (gcnew System::Windows::Forms::Button());
			this->txtgrafo = (gcnew System::Windows::Forms::TextBox());
			this->bruta = (gcnew System::Windows::Forms::Button());
			this->txtrutamascorta = (gcnew System::Windows::Forms::TextBox());
			this->lblpartida = (gcnew System::Windows::Forms::Label());
			this->lblllegada = (gcnew System::Windows::Forms::Label());
			this->txtllegada = (gcnew System::Windows::Forms::TextBox());
			this->txtiteraciones = (gcnew System::Windows::Forms::TextBox());
			this->grafoimagen = (gcnew System::Windows::Forms::PictureBox());
			this->lblconexiones = (gcnew System::Windows::Forms::Label());
			this->lblrutamascorta = (gcnew System::Windows::Forms::Label());
			this->lbltabla = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->grafoimagen))->BeginInit();
			this->SuspendLayout();
			// 
			// bCargar
			// 
			this->bCargar->Font = (gcnew System::Drawing::Font(L"Papyrus", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bCargar->Location = System::Drawing::Point(27, 15);
			this->bCargar->Name = L"bCargar";
			this->bCargar->Size = System::Drawing::Size(139, 29);
			this->bCargar->TabIndex = 0;
			this->bCargar->Text = L"Cargar Archivo";
			this->bCargar->UseVisualStyleBackColor = true;
			this->bCargar->Click += gcnew System::EventHandler(this, &Form1::bCargar_Click);
			// 
			// lblhoja
			// 
			this->lblhoja->AutoSize = true;
			this->lblhoja->Font = (gcnew System::Drawing::Font(L"Segoe Script", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblhoja->Location = System::Drawing::Point(-1, 65);
			this->lblhoja->Name = L"lblhoja";
			this->lblhoja->Size = System::Drawing::Size(370, 20);
			this->lblhoja->TabIndex = 1;
			this->lblhoja->Text = L"Ingrese el numero de hoja con la que desea trabajar:";
			this->lblhoja->Visible = false;
			this->lblhoja->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// txthoja
			// 
			this->txthoja->Font = (gcnew System::Drawing::Font(L"Segoe Script", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txthoja->Location = System::Drawing::Point(375, 57);
			this->txthoja->Name = L"txthoja";
			this->txthoja->Size = System::Drawing::Size(59, 27);
			this->txthoja->TabIndex = 2;
			this->txthoja->Visible = false;
			this->txthoja->TextChanged += gcnew System::EventHandler(this, &Form1::txthoja_TextChanged);
			// 
			// txtpartida
			// 
			this->txtpartida->Font = (gcnew System::Drawing::Font(L"Segoe Script", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtpartida->Location = System::Drawing::Point(660, 57);
			this->txtpartida->Name = L"txtpartida";
			this->txtpartida->Size = System::Drawing::Size(100, 28);
			this->txtpartida->TabIndex = 3;
			this->txtpartida->Visible = false;
			// 
			// bhoja
			// 
			this->bhoja->Font = (gcnew System::Drawing::Font(L"Papyrus", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bhoja->Location = System::Drawing::Point(27, 88);
			this->bhoja->Name = L"bhoja";
			this->bhoja->Size = System::Drawing::Size(165, 32);
			this->bhoja->TabIndex = 4;
			this->bhoja->Text = L"Cargar Hoja";
			this->bhoja->UseVisualStyleBackColor = true;
			this->bhoja->Visible = false;
			this->bhoja->Click += gcnew System::EventHandler(this, &Form1::bhoja_Click);
			// 
			// txtgrafo
			// 
			this->txtgrafo->Enabled = false;
			this->txtgrafo->Location = System::Drawing::Point(27, 142);
			this->txtgrafo->Multiline = true;
			this->txtgrafo->Name = L"txtgrafo";
			this->txtgrafo->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtgrafo->Size = System::Drawing::Size(436, 218);
			this->txtgrafo->TabIndex = 5;
			this->txtgrafo->Visible = false;
			// 
			// bruta
			// 
			this->bruta->Font = (gcnew System::Drawing::Font(L"Papyrus", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bruta->Location = System::Drawing::Point(779, 70);
			this->bruta->Name = L"bruta";
			this->bruta->Size = System::Drawing::Size(75, 31);
			this->bruta->TabIndex = 6;
			this->bruta->Text = L"Calcular ruta";
			this->bruta->UseVisualStyleBackColor = true;
			this->bruta->Visible = false;
			this->bruta->Click += gcnew System::EventHandler(this, &Form1::bruta_Click);
			// 
			// txtrutamascorta
			// 
			this->txtrutamascorta->Location = System::Drawing::Point(507, 171);
			this->txtrutamascorta->Multiline = true;
			this->txtrutamascorta->Name = L"txtrutamascorta";
			this->txtrutamascorta->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtrutamascorta->Size = System::Drawing::Size(540, 125);
			this->txtrutamascorta->TabIndex = 7;
			this->txtrutamascorta->Visible = false;
			this->txtrutamascorta->TextChanged += gcnew System::EventHandler(this, &Form1::txtrutamascorta_TextChanged);
			// 
			// lblpartida
			// 
			this->lblpartida->AutoSize = true;
			this->lblpartida->Location = System::Drawing::Point(502, 27);
			this->lblpartida->Name = L"lblpartida";
			this->lblpartida->Size = System::Drawing::Size(244, 27);
			this->lblpartida->TabIndex = 8;
			this->lblpartida->Text = L"Ingrese el punto de partida:";
			this->lblpartida->Visible = false;
			// 
			// lblllegada
			// 
			this->lblllegada->AutoSize = true;
			this->lblllegada->Location = System::Drawing::Point(502, 88);
			this->lblllegada->Name = L"lblllegada";
			this->lblllegada->Size = System::Drawing::Size(235, 27);
			this->lblllegada->TabIndex = 9;
			this->lblllegada->Text = L"Ingrese el punto de llegada";
			this->lblllegada->Visible = false;
			// 
			// txtllegada
			// 
			this->txtllegada->Font = (gcnew System::Drawing::Font(L"Segoe Script", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtllegada->Location = System::Drawing::Point(660, 118);
			this->txtllegada->Name = L"txtllegada";
			this->txtllegada->Size = System::Drawing::Size(100, 28);
			this->txtllegada->TabIndex = 10;
			this->txtllegada->Visible = false;
			this->txtllegada->TextChanged += gcnew System::EventHandler(this, &Form1::txtllegada_TextChanged);
			// 
			// txtiteraciones
			// 
			this->txtiteraciones->Location = System::Drawing::Point(507, 364);
			this->txtiteraciones->Multiline = true;
			this->txtiteraciones->Name = L"txtiteraciones";
			this->txtiteraciones->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtiteraciones->Size = System::Drawing::Size(540, 110);
			this->txtiteraciones->TabIndex = 11;
			this->txtiteraciones->Visible = false;
			// 
			// grafoimagen
			// 
			this->grafoimagen->Location = System::Drawing::Point(3, 424);
			this->grafoimagen->Name = L"grafoimagen";
			this->grafoimagen->Size = System::Drawing::Size(100, 50);
			this->grafoimagen->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->grafoimagen->TabIndex = 12;
			this->grafoimagen->TabStop = false;
			this->grafoimagen->Visible = false;
			this->grafoimagen->Click += gcnew System::EventHandler(this, &Form1::grafoimagen_Click);
			// 
			// lblconexiones
			// 
			this->lblconexiones->AutoSize = true;
			this->lblconexiones->Location = System::Drawing::Point(38, 367);
			this->lblconexiones->Name = L"lblconexiones";
			this->lblconexiones->Size = System::Drawing::Size(248, 27);
			this->lblconexiones->TabIndex = 13;
			this->lblconexiones->Text = L"Conexiones de la estructura";
			this->lblconexiones->Visible = false;
			this->lblconexiones->Click += gcnew System::EventHandler(this, &Form1::label1_Click_1);
			// 
			// lblrutamascorta
			// 
			this->lblrutamascorta->AutoSize = true;
			this->lblrutamascorta->Location = System::Drawing::Point(589, 299);
			this->lblrutamascorta->Name = L"lblrutamascorta";
			this->lblrutamascorta->Size = System::Drawing::Size(265, 27);
			this->lblrutamascorta->TabIndex = 14;
			this->lblrutamascorta->Text = L"Ruta más corta segun Dijstrak";
			this->lblrutamascorta->Visible = false;
			// 
			// lbltabla
			// 
			this->lbltabla->AutoSize = true;
			this->lbltabla->Location = System::Drawing::Point(589, 494);
			this->lbltabla->Name = L"lbltabla";
			this->lbltabla->Size = System::Drawing::Size(182, 27);
			this->lbltabla->TabIndex = 15;
			this->lbltabla->Text = L"Tabla de iteraciones";
			this->lbltabla->Visible = false;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Papyrus", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(860, 70);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(173, 31);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Calcular otra ruta";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1164, 478);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lbltabla);
			this->Controls->Add(this->lblrutamascorta);
			this->Controls->Add(this->lblconexiones);
			this->Controls->Add(this->grafoimagen);
			this->Controls->Add(this->txtiteraciones);
			this->Controls->Add(this->txtllegada);
			this->Controls->Add(this->lblllegada);
			this->Controls->Add(this->lblpartida);
			this->Controls->Add(this->txtrutamascorta);
			this->Controls->Add(this->bruta);
			this->Controls->Add(this->txtgrafo);
			this->Controls->Add(this->bhoja);
			this->Controls->Add(this->txtpartida);
			this->Controls->Add(this->txthoja);
			this->Controls->Add(this->lblhoja);
			this->Controls->Add(this->bCargar);
			this->Font = (gcnew System::Drawing::Font(L"Segoe Script", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Name = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load_1);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->grafoimagen))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				
		
			 }



	private: System::Void bCargar_Click(System::Object^  sender, System::EventArgs^  e) {
				 book=xlCreateBook();
				 if (book->load(L"Prueba.xls")){
					   MessageBox::Show("El libro de excel con los datos fue cargado correctamente",
						"Datos de hojas", MessageBoxButtons::OK,
						 MessageBoxIcon::Asterisk);
					   txthoja->Visible=true;
					   lblhoja->Visible=true;
					   bhoja->Visible=true;
				 }
				 else{
					   MessageBox::Show("El libro de excel con los datos no fue cargado correctamente",
						"Datos de hojas", MessageBoxButtons::OK,
					 MessageBoxIcon::Asterisk);
				 }
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void txthoja_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void bhoja_Click(System::Object^  sender, System::EventArgs^  e) {
			 lblllegada->Visible=false;
			 lblpartida->Visible=false;
			 txtllegada->Visible=false;
			 txtpartida->Visible=false;
			 lblrutamascorta->Visible=false;
			 lbltabla->Visible=false;
			 txtrutamascorta->Visible=false;
			 txtiteraciones->Visible=false;
			 listavertices=gcnew ListaVertices();
			 if (txthoja->Text==""){
				  MessageBox::Show("Ingrese un valor",
						"Datos de hojas", MessageBoxButtons::OK,
						MessageBoxIcon::Asterisk);
					}
			 else{
			 String ^ hoja = txthoja->Text;
				  int n=Convert::ToInt32(hoja);
				 Sheet * sheet= book->getSheet(n-1);
				 if (sheet){
					 	int cantidad=sheet->readNum(0,1);
						int fila=2;
						int contador=1;
						while (contador<=cantidad){
							int valor=contador;
							Vertice ^ nuevo=gcnew Vertice;
							nuevo->setdatos(valor);
							
							listavertices->agregar(nuevo);
							contador++;
							}
						listavertices->agregararcos(n-1);
						listavertices->mostrar();
						txtgrafo->Visible=true;
						txtgrafo->Enabled=true;
						System::IO::StreamReader  ^ sw = gcnew 
						System::IO::StreamReader ("Test.txt");
						txtgrafo->Text= sw->ReadToEnd();
						sw->Close();
						lblllegada->Visible=true;
						lblpartida->Visible=true;
						txtllegada->Visible=true;
						txtpartida->Visible=true;
						bruta->Visible=true;
						lblconexiones->Visible=true;
						grafoimagen->Visible=true;
						
						if (n==1){
							grafoimagen->Load("uno.jpg");
						}
						if (n==2){
							grafoimagen->Load("dos.jpg");
						}
						if (n==3){
							grafoimagen->Load("tres.jpg");
						}
						if (n==4){
							grafoimagen->Load("cuatro.jpg");
						}
						if (n==5){
							grafoimagen->Load("cinco.jpg");
						}
						if (n==6){
							grafoimagen->Load("seis.jpg");
						}
						
						
				 }
			  
				else{
					   MessageBox::Show("Los hoja no fue encontrada",
						"Datos de hojas", MessageBoxButtons::OK,
						MessageBoxIcon::Asterisk);
				}
			 }
			
 }
			  
			  
		 
		
private: System::Void bruta_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (txtllegada->Text=="" || txtpartida->Text=="")
			 { 
				 MessageBox::Show("Debe ingresar un valor valido",
						"Datos de hojas", MessageBoxButtons::OK,
						MessageBoxIcon::Asterisk);
			 }
			 else{
			 String ^llegada=txtllegada->Text;
			 int llega = Convert::ToInt32(llegada);
			 String ^ salida= txtpartida->Text;
			 int partida=Convert::ToInt32(salida);
			  System::IO::StreamWriter  ^ x = gcnew 
				System::IO::StreamWriter ("Iteracion.txt",false);
			x->WriteLine(" ");
			x->Close();
			if (partida< 1 || llega>listavertices->getLargo()){
				MessageBox::Show("Ingrese un numero que se encuentre en el grafo" ,
						"Error de rango", MessageBoxButtons::OK,
						MessageBoxIcon::Asterisk);
			}
			else{
			listavertices->disktraj(partida,llega,0);
			 txtrutamascorta->Visible=true;
			 System::IO::StreamReader  ^ sw = gcnew 
			System::IO::StreamReader ("Ruta.txt");
			txtrutamascorta->Text= sw->ReadToEnd();
			sw->Close();
			 System::IO::StreamReader  ^ p = gcnew 
			System::IO::StreamReader ("Iteracion.txt");
			 txtiteraciones->Visible=true;
			 txtiteraciones->Text= p->ReadToEnd();
			 p->Close();
			 lblrutamascorta->Visible=true;
			lbltabla->Visible=true;
			txtllegada->Enabled=false;
			txtpartida->Enabled=false;
			bruta->Visible=false;
			button1->Visible=true;
			 }

		 }
		 }

private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			
		 }
private: System::Void Form1_Load_1(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label1_Click_1(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void grafoimagen_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 listavertices->reseteo();
			 bruta->Visible=true;
			 button1->Visible=false;
			 txtllegada->Text="";
			 txtpartida->Text="";
			 txtllegada->Enabled=true;
			 txtpartida->Enabled=true;
			 txtiteraciones->Visible=false;
			 txtrutamascorta->Visible=false;
			 lblrutamascorta->Visible=false;
			 lbltabla->Visible=false;
		 }
private: System::Void txtllegada_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txtrutamascorta_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}


