				/*SUPER MARKET BILLING AND EMPLOYEE DATA HANDLING*/
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
using namespace std;

static int id=10000;
static int prodID=123456;

/***********************************************************************************************************************************************************************
************************************************************************************************************************************************************************
************************************************************************************************************************************************************************/

		// Admin Login 
class login{
	
	char admin_pwd[30]="Admin"; 	//  DEFAULT Admin password
		
	public:
		bool adminLogin(){
			char p[30]; 		//User input password
			cout<<"Enter the admin password:";
			cin>>p;
			cout<<endl;
			
			if(strcmp(p,admin_pwd)==0){		// If Admin passoword is same as user input 
				return true;
			}
			else{
				return false;
			}
		}
		
		void changePass(){					// FUNCTION to change Admin password
			char s[30];
			cout<<"Enter CURRENT password:";
			cin>>s;
			char a;
			if(strcmp(s,admin_pwd)==0){
				cout<<"Enter new Admin password:";
				cin>>s;
				cout<<"Are you sure you want to change admin password(y/n):";
				cin>>a;
				if(a=='y'){
					cout<<"\n\nAdmin Password changed successfully\n";
					strcpy(admin_pwd,s);
				}
				else{
					cout<<"\n\nAdmin Password change failed\n";
					system("PAUSE");
					return;
				}
			}
			else{
				cout<<"Wrong Admin Password\n";
				return;
			}
		}
};

/***********************************************************************************************************************************************************************
************************************************************************************************************************************************************************
************************************************************************************************************************************************************************/

// Employee details Linked list

		//Creating Node for employee   NODE
		
struct node
{
  	string empName; 	// Employee Name
	float empSalary; 	// Employee Salary
	char empPswd[30];	// Employee Password
	int eID;
	int age;			// Employee Age
 	struct node *left,*right;	// Node linkages
 	 	
};

typedef struct node *NODE;
class employee
{
  NODE first;
  int countE;
  
  public:
  	
    employee()		//Constructor to initialise first and node count
    {
      first=NULL;
      countE=1;
    }
    
    void create();	//Employee Details add funtion
    void del(int);	//Employee details delete function
    void print();	//Employee Display Function
    void editE(int); //Employee Details Edit
    int loginE();  //Employee Login Function
};

// Add Employee Details 
void employee::create(){
	
	NODE temp,prev;
  	string name;
  	float salary;
  	char pwd[30];
  	int age;
  
  	cout<<"Enter Employee name: ";
  	cin.ignore();		
  	getline(cin,name);					// To get full name
  	cout<<"Employee ID:"<<id<<endl;		// Output Employee ID
  	cout<<"Enter Employee Age: ";		// Employee Age
  	cin>>age;
  	if(age>60 || age<18){
  		cout<<"Invalid Age"<<endl;
		return;	
	}
  	cout<<"Enter Employee password:";	// Employee Password
  	cin>>pwd;
  	cout<<"Enter Employee salary:";		// Employee Salary
  	cin>>salary;
  	cout<<endl;
  
  	
  	temp=new(struct node);
  	temp->left=temp->right=NULL;
  
  	if(first==NULL){
  	
    	temp->empName=name; 			// Add employee name to node
    	strcpy(temp->empPswd,pwd);		// Add employee password to node 
    	temp->eID=id;					// Add employee ID to node
    	temp->empSalary=salary;			// Add employee salary to node
    	temp->age=age;					// Add employee age to node
    	first=temp;
    	id++;							// Increment id for next new ID generation
     
  	}
  	else
  	{
    	temp->empName=name;			// Add employee name to node
    	strcpy(temp->empPswd,pwd);	// Add employee password to node 
    	temp->eID=id;				// Add employee ID to node
		temp->empSalary=salary;		// Add employee salary to node 
		temp->age=age;				// Add employee age to node
    	prev=first;
		while(prev->right!=NULL){
			prev=prev->right;
		}
		prev->right=temp;
		temp->left=prev;
		temp->right=NULL;
    	id++;				// Increment ID for next new ID generation
  	}
  
}

// Delete Employee Details 

