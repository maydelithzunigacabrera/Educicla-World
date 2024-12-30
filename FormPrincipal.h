#pragma once
#include "FormJuego.h"

using namespace TF;
using namespace std;

namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class FormPrincipal : public System::Windows::Forms::Form
	{
	public:
		FormPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			//Buffer
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);

			//Bitmap
			inicio = gcnew Bitmap("inicio.png");
		}

	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ Reglas_del_juego;
	private: System::Windows::Forms::Button^ creditos;
	private: System::Windows::Forms::TextBox^ textBox1;




		//Bitmap
		Bitmap^ inicio;

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ JUGAR;
	protected:

	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->JUGAR = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Reglas_del_juego = (gcnew System::Windows::Forms::Button());
			this->creditos = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// JUGAR
			// 
			this->JUGAR->BackColor = System::Drawing::Color::RosyBrown;
			this->JUGAR->Font = (gcnew System::Drawing::Font(L"Ink Free", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->JUGAR->Location = System::Drawing::Point(364, 201);
			this->JUGAR->Name = L"JUGAR";
			this->JUGAR->Size = System::Drawing::Size(157, 31);
			this->JUGAR->TabIndex = 0;
			this->JUGAR->Text = L"JUGAR YA!";
			this->JUGAR->UseVisualStyleBackColor = false;
			this->JUGAR->Click += gcnew System::EventHandler(this, &FormPrincipal::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 60;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormPrincipal::timer1_Tick);
			// 
			// Reglas_del_juego
			// 
			this->Reglas_del_juego->BackColor = System::Drawing::Color::Yellow;
			this->Reglas_del_juego->Font = (gcnew System::Drawing::Font(L"Ink Free", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Reglas_del_juego->Location = System::Drawing::Point(328, 272);
			this->Reglas_del_juego->Name = L"Reglas_del_juego";
			this->Reglas_del_juego->Size = System::Drawing::Size(239, 31);
			this->Reglas_del_juego->TabIndex = 1;
			this->Reglas_del_juego->Text = L"REGLAS DEL JUEGO";
			this->Reglas_del_juego->UseVisualStyleBackColor = false;
			this->Reglas_del_juego->Click += gcnew System::EventHandler(this, &FormPrincipal::button2_Click);
			// 
			// creditos
			// 
			this->creditos->BackColor = System::Drawing::Color::Teal;
			this->creditos->Font = (gcnew System::Drawing::Font(L"Ink Free", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->creditos->Location = System::Drawing::Point(365, 337);
			this->creditos->Name = L"creditos";
			this->creditos->Size = System::Drawing::Size(156, 31);
			this->creditos->TabIndex = 2;
			this->creditos->Text = L"CREDITOS";
			this->creditos->UseVisualStyleBackColor = false;
			this->creditos->Click += gcnew System::EventHandler(this, &FormPrincipal::creditos_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"MV Boli", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(111, 55);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(673, 111);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"TRASH COLLECTORS";
			// 
			// FormPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(915, 392);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->creditos);
			this->Controls->Add(this->Reglas_del_juego);
			this->Controls->Add(this->JUGAR);
			this->Name = L"FormPrincipal";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &FormPrincipal::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FormPrincipal::MyForm_Paint);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		FormJuego^ formulario = gcnew FormJuego();
		this->Hide();
        formulario->ShowDialog();
	}
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::White);
		buffer->Graphics->DrawImage(inicio, 0, 0, this->Width, this->Height);
		buffer->Render(g);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("                                           REGLAS DEL JUEGO    " + "\n" + "\n" +
			             "-El juego consiste en un buzo que lucha contra la contaminación" + "\n" +
			             " marina, sumergiéndose a grandes profundidades y evitando que los" + "\n" +
			             " animales marinos sean afectados con la fuerte contaminación de" + "\n" +
			             " los barcos que se encuentran en la zona." + "\n" + "\n"  +
			             "-Mientras los niveles vayan pasando el jugador se encontrará" + "\n" +
			             "con ciertas dificultades las cuales intentarán frenar para poder" + "\n" +
			             "salvar a los animales marinos." + "\n" + "\n" +
		                 "                                           NIVEL 1 " + "\n" +
			             "- El buzo se movera con las teclas direccionales" + "\n" +
			             "- En este nivel se presentará 4 barcos que arrojarán basura cada" + "\n" +
			             "cierto tiempo, la misión del buzo será evitar que lleguen al" + "\n" +
			             "fondo marino." + "\n" +
			             "- Cada barco contará con 2 vidas, las cuales son las veces que" + "\n" +
			             "tenemos que dispararles para poder destruirlos." + "\n" +
			             "- El jugador contará con 5 vidas, lasc uales disminuiran si la" + "\n" +
			             "basura llega al fondo" + "\n" +
			             "- Por cada 5 basuras recolectadas por el buzo se habilitara una" + "\n" +
			             "bala poder combatir contra los barcos y destruirlos." + "\n" +
			             "- Este nivel contará con 3 minutos, pasado el tiempo el jugador" + "\n" +
			             "perdería el nivel." + "\n" + "\n"
			             "                                            NIVEL 2" + "\n" +
			             "- El buzo se movera con las teclas direccionales" + "\n" +
			             "- En este nivel se presentará 3 barcos que arrojarán basura cada" + "\n" +
			             "cierto tiempo, la misión del buzo será evitar que lleguen al" + "\n" +
			             "fondo marino." + "\n" +
			             "- Cada barco contará con 3 vidas, las cuales son las veces que" + "\n" +
			             "tenemos que dispararles para poder destruirlos." + "\n" +
			             "- El jugador contará con 5 vidas, lasc uales disminuiran si la" + "\n" +
			             "basura llega al fondo" + "\n" +
			             "- Por cada 5 basuras recolectadas por el buzo se habilitara una" + "\n" +
			             "bala poder combatir contra los barcos y destruirlos." + "\n" +
			             "-Este nivel contará con 5 minutos, pasado el tiempo el jugador" + "\n" +
			             "perdería el nivel." + "\n" + 
			             "-Para este nivel se implementara un submarino, el cual" + "\n" +
			             "perseguira al buzo y si colisiona con este se le quitara una " + "\n"+
			             "vida al buzo y lo regresara a su posicion inicial, el submarino" + "\n" +
			             "tomara una nueva posición" + "\n");
	}
	private: System::Void creditos_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show( "INTEGRANTES DEL GRUPO:" + "\n" + "\n"
			"Guzmán Guimaraes, Jean Pierre" + " - U20211B277" + "\n" +
			"Li Zegarra, Xiao Lian" + " - U202118784" + "\n" +
			"Zuñiga Cabrera Kiara Cristina" + " - U20211C682" + "\n" +
			"Condori Lozano, Alessandro Ramiro" + " - U20211a118" + "\n");
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {

	}
};
}
