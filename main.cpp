#include <cstdio>
int learning[10][25][2];
int tempdata[25];
int learn(int data[25], int num){
	for(int i = 0;i < 25; i++){
		if(data[i] == learning[0][i][0]){
			learning[0][i][1] += 1;
		}else{
			learning[0][i][1] -= 1;
		}
		if(learning[num][i][1] < 0){
			if(learning[num][i][0] == 1){
				learning[num][i][0] = 0;
			}else{
				learning[num][i][0] = 1;
			}
			learning[num][i][1] = 1;	
		}
	}	
}
int position(){
}
int main(){
	
}