void employee::del(int iD)
{	
					// 'iD' is the user input EMPLOYEE ID	
	int counterx=1;  // counter to count the position of the node
	int pos;
	NODE temp1;
	
	if(first==NULL){
		cout<<"NO EMPLOYEE DATA PRESENT IN DATABASE"<<endl;
		return;
	}
	
	temp1=first;
					// LINEAR SEARCH FOR USER INPUT ID IN EMPLOYEE DETAILS LINKED LIST
	while(temp1!=NULL && temp1->eID<=iD){
		
		if(temp1->eID==iD){			// If user input ID is found, delete the node at that position
			pos=counterx;			// 	using counter find position of that node 
		
		
		// LOGIC FOR DELETETION IN EMPLOYEE DOUBLY LINKED LIST
			NODE cur,prev,temp;
			
			if(pos==1){
     			cout<<first->empName<<" details deleted\n";
     			cur=first;
     			first=first->right;
     			if(first!=NULL)
       			first->left=NULL;
     			delete(cur);
     			return; 
   			}
   
   			prev=NULL;
   			cur=first;
   
  			while(cur!=NULL && countE!=pos){
     			prev=cur;
     			cur=cur->right;
     			countE++;
   			}
   			if(cur==NULL){
     			countE=1;
     			cout<<"Employee ID Error\n";
     			return;
   			}
   
   			else{
   				countE=1;
   				temp=cur->right;
   				prev->right=temp;
   				if(temp!=NULL)
     				temp->left=prev;
     				cout<<cur->empName;
   					cout<<" details deleted";
   					
   					delete(cur);
   					return;
   				}
		}
		
		else{
			temp1=temp1->right;			
			counterx++;
		}
	}
	// If user input ID doesnt match any ID in EMPLOYEE DETAILS LINKED LIST
	cout<<"Employee ID Error";
	return;
}


//Display Employee Details

void employee::print(){
	
  	NODE temp;
  	if(first==NULL)
  	{
    	cout<<"No Employee present\n";
    	return;
  	}
		
  	temp=first;
  	cout<<"EmployeeName\tEmployee ID\tEmployee Age\tEmployee Salary\n\n";
  	while(temp!=NULL)
  	{
    	cout<<temp->empName<<std::setw(20)<<std::right<<temp->eID<<std::setw(20)<<temp->age<<std::setw(10)<<std::right<<"$"<<temp->empSalary<<endl;
    	temp=temp->right;
  	}
}

// Edit Employee Details

void employee::editE(int b){
	NODE temp;
	if(first==NULL){
		cout<<"NO EMPLOYEE DATA IN DATABASE"<<endl;			// Checking if product database is empty
		return;
	}
	temp=first;
	while(temp!=NULL && temp->eID<=b){
		// LOGIC FOR EDITING EMPLOYEE DATA
		if(temp->eID==b){
			string n;
			while(true){
				system("CLS");
				cout<<"\n\t\t1.Edit Employee Name\t\t2.Edit Employee Salary\t\t3.Edit Employee Password\t\t4.Admin Menu\n";
				int ch;
				cout<<"Enter your choice: ";
				cin>>ch;
				switch(ch){
					case 1:system("CLS");
							cout<<"\n\t\tEDIT EMPLOYEE NAME\n";			// Edit employee name
							cout<<"Enter new Employee name: ";
							cin.ignore();
							getline(cin,n);
							cout<<"Are you sure you want to edit name(y/n): ";
							char ya;
							cin>>ya;
							if(ya=='y'){
								temp->empName=n;
								cout<<"Name change success\n";
								cout<<endl<<endl;
								system("PAUSE");
							}
							else{
								cout<<"Name change failed\n\n";
								system("PAUSE");
								break;
							}
						break;
					
					case 2:	system("CLS");
							cout<<"\n\t\tEDIT EMPLOYEE SALARY\n";		// Edit employee salary
							float m;
							cout<<"Enter new Employee Salary: ";
							cin>>m;
							cout<<"Are you sure you want to edit salary(y/n): ";
							cin>>ya;
							if(ya=='y'){
								temp->empSalary=m;
								cout<<"Salary change success\n";
								cout<<endl<<endl;
								system("PAUSE");
							}
							else{
								cout<<"Salary change failed";
								cout<<endl<<endl;
								system("PAUSE");
								break;
							}	
							
						break;
						
					case 3:system("CLS");
							cout<<"\n\t\tEDIT EMPLOYEE PASSWORD\n";		//Edit employee password
							char ps[20];
							cout<<"Enter current employee password: ";
							cin>>ps;
							if(strcmp(temp->empPswd,ps)==0){
								cout<<"Enter new employee password: ";
								cin>>ps;
								cout<<"Are you sure you want to edit password(y/n): ";
								cin>>ya;
								if(ya=='y'){
									strcpy(temp->empPswd,ps);
									cout<<"Password change success\n";
									cout<<endl<<endl;
									system("PAUSE");
								}
								else{
									cout<<"Password change failed\n";
									cout<<endl<<endl;
									system("PAUSE");
									break;
								}	
								
							}
							else{
								cout<<"Employee Password Error\n";			// If employee password is wrong
								cout<<endl<<endl;
								system("PAUSE");
							}
							break;
					
					default:return;
				}	
			
			}
			
		}
		else{
			temp=temp->right;
		}
	}
	cout<<"\nEmployee ID ERROR\n";
	return;
}


