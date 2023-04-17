#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<algorithm>
#pragma once
using namespace std;

int naive_algo(string text , string pattern)
	{
		int n = text.length();
		int m = pattern.length();
		for (int i=0 ; i<=n-m ; i++)
			{
				int j=0;
				for (j ; j<m ; j++)
					{
						if (text[i+j] != pattern[j])
							break;
					}
				if (j == m)
					return i;
			}
		return -1;
	}

class genome{
    private:
        string rna;
        string dna[2]; 
    public:
		genome(){}
		genome(string a,string b,string c)
			{
				rna=a;
				dna[0]=b;
				dna[1]=c;
			}
        void setrna(string a){
            rna=a;
        }void setdna(string a){
            dna[0]=a;
            dna[1]=a;
            int b=a.size(); ///DNA length
            for(int i=0;i<b;i++){
                if(a[i]=='A'){
                    dna[1][i]='T';
                }else if(a[i]=='T'){
                    dna[1][i]='A';
                }else if(a[i]=='C'){
                    dna[1][i]='G';
                }else if(a[i]=='G'){
                    dna[1][i]='C';
                }
            }
        }void dnafromrna(){
            string d=rna;
            int b=rna.size(); ///RNA length
            for(int i=0;i<b;i++){
                if(rna[i]=='A'){
                    d[i]='T';
                }else if(rna[i]=='T'){
                    d[i]='A';
                }else if(rna[i]=='C'){
                    d[i]='G';
                }else if(rna[i]=='G'){
                    d[i]='C';
                }
            }cout<<d<<endl;
        }void small_mutation(char a,char b,int x){
            int y=rna.size();
            int f=x;
            for(int i=0;i<y && x>0;i++){
                if(rna[i]==a){
                    rna[i]=b;
                    x--;
                }
            }
            int e=dna[0].size();
            char c;
            if(a=='A'){
                c='T';
            }else if(a=='T'){
                c='A';
            }else if(a=='C'){
                c='G';
            }else if(a=='G'){
                c='C';
            }char d;
            if(b=='A'){
                d='T';
            }else if(b=='T'){
                d='A';
            }else if(b=='C'){
                d='G';
            }else if(b=='G'){
                d='C';
            }
            for(int i=0;i<e && f>0;i++){
                if(dna[0][i]==a){
                    dna[0][i]=b;
                    dna[1][i]=d;
                    f--;
                }else if(dna[0][i]==c){
                    dna[0][i]=d;
                    dna[1][i]=b;
                    f--;
                }
            }
        }void big_mutation(string s1,string s2){
            int t1 = naive_algo(rna,s1);
			int t2 = naive_algo(dna[0],s1);
			int t3 = naive_algo(dna[1],s1);
			int m = s1.length();
			if (t1!=-1)
				rna.replace(t1,m,s2);
			if (t2!=-1 && t3!=-1)
				{
					if (t2 <= t3)
						{
							dna[0].replace(t2,m,s2);
							setdna(dna[0]);
						}
					else
						{
							string temp;
							dna[1].replace(t3,m,s2);
							setdna(dna[1]);
							temp = dna[1];
							dna[1] = dna[0];
							dna[0] = temp;
						}
				}
			else if (t2!=-1)
				{
					dna[0].replace(t2,m,s2);
					setdna(dna[0]);
				}
			else if (t1!=-1)
				{
					string temp;
					dna[1].replace(t3,m,s2);
					setdna(dna[1]);
					temp = dna[1];
					dna[1] = dna[0];
					dna[0] = temp;
				}

        }
		void reverse_mutation(string s2){
        string s1 = s2;
        reverse(s2.begin() , s2.end());
    	big_mutation(s1,s2);
		}void getrna(){
            cout<<rna<<endl;
        }string getdna1(){
            return dna[0];
        }string getdna2(){
            return dna[1];
        }void display(){
            getrna();
            cout<<getdna1()<<endl<<getdna2()<<endl;
        }
};
class cell : private genome{
    private:
        vector<string> dna1;
        vector<string> dna2;
        int chromosome_count; 
    public:
        void display(){
            for(int i=0;i<chromosome_count;i++){
                cout<<dna1[i]<<endl<<dna2[i]<<endl;
            }
        }
        cell(int n){
            chromosome_count=n;
        }void setcell(vector <string> s){
            for(int i=0;i<chromosome_count;i++){
                genome g;
                string s1;
                s1=s[i];
                g.setdna(s1);
                dna1.push_back(g.getdna1());
                dna2.push_back(g.getdna2());
            }
        }
        vector <string> getdna (){
            return dna1;
        }
        void cell_death(){
            for(int i=0;i<dna1.size();i++){
                bool a=0;
                int b=0;
                for(int j=0;j<dna1[i].size();j++){
                    if(dna1[i][j]==dna2[i][j]){
                        b++;
                    }if(b==5){
                        ///dna1.erase(dna1.begin()+i);
                        ///dna2.erase(dna2.begin()+i);
                        delete this;
                        a=1;
                        break;
                    }
                }if(a==0){
                    int t,c;
                    for(int k=0;k<dna1[i].size();k++){
                        if(dna1[i][k]=='C' || dna1[i][k]=='G'){
                            c++;
                        }else if(dna1[i][k]=='A' || dna1[i][k]=='T'){
                            t++;
                        }c*=3;
                        if(t>c){
                            ///dna1.erase(dna1.begin()+i);
                            ///dna2.erase(dna2.begin()+i);
                            delete this;
                        }
                    }
                }
            }
        }void big_mutation(string s1,int n,string s2,int m){
			int t1 = naive_algo(dna1[n],s1);
			int t2 = naive_algo(dna2[m],s2);
			if(t1!=-1 && t2!=-1){
			genome a1{"",dna1[n],dna2[n]};
			genome a2{"",dna1[m],dna2[m]};
			a1.big_mutation(s1,s2);
			a2.big_mutation(s2,s1);
			dna1[n]=a1.getdna1();
			dna2[n]=a1.getdna2();
			dna1[m]=a2.getdna1();
			dna2[m]=a2.getdna2(); 
			}
        }void reverse_mutation(string s,int n){
			genome a1{"",dna1[n],dna2[n]};
			a1.reverse_mutation(s);
			dna1[n]=a1.getdna1();
			dna2[n]=a1.getdna2();
        }
        
        
        
