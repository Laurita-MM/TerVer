#include <iostream>
#include <clocale>
#include <cstdlib>
#include <map>
#include <ctime>
#include <list>
#include <iomanip>
#include <vector>
#include <math.h>
#include <clocale>

using namespace std;
int index;
int n = 100;
int k = 3;
int m = 1;
float p2 = 0.3;
float p = 1 - p2;
float p1 = 1 - p;
int l = 10000;
list <float> val;
bool flag = true;
double max1 = 0.0;
float a;
float c[1000];
int j = 0;
double r0, g;
float alpha = 0.5;
map <int, int> mp;
map <int, int> ::iterator it = mp.begin();
std::vector<double> splitting;
std::vector<double> q;

/*template<typename T>
std::vector<double> linspace(T start_in, T end_in, int num_in)
{

	std::vector<double> linspaced;

	double start = static_cast<double>(start_in);
	double end = static_cast<double>(end_in);
	double num = static_cast<double>(num_in);

	if (num == 0) { return linspaced; }
	if (num == 1)
	{
		linspaced.push_back(start);
		return linspaced;
	}

	double delta = (end - start) / (num - 1);

	for (int i = 0; i < num - 1; ++i)
	{
		linspaced.push_back(start + delta * i);
	}
	linspaced.push_back(end); // I want to ensure that start and end
							  // are exactly the same as the input
	return linspaced;
}*/

/*void print_vector(std::vector<double> vec)
{
	std::cout << "size: " << vec.size() << std::endl;
	for (double d : vec)
		std::cout << d << " ";
	std::cout << std::endl;
}*/
bool number_single(const int& v) {
	return v <= 1;
}

double f(double x, int r) {
	double result = 0.0;

	if (x <= 0) {
		return 0.0;
	}
	else {
		result = pow(2.0, (double)(-r) / 2.0) * (1.0 / tgamma((double)r / 2.0)) * pow(x, (double)r / 2.0 - 1.0) * exp(-x / 2.0);
		return result;
	}
}

double integral(double a, double b, int r) {
	double result = 0.0;
	int n = 10000;

	for (int i = 1; i <= n; i++) {
		result += (f(a + (b - a) * (double)(i - 1) / (double)n, r) + f(a + (b - a) * (double)i / (double)n, r)) * (b - a) / (2.0 * (double)n);
	}

	return result;
}

double F(double R_0, int r) {
	return 1.0 - integral(0.0, R_0, r);
}




// вычисление выборочного среднего
double GetExpectedValue(map <int, int> mp) {
	double sum = 0.0;
	double summ = 0.0;

	it = mp.begin();
	for (int i = 0; it != mp.end(); it++, i++) {
		summ += it->second;
	}

	it = mp.begin();
	for (int i = 0; it != mp.end(); it++, i++) {
		sum += (it->second) * (it->first);
	}

	sum *= (1 / summ);

	return sum;
}

// вычисление выборочной дисперсии
double GetDispersion(map <int, int> mp) {
	double v = 0.0, x = 0.0;
	double sum = 0.0;

	it = mp.begin();
	for (int i = 0; it != mp.end(); it++, i++) {
		v += it->second;
	}
	x = GetExpectedValue(mp);
	it = mp.begin();
	for (int i = 0; it != mp.end(); it++, i++) {
		sum += (it->first - x) * (it->first - x) * (it->second);
	}

	sum *= (1 / v);

	return sum;
}

// вычисление выборочной медианы
double GetMedian(map <int, int> mp) {
	int v = 0;
	int b = 0;
	int count = 1, c = 1;

	std::vector<int> w;
	if (n % 2 == 0) {
		m = n / 2;
		it = mp.begin();
		for (int i = 0; it != mp.end(); it++, i++) {
			b += it->second;
			if (m > b)
				count++;
			if (m > b + 1)
				c++;
		}
		return (count + c) / 2;
	}
	else {
		m = n / 2 + 1;
		it = mp.begin();
		for (int i = 0; it != mp.end(); it++, i++) {
			b += it->second;
			if (m > b)
				count++;
		}
		return count;
	}



	/*it = mp.begin();
	for (int i = 0; it != mp.end(); it++, i++) {
		for (int j = 0; j < it->second; j++) {
			w.push_back(it->first);
		}
	}

	if (n % 2 == 0) {
		m = (1 / 2) * (w[(n / 2)] + w[(n / 2) - 1]);
		return m;
	}
	else {
		return w[int(n / 2)];
	}*/
}
//размах выборки
double Sweep(map <int, int> mp) {
	int max = 0;
	int min = 100000000;
	std::vector<int> w;

	it = mp.begin();
	for (int i = 0; it != mp.end(); it++, i++) {
		if (it->first > max)
			max = it->first;
	}

	it = mp.begin();
	for (int i = 0; it != mp.end(); it++, i++) {
		if (it->first < min)
			min = it->first;
	}


	return max - min;
}