/*****************************************************************************************************************************************************************
******************************************************************************************************************************************************************/
//EMPLOYEE LOGIN FUNCTION

int employee::loginE(){
	
	int ID;
	char p[30];
	NODE temp;
	
	cout<<"Enter Employee ID: ";
	cin>>ID;							// USER INPUT 'EMPLOYEE ID'
	cout<<"Enter password: ";
	cin>>p;								// USER INPUT 'EMPLOYEE PASSWORD'
	
	if(first==NULL){
		cout<<"NO EMPLOYEE DATA PRESENT"<<endl; 	// If EMPLOYEE LINKED LIST Is EMPTY 
		return -1;
	}
	
	temp=first;
	while(temp!=NULL){

		if(strcmp(p,temp->empPswd)==0 && temp->eID==ID){
			cout<<"Access Granted\n";						//If EMPLOYEE ID and EMPLOYEE PASSWORD match is found
			return ID;
		}
		else{
			temp=temp->right;
		}
	}
	cout<<"Access Denied\n";								//If EMPLOYEE ID and EMPLOYEE PASSWORD match is not found
	return 2;
}


/***********************************************************************************************************************************************************************
************************************************************************************************************************************************************************
************************************************************************************************************************************************************************/
//  PRODUCT DOUBLY LINKED LIST

		// Creating node for product details
struct node1
{
	string pName;		// Product Name
	float mrp;			// Product MRP
	float price; 		// Product price 
	float discount; 	// Product Discount
	int pID; 			// Product ID
	float gst;			// GST 
	
    struct node1 *l,*r; //NODE linkages
};


typedef struct node1 *NODE1;

class product
{
  	public:NODE1 first;
  	private:int countP;
  	
  public:
    product()				// Using constructor to initialise data
    {
      first=NULL;
      countP=1;
    }
    void create();			//	Add Product details
    void del(int);			//	Delete product data using product ID 
    void print();			// Display list of products 
    void edit(int);
    
};

		// Add Product Details 
void product::create()
{
  	NODE1 temp,prev;
  	string nm;
  	float max=0;
  	float prc;
  	float dis=0;
  	float GT;
  
  	cout<<"Enter Product Name: ";
  	cin.ignore();
	getline(cin,nm);									// USER INPUT product name
  
  	cout<<"Product ID: "<<prodID<<endl;		// DISPLAY UNIQUE PRODUCT ID
  	cout<<"Enter MRP: ";
  	cin>>max;									// USER INPUT product MRP  
  
  	cout<<"Enter Discount: ";
  	cin>>dis;									// USER INPUT product discount 
  	if(dis>max){
  		dis=0;
	}
  
  
  	cout<<"Price: "<<max-dis<<endl;			// PRICE = MRP - DISCOUNT
  	cout<<"Enter GST: ";					
  	cin>>GT;									// USER INPUT GST
  
  
  // LOGIC FOR INSERTION IN PRODUCT DOUBLY LINKED LIST
  	temp=new(struct node1);
  	temp->l=temp->r=NULL;
  
  	if(first==NULL)
  	{
  	//Copy USER INPUT DATA to node
     	temp->pName=nm;			
     	temp->mrp=max;
     	temp->discount=dis;
     	temp->price=max-dis;
     	temp->gst=GT;
     	temp->pID=prodID;
     	prodID++;
     	first=temp;
  	}
  	else
  	{
  	// Copy USER INPUT DATA to node
    	temp->pName=nm;
     	temp->mrp=max;
     	temp->discount=dis;
     	temp->price=max-dis;
     	temp->gst=GT;
     	temp->pID=prodID;
     	prodID++;
     	prev=first;
     	while(prev->r!=NULL){
     		prev=prev->r;
		}
    	prev->r=temp;
    	temp->l=prev;
    	temp->r=NULL;
  	}
}

		//Delete Product details
