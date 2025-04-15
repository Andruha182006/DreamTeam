#include <Windows.h>
#include "MathLibrary1.h"

namespace MATHEMATICAPP {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class Form1 : public Form
    {
    public:
        Form1() {
            InitializeComponent();
        }

    private:
        System::ComponentModel::Container^ components;

    protected:
        ~Form1() {
            if (components) delete components;
        }


    private:
        TextBox^ txtN;
        TextBox^ txtX;
        TextBox^ txtA;
        TextBox^ txtB;
        Label^ lblFactorialResult;
        Label^ lblCosResult;
        Label^ lblAreaResult;
        Button^ btnFactorial;
        Button^ btnCos;
        Button^ btnArea;

        void InitializeComponent(void) {
            this->Text = "MATHEMATICAPP";
            this->Width = 500;
            this->Height = 400;

            Label^ lbl1 = gcnew Label();
            lbl1->Text = "Введіть n:";
            lbl1->Top = 20; lbl1->Left = 20;
            this->Controls->Add(lbl1);

            txtN = gcnew TextBox();
            txtN->Top = 40; txtN->Left = 20;
            this->Controls->Add(txtN);

            btnFactorial = gcnew Button();
            btnFactorial->Text = "Обчислити факторіал";
            btnFactorial->Top = 70; btnFactorial->Left = 20;
            btnFactorial->Click += gcnew EventHandler(this, &Form1::btnFactorial_Click);
            this->Controls->Add(btnFactorial);

            lblFactorialResult = gcnew Label();
            lblFactorialResult->Top = 100; lblFactorialResult->Left = 20;
            lblFactorialResult->Width = 400;
            this->Controls->Add(lblFactorialResult);

            Label^ lblX = gcnew Label();
            lblX->Text = "Введіть x:";
            lblX->Top = 140; lblX->Left = 20;
            this->Controls->Add(lblX);

            txtX = gcnew TextBox();
            txtX->Top = 160; txtX->Left = 20;
            this->Controls->Add(txtX);

            Button^ btnCos = gcnew Button();
            btnCos->Text = "Обчислити cos(x) (ряд Тейлора)";
            btnCos->Top = 190; btnCos->Left = 20;
            btnCos->Click += gcnew EventHandler(this, &Form1::btnCos_Click);
            this->Controls->Add(btnCos);

            lblCosResult = gcnew Label();
            lblCosResult->Top = 220; lblCosResult->Left = 20;
            lblCosResult->Width = 400;
            this->Controls->Add(lblCosResult);

            Label^ lblA = gcnew Label();
            lblA->Text = "Катет a:"; lblA->Top = 260; lblA->Left = 20;
            this->Controls->Add(lblA);
            txtA = gcnew TextBox();
            txtA->Top = 280; txtA->Left = 20;
            this->Controls->Add(txtA);

            Label^ lblB = gcnew Label();
            lblB->Text = "Катет b:"; lblB->Top = 260; lblB->Left = 150;
            this->Controls->Add(lblB);
            txtB = gcnew TextBox();
            txtB->Top = 280; txtB->Left = 150;
            this->Controls->Add(txtB);

            btnArea = gcnew Button();
            btnArea->Text = "Обчислити площу трикутника";
            btnArea->Top = 310; btnArea->Left = 20;
            btnArea->Click += gcnew EventHandler(this, &Form1::btnArea_Click);
            this->Controls->Add(btnArea);

            lblAreaResult = gcnew Label();
            lblAreaResult->Top = 340; lblAreaResult->Left = 20;
            lblAreaResult->Width = 400;
            this->Controls->Add(lblAreaResult);
        }

    private:
        System::Void btnFactorial_Click(System::Object^ sender, System::EventArgs^ e) {
            try {
                int n = Convert::ToInt32(txtN->Text);
                if (n < 0) {
                    MessageBox::Show("n не може бути від’ємним.");
                    return;
                }
                int res = Factorial(n);
                lblFactorialResult->Text = "Факторіал: " + res.ToString();
            }
            catch (...) {
                MessageBox::Show("Некоректне значення для n");
            }
        }

        System::Void btnCos_Click(System::Object^ sender, System::EventArgs^ e) {
            try {
                double x = Convert::ToDouble(txtX->Text);
                int n = Convert::ToInt32(txtN->Text);
                if (n <= 0) {
                    MessageBox::Show("Кількість членів ряду має бути > 0");
                    return;
                }
                double result = CosTaylor(x, n);
                lblCosResult->Text = "cos(x) ~ " + result.ToString("F6");
            }
            catch (...) {
                MessageBox::Show("Некоректні значення для x або n");
            }
        }

        System::Void btnArea_Click(System::Object^ sender, System::EventArgs^ e) {
            try {
                double a = Convert::ToDouble(txtA->Text);
                double b = Convert::ToDouble(txtB->Text);
                if (a <= 0 || b <= 0) {
                    MessageBox::Show("Катети мають бути > 0");
                    return;
                }
                double area = TriangleArea(a, b);
                lblAreaResult->Text = "Площа трикутника: " + area.ToString("F2");
            }
            catch (...) {
                MessageBox::Show("Некоректні значення для a або b");
            }
        }
    };
}
