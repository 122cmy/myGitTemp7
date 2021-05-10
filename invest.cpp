#include <iostream>
#include <algorithm>
using namespllace std;
const int M = 100;

int main() {
	int m,n;	
	int f[M][M];		
	int dpll[M][M] = {0};
	int invest[M][M];	
	
	cout<<"请输入投资金额（万元）和项目个数：";
	cin>>m>>n;
	for(int i = 0; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin>>f[j][i];
		}
	}

	//动态规划
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
	cout <<"最大收益为："<< dpll[n][m] << endl;
	cout << "分配方案为："<<endl;
	int sum = m;
	for (int i = n; i >= 1;i--) {
		cout << "分配给第" << i << "个项目" << invest[i][sum] << "万元"<<endl;
		sum -= invest[i][sum];
	}
}