void product::del(int Id)
{
	// 'Id' is the user input product ID  
	NODE1 temp1;	
	int countery=1; 									// Counter to find position of the user input ID 
	int pos;
	
	if(first==NULL){
		cout<<"Empty Product Database\n";				// if no product data is present 
		return;
	}
	temp1=first;
	// LINEAR SEARCH FOR THE USER INPUT ID IN PRODUCT LINKED LIST
	while(temp1!=NULL && temp1->pID<=Id){
		
		if(temp1->pID==Id){							// IF PRODUCT ID MATCH FOUND DELETE PRODUCT DATA
			pos=countery;							// Get the position of node using counter 
			
			// LOGIC FOR DELETION IN PRODUCT DOUBLY LINKED LIST
			NODE1 cur,prev,temp;
			if(pos==1){
     			cout<<first->pName<<" is deleted\n";
     			cur=first;
     			first=first->r;
     			if(first!=NULL)
       			first->l=NULL;
     			delete(cur);
     			return; 
   			}
   
   			prev=NULL;
   			cur=first;
   
  			while(cur!=NULL && countP!=pos){
     			prev=cur;
     			cur=cur->r;
     			countP++;
   			}
   			if(cur==NULL){
     			countP=1;
     			cout<<"Employee ID Error\n";
     			return;
   			}
   
   			else{
   				countP=1;
   				temp=cur->r;
   				prev->r=temp;
   				if(temp!=NULL)
     				temp->l=prev;
     				cout<<cur->pName<<endl;
   					cout<<" is deleted";
   					delete(cur);
   					return;
   				}
		}
		
		else{
			temp1=temp1->r;
			countery++;
		}
	}
	
	cout<<"Product ID Error"<<endl;			//	IF PRODUCT ID MATCH NOT FOUND return
	return;
}

		//Display Product Details
void product::print()
{
  	NODE1 temp;
  	if(first==NULL)
  	{
    	cout<<"PRODUCT DATABASE is empty\n";
    	return;
  	}
  	temp=first;
  	cout<<"ProductName"<<std::setw(15)<<"ProductID"<<std::setw(14)<<"MRP"<<std::setw(15)<<std::right<<"UNIT Price"<<std::setw(10)<<"Discount"<<std::setw(15)<<std::right<<"GST\n\n";
  	while(temp!=NULL)
  	{
    	cout<<temp->pName<<std::setw(20)<<temp->pID<<std::setw(15)<<temp->mrp<<"$"<<std::setw(10)<<temp->price<<"$"<<std::setw(10)<<temp->discount<<"$"<<std::setw(15)<<temp->gst<<"%"<<endl;
    	temp=temp->r;
  	}
}

