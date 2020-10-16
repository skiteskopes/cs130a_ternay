#include "tst_node.h"  
#include <iostream>      
#include <string>  
#include <tuple>  

TST_node::TST_node(){   
	this -> leftempty = false;   
  this -> rightempty = false;  
	
}   
TST_node::~TST_node(){   
  delete this->left;   
  delete this -> right;   
  delete this -> mid;       
}
void TST_node::inc_kleft(){   
	std::get<1>(this -> kleft) += 1;  
}   

void TST_node::inc_kright(){  
	std::get<1>(this -> kright) += 1;   
}   

void TST_node::set_kleft(std::string word){   
	(std::get<0>(this -> kleft)) = word;   
	std::get<1>(this -> kleft) = 1;      
  this->leftempty = true; 
}  

void TST_node::set_kright(std::string word){  
	(std::get<0>(this -> kright)) = word;   
	std::get<1>(this -> kright) = 1;     
  this ->rightempty = true; 
}  

int TST_node::get_kleft_count(){   
	return std::get<1>(this -> kleft);     
}   

int TST_node::get_kright_count(){   
	return std::get<1>(this -> kright);   
}      

std::string TST_node::get_kleft_word(){      
	return std::get<0>(this -> kleft);   
}    

std::string TST_node::get_kright_word(){            
	return std::get<0>(this -> kright);    
}     

void TST_node::set_right(TST_node * node){  
	this-> right = node;
}  

void TST_node::set_left(TST_node * node){ 
	this-> left = node; 
}  

void TST_node::set_mid(TST_node *node){  
	this -> mid = node;  
}  

bool TST_node::kright_status(){     
	return rightempty; 
}  

bool TST_node::kleft_status(){   
	return leftempty;
}    
void TST_node::set_kleft_count(int count){    
  std::get<1>(this -> kleft) = count; 

}
void TST_node::set_kright_count(int count){    
  std::get<1>(this -> kright) = count; 

}      
void TST_node::make_bool_right(){    
  this -> rightempty = true;  

}     
void TST_node::make_bool_left(){    
  this -> leftempty = true;  

} 

TST_node * TST_node::get_mid(){   
  return this->mid;  
} 

TST_node * TST_node::get_left(){   
  return this->left;  
} 

TST_node * TST_node::get_right(){   
  return this->right;  
}      

std::tuple<std::string, int> TST_node::get_kright(){   
  return this->kright;   
}      

std::tuple<std::string, int> TST_node::get_kleft(){   
  return this->kleft;   
}      

void TST_node::deinc_kleft(){   
  std::get<1>(this -> kleft) -= 1; 
}     

void TST_node::deinc_kright(){   
  std::get<1>(this -> kright) -= 1; 
}      

void TST_node::reset_kright(){   
  std::get<1>(this -> kright) = 0;   
  std::get<0>(this -> kright) = "";  
  this -> rightempty = false;  
}   

void TST_node::reset_kleft(){   
  std::get<1>(this -> kleft) = 0;   
  std::get<0>(this -> kleft) = "";  
  this -> leftempty = false;  
}   

void TST_node::putin_kleft(std::tuple<std::string , int> temp){  
  this -> kleft = temp; 
}  

void TST_node::putin_kright(std::tuple<std::string , int> temp){ 
  this -> kright = temp; 
}  

bool TST_node::complete_empty(){  
  if(this->rightempty == false && this->leftempty == false){ 
    return true;
  }  
  return false; 
} 