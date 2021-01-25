#pragma once

namespace opi6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ greetingLabel;
	protected:

	private: System::Windows::Forms::Label^ rowsAmountLabel;
	private: System::Windows::Forms::Label^ columnsAmountLabel;
	private: System::Windows::Forms::Label^ matrixInLabel;
	private: System::Windows::Forms::Label^ matrixOutLabel;


	private: System::Windows::Forms::DataGridView^ matrixInDGV;
	private: System::Windows::Forms::DataGridView^ matrixOutDGV;
	private: System::Windows::Forms::TextBox^ columnsAmountTextBox;
	private: System::Windows::Forms::TextBox^ rowsAmountTextBox;
	private: System::Windows::Forms::Button^ setRowsColumnsButton;
	private: System::Windows::Forms::Button^ genRandomMatrixInButton;
	private: System::Windows::Forms::Button^ performExcerciseButton;
	private: System::Windows::Forms::Label^ badRowsLabel;
	private: System::Windows::Forms::Label^ badColumnsLabel;
	private: System::Windows::Forms::Button^ restartButton;
	private: System::Windows::Forms::Label^ badCellLabel;


	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->greetingLabel = (gcnew System::Windows::Forms::Label());
			this->rowsAmountLabel = (gcnew System::Windows::Forms::Label());
			this->columnsAmountLabel = (gcnew System::Windows::Forms::Label());
			this->matrixInLabel = (gcnew System::Windows::Forms::Label());
			this->matrixOutLabel = (gcnew System::Windows::Forms::Label());
			this->matrixInDGV = (gcnew System::Windows::Forms::DataGridView());
			this->matrixOutDGV = (gcnew System::Windows::Forms::DataGridView());
			this->columnsAmountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->rowsAmountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->setRowsColumnsButton = (gcnew System::Windows::Forms::Button());
			this->genRandomMatrixInButton = (gcnew System::Windows::Forms::Button());
			this->performExcerciseButton = (gcnew System::Windows::Forms::Button());
			this->badRowsLabel = (gcnew System::Windows::Forms::Label());
			this->badColumnsLabel = (gcnew System::Windows::Forms::Label());
			this->restartButton = (gcnew System::Windows::Forms::Button());
			this->badCellLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrixInDGV))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrixOutDGV))->BeginInit();
			this->SuspendLayout();
			// 
			// greetingLabel
			// 
			this->greetingLabel->AutoSize = true;
			this->greetingLabel->Location = System::Drawing::Point(10, 10);
			this->greetingLabel->Name = L"greetingLabel";
			this->greetingLabel->Size = System::Drawing::Size(720, 34);
			this->greetingLabel->TabIndex = 0;
			this->greetingLabel->Text = L"This app lets you create/generate matrix.\nAnd performs next actions: check every "
				L"column for elements with duplicate digits.If it has any - sorts it, else - flips"
				L".";
			// 
			// rowsAmountLabel
			// 
			this->rowsAmountLabel->AutoSize = true;
			this->rowsAmountLabel->Location = System::Drawing::Point(10, 57);
			this->rowsAmountLabel->Name = L"rowsAmountLabel";
			this->rowsAmountLabel->Size = System::Drawing::Size(101, 17);
			this->rowsAmountLabel->TabIndex = 1;
			this->rowsAmountLabel->Text = L"rowsAmount = ";
			// 
			// columnsAmountLabel
			// 
			this->columnsAmountLabel->AutoSize = true;
			this->columnsAmountLabel->Location = System::Drawing::Point(10, 117);
			this->columnsAmountLabel->Name = L"columnsAmountLabel";
			this->columnsAmountLabel->Size = System::Drawing::Size(124, 17);
			this->columnsAmountLabel->TabIndex = 2;
			this->columnsAmountLabel->Text = L"columnsAmount = ";
			// 
			// matrixInLabel
			// 
			this->matrixInLabel->AutoSize = true;
			this->matrixInLabel->Location = System::Drawing::Point(256, 316);
			this->matrixInLabel->Name = L"matrixInLabel";
			this->matrixInLabel->Size = System::Drawing::Size(56, 17);
			this->matrixInLabel->TabIndex = 3;
			this->matrixInLabel->Text = L"matrixIn";
			// 
			// matrixOutLabel
			// 
			this->matrixOutLabel->AutoSize = true;
			this->matrixOutLabel->Location = System::Drawing::Point(522, 316);
			this->matrixOutLabel->Name = L"matrixOutLabel";
			this->matrixOutLabel->Size = System::Drawing::Size(68, 17);
			this->matrixOutLabel->TabIndex = 4;
			this->matrixOutLabel->Text = L"matrixOut";
			// 
			// matrixInDGV
			// 
			this->matrixInDGV->AllowUserToAddRows = false;
			this->matrixInDGV->AllowUserToDeleteRows = false;
			this->matrixInDGV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->matrixInDGV->ColumnHeadersVisible = false;
			this->matrixInDGV->Location = System::Drawing::Point(256, 57);
			this->matrixInDGV->Name = L"matrixInDGV";
			this->matrixInDGV->RowHeadersVisible = false;
			this->matrixInDGV->RowHeadersWidth = 51;
			this->matrixInDGV->RowTemplate->Height = 24;
			this->matrixInDGV->Size = System::Drawing::Size(256, 256);
			this->matrixInDGV->TabIndex = 5;
			// 
			// matrixOutDGV
			// 
			this->matrixOutDGV->AllowUserToAddRows = false;
			this->matrixOutDGV->AllowUserToDeleteRows = false;
			this->matrixOutDGV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->matrixOutDGV->ColumnHeadersVisible = false;
			this->matrixOutDGV->Location = System::Drawing::Point(522, 57);
			this->matrixOutDGV->Name = L"matrixOutDGV";
			this->matrixOutDGV->ReadOnly = true;
			this->matrixOutDGV->RowHeadersVisible = false;
			this->matrixOutDGV->RowHeadersWidth = 51;
			this->matrixOutDGV->RowTemplate->Height = 24;
			this->matrixOutDGV->Size = System::Drawing::Size(256, 256);
			this->matrixOutDGV->TabIndex = 6;
			// 
			// columnsAmountTextBox
			// 
			this->columnsAmountTextBox->Location = System::Drawing::Point(142, 117);
			this->columnsAmountTextBox->Name = L"columnsAmountTextBox";
			this->columnsAmountTextBox->Size = System::Drawing::Size(100, 22);
			this->columnsAmountTextBox->TabIndex = 7;
			this->columnsAmountTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::columnsAmountTextBox_TextChanged);
			// 
			// rowsAmountTextBox
			// 
			this->rowsAmountTextBox->Location = System::Drawing::Point(142, 57);
			this->rowsAmountTextBox->Name = L"rowsAmountTextBox";
			this->rowsAmountTextBox->Size = System::Drawing::Size(100, 22);
			this->rowsAmountTextBox->TabIndex = 8;
			this->rowsAmountTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::rowsAmountTextBox_TextChanged);
			// 
			// setRowsColumnsButton
			// 
			this->setRowsColumnsButton->Enabled = false;
			this->setRowsColumnsButton->Location = System::Drawing::Point(13, 194);
			this->setRowsColumnsButton->Name = L"setRowsColumnsButton";
			this->setRowsColumnsButton->Size = System::Drawing::Size(229, 40);
			this->setRowsColumnsButton->TabIndex = 9;
			this->setRowsColumnsButton->Text = L"set height and width";
			this->setRowsColumnsButton->UseVisualStyleBackColor = true;
			this->setRowsColumnsButton->Click += gcnew System::EventHandler(this, &MyForm::setRowsColumnsButton_Click);
			// 
			// genRandomMatrixInButton
			// 
			this->genRandomMatrixInButton->Enabled = false;
			this->genRandomMatrixInButton->Location = System::Drawing::Point(13, 262);
			this->genRandomMatrixInButton->Name = L"genRandomMatrixInButton";
			this->genRandomMatrixInButton->Size = System::Drawing::Size(229, 40);
			this->genRandomMatrixInButton->TabIndex = 10;
			this->genRandomMatrixInButton->Text = L"generate random MatrixIn";
			this->genRandomMatrixInButton->UseVisualStyleBackColor = true;
			this->genRandomMatrixInButton->Click += gcnew System::EventHandler(this, &MyForm::genRandomMatrixInButton_Click);
			// 
			// performExcerciseButton
			// 
			this->performExcerciseButton->Enabled = false;
			this->performExcerciseButton->Location = System::Drawing::Point(256, 378);
			this->performExcerciseButton->Name = L"performExcerciseButton";
			this->performExcerciseButton->Size = System::Drawing::Size(256, 47);
			this->performExcerciseButton->TabIndex = 11;
			this->performExcerciseButton->Text = L"compute MatrixOut";
			this->performExcerciseButton->UseVisualStyleBackColor = true;
			this->performExcerciseButton->Click += gcnew System::EventHandler(this, &MyForm::performExcerciseButton_Click);
			// 
			// badRowsLabel
			// 
			this->badRowsLabel->AutoSize = true;
			this->badRowsLabel->ForeColor = System::Drawing::Color::Red;
			this->badRowsLabel->Location = System::Drawing::Point(81, 87);
			this->badRowsLabel->Name = L"badRowsLabel";
			this->badRowsLabel->Size = System::Drawing::Size(161, 17);
			this->badRowsLabel->TabIndex = 12;
			this->badRowsLabel->Text = L"must be positive integer!";
			this->badRowsLabel->Visible = false;
			// 
			// badColumnsLabel
			// 
			this->badColumnsLabel->AutoSize = true;
			this->badColumnsLabel->ForeColor = System::Drawing::Color::Red;
			this->badColumnsLabel->Location = System::Drawing::Point(81, 147);
			this->badColumnsLabel->Name = L"badColumnsLabel";
			this->badColumnsLabel->Size = System::Drawing::Size(161, 17);
			this->badColumnsLabel->TabIndex = 13;
			this->badColumnsLabel->Text = L"must be positive integer!";
			this->badColumnsLabel->Visible = false;
			// 
			// restartButton
			// 
			this->restartButton->Location = System::Drawing::Point(522, 378);
			this->restartButton->Name = L"restartButton";
			this->restartButton->Size = System::Drawing::Size(256, 47);
			this->restartButton->TabIndex = 14;
			this->restartButton->Text = L"restart";
			this->restartButton->UseVisualStyleBackColor = true;
			this->restartButton->Click += gcnew System::EventHandler(this, &MyForm::restartButton_Click);
			// 
			// badCellLabel
			// 
			this->badCellLabel->AutoSize = true;
			this->badCellLabel->ForeColor = System::Drawing::Color::Red;
			this->badCellLabel->Location = System::Drawing::Point(332, 346);
			this->badCellLabel->Name = L"badCellLabel";
			this->badCellLabel->Size = System::Drawing::Size(95, 17);
			this->badCellLabel->TabIndex = 15;
			this->badCellLabel->Text = L"bad cell value";
			this->badCellLabel->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(787, 438);
			this->Controls->Add(this->badCellLabel);
			this->Controls->Add(this->restartButton);
			this->Controls->Add(this->badColumnsLabel);
			this->Controls->Add(this->badRowsLabel);
			this->Controls->Add(this->performExcerciseButton);
			this->Controls->Add(this->genRandomMatrixInButton);
			this->Controls->Add(this->setRowsColumnsButton);
			this->Controls->Add(this->rowsAmountTextBox);
			this->Controls->Add(this->columnsAmountTextBox);
			this->Controls->Add(this->matrixOutDGV);
			this->Controls->Add(this->matrixInDGV);
			this->Controls->Add(this->matrixOutLabel);
			this->Controls->Add(this->matrixInLabel);
			this->Controls->Add(this->columnsAmountLabel);
			this->Controls->Add(this->rowsAmountLabel);
			this->Controls->Add(this->greetingLabel);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrixInDGV))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrixOutDGV))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: 
	bool goodRows = false, goodColumns = false;
	int rowsAmount = 0, columnsAmount = 0;
	int** matrixIn = nullptr, **matrixOut = nullptr;
	int columnWidth = 30;//px
	System::Void rowsAmountTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void columnsAmountTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void setRowsColumnsButton_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void genRandomMatrixInButton_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void performExcerciseButton_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void restartButton_Click(System::Object^ sender, System::EventArgs^ e);

	void updateMatrixInDGV();
	void updateMatrixOutDGV();
};
}