// Edit Product Details
void product::edit(int b){
	NODE1 temp;												
	if(first==NULL){
		cout<<"NO PRODUCT DATA IN DATABASE"<<endl;			// Checking if product database is empty 
		return;
	}
	temp=first;
	while(temp!=NULL && temp->pID<=b){
		if(temp->pID==b){
			string n;
			while(true){
				system("CLS");
				cout<<"\n\t\t1.Edit Product Name\t\t2.Edit Product MRP\t\t3.Edit Product Discount\t\t4.Edit Product GST\t\t5.Admin Menu\n";
				int ch;
				cout<<"Enter your choice: ";
				cin>>ch;
				switch(ch){
					case 1:system("CLS");
							cout<<"\n\t\tEDIT PRODUCT NAME\n";		// Edit Product name 
							cout<<"Enter product name: ";
							cin.ignore();
							getline(cin,n);
							cout<<"Are you sure you want to edit name(y/n): ";
							char ya;
							cin>>ya;
							if(ya=='y'){
								temp->pName=n;
								cout<<"Name change success\n";
								cout<<endl<<endl;
								system("PAUSE");
							}
							else{
								cout<<"Name change failed";
								cout<<endl<<endl;
								system("PAUSE");
								break;
							}
						break;
					
					case 2:system("CLS");
							cout<<"\n\t\tEDIT PRODUCT MRP\n";		// Edit Product MRP
							float m;
							cout<<"Enter product MRP: ";
							cin>>m;
							cout<<"Are you sure you want to edit MRP(y/n): ";
							cin>>ya;
							if(ya=='y'){
								temp->mrp=m;
								temp->price=temp->mrp-temp->discount;
								cout<<"MRP change success\n";
								cout<<endl<<endl;
								system("PAUSE");
							}
							else{
								cout<<"MRP change failed";
								cout<<endl<<endl;
								system("PAUSE");
								break;
							}	
							
						break;
					
					case 3:system("CLS");
							cout<<"\n\t\tEDIT PRODUCT DISCOUNT\n";		// Edit Product discount
							float dis;
							cout<<"Enter product Discount: ";
							cin>>dis;
							cout<<"Are you sure you want to edit Discount(y/n): ";
							cin>>ya;
							if(ya=='y'){
								temp->discount=dis;
								temp->price=temp->mrp-dis;
								cout<<"DISCOUNT change success\n";
								cout<<endl<<endl;
								system("PAUSE");
							}
							else{
								cout<<"DISCOUNT change failed";
								cout<<endl<<endl;
								system("PAUSE");
								break;
							}	
						break;
					
					case 4:system("CLS");
							cout<<"\n\t\tEDIT PRODUCT GST\n";		// Edit Product GST
							float g;
							cout<<"Enter product GST: ";
							cin>>g;
							cout<<"Are you sure you want to edit GST(y/n): ";
							cin>>ya;
							if(ya=='y'){
								temp->gst=g;
								cout<<"GST change success\n";
								cout<<endl<<endl;
								system("PAUSE");
							}
							else{
								cout<<"GST change failed";
								cout<<endl<<endl;
								system("PAUSE");
								break;
							}
						break;
					
					default:return;
				}	
			
			}
			
		}
		else{
			temp=temp->r;
		}
	}
	cout<<"\nProduct ID ERROR\n";
	return;
}


/***********************************************************************************************************************************************************************
*************************************************************************************************************************************************************************
****************************************************************************************************************************************************************************/
// CART DOUBLY LINKED LIST

		//Creating node for cart doubly linked list
struct node2
{
	string pNameC;			// Product Name in cart
	float mrpC;					// Product MRP in cart
	float priceC; 				// Product price in cart  After Discount
	float discountC; 			// Product Discount in cart
	int pIDC; 					// Product ID in cart
	float gstC;					// Product GST in cart
	int quantity;         		// Product quantity in cart
    struct node2 *le,*ri; 		// node linkages
};


typedef struct node2 *NODE2;

class cart
{
  	NODE2 first;
  	int countC;
  	public:
    cart()						// USING constructor to initialise data
    {
      	first=NULL;
      	countC=1;
    }
    void create(int,product,cart); 	// ADD ITEMS TO CART USING PRODUCT ID 
    void del(int);				// DELETE ITEMS FROM CART USING PRODUCT ID
    void print();				// DISPLAY CART ITEMS AND TOTAL AMOUNT TO BE PAID
    int delete_duplicate(int,int);
    
};

		// Add Product Details 
void cart::create(int ide,product ob,cart c)
{
	int o;
  	NODE1 temp1;					// CREATE A NODE OF PRODUCT 
  
  	if(ob.first==NULL){
  	cout<<"Product Database empty"<<endl;		// Checking if product database if empty
  	return;
  	}
	temp1=ob.first;
	
	while(temp1!=NULL && temp1->pID<=ide){
		// LOGIC FOR ADDING ITEM TO CART
		if(temp1->pID==ide){
			int q;
			cout<<"Enter Quantity:";
			cin>>q;
			
			NODE2 temp,prev;
			
  		    temp=new(struct node2);
  			temp->le=temp->ri=NULL;
  
  			if(first==NULL)
  			{
     			temp->pNameC=temp1->pName;
     			temp->mrpC=temp1->mrp;
     			temp->discountC=temp1->discount;
     			temp->priceC=temp1->price;
     			temp->gstC=temp1->gst;
     			temp->pIDC=temp1->pID;
     			temp->quantity=q;
     			first=temp;
     			cout<<"Product Added to cart\n";
     			return;
  			}
  			else
  			{	o=c.delete_duplicate(ide,q);
  				if(o==-1){
  					temp->pNameC=temp1->pName;
     				temp->mrpC=temp1->mrp;
     				temp->discountC=temp1->discount;
     				temp->priceC=temp1->price;
     				temp->gstC=temp1->gst;
     				temp->pIDC=temp1->pID;
     				temp->quantity=q;
    				prev=first;
    				while(prev->ri!=NULL){
    					prev=prev->ri;
					}
					prev->ri=temp;
					temp->le=prev;
					temp->ri=NULL;
    				cout<<"Product Added to cart\n";
    				return;
				}
				else{
					cout<<"Product Added to cart\n";
					return;
				}
  			}
		}
		else{
			temp1=temp1->r;
		}
	}
	cout<<"Product ID Error"<<endl;		// If Product id doesnt match 
	return;
}

		//Delete Product details
