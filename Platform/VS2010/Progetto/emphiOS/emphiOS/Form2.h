#pragma once

// system
#include <string.h>
#include <msclr\marshal.h>

// driver
#include "..\..\..\Driver\dntLcdGlo.h"
#include "..\..\..\Driver\dntButtonsGlo.h"

#include "..\..\..\..\..\Firmware\rs2ButtonsGlo.h"

namespace emphiOS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// aggiunta Marco
	using namespace System;
	using namespace msclr::interop;

	/// <summary>
	/// Riepilogo per Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
			this->Visible = true;


			lcd_string[0][0] = 'm';
			lcd_string[0][1] = 'a';
			lcd_string[0][2] = 'r';
			lcd_string[0][3] = 'c';
			lcd_string[0][4] = 'o';
			lcd_string[0][5] = 0;

		}

	protected:
		/// <summary>
		/// Liberare le risorse in uso.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Variabile di progettazione necessaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metodo necessario per il supporto della finestra di progettazione. Non modificare
		/// il contenuto del metodo con l'editor di codice.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Courier New", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(270, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"12345678901234567890";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Courier New", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 97);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(270, 23);
			this->label2->TabIndex = 1;
			this->label2->Text = L"12345678901234567890";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Courier New", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 130);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(270, 23);
			this->label3->TabIndex = 2;
			this->label3->Text = L"12345678901234567890";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Courier New", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(12, 166);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(270, 23);
			this->label4->TabIndex = 3;
			this->label4->Text = L"12345678901234567890";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Courier New", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(12, 199);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(270, 23);
			this->label5->TabIndex = 4;
			this->label5->Text = L"12345678901234567890";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form2::timer1_Tick);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form2";
			this->Text = L"Form2";
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form2::Form2_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form2_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			// lettura tasti

			if ( e->KeyCode == Keys::Left )
			{
				lcd_string[0][0] = 'L';
				dntKeyPress |= CODE_BUTTONS_LEFT;
			}
			if ( e->KeyCode == Keys::Right )
			{
				lcd_string[0][0] = 'R';
				dntKeyPress |= CODE_BUTTONS_RIGHT;
			}
			if ( e->KeyCode == Keys::Up )
			{
				lcd_string[0][0] = 'U';
				dntKeyPress |= CODE_BUTTONS_UP;
			}
			if ( e->KeyCode == Keys::Down )
			{
				lcd_string[0][0] = 'D';
				dntKeyPress |= CODE_BUTTONS_DOWN;
			}
			if ( e->KeyCode == Keys::Enter )
			{
				lcd_string[0][0] = 'E';
				dntKeyPress |= CODE_BUTTONS_ENTER;
			}

		}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

					this->label1->Text = marshal_as<String^>( lcd_string[0] );
					this->label2->Text = marshal_as<String^>( lcd_string[1] );
					this->label3->Text = marshal_as<String^>( lcd_string[2] );
					this->label4->Text = marshal_as<String^>( lcd_string[3] );
					this->label5->Text = marshal_as<String^>( lcd_string[4] );

		 }
};
}
