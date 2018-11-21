    #include<fstream>
    #include<string>
    #include<iostream>
    #include<ctype.h> //for testing and mapping characters

    using namespace std;

    int isMultioperator(char source[]){

	   char separators[3][3] = {":=", "==", "!="};

	   bool gate = false;

	   for(int i = 0 ; i < 3 ; i++){
    
		  if( separators[i] == source){
	   
			 gate = true;
			 break;
	   
		  }
    
	   }

    return gate;
    }


    int isKeyword(char source[]){
    
	   char keyword[11][7] ={"WRITE","READ","IF","ELSE","RETURN","BEGIN","END","MAIN","STRING","INT","REAL"};
    
	   bool gate = false ;

	   for(int i =0 ;i<11;i++){
	   
		  if(strcmp(keyword[i] , source)==0){
			 gate = true;
			 break;
		  }
    
	   }

    return gate;
    }

int main(){

char chh, source[100], operators[] = "+-*/%=", separators[] = ";,()", digit[] = "0123456789",digits[100];
    int j = 0, k = 0;
    ifstream fin("source code.txt");

    if(!fin.is_open()){

	   cout<<"can not open this file \n";
    
	   exit(0); //0:exit succesfull cleanup for terminating programs
    }

    while(!fin.eof()){
    
	   chh = fin.get();


	   /*if(chh == ' '){
    
		  continue;
	   }
	   */
	   for(int d = 0 ; d < 4 ; d++){
	  
		  if(chh == separators[d])

			 cout<<chh<<" is single separator\n";
    
    
	   }

	   /* for(int q = 0 ; q < 9 ; q++){
	  
		  if(chh == digit[q])

			 cout<<chh<<" is Digit\n";
    
    
	   }*/

	   for(int i = 0 ; i < 6 ; i++){ //note for plus
    
		  if(chh == operators[i])
		  
			 cout<<chh<<" is operator\n";
    
	   }
    
	   if(chh=='0' || chh=='1' ||chh=='2' || chh=='3' || chh=='4' || chh=='5' || chh=='6' || chh=='7' || chh=='8' || chh=='9'||chh==' '||chh==';'||chh=='\n'){
				if(chh=='0' || chh=='1' ||chh=='2' || chh=='3' || chh=='4' || chh=='5' || chh=='6' || chh=='7' || chh=='8' || chh=='9'){
				    digits[k++] = chh;}
				    if((chh==' '||chh==' \n'||chh==';')&&(k!=0)){
					   digits[k] = '\0'; //null terminated 
						   k = 0;
					   cout<<digits<<" is digit\n";
				    }
				    }

	   //cout<<digits<<" is digital\n";   
	   
		 
	    if(isalpha(chh)){
		 source[j++] = chh; 
		   }
    
		   else if((chh == ' ' || chh == '\n') && (j != 0)){
    
			 source[j] = '\0'; //null terminated string , in std::string not null terminated you make comiler to print as it be.

			 j = 0;

			 if(isKeyword(source) == true)
		
			 { cout<<source<<" is keyword\n";}

			 else if(isMultioperator(source) == true)
		  
			 {cout<<source<<" is multiseparator\n";}
	   
			 //else if(source == digits){cout<<digits<<" is digits\n";}
			 else
				cout<<source<<" is identifier\n";
    
		  //remainder separator function
		  
	  
    
   
    
	   }
    

    }

    fin.close();

    system("pause");
    return 0 ;


    }
    