void cart::del(int a1)
{
	NODE2 temp1;
	int countery=1;
	int pos;
	
	if(first==NULL){
		cout<<"EMPTY CART\n";
		return;
	}
	
	temp1=first;
	while(temp1!=NULL && temp1->pIDC<=a1){
		// LOGIC FOR DELETING ITEMS FROM CART 
		if(temp1->pIDC==a1){
			pos=countery;
			NODE2 cur,prev,temp;
			
			if(pos==1){
     			cout<<first->pNameC<<" is deleted\n";
     			cur=first;
     			first=first->ri;
     			if(first!=NULL)
       			first->le=NULL;
     			delete(cur);
     			return; 
   			}
   
   			prev=NULL;
   			cur=first;
   
  			while(cur!=NULL && countC!=pos){
     			prev=cur;
     			cur=cur->ri;
     			countC++;
   			}
   			if(cur==NULL){
     			countC=1;
     			cout<<"Product ID Error\n";
     			return;
   			}
   
   			else{
   				countC=1;
   				temp=cur->ri;
   				prev->ri=temp;
   				if(temp!=NULL)
     				temp->le=prev;
     				cout<<cur->pNameC;
   					cout<<" Product is deleted\n";
   					delete(cur);
   					return;
   				}
		}
		
		else{
			temp1=temp1->ri;
			countery++;
		}
	}
	
	cout<<"Product ID Error"<<endl;
	return;
}

	// Handling Duplicate nodes
int cart::delete_duplicate(int a,int b){		// a is product id and b is product quantity
	NODE2 temp;
	temp=first;
	while(temp!=NULL){
		if(temp->pIDC==a){
			temp->quantity=temp->quantity+b;
			return 1;
		}
		temp=temp->ri;
	}
	return -1;
}
 
		//Display Product Details
void cart::print()
{
  	NODE2 temp;
  	float totalP=0;
  	float sum=0;
  	float dis=0;
  	int iNO=0;
  	int qNO=0;
  	if(first==NULL)
  	{
    	cout<<"Cart is empty\n";
    	return;
  	}
  	temp=first;
  	cout<<"ProductName"<<std::setw(15)<<"ProductID"<<std::setw(10)<<"Qty"<<std::setw(14)<<"MRP"<<std::setw(15)<<std::right<<"UNIT Price"<<std::setw(10)<<"Discount"<<std::setw(10)<<"GST"<<std::setw(15)<<std::right<<"AMOUNT\n\n";
  	while(temp!=NULL)
  	{
  		totalP=(float)(temp->priceC)*(temp->quantity);
    	cout<<temp->pNameC<<std::setw(20)<<temp->pIDC<<std::setw(10)<<temp->quantity<<std::setw(15)<<"$"<<temp->mrpC<<std::setw(10)<<"$"<<temp->priceC<<std::setw(10)<<"$"<<temp->discountC<<std::setw(15)<<temp->gstC<<"%"<<std::setw(10)<<"$"<<totalP<<endl;
    	sum=sum+totalP;
    	iNO++;
    	qNO=qNO+temp->quantity;
    	dis=dis+(temp->discountC)*(temp->quantity);
		temp=temp->ri;
  	}
  	cout<<"\n******************************************************************************************************************************************************\n";
  	cout<<"*********************************************************************************************************************************************************\n";
  	cout<<"\tITEMS: "<<iNO<<"\t";
  	cout<<"\tQUANTITY: "<<qNO<<endl<<endl;
  	cout<<"*********************************************************************************************************************************************************\n";
  	cout<<"PAYMENT SUMMARY:\n";
  	cout<<"\n\t\tYOU SAVED: $"<<dis<<endl<<endl;
  	cout<<"\n\t\tAMOUNT TO BE PAID : $"<<sum<<endl<<endl;
  	cout<<"*********************************************************************************************************************************************************\n";
  	cout<<"*********************************************************************************************************************************************************\n";
  	cout<<"*********************************************** THANK YOU FOR SHOPPING WITH US **************************************************************************\n";
}

