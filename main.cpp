#include <iostream>  
#include "TST.h"
#include <stdio.h>  
#include <string.h>  
#include <vector>  
#include<sstream>
int main(int argc, char** argv) {    
  TST * myTST = new TST();   
  
   std::vector<std::string> result;   
   std::string mystring = argv[1];    
   std::stringstream s_stream(mystring); 
   while(s_stream.good()) {
      std::string substr;
      getline(s_stream, substr, ','); 
      result.push_back(substr);
   }  
   
   for(int i = 0; i<result.size(); i++) {       
      std::stringstream mystream(result.at(i));   
      std::vector<std::string> myresult; 
      while(mystream.good()) {  
      std::string mysubstr;
      getline(mystream, mysubstr, ' ');   
      if(mysubstr != ""){  
      myresult.push_back(mysubstr); 
        } 
      }   
     
        if(myresult[0] == "insert"){  
          myTST->insert(myresult[1], myTST->gethead()); 
        }  
        else if(myresult[0] == "delete"){  
          myTST->delete_key( myTST->gethead(), myresult[1]); 
        }  
        else if(myresult[0] == "range_search"){ 
          myTST->range_search( myTST->gethead(), myresult[1],myresult[3]);  
        }  
        else if(myresult[0] == "lookup"){   
          myTST->search(myresult[1], myTST->gethead()); 
        }        
  }  
  
}    


