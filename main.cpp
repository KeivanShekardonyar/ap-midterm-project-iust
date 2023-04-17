#include<iostream>
#include"cell.h"
#include"animal.h"
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;
int main(){
    int n0,n1,n2,n3,n4;
    string s0,s1,s2,s3;
    char c0,c1;
    while(n0!=-1){
        cout<<"what do you want do create?"<<endl<<"genome: 1"<<endl<<"cell: 2"<<endl<<"animal: 3"<<endl<<"exit: -1"<<endl<<"enter a number"<<endl;
        cin>>n0;
        cout<<endl;
        if(n0==1){
            genome g;
            cout<<"enter a rna:"<<endl;
            cin>>s0;
            cout<<endl;
            cout<<"enter a dna:"<<endl;
            cin>>s1;
            cout<<endl;
            g.setdna(s1);
            g.setrna(s0);
            g.display();
            cout<<"what do you want to do to the genome?"<<endl<<"create dna from rna: 1"<<endl<<"small mutation: 2"<<endl<<"big mutation: 3"<<endl<<"reverse mutation: 4"<<endl;
            cin>>n1;
            cout<<endl;
            if(n1==1){
                g.dnafromrna();
            }else if(n1==2){
                cout<<"enter the first char"<<endl;
                cin>>c0;
                cout<<"enter the second char"<<endl;
                cin>>c1;
                cout<<"enter the number of replacements"<<endl;
                cin>>n2;
                g.small_mutation(c0,c1,n2);
                g.display();
            }else if(n1==3){
                cout<<"enter the first string"<<endl;
                cin>>s2;
                cout<<"enter the second string"<<endl;
                cin>>s3;
                g.big_mutation(s2,s3);
                g.display();
            }else if(n1==4){
                cout<<"enter the string"<<endl;
                cin>>s2;
                g.reverse_mutation(s2);
                g.display();
            }
        }else if(n0==2){
            cout<<"enter the number of genomes"<<endl;
            cin>>n3;
            cell c(n3);
            vector <string> a0;
            for(int i=0;i<n3;i++){
                //cout<<"enter a rna:"<<endl;
                //cin>>s0;
                //cout<<endl;
                cout<<"enter a dna:"<<endl;
                cin>>s1;
                cout<<endl;
                a0.push_back(s1);
            }c.setcell(a0);
            cout<<"what do you want to do to the cell?"<<endl<<"palindrom: 1"<<endl<<"small mutation: 2"<<endl<<"big mutation: 3"<<endl<<"reverse mutation: 4"<<endl<<"dead cell: 5"<<endl;
            cin>>n1;
            cout<<endl;
            if(n1==1){
                cout<<"which index?"<<endl;
                cin>>n4;
                cout<<endl;
                c.BasicPalindrome(n4);
            }else if(n1==2){
                cout<<"enter the first char"<<endl;
                cin>>c0;
                cout<<"enter the second char"<<endl;
                cin>>c1;
                cout<<"enter the number of replacements"<<endl;
                cin>>n2;
                cout<<"enter the number of chromosome"<<endl;
                cin>>n4;
                c.small_mutation(c0,c1,n2,n4);
                c.display();
            }else if(n1==3){
                cout<<"enter the first string"<<endl;
                cin>>s2;
                cout<<"enter the second string"<<endl;
                cin>>s3;
                cout<<"enter the number of the first chromosome"<<endl;
                cin>>n2;
                cout<<"enter the number of the second chromosome"<<endl;
                cin>>n4;
                c.big_mutation(s2,n2,s3,n4);
                c.display();
            }else if(n1==4){
                cout<<"enter the string"<<endl;
                cin>>s2;
                cout<<"enter the number of the chromosome"<<endl;
                cin>>n2;
                c.reverse_mutation(s2,n2);
                c.display();
            }else if(n1==5){
                c.cell_death();
            }            
        }else if(n0==3){
            cout<<"enter the number of genomes"<<endl;
            cin>>n3;
            cell c(n3);
            vector <string> a0;
            for(int i=0;i<n3;i++){
                //cout<<"enter a rna:"<<endl;
                //cin>>s0;
                //cout<<endl;
                cout<<"enter a dna:"<<endl;
                cin>>s1;
                cout<<endl;
                a0.push_back(s1);
            }c.setcell(a0);
            animal z(1);
            z.setanimal(c);
            cout<<"what do you want to do to the animal?"<<endl<<"sexual reproduction: 1"<<endl<<"simularity: 2"<<endl<<"smae species: 3"<<endl<<"AsexualReproduction: 4"<<endl<<"dead cell: 5"<<endl;
            cin>>n1;
            cout<<endl;
            if(n1==1){
                cout<<"enter the number of the second animal's genomes"<<endl;
                cin>>n2;
                cell d(n2);
                vector <string> a1;
                for(int i=0;i<n2;i++){
                    cout<<"enter a dna:"<<endl;
                    cin>>s1;
                    cout<<endl;
                    a1.push_back(s1);
                }d.setcell(a1);
                animal y(1);
                y.setanimal(d);
                animal x(1);
                x=z+y;
                x.display();
            }else if(n1==2){
                cout<<"enter the number of the second animal's genomes"<<endl;
                cin>>n2;
                cell d(n2);
                vector <string> a1;
                for(int i=0;i<n2;i++){
                    cout<<"enter a dna:"<<endl;
                    cin>>s1;
                    cout<<endl;
                    a1.push_back(s1);
                }d.setcell(a1);
                animal y(1);
                y.setanimal(d);
                cout<<z.gSimularity(y)<<endl;
            }else if(n1==3){
                cout<<"enter the number of the second animal's genomes"<<endl;
                cin>>n2;
                cell d(n2);
                vector <string> a1;
                for(int i=0;i<n2;i++){
                    cout<<"enter a dna:"<<endl;
                    cin>>s1;
                    cout<<endl;
                    a1.push_back(s1);
                }d.setcell(a1);
                animal y(1);
                y.setanimal(d);
                if(z==y){
                    cout<<"yes"<<endl;
                }else{
                    cout<<"no"<<endl;
                }
            }else if(n1==4){
                z.AsexualReproduction().display();
            }else if(n1==5){
                z.cell_death();
                z.display();
            }
        }
    }
}
