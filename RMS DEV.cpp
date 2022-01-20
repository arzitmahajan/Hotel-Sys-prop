
#include <bits/stdc++.h>
#include<windows.h>
#define B 3
#define A 100

using namespace std;
void active();
void doctive();
void working();
void adder();
void reader();
void booking();
void menu();
void payment();
void report();
void writing();
//for check;
void func();
class  RMS{
public:
	int rono;
	int roprc;
	int rtyp;
	void setrono(int num ) {
		rono = num;
	}
	int getrono() {
		return rono;
	}
	void setprc(int prc) {
		roprc = prc;
	}
	int getprc() {
		return roprc;
	}
	void setstar(int typ) {
		rtyp = typ;
	}
	int getstar() {
		return rtyp;
	}
    int gloarr[A];
    int glo;
    int glotyp[A];
    int gloprc[A];
    int gloid;
    int glostat[A];
    int k;
    int glorecid[A],glorecday[A],glorecroom[A],glorecstat[A],glorecprc[A];
    int bot,goat;
    int repdate,repmonth,repyear,repodate;
    int work,lurk=0;
}obj[B];

void readrec(){
	int vt;
	string ch;
	fstream hot;
	hot.open("Hotel_record.csv",ios::in);
	while(getline(hot,ch)){
		if(ch!=""){
			vt++;
			//cout<<ch<<"\n";
			if(vt>=0){
		//cout<<str<<"\n";
		        vector<string> v;
		        stringstream ss(ch);
		        while (ss.good()) {
	                string substr;
			        getline(ss, substr, ',');
			        v.push_back(substr);
    	}
    	//cout<<atoi(v.at(0).c_str())+12;
    	obj[B].glorecstat[vt]= atoi(v.at(0).c_str());
    	obj[B].glorecroom[vt]= atoi(v.at(1).c_str());
    	obj[B].glorecday[vt]= atoi(v.at(2).c_str());
    	obj[B].glorecprc[vt]= atoi(v.at(3).c_str());
    	obj[B].glorecid[vt]= atoi(v.at(4).c_str());
			}
		}
    }
		obj[B].goat = vt;
	hot.close();	
}
void payment() {
	int bq;
	fstream hot;
	reader();
	printf("List of Active guest is!\n");
	readrec();
	for(bq=1;bq<=obj[B].goat;bq++){
		if(obj[B].glorecstat[bq]==0){
			cout<<"stat = "<<obj[B].glorecstat[bq]<<"\troom = "<<obj[B].glorecroom[bq]<<"\tday  = "<<obj[B].glorecday[bq]<<"\tid = "<<obj[B].glorecid[bq]<<"\n";    
		}
    }
	int ex,ix;
	int to;
	int fo,yo,fair;
	int	 recid;
	int rent,y;
	printf("Enter your ID\n");
	cin>>recid;
	for(fo=0;fo<=obj[B].goat;fo++){
		//cout<<"recid = "<<recid<<endl;
		//cout<<"obj[B].glorecid[fo] = "<<obj[B].glorecid[fo]<<endl;
		//cout<<"fo = "<<fo<<endl;
		//cout<<"obj[B].bot = "<<obj[B].bot<<endl;
		if(recid== obj[B].glorecid[fo]){
			obj[B].glorecstat[fo] = -1;
			ex=fo;
			//cout<<"stat = "<<obj[B].glorecstat[fo]<<"\troom = "<<obj[B].glorecroom[fo]<<"\tday  = "<<obj[B].glorecday[fo]<<"\tid = "<<obj[B].glorecid[fo]<<"\n";    
			for(y=0;y<=obj[B].glo;y++){
				//;cout<<"Y = "<<y<<endl;
				if(obj[B].glorecroom[fo]==obj[B].gloarr[y]){
				    ix = y;
				//	cout<<"Y in if stat = "<<y<<endl;
				//	cout<<"stat for reader = "<<obj[B].glostat[fo]<<"y = "<<y<<endl;
					obj[B].glostat[y] = -1;
				    fair =obj[B].gloprc[y];
				    SYSTEMTIME a;
					GetLocalTime(&a);
					//cout << "Date :" << a.wDay << "/";
				//	cout << a.wMonth << "/"<<a.wYear<<endl;
				//	cout << "Time :" << a.wHour << "/";
				//	cout << a.wMinute << "/" << a.wSecond<< endl;
				    obj[B].repdate = a.wDay;
				    obj[B].repmonth = a.wMonth;
				    obj[B].repyear = a.wYear;
				}
			}
		}
	}
	
    rent = obj[B].glorecday[ex]*fair;
    //cout<<fair;
	cout<<"\nYour rent for "<<obj[B].glorecday[ex]<<" days is $"<<rent<<"\n";
	fstream RMSback;
	RMSback.open("RMS_back.csv",ios::out);
	for(yo =0; yo<obj[B].glo;yo++){
    	//cout<<"stat for reader = "<<obj[B].glostat[yo]<<endl;
    	//cout<<"obj[B].gloarr[yo] ="<<obj[B].gloarr[yo]<<endl; 
		RMSback<<obj[B].gloarr[yo]<<",";
		RMSback<<obj[B].glotyp[yo]<<",";
        RMSback<<obj[B].gloprc[yo]<<",";
		RMSback<<obj[B].glostat[yo]<<"\n";
		//cout<<"stat = "<<obj[B].glostat[yo]<<"\ttyp = "<<obj[B].glotyp[yo]<<"\tprc = "<<obj[B].gloprc[yo]<<"\tstat = "<<obj[B].glostat[yo]<<"\n";
	    }
	    RMSback.close();
	    hot.open("Hotel_record.csv",ios::out);
	    for(to =1 ;to<=obj[B].goat ;to++){
	      //  cout<<"stat ="<<obj[B].glorecstat[to]<<"\troom"<<obj[B].glorecroom[to]<<"\tday"<<obj[B].glorecday[to]<<"\tid"<<obj[B].glorecid[to]<<"\tfair ="<<obj[B].glorecprc[to]<<"\n";
			hot<<obj[B].glorecstat[to]<<",";
	    	hot<<obj[B].glorecroom[to]<<",";
	    	hot<<obj[B].glorecday[to]<<",";
	    	hot<<obj[B].glorecprc[to]<<",";
	    	hot<<obj[B].glorecid[to]<<"\n"; 
	    }
	    hot.close();
	fstream guest;
	guest.open("Guest_history.csv",ios::app);
		//	cout<<"status ="<<obj[B].glostat[u]<<"\fn";
           // cout<<"Room no. "<<obj[B].glorecroom[u]<<"\t obj[B].day= "<<obj[B].glorecday[u]<<"\t price = "<<obj[B].glorecprc[u]<<"\t obj[B].gloid = " <<obj[B].glorecid[u]<<"\n";
			guest<<obj[B].repdate<<"/";
			guest<<obj[B].repmonth<<"/";
			guest<<obj[B].repyear<<",";
			guest<<obj[B].glorecid[ex]<<",";
			guest<<obj[B].glorecroom[ex]<<",";
		    guest<<obj[B].glotyp[ix]<<",";
			guest<<obj[B].glorecday[ex]<<",";
			guest<<rent<<"\n";	
	guest.close();	
//	doctive();
    working();
}
void funcid(){
	string str;
	fstream hotelid;
	hotelid.open("hotelid.csv",ios::in);
	while(getline(hotelid,str)){
	hotelid>>str;
	//cout<<"str ="<<str<<"\n";
}
    obj[B].gloid = atoi(str.c_str());
    obj[B].gloid ++;
   // cout<<"id = "<<obj[B].gloid <<"\n";
    hotelid.close();
	hotelid.open("hotelid.csv",ios::out);
	hotelid<<obj[B].gloid;
	hotelid.close();
}
void working() {
	int choice;
	reader();
	//cout<<obj[B].glo;
	printf("***Welcome***");
	printf("Enter your choice!\n");
	printf("Enter 1 to Add rooms\nEnter 2 to book a room\nEnter 3 to make a payment\nEnter 4 to get the report of hotel\nEnter 5 to exit\n>");
    //cout<<" Work = "<<obj[B].work<<endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		adder();
		break;
	case 2:
		reader();
		if( obj[B].work >0||obj[B].lurk!=0){
		booking();
		}
		else{
			printf("First add rooms\n");
			working();
		}
		break;
	case 3:
		if( obj[B].work >0){
		payment();
		}
		else{
			printf("First add rooms\n");
			working();
		}
		break;
	case 4:
	    report();
	    break;
	case 5:
		break;
	default:
		printf("Enter the valid option!\n");
		break;
	}
}

