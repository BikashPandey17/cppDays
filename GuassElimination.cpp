#include<iostream>
using namespace std;
class G_E {
public:
	void g_e(float a[10][10], float b[10], float x[10], int n);
};
void G_E::g_e(float a[10][10], float b[10], float x[10], int n) {
	int i, j, k;
	float am,s;
	//pivotization of matrices is important since the user might notoriously enter non diagonal leading equations..
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if (abs(a[i][i]) < abs(a[j][i]))//checks if any element in the column is greater.
				for(k=0;k<=n;k++)
			{
					float temp = a[i][k];
					a[i][k] = a[j][k];
					a[j][k] = temp;
			}
	//to get triangular matrices
	for(i=0;i<n;i++)//we can always start the j array with i+1 obviously making it more efficient..
		for(j=i;j<n;j++)//but starting it with 0 makes no change in the answer though the algorithm becomes a little bit redundant in the 2nd step
			if (i != j) {
				am = a[j][i] / a[i][i];
				for (k = 0; k < n; k++)
					a[j][k] = a[j][k] - ( am * a[i][k] );
				b[j] = b[j] - (am*b[i]);
			}
	//to obtain the solutions using back substitution method
	x[n - 1] = b[n - 1] / a[n - 1][n - 1];
	for (i = n - 2; i >= 0; i--) {
		s = 0;
		for (j = i + 1; j < n; j++) {
			s = s + (a[i][j] * x[j]);
		}
		x[i] = (b[i] - s) / a[i][i];
	}
}

int main() {
	float a[10][10], b[10], x[10];
	int i, j, n;
	cout << endl << "Enter number of equations(1-10)=";
	cin >> n;
	cout << endl<<"Enter the coefficients"<<endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
		cout << "b[" << i << "]=";
		cin >> b[i];
	}
	G_E ob;
	ob.g_e(a, b, x, n);
	cout << "The roots are-->\n";
	for (i = 0; i < n; i++) {
		cout << "x[" << i << "]=" << x[i] << endl;
	}
	cout<<endl << "press any key and enter to end the task"<<endl;
	cin >> n;
	return 0;
}
