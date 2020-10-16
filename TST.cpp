#include "TST.h"  
#include "tst_node.h"   
#include <string>   
#include <iostream>      
#include <vector>      
TST::TST(){}            

TST::~TST(){   
postorder_destroy(this->head); 
} 

void TST::postorder_destroy(TST_node * node){  
  postorder_destroy((*node).get_left());   
  postorder_destroy((*node).get_mid());  
  postorder_destroy((*node).get_right());   
  delete node; 
}  

TST_node * TST::gethead(){   

  return this->head;
}

TST_node * TST::insert(std::string word, TST_node * node) {    
	if(this->head == NULL){    
		TST_node * temp = new TST_node();   
		(*temp).set_kleft(word);   
		this-> head = temp;     
    std::cout<< word << " inserted, new count = 1" << std::endl; 
		return head;  
	}
	
	if(node == NULL){   
		TST_node * temp = new TST_node();     
		(*temp).set_kleft(word);   
    std::cout<< word << " inserted, new count = 1" << std::endl; 
		return temp; 
	}        
  
	if(!(*node).kleft_status() && (*node).kright_status()){   
		if(word.compare((*node).get_kright_word()) < 0){   
			(*node).set_kleft(word);	  
      std::cout<< word << " inserted, new count = " << (*node).get_kleft_count()<< std::endl;    	   
		}  
		else if(word.compare((*node).get_kright_word()) > 0){
			int temp = (*node).get_kright_count();   
			std::string wordtemp = (*node).get_kright_word();   
			(*node).set_kright(word);    
			(*node).set_kleft(wordtemp);  
			(*node).set_kleft_count(temp);        
      std::cout<< word << " inserted, new count = " << (*node).get_kright_count()<< std::endl;   
		}   
		else if(word.compare((*node).get_kright_word()) == 0){   
			(*node).inc_kright();       
      std::cout<< word << " inserted, new count = " << (*node).get_kright_count()<< std::endl;       
		}	
	}   
	
	else if((*node).kleft_status() && !(*node).kright_status()){      
		if(word.compare((*node).get_kleft_word()) > 0){   
			(*node).set_kright(word);        
      std::cout<< word << " inserted, new count = " << (*node).get_kright_count()<< std::endl;   
		}    
		else if(word.compare((*node).get_kleft_word()) < 0){     
			int temp = (*node).get_kleft_count();   
			std::string wordtemp = (*node).get_kleft_word();      
			(*node).set_kleft(word);  
			(*node).set_kright(wordtemp);  
			(*node).set_kright_count(temp);       
      std::cout<< word << " inserted, new count = " << (*node).get_kleft_count()<< std::endl; 
		}   
		else if(word.compare((*node).get_kleft_word()) == 0){   
			(*node).inc_kleft();       
      std::cout<< word << " inserted, new count = " << (*node).get_kleft_count()<< std::endl;       
		}
	}   
		
	else if ((*node).kleft_status() && (*node).kright_status()){      

    if(word.compare((*node).get_kright_word()) ==0){   
      (*node).inc_kright();        
      std::cout<< word << " inserted, new count = " << (*node).get_kright_count()<< std::endl;     
    }    
    if(word.compare((*node).get_kleft_word()) ==0){   
      (*node).inc_kleft();     
      std::cout<< word << " inserted, new count = " << (*node).get_kleft_count()<< std::endl;     
    }
    
		if(word.compare((*node).get_kright_word()) < 0 && word.compare((*node).get_kleft_word()) > 0){   
				(*node).set_mid(insert(word,(*node).get_mid()));            
		}   
		else if(word.compare((*node).get_kright_word()) > 0){   
			(*node).set_right(insert(word,(*node).get_right()));  
		}  
		else if(word.compare((*node).get_kleft_word()) < 0){  
			(*node).set_left(insert(word,(*node).get_left()));  		
	  }   
  }    
  return node;
}     

std::tuple<std::string , int> TST::search(std::string word, TST_node * node){     
  if(node == NULL){      
    std::cout<< word << " not found" <<std::endl; 
    return std::make_tuple("", -1); 
  }
  if(word == (*node).get_kleft_word()){     
    std::cout << word << " found, count = " << (*node).get_kleft_count() << std::endl;  
    return (*node).get_kleft(); 

  }           
  else if(word == (*node).get_kright_word()){     
    std::cout << word << " found, count = " << (*node).get_kright_count() << std::endl;     
     return (*node).get_kright(); 
  }       
  else{           
    if(word.compare((*node).get_kright_word()) < 0 && word.compare((*node).get_kleft_word()) > 0){      
				return search(word, (*node).get_mid());      
		}   
		else if(word.compare((*node).get_kright_word()) > 0){   
			return search(word, (*node).get_right()); 
		}  
		else if(word.compare((*node).get_kleft_word()) < 0){  
			return search(word, (*node).get_left());  
    } 

  }
}   