void reader() {
	int p,vt=-1;
	int l1,l2;
	int h, ct = 0;
	int y[100];
	std::ifstream file("RMS_back.csv");
	int gont=0,counting=0;
	std::string str;
	char line[4];	
	while (std::getline(file, str)) {	
		vt++;
		if(vt>=0){
		counting++;
	//	cout<<" vt= "<<vt<<"\n";
	//	cout<<"counting = "<<counting<<"\n";
		vector<string> v;
		stringstream ss(str);
		 while (ss.good()) {
	        string substr;
	        getline(ss, substr, ',');
	        v.push_back(substr);
    	}
    //	cout<<atoi(v.at(0).c_str())+12;
    //	cout<<"work = "<<obj[B].work<<endl;
        //cout<<atoi(v.at(1).c_str())<<"\n";
    	if(atoi(v.at(0).c_str())>0){
		obj[B].gloarr[vt]= atoi(v.at(0).c_str());
    	obj[B].glotyp[vt] = atoi(v.at(1).c_str());
    	obj[B].gloprc[vt] = atoi(v.at(2).c_str());
    	obj[B].glostat[vt] = atoi(v.at(3).c_str());
    	obj[B].work++;
    	//obj[B].gloid;
    	//cout<<atoi(v.at(0).c_str());
    //	cout<<"work = "<<obj[B].work<<endl;
    	}
    	else{
    		break;
		}
        }
	    else{
		   printf("Nothing the record yet !\n");
		   
     	}
    }
    if(vt>=0){
	//	cout<<"counting 2= "<<counting<<"\n";
    	obj[B].glo=counting;
    //	cout<<"objglo = "<<obj[B].glo<<"\n\n";
  		obj[B].bot = vt;
  		file.close();
	}
    
}

