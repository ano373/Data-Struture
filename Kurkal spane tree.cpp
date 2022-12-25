#include <iostream>
#include <conio.h>
using namespace std;

// ************** Kruskals algorithm for Minimum Spanning Tree ***********
#define dim 7
#define inf 99

int weight[dim][dim] =
{ { 0, 28, inf, inf, inf, 10, inf },
{ 28, 0, 16, inf, inf, inf, 14 },
{ inf, 16, 0, 12, inf, inf, inf },
{ inf, inf, 12, 0, 22, inf, 18 },
{ inf, inf, inf, 22, 0, 25, 24 },
{ 10, inf, inf, inf, 25, 0, inf },
{ inf, 14, inf, 18, 24, inf, 0 } };

void print_matrix(int array[dim][dim])
{
	int r, c;
	for (c = 0; c < dim; c++)		cout << "\t" << c;
	cout << "\n";
	for (r = 0; r < dim; r++)
	{
		cout << "\n" << r << "\t";
		for (c = 0; c < dim; c++)
			if (array[r][c] == inf)		cout << "#\t";
			else								cout << array[r][c] << "\t";
	}
	cout << "\n \n";
}

int main(void)
{
	int z[dim], min_span[dim][dim];
	int min, rmin, cmin, r, c, i, j, total_weight, group;

	print_matrix(weight);

	for (r = 0; r < dim; r++)
		for (c = 0; c < dim; c++)
			if (r == c)	min_span[r][c] = 0;
			else			min_span[r][c] = inf;

			group = 0;
			total_weight = 0;
			for (r = 0; r < dim; r++)  z[r] = -1;

			while (1)
			{
				min = inf;
				for (r = 0; r < dim; r++){
                        cout<<"row no:"<<r<<"\t";
					for (c = 0; c < r; c++)
						if (min > weight[r][c])
                         {
                             rmin = r; cmin = c; min = weight[r][c];
                             cout<<min<<" \t"<<endl;
                         }
				}
                cout<<" \n loop ended \t"<< "{ rmin= "<<rmin<<"\t cmin= "<<cmin<<" }\t";
                cout<<"final min= "<<min<<endl;
				if (min == inf)
				{
					cout << "\n\n Minimum Total Weight =" << total_weight << endl << endl;
					print_matrix(min_span);
					return 0;
				}

				if ((z[rmin] != z[cmin]) || (z[rmin] == -1) || (z[cmin] == -1))
				{
					min_span[rmin][cmin] = min_span[cmin][rmin] = min;

					total_weight += min;
					if ((z[rmin] == -1) && (z[cmin] == -1))
					{
						group++; z[rmin] = z[cmin] = group;
					}
					else if ((z[rmin] == -1) && (z[cmin] != -1))
						z[rmin] = z[cmin];
					else if ((z[cmin] == -1) && (z[rmin] != -1))
						z[cmin] = z[rmin];
					else    //z[rmin] != -1 && z[cmin] != -1 && z[rmin] != z[cmin]
					{
						j = z[cmin];
						for (i = 0; i < dim; i++)
							if (z[i] == j) z[i] = z[rmin];
					}
				}
				cout<<"................. \n";
				weight[rmin][cmin] = inf;
			}
	getch();
}