        void small_mutation(char c1 , char c2 , int n , int m ){
        	int counter = 1 ;
        	for (int i = 0 ; i<dna1[m].length() ; i++){
        		if(counter > n){
        			break ;
				}
        		if(dna1[m].at(i) == c1){
        			dna1[m].at(i) = c2 ;
        			switch(c2){
        				case 'A' :
        				    dna2[m].at(i) = 'T' ;	
        				    break ;
        				case 'T' :
        					dna2[m].at(i) = 'A' ;
        					break ;
        				case 'C' :
						    dna2[m].at(i) = 'G' ;
							break ;
						case 'G' :
						    dna2[m].at(i) = 'C' ;		
					}
        			
        			counter++ ;
				}
			}
			///cout << dna1[m] << endl << dna2[m] << endl;
		}
		
		
		
		void BasicPalindrome(int n){
			int a=dna1[n].size();
            string s;
            for(int i=2;i<=a+1;i+=2){
                for(int j=0;j<a;j++){
                    string s="";
                    bool w=1;
                    for(int z=0;z<i;z++){
                        s+=" ";
                        s[z]=dna1[n][j+z];
                    }for(int v=0;v<i/2;v++){
                        if(s[v]!=s[i-v-1]){
                            w=0;
                        }
                    }if(w){
                        cout<<s<<endl;
                    }
                }
            }
		}
};






//int main(){
//    cell c(2);
//    vector <string> v{"TTTTAAAA","CCCCGGGG"};
//	genome a;
	// c.setcell(v);
	// c.display();
	// c.big_mutation("TTT",0,"CC",1);
	// c.reverse_mutation("CCCGGG",1);
	// c.display();
	// a.setrna("TTTAA");
	// a.setdna("TTTAA");
	// a.reverse_mutation("TA");
	// a.display();
	// a.big_mutation("TT","CGGGG");
	// a.display();
    // v.push_back("CCCCAAAA");
    // c.setcell(v);
    // c.BasicPalindrome(0);
//   genome g;
//   g.setdna("TATAATATATTTTC");
//   g.setrna("TATGAA");
//    cell c(g) ;
//    animal a;
//    c.SmallMutation('A','C', 3 , 0);
//    c.BasicPalindrome(g.getdna1() , g.getdna2()) ;
//    vector <string> s1 ;
//    s1.push_back("TTTTTTTTTTT") ;
//    s1.push_back("AAAAAAAAAA") ;
//    s1.push_back("WWWWWWWWWW") ;
//    s1.push_back("EEEEEEEEEE");
//    s1.push_back("HGSHGSHDSHDG");
//    s1.push_back("ystdsydgshdgshjdg");
//    vector <string> s2  ;
//    s2.push_back("TTTTTTTTTTT") ;
//    s2.push_back("AAAAAAAAAA") ;
//    s2.push_back("WWWWWWWWWW") ;
//    s2.push_back("EEEEEEEEEz");
//    s2.push_back("HGSHGSHDSHDG");
//    s2.push_back("ystdsydgshdgshjdg");
//    cout << endl << a.GSimularity("TTTTTTTCGGGT" , "TTTCTTTTTTCG") ;
//    a.gSimularity(s1 , s2);
//    cout << a.species(s1 ,s2 );
//    a.AsexualReproduction(s1);
//    a.SextualReproduction(s1 , s2);
//    return 0 ;
//}