int  menu(int star){
	reader();
	int p,get;
	int x,maker=0;
//	cout<<"from menu start --"<<obj[B].glo<<"\n";
	/*	for(int y=0;y<obj[B].glo;y++){
			    	cout<<"arr = "<<obj[B].gloarr[y]<<"\ttyp = "<<obj[B].glotyp[y]<<"\tprc = "<<obj[B].gloprc[y] <<"\t sttat=="<<obj[B].glostat[y]<<"\n";
		}*/
	
//	printf("Your  rooms is !\n");
	for(p=0;p<=obj[B].glo;p++){
	//	cout<<"arr = "<<obj[B].gloarr[p]<<"\ttyp = "<<obj[B].glotyp[p]<<"\tprc = "<<obj[B].gloprc[p] <<"\t sttat=="<<obj[B].glostat[p]<<"\n";
		if(star==obj[B].glotyp[p] && obj[B].glostat[p]!=1){
			obj[B].k = p;
			 //cout<<"\nk = "<<obj[B].k;
   			 obj[B].glostat[p]=1;
   			 maker++;
   			 return 1;
			// cout<<"Room no. "<<obj[B].gloarr[p]<<"\t price = "<<obj[B].gloprc[p]<<"\t obj[B].gloid = " <<obj[B].gloid <<"\t obj[B].glotyp = "<<obj[B].glotyp[p]<<"\n";
			break;
		}
    }
    if(maker==0){
	//	printf("WE Dont have this type of room!!\n");
		return -1;
	}
   /* for(x=0;x<=obj[B].glo;x++){
    	cout<<"\n after booking stat = "<<obj[B].glostat[x];
	}*/
}
void booking(){
	//	cout<<obj[B].glo<<"\n";
	int use;
	int mo,check=0;
	int lotyp;
	int id[A];
	char  opt[5];
	int star,day;
	printf("Do you want to book a room (yes/no)\n");
	std::cin >> opt;
//	cout<<"glo id ="<<obj[B].gloid<<"\n";
	if(strcmp(opt,"no")==0){
        working();
	/*	for(mo=0;mo<=obj[B].glo;mo++){	
	        //cout<<"Room no. "<<obj[B].gloarr[mo]<<"\t price = "<<obj[B].gloprc[mo]<<"\t obj[B].gloid = " <<obj[B].gloid <<"\t obj[B].glotyp = "<<obj[B].glotyp[mo]<<"obj[B].glostat = "<<obj[B].glostat[mo]<<"\n";		
			check++;	
	    }*/
    }if(strcmp(opt,"yes")==0){
    	printf("Enter how many star's hotel room  you want to book\n");
		std::cin >>star;
	   // cout<<" menu = "<<menu(star);
	    if(menu(star)==1){
		    int fo;
			fstream RMSback;
			RMSback.open("RMS_back.csv",ios::out);
			for(fo =0; fo<obj[B].glo;fo++){
				RMSback<<obj[B].gloarr[fo]<<",";
				RMSback<<obj[B].glotyp[fo]<<",";
	            RMSback<<obj[B].gloprc[fo]<<",";
				RMSback<<obj[B].glostat[fo]<<"\n";
				//	cout<<"stat = "<<obj[B].glostat[fo]<<"\n";
		    }
			RMSback.close();
		      // cout<<"after booking and changing the status \n";
		    /*for(int y=0;y<obj[B].glo;y++){
					    	cout<<"arr = "<<obj[B].gloarr[y]<<"\ttyp = "<<obj[B].glotyp[y]<<"\tprc = "<<obj[B].gloprc[y] <<"\t sttat=="<<obj[B].glostat[y]<<"\n";
				}*/
		
		       	//cout<<"arr = "<<obj[B].gloarr[obj[B].k]<<"\ttyp = "<<day<<"\tprc = "<<obj[B].gloprc[obj[B].k] <<"\t sttat=="<<obj[B].gloid<<"\n";
			funcid();
			//	cout<<obj[B].k<<"New value from room no after booking ";
			printf("Enter for how many days you want to book the room\n");
	        //cout<<"glo id ="<<obj[B].gloid;
	        //cout<<"\n new value from  asd \n";
			std::cin >> day;
			cout<<"Your UID is ->"<<obj[B].gloid<<endl;
			fstream hot;
			hot.open("Hotel_record.csv",ios::app);
				hot<<"0"<<",";			
				hot<<obj[B].gloarr[obj[B].k]<<",";
				hot<<day<<",";
				hot<<obj[B].gloprc[obj[B].k]<<",";
				hot<<obj[B].gloid<<"\n";
				
			//	cout<<"arr = "<<"\n";
			//	cout<<"New value from room no after booking ";
			hot.close();
		}	
		else{
			printf("WE Dont have this type of room\n\n");
		}
    }
	//overwriting the reade file
	//active();
	working();
}
void initial(int yumb){
	int inroom,intyp,inprc;
	fstream RMSback;
    printf("First enter 1 room for initialisation\n");
	printf("enter room no.\n");
	cin>>inroom;
	printf("Enter thr room type\n");
	cin>>intyp;
	printf("Enter the price\n");
	cin>>inprc;
	RMSback.open("RMS_back.csv",ios::out);
	RMSback<<inroom<<",";
	RMSback<<intyp<<",";
    RMSback<<inprc<<","<<"0"<<"\n";
    RMSback.close();
	yumb++;
	cout<<"yumb = "<<yumb<<endl;
	working();
}
void adder() {
	reader();	
	int bill=0;
    int typ,prc;
	int clo,po=0;
	int roo,num=0,x,y;
	int ga,tra,fad;
	char inques[3];
	fstream RMSback;
	int yumb = 0;
	//cout<<"work = "<<obj[B].work<<"\n";
	//cout<<"yumb = "<<yumb<<"\n";
	if(yumb!=0||obj[B].work ==0){
	    initial(yumb);
	}
	else{
		printf("Do you want to add rooms(yes/no)\n");
		cin>>inques;
		if(strcmp(inques,"yes")==0){
			printf("Enter the number of rooms \n");
			std::cin >> roo;
			printf("Existing rooms are\n");
			for(ga=0;ga<obj[B].glo;ga++){
		        	cout<<"ROOM  = "<<obj[B].gloarr[ga]<<endl;
				}
			for (x = 0; x < roo; x++) {
				printf("Enter the Room no.\n");
				std::cin >> num;
				for(clo=0;clo<obj[B].glo;clo++){
					if(obj[B].gloarr[clo]==num){
						po++;
						
					//	cout<<"obj ="<<obj[B].gloarr[clo]<<"\n";	
					}
					for(int gud=0;gud<roo;gud++){
						if(num==obj[gud].getrono()){
							bill++;
						}
					}
					if(bill>1){
						po++;
					}
				}
			//	cout<<"glo = "<<obj[B].glo<<endl;
			//	cout<<"clo = "<<clo<<endl;
			//	cout<<"x = "<<x<<endl;
			    if(po==0){
			   	//	writing(num);
					RMSback.open("RMS_back.csv",ios::app);
				//	cout<<"uniques:\n";
					printf("Enter the number of stars of the room\n");
					std::cin>> typ;
					printf("Enter the price of the room\n");
					std::cin >> prc;
				    obj[x].setrono(num);
					obj[x].setstar(typ);
					obj[x].setprc(prc);
					                
					RMSback<<num<<",";
					RMSback<<typ<<",";
				    RMSback<<prc<<","<<"0"<<"\n";
				    obj[B].lurk = 1;
				    RMSback.close();
			        }
		        else{
		        	printf("This Room Number Already exists !\n\n");
		        	po = 0;
		        	bill=0;
				}
		   }
		   	reader();
		   	//printf("Please exit if you have added the room!\n");
		   	working();  
	   }
	   else{
	   	working();
	   }
   }
}
/*void writing(int num){
	int typ,prc;
	RMSback.open("RMS_back.csv",ios::app);
	cout<<"uniques:\n";
	printf("Enter the number of stars of the room\n");
	std::cin >> typ;
	printf("Enter the price of the room\n");
	std::cin >> prc;
    obj[x].setrono(num);
	obj[x].setstar(typ);
	obj[x].setprc(prc);
	RMSback<<num<<",";
	RMSback<<typ<<",";
    RMSback<<prc<<","<<"0"<<"\n";
    RMSback.close();
}*/
/*void active(){
	int fo;
	fstream RMSback;
	RMSback.open("RMS_back.csv",ios::out);
	for(fo =0; fo<obj[B].glo;fo++){
			RMSback<<obj[B].gloarr[fo]<<",";
			RMSback<<obj[B].glotyp[fo]<<",";
            RMSback<<obj[B].gloprc[fo]<<",";
			RMSback<<obj[B].glostat[fo]<<"\n";
			cout<<"stat = "<<obj[B].glostat[fo]<<"\n";
        }
	RMSback.close();
	
}*/
void report(){
	int u;
	int ct=0;
	string ch;
	printf("Detail list of guest!\n");
	fstream guest;
	guest.open("Guest_history.csv",ios::in);
	printf("Date--UID--Room--Type--Days--Rent\n");
    while(getline(guest,ch)){
    	if(ch!=""){
			cout<<ch<<"\n";
			ct++;  
	    }
    }
    if(ct==0){
		   printf("Nothing in the file !");
		}
	guest.close();
	working();
}

int main()
{
  working(); 
}