void TST::inorder(TST_node * node){           
  if(node == NULL){  
    return; 
  }
  inorder((*node).get_left());      
  if ((*node).kleft_status() == true){       
  std::cout<<(*node).get_kleft_word()<<std::endl;}    
  inorder((*node).get_mid());    
  if((*node).kright_status() == true){    
  std::cout<<(*node).get_kright_word()<<std::endl;}   
  inorder((*node).get_right()); 
}                  

void TST::range_search(TST_node * node, std::string smallword, std::string bigword){           
  if(node == NULL){  
    return; 
  }
  range_search((*node).get_left(), smallword, bigword);      
  if ((*node).kleft_status() == true && ((*node).get_kleft_word()).compare(smallword) >= 0 && ((*node).get_kleft_word()).compare(bigword) <= 0 ){       
    std::cout<<(*node).get_kleft_word()<<std::endl;   
  }    

  range_search((*node).get_mid(), smallword, bigword);

  if((*node).kright_status() == true && ((*node).get_kright_word()).compare(smallword) >= 0 && ((*node).get_kright_word()).compare(bigword) <= 0 ){     
    std::cout<<(*node).get_kright_word()<<std::endl;   

  }

  range_search((*node).get_right(), smallword, bigword); 
}   

void TST::delete_key(TST_node * node, std::string word){    
  if(node == NULL){   
    return;
  }    
  if((*node).get_kleft_word() == word){    
    if((*node).get_kleft_count() > 1){   
      (*node).deinc_kleft();  
      std::cout<< word <<" deleted, new count = "<<node->get_kleft_count()<<std::endl;
    }      
    else{      
      if((*node).kright_status() == false){     
        delink(node, this-> head);     
        std::cout<< word <<" deleted"<<std::endl; 
        delete node;   
      }      
      else{          
        if((*node).get_mid() == NULL && (*node).get_left() == NULL && (*node).get_right() == NULL){   
          (*node).reset_kleft();     
          std::cout<< word <<" deleted"<<std::endl; 
        }  
        else if ((*node).get_mid() == NULL && (*node).get_left() != NULL){  
           std::tuple<std::string , int> temp = find_max((*node).get_left()); 
           (*node).putin_kleft(temp);    
           std::cout<< word <<" deleted"<<std::endl; 
        }   
        else if ((*node).get_mid() != NULL && (*node).get_left() == NULL){
          std::tuple<std::string , int> temp = find_min((*node).get_mid());   
          (*node).putin_kleft(temp);    
          std::cout<< word <<" deleted"<<std::endl; 
          }   
        else if((*node).get_mid() == NULL && (*node).get_left() == NULL){  
          std::tuple<std::string , int> temp = find_min((*node).get_right());
          std::tuple<std::string , int> temp2 = (*node).get_kright();   
          (*node).putin_kright(temp);  
          (*node).putin_kleft(temp2);   
          std::cout<< word <<" deleted"<<std::endl; 
        }
      }
    
    }  
}    

  else if((*node).get_kright_word() == word){      
    
    if((*node).get_kright_count() > 1){   
      (*node).deinc_kright();  
      std::cout<< word <<" deleted, new count = "<<node->get_kright_count()<<std::endl;
    }   
    else{        
      if((*node).kleft_status() == false){ 
        delink(node, this-> head);     
        delete node;      
        std::cout<< word <<" deleted"<<std::endl; 
      }  
      else{     
        if((*node).get_mid() == NULL && (*node).get_left() == NULL && (*node).get_right() == NULL){     
          (*node).reset_kright();    
          std::cout<< word <<" deleted"<<std::endl; 
        }   
        else if((*node).get_mid() == NULL && (*node).get_right() != NULL){  
           std::tuple<std::string , int> temp = find_min((*node).get_right());  //find successor      
           (*node).putin_kright(temp);  
           std::cout<< word <<" deleted"<<std::endl; 
        }   
        else if ((*node).get_mid() != NULL && (*node).get_right() == NULL){
          std::tuple<std::string , int> temp = find_max((*node).get_mid());   
          (*node).putin_kright(temp);   
          std::cout<< word <<" deleted"<<std::endl;  
        } 
        else if((*node).get_mid() == NULL && (*node).get_right() == NULL){      
          std::tuple<std::string , int> temp = find_max((*node).get_left());
          std::tuple<std::string , int> temp2 = (*node).get_kleft();   
          (*node).putin_kleft(temp);  
          (*node).putin_kright(temp2);  
          std::cout<< word <<" deleted"<<std::endl; 
        }
      }
  }       
  }
  else {   
    if((*node).get_kright_word().compare(word) < 0 ){ 
      delete_key((*node).get_right(), word); 
    }   
    else if ((*node).get_kleft_word().compare(word) > 0 ){ 
      delete_key((*node).get_left(), word);       
    }  
    else{
      delete_key((*node).get_mid(), word);
    } 
  }
  

  
}  
std::tuple<std::string , int> TST::find_max(TST_node * node){   
  if((*node).get_right() == NULL){    
    if((*node).kright_status() == false){             
      std::tuple<std::string , int> temp =  (*node).get_kleft();  
      delink(node, this-> head);    
      delete node;     
      return temp;
    }    
    else if ((*node).kleft_status() == false){         
      std::tuple<std::string , int> temp =  (*node).get_kright();
      (*node).reset_kright();  
      delink(node, this-> head);  
      delete node;
      return temp; 
    }   
    else{    
      std::tuple<std::string , int> temp =  (*node).get_kright();
      (*node).reset_kright();  

      if(node->get_right() != NULL){  
        std::tuple<std::string , int> temp = find_min((*node).get_right());  
        (*node).putin_kright(temp);     
        (*node).make_bool_right();  
      }    
      else if (node ->get_left() != NULL){    
        std::tuple<std::string , int> temp = find_max((*node).get_left());
        std::tuple<std::string , int> temp2 = (*node).get_kleft();   
        (*node).putin_kleft(temp);  
        (*node).putin_kright(temp2);  
        (*node).make_bool_right();   
        (*node).make_bool_left(); 

      }   
      else if (node -> get_mid() != NULL){     
        std::tuple<std::string , int> temp = find_max((*node).get_mid());  
        (*node).putin_kright(temp);   
        (*node).make_bool_right();  

      } 
      return temp;
    }
  }  
  else{   
    return find_max((*node).get_right());
  }
  
}    

