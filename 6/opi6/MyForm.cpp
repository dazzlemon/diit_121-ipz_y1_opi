#include "MyForm.h"
#include "matrix.h"
#include <Windows.h>
using namespace opi6;///opi6

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

//checks if new Text can be parsed to Int, if not shows error msg
System::Void opi6::MyForm::rowsAmountTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	bool isInt = Int32::TryParse(rowsAmountTextBox->Text, rowsAmount);
	goodRows = (isInt && rowsAmount > 0);
	setRowsColumnsButton->Enabled = (goodRows && goodColumns);//
	badRowsLabel->Visible = !goodRows;
}

//checks if new Text can be parsed to Int, if not shows error msg
System::Void opi6::MyForm::columnsAmountTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	bool isInt = Int32::TryParse(columnsAmountTextBox->Text, columnsAmount);
	goodColumns = (isInt && columnsAmount > 0);
	setRowsColumnsButton->Enabled = (goodRows && goodColumns);//
	badColumnsLabel->Visible = !goodColumns;
}

//updates value of rowsAmount and columnsAmount from TextBoxes
System::Void opi6::MyForm::setRowsColumnsButton_Click(System::Object^ sender, System::EventArgs^ e) {
	matrixIn = createMatrix<int>(rowsAmount, columnsAmount);
	setMatrix0(matrixIn, rowsAmount, columnsAmount);
	matrixInDGV->RowCount = rowsAmount;
	matrixInDGV->ColumnCount = columnsAmount;
	updateMatrixInDGV();

	matrixOut = createMatrix<int>(rowsAmount, columnsAmount);
	setMatrix0(matrixOut, rowsAmount, columnsAmount);
	matrixOutDGV->RowCount = rowsAmount;
	matrixOutDGV->ColumnCount = columnsAmount;
	updateMatrixOutDGV();

	for (int j = 0; j < columnsAmount; j++) {//setWidth
		matrixInDGV->Columns[j]->Width = columnWidth;
		matrixOutDGV->Columns[j]->Width = columnWidth;
	}

	genRandomMatrixInButton->Enabled = true;
	performExcerciseButton->Enabled = true;

	rowsAmountTextBox->Enabled = false;
	columnsAmountTextBox->Enabled = false;
	setRowsColumnsButton->Enabled = false;
}

//generates new matrixIn and shows it on screen
System::Void opi6::MyForm::genRandomMatrixInButton_Click(System::Object^ sender, System::EventArgs^ e) {
	genMatrix(matrixIn, rowsAmount, columnsAmount);
	updateMatrixInDGV();
}

//updates matrixOut from matrixIn
System::Void opi6::MyForm::performExcerciseButton_Click(System::Object^ sender, System::EventArgs^ e) {
	bool isInt = true;
	for (int i = 0; i < rowsAmount && isInt; i++)//read matrixInDGV to matrixIn with validation
		for (int j = 0; j < columnsAmount && isInt; j++)
			isInt = Int32::TryParse(matrixInDGV->Rows[i]->Cells[j]->Value->ToString(), matrixOut[i][j]);
	if (isInt) {
		exercise(matrixOut, rowsAmount, columnsAmount);
		updateMatrixOutDGV();
		matrixInDGV->ReadOnly = true;
		genRandomMatrixInButton->Enabled = false;
		performExcerciseButton->Enabled = false;
		badCellLabel->Visible = false;
	}
	else
		badCellLabel->Visible = true;
}

//"restarts" app
System::Void opi6::MyForm::restartButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (matrixIn)
		deleteMatrix(matrixIn, rowsAmount, columnsAmount);
	if (matrixOut)
		deleteMatrix(matrixOut, rowsAmount, columnsAmount);
	genRandomMatrixInButton->Enabled = false;
	performExcerciseButton->Enabled = false;

	columnsAmountTextBox->Enabled = true;
	rowsAmountTextBox->Enabled = true;
	columnsAmountTextBox->Text = "";
	rowsAmountTextBox->Text = "";
	badRowsLabel->Visible = false;
	badColumnsLabel->Visible = false;

	matrixInDGV->RowCount = 0;
	matrixOutDGV->RowCount = 0;
	matrixInDGV->ColumnCount = 0;
	matrixOutDGV->ColumnCount = 0;
	rowsAmount = columnsAmount = 0;
}

//updates cell of matrixInDGV from matrixIn
void opi6::MyForm::updateMatrixInDGV() {
	for (int i = 0; i < rowsAmount; i++)
		for (int j = 0; j < columnsAmount; j++)
			matrixInDGV->Rows[i]->Cells[j]->Value = matrixIn[i][j];
}

//updates cell of matrixOutDGV from matrixOut
void opi6::MyForm::updateMatrixOutDGV() {
	for (int i = 0; i < rowsAmount; i++)
		for (int j = 0; j < columnsAmount; j++)
			matrixOutDGV->Rows[i]->Cells[j]->Value = matrixOut[i][j];
}