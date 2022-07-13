/*Super Market Billing system
Project by 
1- Gohar Nadeem (F2020266107)
*/

 aa#include<iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include<ctype.h>
using namespace std;

int main();
class Node{
    public:
    Node *prev;
    Node *next;
    int data;
    int quantity,price,sum;     //x == quantity
    string name,nam;   //y == price

    Node()
    {
        prev = NULL;
        next = NULL;
        data = 0;
        quantity = 0;
        price = 0;
        sum = 0;

    }
    
};


class LinkedList
{
    public:
    Node* start;
    LinkedList()
    {
        start = NULL;
    }

    int intCheck(string x)
    {
    bool check=true;
    bool pehliBaar=true;
    do{
        if(!pehliBaar)
        {
        cout<<"ENTER AGAIN: "<<endl;
        cin>>x;
        }
        for(int i = 0; i<x.length();i++)
        {
            if(!(isdigit(x[i])))
            {
            check=false;
            break;
            }
            else
            check = true;
        }
        if(!check)
        {
            pehliBaar=false;
            cout<<"You have entered an invalid input. Please enter an integer"<<endl;
        }
    }while(check==false);
        return(stoi(x));
}
    

    Node* create_node(){
        Node *n = new Node;
        bool flag=true;
        string num,a;
        //bool check=true;
        
        cout<<"ENTER PRODUCT ID: "<<endl;
        cin>>num;
        
        n->data=intCheck(num);
        cin.ignore();
        do
        {
        cout<<"ENTER PRODUCT NAME: "<<endl;
        getline(cin,a);
        for(int i = 0; i<a.length();i++)
        {
            if(isdigit(a[i]))
            {
            flag=false;
            break;
            }
            else
            flag = true;
        }
        if(flag==false)
        {
            cout<<"You have entered an invalid input. Please enter product name again: "<<endl;
        }
        }while(flag==false);
        n->name=a;

        cout<<"ENTER QUANTITY: "<<endl;
        cin>>num;
        n->quantity=intCheck(num);
        cout<<"ENTER PRICE OF EACH PRODUCT: "<<endl;
        cin>>num;
        n->price=intCheck(num);
        n->next = NULL;
        n->prev = NULL;
        return n;
    }
// INSERTION IN LINKEDLIST 
    void insert_node(){
        Node *temp;
        temp = create_node();
        if(start == NULL){
        start = temp;
        }
        else{
        Node *traverse;
        traverse = start;
        while(traverse->next != NULL){
            traverse = traverse->next;
        }
            traverse->next=temp;
            temp->prev=traverse;
        }
    }
// INSERTION AT START IN LINKEDLIST 
    void add_begin(){
        Node *temp;
        temp = create_node();
        temp->next = start;
        start->prev = temp;
        start=temp;
    }
//INSERTION AT GIVEN POSITION 
    void add_after(){
        Node *temp;
        temp= create_node();
        int value;
        cout<<"Enter the product id after which the product has to be inserted :"<<endl;
        cin>>value;
        Node *traverse;
        traverse = start;
        while(traverse->data!=value){
            traverse = traverse->next;
        }
        temp->prev = traverse;
        temp->next=traverse->next;
        traverse->next->prev = temp;
        traverse->next = temp;
        main();
    }
// FUNCTION TO GET INPUTS FROM USER 
    void display(){
        Node *traverse;
        traverse  = start;
        system("cls");
        cout<<"\n\n\t\t\t****SUPER MART STORE***"<<endl;
        cout<<"\n\n\t\t\t****DISCOUNTS IS AVALIBLE***"<<endl;
        cout<<"\nPRODUCT ID\t"<<"PRODUCT NAME\t"<<"QUANTITY\t"<<"PRICE"<<endl;
        while(traverse!=NULL){
            cout<<traverse->data<<"\t\t";
            cout<<traverse->name<<"\t\t";
            cout<<traverse->quantity<<"\t\t";
            cout<<traverse->price<<"\n";
            traverse = traverse->next;

        }
        cin.get();
        cin.get();
    }
// FUNCTION TO DELETE DATA AT START
    void delete_beg(){
        Node *temp;
        temp = start;
        start = start->next;
        cout<<temp->data<<" has been deleted"<<endl;
        delete(temp);
    }
// FUNCTION TO DELETE AT END
    void delete_end(){
        Node *traverse;
        traverse = start;
        while(traverse->next != NULL){
        traverse = traverse->next;
        }
        traverse->prev->next = NULL;
        cout<<traverse->data<<" has been deleted"<<endl;
        delete(traverse);
    }
// FUNCTION TO DELETE THE RANDM VALUES
    void delete_after(){
        int value;
        cout<<"Enter the producd after which the Node has to be deleted"<<endl;
        cin>>value;
        Node *traverse;
        traverse = start;
        while(traverse->data != value){
            traverse = traverse->next;
        }
        Node *temp;
        temp = traverse->next;
        traverse->next = temp->next;
        temp->next->prev = traverse;
        cout<<temp->data<<" has been deleted"<<endl;
        delete(temp);
        main();
    }
// IF YOU WANT TO BUY SOMETHING This FUNCTION IS USED 
    void buy(){
        system("cls");
        bool flag=true;
        string products[20];
        int pay=0,no,c=0,price,id,i=1;
        if(start==NULL) {
	        cout<<"\n<<<<There is no items to buy>>>>\n\n";
        }
	    else{
            cout<<"How many items you want to buy!\n";
		    cin>>no;
			    int count= display1();
	    while (i<=no){
			Node *cur=start;
            int quant,cho;
	        cout<<"Enter id of item that you want to buy: \n";
            int id,pos=0;
	        cin>>id;
	        pos=search(id);
	        if(pos<=count){
		        while(cur->data!=id){
			        cur=cur->next;
		        }
	            cout<<"How many products of id number#" <<id <<" you want: \n";
	            cin>>quant;
	            products[c]=cur->name; c++;
	            pay=pay+(cur->price*quant);
	            if(cur->quantity-quant<=0){
	            	cout<<"Product is Out of Stock\n\n";
	            	flag=false;
				}
				else{
					cur->quantity=cur->quantity-quant;
				}
	            //cur->quantity=cur->quantity-quant;
	            i++;
	            }
	            else{
		        cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
	        }
        }
	        //system("cls");
	        if(flag==true){
	        	cout<<"\n\n\n\t\t\tYou have bought : ";
		        for(int i=0;i<no;i++){
			    cout<<products[i]<<",";
		        }
		        price=pay*(0.9);
			    cout<<"\n\nOriginal price : "<<pay;
		        cout<<"\n with 10'%' discount: "<<price<<"\nThank you! for the shopping\n\n";
			}
        
        }
    }

// IF USER WANTS ANY SEPECFIC THING TO BUY THIS FUNCTION SHOWS THE AVALIBILY OF PRODUCT 
	int search(int id){
 	
        int count=1;
 	    Node *p=start;
 	    while(p!=NULL)
 	    {
 		    if(p->data==id)
 		    {

 			    break; 
            }
 		    else
 			    count++;
 			    p=p->next;
	    }

 	    return count;
    }

// THIS FUNCTION SHOWS THE STOCK WHICH IS AVALIBLE AT STORE
    int display1(){
	    //	system("cls");
        int c=0;
        Node *p=start;
        cout<<"Existing products are:\n";
        cout<<"ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
        while(p!=NULL)
		    {
			    cout<<p->data<<"\t\t"<<p->name<<"\t\t\t"<<p->price<<"\t\t"<<check(p->quantity)<<"\n";
			    p=p->next;
			    c=c+1;
		    }
        cout<<"\nTotal products in our store is : "<<c<<"\n\n\n";
        return c;
    }

