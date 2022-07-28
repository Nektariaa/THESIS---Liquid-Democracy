#include <iostream>
#include <fstream>
#include <cstdlib> //for the random num
#include <ctime>
#include<chrono> 
#include<random>
#include <bits/stdc++.h>
using namespace std;

int main ()
{
	//ARXIKO DIKTIO me 0
	int nog=500;//num of voters 
	int noig=25; //num of gurus	10% of 20 voters
	int missinformed=50;//EPELEKSE TO PLITHOS TWN MISSINFORMED-------------------------------------------------------------------------!-!-!-!-!
	int array[nog+1][nog+1];
	for (int i = 0; i < nog+1; i++)
    {
        for (int j = 0; j < nog+1; j++)
        {
            array[i][j] = 0;

        }
    }
    
    
    
    
//read small world network from file
    ifstream file("WS 500-12-0.375.txt");
	
    int x, y;
    char padding;
	while (!file.eof()) // While there is somthing more in the file
	    {
	        file >> x >> padding >> y ;
	        
	        array[x][y] = 1; // Place the mark
	    }
	    
	/*for (int i = 1; i < nog+1; i++){ 
	   	for (int j = 1; j < nog+1; j++){
	    		
			cout << array[i][j] << " ";
	    }
		cout << endl;
	}
cout<<endl;-----------------------------------------------------------------------------------------------------------1*/


//guru array creation	
	
	
	float guru [nog];
	
	int index [noig];
	srand(time(0));  // Initialize random number generator.
	
	for (int j = 1; j < nog+1; j++)
        {
            guru[j] = 0;

        }
    





//declare gurus in random   
    //cout<<"Random gurus generated between 1 and 20:"<<endl;
    for(int i=1;i<noig+1;i++){
	
        index[i]= (rand() % nog) + 1; 
       // cout << index[i] << " ";
    }
   // cout << endl;-----------------------------------------------------------------------------------------------------------2*/
    
    set<int>s;
	
	for(int i=1; i<noig+1; i++){
		s.insert(index[i]);
	}
	
	set<int>::iterator it;
	
	int metritis=0;
	//cout<<"After removing dups: \n";
	for(it =s.begin(); it!=s.end(); ++it){
		//cout<<*it<<" ";
		metritis++;
	}
    //cout << endl;
    //cout << endl;
    //cout<<metritis;
    
    ////////////////////////////////////////////////
    double S[metritis]={0};
    for (int i=1; i<noig+1; i++){
    	for (int j=1; j<nog+1; j++){
    		if (index[i] == j){
    			guru[j] = 1;
			}
		}
	}
	/*cout<<endl;
	cout<<"guru[nog]: ";
	cout<<endl;
	for (int j=1; j<nog+1; j++){
		cout << guru[j] << " ";
	}
	cout << endl;//-----------------------------------------------------------------------------------------------------------3*/

	
	
	
	
//Gaussian distrubiuted numbers for gurus accurancies	
	unsigned seed = chrono::steady_clock::now().time_since_epoch().count(); 
    default_random_engine e (seed); 
  
    /* declaring normal distribution object 'distN' and initializing its mean and standard deviation fields. */
  	/* Mean and standard deviation are distribution parameters of Normal distribution. Here, we have used mean=0.7, and standard deviation=0.1. */
    normal_distribution<double> distN(0.7,0.1); 
    
    
    double r;
    for (int i=1; i<nog+1; i++){
      	r=distN(e);
      
      	if (guru[i]==1) {
      		guru[i]=r;
		  }
	}
	
	/*for(int i=1; i<nog+1; i++){
		cout<<guru[i]<<" ";
	}//---------------------------------------------------------------------------------------------------------------------4*/
	  
	int j=1;
	for (int i=1; i<nog+1; i++){
		if (guru[i]!=0) {
			S[j]=guru[i];
			j++;
		}
	}
	/*cout<<endl;
	cout<<endl;
	cout<<"S[2]: ";
	for (int j=1; j<metritis+1; j++){
		cout<<S[j]<<" ";
	}
	cout<<endl;-----------------------------------------------------------------------------------------------------------5*/

//Parallel descending sortment of S (gaussian_dis_nums) and guru (set of gurus)
	for(int i=1; i<metritis+1; i++){
		for(int j=i+1; j<metritis+1; j++){
			if ( S[i] <= S[j]){
				double temp = S[i];
				S[i]=S[j];
				S[j]=temp;
				
				int temp1= index[i];
				index[i]=index[j];
				index[j]=temp1;
			}
			
		}
	}
	/*cout<<endl;
	cout<<"Descending sorted S[]:";
	cout<<endl;
	for (int i=1; i<metritis+1; i++){
		cout << S[i] << " ";
	}
	cout << endl;
	cout<<endl;
	cout<<"Descending sorted index[]:";
	cout<<endl;
	for (int i=1; i<metritis+1; i++){
		cout << index[i] << " ";
	}
	cout << endl;cout << endl;//-----------------------------------------------------------------------------------*/
	
	
	
	
	
	int fol[nog+1][nog+1];
	
	for (int i = 1; i < nog+1; i++){
    	for (int j = 1; j <nog+1; j++){
            fol[i][j] = 0;
            
		}
		
    }
	
	
	/*for (int i=1; i<nog+1; i++){
		for(int j=1; j<nog+1; j++){
			cout<<fol[i][j]<<" ";
		}
		cout << endl;
	}	
	cout << endl;*/
	
	//katw apo ti thesi kathe guru tipwse vale tous psifoforous 
	//pou ton ftanoun sto diktyo
	//dld tous followers tou kathe guru
	for (int k=1; k<noig+1; k++){
		int l=1;
		//int d=1;
		for (int i=1; i<nog+1; i++){
			for (int j=1; j<nog+1; j++){
				if ((j==index[k]) && (array[i][j]==1)){
					fol[l][j]=i;
					l++;
				}
				
			}
		}
		
	}
	/*cout<<"gia na dw";
	cout<<endl;
	cout<<endl;
	for (int l=1; l<nog+1; l++){
		for(int j=1; j<nog+1; j++){
			cout<<fol[l][j]<<" ";
		}
		cout << endl;
	}	
	cout << endl;*/
	
	
/*	for (int l=1; l<nog+1; l++){
		
		
			for (int k=1; k<noig+1; k++){
				for (int l=1; l<nog+1; l++){
					if (fol[l][index[k]]==fol[l][index[k+1]]){
						fol[l][index[k+1]]=0;
						
					}
				}
			}
		
	}*/
	/*cout<<"Every guru's follower: ";
	cout<<endl;
	for (int l=1; l<nog+1; l++){
		for(int j=1; j<nog+1; j++){
			cout<<fol[l][j]<<" ";
		}
		cout << endl;
	}	
	cout << endl;-----------------------------------------------------------------------------------------------------------7*/
	
	int voters[nog+1];
	for(int a=1; a<nog+1; a++){
		voters[a]=a;
	}
	
	/*cout<<"Voters[a]:";
	cout<<endl;
	for (int a=1; a<nog+1; a++){
		cout<<voters[a]<<" ";
	}
	cout<<endl;------------------------------------------------------------------------------------------------------8*/
	
	//vriskei to size_del pou einai to megethos tou pinaka del
	//ousiastika vriskei autous pou anathetoun kapou ti psifo tous
	int size_del=0;
	for (int l=1; l<nog+1; l++){
		for (int j=1; j<nog+1; j++){
			if (fol[l][j]!=0){
				size_del++;
			}
		}
	}
	/*cout<<endl;
	cout<<"Size_del: "<<size_del;
	cout<<endl;
	cout<<endl;-------------------------------------------------------------------------------------------------------9*/
	
	int del[size_del];
	int t=1;
	for (int l=1; l<nog+1; l++){
		for (int j=1; j<nog+1; j++){
			if (fol[l][j]!=0){
				del[t]=fol[l][j];
				t++;
			}
		}
	}
	
	/*cout<<"Delegators[size_del]:";
	cout<<endl;
	for(int t=1; t<size_del+1; t++){
		cout<<del[t]<<" ";
	}
	cout<<endl;
	cout<<endl;-----------------------------------------------------------------------------------------------------10*/
	
	
	//diagrafw tis duplicates stis katagrafes twn delegators
	for (int x=1; x<size_del+1; x++){
		for (int y=x+1; y<size_del+1; y++){
			if (del[x]==del[y]){
				for (int z=y; z<size_del+1; z++){
					del[z]=del[z+1];
				}
				size_del--;
				y--;
			}
		}
	}
	/*cout<<"Delegators are:";
	cout<<endl;
	for (int x=1; x<size_del+1; x++){
		cout<<del[x]<<" ";
	}
	cout<<endl;
	cout<<endl;//-------------------------------------------------------------------------------------------------------------11*/
	
	
	
	//vriskei to megethos tou pinaka twn psifoforwn pou psifizoun amesa
	int size_dir=nog; //arxikopoiisi me to plithos twn psififirwn
	for(int t=1; t<size_del+1; t++){
		for(int a=1; a<nog+1; a++){
			if (voters[a]==del[t]){
				size_dir--;
				
			}
		}
	}
	
	/*cout<<"Size_dir: "<<size_dir;
	cout<<endl;
	cout<<endl;-------------------------------------------------------------------------------------------------------------12*/
	
	
	
	//vale ston dir[size_dir] tous voters pou psifizoun amesa
	int dir[size_dir]={0};
	
	bool contains = false;
	int w=0;
	
	for(int a=1; a<nog+1; a++){
		for (int t=1; t<size_del+1; t++){
			if (del[t] == voters[a]){
				contains = true;
				break;
			}
		}
		if (!contains){
			dir[w]=voters[a];
			++w;
		}
		else{
			contains = false;
		}
	}
	
	
	
	/*cout<<"Direct voters:";
	cout<<endl;
	for(int p=0; p<size_dir; p++){
		cout<<dir[p]<<" ";
	}
	cout<<endl;-------------------------------------------------------------------------------------------------------13*/
	
	
	
	
	
	
	
	//gia kathe guru kane t_a tou * tous followers tou
	//prosthese ta apotelesmata kai valta sto psif_del
	float psif_del=0;//sunoliki t_a apo deligators
	
	for(int k=0; k<noig; k++){
		for (int j=1; j<nog+1; j++){
			for (int l=1; l<nog+1; l++){
				if (index[k]==j){
					if (fol[l][j]!=0){
						psif_del=psif_del + S[k];
					}
				}
			}
		}
	}
	/*cout<<"psif_del: "<<psif_del;
	cout<<endl;
	cout<<endl;---------------------------------------------------------------------------------------------------14*/
	
	float f[nog+1]={0};
	for (int k=0; k<noig; k++){
		for (int b=1; b<nog+1; b++){
			if (b==index[k]){
				f[b]=S[k];
			}
		}
	}
	
	/* for (int b=1; b<nog+1; b++){
		cout<<f[b]<<" ";
	}*/
	
	//bgale 100 tuxaious missinformed
	
	int count=1;
	for (int m=1; m<missinformed+1; m++){
		for (int b=(rand() % nog) +1; ((b<nog+1) && (count<missinformed+1)); b++){
			if (f[b]==0){
				f[b]=4;
				b=(rand() % nog) +1;
				count++;
			}
		}
	}
	
	
	//bgale gia tous 100 missinformed t_a
	float Missr;
	for (int b=1; b<nog+1; b++){
		if (f[b]==4){
			unsigned seed = chrono::steady_clock::now().time_since_epoch().count(); 
    		default_random_engine e (seed); 
    		normal_distribution<double> distN(0.3,0.1);
    		Missr=distN(e);
    		f[b]=Missr;
		}
	}
	
	
	
	//bgale gia tous ypoloipous voters (pou einai average) t_a
	float Avgr;
	for (int b=1; b<nog+1; b++){
		if (f[b]==0){
			unsigned seed = chrono::steady_clock::now().time_since_epoch().count(); 
    		default_random_engine e (seed); 
    		normal_distribution<double> distN(0.5,0.1);
    		Avgr=distN(e);
    		f[b]=Avgr;
		}
	}
	
	
	/*cout<<"Accuracy values for every voter: ";
	for (int b=1; b<nog+1; b++){
		cout<<f[b]<<" ";
	
	}
	cout<<endl;
	cout<<endl;*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//OPTIMIZATION!_!_!_!_!_!_!_!-----------------------------
	//perase aytous pou psifizoun amesa me t_a <=4,5 kai valtous sto opt[iopt]
	int iopt=nog;
	int opt[iopt]={0};
	int o=0;
	for(int i=1; i<iopt+1; i++){
		for (int m=0; m<size_dir; m++){
			if ((f[i]<=0.45) && (i==dir[m])){
				opt[o]=i;
				o++;
			}
		}
	}
	
	/*cout<<"opt[iopt]: ";
	cout<<endl;
	for (int o=0; o<iopt; o++){
		cout<<opt[o]<<" ";
	}
	cout<<endl;*/
	
	
	//bgale ta midenika apo to opt[iopt] kai ftiakse kai to iopt analoga
	for(int i=0; i<iopt; i++){
		if (opt[i]==0){
			for (int j=i; j<(iopt-1); j++){
				opt[j]=opt[j+1];
			}
			i--;
			iopt--;
		}
	}
	
	for (int i=0; i<iopt; i++){
		for (int l=0; l<nog; l++){
			for (int j=0; j<nog; j++){
				if (array[opt[i]][j]==1){
					fol[opt[i]][j]=opt[i];
				}
			}
		}
	}
	
	
	/*cout<<"Accuracy values for every voter: ";
	for (int b=1; b<nog+1; b++){
		cout<<f[b]<<" ";
	
	}
	cout<<endl;
	
	cout<<"Every guru's follower: ";
	cout<<endl;
	for (int l=1; l<nog+1; l++){
		for(int j=1; j<nog+1; j++){
			cout<<fol[l][j]<<" ";
		}
		cout << endl;
	}*/
	
	
	//svise apo to dir[] auta poy vriskontai ston fol[][]
	for(int i=0; i<size_dir; i++){
		for(int l=1; l<nog+1; l++){
			for (int j=1; j<nog+1; j++){
				if (dir[i]==fol[l][j]){
					dir[i]=0;
				}
			}
		}
	}
	
	
	/*cout<<"Direct voters:";
	cout<<endl;
	for(int p=0; p<size_dir; p++){
		cout<<dir[p]<<" ";
	}
	cout<<endl;*/
	
	
	//bgale ta midenika apo to dir[size_dir] kai ftiakse kai to size_dir analoga
	for(int i=0; i<size_dir; i++){
		if (dir[i]==0){
			for (int j=i; j<(size_dir-1); j++){
				dir[j]=dir[j+1];
			}
			i--;
			size_dir--;
		}
	}
	/*cout<<"Direct voters:";
	cout<<endl;
	for(int p=0; p<size_dir; p++){
		cout<<dir[p]<<" ";
	}
	cout<<endl;*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	//vres synoliki t_a gia tous voters pou psifizoun amesa
	float psif_dir=0;
	for (int x=0; x<size_dir; x++){
		psif_dir=psif_dir + f[dir[x]];
	}
	
	
	
	
	//vres to optimal psif_del
	float opt_psif_del=0;
	
	for (int i=0; i<iopt; i++){//EDWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
		for (int j=1; j<nog+1; j++){
			if (fol[opt[i]][j]!=0){
				opt_psif_del=opt_psif_del + f[j];
			}
		}
			
	}
	
//	cout<<"psif_dir: "<<psif_dir;//------------------------------------------------------------------------------------------15*/
	//cout<<"opt_psif_del: "<<opt_psif_del;
	
	float mo=0;
	mo=(psif_del + psif_dir + opt_psif_del)/1000;
	
	cout<<endl;
	cout<<endl;
	cout<<"The OPTIMAL Average Accuracy Value with witch the truth is elected: ";
	cout<<mo;
	
	/*cout<<endl;
	cout<<endl;
	float blah=0;
	for(int i=0; i<nog; i++){
		blah=blah+f[i];
	}
	blah=blah/nog;
	cout<<"blah:"<<blah;*/
}



