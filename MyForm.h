#include <Windows.h>
#include <string>
#include <vector>
#include <iostream>
#include <list>
#pragma once


BOOL _Run = FALSE;
BOOL _Attack = FALSE;
BOOL _TPbot = FALSE;
BOOL _Bot = FALSE;
BOOL _TopMost = TRUE;
BOOL _NoAnim = FALSE;
BOOL _Pumpkin = FALSE;
BOOL _currentXYZ;
uintptr_t _EntitiesBase = (uintptr_t)GetModuleHandle(L"EntitiesMP.dll");
uintptr_t EntityBase = _EntitiesBase + 0x3153D0;
DWORD Xpos = 0x58;
DWORD Ypos = 0x5c;
DWORD Zpos = Xpos + 0x08;
DWORD Run = 0xDE4;
DWORD Attack = 0xDD8;
DWORD Anim = 0xEA4;
uintptr_t base = (uintptr_t)GetModuleHandle(L"Engine.dll");
uintptr_t a1 = *(uintptr_t*)(base + 0xD52AB0);

float maxX;
float maxY;
float addPosX;
float addPosY;
int botAttack;
int min_objLVL;
int max_objLVL;
int chosenCord;
std::vector<int> Mitina;

namespace LC {
	FLOAT Speed = 1;
	int Attspeed = 11;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	public: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	public:
	public: System::Windows::Forms::TextBox^ textBox2;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox3;
	public: System::Windows::Forms::TextBox^ textBox4;
	public: System::Windows::Forms::TextBox^ textBox5;
	public: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Button^ button5;







	private:


	protected:

