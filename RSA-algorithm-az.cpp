#include<iostream>
#include<cmath>
using namespace std;
int ebob(int a,int b){
	
	int temp;
	while(1){
		temp=a%b;
		if(temp==0) return b;
		
		a=b;
		b=temp;
		
	}
	
}

int e_hesabla(int fn){
	
	for(int e=2 ; e<fn ; e++){
		if(ebob(e,fn)==1) return e;
	}
	
}

int d_hesabla(int e,int fn){
	
    int k=1;
    
    while(true){
        
        k+=fn;
        
        if(k%e==0) return k/e; //return d
    }
	
}

int sifrele(int ch,int e,int n){
	
	int netice=1,simvol=ch-97;
	
	for(int i=0 ; i<e ; i++){
		netice*=simvol;
		netice%=n;
	}
	
	return netice;
}

int desifrele(int ch,int d,int n){
	
	int netice=1;
	
	for(int i=0 ; i<d ; i++){
		netice*=ch;
		netice%=n;
	}
	
	return netice+97;
	
	
}

int main(){
	
	string setir;
	
	int sifrelenmish[100]={0};
	int desifrelenmish[100]={0};
	
	int sade1=97,sade2=11;
	
	cout<<"Varianta uygun sade ededler: p = "<<sade1<<" p = "<<sade2<<endl<<endl;;
	
	int n=sade1*sade2;
	int fn=(sade1-1)*(sade2-1);
	
	cout<<"Sade ededlerden alinmish uygun olaraq n ve f(n) ededi : "<<n<<" "<<fn<<endl<<endl;
	
	int e=e_hesabla(fn);
	
	cout<<"Hesablanmish e ededi: "<<e<<endl<<endl;
	
	int d=d_hesabla(e,fn);
	
	cout<<"Hesablanmish d ededi: "<<d<<endl<<endl;
	
	cout<<"Aciq acar : ("<<n<<","<<e<<")"<<endl<<endl;
	cout<<"Mexfi acar : ("<<n<<","<<d<<")"<<endl<<endl;
	
	cout<<"Sifrelenecek setri daxil edin: ";
	
	getline(cin,setir);
	
	for(int i=0 ; i<setir.length() ; i++){
		sifrelenmish[i]=sifrele(setir[i],e,n);
	}
	
	cout<<endl<<"Sifrelenmish metn: ";
	
	for(int i=0 ; i<setir.length() ; i++) cout<<(char)sifrelenmish[i];
	
	cout<<endl<<endl<<"Desifrelenmish metn: ";
	
	for(int i=0 ; i<setir.length() ; i++){
		desifrelenmish[i]=desifrele(sifrelenmish[i],d,n);
	}
	
	for(int i=0 ; i<setir.length() ; i++) cout<<(char)desifrelenmish[i];
	
	
	return 0;
}
