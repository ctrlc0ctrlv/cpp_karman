#pragma once

#include <windows.h>
#include <algorithm>
#include "karman.h"

#using < System.dll>
#using < System.Drawing.dll>
#using < System.Data.dll>
#using < System.Windows.Forms.dll>

namespace Project2
{
    using namespace System;
    using namespace System::IO;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Threading;

    /// <summary>
    /// Сводка для MyForm
    /// </summary>
public
    ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            //
            // TODO: добавьте код конструктора
            //
        }

    protected:
        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }
        int ind_picture = 0;

    private:
        System::Windows::Forms::PictureBox ^ pictureBox1;

    private:
        System::Windows::Forms::Label ^ label1;

    private:
        System::Windows::Forms::ListBox ^ listBox1;

    private:
        System::Windows::Forms::OpenFileDialog ^ openFileDialog1;

    private:
        System::Windows::Forms::Label ^ label2;

    private:
        System::Windows::Forms::Label ^ label3;

    private:
        System::Windows::Forms::Label ^ label4;

    private:
        System::Windows::Forms::DomainUpDown ^ domainUpDown1;

    private:
        System::Windows::Forms::TrackBar ^ trackBar1;

    private:
        System::Windows::Forms::Label ^ label5;

    private:
        System::Windows::Forms::PictureBox ^ pictureBox2;

    private:
        System::Windows::Forms::Button ^ button1;

    private:
        System::Windows::Forms::TextBox ^ textBox1;

    private:
        System::Windows::Forms::Button ^ button4;

    private:
        System::Windows::Forms::TextBox ^ textBox2;

    private:
        System::Windows::Forms::ToolTip ^ toolTip1;

    private:
        System::Windows::Forms::Button ^ button3;

    private:
        System::ComponentModel::BackgroundWorker ^ backgroundWorker1;

    private:
        System::Windows::Forms::ProgressBar ^ progressBar1;

    private:
        System::Windows::Forms::Label ^ label6;

    private:
        System::Windows::Forms::ToolTip ^ toolTip2;

    private:
        System::ComponentModel::IContainer ^ components;

    private:
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager ^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->listBox1 = (gcnew System::Windows::Forms::ListBox());
            this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->domainUpDown1 = (gcnew System::Windows::Forms::DomainUpDown());
            this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
            this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->trackBar1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->pictureBox2))->BeginInit();
            this->SuspendLayout();
            //
            // pictureBox1
            //
            this->pictureBox1->BackColor = System::Drawing::SystemColors::Control;
            // Image ^ image = Image::FromFile("histogram.png");
            // this->pictureBox1->BackgroundImage = image;
            this->pictureBox1->BackgroundImage = Image::FromFile(L"C:\\Users\\Антон\\Desktop\\New_folder\\projects\\Karman\\new\\histogram.png");
            this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->pictureBox1->Location = System::Drawing::Point(518, 303);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(301, 201);
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Bluu Next Cyrillic", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                              static_cast<System::Byte>(204)));
            this->label1->ForeColor = System::Drawing::Color::Purple;
            this->label1->Location = System::Drawing::Point(54, 28);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(727, 38);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Численное моделирование дорожки Кармана";
            this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
            //
            // listBox1
            //
            this->listBox1->Font = (gcnew System::Drawing::Font(L"Bluu Next Cyrillic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                                static_cast<System::Byte>(204)));
            this->listBox1->FormattingEnabled = true;
            this->listBox1->ItemHeight = 29;
            this->listBox1->Items->AddRange(gcnew cli::array<System::Object ^>(2){L"Вода", L"Воздух"});
            this->listBox1->Location = System::Drawing::Point(61, 157);
            this->listBox1->Name = L"listBox1";
            this->listBox1->Size = System::Drawing::Size(120, 62);
            this->listBox1->TabIndex = 3;
            this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
            //
            // openFileDialog1
            //
            this->openFileDialog1->FileName = L"openFileDialog1";
            this->openFileDialog1->InitialDirectory = L".\\";
            this->openFileDialog1->ShowReadOnly = true;
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Bluu Next Cyrillic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                              static_cast<System::Byte>(204)));
            this->label2->Location = System::Drawing::Point(57, 106);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(410, 48);
            this->label2->TabIndex = 9;
            this->label2->Text = L"1. Выбрать среду для численного модели-\r\nрования при T = 20 градусов Цельсия:";
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Bluu Next Cyrillic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                              static_cast<System::Byte>(204)));
            this->label3->Location = System::Drawing::Point(57, 243);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(413, 24);
            this->label3->TabIndex = 10;
            this->label3->Text = L"2. Выбрать число Рейнольдса от 50 до 300:";
            //
            // label4
            //
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Bluu Next Cyrillic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                              static_cast<System::Byte>(204)));
            this->label4->Location = System::Drawing::Point(57, 344);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(296, 24);
            this->label4->TabIndex = 11;
            this->label4->Text = L"3. Выбрать режим просмотра:";
            //
            // domainUpDown1
            //
            this->domainUpDown1->Font = (gcnew System::Drawing::Font(L"Bluu Next Cyrillic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                                     static_cast<System::Byte>(204)));
            this->domainUpDown1->Items->Add(L"x-компонента скорости V_x");
            this->domainUpDown1->Items->Add(L"y-компонента скорости V_y");
            this->domainUpDown1->Items->Add(L"модуль скорости V");
            this->domainUpDown1->Items->Add(L"поле вихрей");
            this->domainUpDown1->Items->Add(L"поле давлений");
            this->domainUpDown1->Location = System::Drawing::Point(61, 371);
            this->domainUpDown1->Name = L"domainUpDown1";
            this->domainUpDown1->Size = System::Drawing::Size(406, 36);
            this->domainUpDown1->TabIndex = 12;
            this->domainUpDown1->Text = L"Выбрать вид...";
            //
            // trackBar1
            //
            this->trackBar1->Cursor = System::Windows::Forms::Cursors::Hand;
            this->trackBar1->LargeChange = 50;
            this->trackBar1->Location = System::Drawing::Point(61, 272);
            this->trackBar1->Maximum = 300;
            this->trackBar1->Minimum = 50;
            this->trackBar1->Name = L"trackBar1";
            this->trackBar1->Size = System::Drawing::Size(378, 69);
            this->trackBar1->SmallChange = 10;
            this->trackBar1->TabIndex = 14;
            this->trackBar1->Value = 50;
            this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
            //
            // label5
            //
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Bluu Next Cyrillic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                              static_cast<System::Byte>(204)));
            this->label5->Location = System::Drawing::Point(57, 430);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(380, 48);
            this->label5->TabIndex = 16;
            this->label5->Text = L"4. Нажать на кнопку \"смоделировать\" и\r\nдождаться загрузки изображений.";
            //
            // pictureBox2
            //
            // this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
            this->pictureBox1->BackgroundImage = Image::FromFile(L"C:\\Users\\Антон\\Desktop\\New_folder\\projects\\Karman\\new\\histogram.png");
            this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->pictureBox2->Location = System::Drawing::Point(518, 96);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(302, 201);
            this->pictureBox2->TabIndex = 17;
            this->pictureBox2->TabStop = false;
            //
            // button1
            //
            this->button1->Font = (gcnew System::Drawing::Font(L"Bluu Next Cyrillic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                               static_cast<System::Byte>(204)));
            this->button1->Location = System::Drawing::Point(452, 536);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(368, 38);
            this->button1->TabIndex = 18;
            this->button1->Text = L"Открыть файл с данными";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            //
            // textBox1
            //
            this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox1->Font = (gcnew System::Drawing::Font(L"Bluu Next Cyrillic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                                static_cast<System::Byte>(204)));
            this->textBox1->Location = System::Drawing::Point(439, 273);
            this->textBox1->Name = L"textBox1";
            this->textBox1->ReadOnly = true;
            this->textBox1->Size = System::Drawing::Size(39, 24);
            this->textBox1->TabIndex = 20;
            //
            // button4
            //
            this->button4->Font = (gcnew System::Drawing::Font(L"Bluu Next Cyrillic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                               static_cast<System::Byte>(204)));
            this->button4->Location = System::Drawing::Point(452, 580);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(368, 38);
            this->button4->TabIndex = 23;
            this->button4->Text = L"Выход";
            this->button4->UseVisualStyleBackColor = true;
            this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
            //
            // textBox2
            //
            this->textBox2->AcceptsReturn = true;
            this->textBox2->AcceptsTab = true;
            this->textBox2->BackColor = System::Drawing::SystemColors::Window;
            this->textBox2->Location = System::Drawing::Point(841, 28);
            this->textBox2->MaximumSize = System::Drawing::Size(400, 600);
            this->textBox2->MinimumSize = System::Drawing::Size(400, 300);
            this->textBox2->Multiline = true;
            this->textBox2->Name = L"textBox2";
            this->textBox2->ReadOnly = true;
            this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->textBox2->Size = System::Drawing::Size(400, 590);
            this->textBox2->TabIndex = 24;
            //
            // button3
            //
            this->button3->Font = (gcnew System::Drawing::Font(L"Bluu Next Cyrillic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                               static_cast<System::Byte>(204)));
            this->button3->ForeColor = System::Drawing::Color::Purple;
            this->button3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->button3->Location = System::Drawing::Point(61, 536);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(368, 82);
            this->button3->TabIndex = 22;
            this->button3->Text = L"Смоделировать";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
            //
            // backgroundWorker1
            //
            this->backgroundWorker1->WorkerReportsProgress = true;
            this->backgroundWorker1->WorkerSupportsCancellation = true;
            this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
            this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker1_ProgressChanged);
            //
            // progressBar1
            //
            this->progressBar1->Location = System::Drawing::Point(61, 481);
            this->progressBar1->Name = L"progressBar1";
            this->progressBar1->Size = System::Drawing::Size(368, 23);
            this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
            this->progressBar1->TabIndex = 25;
            //
            // label6
            //
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Bluu Next Cyrillic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                              static_cast<System::Byte>(204)));
            this->label6->ForeColor = System::Drawing::Color::Purple;
            this->label6->Location = System::Drawing::Point(435, 478);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(21, 24);
            this->label6->TabIndex = 26;
            this->label6->Text = L"0";
            //
            // MyForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Menu;
            this->ClientSize = System::Drawing::Size(1278, 644);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->progressBar1);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->button4);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->pictureBox2);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->trackBar1);
            this->Controls->Add(this->domainUpDown1);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->listBox1);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->button3);
            this->Name = L"MyForm";
            this->Text = L"Дорожка Кармана. Герасимов, Зобова";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->pictureBox1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->trackBar1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->pictureBox2))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private:
        System::Void pictureBox1_Click(System::Object ^ sender, System::EventArgs ^ e)
        {
            array<String ^> ^ files = Directory::GetFiles(".\\animation\\");
            files->Sort(files, gcnew Comparison<String ^>(&compare));
            this->pictureBox1->Image = Image::FromFile(files[ind_picture]);
            ind_picture = (ind_picture + 1) % files->Length;
            this->pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;
        }

    private:
        static int compare(String ^ s1, String ^ s2)
        {
            String ^ temp1 = s1->Replace(".bmp", "")->Replace(".\\animation\\", "")->Replace(".", ",");
            String ^ temp2 = s2->Replace(".bmp", "")->Replace(".\\animation\\", "")->Replace(".", ",");
            if (System::Convert::ToDouble(temp1) < System::Convert::ToDouble(temp2))
                return -1;
            else if (temp1 == temp2)
                return 0;
            else
                return +1;
        }

    private:
        System::Void label1_Click(System::Object ^ sender, System::EventArgs ^ e)
        {
        }

    private:
        System::Void listBox1_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e)
        {
            if (listBox1->SelectedIndex == 0)
            {
                nu = nu_water;
            }
            else
            {
                nu = nu_air;
            }
        }

    private:
        System::Void trackBar1_Scroll(System::Object ^ sender, System::EventArgs ^ e)
        {
            textBox1->Text = "" + trackBar1->Value;
            Re = trackBar1->Value;
        }

    private:
        System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e)
        {
            ToolTip ^ toolTip2 = gcnew ToolTip();
            toolTip2->AutoPopDelay = 5000;
            toolTip2->InitialDelay = 1000;
            toolTip2->ReshowDelay = 500;
            toolTip2->ShowAlways = true;
            if (k != k_max)
            {
                this->button1->Enabled = false;
                toolTip2->SetToolTip(this->button1, "К сожалению, работа с файлами в процессе моделирования невозможна.");
            }
            else
            {
                this->button1->Enabled = true;
                OpenFileDialog ^ openDlg = gcnew OpenFileDialog();
                openDlg->Filter = "Text Files(*.txt)|*.txt|All files (*.*)|*.*";
                if (this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                {
                    this->textBox2->Text = System::IO::File::ReadAllText(this->openFileDialog1->FileName);
                }
            }
        }

    private:
        System::Void button4_Click(System::Object ^ sender, System::EventArgs ^ e)
        {
            backgroundWorker1->CancelAsync();
            Close();
        }

    private:
        System::Void button3_Click(System::Object ^ sender, System::EventArgs ^ e)
        {
            ToolTip ^ toolTip1 = gcnew ToolTip();
            toolTip1->AutoPopDelay = 5000;
            toolTip1->InitialDelay = 1000;
            toolTip1->ReshowDelay = 500;
            toolTip1->ShowAlways = true;
            if (trackBar1->Value == 0 || listBox1->SelectedIndex == -1 || domainUpDown1->SelectedIndex == -1)
            {
                toolTip1->SetToolTip(this->button3, "Пожалуйста, заполните все поля!");
            }
            else
            {
                backgroundWorker1->RunWorkerAsync(1);
                toolTip1->SetToolTip(this->button3, "Моделирование началось! Это займет некоторое время.");
                U = Re * nu;
                T_max = 80. / U;
                k_max = (int)(round(T_max / dt));
                this->progressBar1->Maximum = k_max + 1;
                while (this->backgroundWorker1->IsBusy)
                {
                    this->progressBar1->Value = k;
                    this->label6->Text = System::Convert::ToString(k);
                    Application::DoEvents();
                }
                backgroundWorker1->CancelAsync();
                toolTip1->SetToolTip(this->button3, "Моделирование завершено.");
            }
        }

    private:
        System::Void backgroundWorker1_DoWork(System::Object ^ sender, System::ComponentModel::DoWorkEventArgs ^ e)
        {
            int temp = this->domainUpDown1->SelectedIndex;
            // char* params[1];
            // main(1, params);
            char params[17];
            itoa(temp, params, 10);
            main(2, params);
        }

    private:
        System::Void backgroundWorker1_ProgressChanged(System::Object ^ sender, System::ComponentModel::ProgressChangedEventArgs ^ e)
        {
            progressBar1->Value += e->ProgressPercentage;
        }
    };

}