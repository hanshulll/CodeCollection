#include<bits/stdc++.h>
using namespace std;

map<string,int> sp;
int spsize=1;
int villainsize=1;
int a[1010];
int cal[1010];
int d[1010];
int memo[1010][1010];
bool can[1010][1010];

void print(){
	for(int i=0;i<spsize;i++){
		cout << i << " "<< a[i] << " "<< cal[i] << endl;
	}
	for(int i=0;i<villainsize;i++){
		cout << i << " "<< d[i] << " ";
		cout  << endl;
	}
}


int main(){
	int P,V,E;
	scanf("%d %d %d",&P,&V,&E);
	while(!((P==0)&&(V==0)&&(E==0))){
		for(int i=0;i<1010;i++){
			for(int j=0;j<1010;j++){
				can[i][j]=false;
			}
		}
		for(int i=1;i<=P;i++){
			string spname;
			int tempa;
			int tempcal;
			cin >> spname >> tempa >>tempcal;
			
			a[i]=tempa;
			cal[i]=tempcal;
			sp.insert(pair<string,int>(spname,i));
		}
		for(int i=1;i<=V;i++){
			string vilname;
			string spname;
			int tempd;

			cin >> vilname >> tempd >> spname;

			d[i]=tempd;

			istringstream instream(spname);
			
			string singlesp;
			while(getline(instream,singlesp,',')){
				map<string,int>::iterator it;
				it=sp.find(singlesp);
				int index=it->second;
				can[i][index]=true;
			}
		}
		//print();

		
		for(int i = 0;i <= P;++i){
			memo[0][i] = 0;
		}
        for(int i = 1;i <= V;++i) {
        	memo[i][0] = E+1;
        }

		for(int i=1;i<=V;i++){
			for(int j=1;j<=P;j++){
				memo[i][j]=memo[i][j-1];
				if((can[i][j]) && (a[j]>=d[i])){
					memo[i][j]=min(memo[i][j],memo[i-1][j-1]+cal[j]);
				}
			}
		}

		if(memo[V][P]<=E){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}


		scanf("%d %d %d",&P,&V,&E);
	}
	return 0;
}
