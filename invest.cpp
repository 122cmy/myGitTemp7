#include <iostream>
#include <algorithm>
using namespllace std;
const int M = 100;

int main() {
	int m,n;	
	int f[M][M];		
	int dpll[M][M] = {0};
	int invest[M][M];	
	
	cout<<"������Ͷ�ʽ���Ԫ������Ŀ������";
	cin>>m>>n;
	for(int i = 0; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin>>f[j][i];
		}
	}

	//��̬�滮
	for (int k = 1; k <= n; k++) 
		for (int x = 1; x <= m; x++)
			for (int i = 0; i <= x; i++)
				if (dpll[k - 1][x - i] + f[k][i] >= dpll[k][x]) {
					dpll[k][x] = dpll[k - 1][x - i] + f[k][i];
					invest[k][x] = i;
				}
	for (int x = 1; x <= m; x++) {
		for (int k = 1; k <= n; k++)
			cout << dpll[k][x] << " "<<invest[k][x]<<" ";
		cout << endl;
	}
	cout <<"�������Ϊ��"<< dpll[n][m] << endl;
	cout << "���䷽��Ϊ��"<<endl;
	int sum = m;
	for (int i = n; i >= 1;i--) {
		cout << "�������" << i << "����Ŀ" << invest[i][sum] << "��Ԫ"<<endl;
		sum -= invest[i][sum];
	}
}