    string check(int quant){
        int a = quant;
        stringstream ss;
        ss << a;
        string quantity = ss.str();
        if(quant<=0)
        return "out of stock!";
        else
        return quantity;
    }
 
// SEARCHING FUNCTION TO FIND SOME SPECIFIC PRODUCT
    void srch(){
        system("cls");
    	cout<<"\n\n\t\t\t****SUPER MART STORE***"<<endl;
        cout<<"\n\n\t\t\t****DISCOUNTS IS AVALIBLE***"<<endl;
        string nam;
        cout<<"Enter Product Name "<<endl;
        cin>>nam;
        int f=0;
 	    Node *p=start;
 	    while(p!=NULL)
 	    {
 		    if(nam==p->name)
 		    {
 		        f=1;
 			    break;
 			        }

 			    p=p->next;
	    }

	    if(f==1)
        {
        	    cout<<"Product is available"<<endl;
        }
        else{
                cout<<"Out of Stock"<<endl;

        }
    }


};

void menu()
{
    cout<<"     ---------------------------------"<<endl;
    cout<<"     1. ADD PRODUCT"<<endl;
    cout<<"     2. ADD PRODUCT AT FIRST POSITION"<<endl;
    cout<<"     3. ADD PRODUCT AFTER A GIVEN POSITION"<<endl;
    cout<<"     4. DELETE PRODUCT AT LAST POSITION"<<endl;
    cout<<"     5. DELETE PRODUCT AT FIRST POSITION"<<endl;
    cout<<"     6. DELETE PRODUCT AT AFTER A GIVEN POSITION"<<endl;
    cout<<"     7. DISPLAY PRODUCTS"<<endl;
    cout<<"     8. BUY"<<endl;
    cout<<"     9. SEARCH"<<endl;
    cout<<"     Press zero to exit at any point" <<endl;
}


int main(){
LinkedList l1;
// WHAT THING WANT TO DO THE USER SELECT AT MENU
int option;
do{
    menu();
//HERE WE USE SWITCH TO CALL THE FUNCTION ONE BY ONE 
    cin>>option;
    switch(option){
    case 1:l1.insert_node();
          break;
    case 2: l1.add_begin();
           break;
    case 3: l1.add_after();
           break;
    case 4: l1.delete_end();
           break;
    case 5: l1.delete_beg();
           break;
    case 6: l1.delete_after();
           break;
    case 7: l1.display();
           break;
    case 8:  l1.buy();
           break;
    case 9: l1.srch();
            break;
   }

}while(option != 0);
return 0;
}/*-----------------------------THANKS-------------------------------------*/