std::tuple<std::string , int> TST::find_min(TST_node * node){   
  if((*node).get_left() == NULL){    
    if((*node).kleft_status() == false){           
      std::tuple<std::string , int> temp =  (*node).get_kright();
      delink(node, this-> head);   
      delete node; 
      return temp;
    }    
    else if ((*node).kright_status() == false){         
      std::tuple<std::string , int> temp =  (*node).get_kleft();
      (*node).reset_kleft();  
      delink(node, this-> head);   
      delete node; 
      return temp; 
    }   
    else{  
      std::tuple<std::string , int> temp =  (*node).get_kleft();
      (*node).reset_kleft();        
      if(node->get_left() != NULL){  
        std::tuple<std::string , int> temp = find_max((*node).get_left());  
        (*node).putin_kleft(temp);    
        (*node).make_bool_left();  
      }    
      else if (node ->get_right() != NULL){    
        std::tuple<std::string , int> temp = find_min((*node).get_right());
        std::tuple<std::string , int> temp2 = (*node).get_kright();   
        (*node).putin_kleft(temp2);  
        (*node).putin_kright(temp);  
        (*node).make_bool_right();   
        (*node).make_bool_left();  

      }   
      else if (node -> get_mid() != NULL){     
        std::tuple<std::string , int> temp = find_min((*node).get_mid());  
        (*node).putin_kleft(temp);   
        (*node).make_bool_left();  

      }
      return temp; 
    }
  }  
  else{   
    return find_max((*node).get_left());
  }
  
}   

void TST::delink(TST_node * node, TST_node * head){         
  if(head == NULL){   
    return; 
  }   
  if(head->get_mid() == node){   
    head->set_mid(NULL);   
    return;
  }   
  else if (head->get_left() == node){    
    head -> set_left(NULL);  
    return;      
  }   
  else if (head ->get_right() == node){   
    head -> set_right(NULL);  
    return;    
  }   
  else{      
    delink(node, head->get_mid());  
    delink(node, head->get_right());   
    delink(node, head ->get_left()); 
  }
}   