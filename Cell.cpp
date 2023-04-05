#include<iostream>
#include<string>
#include<vector>
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
        }void big_mutation(string s1,string s2){
            int a=rna.size();
            int b=s1.size();
            int c=s2.size();
            string t1,t2,t3;
            bool w,v=0;
            int i,jj=0;
            while(i<a && w==0){
                t2="";
                for(int j=0;j<b;j++){
                    t2+=" ";
                    t2[j]=rna[i+j];
                }if(t2==s1){
                    t2=s2;
                    for(int k=0;k<a-i-b;k++){
                        t3+=" ";
                        t3[k]=rna[k+i+b];
                    }rna=t1+t2+t3;
                    w=1;
                }
                t1+=" ";
                t1[i]=rna[i];
                i++;
            }int x=dna[0].size();
            string r1,r2,r3,d1,d2,d3;
            string s3;
            for(int ii=0;ii<c;ii++){
                if(s2[ii]=='A'){
                    s3+=" ";
                    s3[ii]='T';
                }else if(s2[ii]=='T'){
                    s3+=" ";
                    s3[ii]='A';
                }else if(s2[ii]=='C'){
                    s3+=" ";
                    s3[ii]='G';
                }else if(s2[ii]=='G'){
                    s3+=" ";
                    s3[ii]='C';
                }
            }
            while(jj<x && v==0){
                r2="";
                d2="";
                for(int kk=0;kk<b;kk++){
                    r2+=" ";
                    r2[kk]=dna[0][kk+jj];
                    d2+=" ";
                    d2[kk]=dna[1][kk+jj];
                }if(r2==s1){
                    r2=s2;
                    d2=s3;
                    for(int l=0;l<x-b-jj;l++){
                        r3+=" ";
                        r3[l]=dna[0][l+b+jj];
                        d3+=" ";
                        d3[l]=dna[1][l+b+jj];
                    }dna[0]=r1+r2+r3;
                    dna[1]=d1+d2+d3;
                    v=1;
                }else if(d2==s1){
                    d2=s2;
                    r2=s3;
                    for(int l=0;l<x-b-jj;l++){
                        r3+=" ";
                        r3[l]=dna[0][l+b+jj];
                        d3+=" ";
                        d3[l]=dna[1][l+b+jj];
                    }dna[0]=r1+r2+r3;
                    dna[1]=d1+d2+d3;
                    v=1;        
                }r1+=" ";
                r1[jj]=dna[0][jj];
                d1+=" ";
                d1[jj]=dna[1][jj];
                jj++;
            }
        }void reverse_mutation(string s1){
            string s3,t1,t2,t3,r1,r2,r3,d1,d2,d3;
            int c=s1.size();
            int a=rna.size();
            int b=dna[0].size();
            bool w,v=0;
            for(int i=0;i<c;i++){
                if(s1[i]=='A'){
                    s3+=" ";
                    s3[i]='T';
                }else if(s1[i]=='T'){
                    s3+=" ";
                    s3[i]='A';
                }else if(s1[i]=='C'){
                    s3+=" ";
                    s3[i]='G';
                }else if(s1[i]=='G'){
                    s3+=" ";
                    s3[i]='C';
                }
            }int j,k=0;
            while(j<a && w==0){
                t2="";
                for(int j0=0;j0<c;j0++){
                    t2+=" ";
                    t2[j0]=rna[j0+j];
                }if(t2==s1){
                    t2=s3;
                    for(int j1=0;j1<a-j-c;j1++){
                        t3+=" ";
                        t3[j1]=rna[j1+j+c];
                    }rna=t1+t2+t3;
                    w=1;
                }t1+=" ";
                t1[j]=rna[j];
                j++;
            }while(k<b && v==0){
                r2="";
                d2="";
                for(int k0=0;k0<c;k0++){
                    r2+=" ";
                    r2[k0]=dna[0][k0+k];
                    d2+=" ";
                    d2[k0]=dna[1][k0+k];
                }if(r2==s1){
                    r2=s3;
                    d2=s1;
                    for(int k1=0;k1<b-c-k;k1++){
                        r3+=" ";
                        r3[k1]=dna[0][k1+c+k];
                        d3+=" ";
                        d3[k1]=dna[1][k1+c+k];
                    }dna[0]=r1+r2+r3;
                    dna[1]=d1+d2+d3;
                    v=1;
                }else if(d2==s1){
                    d2=s3;
                    r2=s1;
                    for(int k1=0;k1<b-c-k;k1++){
                        r3+=" ";
                        r3[k1]=dna[0][k1+c+k];
                        d3+=" ";
                        d3[k1]=dna[1][k1+c+k];
                    }dna[0]=r1+r2+r3;
                    dna[1]=d1+d2+d3;
                    v=1;
                }r1+=" ";
                r1[k]=dna[0][k];
                d1+=" ";
                d1[k]=dna[1][k];
                k++;
            }
        }void getrna(){
            cout<<rna<<endl;
        }string getdna1(){
            return dna[0];
        }string getdna2(){
            return dna[1];
        }
};
class cell : private genome{
    private:
        vector<string> dna1;
        vector<string> dna2;
    public:
        cell(genome g){
            dna1.push_back(g.getdna1());
            dna2.push_back(g.getdna2());
        }void cell_death(){
            for(int i=0;i<dna1.size();i++){
                bool a=0;
                int b=0;
                for(int j=0;j<dna1[i].size();j++){
                    if(dna1[i][j]==dna2[i][j]){
                        b++;
                    }if(b==5){
                        dna1.erase(dna1.begin()+i);
                        dna2.erase(dna2.begin()+i);
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
                            dna1.erase(dna1.begin()+i);
                            dna2.erase(dna2.begin()+i);
                        }
                    }
                }
            }
        }void big_mutation(string s1,int n,string s2,int m){
            int a1=dna1[n].size();
            int a2=dna1[m].size();
            int c1=s1.size();
            int c2=s2.size();
            bool w,v=0;
            int i1,i2=0;
            string t1,t2,t3,r1,r2,r3,d1,d2,d3,f1,f2,f3,s3,s4;
            for(int i=0;i<c1;i++){
                if(s1[i]=='A'){
                    s3+=" ";
                    s3[i]='T';
                }else if(s1[i]=='T'){
                    s3+=" ";
                    s3[i]='A';
                }else if(s1[i]=='C'){
                    s3+=" ";
                    s3[i]='G';
                }else if(s1[i]=='G'){
                    s3+=" ";
                    s3[i]='C';
                }
            }for(int i=0;i<c2;i++){
                if(s2[i]=='A'){
                    s4+=" ";
                    s4[i]='T';
                }else if(s2[i]=='T'){
                    s4+=" ";
                    s4[i]='A';
                }else if(s2[i]=='C'){
                    s4+=" ";
                    s4[i]='G';
                }else if(s2[i]=='G'){
                    s4+=" ";
                    s4[i]='C';
                }
            }
            while(i1<a1 && w==0){
                t2="";
                r2="";
                for(int j1=0;j1<c1;j1++){
                    t2+=" ";
                    t2[j1]=dna1[n][j1+i1];
                    r2+=" ";
                    r2[j1]=dna2[n][j1+i1];
                }if(t2==s1){
                    t2=s2;
                    r2=s4;
                    for(int k1=0;k1<a1-i1-c1;k1++){
                        t3+=" ";
                        t3[k1]=dna1[n][k1+i1+c1];
                        r3+=" ";
                        r3[k1]=dna2[n][k1+i1+c1];
                    }w=1;
                    dna1[n]=t1+t2+t3;
                    dna2[n]=r1+r2+r3;
                }else if(r2==s1){
                    r2=s2;
                    t2=s4;
                    for(int k1=0;k1<a1-i1-c1;k1++){
                        t3+=" ";
                        t3[k1]=dna1[n][k1+i1+c1];
                        r3+=" ";
                        r3[k1]=dna2[n][k1+i1+c1];
                    }w=1;
                    dna1[n]=t1+t2+t3;
                    dna2[n]=r1+r2+r3;
                }
                t1+=" ";
                t1[i1]=dna1[n][i1];
                r1+=" ";
                r1[i1]=dna2[n][i1];
                i1++;
            }while(i2<a2 && v==0){
                d2="";
                f2="";
                for(int j2=0;j2<c2;j2++){
                    d2+=" ";
                    d2[j2]=dna2[m][j2+i2];
                    f2+=" ";
                    f2[j2]=dna2[m][j2+i2];
                }if(d2==s2){
                    d2=s1;
                    f2=s3;
                    for(int k2=0;k2<a2-i2-c2;k2++){
                        d3+=" ";
                        d3[k2]=dna1[m][k2+i1+c1];
                        f3+=" ";
                        f3[k2]=dna2[m][k2+i1+c1];
                    }v=1;
                    dna1[m]=d1+d2+d3;
                    dna2[m]=f1+f2+f3;
                }else if(f2==s2){
                    f2=s1;
                    d2=s3;
                    for(int k2=0;k2<a2-i2-c2;k2++){
                        d3+=" ";
                        d3[k2]=dna1[m][k2+i1+c1];
                        f3+=" ";
                        f3[k2]=dna2[m][k2+i1+c1];
                    }v=1;
                    dna1[m]=d1+d2+d3;
                    dna2[m]=f1+f2+f3;
                }
                d1+=" ";
                d1[i2]=dna1[m][i2];
                f1+=" ";
                f1[i2]=dna2[m][i2];
                i2++;
            }
        }void reverse_mutation(string s,int n){
            string s1,r1,r2,r3,t1,t2,t3;
            int a=dna1[n].size();
            int c=s.size();
            bool w=0;
            for(int p=0;p<c;p++){
                if(s[p]=='A'){
                    s1+=" ";
                    s1[p]='T';
                }else if(s[p]=='T'){
                    s1+=" ";
                    s1[p]='A';
                }else if(s[p]=='C'){
                    s1+=" ";
                    s1[p]='G';
                }else if(s1[p]=='G'){
                    s1+=" ";
                    s1[p]='C';
                }
            }int i=0;
            while(i<a && w==0){
                r2="";
                t2="";
                for(int j=0;j<c;j++){
                    t2+=" ";
                    t2[j]=dna1[n][j+i];
                    r2+=" ";
                    r2[j]=dna2[n][j+i];
                }if(t2==s){
                    t2=s1;
                    r2=s;
                    for(int k=0;k<a-i-c;k++){
                        t3+=" ";
                        t3[k]=dna1[n][k+i+c];
                        r3+=" ";
                        r3[k]=dna2[n][k+i+c];
                    }w=1;
                    dna1[n]=t1+t2+t3;
                    dna2[n]=r1+r2+r3;
                }t1+=" ";
                t1[i]=dna1[n][i];
                r1+=" ";
                r1[i]=dna2[n][i];
                i++;
            }
        }
};
int main(){
    genome g;
    g.setdna("TATGGA");
    g.setrna("TATGAA");
    g.reverse_mutation("TG");
}
