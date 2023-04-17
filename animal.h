#include"cell.h"
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std ;

class animal: private cell{
	private:
		cell c;
	public :
		void setanimal(cell d){
			c=d;
		}
		double GSimularity (string str1 , string str2){
			if(str1.length() == str2.length()){
				for(int i = str1.length() ; i>1 ; i--){
					cout << i << endl ;
					for(int j = 0 ; j<= str1.length()-i ; j++){
						string strN1 ;
						for(int k = j ; k< i ; k++){
							strN1 += str1.at(k) ;
							
						}
						cout << strN1 << endl ;
						for(int z = 0 ; z<= str1.length()-i ; z++ ){
							    string strN2 ;
							    
						     	for(int t = z ; t < i ; t++){
								    strN2 += str2.at(t);   
							    }
							    cout << strN2 << endl  ;
							    if(strN1 == strN2){
								    	return (i*100.0/(str1.length()) ) ;
									}
						    }
						
					}
				}
			}
		}
		
		
		double gSimularity(cell a , cell b){
			int count = 0 ;
			double persentage ;
			vector <string>  AlternateSTR ;
			if (a.getdna().size () >= b.getdna().size()){
				AlternateSTR = b.getdna() ;
				for(int i = 0 ; i < a.getdna().size() ; i++){
			     	for(int j = 0 ; j < AlternateSTR.size() ; j++){
					     if(a.getdna()[i] == AlternateSTR[j]){
						    count ++;
						    AlternateSTR[j] = " " ;
					    }
				    }
			    }
			     persentage = (count*100.0 / a.getdna().size() ) ;
			    
			}
			else {
				AlternateSTR = a.getdna() ;
				for(int i = 0 ; i < b.getdna().size() ; i++){
			     	for(int j = 0 ; j < AlternateSTR.size() ; j++){
					     if(b.getdna()[i] == AlternateSTR[j]){
						    count ++;
						    AlternateSTR[j] = " " ;
					    }
				    }
			    }
			     persentage = (count*100.0 / b.getdna().size() ) ;
			    
			}
			return persentage ;
			
		}
		
		
		
		bool operator== (cell a , cell b){
			if (a.getdna().size() == b.getdna().size()){
				if (gSimularity(a.dna1 , b.dna2) >= 70){
					return true ;
				}
				else {
					return false ;
				}
			}
			else {
				return false ;
			}
		}
		
		
		vector <string> AsexualReproduction (cell a ){
			vector <string> child ;
			int start = a.getdna().size() * 0.7   ;
			int range = (a.getdna().size() - start)  ;
			int random	= start+1 + (rand() %range) ;
			for (int i = 0 ; i < random ; i++){
				child.push_back(a.getdna()[i]) ;
			}
			int rest = a.getdna().size() - random ;
			char Alphabet [4] = {'A', 'T' , 'C' , 'G' } ;
			for (int j = 0 ; j < rest ; j++){
				string Chromosome ;
				for (int i = 0 ; i<15 ; i ++){
			     	Chromosome += Alphabet[rand() %4] ;
			    }
		     	child.push_back(Chromosome) ;
			}
			///for (int i = 0 ; i< child.size(); i ++ ){
			///	cout<<endl << child[i] ;
			///}
			return child ;
		}
		
		
		void operator+ (cell a , cell b){
			if (a.getdna1().size()%2 == 1 || b.getdna1().size()%2 == 1){
				cout << "you can't do this function becouse the chromosome's number is individual";
			}
			else {
				vector <string> nObject1 =  AsexualReproduction(str1) ;
				vector <string> nObject2 =  AsexualReproduction(str2);
				vector < string > child ;
				int random = rand() %a.getdna1().size() ;
				int j = random ;
				for (int i = 0 ; i<a.getdna1().size()/2 ; i ++){
					
					if(j >= a.getdna1().size()){
						j -= a.getdna1().size();
					}
					child.push_back(a.getdna1()[j]);
					child.push_back(b.getdna1()[j]);
					j++ ;
					
					
				}
				for (int i = 0 ; i < child.size() ; i++){
					cout << endl << child[i];
				}
			}
			
		}
};

int main(){
	animal a ;
	return 0 ;
}