double distribution_function(double x, map <int, int> mp) {
	int val;
	if (x <= 0)
		return 0;
	else
		val = 0;
	it = mp.begin();
	for (int i = 0; it != mp.end(); it++, i++) {
		if (x > it->first) {
			val += it->second;
		}
		else
			break;
		val /= n;
		return val;
	}
}
//  “еоретическа€ функци€ распределени€
double th_func(double x) {
	return 1 - pow((1 - p2), x);
}
//ѕодсчет геометрической веро€тности дл€ q_j
double geom_probability(double x) {
	return p2 * pow((1 - p2), (x - 1));
}

//ћера расхождени€ теоретической и выборочной функций распределени€
double D(map <int, int> mp) {
	double max = 0.0, d = 0.0;
	std::vector<double> x;
	it = mp.begin();
	for (int i = 0; it != mp.end(); it++, i++) {
		if (it->second > max) {
			max = it->second;
		}
		for (i = 0; i < max; i++) {
			x[i] = i;
		}
		for (i = 0; i < size(x); i++) {
			if (abs(distribution_function(i, mp) - th_func(i)) > d) {
				d = abs(distribution_function(i, mp) - th_func(i));
			}
		}
		d = int(d * 10000 + 0.5) / 10000.0;
		return d;
	}
}

double max_deviation(map <int, int> mp) {
	double maxd = 0.0;
	it = mp.begin();
	for (int i = 0; it != mp.end(); it++, i++) {
		if (abs(p * pow((1 - p), it->first) - it->second / n) > maxd) {
			maxd = abs(p * pow((1 - p), it->first - it->second) / n);
		}
		maxd = int(maxd * 10000 + 0.5) / 10000.0;
		return maxd;
	}
}

double nj(int n, vector<double>splitting, map <int, int> mp) {
	int result = 0;
	std::vector<int> w;

	it = mp.begin();
	/*for (int i = 0; it != mp.end(); it++, i++) {
		for (int j = 0; j < it->second; j++) {
			w.push_back(it->first);
		}
	}
	for (int i = 0; i < size(w); i++)
	{
		for (int j = 0; j < z->size() - 1; j++)
		{
			//  если значение эксперимента попадает в интервал [z[j], z[j+1]]
			if (((double)expandedResults->at(i) > z->at(j)) && ((double)expandedResults->at(i) < z->at(j + 1)))
				n[j + 1]++; // увеличиваем счетчик числа наблюдений, попавших в интервал
		}, it != mp.end() ,it++
	}*/
	for (int i = splitting[n]; i < splitting[n + 1]; i++) {
		if (mp.count(i) > 0) {
			result += mp[i];
		}
	}
	return result;
}

double R0(vector<double>splitting, map <int, int> mp, vector<double>q) {
	double r0 = 0;
	for (int i = 0; i < k; i++) {
		if (q[i] != 0) {
			r0 += pow((nj(i, splitting, mp) - n * q[i]), 2) / (n * q[i]);
			//cout << nj(i, splitting, mp) << " ";
		}
	}
	return r0;//nj(i, splitting, mp)
}

double distr_func(double x, double *w, int size) {
	int val;
	if (x <= 0)
		return 0;
	else
		val = 0;
	
	for (int i = 1; i<=size; i++) {
		if (x > i) {
			val += w[i];
		}
		else
			break;
		val /= n;
		return val;
	}
}



