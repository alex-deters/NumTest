#include <cstdio>
#include <cstring>
#include <iostream>
int learning[10][25][2] = {0};
int data[25] = {0};
void learn(int num){
	for(int i = 0; i < 25; i++){
		if(data[i] == learning[num][i][0]){
			learning[num][i][1] += 1;
		}else{
			learning[num][i][1] -= 1;
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
int read(){
	int activator[10] = {0};
	int max[2] = {0};
	for(int n = 0; n < 10; n++){
		for(int i = 0; i < 25; i++){
			if(data[i] == learning[n][i][0]){
				activator[n] += learning[n][i][1];	
			}else{
				activator[n] -= learning[n][i][1];
			}
		}
		if(n == 0){
			max[0] = activator[0];
			max[1] = 0;
		}else if(activator[n] > max[0]){
			max[0] = activator[n];
			max[1] = n;
		}
	}
	return(max[1]);
			
}
int main(){
	bool quit = false;
	int tempkey;	
	while(!quit){
	printf("Select an option:\n1: Full learning mode\n2: Read mode\n");
	std::cin >> tempkey;
	switch(tempkey){
		case 1:
			printf("Draw a number between 0 and 9, the number being 5x5 and a 1 being a full box and a 0 being an empty box\n");
			for(int i = 0; i < 25; i++){
				std::cin >> data[i];
			}	
			printf("Enter in what number you drew\n");
			std::cin >> tempkey;
			learn(tempkey);
			break;
		case 2:
			printf("Draw a number between 0 and 9, the number being 5x5 and a 1 being a full box and a 0 being an empty box \n");
			for(int i = 0; i < 25; i++){
			std::cin >> data[i];
			}
			tempkey = read();
			printf("The number %d was read, what was the correct number?\n",tempkey);
			std::cin >> tempkey;
			learn(tempkey);
			break;
		default:
			break;
	}
	}
}
