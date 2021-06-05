#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iomanip>
#include <iostream>
#include <clocale>
#include <cstdlib>
#include <map>
#include <ctime>
#include <list>
#include <vector>
#include <math.h>
#include <clocale>
#include "Header.h"


namespace TerVerLaba {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace ZedGraph;
	map <double, double> mp;
	map <double, double> ::iterator it = mp.begin();

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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;

	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:









	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart
			// 
			chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea1->AxisX->Minimum = 0;
			chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea1->AxisY->Maximum = 1.2;
			chartArea1->BackColor = System::Drawing::Color::White;
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			legend1->Enabled = false;
			legend1->MaximumAutoSize = 80;
			legend1->Name = L"Legend1";
			legend1->Position->Auto = false;
			legend1->Position->Height = 15;
			legend1->Position->Width = 30.88671F;
			legend1->Position->X = 15;
			legend1->Position->Y = 5;
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(55, 76);
			this->chart->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->chart->Name = L"chart";
			series1->BorderWidth = 2;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
			series1->Legend = L"Legend1";
			series1->LegendText = L"“еоретическа€";
			series1->Name = L"Series1";
			series2->BorderWidth = 2;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
			series2->Legend = L"Legend1";
			series2->LegendText = L"Ёмпирическа€";
			series2->Name = L"Series2";
			this->chart->Series->Add(series1);
			this->chart->Series->Add(series2);
			this->chart->Size = System::Drawing::Size(677, 537);
			this->chart->TabIndex = 0;
			this->chart->Text = L"chart1";
			this->chart->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(55, 24);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(95, 44);
			this->button1->TabIndex = 1;
			this->button1->Text = L"графики";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// chart1
			// 
			chartArea2->AxisX->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea2->AxisX->Minimum = 0;
			chartArea2->AxisY->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea2->AxisY->Maximum = 1.2;
			chartArea2->BackColor = System::Drawing::Color::White;
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Enabled = false;
			legend2->MaximumAutoSize = 80;
			legend2->Name = L"Legend1";
			legend2->Position->Auto = false;
			legend2->Position->Height = 15;
			legend2->Position->Width = 30.88671F;
			legend2->Position->X = 15;
			legend2->Position->Y = 5;
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(713, 675);
			this->chart1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->chart1->Name = L"chart1";
			series3->BorderWidth = 2;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
			series3->Legend = L"Legend1";
			series3->Name = L"Series1";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Legend = L"Legend1";
			series4->LegendText = L"Ёмпирическа€";
			series4->Name = L"Series2";
			series4->YValuesPerPoint = 2;
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(677, 537);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(1492, 934);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm";
			this->Text = L"Terver";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		
	
private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	double w[1000];
	int size;
	double n = 100.0;
	bool flag = true;
	float a;
	float p2 = 0.3;
	int j = 0;
	int l = 10000;
	
	/*for (int i = 0; i < 500; i++) {
		w[i] = 0;
	}

	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		while (flag) {
			a = ((double)rand()) / RAND_MAX;
			if (a <= p2)
				flag = false;
			j++;

		}
		w[j] += 1;
		j = 0;
		flag = true;
	}*/
	for (int i = 0; i < l; i++) {
		mp[i] = 0;
	}

	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		while (flag) {
			a = ((double)rand()) / RAND_MAX;
			if (a <= p2)
				flag = false;
			j++;

		}
		mp[j] += 1;
		j = 0;
		flag = true;
	}
	for (int i = 0; i < l; i++) {
		if (mp[i] == 0)
			mp.erase(i);
	}
	double max=0.0;
	it = mp.begin();
	for (int i = 0; it != mp.end(); it++, i++) {
		if (it->first > max)
			max = it->first;
	}
	
	size = 100;

	chart->Series[0]->Points->Clear();
	//chart->Series[1]->Points->Clear();
	chart->Legends[0]->Enabled = true;
	double sum = 0.0;
	//теоретическа€ функци€ распределени€
	max = 3 / p2;
	int res_min = 0;
	double res_max = max;
	//double div[10]; // массив дл€ хранени€ значений функции распределени€
	chart->ChartAreas[0]->AxisX->Maximum = res_max + 1;
	chart->Series[0]->Points->AddXY(0, 0);
	
	for (int x = res_min; x <= res_max; x++)
	{
		sum = th_func(x);
		//div[x] = sum;
		chart->Series[0]->Points->AddXY(x, sum);
	}
	chart->Series[0]->Points->AddXY(res_max + 1, 1);

	 // выборочна€ функци€ распределени€ 
	it = mp.begin();
	sum = 0.0;
	chart->Series[1]->Points->AddXY(0, 0);
	for (int x = res_min+1; x <= res_max, it != mp.end(); it++, x++)
	{
		sum += mp[x]/n;
		chart->Series[1]->Points->AddXY(x, sum);
	}
	chart->Series[1]->Points->AddXY(res_max + 1, 1);
}
};
}



