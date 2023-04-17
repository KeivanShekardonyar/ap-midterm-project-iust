#include"cell.h"
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std ; 
class animal : private cell{
	private:
		vector <string> dna11;
		vector <string> dna22;
		int q;
	public :
		void display(){
            for(int i=0;i<dna11.size();i++){
                cout<<dna11[i]<<endl<<dna22[i]<<endl;
            }
        }
		animal(int n):cell(n){
			q=n;
		}
		void setanimal(cell d){
			int n=d.getdna().size();
			for(int i=0;i<n;i++){
				this->dna11.push_back(d.getdna()[i]);
			}
		}vector <string> getdna (){
            return dna11;
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
		
		
		double gSimularity(animal b){
			int count = 0 ;
			double persentage ;
			vector <string>  AlternateSTR ;
			if (this->getdna().size () >= b.getdna().size()){
				AlternateSTR = b.getdna() ;
				for(int i = 0 ; i < this->getdna().size() ; i++){
			     	for(int j = 0 ; j < AlternateSTR.size() ; j++){
					     if(this->getdna()[i] == AlternateSTR[j]){
						    count ++;
						    AlternateSTR[j] = " " ;
					    }
				    }
			    }
			     persentage = (count*100.0 / this->getdna().size() ) ;
			    
			}
			else {
				AlternateSTR = this->getdna() ;
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
		
		
		
		bool operator== (animal b){
			if (this->getdna().size() == b.getdna().size()){
				if (gSimularity(b) >= 70){
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
		
		
		animal AsexualReproduction (){
			cell  a(this->getdna().size());
			vector <string> child ;
			int start = this->getdna().size() * 0.7   ;
			int range = (this->getdna().size() - start)  ;
			int random	= start+1 + (rand() %range) ;
			for (int i = 0 ; i < random ; i++){
				child.push_back(this->getdna()[i]) ;
			}
			int rest = this->getdna().size() - random ;
			char Alphabet [4] = {'A', 'T' , 'C' , 'G' } ;
			for (int j = 0 ; j < rest ; j++){
				string Chromosome ;
				for (int i = 0 ; i<15 ; i ++){
					Chromosome+=" ";
			     	Chromosome[i]= Alphabet[rand() %4] ;
			    }
		     	child.push_back(Chromosome) ;
			}
			///for (int i = 0 ; i< child.size(); i ++ ){
			///	cout<<endl << child[i] ;
			///}
			a.setcell(child);
			animal b(1);
			b.setanimal(a);
			return b;
		}
		
		
		animal operator+ (animal b){
			if (this->getdna().size()%2 == 1 || b.getdna().size()%2 == 1){
				cout << "you can't do this function becouse the chromosome's number is individual";
			}
			else if(gSimularity(b) >= 70 && this->getdna().size() == b.getdna().size()) {
				animal nObject1 =  this->AsexualReproduction() ;
				animal nObject2 =  b.AsexualReproduction();
				vector < string > child ;
				int random = rand() %this->getdna().size() ;
				int j = random ;
				for (int i = 0 ; i<this->getdna().size()/2 ; i ++){
					
					if(j >= this->getdna().size()){
						j -= this->getdna().size();
					}
					child.push_back(this->getdna()[j]);
					child.push_back(b.getdna()[j]);
					j++ ;
					
					
				}
				cell c(child.size());
				c.setcell(child);
				animal z(1);
				z.setanimal(c);
				return z;
			}
			
		}void cell_death(){
			for(int i=0;i<dna11.size();i++){
                bool a=0;
                int b=0;
                for(int j=0;j<dna11[i].size();j++){
                    if(dna11[i][j]==dna22[i][j]){
                        b++;
                    }if(b==5){
                        dna11.erase(dna11.begin()+i);
                        dna22.erase(dna22.begin()+i);
                        a=1;
                        break;
                    }
                }if(a==0){
                    int t,c;
                    for(int k=0;k<dna11[i].size();k++){
                        if(dna11[i][k]=='C' || dna11[i][k]=='G'){
                            c++;
                        }else if(dna11[i][k]=='A' || dna11[i][k]=='T'){
                            t++;
                        }c*=3;
                        if(t>c){
                            dna11.erase(dna11.begin()+i);
                            dna22.erase(dna22.begin()+i);
                        }
                    }
                }
            }
		}
};

int main(){
	return 0 ;
}
