#pragma once
#include "Controladora.hpp"
#include "Archivo.hpp"
namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmPrincipal
	/// </summary>
	public ref class FormJuego : public System::Windows::Forms::Form
	{
	public:
		FormJuego(void)
		{
			InitializeComponent();

			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmap
			bmpBuzo = gcnew Bitmap("BUZO2.png");
			bmpBarco = gcnew Bitmap("barcoPirata.png");
			bmpEscenario1 = gcnew Bitmap("newfondo.jpg");
			bmpEscenario2 = gcnew Bitmap("newfondo2.jpg");
			bmpPezPlomo = gcnew Bitmap("pez1.png");
			bmpPezAzul = gcnew Bitmap("pez3.png");
			bmpPulpo = gcnew Bitmap("pulpo2.png");
			bmpTortugaMarina = gcnew Bitmap("newTortuga.png");
			bmpBasura = gcnew Bitmap("basura.png");
			bmpSubmarino = gcnew Bitmap("submarino.png");

			//Controller
			oControladora = new CControladora(bmpBuzo, bmpBarco, bmpPezPlomo, bmpPezAzul, bmpPulpo, bmpTortugaMarina, bmpSubmarino);

			//Archivo de configuración
			archivo = new CArchivo();
			archivo->readData();
			myTime1 = archivo->getMyTime1();
			myTime2 = archivo->getMyTime2();
			hp = archivo->getHp();
			HpBarco2 = archivo->getHpBarco2();
			nBarco2 = archivo->getNBarco2();
			//mandar los datos a la clase controladora
			oControladora->getBuzo()->setHp(hp);
			oControladora->setNBarcosNivel2(nBarco2);
			oControladora->setHpBarcosNivel2(HpBarco2);

			//tiempo del juego
			tiempo = myTime1;
		}  
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmap
		Bitmap^ bmpBuzo;
		Bitmap^ bmpEscenario1;
		Bitmap^ bmpEscenario2;
		Bitmap^ bmpBarco;
		Bitmap^ bmpPezPlomo;
		Bitmap^ bmpPezAzul;
		Bitmap^ bmpTortugaMarina;
		Bitmap^ bmpBasura;
		Bitmap^ bmpPulpo;
		Bitmap^ bmpSubmarino;

		//tiempo
		int tiempo;
	
		//Juego
		CControladora* oControladora;

		//archivo de configuracion
		CArchivo* archivo;
		int myTime1;
		int myTime2;
		int hp;
		int HpBarco2;
		int nBarco2;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::ComponentModel::IContainer^ components;

		   ~FormJuego()
		   {
			   if (components)
			   {
				   delete components;
			   }
		   }

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormJuego::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(1, -1);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1282, 685);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1215, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &FormJuego::timer2_Tick);
			// 
			// FormLevel1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 653);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"FormLevel1";
			this->Text = L"FrmPrincipal";
			this->Load += gcnew System::EventHandler(this, &FormJuego::FrmPrincipal_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormJuego::FrmPrincipal_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::White);
		//tiempo
		label1->Text = "Tiempo " + Convert::ToString(tiempo);
		
		//jugar nivel 1
		if (oControladora->getNivel() == 1) {
			oControladora->jugarNivel1(buffer->Graphics, bmpEscenario1, panel1, bmpBuzo, bmpBarco, bmpPezPlomo, bmpPezAzul, bmpPulpo, bmpBasura, bmpTortugaMarina, bmpSubmarino);
		}
		if (oControladora->getNivel() == 2) {
			oControladora->jugarNivel2(buffer->Graphics, bmpEscenario2, panel1, bmpBuzo, bmpBarco, bmpPezPlomo, bmpPezAzul, bmpPulpo, bmpBasura, bmpTortugaMarina, bmpSubmarino);
		}
		//GAME OVER
		if (oControladora->getNivel() == 1) {
				if (oControladora->getBuzo()->getHp() == 0 || tiempo <= 0) {
					timer1->Enabled = false;
					timer2->Enabled = false;
					MessageBox::Show("GAME OVER");
					this->Close();
				}
		}

		//pasar siguiente nivel
		if (oControladora->getNivel() == 1) {
			if (tiempo < (myTime1 - 2)) {
				if (oControladora->getBuzo()->getHp() > 0 && tiempo > 0 && oControladora->getBarcos().size() == 0) {
					timer1->Enabled = false;
					timer2->Enabled = false;
					MessageBox::Show("FELICIDADES!!!!" + "\n" + "VENCISTE EL PRIMER NIVEL" + "\n" + "AHORA TE ENFRENTARAS AL NIVEL 2");
					oControladora->setNivel(2);
					tiempo = myTime2;
					timer1->Enabled = true;
					timer2->Enabled = true;
				}
			}
		}

		//ganar el nivel 2
		if (oControladora->getNivel() == 2) {
			if (tiempo < (myTime2-2)) {
				if (oControladora->getBuzo()->getHp() > 0 && tiempo > 0 && oControladora->getBarcos().size() == 0) {
					timer1->Enabled = false;
					timer2->Enabled = false;
					MessageBox::Show("FELICIDADES!!!!" + "\n" + "ACABASTE CON LA CONTAMINACIÓN DEL MAR");
				}
			}
		}

		//perder nivel 2
		if (oControladora->getNivel() == 2) {
			if (oControladora->getBuzo()->getHp() == 0 || tiempo <= 0) {
				timer1->Enabled = false;
				timer2->Enabled = false;
				MessageBox::Show("GAME OVER");
				this->Close();
			}
		}

		//Render
		buffer->Render(g);	
	}
	private: System::Void FrmPrincipal_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		switch (e->KeyCode)
		{
		case Keys::A: case Keys::Left:
			oControladora->getBuzo()->setDireccion(1); break;
		case Keys::D: case Keys::Right:
			oControladora->getBuzo()->setDireccion(2); break;
		case Keys::W: case Keys::Up:
			oControladora->getBuzo()->setDireccion(3); break;
		case Keys::S: case Keys::Down:
			oControladora->getBuzo()->setDireccion(4); break;
		case Keys::Space:
			if (oControladora->getBalas() > 0) {
				CBala* objBala = new CBala(oControladora->getBuzo()->getX(), oControladora->getBuzo()->getY(), 10, 10);
				objBala->setDireccion(oControladora->getBuzo()->getIDY());
				oControladora->AgregarBala(objBala);
			}
			break;
		case Keys::O:
			timer1->Enabled = false;
			timer2->Enabled = false;
		break;
		case Keys::P:
			timer1->Enabled = true;
			timer2->Enabled = true;
			break;
		}
	}
	private: System::Void FrmPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	   tiempo--;
	   for (int i = 0; i < oControladora->getBarcos().size(); i++) {
		   if (oControladora->getBarcos().at(i)->getContador() == 10) {
			   CBasura* C = new CBasura(bmpBasura->Width, bmpBasura->Height, oControladora->getBarcos().at(i)->getX()+20);
			   oControladora->AgregarBasura(C);
			   oControladora->getBarcos().at(i)->setContador(0);
		   }
		   else {
			   oControladora->getBarcos().at(i)->AumentarContador();
		   }
	   }
    }
    };
}