/*int main() {

	setlocale(LC_ALL, "Russian");

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


	it = mp.begin();
	for (int i = 0; it != mp.end(); it++, i++) {
		if (it->first > max1) {
			max1 = it->first;
		}
	}



	double left_b = max1; // ћаксимальное значение выборки

	//std::fill(splitting.begin(), splitting.end(), k+1);
	//std::fill(q.begin(), q.end(), k);

	for (int i = 0; i < (k + 1); i++) {
		splitting.push_back(0);
	}
	for (int i = 0; i < k; i++) {
		q.push_back(0);
	}

	cout << std::setw(8) << std::left << "y(i)" << " ";
	it = mp.begin();
	for (int i = 0; it != mp.end(); it++, i++) {
		cout << std::setw(10) << std::left << it->first << " ";
	}
	cout << endl;
	it = mp.begin();
	cout << std::setw(8) << std::left << "n(i)" << " ";
	for (int i = 0; it != mp.end(); it++, i++) {
		c[i] = it->second;
		cout << std::setw(10) << std::left << it->second << " ";
	}
	cout << endl;

	it = mp.begin();
	cout << std::setw(8) << std::left << "n(i)/n" << " ";
	for (int i = 0; it != mp.end(); it++, i++) {
		float d[1000];
		d[i] = c[i] / n;
		cout << std::setw(10) << std::left << round(d[i] * 10000) / 10000 << " ";
	}
	cout << endl;

	double sampl_m = GetExpectedValue(mp);
	double med = GetMedian(mp);
	double disp2 = GetDispersion(mp);
	double sw = Sweep(mp);
	cout << endl;
	cout << std::setw(15) << std::left << "E_eta";
	cout << std::setw(15) << std::left << "x";
	cout << std::setw(15) << std::left << "|E_eta - x|";
	cout << std::setw(15) << std::left << "D_eta";
	cout << std::setw(15) << std::left << "S^2";
	cout << std::setw(15) << std::left << "|D_eta - S^2|";
	cout << std::setw(15) << std::left << "Me";
	cout << std::setw(15) << std::left << "R" << endl;
	cout << std::setw(15) << std::left << 1 / p2;
	cout << std::setw(15) << std::left << sampl_m;
	cout << std::setw(15) << std::left << abs(1 / p2 - sampl_m);
	cout << std::setw(15) << std::left << (1 - p2) / pow(p2, 2);
	cout << std::setw(15) << std::left << disp2;
	cout << std::setw(15) << std::left << abs((1 - p2) / pow(p2, 2) - disp2);
	cout << std::setw(15) << std::left << med;
	cout << std::setw(15) << std::left << sw << endl;

	cout << endl;
	cout << std::setw(8) << std::left << "y" << " ";
	it = mp.begin();
	for (int i = 0; it != mp.end(); it++, i++) {
		cout << std::setw(10) << std::left << it->first << " ";
	}
	cout << endl;

	it = mp.begin();
	cout << std::setw(8) << std::left << "P" << " ";
	for (int i = 0; it != mp.end(); it++, i++) {
		c[i] = it->second;
		cout << std::setw(10) << std::left << p2 * pow((1 - p2), it->first) << " ";
	}
	cout << endl;

	it = mp.begin();
	cout << std::setw(8) << std::left << "n(i)/n" << " ";
	for (int i = 0; it != mp.end(); it++, i++) {
		float d[1000];
		d[i] = c[i] / n;
		cout << std::setw(10) << std::left << round(d[i] * 10000) / 10000 << " ";
	}
	cout << endl;

	cout << "¬ведите интервалы разбиени€" << endl;
	for (int z = 1; z < k; z++) {
		cout << "z" << z << endl;
		cin >> splitting[z];
	}
	splitting[0] = 1;
	splitting[k] = 10000;
	index = 0;

	cout << splitting[0] << endl;
	int hb, b;

	cout << nj(0, splitting, mp) << " ";
	cout << nj(1, splitting, mp) << " ";
	cout << nj(2, splitting, mp) << " ";

	//вычисление q
	for (hb = 1; hb < size(splitting); hb++) {

		for (int i = 0; i < left_b; i++) {
			if (i < splitting[hb] && i >= splitting[hb - 1]) {
				q[hb - 1] += geom_probability(i);
			}


		}
	}
	cout << hb << endl;
	double summa = 0.0;
	for (int i = 0; i < k - 1; i++) {
		summa += q[i];
	}

	q[hb - 2] = 1 - summa;
	cout << "q = ";
	for (int i = 0; i < k; i++) {
		cout << q[i] << "  ";
	}

	cout << endl;
	int result = 0;
	std::vector<int> w;
	std::vector<double> nj;
	for (int i = 0; i < k; i++) {
		nj.push_back(0);
	}


	it = mp.begin();
	for (int i = 0; it != mp.end(); it++, i++) {
		for (int j = 0; j < it->second; j++) {
			w.push_back(it->first);
		}
	}


	double s = 0.0;

	r0 = R0(splitting, mp, q);
	cout << "r0 = " << r0 << endl;
	g = F(r0, k - 1);
	cout << "f = " << g << endl;

	if (g > alpha)
		cout << "ѕринимаем" << endl;
	else
		cout << "ќтвергаем" << endl;
	//it = mp.begin();
	//cout << it->first << " " << it->second << endl;
	system("pause");
	return 0;
}*/