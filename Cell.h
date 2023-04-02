#include<iostream>
#include<string>
using namespace std;
class genome{
    private:
        string rna;
        string dna[2]; 
    public:
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
        }string dnafromrna(){
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
        }
};