/*******************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************/
// Main Function 
int main(){

	char y;
	int choice;
	
	int pos1,choice1;		
   	int pos2,choice2;	
	int billNO=10;
	bool tr;		
	
	product p1; //Creating product object
	
	login ad; // Creating login object
	
	employee d; //Creating employee object
	

		while(true){
x:			system("CLS");
			cout<<"\n\t\t\t\tLOGIN MENU\n\n";
			cout<<"*****************************************************************************************************************************************\n";
			cout<<"*****************************************************************************************************************************************\n";
			cout<<"\n\t1.Admin Login\t\t2.Employee Login\t\t3.Exit\n\n";			// Admin or Employee Login Menu
			cout<<"******************************************************************************************************************************************\n";
			cout<<"Enter your choice: ";
			cin>>choice;
		
		switch(choice){
			case 1:system("CLS");						// CLEARSCREEN
					cout<<"\t\t\tAdmin Login\n\n\n";
					cout<<"****************************************************************************************************************************************\n\n";
					tr=ad.adminLogin();					// Admin Login Function Call
					if(tr==1){							// If Password is correct -- Enter Admin Menu
						cout<<"Access Granted"<<endl;
y:						while(true){
							system("CLS");
							cout<<"\n\t\t\t\t\tAdmin Menu\n\n";
							cout<<"**************************************************************************************************************************************************\n";
							cout<<"**************************************************************************************************************************************************\n";      
							cout<<"\n\t1.Add Employee Details\t\t2.Delete Employee Details\t\t3.Display Employee Details\t\t4.Edit Employee Details\n\n\t5.Add Product Details\t\t6.Delete Product Details\t\t7.Display Product Details\t\t8.Edit Product Details\n\n\t9.Change Admin Password\t\t10.Login Menu\n\n";
                        	cout<<"\nEnter your choice: ";
							cin>>choice1;
							cout<<endl;
							
							switch(choice1){
								case 1:system("CLS");		
										cout<<"\n\tAdd Employee details\n"<<endl;				// Add Employee details
										d.create();
										cout<<endl<<endl;;
										system("PAUSE");
									break;
									
								case 2:system("CLS");
										cout<<"\n\tDelete Employee details\n"<<endl;   		// Delete Employee details
	   									cout<<"Enter the Employee ID to delete:\n";
       									cin>>pos2;
       									cout<<"Are you sure you want to delete the employee details(y/n):";
       									cin>>y;
       									if(y=='y'){
       										d.del(pos2);
										   }
       									else{
       										cout<<"Delete Unsuccessful"<<endl;
										   }
										cout<<endl<<endl;
       									system("PAUSE");
									break;
									
								case 3:system("CLS");
										cout<<"\n\tDisplay Employee details\n"<<endl;			// Display Employee Details
										d.print();
										cout<<endl<<endl;
										system("PAUSE");
									break;
								
								case 4:system("CLS");
										cout<<"\n\tEdit Employee Data\n\n";				// Edit Employee Data
										cout<<"Enter Employee ID: ";
       									int e_id;
       									cin>>e_id;
       									d.editE(e_id);
       									cout<<endl<<endl;
       									system("PAUSE");
       									goto y;
									
								case 5:system("CLS");
										cout<<"\n\tAdd product details\n"<<endl;		// Add Product Details
										p1.create();
										cout<<endl<<endl;
										system("PAUSE");
									break;
									
								case 6:system("CLS");
										cout<<"\n\tDelete Product details\n"<<endl;		// Delete Product Details
										cout<<"Enter the Product ID:";
       									cin>>pos1;
       									cout<<"Are you sure you want to delete this item (y/n):";
       									cin>>y;
       									if(y=='y'){
       										p1.del(pos1);
										   }
       									else{
       										cout<<"Delete Unsuccessful"<<endl<<endl;
										   }
										cout<<endl<<endl;
       									system("PAUSE");
       									goto y;
									break;
									
								case 7:system("CLS");
										cout<<"\n\tDisplay Product details\n"<<endl;		// Display Product Details 
										p1.print();
										cout<<endl<<endl;
										system("PAUSE");
										goto y;
									break;
								
								case 8:system("CLS");
										cout<<"\n\tEdit Product Data\n\n";				// Edit Product Data
										cout<<"Enter Product ID: ";
       									int i_d;
       									cin>>i_d;
       									p1.edit(i_d);
       									cout<<endl<<endl;
       									system("PAUSE");
       									goto y;
									break;
									
								case 9:system("CLS");						
										cout<<"\n\t\tAdmin Password\n\n";					// Change Admin Password
										ad.changePass();
										cout<<endl;
										system("PAUSE");
									break;
									
								default:goto x;
							}
							
						}
					}
				break;
				
			case 2:
					system("CLS");
					cout<<"\nEmployee Login"<<endl;
					int lin;
					lin=d.loginE();		//Calling Employee Login function
					
					if(lin!=-1 && lin!=2){		// If Employee Login is successful
					// Enter Cart Menu 
						while(true){
						
z:							cart c;
							int iid;
							char chc='y';								
za:							system("CLS");
							cout<<"\t\t\t\tBILL GENERATION MENU\n\n"<<endl;
							cout<<"************************************************************************************************************************\n";
							cout<<"************************************************************************************************************************\n";
							cout<<"\n\t\t1.New Bill generation\t\t2.Add Product to cart\t\t3.Delete product from cart\n\t\t4.GENERATE BILL\t\t\t5.Login Menu\n";
							int co;
							cout<<"Enter your choice:";
							cin>>co;
							
							switch(co){
								case 1:system("CLS");
										billNO++;
										cout<<"\n\t\tNew bill generation successful"<<endl;		// New BILL Generation
										cout<<endl<<endl;
										system("PAUSE");
										goto z;
										break;
								case 2:system("CLS");
										chc='Y';
										while(chc=='y' || chc=='Y'){
											cout<<"\n\t\tADD ITEMS TO CART"<<endl<<endl;			// Add item to cart using product ID
											p1.print();
											cout<<endl;
											cout<<"Enter the Product ID: ";
											cin>>iid;
											c.create(iid,p1,c);
											cout<<endl<<endl;
											cout<<"Do you want to add more products(y/n)"<<endl;
											cin>>chc;
											if(chc=='y' || chc=='Y'){
												system("CLS");
											}
										}
										system("PAUSE");
       									goto za;
									break;
								case 3:system("CLS");
										cout<<"\n\t\tDELETE ITEMS FROM CART"<<endl<<endl;		// Delete item from cart using product ID
										cout<<"Enter Product ID: ";
										cin>>iid;
										c.del(iid);
										cout<<endl<<endl;
       									system("PAUSE");
       									goto za;
									break;
								case 4:	system("CLS");
										time_t my_time;											// Display GENERATED BILL
										my_time= time(NULL); 
										cout<<"\n\t\t\tGenerated Bill\n\n";
										cout<<"********************************************************************************************************************************************************\n\n";
										cout<<"\t\t\t\t\t\tRELIANCE FRESH\n\n";
  										cout<<"\t\t\t\t\t\tTAX INVOICE\n";
  										cout<<"********************************************************************************************************************************************************\n";
  										cout<<"********************************************************************************************************************************************************\n";
										cout<<"\t\tSTAFF ID: "<<lin<<"\t\tDATE: "<<ctime(&my_time)<<"\t\tBILL NO:"<<billNO;
										cout<<endl;
										cout<<"*********************************************************************************************************************************************************\n";
										c.print();
										cout<<endl;
										system("PAUSE");
       									goto za;
									break;
									
								default:cout<<"\n\t\tGO TO LOGIN MENU(y/n):";
										cin>>y;
										if(y=='y'){
											goto x;
										}
										else{
											goto za;
										}
										goto x;
							}	
						}
					}
					else if(lin==2){
						cout<<"Employee ID or password is incorrect\n";
						cout<<endl<<endl;
						system("PAUSE");
						goto x;
					}
					else{
						system("PAUSE");
						goto x;
					}
				
				break;
				
				default:cout<<"\n\n\tExit";
					exit(0);
		}
	}	
	return 0;
}
