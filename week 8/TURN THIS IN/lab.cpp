#include<iostream>
#include<cstdlib>

using namespace std;

class SERVER{
private:
	int serverNo;
	int sevicingTime;
	bool serviceOn;
	int totalWaitForService;
	int totalService;
public:
	SERVER(){serviceOn=false;sevicingTime=10;totalWaitForService=0;totalService=0;}
	SERVER(int c){serverNo=c;SERVER();}
	int getServerNo(){return(serverNo);}
	int getservicingTime(){return(sevicingTime);}
	void setTotalWaitForService(int s){totalWaitForService+=s;}
	void setTotalService(){totalService+=10;}
	int getTotalService(){return(totalService);}
	int getTotalWaitForService(){return(totalWaitForService);}
	void setServiceOn(bool s){serviceOn=s;}
	bool getServiceOn(){return(serviceOn);}
};

class CUSTOMER{
private:
	int arraivingTime;
	int serviceTime;
	int type;
	CUSTOMER *next;
public:
	CUSTOMER(){
	arraivingTime=0;
	serviceTime=0;
	type=0;
	next=NULL;
	}
	void setArraive(int s){arraivingTime=s;}
	void setService(int s){serviceTime=s;}
	void setType(int t){type=t;}
	int getType(){return(type);}
	int getArraive(){return(arraivingTime);}
	int getService(){return(serviceTime);}
	void setNext(CUSTOMER *s){next=s;}
	CUSTOMER* getNext(){return(next);}
};


class Line{
private:
CUSTOMER **start;
CUSTOMER **last;
int number;
public:
	Line(){}
	void initial(int c){
		number=c;
		start=new CUSTOMER*[c];last=new CUSTOMER*[c];
		for(int i=0;i<c;i++){
			start[i]=NULL;last[i]=NULL;
		}

	}
	void add(CUSTOMER *c,int p){
		if(start[p]==NULL){
		start[p]=c;
		last[p]=c;
		//cout<<"A";
		}
		else{
			if(start[p]==last[p]){
				start[p]->setNext(c);
				last[p]=last[p]->getNext();
				last[p]=c;
				//cout<<"B";
			}
			else{
			last[p]->setNext(c);
			last[p]=c;
			last[p]->setNext(NULL);
			//cout<<"C";
			}
		}
	}
	CUSTOMER* top(int p){
		return(start[p]);
	}
	void clearTop(int p){
		start[p]=start[p]->getNext();
	}

	int length(int p){
		CUSTOMER *tmp;
		tmp=start[p];
		int count=0;
		while(tmp){
			count++;
			tmp=tmp->getNext();
		}
		return(count);
	}
	bool isFree(){
	bool tm=true;
	for(int a=0;a<number;a++){
		if(length(a)>0){tm=false;break;}
	}
	return(tm);
	}
};

class CUSTOMERS{
private:
	int time;
	int *eachTime;
	SERVER *s;
	Line l;
	int no;
public:
	CUSTOMERS(){}
	CUSTOMERS(int n){
	no=n;
	s=new SERVER[n];
	l.initial(n);
	eachTime= new int[n];
	time=0;
	for(int x=0;x<no;x++){
	//s[x]=NULL;
	//l[x]=NULL;
	eachTime[x]=0;
	}
	}
	CUSTOMER* randomCustomer(){
		CUSTOMER *c=new CUSTOMER();
		time+=rand()%5;
		cout<<"\n|"<<time<<"|";///
		c->setArraive(time);
		c->setType(rand()%2);
		c->setNext(NULL);
		return(c);
	}
	void calculation(int t){

		int min,index=0,noOfCustomer=0;
		CUSTOMER *tmp;int total=0;
		do{
		min=10000;

		if(time<=t){
		for(int i=0;i<no;i++){
			if(min>l.length(i)){min=l.length(i);index=i;}
		}
		l.add(randomCustomer(),index);
		noOfCustomer++;
		cout<<"Sever no :"<<index<<endl;
		}
		else{time+=1;}

		cout<<"Current length";
		for(int i=0;i<no;i++){
			cout<<"["<<l.length(i)<<"]";
		}
		//system("pause");

		cout<<"Time all server :";
		for(int i=0;i<no;i++){
			if(s[i].getServiceOn()==false && time<=t){
					tmp=l.top(i);
					total+=tmp->getArraive()-eachTime[i];
					s[i].getTotalWaitForService();eachTime[i]+=s[i].getservicingTime()+(tmp->getArraive()-eachTime[i]);s[i].setServiceOn(true);break;
			}

			if(eachTime[i]<time && s[i].getServiceOn()==true){l.clearTop(i);//cout<<"A";
			if(l.length(i)==0){//cout<<"B";
				s[i].setServiceOn(false);}
			}
			if((l.length(i)!=0 && eachTime[i]<time)){
				//cout<<"C";
				if(l.length(i)!=1){
					//cout<<"D";
					tmp=l.top(i);
					total+=eachTime[i]-tmp->getArraive();
					s[i].getTotalWaitForService();eachTime[i]+=s[i].getservicingTime();s[i].setServiceOn(true);
				}
				else{
					//cout<<"E";
					tmp=l.top(i);s[i].setTotalWaitForService(eachTime[i]-tmp->getArraive());
				s[i].getTotalWaitForService();eachTime[i]+=s[i].getservicingTime();s[i].setServiceOn(true);
				}
			}

		}

		for(int i=0;i<no;i++){cout<<"+"<<eachTime[i];}

		cout<<"\nTotal : "<<total<<"  Customer : "<<noOfCustomer<<endl;
		}while(l.isFree()==false);
		cout<<"Average waiting time per customer : "<<total/float(noOfCustomer)<<endl;
		total=0;
		for(int i=0;i<no;i++){
		total+=s[i].getTotalWaitForService();
		}
		cout<<"Average down time for server : "<<float(total/no)<<endl;
		cout<<"Average customer per minite : "<<(noOfCustomer*60)/time<<endl;
		//cout<<""
	}
};


int main(){
	int x;
	cout<<"Enter number of server : ";
	cin>>x;
	CUSTOMERS C(x);
	cout<<"Enter number of shutDown time for customer : ";
	cin>>x;
	C.calculation(x);
system("pause");

return(0);
}