	public:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button1->Location = System::Drawing::Point(10, 208);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(49, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Run speed";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Ivory;
			this->textBox1->Location = System::Drawing::Point(10, 180);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(49, 21);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"20";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button2->Location = System::Drawing::Point(65, 208);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(47, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Attck";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::White;
			this->textBox2->Location = System::Drawing::Point(65, 180);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(47, 21);
			this->textBox2->TabIndex = 4;
			this->textBox2->Text = L"1";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(10, 13);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(102, 25);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Save";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(118, 99);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(81, 25);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Teleport";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(10, 43);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(102, 21);
			this->textBox3->TabIndex = 8;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(118, 13);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(80, 21);
			this->textBox4->TabIndex = 9;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(118, 43);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(80, 21);
			this->textBox5->TabIndex = 10;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(118, 71);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(80, 21);
			this->textBox6->TabIndex = 11;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(119, 213);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(99, 18);
			this->checkBox1->TabIndex = 12;
			this->checkBox1->Text = L"Always on top";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_1);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(119, 190);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(70, 18);
			this->checkBox2->TabIndex = 13;
			this->checkBox2->Text = L"Fast Pick";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(118, 166);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(58, 18);
			this->checkBox3->TabIndex = 14;
			this->checkBox3->Text = L"TP bot";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox3_CheckedChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(10, 71);
			this->comboBox1->MaxDropDownItems = 10;
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(102, 22);
			this->comboBox1->TabIndex = 15;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(204, 67);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(67, 18);
			this->checkBox4->TabIndex = 16;
			this->checkBox4->Text = L"BOT ON";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox4_CheckedChanged);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(204, 40);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(34, 21);
			this->textBox7->TabIndex = 17;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(204, 118);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(80, 21);
			this->textBox8->TabIndex = 18;
			this->textBox8->Text = L"0";
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(119, 143);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(71, 18);
			this->checkBox5->TabIndex = 19;
			this->checkBox5->Text = L"Pumpkin";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox5_CheckedChanged);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(204, 91);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(80, 21);
			this->textBox9->TabIndex = 20;
			this->textBox9->Text = L"0";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(244, 40);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(40, 21);
			this->textBox10->TabIndex = 21;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(204, 16);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(80, 21);
			this->textBox11->TabIndex = 22;
			this->textBox11->Text = L"5";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(119, 126);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(81, 13);
			this->button5->TabIndex = 23;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(287, 240);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->checkBox5);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"LC Classic";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Speed = Convert::ToDouble(LC::MyForm::textBox1->Text);
		_Run = !_Run;
		if (_Run)
		{
			MyForm::textBox1->BackColor = System::Drawing::Color::GreenYellow;
		}
		else
		{
			MyForm::textBox1->BackColor = System::Drawing::Color::White;
		}
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Attspeed = Convert::ToInt32(LC::MyForm::textBox2->Text);
		_Attack = !_Attack;
		if (_Attack)
		{
			MyForm::textBox2->BackColor = System::Drawing::Color::GreenYellow;
		}
		else
		{
			MyForm::textBox2->BackColor = System::Drawing::Color::White;
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {							  
		if (LC::MyForm::textBox3->Text != "")
		{ 
			Mitina.push_back((*(FLOAT*)(*(DWORD*)EntityBase + Xpos)));
			Mitina.push_back((*(FLOAT*)(*(DWORD*)EntityBase + Ypos)));
			Mitina.push_back((*(FLOAT*)(*(DWORD*)EntityBase + Zpos)));
			LC::MyForm::comboBox1->Items->Add(LC::MyForm::textBox3->Text);
			//LC::MyForm::comboBox1->Items->Add((*(FLOAT*)(*(DWORD*)EntityBase + Xpos)));
			//LC::MyForm::comboBox1->Items->Add((*(FLOAT*)(*(DWORD*)EntityBase + Ypos)));
			//LC::MyForm::comboBox1->Items->Add((*(FLOAT*)(*(DWORD*)EntityBase + Zpos)));
			//LC::MyForm::saved_coords->Items->Add(LC::MyForm::textBox3->Text);
			//LC::MyForm::saved_coords->Items->Add((*(FLOAT*)(*(DWORD*)EntityBase + Xpos)));
			//LC::MyForm::saved_coords->Items->Add((*(FLOAT*)(*(DWORD*)EntityBase + Ypos)));
			//LC::MyForm::saved_coords->Items->Add((*(FLOAT*)(*(DWORD*)EntityBase + Zpos)));
			LC::MyForm::textBox3->Text = "";
		}
	}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MyForm::comboBox1->Text != "")
	{
		int i = (chosenCord * 2) - 1;
		if (chosenCord == 0)
		{
			*(FLOAT*)(*(DWORD*)EntityBase + Xpos) = Mitina.at(chosenCord);	//Convert::ToDouble(LC::MyForm::textBox4->Text);
			*(FLOAT*)(*(DWORD*)EntityBase + Ypos) = (Mitina.at(chosenCord + 1) + 1);	//Convert::ToDouble(LC::MyForm::textBox5->Text);
			*(FLOAT*)(*(DWORD*)EntityBase + Zpos) = Mitina.at(chosenCord + 2);	//Convert::ToDouble(LC::MyForm::textBox6->Text);
		}
		else
		{
			*(FLOAT*)(*(DWORD*)EntityBase + Xpos) = Mitina.at(i + chosenCord + 1);
			*(FLOAT*)(*(DWORD*)EntityBase + Ypos) = (Mitina.at(i + chosenCord + 2) + 1);
			*(FLOAT*)(*(DWORD*)EntityBase + Zpos) = Mitina.at(i + chosenCord + 3);
		}
		MyForm::comboBox1->Text = "";
	}
	else
	{
		*(FLOAT*)(*(DWORD*)EntityBase + Xpos) = Convert::ToDouble(LC::MyForm::textBox4->Text);
		*(FLOAT*)(*(DWORD*)EntityBase + Ypos) = Convert::ToDouble(LC::MyForm::textBox5->Text);
		*(FLOAT*)(*(DWORD*)EntityBase + Zpos) = Convert::ToDouble(LC::MyForm::textBox6->Text);
	}
	
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBox1_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	_TopMost = !_TopMost;
	MyForm::TopMost = _TopMost;
}
private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	_NoAnim = !_NoAnim;
}
private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	_TPbot = !_TPbot;
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	chosenCord = LC::MyForm::comboBox1->SelectedIndex;
}
private: System::Void checkBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textBox7->Text != "")
	{
		addPosX = Convert::ToDouble(MyForm::textBox9->Text);
		addPosY = Convert::ToDouble(MyForm::textBox8->Text);
		min_objLVL = Convert::ToInt32(LC::MyForm::textBox7->Text);
		max_objLVL = Convert::ToInt32(LC::MyForm::textBox10->Text);
		botAttack = Convert::ToInt32(LC::MyForm::textBox11->Text);
		_Bot = !_Bot;
	}
}
private: System::Void checkBox5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	_Pumpkin = !_Pumpkin;
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	LC::MyForm::textBox4->Text = Convert::ToString(*(FLOAT*)(*(DWORD*)EntityBase + Xpos));
	LC::MyForm::textBox5->Text = Convert::ToString(*(FLOAT*)(*(DWORD*)EntityBase + Ypos));
	LC::MyForm::textBox6->Text = Convert::ToString(*(FLOAT*)(*(DWORD*)EntityBase + Zpos));
}
};
}
