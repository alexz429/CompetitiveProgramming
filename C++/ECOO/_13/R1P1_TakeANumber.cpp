/*
 * TakeANumber.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: Alex.Zhang
 */

#include <iostream>

using namespace std;
int main(){
	int count;
	cin>>count;
	string next;
	cin>>next;
//	cout<<next;s
//	cout<<"HA"<<endl;
	int overFlow=0;
	int lates=0;
	while(next.compare("EOF")!=0){
		if(next.compare("TAKE")==0){
			overFlow++;
			lates++;
			count++;
			if(count>999){
				count=1;
			}
		}
		else if(next.compare("SERVE")==0){
			overFlow--;
		}
		else{
			cout<<lates;
			cout<<" ";
			cout<<overFlow;
			cout<<" ";
			cout<<count<<endl;

			overFlow=0;
			lates=0;
		}
		cin>>next;
	}
	return 0;
}
